# LeetCode 78 - Subsets

## Problem Statement

Given an integer array `nums` of **unique** elements, return *all possible subsets* (the power set).

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

**LeetCode Link:** https://leetcode.com/problems/subsets/

---

## Examples

**Example 1:**
```
Input:  nums = [1, 2, 3]
Output: [[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]]
```

**Example 2:**
```
Input:  nums = [0]
Output: [[], [0]]
```

---

## Approach — Backtracking (Include / Exclude)

For every element we make a binary choice: **include** it in the current subset or **exclude** it. Recursing through all elements this way generates every possible subset exactly once.

### Steps:
1. Start with an empty `subset` and index `0`.
2. At each index, **include** `nums[index]`, recurse, then **exclude** (pop) and recurse again.
3. When `index == nums.size()`, the current `subset` is complete — add it to `res`.

This explores a binary decision tree of depth `n`, producing all `2^n` subsets.

---

## Solution

```cpp
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
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(n * 2^n)` — `2^n` subsets, each taking up to `O(n)` to copy |
| **Space** | `O(n)` — recursion stack depth is at most `n` |

---

## Constraints

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- All the numbers of `nums` are **unique**
