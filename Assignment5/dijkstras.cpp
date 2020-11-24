#include "Graph.h"

int main()
{
	Graph graph(4);

	graph.AddEdge(0, 1, 1);
	graph.AddEdge(0, 2, 3);
	graph.AddEdge(0, 3, 1);
	graph.AddEdge(1, 3, 3);
	graph.AddEdge(2, 3, 1);

	graph.ShortestPath(1);

	return 0;
}