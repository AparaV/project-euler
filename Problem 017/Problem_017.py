'''
Problem 017: Number Letter Count
Author: Aparajithan Venkateswaran
'''

def one_to_9():
    answer = 3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4
    return answer

def ten_to_19():
    answer = 3 + 6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8
    return answer

def twenty_to_99():
    tens = 6 + 6 + 5 + 5 + 5 + 7 + 6 + 6
    answer = 10 * tens + 8 * one_to_9()
    return answer

def one_to_99():
    return one_to_9() + ten_to_19() + twenty_to_99()

def hundred_to_999():
    hundred = 7
    hundredand = 10
    answer = 9 * one_to_99() + 100 * one_to_9() + 9*hundred + 9*99*hundredand
    return answer

def one_to_1000():
    return one_to_99() + hundred_to_999() + 11

if __name__ == "__main__":
    print one_to_1000()
