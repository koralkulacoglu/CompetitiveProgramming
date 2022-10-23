// binary search for each number and remove from set.
// any two distinct indices (i didn't see this)

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        
        map<int, int> valsEven, negEven, valsOdd, negOdd;
        // multiset<int> valsEven, negEven, valsOdd, negOdd;
        for (int i : target) {
            if (i%2) {
                valsOdd[i]++;
                negOdd[-i]++;
            }
            else {
                valsEven[i]++;
                negEven[-i]++;
            }
        }
        
        sort(nums.begin(), nums.end());
                
        long long ans = 0;
        for (int i=0; i<n; i++) {
            int val = nums[i];
            
            if (val%2) {
                auto higherv = valsOdd.lower_bound(val);
                auto lowerv = negOdd.lower_bound(-val);
                
                int higher = (*higherv).first;
                int lower = -(*lowerv).first;
                
                if (lowerv == negOdd.end()) {
                    valsOdd[higher]--;
                    if (valsOdd[higher] == 0) valsOdd.erase(higher);
                    
                    negOdd[-higher]--;
                    if (negOdd[-higher] == 0) negOdd.erase(-higher);
                    
                    ans += abs(val - higher)/2;
                }
                else {
                    valsOdd[lower]--;
                    if (valsOdd[lower] == 0) valsOdd.erase(lower);
                    
                    negOdd[-lower]--;
                    if (negOdd[-lower] == 0) negOdd.erase(-lower);
                    ans += abs(val - lower)/2;
                }
            }
            else {
                auto higherv = valsEven.lower_bound(val);
                auto lowerv = negEven.lower_bound(-val);
                
                int higher = (*higherv).first;
                int lower = -(*lowerv).first;
                
                if (lowerv == negEven.end()) {
                    valsEven[higher]--;
                    if (valsEven[higher] == 0) valsEven.erase(higher);
                    
                    negEven[-higher]--;
                    if (negEven[-higher] == 0) negEven.erase(-higher);
                    
                    ans += abs(val - higher)/2;
                }
                else {
                    valsEven[lower]--;
                    if (valsEven[lower] == 0) valsEven.erase(valsEven.find(lower));
                    
                    negEven[-lower]--;
                    if (negEven[-lower] == 0) negEven.erase(-lower);
                    
                    ans += abs(val - lower)/2;
                }
            }
        }
        return ans/2;
    }
};
