class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
        
        if (totalSum == 0) return 0; 
        
        unordered_map<int, int> prefixSumIndex;
        prefixSumIndex[0] = -1; 
        int currentSum = 0;
        int minLength = n;
        
        for (int i = 0; i < n; ++i) {
            currentSum = (currentSum + nums[i]) % p;
            int target = (currentSum - totalSum + p) % p;
            if (prefixSumIndex.find(target) != prefixSumIndex.end()) {
                minLength = min(minLength, i - prefixSumIndex[target]);
            }
            prefixSumIndex[currentSum] = i;
        }
        
        return minLength == n ? -1 : minLength;
    }
};
