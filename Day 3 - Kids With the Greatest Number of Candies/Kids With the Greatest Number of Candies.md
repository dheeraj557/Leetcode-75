Problem link : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75

There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

 

Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
 

Constraints:

n == candies.length
2 <= n <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50
 
**Solution**

- **Idea:** Find the maximum number of candies any kid currently has. For each kid, give them all `extraCandies` and check whether their new total is at least that maximum. If it is, they can have the greatest number of candies.

- **Steps in the code:**
	- Compute `maxval` by iterating once over `candies`.
	- Create a `vector<bool> ans` and for each `i` in `candies` push `true` if `i + extraCandies >= maxval`, otherwise push `false`.
	- Return `ans`.

- **Why it works:** The only thing that matters when deciding if a kid can reach the greatest count after receiving all extra candies is the current global maximum. Comparing each kid's potential total to that maximum gives the correct boolean result.

- **Time Complexity:** O(n) — one pass to find the maximum and one pass to build the result.
- **Space Complexity:** O(n) — the output vector of size `n` (ignoring input storage).

- **Code notes:** The provided C++ solution follows this approach: it initializes `maxval`, finds the maximum, then constructs the answer vector by pushing `true`/`false` based on the comparison `i + extraCandies >= maxval`.
 
