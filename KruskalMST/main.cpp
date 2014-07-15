#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include <sstream>
#include <iterator>

#include "Graph.h"
#include "UnionFind.h"
#include "KruskalMST.h"

using std::vector;

Graph readGraphFromFile()
{
	Graph g;

	std::string currentLine;
	std::ifstream input("edges.txt");

	if (input.is_open())
	{
		getline(input, currentLine);

		while (getline(input, currentLine))
		{
			std::istringstream buf(currentLine);
			std::istream_iterator<std::string> beg(buf), end;

			std::vector<std::string> tokens(beg, end);

			g.AddEdge(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));
		}
	}

	return g;
}

int main(int argc, char** argv)
{
	Graph g = readGraphFromFile();
	KruskalMST mst(g);

	try
	{
		mst.FindSpanningTree();

		std::vector<Edge> tree = mst.MinimumSpanningTree;
		std::cout << "minimum cost (Kruskal's algorithm): " << mst.GetMinimumCost();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what();
	}

	std::cin.get();

	return 0;
}