

'''
Given a list of non negative integers, arrange them such that they form the largest number.
For example:
Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

'''

from functools import cmp_to_key # converts a comparison function into a key for sorting.

# custom comparison function. since we cannot sort it in the normal way, if we have x, y as two inputs,
# we need to see if xy > yx. if so, then we return -1 (since we are sorting in reverese order. return 1 if we need to sort in ascending)
# this is because when sorting, we need to compare the digits of the two numbers starting from the leftmost to the rightmost. 

def comp(x, y):
    t1, t2 = int(str(x) + str(y)), int(str(y) + str(x))
    return -1 if t1 > t2 else 1
        
def largestNumber(a):
    # sorting based on a custom comparator operator.    
	a.sort(key = cmp_to_key(comp))
	return ''.join(map(str, a))


a = list(map(int, input('enter the array ').split()))
print(largestNumber(a))
