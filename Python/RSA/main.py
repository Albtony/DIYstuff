# Title 		: RSA algorithm
# Description 	: super simple RSA algorithm that obviously fails on large numebr
# https://www.educative.io/edpresso/what-is-the-rsa-algorithm

#!/usr/bin/python
from function import *

# main section
def main():
	x = int(input("first prime number: "))
	y = int(input("second prime number: "))
	num = int(input("number to encrypt: "))

	e, pub, priv = RSA(x, y, num)
	print(f'encrypted :{e}')
	print(f'public_key :{pub}')
	print(f'private_key :{priv}')

if __name__ == "__main__":
	main()