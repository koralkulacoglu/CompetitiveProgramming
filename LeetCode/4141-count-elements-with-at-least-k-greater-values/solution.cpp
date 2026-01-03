class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        set<int> s;
        for (int i : nums) {
            s.insert(i);
            freq[i]++;
        }

        int total = 0;
        for (int i : s) {
            int f = freq[i];
            total += f;
            int greater = n - total;
            if (greater < k) return total - f;
        }

        return n;
    }
};
