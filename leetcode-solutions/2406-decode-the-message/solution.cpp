class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        mp[' '] = ' ';
        char cur = 'a';
        for (char c : key) {
            if (mp.find(c) != mp.end()) continue;
            mp[c] = cur;
            cur++;
            if (cur > 'z') break;
        }

        int n = message.size();
        for (int i=0; i<n; i++) {
            message[i] = mp[message[i]];
        }

        return message;
    }
};
