#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using std::string;
using std::vector;
using std::deque;
using std::cout;
using std::cin;

vector<int> visited;
vector<vector<int>> matrix;
deque<int> out;

void dfs(int u, int V) 
{
	if (visited[u] == 0) 
	{
		visited[u] = 1;
		for (int i = 0; i < V; i++) 
		{
			if (matrix[u][i] == 1 && visited[i] == 0)
			{
				dfs(i, V);
			}
		}
		out.push_front(u);
	}
}

deque<int> build(vector<int>& projects, vector<vector<int>>& dependencies, int V, int E)
{
	out.clear();
	visited.clear();
	visited.resize(V);
	std::fill(visited.begin(), visited.end(), 0);
	matrix.clear();
	matrix.resize(V + 1);
	for (int i = 0; i < V + 1; ++i)
	{
		matrix[i].resize(V + 1);
		std::fill(matrix[i].begin(), matrix[i].end(), 0);
	}
	for (int i = 0; i < E; ++i) 
	{
		int edge1 = dependencies[i][0];
		int edge2 = dependencies[i][1];
		matrix[edge2][edge1] = 1;
	}
	for (int i = 0; i < V; i++) 
	{
		if (visited[i] == 0)
		{
			dfs(i, V);
		}
	}
	return out;
}

int main()
{
	vector<int> projects1 = {1, 2, 3, 4, 5, 6, 7};
	vector<vector<int>> dependencies1 = {{3, 0}, {1, 5}, {3, 1}, {0, 5}, {2, 3}};
	int V = 6;
	int E = 5;
	deque<int> list = build(projects1, dependencies1, V, E);
	for (int i = 0; i < V; i++)
	{
		cout << projects1[list[i]];
		if (i < V - 1)
		{
			cout << '\t';
		}
	}

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
