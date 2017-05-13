'''
Problem 055: Lychrel numbers
Author: Aparajithan Venkateswaran
'''

from sets import Set
from time import time


def isPalindrome(num, base):
    reverse = 0
    temp = num
    while temp > 0:
		reverse = base * reverse + temp % base
		temp = temp / base
    if num == reverse:
        return True
    else:
        return False

def answer():
    nonLychrels = Set()
    lychrels = Set()

    for i in range(1,10000):
        iters = 1
        num = i
        nonLychrel = False
        chain = []

		# iterate 50 times
        while iters < 50 and nonLychrel == False:
			# get reverse
            reverse = 0
            temp = num
            while temp > 0:
                reverse = reverse * 10 + (temp % 10)
                temp = temp / 10
            chain.append(num)
            chain.append(reverse)
			# check if it is a non lychrel
            if (num in nonLychrels) or (isPalindrome(num + reverse, 10)):
                nonLychrel = True
			# update num and check if its a palindrome
            num = num + reverse
            iters = iters + 1
        # end while

        # add to non-lychrels if non lychrel
        if nonLychrel:
            for num in chain:
                nonLychrels.add(num)
        else:
            lychrels.add(chain[0]);
    # end for loop

    return len(lychrels)

if __name__ == "__main__":
    begin = float(time()) * 1000
    solution = answer()
    elapsed = float(time()) * 1000 - begin
    print "The answer is", solution
    print "It took", elapsed, "ms"
