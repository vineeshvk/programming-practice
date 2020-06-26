

def transform_exp(exp: list):
    trans_exp: list = []
    symbols: list = []

    for x in exp:
        if x == "(":
            symbols.append("(")
        elif x.isalnum():
            trans_exp.append(x)
        elif x == ")":
            last = symbols.pop()

            while last != "(":
                trans_exp.append(last)

                last = symbols.pop()
        else:
            if operator(x) <= operator(symbols[-1]):
                symbols.insert(-1, x)
            else:
                symbols.append(x)

    while symbols:
        trans_exp(symbols.pop())

    for x in trans_exp:
        print(x, end="")


def operator(c):
    if c == "^":
        return 3
    if c == "*" or c == "/":
        return 2
    if c == "+" or c == "-":
        return 1
    return -1

if __name__ == "__main__":
    n: int = int(input())
    for x in range(n):
        transform_exp(list(input().strip()))
        print()
