
def n_step(x, y):
    total = x + y
    condition = 2 >= x - y >= 0 and total % 2 == 0

    if x % 2 == 0 and condition:
        return total
    if x % 2 != 0 and condition:
        return total - 1
    return -1

if __name__ == "__main__":
    n = int(input())

    for x in range(n):
        inp = input().split(" ")
        x, y = list(map(int, inp))

        val = n_step(x, y)
        print(("No Number", val)[val != -1])
