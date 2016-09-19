#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using std::string;
using std::vector;
using std::list;
using std::unordered_set;
using std::cout;
using std::cin;

class Node
{
public:
	explicit Node(string vertex) 
	{
		this->vertex = vertex;
	}

	void addAdjacent(Node* node) 
	{
		adjacent.push_back(node);
	}

	int adjacentCount() 
	{
		return adjacent.size();
	}
public:
	enum class State
	{
		Unvisited,
		Visited,
		Visiting
	};
	State state = State::Unvisited;
	vector<Node*> adjacent;
private:
	string vertex;
};
