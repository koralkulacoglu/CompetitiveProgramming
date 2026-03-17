class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> color, freq;
        int colors = 0;
        vector<int> res;
        for (vector<int>& query : queries) {
            int x = query[0];
            int y = query[1];

            int prevCol = color[x];
            if (prevCol == 0) {
                color[x] = y;
                freq[y]++;
                if (freq[y] == 1) colors++;
            }
            else if (prevCol != y) {
                color[x] = y;
                freq[prevCol]--;
                freq[y]++;
                if (freq[prevCol] == 0) colors--;
                if (freq[y] == 1) colors++;
            }

            res.push_back(colors);
        }

        return res;
    }
};
