'''
Problem 057: Square root convergents
Author: Aparajithan Venkateswaran
'''
from time import time

'''
By writing out the fractions, we can deduce the following pattern:
    n(k+1) = n(k) + 2*d(k)
    d(k+1) = n(k) + d(k) = n(k+1) - d(k)
where n(k) and d(k) are the numerator and the denominator of the kth fraction
'''
def answer():
    num = 3
    den = 2
    counter = 0
    for i in range(1,1001):
        num = num + 2 * den
        den = num - den
        if len(str(num)) > len(str(den)):
            counter = counter + 1
    return counter

if __name__ == "__main__":
    begin = float(time()) * 1000
    solution = answer()
    elapsed = float(time()) * 1000 - begin
    print "The answer is", solution
    print "It took", elapsed, "ms"
