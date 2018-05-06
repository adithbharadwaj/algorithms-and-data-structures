
# kadane's algorithm for maximum contiguous subarray

def maxSubarray(a):

	s = 0
	m = 0
	
	for i in range(len(a)):

		s += a[i]

		if(s > m):
			m = s		

		if(s < 0):
			s = 0	

	if(m == 0):
		m = max(a)		

	return m			


if __name__ == "__main__":
    
    t = int(input().strip())
   
    for a in range(t):
        
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))

        print()
        print()
        
        result = maxSubarray(arr)
        
        print(result)