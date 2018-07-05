# program to construct minesweeper.
# arguments : a 2d list containing the locations of bombs. no of rows, no. of columns.


def minesweeper(bombs, row, col):

	a = [[0 for i in range(col)] for j in range(row)]
	
	# for every bomb location in the list
	for i,j in bombs:

		# iterate over the 3x3 cells surrounding the bomb
		for x in range(i - 1, i + 2):
			for y in range(j - 1, j + 2):
				# if the cell is in range, increment the count of that cell by 1
				if(x >= 0 and y >= 0 and x < row and y < col):
					a[x][y] += 1

				# if the cell is out of range, ignore it and move on.	

	# we give -1 to the location of a bomb.			
	for i,j in bombs:
		a[i][j] = -1	
		
	# print the solution.	
	for i in range(row):
		for j in range(col):
			print(a[i][j], end = '\t')
		print()		



if __name__ == '__main__':

	
	minesweeper([[1, 0], [1, 4], [2, 3]], 4, 5)	
