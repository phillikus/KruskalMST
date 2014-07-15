#pragma once

#include "Graph.h"
#include "UnionFind.h"

class KruskalMST
{
private:
	Graph graph;
	UnionFind unionFind;
	bool CompareEdgeWeight(Edge e1, Edge e2);

public:
	KruskalMST(Graph g);
	~KruskalMST();
	void FindSpanningTree();
	int MaximumClustering(int clusterCount);
	std::vector<Edge> MinimumSpanningTree;
	long GetMinimumCost();
};

