class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        for (int i : tasks) freq[i]++;
        
        int ans=0;
        for (auto i : freq) {
            if (i.second == 1) {
                return -1;
            }
            for (int j=i.second/3; j>=0; j--) {
                int rem = i.second - 3*j;
                if (rem%2 == 0) {
                    ans += j + rem/2;
                    break;
                }
            }
        }
        return ans;
    }
};
