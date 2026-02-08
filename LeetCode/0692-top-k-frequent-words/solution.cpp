struct Item {
    int freq;
    string word;

    bool operator<(const Item& other) const {
        if (freq < other.freq) return true;
        if (freq > other.freq) return false;
        return word > other.word;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string word : words) freq[word]++;
        set<Item> s;
        for (auto i : freq) s.insert(Item(i.second, i.first));
        vector<string> res;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (k == 0) break;
            k--;
            res.push_back(it->word);
        }
        return res;
    }
};
