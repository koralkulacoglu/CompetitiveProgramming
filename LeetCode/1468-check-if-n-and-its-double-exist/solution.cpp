class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, bool> vis;
        for (int &i : arr) {
            if ((i%2==0 && vis[i/2]) || vis[i*2]) {
                return true;
            }
            vis[i] = true;
        }
        return false;
    }
};
