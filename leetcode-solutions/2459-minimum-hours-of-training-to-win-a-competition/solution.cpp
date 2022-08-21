// in order

class Solution {
public:
    int minNumberOfHours(int eg, int xp, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans += max(0, energy[i]-eg+1);
            ans += max(0, experience[i]-xp+1);
            
            eg -= energy[i];
            xp = max(xp, experience[i]+1);
            xp += experience[i];
            
            eg = max(eg, 1);
        }
        return ans;
    }
};
