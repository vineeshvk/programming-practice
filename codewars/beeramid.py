def beeramid(bonus, price):
    total_expense = 0
    val = 1
    while True:
        total_expense += val ** 2 * price
        if(total_expense > bonus):
            return val - 1
        val += 1
    return val

print(beeramid(21, 1.5))