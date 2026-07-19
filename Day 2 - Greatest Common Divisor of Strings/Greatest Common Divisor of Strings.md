# Greatest Common Divisor of Strings

This solution uses a brute-force approach to find the largest string that can divide both given strings.

## Problem Idea

We need to find the greatest common divisor string of two strings, `str1` and `str2`.

A valid answer must satisfy two conditions:

- Both strings must be made by repeating the same base string some number of times.
- The length of that base string must divide the lengths of both strings.

For example, if the answer is `"abc"`, then:

- `str1` must be `"abcabc"` or `"abcabcabc"`
- `str2` must be `"abcabcabcabc"` etc.

## Brute-Force Approach

The code tries every possible prefix of the smaller string as a candidate answer.

### Step 1: Try every possible length

The loop starts from the smaller of the two string lengths and goes down to `1`:

- `base = str1.substr(0, i)` takes the first `i` characters as a possible common divisor.
- Each candidate is checked using the helper function `isvalid`.

### Step 2: Check if the candidate is valid

The `isvalid` function verifies whether the candidate string can form both inputs:

- It first checks whether both string lengths are divisible by the candidate length.
- Then it checks whether `str1` and `str2` are exactly equal to repeated versions of the candidate.

This is done using the helper function `joinwords`, which repeats a string `k` times.

### Step 3: Return the first valid candidate

The loop checks candidates from largest to smallest, so the first valid one found is the greatest common divisor string.

If no valid candidate exists, the function returns an empty string.

## How the Helpers Work

### `isvalid`

This function checks whether a given `base` can generate both strings:

- `len1 % len3 == 0` and `len2 % len3 == 0` ensure the base length evenly divides both strings.
- `joinwords(base, q1)` and `joinwords(base, q2)` rebuild the two strings from the base.
- If both rebuilt strings match the originals, the candidate is valid.

### `joinwords`

This function repeats a string `k` times and returns the combined result.

## Complexity

This is a brute-force solution, so it checks many candidates one by one.

- It is simple and easy to understand.
- It is not the most efficient approach for very large strings.

In short, the program tries every possible common divisor candidate, tests it, and returns the first one that works.
