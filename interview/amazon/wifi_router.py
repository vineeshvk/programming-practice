#!/bin/python3


#
# Complete the 'getServedBuildings' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY buildingCount
#  2. INTEGER_ARRAY routerLocation
#  3. INTEGER_ARRAY routerRange
#

def getServedBuildings(buildingCount, routerLocation, routerRange):
    # Write your code here
    range_count = dict.fromkeys(range(0, len(buildingCount)), 0)
    for i, x in enumerate(routerLocation):
        range_w = routerRange[i]
        ranged_buildings = [v for v in range(
            x - range_w - 1, x + range_w+1 - 1) if v > -1 and len(buildingCount) > v
            ]
        for y in ranged_buildings:
            range_count[y] += 1
    i = 0
    total_satisfied = 0
    for x in buildingCount:
        print(x, range_count[i])
        if x <= range_count[i]:
            total_satisfied+=1
        i +=1

    return total_satisfied


print(getServedBuildings([4, 6, 2, 5, 6, 2, 3] ,
[2, 3, 7, 1, 3, 7, 4, 6, 1] ,
[7, 0, 0, 2, 5, 2, 6, 1, 3]))

