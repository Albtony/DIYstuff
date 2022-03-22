# Title			: ROT decoder/encoder
# Description	: subtitute aplha char x with char x + value and vice versa
# Reference 	: https://en.wikipedia.org/wiki/ROT13

from function import *

# main section
def main():
	ROTstring  = input("enter ROT string: ")
	ROTvalue = int(input("enter ROT value: "))

	print(f'your result is {ROT(ROTstring, ROTvalue)}')

if __name__ == "__main__":
    main()