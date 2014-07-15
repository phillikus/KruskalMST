#pragma once
#include <vector>
#include <map>

class UnionFind
{
private:

public:

	class Node
	{
	public:
		int data;
		int rank;
		Node* parent;

		Node() : data(0), rank(0), parent(this){}
	};

	int ClusterCount = 0;
	std::vector<Node*> Nodes;

	UnionFind::UnionFind()
	{}
	
	UnionFind::~UnionFind()
	{
		for (auto &it : Nodes) delete it; Nodes.clear();
	}

	void AddNode(Node* node)
	{
		Nodes.push_back(node);
		ClusterCount++;
	}

	Node* Find(Node* node)
	{
		if (node != node->parent)
		{
			node->parent = Find(node->parent);
		}
		return node->parent;
	}

	void Union(Node* i, Node* j)
	{
		ClusterCount--;
		Node* iRoot = Find(i);
		Node* jRoot = Find(j);

		if (iRoot == jRoot)
			return;

		if (iRoot->rank < jRoot->rank)
		{
			iRoot->parent = jRoot;
		}
		else if (iRoot->rank > jRoot->rank)
		{
			jRoot->parent = iRoot;
		}
		else
		{
			jRoot->parent = iRoot;
			iRoot->rank += 1;
		}

	}
};