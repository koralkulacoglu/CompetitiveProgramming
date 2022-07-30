class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size(), cnt=1e9;
        map<int, int> idx;
        for (int i=0; i<n; i++) {
            int num = cards[i];
            if (idx[num]) {
                cnt = min(cnt, i-idx[num] + 2);
            }
            idx[num] = i + 1;
        }
        return cnt < 1e9 ? cnt : -1;
    }
};
