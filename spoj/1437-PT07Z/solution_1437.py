# time limit exception
def longest_path_dfs(edges, nodes, root=-1):
    fromRoot = root != -1

    visitedNodes = [False for x in range(nodes + 1)]
    stack = [edges[0][0]]

    if fromRoot:
        stack[0] = root

    visitedNodes[stack[0]]
    visited = 1
    maxPos = -1
    maxVal = -1

    while visited < nodes and len(stack) != 0:
        i = 0
        while i < nodes - 1:
            first = edges[i][0]
            second = edges[i][1]
            if first == stack[-1] and not visitedNodes[second]:
                visitedNodes[second] = True
                i = 0
                visited += 1
                stack.append(second)
            elif second == stack[-1] and not visitedNodes[first]:
                visitedNodes[first] = True
                i = 0
                visited += 1
                stack.append(first)
            else:
                i += 1
        if maxPos < (len(stack) - 1):
            maxPos = len(stack) - 1
            maxVal = stack[-1]
        stack.pop()

    return maxPos if fromRoot else longest_path_dfs(edges, nodes, maxVal)


if __name__ == "__main__":
    nodes = int(input())
    edges = []

    for x in range(nodes - 1):
        edges.append(list(map(int, input().split(" "))))
    print(longest_path_dfs(edges, nodes))
# 5
# 1 2
# 1 3
# 2 4
# 2 5
