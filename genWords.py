from random import randint, choice
from sys import argv, exit

if __name__ == '__main__':
	if len(argv) < 5:
		print(argv[0] + " FILE LINES WORDS NL")
		exit(0)
	file = open(argv[1], 'w');

	fdictionary = open("words.txt", 'r')
	dictionary = fdictionary.read().split('\n')
	fdictionary.close()
	nl = bool(argv[4])

	for i in range(int(argv[2])):
		for j in range(int(argv[3])):
			file.write(choice(dictionary) + ' ')
		if nl:
			file.write('\n')

	file.close()
