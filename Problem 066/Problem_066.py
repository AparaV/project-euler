'''
Problem 066: Diophantine Equation
Author: Aparajithan Venkateswaran
'''

from time import time
import math

def perfect_square(x):
    temp = math.sqrt(x)
    if temp == math.ceil(temp):
        return True
    return False

def answer():
    x_max = 0
    result = 0

    for D in range(1000,1,-1):
        S = (int)((math.sqrt(D)))
        if S * S == D:
            continue

        m = 0
        d = 1
        a = S
        num1 = 1
        num = a
        den1 = 0
        den = 1

        while num*num - D*den*den != 1:
            m = d * a - m
            d = (int)((D - m * m) / d)
            a = (int)((S + m) / d)

            num2 = num1
            num1 = num
            den2 = den1
            den1 = den

            num = a*num1 + num2
            den = a*den1 + den2

        if num > x_max:
            x_max = num
            result = D

    return result

if __name__ == "__main__":

    begin = float(time()) * 1000
    solution = answer()
    elapsed = float(time()) * 1000 - begin
    print("The answer is %s" %(str(solution)))
    print("It took %f ms" %(elapsed))
