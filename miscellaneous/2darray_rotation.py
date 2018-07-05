
# rotating a 2d array by 90 degrees. 

# function to print array
def printarr(a):

	for i in range(len(a)):
		for j in range(len(a[0])):
			print(a[i][j], end = ' ')

		print()

# function to rotate the array in place without using a temporary 2d array. (no extra memory)
def inplace(a):

	x, y = 0, 0

	for j in range(len(a)):
		y = 0
		for i in range(len(a) - 1, -1, -1):

			if(i != len(a) - 1 - i and j != len(a) - j - 1):
				a[i][j], a[x][y] = a[x][y], a[i][j]
				y += 1

		x += 1

	

	a[0][0], a[len(a) - 1][len(a) - 1] = a[len(a) - 1][len(a) - 1], a[0][0]		

	printarr(a)			



# function to rotate the array out of place. i.e, using an auxillary array. (extra memory).
def outofplace(a):

	b = [[0 for i in range(len(a))] for j in range(len(a))]

	x, y = 0, 0

	for j in range(len(a)):
		y = 0
		for i in range(len(a)-1, -1, -1):
			
			b[x][y] = a[i][j]
			y += 1

		x += 1	

	
	printarr(b)	


if __name__ == '__main__':
	
	a = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]

	inplace(a)


# printarr(a)

