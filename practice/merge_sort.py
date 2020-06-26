def merge_sort(arr):

    if len(arr) < 2:
        return arr

    mid = len(arr) // 2

    left = merge_sort(arr[0:mid])
    right = merge_sort(arr[mid : len(arr)])

    sorted_arr = []

    li = ri = 0
    while li < mid and ri < len(arr) - mid:
        if left[li] > right[ri]:
            sorted_arr.append(left[li])
            li += 1
        else:
            sorted_arr.append(right[ri])
            ri += 1

    if ri < len(arr) - mid:
        sorted_arr.extend(right[ri:])
    if li < mid:
        sorted_arr.extend(left[li:])

    return sorted_arr


if __name__ == "__main__":
    arr = [3, 4, 1, 2, 6]
    print(merge_sort(arr))
