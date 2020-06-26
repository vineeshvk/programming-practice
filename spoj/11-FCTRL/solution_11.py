
def trailing_zeros(num:int):
    zeros = 0
    while num >= 5:
        num //= 5
        zeros += num
    return zeros

if __name__ == "__main__":
    n = int(input())
    inputs = [int(input()) for x in range(n)]
    output = map(trailing_zeros, inputs)
    [print(x) for x in list(output) ]
