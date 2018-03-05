#include "ModelLoader.h"

using namespace std;
namespace ModelLoader
{
	void LoadVertices(ObjMesh& mesh, string& buffer);
	void LoadFaces(ObjMesh& mesh, string &buffer);
	void LoadTexCoords(ObjMesh& mesh, string &buffer);
	void LoadNormals(ObjMesh& mesh, string &buffer);

	std::vector<Vertex> tempVertices;
	std::vector<Textures> tempTextures;
	std::vector<Vertex> tempNormals;

	void LoadVertices(ObjMesh & mesh, string& buffer)
	{
		if (buffer[0] == 'v' && buffer[1] == ' ')
		{
			//string buffer;
			Vertex temp3;

			float tmpX, tmpY, tmpZ;
			sscanf_s(buffer.c_str(), "v %f %f %f", &tmpX, &tmpY, &tmpZ);

			temp3.x = tmpX;
			temp3.y = tmpY;
			temp3.z = tmpZ;
			tempVertices.push_back(temp3);
		}		
	}
	
	void LoadTexCoords(ObjMesh & mesh, string& buffer)
	{
		if (buffer[0] == 'v' && buffer[1] == 't')
		{
		Textures temp2;

		float tmpU, tmpV;
		sscanf_s(buffer.c_str(), "vt %f %f", &tmpU, &tmpV);

		temp2.u = tmpU;
		temp2.v = tmpV;

		tempTextures.push_back(temp2);
	   }
	}
	
	void LoadNormals(ObjMesh & mesh, string& buffer)
	{
		if (buffer[0] == 'v' && buffer[1] == 'n')
		{
			Vertex temp3;

			float tmpX, tmpY, tmpZ;
			sscanf_s(buffer.c_str(), "vn %f %f %f", &tmpX, &tmpY, &tmpZ);

			temp3.x = tmpX;
			temp3.y = tmpY;
			temp3.z = tmpZ;

			tempNormals.push_back(temp3);
		}
	    
	}

	void LoadFaces(ObjMesh & mesh, string& buffer)
	{
		if (buffer[0] == 'f' && buffer[1] == ' ')
		{
			if (sscanf_s(buffer.c_str(), "f %i//%i %i//%i %i//%i", &mesh.vertexIndex[0], &mesh.normalIndex[0], &mesh.vertexIndex[1], &mesh.normalIndex[1], &mesh.vertexIndex[2], &mesh.normalIndex[2]) == 6) //Vertex and normal
			{
				mesh.vertexIndices.push_back(mesh.vertexIndex[0]);
				mesh.vertexIndices.push_back(mesh.vertexIndex[1]);
				mesh.vertexIndices.push_back(mesh.vertexIndex[2]);

				mesh.normalIndices.push_back(mesh.normalIndex[0]);
				mesh.normalIndices.push_back(mesh.normalIndex[1]);
				mesh.normalIndices.push_back(mesh.normalIndex[2]);
			}

			if (sscanf_s(buffer.c_str(), "f %i/%i/%i %i/%i/%i %i/%i/%i", &mesh.vertexIndex[0], &mesh.uvIndex[0], &mesh.normalIndex[0],
				&mesh.vertexIndex[1], &mesh.uvIndex[1], &mesh.normalIndex[1],
				&mesh.vertexIndex[2], &mesh.uvIndex[2], &mesh.normalIndex[2]) == 9) //vertex normal and texture
			{
				mesh.textureEnabled = true;
				mesh.vertexIndices.push_back(mesh.vertexIndex[0]);
				mesh.vertexIndices.push_back(mesh.vertexIndex[1]);
				mesh.vertexIndices.push_back(mesh.vertexIndex[2]);

				mesh.normalIndices.push_back(mesh.normalIndex[0]);
				mesh.normalIndices.push_back(mesh.normalIndex[1]);
				mesh.normalIndices.push_back(mesh.normalIndex[2]);

				mesh.uvIndices.push_back(mesh.uvIndex[0]);
				mesh.uvIndices.push_back(mesh.uvIndex[1]);
				mesh.uvIndices.push_back(mesh.uvIndex[2]);
			}

			if (sscanf_s(buffer.c_str(), "f %i/%i %i/%i %i/%i", &mesh.vertexIndex[0], &mesh.uvIndex[0], &mesh.vertexIndex[1], &mesh.uvIndex[1], &mesh.vertexIndex[2], &mesh.uvIndex[2]) == 6) //vertex and texture
			{
				mesh.textureEnabled = true;
				mesh.vertexIndices.push_back(mesh.vertexIndex[0]);
				mesh.vertexIndices.push_back(mesh.vertexIndex[1]);
				mesh.vertexIndices.push_back(mesh.vertexIndex[2]);

				mesh.uvIndices.push_back(mesh.uvIndex[0]);
				mesh.uvIndices.push_back(mesh.uvIndex[1]);
				mesh.uvIndices.push_back(mesh.uvIndex[2]);
			}
		}

	}

	ObjMesh * ModelLoader::Load(char * path)
	{
		ObjMesh* objMesh = new ObjMesh();

		ifstream file;
		file.open(path);

		string buffer;

		if (!file.good())
		{
			cerr << "Can't open texture file " << path << endl;
			return nullptr;
		}

		while (!file.eof())
		{
			getline(file, buffer);

			if (buffer[0] == '#')
			{
				continue;
			}
			else
			{
				LoadVertices(*objMesh, buffer);

				LoadNormals(*objMesh, buffer);

				LoadTexCoords(*objMesh, buffer);
				
				LoadFaces(*objMesh, buffer);
			}		
		}

		file.close();

		for (unsigned int i = 0; i < objMesh->vertexIndices.size(); i++)
		{
			unsigned int vertexIndex = objMesh->vertexIndices[i];
			Vertex faceVertices;
			faceVertices = tempVertices[vertexIndex - 1];

			objMesh->vertices.push_back(faceVertices);
		}

		for (unsigned int i = 0; i < objMesh->normalIndices.size(); i++)
		{
			unsigned int normalIndex = objMesh->normalIndices[i];
			Vertex faceNormals;
			faceNormals = tempNormals[normalIndex - 1];

			objMesh->normals.push_back(faceNormals);
		}

		for (unsigned int i = 0; i < objMesh->uvIndices.size(); i++)
		{
			unsigned int uvIndex = objMesh->uvIndices[i];
			Textures faceTextures;
			faceTextures = tempTextures[uvIndex - 1];

			objMesh->textures.push_back(faceTextures);
		}

		tempNormals.clear(); //Microsoft function which will clear the temp arrays allowing me to load in new arrays
		tempTextures.clear();
		tempVertices.clear();

		return objMesh;
	}

}


