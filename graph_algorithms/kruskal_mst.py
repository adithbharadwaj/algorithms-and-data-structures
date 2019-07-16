
# kruskal's algorithm to find minimum spanning tree of the given graph using disjoint set data structure. (hackerrank verfied)

from collections import defaultdict
import math

class Disjoint:  # implementation of disjoint set 

    parent = dict()

    def __init__(self, n):
        for i in range(1, n + 1):
            self.parent[i] = i

    def find(self, a):

        if(self.parent[a] == a):
            return a
        
        return self.find(self.parent[a])    

    def union(self, a, b):

        x = self.find(a)
        y = self.find(b)    

        self.parent[x] = y


numbers = list(map(int, input().split()))

graph = defaultdict(list)
weights = dict()

def kruskal(numbers, weights):
    
    sets = Disjoint(numbers[0])
    ans = list()
     
    for i in range(len(weights)):  # repeat no. of edges times.
        
        m = math.inf
        for i in weights:        # finding the edge that corresponds to minimum weight
            if(weights[i] < m):
                m = weights[i]
                edge = i
        
        x = edge[0]
        y = edge[1]

        del weights[(x, y)]   # deleting the minimum edge so that in the next iteration, the next min edge can be found.

        if(sets.find(x) != sets.find(y)):  # verifying if there's a cycle in the min edge by using find method(disjoint set)
            ans.append(m)           # if there is no cycle, then we add the wiight of the edge to our ans list.    
            sets.union(x, y)          # now we add the edge to out set. 
    
    return ans
    
e = list()    

for i in range(numbers[1]):

    edge = list(map(int, input().split()))
    
    if((edge[0], edge[1]) in weights):
        if(weights[(edge[0], edge[1])] > edge[2]):
            weights[(edge[0], edge[1])] = edge[2]
    else:  
        weights[(edge[0], edge[1])] = edge[2]

a = kruskal(numbers, weights)
s = 0

for i in a: # adding up the weights of the edges of the mst formed. 
    s += i    

print(s)     
           
    