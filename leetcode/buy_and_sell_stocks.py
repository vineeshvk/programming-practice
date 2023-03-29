def buy_and_sell_stocks(input: list):
    i = 0
    max_profit = 0

    for j in range(len(input)):
        profit = input[j] - input[i]
        if profit > max_profit:
            max_profit = profit

        if input[j] < input[i]:
            i = j
        j += 1

    return max_profit


print(buy_and_sell_stocks([1, 7]))
