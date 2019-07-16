
# verify if there is a path between two vertices in an undirected graph.

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
	visited[c[0]] = False
	visited[c[1]] = False

path = list(map(int, input().split()))

if ([path[0], path[1]]) in d:
	ans = 1

a = 0

def hasPath(x, y):

	visited[x] = True
   	
	for i in graph[x]:
		if visited[i] == False:
			hasPath(i, x)	


x = path[0]
y = path[1]

hasPath(x, y)

if visited[path[1]] == True:
	print(1)
else:
	print(0)

		
