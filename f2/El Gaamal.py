import random
from math import pow

a = random.randint(2, 10)

# For calculating the GCD 
def GCD(a, b):
	if a < b:
		return GCD(b, a)
	elif a % b == 0:
		return b
	else:
		return GCD(b, a % b)

# For generating a key such that GCD(g,key) = 1
def key_gen(q):

	key = random.randint(pow(10, 20), q)
	while GCD(q, key) != 1:
		key = random.randint(pow(10, 20), q)

	return key

# Modular exponentiation
def mod_expo(a, b, c):
	x = 1
	y = a

	while b > 0:
		if b % 2 != 0:
			x = (x * y) % c
		y = (y * y) % c
		b = int(b / 2)

	return x % c

# Asymmetric Encryption
def Encryption(msg, q, h, g):

	en_msg = []

	k = key_gen(q)# Private key for sender
	s = mod_expo(h, k, q)
	p = mod_expo(g, k, q)
	
	for i in range(0, len(msg)):
		en_msg.append(msg[i])

	print("g^k used : ", p)
	print("g^ak used : ", s)
	for i in range(0, len(en_msg)):
		en_msg[i] = s * ord(en_msg[i])

	return en_msg, p

def Decrypt(en_msg, p, key, q):

	dr_msg = []
	h = mod_expo(p, key, q)
	for i in range(0, len(en_msg)):
		dr_msg.append(chr(int(en_msg[i]/h)))
		
	return dr_msg

# Driver code
def main():

	msg = 'How you doing ?'
	print("Original Message :", msg)

	q = random.randint(pow(10, 20), pow(10, 50))
	g = random.randint(2, q)

	key = key_gen(q)# Private key for receiver
	h = mod_expo(g, key, q)
	print("g used : ", g)
	print("h = g^a used : ", h)

	en_msg, p = Encryption(msg, q, h, g)
	dr_msg = Decrypt(en_msg, p, key, q)
	dmsg = ''.join(dr_msg)
	print("Decrypted Message :", dmsg);


if __name__ == '__main__':
	main()
