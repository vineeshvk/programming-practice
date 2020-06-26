if __name__ == "__main__":
    for x in range(int(input())):
        input()
        n = int(input())
        total=sum([ int(input()) for _ in range(n)])
        print(("NO","YES")[total % n == 0])
