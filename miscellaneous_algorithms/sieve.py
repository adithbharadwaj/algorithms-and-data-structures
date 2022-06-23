
# sieve of eratosthenes for generating prime numbers < n

n = int(input('enter the number'))
print()

a = [True for i in range(n + 1)]
p = 2

while(p*p < n):

	if(a[p] == True):

		for i in range(p + p, n+1, p):
			a[i] = False

	p += 1

for i in range(2, n):
	
	if(a[i] == True):
		print(i, end = ' ')			

print()
