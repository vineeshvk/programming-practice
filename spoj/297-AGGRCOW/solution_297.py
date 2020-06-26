def arrange_cows(stalls, cows):
    stalls.sort()
    low = stalls[0]
    high = stalls[-1]
    best = 0
    while low <= high:
        mid = low + ((high - low) // 2)
        prev_stall = stalls[0]
        c_arranged = 1
        for x in stalls:
            if x - prev_stall >= mid:
                c_arranged += 1
                prev_stall = x
        if c_arranged >= cows:
            best = mid
            low = mid + 1
        else:
            high = mid - 1
    return best


if __name__ == "__main__":
    for x in range(int(input())):
        size, cows = map(int, input().split(" "))
        stalls = [int(input()) for _ in range(size)]
        print(arrange_cows(stalls, cows))
