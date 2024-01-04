class Solution:
    def floodFill(self, image , sr: int, sc: int, color: int) :
        visited_nodes = set()
        stack = [(sr, sc)]

        match = image[sr][sc]

        m = len(image) - 1
        n = len(image[0]) - 1

        while len(stack) != 0:
            current_node = stack[-1]
            sr = current_node[0]
            sc = current_node[1]

            visited_nodes.add(current_node)

            if image[current_node[0]][current_node[1]] == match:
                image[current_node[0]][current_node[1]]  = color
            
            value = None

            if sr < m and image[sr + 1][sc] == match :
                value = (sr + 1, sc)

            elif sc < n and image[sr][sc + 1] == match :
                value = (sr, sc + 1)

            elif sr > 0 and image[sr - 1][sc] == match:
                value = (sr - 1, sc)

            elif sc > 0 and image[sr][sc - 1] == match:
                value = (sr, sc - 1)
            
            if value:
                stack.append(value)
            else:
                stack.pop()
        return image


print(Solution().floodFill([[1,1,1],[1,1,0],[1,0,1]], 1, 1, 2))
