# trie

class Node():

	def __init__(self):
		self.children = [None] * 26 # each node can have 26 children (number of letters in the english alphabet)
		self.isend = False # is this node the end of the word ? 

class Trie():

	def __init__(self):
		self.root = Node()

	# converting the character to an index in the range 0-25.
	def chartoindex(self, a):
		return ord(a) - ord('a')

	def insert(self, word):
		pcrawl = self.root # pointer to root
		levels = len(word) # length of the word

		# iterate throught the word
		for i in range(levels):
			index = self.chartoindex(word[i]) # get the ith character of word and convert it into index (0-25)
			if(not pcrawl.children[index]): # if the character doesn't already exist in the trie, create a node for that character.
				pcrawl.children[index] = Node()

			# set pcrawl to its child so that we can continue adding the rest of the word
			pcrawl = pcrawl.children[index]

		# dont forget to set isend to true cuz this is the end of the word. 
		pcrawl.isend = True

	# function to check if a word exists in the trie
	def search(self, key):
		pcrawl = self.root
		levels = len(key)
		# iterate through all the letters in the word.
		for i in range(levels):
			index = self.chartoindex(key[i]) # convert the char to its corresponding index.
			if(not pcrawl.children[index]): # if the character doesnt exist in the trie, then return false cuz the word is not there
				return False
			pcrawl = pcrawl.children[index]

		# in the end, check if pcrawl is not none and it is the end of the word. if yes, return true.
		return pcrawl != None and pcrawl.isend

	#function to get all the words of the trie.
	def get_all_words(self):
		r = self.root
		# temp stores the intermediate letters of the word during traversal.
		temp = []
		# res stores all the words.
		res = []
		# call the recursive function traverse.
		self.traverse(r, res, temp)
		# return all the words.
		return res

	def traverse(self, root, res, temp):
		if(root.isend == True): # if this is the end, then add temp to res.
			res.append(''.join(temp))
		for i in range(26): # iterate through all possible children.
			if(root.children[i]): # if the child exists, then append the corresponding char to temp.
				temp.append(chr(ord('a') + i)) # convert the index of the char to its corresponding char.
				self.traverse(root.children[i], res, temp) # recursively call the function on all its child nodes.
				temp.pop() # very important to pop the last letter from temp after recursion so that the previous word is not there.

if __name__ == '__main__':

	trie = Trie()
	trie.insert('keynote')
	trie.insert('key')
	trie.insert('far')
	trie.insert('farther')
	trie.insert('the')
	trie.insert('there')
	trie.insert('something')

	print(trie.search('abcd'), trie.search('z'), trie.search('klmno'), trie.search('abgh'))
	print(trie.get_all_words())


