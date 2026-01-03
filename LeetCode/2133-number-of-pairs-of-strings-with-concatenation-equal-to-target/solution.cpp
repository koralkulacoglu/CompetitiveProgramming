class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = target.size();
        
        unordered_map<string, int> freq;
        for (string s : nums) freq[s]++;

        int ans = 0;
        for (int i=0; i<n; i++) {
            string left = target.substr(0, i);
            string right = target.substr(i, n-i);

            int leftFreq = freq[left];
            int rightFreq = freq[right];

            ans += (leftFreq - (left == right)) * rightFreq;
        }
        
        return ans;
    }
};
