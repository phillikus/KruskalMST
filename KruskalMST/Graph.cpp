#include "Graph.h"

#include <vector>

Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::AddEdge(int from, int to, int weight)
{
	Edges.push_back(Edge(from, to, weight));

	if (!IsDirected)
	{
		Edges.push_back(Edge(to, from, weight));
	}

	if (std::find(Nodes.begin(), Nodes.end(), from) == Nodes.end())
	{
		Nodes.push_back(from);
	}

	if (std::find(Nodes.begin(), Nodes.end(), to) == Nodes.end())
	{
		Nodes.push_back(to);
	}
}