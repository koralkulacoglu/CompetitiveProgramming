class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, bool> vis;
        unordered_map<char, char> p;
        char cur='a';
        for (int i : key) {
            if (vis[i] || i == ' ') continue;
            p[i] = cur;
            cur++;
            vis[i] = true;
        }
        for (int i=0; i<message.size(); i++) {
            if (message[i] == ' ') continue;
            message[i] = p[message[i]];
        }
        return message;
    }
};
