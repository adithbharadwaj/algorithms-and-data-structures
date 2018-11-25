# nqueens using backtracking

def isSafe(a, r, c, n):

	for i in range(c):		
		if(a[r][i] == 1):
			return False

	for i, j in zip(range(r, -1, -1), range(c, -1, -1)):
		if(a[i][j] == 1):
			return False			

	for i, j in zip(range(r, n), range(c, -1, -1)):
		if(a[i][j] == 1):
			return False		

	return True

def queen(a, n, c):
	
	if(c >= n):
		return True

	for i in range(n):

		if(isSafe(a, i, c, n)):

			a[i][c] = 1

			if(queen(a, n, c + 1) == True):
				return True

			a[i][c] = 0

	return False			

if __name__ == '__main__':

	n = int(input('enter the size'))

	a = [[0 for j in range(n)] for i in range(n)]

	queen(a, n, 0)

	for i in range(n):
		for j in range(n):
			print(a[i][j], end = ' ')

		print()	




