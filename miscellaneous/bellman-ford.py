
# bellman ford is used to find the single source shortest path is a graph with neg weights. time: O(v.e) 

def bellman(graph, weights, n, src):

	dist = [1000]*n

	dist[src] = 0

	for i in range(n - 1): # repeat v - 1 times.

		for u, v in graph: # for all the edges in the graph, update their dist.

			if(dist[u] != 1000 and dist[v] > dist[u] + weights[(u, v)]): # similar to dijkstra.
				dist[v] = dist[u] + weights[(u, v)]

	return dist			


graph = []

n = int(input('enter the no. of vertices'))

e = int(input('enter the number of edges'))

weights = {}

for i in range(e):
	edge = list(map(int, input().split()))
	graph.append([edge[0], edge[1]])
	weights[(edge[0], edge[1])] = edge[2]

ans = bellman(graph, weights, n, 0)	

print(ans)