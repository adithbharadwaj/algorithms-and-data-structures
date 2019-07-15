'''
Quick select algorithm to print the kth smallest element in a list.
average and best case = O(n)
worst case = O(n*n)

Works based on quick sort. instead of completely sorting the array, we stop when the pivot element is equal to k.
This works because the pivot element is the kth element in the sorted array (all elements less than the pivot are towards the left)
Therefore, the pivot itself is the kth smallest element. 
When the pivot is greater than k, then we only need to consider the left subarray. else, the right subarray.
we only consider one subarray at a time since we dont need to completely sort the array.
Partition function remains the same as quick sort.

'''

import random

def partition(a, l, h):

	pivot = a[h]
	i = l
	for j in range(l, h):
		if(a[j] <= pivot):
			a[i], a[j] = a[j], a[i]
			i += 1

	a[i], a[h] = a[h], a[i]
	return i

def quickselect(a, l, r, k):

	if(k > 0 and k <= r - l + 1):

		pivot = random_partition(a, l, r)
		length = pivot - l + 1 # subtracting l because: when we iterate through the second half, we need to find the pivot - l + 1 th
								# smallest element (which is the kth element from the beginning)

		if(length == k):
			return a[pivot]

		elif(length < k):
			return quickselect(a, pivot + 1, r, k - length)
		else:
			return quickselect(a, l, pivot - 1, k)

def random_partition(a, l, h):
	rand_index = random.randint(l, h)
	a[rand_index], a[h] = a[h], a[rand_index]
	return partition(a, l, h)

if __name__ == '__main__':

	a = list(map(int, input('Enter the elements \n').split()))
	k = int(input('Enter the value of k  \n'))

	print('kth smallest element is: ', quickselect(a, 0, len(a) - 1, k))
