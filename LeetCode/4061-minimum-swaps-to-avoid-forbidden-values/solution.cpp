class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        
        // first swap between invalid nums
        vector<pair<int, int>> toSwap;
        for (int i=0; i<n; i++) {
            if (nums[i] != forbidden[i]) continue;
            toSwap.push_back({nums[i], i});
        }
        
        int m = toSwap.size();
        if (m == 0) return 0;

        sort(toSwap.begin(), toSwap.end());

        unordered_map<int, vector<int>> groups;
        for (auto p : toSwap) groups[p.first].push_back(p.second);

        priority_queue<pair<int, int>> pq;
        for (auto g : groups) pq.push({g.second.size(), g.first});

        int ans = 0;
        while (pq.size() >= 2) {
            auto [cnt1, val1] = pq.top(); pq.pop();
            auto [cnt2, val2] = pq.top(); pq.pop();
            int idx1 = groups[val1].back(); groups[val1].pop_back();
            int idx2 = groups[val2].back(); groups[val2].pop_back();

            swap(nums[idx1], nums[idx2]);
            ans++;

            if (--cnt1 > 0) pq.push({cnt1, val1});
            if (--cnt2 > 0) pq.push({cnt2, val2});
        }

        // now there's one type of number left to swap
        int badNum = -1;
        multiset<int> badForbidden, goodForbidden;
        for (int i=0; i<n; i++) {
            if (nums[i] == forbidden[i]) {
                badForbidden.insert(forbidden[i]);
                badNum = nums[i];
            }
        }

        if (badNum == -1) return ans;

        for (int i=0; i<n; i++) {
            if (nums[i] != forbidden[i] && forbidden[i] != badNum && nums[i] != badNum) {
                goodForbidden.insert(nums[i]);
            }
        }

        /*
        for (int i : goodForbidden) cout << i << ' ';
        cout << endl;
        for (int i : badForbidden) cout << i << ' ';
        cout << endl;
        */

        auto it = goodForbidden.end();
        for (int bad : badForbidden) {
            if (it == goodForbidden.begin()) return -1;
            it--;
            if (*it == bad) return -1;
            ans++;
        }

        return ans;
    }
};
