# LeetCode 35 - Search Insert Position

## Problem Statement

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

**LeetCode Link:** https://leetcode.com/problems/search-insert-position/

---

## Examples

**Example 1:**
```
Input:  nums = [1, 3, 5, 6], target = 5
Output: 2
```

**Example 2:**
```
Input:  nums = [1, 3, 5, 6], target = 2
Output: 1
```

**Example 3:**
```
Input:  nums = [1, 3, 5, 6], target = 7
Output: 4
```

---

## Approach — Binary Search

Since the array is **sorted**, we can use **Binary Search** to find the target or the correct insertion position in `O(log n)` time.

### Key Insight
When the while loop ends without finding the target, `low` always points to the correct insertion index. This is because:
- If `target > nums[mid]`, we move `low` up → target belongs after `mid`
- If `target < nums[mid]`, we move `high` down → target belongs before or at `mid`

At termination, `low > high` and `low` is exactly where the target should be inserted.

### Algorithm
1. Initialize `low = 0`, `high = nums.length - 1`
2. While `low <= high`:
   - Compute `mid = low + (high - low) / 2`
   - If `nums[mid] == target` → return `mid`
   - If `target > nums[mid]` → search right half: `low = mid + 1`
   - Else → search left half: `high = mid - 1`
3. Return `low` (insertion point)

---

## Solution

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
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

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` contains **distinct** values sorted in **ascending** order
- `-10^4 <= target <= 10^4`
