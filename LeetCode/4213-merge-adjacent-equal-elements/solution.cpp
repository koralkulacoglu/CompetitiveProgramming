class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> pref;

        auto merge = [&]() {
            while (true) {
                int n = pref.size();
                if (n <= 1) break;
                
                long long temp = pref[n-1];
                if (temp == pref[n-2]) {
                    pref.pop_back();
                    pref.pop_back();
                    pref.push_back(temp + temp);
                }
                else break;
            }
        };
        
        for (long long i : nums) {
            pref.push_back(i);
            merge();
        }

        return pref;
    }
};
