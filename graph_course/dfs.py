
#dfs for undirected graph.

from collections import defaultdict # to use a dictionary of lists

numbers = list(map(int, input().split())) # this line is used to get a line of integers as a list

graph = defaultdict(list) # making an adjacency list used to represent graphs
visited = dict()
d = list()

for i in range(numbers[1]):
	c = (list(map(int, input().split())))
	d.append(c)
	graph[c[0]].append(c[1]) # here i'm adding both the vertices as an edge since this is an undirected graph. i.e, there's a connection 
	graph[c[1]].append(c[0]) # between a,b and b,a. if it is directed graph, then there's only one connection
	visited[c[0]] = False
	visited[c[1]] = False

def Dfs(x):

	if(visited[x] == False):
		print(x)
	
	visited[x] = True

	for i in graph[x]:
		if visited[i] == False:
			Dfs(i)
	

for i in range(1, len(graph)):
	Dfs(i)
