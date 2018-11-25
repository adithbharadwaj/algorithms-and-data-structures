
# longest increasing subsequence using dp


def lis(s):

	n = len(s)

	a = [1] * n

	for i in range(1, n):
		for j in range(0, i):
			if(s[i] > s[j] and a[i] < a[j] + 1):
				a[i] = a[j] + 1

	print(max(a))	


if __name__ == '__main__':

	x = list(map(int, input().split()))

	lis(x)
				
