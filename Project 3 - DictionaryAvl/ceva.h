#pragma once
#include <algorithm>


template<typename T>
class Node{
private:
	T value;
	int height;
	Node* leftNode;
	Node* rightNode;
	void updateHeight();

	template<class T> friend class BST;
	template<class T> friend class AVL;

public:
	Node() : Node(T()) {} //delegating to the value constructor with the default value
	Node(T value);
	~Node();

	static int getHeight(Node<T>* node);
	static int getBalance(Node<T>* node);
};
