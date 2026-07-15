You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

## Solution Explanation

The implementation uses two pointers to merge `word1` and `word2` character by character:

- Initialize `i` for `word1` and `j` for `word2` at 0.
- Use a `result` string to build the merged output.
- While both pointers are within their string lengths, append `word1[i]` then `word2[j]`, and increment both pointers.
- After the loop, one string may still have remaining characters. Append any leftover characters from `word1` or `word2` in order.

This correctly produces the alternating merged string and handles the case when one word is longer by appending the extra tail characters.

### Code behavior

- `while(i < word1.size() and j < word2.size())`: alternate characters from both strings.
- `while(i < word1.size())`: append remaining characters from `word1`.
- `while(j < word2.size())`: append remaining characters from `word2`.

The function returns the final merged string.
