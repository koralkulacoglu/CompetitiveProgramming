# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node, level=0):
        if node == None:
            return
        
        if self.level_sum[level] == None:
            self.level_sum[level] = node.val
        else:
            self.level_sum[level] += node.val
            
        self.dfs(node.left, level+1)
        self.dfs(node.right, level+1)

    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        self.level_sum = [None for i in range(10**4)]
        self.dfs(root)
        max_level = 0
        for i in range(10**4):
            if self.level_sum[i] != None and self.level_sum[i] > self.level_sum[max_level]:
                max_level = i
        
        return max_level+1
