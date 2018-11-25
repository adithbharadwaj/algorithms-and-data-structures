

def isSafe(a, r, c, n):

	# checking rows for the same number
	for i in range(9):
		if(a[r][i] == n):
			return False

	# checking columns for the same number		
	for i in range(9):
		if(a[i][c] == n):
			return False

	# to check if a subgrid of size 3x3 has the number or not (this is also the condition to solve sudoku)		
	
	'''
	for i in range(3):
		for j in range(3):
			if(a[(r - r%3) + i][(c - c%3) + j] == n):
				return False
	'''

	return True			


def completed(a):

	# function to check if the puzzle is completed or not. 
	# it is completed when all the cells are assigned with a number(not zero)

	for i in range(9):
		for j in range(9):
			if(a[i][j] == 0):
				return False

	return True
				

def findEmptyLocation(a):

	# finding an empty location so that we can assign a number for that particular row and column.

	for i in range(9):
		for j in range(9):
			if(a[i][j] == 0):
				return i, j	


def sudoku(a):

	if(completed(a)):
		return True

	r, c = findEmptyLocation(a)	# finding an empty location.

	for i in range(1, 10):	
		
		if(isSafe(a, r, c, i)):

			a[r][c] = i

			if(sudoku(a)):
				return True

			a[r][c] = 0
	
	return False			


t = int(input())


for i in range(t):

	b = list(map(int, input().split()))

	a = [[0 for x in range(9)] for y in range(9)]

	ind = 0
	for i in range(9):
		for j in range(9):
			a[i][j] = b[ind]
			ind += 1

	sudoku(a)

	for i in range(9):
		for j in range(9):
			print(a[i][j], end = ' ')

		print()

	print()
	


