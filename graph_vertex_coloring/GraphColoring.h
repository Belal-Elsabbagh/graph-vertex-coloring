#pragma once
#include<iostream>
#include <vector>
#include "Graph.h"
#define NO_COLOR 0

class GraphColoring
{
public:
	int old_counter = 1, improved_counter = 1;
	void color_improved(Graph<int> graph, int numOfColors, int current_node, std::vector<int> colors);
	void color_old(Graph<int> graph, int numOfColors, int current_node, std::vector<int> colors);
private:
	void printColorSequence(std::vector<int> color);
	bool adjacent_colors(Graph<int> graph, std::vector<int> color, int node1, int node2);
	bool isSafe(Graph<int> graph, std::vector<int> color);
};
void GraphColoring::color_improved(Graph<int> graph, int numOfColors, int current_node, std::vector<int> colors)
{
	if (current_node == graph.get_number_of_nodes())
	{
		std::cout << "A Possible color sequence: "; printColorSequence(colors);
		return;
	}
	for (int color_number = 1; color_number <= numOfColors; color_number++)
	{
		colors[current_node] = color_number;
		if (!isSafe(graph, colors)) continue;
		color_improved(graph, numOfColors, current_node + 1, colors);
		improved_counter++;
	}
}

inline void GraphColoring::color_old(Graph<int> graph, int numOfColors, int current_node, std::vector<int> colors)
{
	if (!isSafe(graph, colors)) return;
	if (current_node == graph.get_number_of_nodes())
	{
		std::cout << "A Possible color sequence: "; printColorSequence(colors);
		return;
	}
	for (int color_number = 1; color_number <= numOfColors; color_number++)
	{
		colors[current_node] = color_number;
		color_old(graph, numOfColors, current_node + 1, colors);
		old_counter++;
	}
}

void GraphColoring::printColorSequence(std::vector<int> color)
{
	for (int i = 0; i < color.size(); i++)
		std::cout << " " << color[i];
	std::cout << "\n";
}

inline bool GraphColoring::adjacent_colors(Graph<int> graph, std::vector<int> color, int node1, int node2) {
	return graph.edge_exists(node1, node2)
		&& (color[node1] == color[node2])
		&& color[node1] != NO_COLOR && color[node2] != NO_COLOR;
}

inline bool GraphColoring::isSafe(Graph<int> graph, std::vector<int> color)
{
	for (int i = 0; i < graph.get_number_of_nodes(); i++)
		for (int j = i + 1; j < graph.get_number_of_nodes(); j++)
			if (adjacent_colors(graph, color, i, j)) return false;
	return true;
}

void TEST_coloring()
{
	Graph<int> graph(20);
	graph.set_edge(0, 1);
	graph.set_edge(1, 2);
	graph.set_edge(2, 3);
	graph.set_edge(3, 4);
	graph.set_edge(0, 4);

	graph.set_edge(0, 5);
	graph.set_edge(1, 7);
	graph.set_edge(2, 9);
	graph.set_edge(3, 11);
	graph.set_edge(4, 13);

	graph.set_edge(5, 6);
	graph.set_edge(6, 7);
	graph.set_edge(7, 8);
	graph.set_edge(8, 9);
	graph.set_edge(9, 10);
	graph.set_edge(10, 11);
	graph.set_edge(11, 12);
	graph.set_edge(12, 13);
	graph.set_edge(13, 14);
	graph.set_edge(5, 14);

	graph.set_edge(6, 15);
	graph.set_edge(8, 16);
	graph.set_edge(10, 17);
	graph.set_edge(12, 18);
	graph.set_edge(14, 19);

	graph.set_edge(15, 16);
	graph.set_edge(15, 19);
	graph.set_edge(16, 17);
	graph.set_edge(17, 18);
	graph.set_edge(18, 19);

	GraphColoring g;
	int m = 3;
	std::vector<int> coloring(graph.get_number_of_nodes(), NO_COLOR);

	g.color_improved(graph, m, 0, coloring);
	std::cout << "IMPROVED function call count: " << g.improved_counter << "\n";
	std::cout << "====================================================\n";
	g.color_old(graph, m, 0, coloring);
	std::cout << "OLD function call count: " << g.old_counter << "\n";


}