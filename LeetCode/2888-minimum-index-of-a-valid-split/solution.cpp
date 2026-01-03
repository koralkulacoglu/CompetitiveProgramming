class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> rightFreq, leftFreq;
        multiset<pair<int, int>> rightFreqI, leftFreqI;
        for (int i : nums) rightFreq[i]++;
        for (pair<int, int> i : rightFreq) rightFreqI.insert({i.second, i.first});
        for (int i=0; i<n; i++) {
            leftFreqI.erase({leftFreq[nums[i]], nums[i]});
            leftFreqI.insert({leftFreq[nums[i]]+1, nums[i]});
            rightFreqI.erase({rightFreq[nums[i]], nums[i]});
            if (rightFreq[nums[i]] > 1) rightFreqI.insert({rightFreq[nums[i]]-1, nums[i]});
            leftFreq[nums[i]]++;
            if (rightFreq[nums[i]] > 1) rightFreq[nums[i]]--;
            else rightFreq.erase(nums[i]);
            if (rightFreqI.empty()) continue;
            if (leftFreqI.rbegin()->second == rightFreqI.rbegin()->second && leftFreqI.rbegin()->first > (i+1)/2 && rightFreqI.rbegin()->first > (n-i-1)/2) return i;
        }
        return -1;
    }
};
