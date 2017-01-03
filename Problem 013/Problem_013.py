def solution():
    numbers = []
    with open('data.txt', 'r') as f:
        for line in f:
            line = line.strip()
            numbers.append(line)
    answer = 0
    for number in numbers:
        answer += int(number[:11])
    answer = str(answer)[:10]
    return answer

print solution()
