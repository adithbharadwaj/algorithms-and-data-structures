#include<iostream>
#include<vector>

using namespace std;

int main(){

	int n;
	cout << "enter the number of vertices " << endl;
	cin >> n;

	vector<int> graph[n];

	cout << "enter the number of edges" << endl;
	int e;
	cin >> e;

	int weights[n][n];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			weights[i][j] = 10000;
		}
	}

	for(int i = 0; i < e; i++){
		int u, v, w;
		cin >> u >> v >> w;
		weights[u][v] = w;
		weights[v][u] = w;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int src = 0, cost = 0;

	vector<bool> visited(n, false);
	vector<int> key(n, 10000);
	key[src] = 0;

	for(int i = 0; i < n; i++){
		int min = 10000;
		int v;
		
		// finding the vertex that corresponds to minimum key(value of edge).

		for(int j = 0; j < n; j++){
			if(visited[j] == false && key[j] < min){
				min = key[j];
				v = j;
			}
		}

		// making the vertex visited(adding it to our list of vertices)

		visited[v] = true;
		cost += min;

		// updating the value of key for all the vertices connected to the minimum vertex.

		for(int j = 0; j < n; j++){
			if(visited[j] == false && weights[v][j] < key[j]){
				key[j] = weights[v][j];
			}
		}

	}

	cout << cost << endl;

	return 0;
}