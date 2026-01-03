class Solution {
public:
    bool wordPattern(string &pattern, string &s) {
        
        map <string, char> mp1;
        map <char, string> mp2;

        vector<string> v;
        int n = s.size();
        string temp = "";
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
            
        }
        v.push_back(temp);
        
        if(v.size() != pattern.size()){
            return false;
        }

        string t = "";
        
        for(int i = 0; i < v.size(); i++){

            if(mp1.find(v[i]) == mp1.end() and mp2.find(pattern[i]) == mp2.end()){
                    mp1[v[i]] = pattern[i];
                    mp2[pattern[i]] = v[i];
            }
            
            else{
                if(mp1[v[i]] != pattern[i] or mp2[pattern[i]] != v[i]){
                    return false;
                } 
            }
        }

        return true;
    }
};
