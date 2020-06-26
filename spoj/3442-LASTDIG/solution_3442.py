# using binary exponential
# time limit exceeded
def last_digit(num, p):
    bn = bin(p)[2:][::-1]
    mul = 1
    for i, x in enumerate(list(bn)):
        if x == "1":
            mul *= num ** (2 ** i) % 10
    return mul % 10


if __name__ == "__main__":
    t = int(input())
    for x in range(t):
        inp = map(int, input().split(" "))
        num, p = list(inp)
        print(last_digit(num, p))
