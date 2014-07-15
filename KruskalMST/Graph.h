#pragma once

#include<vector>

struct Edge
{
	int from, to, weight;

	Edge()
	{
		from = -1;
		to = -1;
		weight = -1;
	}

	Edge(int f, int t, int w)
	{
		from = f;
		to = t;
		weight = w;
	}

	bool isEmpty()
	{
		return from == -1 && to == -1 && weight == -1;
	}
};

class Graph
{
public:
	Graph();
	~Graph();

	std::vector<Edge> Edges;
	std::vector<int> Nodes;
	bool IsDirected = false;

	void AddEdge(int from, int to, int weight);
};

