def maxCandies(candies, times):
    candies = sorted(candies)[::-1]
    total = 0

    for x in range(times):
        i = 0
        while i < len(candies) and candies[i] < candies[i + 1]:
            i += 1
        total += candies[i] 
        candies[i] //= 2

    return total


if __name__ == "__main__":
    for x in range(int(input())):
        n, k = map(int, input().split(" "))
        candies = list(map(int, input().split(" ")))
        print(maxCandies(candies, k))
