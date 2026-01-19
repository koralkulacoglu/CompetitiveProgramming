class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int mex = 0;
        set<int> vals;
        unordered_map<int, int> nextTarget;
        for (int num : nums) {
            int ops = (num - mex) / value;
            int val = num - ops * value;
            if (val < mex) val += value;

            val = (nextTarget.contains(val%value) ? nextTarget[val%value] : val);
            vals.insert(val);

            nextTarget[val%value] = val + value;

            if (val != mex) continue;

            auto ptr = vals.find(val);
            for (auto it=ptr; it!=vals.end(); it++) {
                if (*it == mex) mex++;
                else break;
            }
        }

        return mex;
    }
};
