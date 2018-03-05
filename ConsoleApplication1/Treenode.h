#pragma once
#include "Player.h"
#include "Structures.h"

class Treenode
{
	private:
	char data;
	Treenode * left;
	Treenode * right;


	public:

		Treenode(char c) : data(c)
		{
			left = nullptr;
			right = nullptr;
		}
	~Treenode();
	void getData();
	void preOrderTraverse();
	void inOrderTraverse();
	void depthFirstSearch(char searchChar);
	void addLeftChild(Treenode* t);
	void addRightChild(Treenode* t);

};