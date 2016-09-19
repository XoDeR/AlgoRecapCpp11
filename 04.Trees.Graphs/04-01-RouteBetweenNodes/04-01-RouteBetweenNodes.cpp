#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using std::string;
using std::vector;
using std::deque;
using std::unordered_set;
using std::cout;
using std::cin;

#include "Graph.h"

bool search(Graph& g, Node* start, Node* end)
{
	if (start == end)
	{
		return true;
	}

	deque<Node*> queue;

	for (Node* node : *g.vertices) 
	{
		node->state = Node::State::Unvisited;
	}

	start->state = Node::State::Visiting;
	queue.push_back(start);
	Node* temp = nullptr;
	while (!queue.empty()) 
	{
		temp = queue.back();
		queue.pop_back();
		if (temp != nullptr) 
		{
			for (Node* adjacent : temp->adjacent) 
			{
				if (adjacent->state == Node::State::Unvisited) 
				{
					if (adjacent == end) 
					{
						return true;
					}
					else 
					{
						adjacent->state = Node::State::Visiting;
						queue.push_back(adjacent);
					}
				}
			}
		}
		temp->state = Node::State::Visited;
	}
	return false;
}

int main()
{
	Graph g;
	vector<Node*> nodes = 
	{
		new Node("0"), new Node("1"), new Node("2"), new Node("3"), new Node("4"), new Node("5")
	};

	nodes[0]->addAdjacent(nodes[1]);
	nodes[0]->addAdjacent(nodes[4]);
	nodes[0]->addAdjacent(nodes[5]);
	nodes[1]->addAdjacent(nodes[4]);
	nodes[1]->addAdjacent(nodes[3]);
	nodes[2]->addAdjacent(nodes[1]);
	nodes[3]->addAdjacent(nodes[2]);
	nodes[3]->addAdjacent(nodes[4]);

	g.vertices = &nodes;
	g.count = 6;

	cout << search(g, nodes[0], nodes[3]);
	cout << search(g, nodes[3], nodes[5]);

	// cleanup, dealloc memory
	for (auto& node : nodes)
	{
		delete node;
	}

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
