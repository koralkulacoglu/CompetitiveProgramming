class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        int i = nums.size() - 1;
        while (i >= 0) {
            while (st.top() > nums[i]) st.pop();
            ans += (nums[i] != 0 && st.top() < nums[i]);
            st.push(nums[i]);
            i--;
        }
        return ans;
    }
};
