def decrypt(message, col):
    row = len(message) // col

    spt = lambda x: list(message[x * col : x * col + col])
    
    val = [spt(x) if x % 2 == 0 else spt(x)[::-1] for x in range(0, row)]
    
    result = "".join([val[y][x] for x in range(col) for y in range(row)])
    
    return result


if __name__ == "__main__":
    while True:
        col = int(input())
        if col == 0:
            break
        message = input()
        print(decrypt(message, col))
