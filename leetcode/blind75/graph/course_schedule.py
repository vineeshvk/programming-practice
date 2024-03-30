"""
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


https://leetcode.com/problems/course-schedule/


failed input

20
[[0,10],[3,18],[5,5],[6,11],[11,14],[13,1],[15,1],[17,4]]

Expected: False


"""


# class Solution:
    
#     def canFinish(self, numCourses: int, prerequisites) -> bool:
#         stack = [prerequisites[0][1]]  
#         visited_nodes = [prerequisites[0][1]]    
        
#         while len(stack) > 0:
#             current_val = stack[-1]
            
#             pre_req = [x for x in prerequisites if x[1] == current_val]
            
#             if not pre_req:
#                 stack.pop()
                
#             else:
#                 pre_req = pre_req[0]
#                 if pre_req[0] in stack:
#                     return False
#                 if pre_req[0] in visited_nodes:
#                     stack.pop()
#                 else:
#                     stack.append(pre_req[0])
#                     visited_nodes.append(pre_req[0])
                
        
#         return True



class Solution:
    
    def canFinish(self, numCourses: int, prerequisites):
        visited_nodes = set()
        stack = []
        pre_req_dic = {}
        i = 0
        
        
        for x,y in prerequisites:
            if x not in pre_req_dic:
                pre_req_dic[x] = []
                
            pre_req_dic[x].append(y)
        
        def dfs(input_course, prerequisites):
            print(input_course)
            if input_course in stack:
                return False
            
            
            if input_course not in pre_req_dic or input_course in visited_nodes:
                return True

            course_nodes = pre_req_dic[input_course]
            
            stack.append(input_course)

            for node in course_nodes:
                value =  dfs(node, prerequisites)
                if not value:
                    return False

            stack.pop()
            visited_nodes.add(input_course)
            return True
        
        while i <= numCourses:
            valid = dfs(i, prerequisites)
            if not valid:
                return False
            i += 1
        
        return True
    
    

            
            
            
            
            
        
        


sol = Solution()
print(sol.canFinish(20,[[0,10],[3,18],[5,5],[6,11],[11,14],[13,1],[15,1],[17,4]]))

