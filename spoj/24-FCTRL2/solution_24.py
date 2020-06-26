from functools import reduce

if __name__ == "__main__":
    n = int(input())
    for x in range(n):
        num = int(input())

        series = range(1, num + 1) or [1]
        factorial = lambda a, b: a * b

        print(reduce(factorial, series))
