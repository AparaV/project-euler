'''
Problem 065: Convergents of e
Author: Aparajithan Venkateswaran
'''
from time import time

'''
By writing out the fractions, we can deduce the following pattern:
    n(k+1) = a(k) * n(k-1) + n(k-2)
'''

def answer():
	d = 1
	n = 2
	
	for i in range(2, 101):
		temp = d
		c = 1
		if i % 3 == 0:
			c = 2 * int(i / 3)
		d = n
		n = c * d + temp
	
	return sum(int(i) for i in str(n))

if __name__ == "__main__":
	
	begin = float(time()) * 1000
	solution = answer()
	elapsed = float(time()) * 1000 - begin
	print "The answer is", solution
	print "It took", elapsed, "ms"