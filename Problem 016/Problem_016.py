def answer(a, n):
    power = str(a**n)
    ans = sum(int(power[i]) for i in range(len(power)))
    return ans

if __name__ == "__main__":
    print answer(2, 1000)
