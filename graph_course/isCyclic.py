
# program to check whether the given graph is cyclic or not using dfs

from collections import defaultdict

numbers = list(map(int, input().split()))

graph = defaultdict(list)
visited = dict()
record = dict()

for i in range(numbers[1]):
	edge = list(map(int, input().split()))
	graph[edge[0]].append(edge[1])


def dfsUtil(i, record, visited, graph):

	if(visited[i] == False):
  		
  		visited[i] = True
  		record[i] = True

  		for j in graph[i]:
  			if(visited[j] == False and dfsUtil(j, record, visited, graph) == True):
  				return True	
  			elif(record[j] == True):
  				return True

	record[i] = False
	return False						 			
	

def hasCycle(visited, record, graph):

	for i in range(numbers[0] + 1):
		visited[i] = False
		record[i] = False


	for i in range(1, numbers[0] + 1):
		if(dfsUtil(i, visited, record, graph)):
			return True


	return False


if(hasCycle(visited, record, graph) == True):
	print('1')
else:
	print('0')		


