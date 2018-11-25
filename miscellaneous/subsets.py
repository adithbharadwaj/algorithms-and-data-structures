
n = int(input())

a = list(map(int, input().split()))

size = 2 ** n

for i in range(1, size):

    for j in range(n):

        if(1 << j & i):
            print(a[j], end = ' ')

    print()

            