class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        set<pair<int, int>> houses;
        unordered_map<int, bool> seen;
        for (int i=0; i<n; i++) {
            int c = colors[i];
            auto house = houses.begin();
            if (house != houses.end()) {
                int houseIdx = house->first;
                int houseCol = house->second;
                house++;
                if (houseCol != c) {
                    ans = max(ans, i - houseIdx);
                }
                else if (house != houses.end()) {
                    houseIdx = house->first;
                    houseCol = house->second;
                    ans = max(ans, i - houseIdx);
                }
            }
            if (!seen[c]) houses.insert({i, c});
            seen[c] = true;
        }
        return ans;
    }
};
