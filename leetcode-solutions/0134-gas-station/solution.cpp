class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;

        int n = gas.size();
        int idx = 0;
        int tank = 0;
        for (int i=0; i<n; i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                // idx does not work, go up
                tank = 0;
                idx = i+1;
            }
        }

        return idx;
    }
};
