def merge_sort(arr, inv):
    if len(arr) < 2:
        return arr, inv

    mid = len(arr) // 2

    left, inv = merge_sort(arr[:mid], inv)
    right, inv = merge_sort(arr[mid:], inv)

    sorted_arr = []
    li = ri = 0

    while li < mid and ri < len(arr) - mid:
        if left[li] > right[ri]:
            inv += mid - li
            sorted_arr.append(right[ri])
            ri += 1
        else:
            sorted_arr.append(left[li])
            li += 1

    if li < mid:
        sorted_arr.extend(left[li:])
    if ri < len(arr) - mid:
        sorted_arr.extend(right[ri:])

    return sorted_arr, inv


if __name__ == "__main__":
    for x in range(int(input())):
        input()
        arr = [int(input()) for y in range(int(input()))]
        inv = 0
        sa, inv = merge_sort(arr, inv)
        print(inv)
