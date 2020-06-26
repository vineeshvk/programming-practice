def getSum(BITree, index):
    sum = 0
    while index > 0:
        sum += BITree[index]
        index -= index & (-index)
    return sum


def updateBIT(BITree, n, index, val):
    while index <= n:
        BITree[index] += val
        index += index & (-index)


def convert(arr, n):
    temp = sorted(arr[:])
    for i in range(n):
        arr[i] = temp.index(arr[i]) + 1


def getInvCount(arr, n):
    invcount = 0
    convert(arr, n)
    BIT = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        invcount += getSum(BIT, arr[i] - 1)
        updateBIT(BIT, n, arr[i], 1)
    return invcount


if __name__ == "__main__":

    arr = [2, 3, 8, 6, 1]
    n = len(arr)
    print("Number of inversions are : ", getInvCount(arr, n))
