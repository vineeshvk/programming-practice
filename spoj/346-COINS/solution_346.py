memory = dict()


def coin_ex(num):
    if num == 0:
        return 0

    if not memory.get(num):
        total = num // 2 + num // 3 + num // 4
        if num > total:
            return num

        val = coin_ex(num // 2) + coin_ex(num // 3) + coin_ex(num // 4)

        memory[num] = val

    return memory[num]


if __name__ == "__main__":
    while True:
        try:
            num = int(input())
            print(coin_ex(num))
        except:
            break
