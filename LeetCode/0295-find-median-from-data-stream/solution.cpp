class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    void addNum(int num) {
        if (left.empty() || num <= left.top()) left.push(num);
        else right.push(num);

        int leftSize = left.size();
        int rightSize = right.size();

        if (rightSize > leftSize + 1) {
            int median = right.top();
            right.pop();
            left.push(median);
        }
        else if (leftSize > rightSize + 1) {
            int median = left.top();
            left.pop();
            right.push(median);
        }
    }
    
    double findMedian() {
        int leftSize = left.size();
        int rightSize = right.size();

        if (rightSize > leftSize) return right.top();
        if (rightSize < leftSize) return left.top();

        return double(left.top() + right.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
