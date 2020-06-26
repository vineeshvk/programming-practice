def find_ap_gp(x, y, z):
    diff = y - x
    if z - y == diff:
        print(f"AP {(z + diff)}")
    else:
        print(f"GP {int(z * y / x)}")


if __name__ == "__main__":
    while True:
        inp = input().split(" ")
        x, y, z = list(map(int, inp))
        if x == y == z == 0:
            break
        find_ap_gp(x, y, z)
