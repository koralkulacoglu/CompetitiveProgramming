class MedianFinder {
    priority_queue<int, vector<int>, less<int>> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
public:
    MedianFinder() = default;
    
    void addNum(int num) {
        if (leftHeap.empty() || num <= leftHeap.top()) leftHeap.push(num);
        else rightHeap.push(num);

        while (leftHeap.size() > rightHeap.size() + 1) {
            int val = leftHeap.top();
            leftHeap.pop();
            rightHeap.push(val);
        }
        while (leftHeap.size() + 1 < rightHeap.size()) {
            int val = rightHeap.top();
            rightHeap.pop();
            leftHeap.push(val);
        }
    }
    
    double findMedian() {
        if (leftHeap.empty() || rightHeap.size() > leftHeap.size()) {
            return rightHeap.top();
        }

        if (rightHeap.empty() || leftHeap.size() > rightHeap.size()) {
            return leftHeap.top();
        }

        return (leftHeap.top() + rightHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
