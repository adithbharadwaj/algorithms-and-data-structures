
# bst in python

class node:

	def __init__(self, val):
		self.left = None
		self.right = None
		self.data = val


def insert(root, val):

	if root is None:
		n = node(val)
		root = n
		return root

	n = node(val)

	if(val < root.data):
		root.left = insert(root.left, val)
	else:
		root.right = insert(root.right, val)

	return root				


def inorder(root):

	if root is not None:

		inorder(root.left)
		print(root.data)
		inorder(root.right)


def preorder(root):

	if root is not None:

		print(root.data)
		preorder(root.left)
		preorder(root.right)

def postorder(root):

	if root is not None:

		postorder(root.left)
		postorder(root.right)
		print(root.data)

if __name__ == '__main__':


	root = node(5)

	insert(root, 4)
	insert(root, 6)
	insert(root, 3)
	insert(root, 7)
	insert(root, 2)
	insert(root, 8)
	insert(root, 1)
	insert(root, 9)

	inorder(root)
	print("----------------------------")
	preorder(root)
	print('----------------------------')
	postorder(root)