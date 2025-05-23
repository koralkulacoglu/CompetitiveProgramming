class Solution {
public:
    bool isValid(int maxVal, const vector<int>& nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if ((sum + i) / (i + 1) > maxVal) return false;
        }
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(mid, nums)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};

