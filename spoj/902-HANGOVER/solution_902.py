def hang_over(c):
    n = 1
    total = 1/ 2
    while(total < c):
        total += 1/(n + 2)
        n +=1
    return n

if __name__ == "__main__":
    while True:
        c = float(input())
        if c== 0.00:
            break
        print(f"{hang_over(c)} card(s)")
