
# finding the number of conncected components in a given undirected graph

from collections import defaultdict

numbers = list(map(int, input().split()))

graph = defaultdict(list)	
visited = dict()
d = list()

for i in range(numbers[1]):
	c = (list(map(int, input().split())))
	d.append(c)
	graph[c[0]].append(c[1])
	graph[c[1]].append(c[0])

def hasPath(x):

	visited[x] = True
   	
	for i in graph[x]:
		if visited[i] == False:
			hasPath(i)	

def dfs():

	count = 0

	for i in range(numbers[0] + 1):	
		visited[i] = False

	for i in range(1, numbers[0] + 1):
		if(visited[i] == False):
			hasPath(i)	
			count += 1

	print(count)
			
dfs()