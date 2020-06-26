def apple_count(total, more):
    half = total // 2
    diff = more // 2
    print(half,diff)
    print(half + diff + (1, 0)[total % 2 == 0])
    print(half - diff)


if __name__ == "__main__":
    for x in range(10):
        total = int(input())
        more = int(input())
        apple_count(total, more)
