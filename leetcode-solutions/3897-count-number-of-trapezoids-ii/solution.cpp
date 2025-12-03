class Solution {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long countValidPairsInMap(map<pair<int, int>, vector<pair<int, int>>>& groups, vector<vector<int>>& points) {
        long long count = 0;

        for (auto& entry : groups) {
            pair<int, int> slope = entry.first;
            vector<pair<int, int>>& segments = entry.second;
            vector<long long> intercepts;
            for (auto& seg : segments) {
                long long val = (long long)slope.second * points[seg.first][1] - (long long)slope.first * points[seg.first][0];
                intercepts.push_back(val);
            }
            
            sort(intercepts.begin(), intercepts.end());

            long long totalSegments = intercepts.size();
            long long collinearPairs = 0;
            long long currentRun = 1;

            for (int k = 1; k < totalSegments; k++) {
                if (intercepts[k] == intercepts[k-1]) {
                    currentRun++;
                } else {
                    collinearPairs += currentRun * (currentRun - 1) / 2;
                    currentRun = 1;
                }
            }
            collinearPairs += currentRun * (currentRun - 1) / 2;

            long long totalPairs = totalSegments * (totalSegments - 1) / 2;
            count += (totalPairs - collinearPairs);
        }
        return count;
    }

public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        
        map<pair<int, int>, vector<pair<int, int>>> slopes;
        map<pair<int, int>, vector<pair<int, int>>> vectors;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dy = points[i][1] - points[j][1];
                int dx = points[i][0] - points[j][0];
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                
                vectors[{dy, dx}].push_back({i, j});

                int g = gcd(abs(dy), abs(dx));
                dy /= g;
                dx /= g;
                slopes[{dy, dx}].push_back({i, j});
            }
        }

        long long totalSlopePairs = countValidPairsInMap(slopes, points);
        long long totalVectorPairs = countValidPairsInMap(vectors, points);

        return totalSlopePairs - (totalVectorPairs / 2);
    }
};
