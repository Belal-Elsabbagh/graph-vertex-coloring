#pragma once
#include <iostream>
#include <vector>
#define NULL_EDGE -1
template<class Weight>
class Graph
{
public:
	Graph(int numOfNodes);
	Graph(std::vector<std::vector<Weight>> g);
	void set_edge(int start_node, int end_node, Weight weight = 0);
	void remove_edge(int start_node, int end_node);
	bool edge_exists(int start_node, int end_node);
	Weight get_edge_weight(int start_node, int end_node);
	void print_adjacency_matrix();
	int get_number_of_nodes() { return numberOfNodes; }
private:
	std::vector<std::vector<Weight>> adjacency_matrix;
	int numberOfNodes;
};

template<class Weight>
inline Graph<Weight>::Graph(int numOfNodes)
	: numberOfNodes(numOfNodes),
	adjacency_matrix(numOfNodes, std::vector<Weight>(numOfNodes, NULL_EDGE)) 
{

}

template<class Weight>
inline Graph<Weight>::Graph(std::vector<std::vector<Weight>> g)
	: adjacency_matrix(g),numberOfNodes(g.size())
{

}

template<class Weight>
inline void Graph<Weight>::set_edge(int start_node, int end_node, Weight weight)
{
	adjacency_matrix[start_node][end_node] = weight;
}

template<class Weight>
inline void Graph<Weight>::remove_edge(int start_node, int end_node)
{
	adjacency_matrix[start_node][end_node] = NULL_EDGE;
}

template<class Weight>
inline bool Graph<Weight>::edge_exists(int start_node, int end_node) 
{ 
	return adjacency_matrix[start_node][end_node] != NULL_EDGE; 
}

template<class Weight>
inline Weight Graph<Weight>::get_edge_weight(int start_node, int end_node) 
{ 
	return adjacency_matrix[start_node][end_node]; 
}

template<class Weight>
inline void Graph<Weight>::print_adjacency_matrix()
{
	for (size_t i = 0; i < adjacency_matrix.size(); i++)
	{
		for (size_t j = 0; j < adjacency_matrix[i].size(); j++)
			std::cout << adjacency_matrix[i][j] << "\t";
		std::cout << "\n";
	}
}
