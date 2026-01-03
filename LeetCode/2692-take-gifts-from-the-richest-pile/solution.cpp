class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> vals;
        for (int i : gifts) vals.push(i);
        
        for (int i=0; i<k; i++) {
            int val = sqrt(vals.top());
            vals.pop();
            vals.push(val);
        }
        
        long long ans = 0;
        while (!vals.empty()) {
            ans += vals.top();
            vals.pop();
        }
        
        return ans;
    }
};
