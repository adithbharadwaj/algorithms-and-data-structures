
# algorithm to find negative cycles in a directed graph using bellman ford algorithm.

from collections import defaultdict
import queue
import math

numbers = list(map(int, input().split()))

graph = defaultdict(list)
dist = list()
prev = list()
weights = dict()

for i in range(numbers[1]):
	edge = list(map(int, input().split()))
	graph[edge[0]].append(edge[1])
	weights[(edge[0], edge[1])] = edge[2]

source = int(input())


def bellman_ford(s, graph, vertices, edges, weights):
	
	dist = dict()

	for i in range(1, vertices + 1):
		dist[i] = math.inf	

	dist[s] = 0

	# the following algorithm is the bellman ford algo to compute the min distances in a graph with negative weights.

	for i in range(vertices - 1):
		for j in range(1, edges + 1):
			for k in graph[j]:
				if(dist[j] != math.inf and dist[k] > dist[j] + weights[(j, k)]):
					dist[k] = dist[j] + weights[(j, k)]	

	# after the above iteration, the minimum possible distances of all the vertices has been computed(provided there are no cycles)
	
	for i in range(1, edges + 1):
		for j in graph[i]:
			if(dist[i] != math.inf and dist[j] > dist[i] + weights[(i, j)]): # if we can further decrease the distance of any particular
				print("negative cycle found")								# vertex, then there is a negative cycle in a graph
				return												      # cuz, if there's a negative cycle, dist keeps on decreasing.		

	print("No negative cycle")			


bellman_ford(source, graph, numbers[0], numbers[1], weights)	

