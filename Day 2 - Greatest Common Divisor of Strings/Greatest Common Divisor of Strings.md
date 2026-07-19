Problem link : https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
# Greatest Common Divisor of Strings

## Problem Idea

We need to find the largest string that can be repeated to form both given strings.

A valid answer must satisfy these conditions:

- Both strings must be made by repeating the same base string.
- That base string must divide the lengths of both strings evenly.

For example, if the answer is `"abc"`, then:

- `"abcabc"` and `"abcabcabc"` are valid
- but `"abca"` would not be valid

## Approach 1: Brute Force

This approach tries every possible prefix of the first string as a candidate answer.

### How it works

- Start from the smaller length and check each possible length from large to small.
- Take the first `i` characters of `str1` as a candidate base string.
- Check whether that candidate can form both strings by repeating it the correct number of times.
- The first valid candidate found is the answer.

### Why it works

If a string is a common divisor, then it must be a prefix of both strings and must repeat evenly to make them.

### Complexity

- Time complexity: `O(n * m)` in practice, because many candidate strings are tested
- Space complexity: `O(n + m)` for the repeated strings built during checking

## Approach 2: Optimized Solution

This solution is much faster and uses a clever observation.

### Key idea

If a common repeating string exists, then:

- `str1 + str2` must be equal to `str2 + str1`
- otherwise, no valid non-empty answer exists

If this condition passes, then the answer is simply the prefix of `str1` of length equal to the greatest common divisor of the two string lengths.

### Why it works

If both strings are made by repeating the same base string, then their lengths must share a common divisor, and the base string must be the repeating pattern.

### Code Summary

The implementation does three things:

1. Checks whether a common repeating pattern is possible.
2. Finds the GCD of the two string lengths.
3. Returns the prefix of the first string with that length.

### Complexity

- Time complexity: `O(n + m)`
- Space complexity: `O(n + m)`

## Example

Suppose:

- `str1 = "abcabc"`
- `str2 = "abcabcabc"`

The common pattern is `"abc"`.

- Lengths are `6` and `9`
- GCD of `6` and `9` is `3`
- The answer is the first `3` characters of `str1`, which is `"abc"`

## Summary

- The brute-force approach is simple but slower.
- The optimized approach is the standard efficient solution for this problem.
