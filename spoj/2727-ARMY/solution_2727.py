if __name__ == "__main__":
    for t in range(int(input())):
        input()
        NG, NM = map(int, input().split(" "))
        GMonsters = list(map(int, input().split(" ")))
        MMonsters = list(map(int, input().split(" ")))
        GMonsters.sort()
        MMonsters.sort()
        gi = mi = 0
        while gi < NG and mi < NM:
            if GMonsters[gi] >= MMonsters[mi]:
                mi += 1
            else:
                gi += 1

        if gi == NG and mi == NM:
            print("uncertain")
        elif gi == NG:
            print("MechaGodzilla")
        else:
            print("Godzilla")
