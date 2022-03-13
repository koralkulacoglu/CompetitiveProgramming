class Solution {
public:
    int maximumTop(vector<int>& a, int k) {
        int n=a.size(), ans=0;
        if (n == 1) {
            return k%2?-1:a[0];
        }
        if (k > n) {
            return *max_element(a.begin(), a.begin()+n);
        }
        if (k == n) {
            return *max_element(a.begin(), a.begin()+n-1);
        }
        int mx=-1, sec=-1, idx=0;
        for (int i=0; i<k; i++) {
            if (a[i] >= mx) {
                sec = mx;
                mx = a[i];
                idx = i;
            }
            else if (a[i] >= sec) {
                sec = a[i];
            }
        }
        if ((a[k] > mx) || (k == idx+1 && a[k] > sec)) return a[k];
        if (k == idx+1) return sec!=-1?sec:a[1];
        return mx;
    }
};
