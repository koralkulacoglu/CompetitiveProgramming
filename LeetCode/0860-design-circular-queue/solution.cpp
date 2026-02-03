class MyCircularQueue {
    int n;
    int head;
    int tail;
    int items;
    vector<int> buffer;
public:
    MyCircularQueue(int k) : n(k), head(0), tail(0), items(0), buffer(k) {}
    
    bool enQueue(int value) {
        if (isFull()) return false;
        buffer[head] = value;
        head++;
        head %= n;
        items++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        tail++;
        tail %= n;
        items--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return buffer[tail];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        int temp = (head - 1 + n) % n;
        return buffer[temp];
    }
    
    bool isEmpty() {
        return items == 0;
    }
    
    bool isFull() {
        return items == n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
