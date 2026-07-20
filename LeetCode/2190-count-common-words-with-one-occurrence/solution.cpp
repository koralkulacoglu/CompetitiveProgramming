class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1, freq2;
        for (string& word : words1) freq1[word]++;
        for (string& word : words2) freq2[word]++;

        int ans = 0;
        for (auto p : freq1) {
            int f1 = p.second;
            int f2 = freq2[p.first];
            ans += (f1 == 1 && f2 == 1);
        }
        
        return ans;
    }
};
