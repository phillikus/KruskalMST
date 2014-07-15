#include "KruskalMST.h"
#include "UnionFind.h"
#include <algorithm>

bool compareEdgeWeight(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

KruskalMST::KruskalMST(Graph g)
{
	std::sort(g.Edges.begin(), g.Edges.end(), compareEdgeWeight);
	unionFind = UnionFind();

	std::vector<UnionFind::Node*> nodes;

	for (std::vector<int>::const_iterator it = g.Nodes.begin(); it != g.Nodes.end(); it++)
	{
		UnionFind::Node* n = new UnionFind::Node();
		n->data = *it;
		n->rank = 0;

		unionFind.AddNode(n);
	}

	graph = g;
}


KruskalMST::~KruskalMST()
{
}

void KruskalMST::FindSpanningTree()
{
	for (std::vector<Edge>::iterator it = graph.Edges.begin(); it != graph.Edges.end(); it++)
	{		
		UnionFind::Node* u = unionFind.Nodes[it->from-1]; // -1 because vector/array starts at index 0 while graph starts with node #1
		UnionFind::Node* v = unionFind.Nodes[it->to-1];   //

		if (unionFind.Find(u) != unionFind.Find(v))
		{
			Edge e = Edge(it->from, it->to, it->weight);
			MinimumSpanningTree.push_back(e);
			unionFind.Union(u, v);
		}

		if (unionFind.ClusterCount == 1) //end when all nodes are connected (in the same cluster)
			break;
	}
}

int KruskalMST::MaximumClustering(int clusterCount)
{
	for (std::vector<Edge>::iterator it = graph.Edges.begin(); it != graph.Edges.end(); it++)
	{
		UnionFind::Node* u = unionFind.Nodes[it->from - 1]; // -1 because vector/array starts at index 0 while graph starts with node #1
		UnionFind::Node* v = unionFind.Nodes[it->to - 1];   //

		if (unionFind.Find(u) != unionFind.Find(v))
		{
			if (clusterCount == unionFind.ClusterCount)
			{
				return it->weight;
			}

			Edge e = Edge(it->from, it->to, it->weight);
			MinimumSpanningTree.push_back(e);
			unionFind.Union(u, v);			
		}
	}

	return -1;
}

long KruskalMST::GetMinimumCost()
{
	long totalCost = 0;

	for (std::vector<Edge>::const_iterator it = MinimumSpanningTree.begin(); it != MinimumSpanningTree.end(); it++)
	{
		totalCost += it->weight;
	}

	return totalCost;
}
