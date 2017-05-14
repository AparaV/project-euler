'''
Problem 056: Powerful Digit sum
Author: Aparajithan Venkateswaran
'''

from time import time


def answer():
    maxSum = 0
    for a in range(1,100):
        if a == 1 or a == 10 or a == 100:
            continue
        for b in range(1,100):
            power = pow(a, b)
            cSum = sum(int(x) for x in str(power))
            if cSum > maxSum:
                maxSum = cSum
    return maxSum

if __name__ == "__main__":
    begin = float(time()) * 1000
    solution = answer()
    elapsed = float(time()) * 1000 - begin
    print "The answer is", solution
    print "It took", elapsed, "ms"
