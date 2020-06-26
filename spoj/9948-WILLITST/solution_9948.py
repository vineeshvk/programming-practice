
def will_it_stop(n):
    arr = []
    while n>1:
        if n % 2 == 0:
            n = n//2
        else:
            if n in arr:
                return "NIE"
            arr.append(n)
            n = 3 * n + 3
    return "TAK"

if __name__ == "__main__":
    n = int(input())
    print(will_it_stop(n))
