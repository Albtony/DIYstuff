def findCoPrime(n):
	pfactor = primeFactors(n)
	pnow = pfactor[0]
	for prime in pfactor:
		if pnow != prime:
			return pnow
		pnow = findNextPrime(pnow)
	return pnow

def findNextPrime(n):
	for number in range(n + 1, 2 * n):
		if isPrime(number): 
			return number
	return None

def isPrime(n):
	for i in range(2, int(math.sqrt(n))+1):
		if (n % i == 0):
			return False
	return True

def primeFactors(n):
	pfactor = []
	if n % 2 == 0:
		pfactor.append(2)
		while n % 2 == 0:
			n /= 2

	for denom in range(3, int(math.sqrt(n))+1, 2):
		if n % denom == 0:
			pfactor.append(denom)
			while n % denom == 0:
				n = n / denom
    
	return pfactor