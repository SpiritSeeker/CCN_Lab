#pragma once

#include <utility>
#include <list>

typedef std::pair<int, int> intPair;

class Graph
{
public:
	Graph(int vertices);
	~Graph();
	
	void AddEdge(int source, int destination, int weight);
	void ShortestPath(int source);
private:
	int m_Vertices;
	std::list<std::pair<int, int>> *m_Adjacency;
};