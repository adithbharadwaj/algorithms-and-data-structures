
# bfs of a Directed graph using queues. 

from collections import defaultdict
import queue

numbers = list(map(int, input().split()))

graph = defaultdict(list)
dist = list() # list to keep track of the distance of the nodes from the root node. 

for i in range(numbers[1]):
	edge = list(map(int, input().split()))
	graph[edge[0]].append(edge[1])


def bfs(x):

	q = queue.Queue()
	
	global graph
	global dist

	dist = [-1] * (numbers[0] + 1)

	q.put(x)
	dist[x] = 0

	while (not q.empty()):
		vertex = q.get()
		print(vertex)
		for i in graph[vertex]:
			if(dist[i] == -1):
				q.put(i)
				dist[i] = dist[vertex] + 1
				

bfs(1)
print(dist)