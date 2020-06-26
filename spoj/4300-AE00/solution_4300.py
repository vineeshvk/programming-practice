from math import sqrt


def factor_count(num):
    count = 0
    for x in range(2, int(sqrt(num)) + 1):
        if num % x == 0:
            count += 1
    return count


def rectangle_count(num):
    factors = 0
    for x in range(4, num + 1):
        factors += factor_count(x)
    return num + factors


if __name__ == "__main__":
    num = int(input())
    print(rectangle_count(num))
