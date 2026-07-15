# LeetCode 33 - Search in Rotated Sorted Array

## Problem Statement

There is an integer array `nums` sorted in ascending order (with **distinct** values). Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index `k` such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`.

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

**LeetCode Link:** https://leetcode.com/problems/search-in-rotated-sorted-array/

---

## Examples

**Example 1:**
```
Input:  nums = [4, 5, 6, 7, 0, 1, 2], target = 0
Output: 4
```

**Example 2:**
```
Input:  nums = [4, 5, 6, 7, 0, 1, 2], target = 3
Output: -1
```

**Example 3:**
```
Input:  nums = [1], target = 0
Output: -1
```

---

## Approach — Modified Binary Search

A rotated sorted array always has **one sorted half** at any `mid` point. We exploit this property:

### Key Observations
At any `mid`:
1. If `nums[mid] >= nums[start]` → the **left half** `[start..mid]` is sorted
   - If `target` lies within `[nums[start], nums[mid]]` → search left half
   - Otherwise → search right half
2. If `nums[mid] <= nums[end]` → the **right half** `[mid..end]` is sorted
   - If `target` lies within `[nums[mid], nums[end]]` → search right half
   - Otherwise → search left half

### Algorithm
1. Initialize `start = 0`, `end = nums.length - 1`
2. While `start <= end`:
   - Compute `mid = start + (end - start) / 2`
   - If `nums[mid] == target` → return `mid`
   - Check which half is sorted and decide the search direction
3. Return `-1` if not found

---

## Solution

```java
class Solution {
    public int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target == nums[mid]) {
                return mid;
            }
            else if (nums[mid] >= nums[start]) {
                // Left half is sorted
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                }
                else start = mid + 1;
            }
            else if (nums[mid] <= nums[end]) {
                // Right half is sorted
                if (target <= nums[end] && target >= nums[mid]) {
                    start = mid + 1;
                }
                else end = mid - 1;
            }
        }
        return -1;
    }
}
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(log n)` — Binary search halves the search space each iteration |
| **Space** | `O(1)` — Only a constant number of variables used |

---

## Constraints

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- All values in `nums` are **unique**
- `nums` is an ascending sorted array, possibly rotated
- `-10^4 <= target <= 10^4`
