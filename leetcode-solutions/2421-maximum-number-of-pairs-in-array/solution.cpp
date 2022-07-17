class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> freq;
        for (int &i : nums) freq[i]++;
        vector<int> res(2, 0);
        for (auto i : freq) {
            res[0] += i.second/2;
            res[1] += i.second%2;
        }
        return res;
    }
};
