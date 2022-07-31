class NumArray:
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.tree = [0] * (4*len(nums))
        
        def build_tree(node, start, end):
            if start == end:
                self.tree[node] = self.nums[start]
                return
            mid = (start+end) // 2
            left_node, right_node = 2*node + 1, 2*node + 2
            build_tree(left_node, start, mid)
            build_tree(right_node, mid+1, end)
            self.tree[node] = self.tree[left_node] + self.tree[right_node]
        build_tree(0, 0, len(nums)-1)
        
        
    def update(self, idx: int, val: int) -> None:
        def update_tree(node, start, end):
            if start == end:
                self.tree[node] = self.nums[idx] = val
                return
            mid = (start+end) // 2
            left_node, right_node = 2*node + 1, 2*node + 2
            if start <= idx <= mid:
                update_tree(left_node, start, mid)
            else:
                update_tree(right_node, mid+1, end)
            self.tree[node] = self.tree[left_node] + self.tree[right_node]
        update_tree(0, 0, len(self.nums)-1)
        

    def sumRange(self, left: int, right: int) -> int:
        def query_tree(node, start, end):
            if end < left or start > right:
                return 0
            if left <= start <= end <= right:
                return self.tree[node]
            mid = (start+end) // 2
            left_node, right_node = 2*node + 1, 2*node + 2
            left_sum = query_tree(left_node, start, mid)
            right_sum = query_tree(right_node, mid+1, end)
            return left_sum + right_sum
        return query_tree(0, 0, len(self.nums)-1)

