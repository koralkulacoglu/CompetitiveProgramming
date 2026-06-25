struct ordered_multiset {
    std::vector<int> data;

    // Inserts an element and maintains sorted order: O(n)
    void insert(int val) {
        auto it = std::upper_bound(data.begin(), data.end(), val);
        data.insert(it, val);
    }

    // Erases exactly ONE instance of a value if it exists: O(n)
    void erase_one(int val) {
        auto it = std::lower_bound(data.begin(), data.end(), val);
        if (it != data.end() && *it == val) {
            data.erase(it);
        }
    }

    // Returns the 0-based index of the lower bound: O(log n)
    int order_of_key(int val) {
        auto it = std::lower_bound(data.begin(), data.end(), val);
        return it - data.begin();
    }

    // Returns the total number of elements: O(1)
    size_t size() const {
        return data.size();
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        long long psa = 0;
        ordered_multiset sums;
        sums.insert(0);
        for (int i : nums) {
            psa += (i == target) ? 1 : -1;
            int idx = sums.order_of_key(psa);
            ans += idx;
            sums.insert(psa);
        }
        return ans;
    }
};
