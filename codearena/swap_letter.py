def swap_letter():
    n = int(input())
    l = []
    for x in range(n):
        l.append(list(input().split(" ")))
    sen = list(input())
    for a,b in l:
        for x in range(len(sen)):
            if sen[x] == a:
                sen[x] = b
            elif sen[x] == b:
                sen[x] = a
    print("".join(sen))

swap_letter()