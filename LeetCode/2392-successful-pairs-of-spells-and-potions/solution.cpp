class Solution {
public:
    // sort and binary search (lb)
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(), m=potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(n, 0);
        for (int i=0; i<n; i++) {
            int mid;
            int low = 0;
            int high = m;
            while (low < high) {
                mid = low + (high - low) / 2;
                if (success <= ((long long)spells[i])*potions[mid]) {
                    high = mid;
                }
                else {
                    low = mid + 1;
                }
            }

            if (low < m && ((long long)spells[i])*potions[low] < success) {
               low++;
            }

            
            int loc = low;
            if (loc == n) continue;
            res[i] = m - loc;
        }
        return res;
    }
};
