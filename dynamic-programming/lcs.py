

# longest common subsequence problem using dp

def lcs(x, y):

	l1 = len(x)
	l2 = len(y)

	a = [[0] *(l2 + 1)] *(l1 + 1)

	for i in range(l1 + 1):
		for j in range(l2 + 1):

			if(i == 0 or j == 0):
				a[i][j] = 0

			elif(x[i - 1] == y[j - 1]):
				a[i][j] = a[i - 1][j - 1] + 1
			else:
				a[i][j] = max(a[i - 1][j], a[i][j - 1])

	print(a[l1][l2])


x = input()
y = input()

lcs(x, y)