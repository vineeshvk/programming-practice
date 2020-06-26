# Time limit exceed
def is_graph_dfs(edges, nodes):
    stack = []
    visitedNodes = [False for x in range(nodes + 1)]

    stack.append(edges[0][0])
    visitedNodes[edges[0][0]] = True
    visitedCount = 1

    while visitedCount < nodes and len(stack) != 0:
        for first, second in edges:
            if stack[-1] == first and not visitedNodes[second]:
                visitedCount += 1
                visitedNodes[second] = True
                stack.append(second)
        stack.pop()

    return visitedCount == nodes


if __name__ == "__main__":
    nodes, e = map(int, input().split(" "))
    edges = []
    for x in range(e):
        edges.append(list(map(int, input().split(" "))))

    if is_graph_dfs(edges, nodes) and (nodes - 1) == e:
        print("YES")
    else:
        print("NO")
# 5 4
# 1 2
# 1 3
# 3 4
# 4 5
