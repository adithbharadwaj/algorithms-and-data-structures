
def rod(val, length):

	a = [[0 for j in range(length + 1)] for i in range(len(val) + 1)]

	for i in range(len(val) + 1):
		for j in range(length + 1):

			if(i == 0 or j == 0):
				a[i][j] = 0

			elif(j >= i):
				a[i][j] = max(a[i - 1][j], val[i - 1] + a[i][j - i])
			else:
				a[i][j]	= a[i - 1][j]

	print(a[len(val)][length])		
	

if __name__ == '__main__':

	price = [1, 5, 8, 9, 10, 17, 17, 20]
	length = 8

	rod(price, length)	