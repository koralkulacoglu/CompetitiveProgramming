class SmallestInfiniteSet {
public:
    set<int> removed;
    SmallestInfiniteSet() {
        ;
    }
    
    int popSmallest() {
        for (int i=1; i<1e9; i++) {
            if (removed.find(i) == removed.end()) {
                removed.insert(i);
                return i;
            }
        }
        return -1;
    }
    
    void addBack(int num) {
        removed.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
