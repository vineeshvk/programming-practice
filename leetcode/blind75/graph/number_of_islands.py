'''
https://leetcode.com/problems/number-of-islands/


Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3



'''




class Solution:
    def numIslands(self, grid) -> int:
        island_count = 0
                
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                if grid[i][j] == "0":
                    continue
                
                island_count += 1                        
                self.dfs_traverse(visited_nodes=grid, i=i, j = j)
                    
        return island_count
    
    def dfs_traverse(self,visited_nodes: list[list], i: int, j: int):
        visited_nodes[i][j] = "0"
        
        nodes = self.nearby_non_visited_nodes(visited_nodes=visited_nodes, i=i, j=j)
        
        for node in nodes:
            self.dfs_traverse(visited_nodes=visited_nodes, i=node[0], j=node[1])
        
    
    def nearby_non_visited_nodes(self, visited_nodes, i,j):
        nodes = set()
        
        max_i = len(visited_nodes)
        max_j = len(visited_nodes[0]) 
        
        if i > 0 and  visited_nodes[i-1][j] == "1":
            nodes.add((i-1, j))
        
        if j > 0 and visited_nodes[i][j - 1] == "1":
            nodes.add((i, j-1))
            

        if i + 1 < max_i and visited_nodes[i+1][j] == "1":
            nodes.add((i+1, j))
        
        if j+1 < max_j and visited_nodes[i][j+1] == "1":
            nodes.add((i,j+1))
            
        return nodes


sol = Solution()
print(sol.numIslands(
[["0","1","0"],
 ["1","0","1"],
 ["0","1","0"],
 ]
))