class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};

        vector<int> copy = arr;
        sort(copy.begin(), copy.end());

        unordered_map<int, int> map;
        int rank = 1;
        map[copy[0]] = rank;

        for (int i = 1; i < copy.size(); ++i) {
            if (copy[i] != copy[i - 1]) {
                ++rank;
            }
            map[copy[i]] = rank;
        }

        vector<int> ans;
        for (int i = 0; i < arr.size(); ++i) {
            ans.push_back(map[arr[i]]);
        }

        return ans;
    }
};
