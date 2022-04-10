/*
from queue import PriorityQueue

class Solution:
    def maximumProduct(self, arr: List[int], n: int) -> int:
        q = PriorityQueue()
        m = len(arr)
        for i in range(m):
            q.put(arr[i])

        while n:
            x = q.get()
            y = q.get()
            
            diff = min(y-x+1, n)
            
            x += diff
            n -= diff
            q.put(x)
            q.put(y)

        ans = 1
        while not q.empty():
            ans *= q.get()
            ans %= int(1e9 + 7)

        return ans

# 338 ms
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums, long long n) {
        long long MOD = 1e9 + 7;
        priority_queue<long long> q;
        int m = nums.size();
        for (long long i : nums) q.push(-i);
        
        while (n) {
            long long x = -q.top();
            q.pop();
            long long y = -q.top();
            
            long long diff = min(y-x+1, n);
            
            x += diff;
            n -= diff;
            
            q.push(-x);
        }
        
        long long ans = 1;
        while (!q.empty()) {
            ans *= -q.top();
            q.pop();
            ans %= MOD;
        }
        
        return (int)ans;
    }
};
