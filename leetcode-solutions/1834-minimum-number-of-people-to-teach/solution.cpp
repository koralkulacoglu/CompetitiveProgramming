#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    // The DFS and related members are removed because the "connected component" 
    // approach was the part that needed adjustment.

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // For efficiency, it's helpful to put user languages into sets for fast lookups.
        std::vector<std::unordered_set<int>> lang_sets(m + 1);
        for(int i = 0; i < m; ++i) {
            lang_sets[i+1] = std::unordered_set<int>(languages[i].begin(), languages[i].end());
        }

        // STEP 1: Identify the correct "group" of users.
        // This set will contain only users who are part of a non-communicating friendship.
        std::unordered_set<int> group_to_fix; 
        for (vector<int>& f : friendships) {
            int u = f[0];
            int v = f[1];

            bool can_communicate = false;
            // Check for a common language
            for (int lang_u : lang_sets[u]) {
                if (lang_sets[v].count(lang_u)) {
                    can_communicate = true;
                    break;
                }
            }
            // If they can't talk, add both to our group that needs fixing.
            if (!can_communicate) {
                group_to_fix.insert(u);
                group_to_fix.insert(v);
            }
        }

        // If the group is empty, no one needs teaching.
        if (group_to_fix.empty()) {
            return 0;
        }

        // STEP 2: Your original logic for finding the best language now works perfectly!
        // We just apply it to our correctly defined `group_to_fix`.
        int ans = m; // Initialize with max possible teachings
        for (int l = 1; l <= n; l++) {
            // teach language l
            int curAns = 0;
            for (int user : group_to_fix) {
                // Count how many people in our group need to be taught language 'l'
                if (lang_sets[user].find(l) == lang_sets[user].end()) {
                    curAns++;
                }
            }
            ans = std::min(ans, curAns);
        }

        return ans;
    }
};
