'''
Fast exponentiation or modular exponentiation (mod = 10**9 + 7)

recursive function that returns a^n
if n is even, then a^n = a^n/2 * a^n/2
else a^n = a^n/2*a^n/2*a
(divide and conquer so that we dont have to compute the values twice)

time complexity = o(logn)

'''

def exp(a, n, mod):

	if(n == 0):
		return 1
	elif(n == 1):
		return a

	x = exp(a,n//2, mod)
	if(n % 2 == 0):
		x = (x * x)%mod
	else:
		x = (x * x * a)%mod
	
	return x


#print(exp(10, 2, 10**9 + 7))