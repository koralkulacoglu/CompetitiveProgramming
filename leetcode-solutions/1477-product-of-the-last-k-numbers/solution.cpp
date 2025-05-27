class ProductOfNumbers {
public:
    vector<int> a;

    ProductOfNumbers() {
        a.clear();
    }
    
    void add(int num) {
        int n = a.size();
        if (num) {
            if (n) a.push_back(a[n-1] * num);
            else a.push_back(num);
        }
        else a.clear();
    }
    
    int getProduct(int k) {
        int n = a.size();
        if (k > n) return 0;
        return a[n-1] / (n-k > 0 ? a[n-k-1] : 1);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
