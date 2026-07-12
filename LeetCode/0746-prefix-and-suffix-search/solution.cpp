class WordFilter {
    struct Trie {
        vector<Trie*> children = vector<Trie*>(26, nullptr);
        vector<int> indices;
    };

    Trie* prefTrie;
    Trie* suffTrie;

public:
    WordFilter(vector<string>& words) {
        prefTrie = new Trie();
        suffTrie = new Trie();

        int n = words.size();
        for (int i=0; i<n; i++) {
            string& word = words[i];

            Trie* tempPref = prefTrie;
            Trie* tempSuff = suffTrie;

            int m = word.size();
            for (int j=0; j<m; j++) {
                int idx = word[j] - 'a';

                if (tempPref->children[idx] == nullptr) tempPref->children[idx] = new Trie();
                tempPref = tempPref->children[idx];
                tempPref->indices.push_back(i);
            }

            for (int j=m-1; j>=0; j--) {
                int idx = word[j] - 'a';

                if (tempSuff->children[idx] == nullptr) tempSuff->children[idx] = new Trie();
                tempSuff = tempSuff->children[idx];
                tempSuff->indices.push_back(i);
            }
        }
    }
    
    int f(string pref, string suff) {
        Trie* tempPref = prefTrie;
        Trie* tempSuff = suffTrie;
        int n = pref.size();
        int m = suff.size();

        for (int i=0; i<n; i++) {
            int idx = pref[i] - 'a';
            tempPref = tempPref->children[idx];
            if (tempPref == nullptr) return -1;
        }

        for (int i=m-1; i>=0; i--) {
            int idx = suff[i] - 'a';
            tempSuff = tempSuff->children[idx];
            if (tempSuff == nullptr) return -1;
        }

        vector<int>& prefIdxs = tempPref->indices;
        vector<int>& suffIdxs = tempSuff->indices;

        int k = prefIdxs.size();
        int l = suffIdxs.size();

        for (int i=k-1, j=l-1; i>=0; i--) {
            while (prefIdxs[i] < suffIdxs[j]) {
                j--;
                if (j < 0) return -1;
            }
            if (prefIdxs[i] == suffIdxs[j]) return prefIdxs[i];
        }

        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */

