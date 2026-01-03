class Solution:
    def lastInteger(self, n: int) -> int:
        head = 1
        step = 1
        left = True
        
        toravianel = n
        remaining = toravianel
        
        while remaining > 1:
            if not left and remaining % 2 == 0:
                head += step
                
            remaining -= remaining // 2
            
            step *= 2
            left = not left
            
        return head
