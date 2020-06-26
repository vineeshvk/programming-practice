def next_palindrome(s):
    s_list = list(s)
    temp = s_list[:]
    n = len(s_list)
    half = (n - 1) // 2

    for x in range(half + 1):
        s_list[n - x - 1] = s_list[x]

    if temp >= s_list:
        for x in range(half, -1, -1):
            digit = s_list[x]
            if digit != "9":
                s_list[x] = str(int(digit) + 1)
                break
            s_list[x] = "0"

        for x in range(half + 1):
            s_list[n - x - 1] = s_list[x]
        if s_list[0] == "0":
            s_list[0] = "1"
            s_list.append("1")

    return "".join(s_list)


if __name__ == "__main__":
    for x in range(int(input())):
        s = input()
        print(next_palindrome(s))
