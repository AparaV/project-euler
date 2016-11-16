def readFile(filename):
    f = open(filename, "r")
    return f.readlines()

def calculateSum(filename):
    tree = readFile(filename)
    sum = 0 
    for i in range(0, len(tree)-1):
        if i == 0:
            j = 0
            sum += tree[i][0]
        else if tree[i+1][j] > tree[i+1][j+1]:
            sum += tree[i+1][j]
        else:
            sum += tree[i+1][j+1]
            j += 1
    return sum

def main():
    print calculateSum("tree.txt")

if __name__ == "__main__":
    main()
                
