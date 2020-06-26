def can_arrange_trucks(trucks):
    nextTarget = 1
    i = 0
    stack = []

    while i < len(trucks) and nextTarget <= len(trucks):
        if nextTarget == trucks[i]:
            nextTarget += 1
            i += 1
        elif len(stack) != 0 and stack[-1] == nextTarget:
            stack.pop()
            nextTarget += 1
        elif len(stack) == 0 or stack[-1] >= nextTarget:
            stack.append(trucks[i])
            i += 1
        else:
            return "no"

    for x in stack[::-1]:
        if x != nextTarget:
            return "no"
        nextTarget += 1
    return "yes" if (nextTarget - 1) == len(trucks) else "no"


if __name__ == "__main__":
    while True:
        n = int(input())
        if n == 0:
            break
        trucks = list(map(int, input().strip().split(" ")))
        print(can_arrange_trucks(trucks))
