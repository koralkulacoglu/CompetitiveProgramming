class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int idx = -1;
        int n = capacity.size();
        for (int i=0; i<n; i++) {
            if (capacity[i] >= itemSize) {
                if (idx == -1 || capacity[idx] > capacity[i]) idx = i;
            }
        }
        return idx;
    }
};
