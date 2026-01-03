class Solution {
public:
    map<char, bool> vow;
    
    bool check(string s) {
        return vow[s[0]] && vow[s[s.length()-1]];
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vow['a'] = true;
        vow['e'] = true;
        vow['i'] = true;
        vow['o'] = true;
        vow['u'] = true;
        
        int n = words.size();
        vector<int> v(n+1, 0);
        v[0] = 0;
        
        for (int i=1; i<n+1; i++) {
            v[i] = v[i-1] + check(words[i-1]);
        }
        
        vector<int> ans;
        for (vector<int> i : queries) {
            ans.push_back(v[i[1]+1] - v[i[0]]);
        }
        
        return ans;
    }
};
