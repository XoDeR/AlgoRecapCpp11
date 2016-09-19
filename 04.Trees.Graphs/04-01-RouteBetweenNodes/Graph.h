#include "Node.h"

class Graph
{
public:
	void add(Node* node) 
	{
		vertices->push_back(node);
		count++;
	}
	// not owning
	vector<Node*>* vertices = nullptr;
	int count = 0;
};
