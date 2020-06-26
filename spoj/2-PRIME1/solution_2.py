def prime_num(start, end):
    
    for x in range(start,end+1):
        odd = x % 2 != 0
        n = (2,3)[odd]
        prime = x != 1
        while(n*n <= x and prime):
            prime = x%n != 0
            n+=2
        if prime :
            print(x)


if __name__ == "__main__":
    t = int(input())
    for x in range(t):
        m,n = input().split(" ")
        m = int(m)
        n = int(n)
        prime_num(m,n)
        print()
