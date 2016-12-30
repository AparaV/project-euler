'''
Problem 22 - Names Scores
Author: Aparajithan Venkateswaran
'''

value = {'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7, 'H': 8, 'I': 9, 'J': 10, 'K': 11, 'L': 12, 'M': 13, 'N': 14, 'O': 15, 'P': 16, 'Q': 17, 'R': 18, 'S': 19, 'T': 20, 'U': 21, 'V': 22, 'W': 23, 'X': 24, 'Y': 25, 'Z': 26}

def readfile(filename):
    fp = open(filename, 'r')
    lst = fp.readline()
    lst = lst.replace('"', '')
    lst = lst.split(',')
    return lst

def namescore(name):
    score = 0
    for i in range(0, len(name)):
        score += value[name[i]]
    return score

def answer():
    names = readfile('p022_names.txt')
    names = sorted(names, key=str.lower)
    sum = 0
    for i in range(0, len(names)):
        score = namescore(names[i]) * ( i + 1)
        sum += score
    return sum


if __name__ == "__main__":
    
    print answer()
