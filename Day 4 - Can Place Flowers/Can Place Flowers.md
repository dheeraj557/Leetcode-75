Problem link : https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
 

**Solution**

- **Idea:** Iterate the flowerbed and try to plant a flower at any empty plot (0) only when both neighbors are empty or don't exist (edges). Each time you plant, decrement `n`. If `n` reaches 0, return `true`.

- **Steps in the code:**
	- Handle small sizes explicitly (size 1 is a special case).
	- Loop through the array; for the first index check only the right neighbor, for the last index check only the left neighbor, and for middle indices check both neighbors.
	- When a valid empty plot is found, set it to 1 (simulate planting) and decrement `n`.
	- Return `true` early if `n` becomes 0; otherwise return `false` after the loop.

**Edge cases & Safety (avoid heap/undefined-behavior):**

- **Never access out-of-bounds indices.** Accessing `flowerbed[i+1]` when `i` is `size-1`, or `flowerbed[i-1]` when `i` is `0`, is undefined behavior and can cause crashes or memory corruption. Always check the index or branch on `i==0` / `i==size-1` before touching neighbors.

- **Check for empty or very small arrays before indexed access.** The code treats `size == 1` specially to avoid reading `flowerbed[1]`. If you access `flowerbed[1]` without checking the size first you risk a segmentation fault.


- **Testing edge inputs:** Try `flowerbed` lengths of 1 and 2, `n = 0`, all zeros, and alternating patterns to ensure correctness and to surface any out-of-bounds access.

**Complexity:**

- Time: O(m) where `m` is `flowerbed.length` (single pass, early exit possible).
- Space: O(1) extra space (in-place modification).

**Code note:** The current C++ solution follows this approach: it handles `size == 1` specially, then iterates and performs neighbor checks with separate cases for the first and last positions. The main pitfall to watch for is any unchecked access to `flowerbed[i+1]` or `flowerbed[i-1]`.


