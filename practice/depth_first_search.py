def dfs ():
    traversedNodes = []
    checkInNodes = []
    nodes = [1, 2, 3, 0]
    final = []

    currentI = 0
    i = currentI
    while len(traversedNodes) < len(nodes) and i < len(nodes):
        if nodes[i] not in traversedNodes:
            i = nodes[i]
            traversedNodes.append(i)
            checkInNodes.append(i)
        else:
            i+=1
            if len(checkInNodes) != 0:
                final.append(len(checkInNodes))
                checkInNodes = []
    final.append(len(checkInNodes))
    return max(final)

dfs()