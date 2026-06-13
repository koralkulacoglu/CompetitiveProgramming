class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i=0; i<n; i++) {
            int num1 = numbers[i];
            int num2 = target - num1;
            auto it = upper_bound(numbers.begin(), numbers.end(), num2);
            it--;
            if (*it == num2) return {i + 1, int(it - numbers.begin()) + 1};
        }
        return {-1, -1};
    }
};
