class Solution {
public:
    // We use a flat struct with integer indices instead of pointers
    struct Node {
        int children[26];
        int minLen;
        int bestIdx;
    };

    // Store all nodes in a single vector (Memory Pool)
    vector<Node> trie;

    // Helper to create a new node in the pool
    int newNode() {
        Node node;
        fill(begin(node.children), end(node.children), -1); 
        node.minLen = 1e9;
        node.bestIdx = -1;
        trie.push_back(node);
        return trie.size() - 1;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();
        trie.reserve(500005); 

        int root = newNode();

        for (int i = 0; i < wordsContainer.size(); ++i) {
            const string& w = wordsContainer[i];
            int len = w.length();
            int curr = root;

            if (len < trie[curr].minLen) {
                trie[curr].minLen = len;
                trie[curr].bestIdx = i;
            }

            for (int j = len - 1; j >= 0; --j) {
                int c = w[j] - 'a';
                if (trie[curr].children[c] == -1) {
                    trie[curr].children[c] = newNode();
                }
                curr = trie[curr].children[c];

                if (len < trie[curr].minLen) {
                    trie[curr].minLen = len;
                    trie[curr].bestIdx = i;
                }
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (const string& w : wordsQuery) {
            int curr = root;
            int len = w.length();
            
            for (int j = len - 1; j >= 0; --j) {
                int c = w[j] - 'a';
                if (trie[curr].children[c] == -1) {
                    break; 
                }
                curr = trie[curr].children[c];
            }
            ans.push_back(trie[curr].bestIdx);
        }

        return ans;
    }
};

