class KthLargest {
public:
    int k;
    priority_queue<int> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        for (int i : nums) pq.push(-i);
        for (int i=k; i<n; i++) pq.pop();
    }
    
    int add(int val) {
        pq.push(-val);
        if (pq.size() > k) pq.pop();
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
