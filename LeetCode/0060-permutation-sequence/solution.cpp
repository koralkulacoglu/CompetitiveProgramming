class Solution {
public:
string getPermutation(int n, int k) {
    string result;
    vector<int> nums;

    // Populate nums array with numbers from 1 to n
    for (int i = 1; i <= n; ++i)
        nums.push_back(i);

    // Calculate factorial of n
    vector<int> factorial(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        factorial[i] = factorial[i - 1] * i;

    // Decrement k to match 0-based indexing
    --k;

    // Generate the kth permutation
    for (int i = n; i > 0; --i) {
        int index = k / factorial[i - 1];
        k %= factorial[i - 1];
        result += to_string(nums[index]);
        nums.erase(nums.begin() + index);
    }

    return result;
}};
