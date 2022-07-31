class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int sz = grades.size();
        for (int i=1; i<2e5; i++) {
            if (i*(i+1)/2 > sz) return i-1;
        }
        return -1;
    }
};
