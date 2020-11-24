#include "Graph.h"
#include <limits>
#include <queue>
#include <iostream>

Graph::Graph(int vertices)
	: m_Vertices(vertices)
{
	m_Adjacency = new std::list<intPair>[m_Vertices];
}

Graph::~Graph()
{
	delete[] m_Adjacency;
}

void Graph::AddEdge(int source, int destination, int weight)
{
	m_Adjacency[source].push_back(std::make_pair(destination, weight));
	m_Adjacency[destination].push_back(std::make_pair(source, weight));
}

void Graph::ShortestPath(int source)
{
	std::priority_queue<intPair, std::vector<intPair>, std::greater<intPair>> priorityQueue;
	std::vector<int> distances(m_Vertices, std::numeric_limits<int>::max());

	priorityQueue.push(std::make_pair(0, source));
	distances[source] = 0;

	while (!priorityQueue.empty())
	{
		int vertex = priorityQueue.top().second;
		priorityQueue.pop();

		for (auto i = m_Adjacency[vertex].begin(); i != m_Adjacency[vertex].end(); ++i)
		{
			int nextVertex = (*i).first;
			int weight = (*i).second;

			if (distances[vertex] + weight < distances[nextVertex])
			{
				distances[nextVertex] = distances[vertex] + weight;
				priorityQueue.push(std::make_pair(distances[nextVertex], nextVertex));
			}
		}
	}

	std::cout << "Shortest paths from vertex " << source << ":" << std::endl;
	std::cout << "To\tDistance" << std::endl;
	for (int i = 0; i < m_Vertices; ++i)
		std::cout << i << "\t    " << distances[i] << std::endl;
}