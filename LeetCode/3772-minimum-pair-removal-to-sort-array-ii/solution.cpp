class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<long long> val(n);
        vector<int> left(n, -1), right(n, -1);
        
        int inversions = 0;
        
        auto cmp = [](const vector<long long>& a, const vector<long long>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] > b[1];
        };
        priority_queue<vector<long long>, vector<vector<long long>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < n; i++) {
            val[i] = nums[i];
            if (i < n - 1) {
                right[i] = i + 1;
                left[i + 1] = i;
                
                if (nums[i] > nums[i+1]) inversions++;
                
                pq.push({(long long)nums[i] + nums[i+1], (long long)i, (long long)i + 1});
            }
        }

        int ops = 0;

        while (inversions > 0 && !pq.empty()) {
            vector<long long> top = pq.top();
            pq.pop();

            long long stored_sum = top[0];
            int l_idx = (int)top[1];
            int r_idx = (int)top[2];

            if (right[l_idx] != r_idx || left[r_idx] != l_idx) {
                continue;
            }

            if (stored_sum != val[l_idx] + val[r_idx]) {
                continue;
            }

            ops++;

            if (val[l_idx] > val[r_idx]) inversions--;
            
            int l_neighbor = left[l_idx];
            if (l_neighbor != -1 && val[l_neighbor] > val[l_idx]) inversions--;
            
            int r_neighbor = right[r_idx];
            if (r_neighbor != -1 && val[r_idx] > val[r_neighbor]) inversions--;

            val[l_idx] = val[l_idx] + val[r_idx];
            
            right[l_idx] = r_neighbor;
            if (r_neighbor != -1) {
                left[r_neighbor] = l_idx;
            }

            left[r_idx] = -1;
            right[r_idx] = -1;

            if (l_neighbor != -1 && val[l_neighbor] > val[l_idx]) inversions++;
            if (r_neighbor != -1 && val[l_idx] > val[r_neighbor]) inversions++;

            if (l_neighbor != -1) {
                pq.push({val[l_neighbor] + val[l_idx], (long long)l_neighbor, (long long)l_idx});
            }
            if (r_neighbor != -1) {
                pq.push({val[l_idx] + val[r_neighbor], (long long)l_idx, (long long)r_neighbor});
            }
        }

        return ops;
    }
};
