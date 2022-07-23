class NumberContainers {
public:
    map<int, set<int>> idxs;
    map<int, int> idxVal;
    NumberContainers() {
        ;
    }
    
    void change(int index, int number) {
        if (idxVal[index] == 0) {
            idxVal[index] = number;
            idxs[number].insert(index);
        }
        else {
            idxs[idxVal[index]].erase(index);
            idxVal[index] = number;
            idxs[number].insert(index);
        }
    }
    
    int find(int number) {
        return idxs[number].empty() ? -1 : *idxs[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
