class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = 0;
        int n = skill.size();
        for (int i = 0; i < n; i++) {
            sum += skill[i];
        }

        if (n == 2) {
            return skill[0] * skill[1];
        }
        if (sum % (n / 2) != 0) {
            return -1;
        }

        sort(skill.begin(), skill.end());
        int pair = sum / (n / 2);
        int i = 0;
        int j = n - 1;
        long long ans = 0;

        while (i < j) {
            int currentSum = skill[i] + skill[j];
            if (currentSum == pair) {
                ans += skill[i] * skill[j];
                i++;
                j--;
            } else if (currentSum > pair) {
                return -1;  // If the sum is greater, it means we can't form the required pairs
            } else {
                return -1;  // If the sum is less, it also means we can't form the required pairs
            }
        }

        return ans;
    }
};
