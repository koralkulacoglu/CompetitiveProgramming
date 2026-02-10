struct Num {
    int val;
    int digitSum;

    Num(int val) : val(val), digitSum(0) {
        int temp = val;
        while (temp) {
            digitSum += temp % 10;
            temp /= 10;
        }
    }

    bool operator<(const Num& other) const {
        if (digitSum < other.digitSum) return true;
        if (digitSum > other.digitSum) return false;
        return val < other.val;
    }
};

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> loc;
        for (int i=0; i<n; i++) loc[nums[i]] = i;
        vector<Num> a(nums.begin(), nums.end());
        sort(a.begin(), a.end());

        int ans = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] != a[i].val) {
                int correctVal = a[i].val;
                int oldIdx = loc[correctVal];
                int currentVal = nums[i];
                loc[currentVal] = oldIdx;
                loc[correctVal] = i;
                swap(nums[i], nums[oldIdx]);
                ans++;
            }
        }

        return ans;
    }
};
