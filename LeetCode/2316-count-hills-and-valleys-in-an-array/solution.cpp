class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int p1=nums[0], p2=0, p3=0, idx=0;
        for (int i=0; i<n; i++) {
            if (nums[i] != p1 && !p2) p2 = nums[i];
            else if (nums[i] != p2 && p2 && !p3) p3 = nums[i];
            
            if (p1 && p2 && p3) break;
            idx++;
        }
        if (!p3) return ans;
        
        ans += (p1<p2 && p3<p2) || (p1>p2 && p3>p2);
        for (int i=idx+1; i<n; i++) {
            if (nums[i] != p3) {
                p1 = p2;
                p2 = p3;
                p3 = nums[i];
                
                if ((p1<p2 && p3<p2) || (p1>p2 && p3>p2)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
