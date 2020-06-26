if __name__ == "__main__":
    n = int(input())
    for x in range(n):
        x,y = input().split(" ")
        x = int(x[::-1])
        y = int(y[::-1])
        print(int(str(x+y)[::-1]))