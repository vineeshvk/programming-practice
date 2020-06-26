if __name__ == '__main__':
    for x in range(int(input())):
        total,_ = map(int,input().split(" "))
        friend_stamp  = list(map(int,input().split(" ")))
        friend_stamp.sort(reverse=True)
        count = 0
        for stamps in friend_stamp:
            count += 1
            total -= stamps
            if total <= 0:
                break
        print(f"Scenario #{x+1}:")
        print(("impossible",count)[total <= 0])
