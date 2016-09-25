# LeetCode

还尝试英文写题解，实在表达不好，还是上中文。好多题目没有数据范围，有点不适应。

## LeetCode Algorithms

### [1.Two Sum](https://leetcode.com/problems/two-sum/)

求数列中两个数加起来等于目标值。返回这两个值的索引下标。

C++中用map。O(n*log(n))的复杂度。

### [12.Integer to Roman](https://leetcode.com/problems/integer-to-roman/)

Convert an integer to a [roman numeral](https://en.wikipedia.org/wiki/Roman_numerals).

Notice, 4 is IV, and 9 is IX. It's same for 40, 90, 400, 900. And converting integer to roman numeral is the same as converting a decimal number to hexadecimal.

### [13.Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

It is similar to the last problem.

We can convert roman numeral to integer from high to low or low to high.

### [191.Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

求32-bit integer中写成二进制`1`的个数。从末尾依次找即可，O(log(n)) 解决。

### [338. Counting Bits](https://leetcode.com/problems/counting-bits/)

It's easy to solve this problem by O(n*log(n)) algorithm. 

But we can make use of what we have produced already. The time complexity of this dynamic programming algorithm is **O(n)**. 

For num`i` and `i-1` , it's only different for the low part in their binary format. For example, number 23(10111) and 24(11000), the high part `1`  is same, the another part `0111` and `1000` is different. We can get the result of `11000` by the result of  number `10000` (set the low part to zero).

solution: **result[i] = result[i & (i-1)] + 1.**

### [344.Reverse String](https://leetcode.com/problems/reverse-string/)

A simple problem about string. Just reverse a string.

