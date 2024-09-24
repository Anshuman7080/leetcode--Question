class Solution {
private:
    void solve(unordered_set<string>& prefix, string n, string temp, int index) {
        if (index == n.length()) {
            return;
        }
        temp += n[index];
        prefix.insert(temp);
        solve(prefix, n, temp, index + 1);
    }

    void solve2(unordered_set<string>& prefix, string n, int index, string temp, int& len) {
        if (index == n.length()) {
            return;
        }
        temp += n[index];
        if (prefix.find(temp) != prefix.end()) {
            len = std::max(len, static_cast<int>(temp.length()));
        }
        solve2(prefix, n, index + 1, temp, len);
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefix;
        for (int i = 0; i < arr1.size(); i++) {
            int index = 0;
            string temp = "";
            string n = to_string(arr1[i]);
            solve(prefix, n, temp, index);
        }

        int len = 0;
        for (int i = 0; i < arr2.size(); i++) {
            string n = to_string(arr2[i]);
            int index = 0;
            string temp = "";
            solve2(prefix, n, index, temp, len);
        }

        return len;
    }
};
