
# catlan numbers: c[n + 1] = sigma(c[i]*c[n - i]) for i = 0 to n
# solved using dp. c[0], c[1] = 1.

def catlan(n, a):
	if(n <= 1):
		a[n] = 1
		return a[n]

	ans = 0
	for i in range(n):
		s = 1
		if(a[i] != -1):
			s = a[i]
		else:
			s = catlan(i, a)
			a[i] = s
		if(a[n - i - 1] != -1):
			s = s*a[n - i - 1]
		else:
			temp = catlan(n - i - 1, a) 
			s = s*temp
			a[n - i - 1] = temp
		ans += s
	a[n] = ans
	return ans

n = int(input('enter the value of n: (nth term of the number) '))
a = [-1 for i in range(n + 1)]

print(catlan(n, a))