
# finding the shortest path between two vertices in an undirected graph using bfs and maintaining a record of the previous nodes 
# of a particular node by using a prev list. then, we go from the final node (y) to x by using prev and find the shortest path 
# if it exists. we basically construct a shortest path tree and move back from the final node to the root node(x).

from collections import defaultdict
import queue

numbers = list(map(int, input().split()))

graph = defaultdict(list)
dist = list()
prev = list()

for i in range(numbers[1]):
	edge = list(map(int, input().split()))
	graph[edge[0]].append(edge[1])
	graph[edge[1]].append(edge[0]) # undirected graph

shortest = list(map(int, input().split()))

def bfs(x):

	q = queue.Queue()
	
	global graph
	global dist
	global prev

	dist = [-1] * (numbers[0] + 1)
	dist[x] = 0
	prev = [-1] * (numbers[0] + 1)

	q.put(x)

	while (not q.empty()):
		vertex = q.get()
		for i in graph[vertex]:
			if(dist[i] == -1):
				q.put(i)
				dist[i] = dist[vertex] + 1
				prev[i] = vertex	


def path(x, y):
	
	global dist
	global prev

	result = 0

	if(dist[x] == -1): # if there is no path between x and y. i.e, they are disconnected components.
		print(-1)
		return

	while(x != y):
		x = prev[x]
		result += 1

	print(result)
	return	

bfs(shortest[0])
path(shortest[1], shortest[0])	