
# knapsack problem using dp

def knapsack(weights, values, c):

	a = [[0 for k in range(c + 1)] for x in range(len(weights) + 1)]

	for i in range(len(weights) + 1):
		for j in range(c + 1):
			if(i == 0 or j == 0):
				a[i][j] = 0
			elif(weights[i - 1] > c):
				a[i][j] = a[i - 1][j]
			else:
				a[i][j]	= max(a[i - 1][j - weights[i - 1]] + values[i - 1], a[i - 1][j])

	print("ans", a[len(weights)][c])


weights = list(map(int, input().split()))
values = list(map(int, input().split()))
c = int(input())

knapsack(weights, values, c)					

