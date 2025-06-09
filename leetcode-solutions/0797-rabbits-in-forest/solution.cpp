class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int, int> freq;
        for (int i : answers) freq[i]++;

        int ans = 0;
        for (pair<int, int> i : freq) {
            int val = i.first;
            int fre = i.second;

            // group by val + 1
            ans += (fre + val) / (val + 1) * (val + 1);
        }

        return ans;
    }
};

// 3 split into groups of 2
