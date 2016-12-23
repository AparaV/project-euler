def readFile(filename):
    f = open(filename, "r")
    array = []
    for line in f:
        line = line.strip("\n")
        array.append(line.split(" "))
    tree = []
    for row in array:
        tree.append(map(int, row))
    return tree

def calculateSum(filename):
    tree = readFile(filename)
    for i in range(len(tree) - 2, -1, -1):
        for j in range(len(tree[i])):
            c = tree[i][j] + tree[i + 1][j]
            d = tree[i][j] + tree[i + 1][j + 1]
            tree[i][j] = max(c, d)
    return tree[0][0]



def main():
    print calculateSum("triangle.txt")

if __name__ == "__main__":
    main()