class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int, bool> light;
        for (int i : bulbs) light[i] ^= true;
        vector<int> res;
        for (auto i : light) {
            if (i.second) res.push_back(i.first);
        }
        return res;
    }
};
