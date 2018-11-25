
# dijkstra's algorithm using arrays to find min value(v^2) runtime. using undirected graphs and a number of test cases.(hackerrank verified)

from collections import defaultdict
#import heapq
import math

def dijkstra(s, numbers, graph, weights, determined, dist):
    
        vertices = range(1, numbers[0] + 1)

        for i in range(1, numbers[0] + 1):
            dist[i] = math.inf
            determined[i] = False

        dist[s] = 0

        for count in range(numbers[0]):
            mval = math.inf
            index = 0
            for j in range(1, numbers[0] + 1):
                if(determined[j] == False and dist[j] < mval):
                    mval = dist[j]
                    index = j
            
            determined[index] = True

            if(mval == math.inf):
                break

            for i in graph[index]:
                if((dist[index] + weights[(index, i)] < dist[i]) and determined[i] == False ):
                    dist[i] = dist[index] + weights[(index, i)]
                    
        
        #printing the min distance of every vertex except the source vertex 
        for i in dist:
            if(i != s):
                if(dist[i] == math.inf):
                    print(-1, end = " ")
                else:
                    print(dist[i], end = " ")
        print()       


# number of test cases(queries)

test = int(input())           
        
for i in range(test):
    
    graph = defaultdict(list)
    dist = dict()
    weights = {}
    determined = dict()
    
    numbers = list(map(int, input().split()))

    for i in range(numbers[1]):
        edge = list(map(int, input().split()))
        
        if((edge[0], edge[1]) in weights):
            if(weights[(edge[0], edge[1])] > edge[2]):
                weights[(edge[0], edge[1])] = edge[2]
                weights[(edge[1], edge[0])] = edge[2]
                graph[edge[0]].append(edge[1])
                graph[edge[1]].append(edge[0])
        else:  
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
            weights[(edge[0], edge[1])] = edge[2]
            weights[(edge[1], edge[0])] = edge[2]

    path = int(input())
    
    dijkstra(path, numbers, graph, weights, determined, dist)
    
    
        
        
    
