def equal_candies(candies):
    total = sum(candies)

    if total % len(candies) != 0:
        return -1

    avg = total // len(candies)

    moves_required = sum([avg - x for x in candies if x < avg])

    return moves_required


if __name__ == "__main__":
    while True:
        n = int(input())
        if n == -1:
            break

        candies = []
        for x in range(n):
            candies.append(int(input()))

        print(equal_candies(candies))
