if __name__ == "__main__":
    for t in range(int(input())):
        n = int(input())
        total = 0
        i = 0
        while (total + i + 1) < n:
            i += 1
            total += i

        even = i % 2 == 0
        x = (0, i)[even]
        y = (i, 0)[even]
        diff = (1, -1)[even]

        while total + 1 < n:
            x += diff
            y -= diff
            total += 1

        print(f"TERM {n} IS {x + 1}/{y + 1}")
