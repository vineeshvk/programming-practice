def two_factors(num):
    factors = 0
    while num % 2 == 0:
        num //= 2
        factors += 1
    return factors


def ten_series(num):
    result = (num // 10) * 5
    if num % 10 != 0:
        for x in range(2, num % 10 + 1, 2):
            result += 1
    return result


def jerry_wins(TS):
    if TS % 2 != 0:
        return ten_series(TS)
    else:
        count = 0
        p = two_factors(TS) + 1
        i = 2
        power = 2 ** p
        val = power
        while val < TS:
            count += 1
            val = power * i
            i += 1
        return count


if __name__ == "__main__":
    for t in range(int(input())):
        TS = int(input())
        print(jerry_wins(TS))
