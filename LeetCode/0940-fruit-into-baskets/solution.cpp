class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        
        int fruit1 = -1;
        int fruit2 = -1;
        int count1 = 0;
        int count2 = 0;
        int ans = 0;
        int left = 0;
        for (int right=0; right<n; right++) {
            int curFruit = fruits[right];
            if (fruit1 == -1 || curFruit == fruit1) {
                fruit1 = curFruit;
                count1++;
            }
            else if (fruit2 == -1 || curFruit == fruit2) {
                fruit2 = curFruit;
                count2++;
            }
            else {
                while (left < n && count1 > 0 && count2 > 0) {
                    int leftFruit = fruits[left];
                    if (leftFruit == fruit1) count1--;
                    else if (leftFruit == fruit2) count2--;
                    left++;
                }

                if (count1 == 0) {
                    fruit1 = curFruit;
                    count1++;
                }
                else {
                    fruit2 = curFruit;
                    count2++;
                }
            }

            // cout << fruit1 << ':' << count1 << endl;
            // cout << fruit2 << ':' << count2 << endl;
            // cout << endl;

            int curAns = count1 + count2;

            ans = max(ans, curAns);
        }

        return ans;
    }
};
