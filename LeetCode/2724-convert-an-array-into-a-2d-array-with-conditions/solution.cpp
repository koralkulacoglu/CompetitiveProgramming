class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // int count[201] = {0};
        // map (tree ds) O(log_2(n)), hashmap (uses hashing) O(1) (hash collision)

        unordered_map<int, int> count;

        vector<vector<int>> result;

        for (int i{}; i < nums.size(); i++){
            count[nums[i]]++;
        }

        while(true){
            vector<int> temp;
            for (auto i : count) {
                // i: {i.first: key, i.second: value}
                if (count[i.first] > 0){
                    count[i.first]--;
                    temp.push_back(i.first);
                }
            }
            if (temp.empty()){
                break;
            }
            result.push_back(temp);
        }

        return result;
    }
};

