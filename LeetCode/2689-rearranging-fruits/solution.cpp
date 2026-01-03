class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<long long, int> freq, freq1, freq2;

        // create frequency maps
        for (int i : basket1) {
            freq[i]++;
            freq1[i]++;
        }
        
        for (int i : basket2) {
            freq[i]++;
            freq2[i]++;
        }

        // check if possible
        for (auto i : freq) {
            long long val = i.first;
            int f1 = freq1[val];
            int f2 = freq2[val];
            if ((f1 + f2) % 2) return -1;
        }

        // create remaining arrays
        vector<long long> rem1, rem2;
        for (auto i : freq) {
            long long val = i.first;
            int f1 = freq1[val];
            int f2 = freq2[val];

            if (f1 > f2) {
                for (int j=0; j<f1-f2; j++) rem1.push_back(val);
            }
            else if (f2 > f1) {
                for (int j=0; j<f2-f1; j++) rem2.push_back(val);
            }
        }

        // for (int i : rem1) cout << i << ' ';
        // cout << endl;
        // for (int i : rem2) cout << i << ' ';
        // cout << endl;

        /*
        at this point we have an even number of elements
        size of rem1 = rem2
        at each swap we either:
            get rid of 4 elements (cost = min value of the 4 elements)
                pair max with min element
            get rid of 2 elements by using the overall min value (cost = overall min * 2)
                running this twice is equivalent to getting rid of 4 elements
        */

        long long globalMin = freq.begin()->first;
        // cout << globalMin << endl;

        int n = rem1.size();
        long long cost = 0;
        for (int i=0; i<n; i+=2) {
            long long cost1 = globalMin * 2;
            long long cost2 = min(rem1[i], rem2[n-i-1]);
            cost += min(cost1, cost2);
        }
        
        return cost;
    }
};
