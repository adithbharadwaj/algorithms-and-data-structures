# segment tree for range queries. 

# getting the max value in the given range
def getmax(node, ss, se, qs, qe, i):
    
    '''
    ss -> starting index of the range of values of the current node
    se-> ending index of the range of values contained in the current node
    qs-> starting index of the query
    qe-> ending index of the query
    '''
    # if the query is out of range of the current node.
    if(se < qs or ss > qe):
        return 0

    # if the query is entirely within the range of the current node. 
    elif(qs <= ss and qe >= se):
        return node[i]

    # if both the above conditions are not satisfied, then we need to send the query to the left child and right child
    # left = 2*i + 1, right = 2*i + 2. ranges of the left and right child will be [ss, mid] and [mid + 1, se] respectively
    mid = (ss + se)//2
    
    # return the maximum of left and right chuld. 
    return max(getmax(node, ss, mid, qs, qe, 2*i + 1), getmax(node, mid+1, se, qs, qe, 2*i + 2))


def update(node, val, ss, se, i):

    # if the element is not in the range of this node
    if(i< ss or i > se):
        return

    # update the value of this node if i is in its range
    node[i] = node[i] + val
    mid = (ss + se)//2
    # if this is not a leaf node, then update its children.
    if(ss != se):
        update(node, val, ss, mid, 2*i + 1)
        update(node, val, mid + 1, se, 2*i + 2)

def construct(a, l, r, node, i):
    # if there is only one element. i.e left = right
    if(l == r):
        node[i] = a[l]
        return a[l]

    mid = (l + r)//2
    
    # setting the current node to the maximum of the left and right nodes.    
    node[i] = max(construct(a, l, mid, node, 2*i + 1), construct(a, mid + 1, r, node, 2*i + 2))
    # returning the current node after recurion.
    return node[i]

# height of the segment tree. approx log2(n)
h = int(math.log2(n) + 1)
# size will be power(2, height)
size = 2*2**h - 1
# node contains the value of the nodes in the tree
node = [0 for i in range(size)]

construct(arr, 0, n - 1, node, 0)