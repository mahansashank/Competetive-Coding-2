#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        createSubset(nums, 0, res, subset);
        return res;
    }

    void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        createSubset(nums, index + 1, res, subset);

        subset.pop_back();
        createSubset(nums, index + 1, res, subset);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3};
    auto res1 = sol.subsets(nums1);
    cout << "Example 1:\n";
    for (auto& s : res1) {
        cout << "[";
        for (int i = 0; i < s.size(); i++) {
            cout << s[i];
            if (i + 1 < s.size()) cout << ",";
        }
        cout << "]\n";
    }

    vector<int> nums2 = {0};
    auto res2 = sol.subsets(nums2);
    cout << "Example 2:\n";
    for (auto& s : res2) {
        cout << "[";
        for (int i = 0; i < s.size(); i++) {
            cout << s[i];
            if (i + 1 < s.size()) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
