# function section
def ROT(string, value):
	UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	LOWER = "abcdefghijklmnopqrstuvwxyz"
	result = ""
	for char in string:
		if char.islower():
			result += LOWER[(ord(char) % 97 + value) % 26]
		elif char.isupper():
			result += UPPER[(ord(char) % 65 + value) % 26]
		else:
			result += char
	return result