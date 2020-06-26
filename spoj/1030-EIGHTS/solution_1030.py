def eights(k):
    return 192 + ((k - 1) * 250)


if __name__ == "__main__":
    for x in range(int(input())):
        k = int(input())
        print(eights(k))
