# LeetCode 34 - Find First and Last Position of Element in Sorted Array

## Problem Statement

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

**LeetCode Link:** https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

---

## Examples

**Example 1:**
```
Input:  nums = [5, 7, 7, 8, 8, 10], target = 8
Output: [3, 4]
```

**Example 2:**
```
Input:  nums = [5, 7, 7, 8, 8, 10], target = 6
Output: [-1, -1]
```

**Example 3:**
```
Input:  nums = [], target = 0
Output: [-1, -1]
```

---

## Approach — Two Binary Searches

We run **two separate Binary Searches** — one to find the **first occurrence** and one to find the **last occurrence** of the target.

### Finding First Occurrence (`firstOcc`)
- When `nums[mid] == target`, record the index but **keep searching left** (`right = mid - 1`) to find an earlier occurrence.
- If `target <= nums[mid]`, move left.
- Else move right.

### Finding Last Occurrence (`lastOcc`)
- When `nums[mid] == target`, record the index but **keep searching right** (`left = mid + 1`) to find a later occurrence.
- If `target >= nums[mid]`, move right.
- Else move left.

---

## Solution

```java
class Solution {
    public static int firstOcc(int nums[], int target) {
        int left = 0;
        int right = nums.length - 1;
        int index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) index = mid;
            if (target <= nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return index;
    }

    public static int lastOcc(int nums[], int target) {
        int left = 0;
        int right = nums.length - 1;
        int index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) index = mid;
            if (target >= nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return index;
    }

    public int[] searchRange(int[] nums, int target) {
        int arr[] = new int[2];
        arr[0] = firstOcc(nums, target);
        arr[1] = lastOcc(nums, target);
        return arr;
    }
}
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(log n)` — Two independent binary searches, each `O(log n)` |
| **Space** | `O(1)` — No extra space used beyond result array |

---

## Constraints

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `nums` is sorted in **non-decreasing** order
- `-10^9 <= target <= 10^9`
