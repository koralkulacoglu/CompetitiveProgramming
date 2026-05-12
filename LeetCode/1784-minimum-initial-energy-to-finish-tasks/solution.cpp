class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int ans = 0;
        int energy = 0;
        for (vector<int>& task : tasks) {
            int actual = task[0];
            int minimum = task[1];
            int need = minimum - energy;
            if (need > 0) {
                ans += need;
                energy += need;
            }
            energy -= actual;
        }
        return ans;
    }
};
