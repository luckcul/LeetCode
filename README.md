# LeetCode

## LeetCode Algorithms

### [338. Counting Bits](https://leetcode.com/problems/counting-bits/)

It's easy to solve this problem by O(n*log(n)) algorithm. 

But we can make use of what we have produced already. The time complexity of this dynamic programming algorithm is **O(n)**. 

For num`i` and `i-1` , it's only different for the low part in their binary format. For example, number 23(10111) and 24(11000), the high part `1`  is same, the another part `0111` and `1000` is different. We can get the result of `11000` by the result of  number `10000` (set the low part to zero).

solution: **result[i] = result[i & (i-1)] + 1.**

### [344.Reverse String](https://leetcode.com/problems/reverse-string/)

A simple problem about string. Just reverse a string.

