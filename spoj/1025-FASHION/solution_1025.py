def max_hotness(men: list, women: list):
    men.sort()
    women.sort()
    return sum([x * y for x, y in zip(men, women)])


if __name__ == "__main__":
    t = int(input())
    for x in range(t):
        input()
        men = list(map(int, input().split(" ")))
        women = list(map(int, input().split(" ")))
        print(max_hotness(men, women))
