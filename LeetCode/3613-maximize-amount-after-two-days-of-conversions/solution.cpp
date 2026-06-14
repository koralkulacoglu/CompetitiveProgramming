class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<pair<string, double>>> conversions1, conversions2;
        int n = pairs1.size(), m = pairs2.size();

        for (int i=0; i<n; i++) {
            string startCurrency = pairs1[i][0];
            string targetCurrency = pairs1[i][1];
            double rate = rates1[i];
            conversions1[startCurrency].push_back({targetCurrency, rate});
            conversions1[targetCurrency].push_back({startCurrency, 1/rate});
        }

        for (int i=0; i<m; i++) {
            string startCurrency = pairs2[i][0];
            string targetCurrency = pairs2[i][1];
            double rate = rates2[i];
            conversions2[startCurrency].push_back({targetCurrency, rate});
            conversions2[targetCurrency].push_back({startCurrency, 1/rate});
        }

        unordered_map<string, double> maxVal;
        maxVal[initialCurrency] = 1;
        queue<pair<string, double>> q;
        q.push({initialCurrency, 1});
        while (!q.empty()) {
            auto [currency, value] = q.front();
            q.pop();

            if (value < maxVal[currency]) continue;

            for (auto& neigh : conversions1[currency]) {
                string newCurrency = neigh.first;
                double newValue = value * neigh.second;

                if (newValue <= maxVal[newCurrency]) continue;
                
                maxVal[newCurrency] = newValue;
                q.push({newCurrency, newValue});
            }
        }

        for (auto& val : maxVal) q.push(val);
        while (!q.empty()) {
            auto [currency, value] = q.front();
            q.pop();

            if (value < maxVal[currency]) continue;

            for (auto& neigh : conversions2[currency]) {
                string newCurrency = neigh.first;
                double newValue = value * neigh.second;

                if (newValue <= maxVal[newCurrency]) continue;
                
                maxVal[newCurrency] = newValue;
                q.push({newCurrency, newValue});
            }
        }

        return maxVal[initialCurrency];
    }
};
