
# program to generate all the subsets of a given set or array.

n = int(input('enter the number of elements\n'))

a = list(map(int, input().split()))

size = 2 ** n

for i in range(1, size):

    for j in range(n):

        if(1 << j & i):
            print(a[j], end = ' ')

    print()

            