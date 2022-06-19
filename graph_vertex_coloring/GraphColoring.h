#pragma once
#include<iostream>
#include <vector>
#include "DirectedWeightedGraph.h"
#define NO_COLOR 0

class GraphColoring
{
public:
	void color(DirectedWeightedGraph<int> graph, int numOfColors, int i, std::vector<int> color);
private:
	void printColorSequence(std::vector<int> color);
	bool adjacent_colors(DirectedWeightedGraph<int> graph, std::vector<int> color, int node1, int node2);
	bool isSafe(DirectedWeightedGraph<int> graph, std::vector<int> color);
};
void GraphColoring::color(DirectedWeightedGraph<int> graph, int numOfColors, int current_node, std::vector<int> colors)
{
	if (current_node == graph.get_number_of_nodes())
	{
		std::cout << "! A Possible color sequence: "; printColorSequence(colors);
		return;
	}
	for (int color_number = 1; color_number <= numOfColors; color_number++)
	{
		colors[current_node] = color_number;
		if (!isSafe(graph, colors)) continue;
		std::cout << "? Now trying color sequence: "; printColorSequence(colors);
		color(graph, numOfColors, current_node + 1, colors);
	}
}

void GraphColoring::printColorSequence(std::vector<int> color)
{
	for (int i = 0; i < color.size(); i++)
		std::cout << " " << color[i];
	std::cout << "\n";
}

inline bool GraphColoring::adjacent_colors(DirectedWeightedGraph<int> graph, std::vector<int> color, int node1, int node2) {
	return graph.edge_exists(node1, node2)
		&& (color[node1] == color[node2])
		&& color[node1] != NO_COLOR && color[node2] != NO_COLOR;
}

inline bool GraphColoring::isSafe(DirectedWeightedGraph<int> graph, std::vector<int> color)
{
	for (int i = 0; i < graph.get_number_of_nodes(); i++)
		for (int j = i + 1; j < graph.get_number_of_nodes(); j++)
			if (adjacent_colors(graph, color, i, j)) return false;
	return true;
}

void TEST_coloring()
{
	DirectedWeightedGraph<int> graph(4);
	graph.set_edge(0, 1);
	graph.set_edge(0, 2);
	graph.set_edge(0, 3);
	graph.set_edge(1, 2);
	graph.set_edge(2, 3);

	GraphColoring g;
	int m = 3;
	std::vector<int> coloring(graph.get_number_of_nodes(), NO_COLOR);

	g.color(graph, m, 0, coloring);
}