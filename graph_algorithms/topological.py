
# topologcal sorting for DIRECTED ACYCLIC GRAPH. here, if there is an edge (u,v) then u is visited first before v
# here, the starting vertex (the one printed first) is the vertex with no incoming edges. i.e, all vertices with no
# incoming edges are printed first. we use dsf and store the unvisited vertices in a stack at the end so that vertices with incoming 
# edges are stored first and onews with outgoing edges only are stored last. then we pop the stack elements one by one and print.

#  1 --- > 2 ---- > 3
#  ^       ^
#  |       | 
#  4 --- > 5    

# output = 4, 5, 1, 2, 3 

from collections import defaultdict

numbers = list(map(int, input().split()))

graph = defaultdict(list)
visited = dict()
stack = list()

for i in range(numbers[1]):
	edge = list(map(int, input().split()))
	graph[edge[0]].append(edge[1])


def dfs(x):

	global graph
	global visited
	global stack

	visited[x] = True	

	for i in graph[x]:
		if(visited[i] == False):
			dfs(i)

	stack.append(x)		

def topological():

	global graph
	global visited
	global stack

	for i in range(numbers[0] + 1):
		visited[i] = False

	for i in range(1, numbers[0] + 1):
		if(visited[i] == False):
			dfs(i)

	
	for i in range(len(stack)):
		print(stack.pop())		

topological()



