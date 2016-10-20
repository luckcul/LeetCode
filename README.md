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

### [15.3sum](https://leetcode.com/problems/3sum/)

给定n个整数，求其中3数a,b,c。使得a+b+c = 0。返回虽有不重复的三元组。

先排序，然后枚举第一个元素。在剩余的区间上，从两端向中间逼近。复杂度O(n^2)。

注意不要重复。

### [16.3Sum Closest](https://leetcode.com/problems/3sum-closest/)

给定n个整数，找到其中3个数的和与给定的target最接近。返回这个最接近的和，题目假设只有一个最优的结果。

和之前的`3sum`系列类似。枚举第一个元素，在剩余区间，从两端到中间逼近，记录最接近的值。复杂度O(n^2)。

### [18.4sum](https://leetcode.com/problems/4sum/)

给定一个包含n个整数的数组和目标target。要求找到一个唯一的四元组(a,b,c,d)，使得a+b+c+d = target。

先排序，枚举前两个元素，然后对于后两个值，从剩余的区间的两端向中间逼近。复杂度O(n^3)。

注意四元组是唯一的，不要出现重复。

### [50.Pow(x, n)](https://leetcode.com/problems/powx-n/)

题目思路并不难,进行移位操作，复杂度O(log(n))。但是注意一下，

1.n可能是负数。

2.n可能是-2^31.这种情况比较极端，在我们做法中，先进行转化为正数，然后对结果取倒数，再取反。在转化为正数的时候，就有问题，`n = -n`，得到的还是`-2^31`，无效。然后，进行右移的位操作`>>`，当int时负数的时候，右移的时候左面补的是符号位`1`，永远不可能为0，所以TLE。

解决办法就是转化为long long，就避免了这个极端情况出现的问题。

### [191.Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

求32-bit integer中写成二进制`1`的个数。从末尾依次找即可，O(log(n)) 解决。

### [338. Counting Bits](https://leetcode.com/problems/counting-bits/)

It's easy to solve this problem by O(n*log(n)) algorithm. 

But we can make use of what we have produced already. The time complexity of this dynamic programming algorithm is **O(n)**. 

For num`i` and `i-1` , it's only different for the low part in their binary format. For example, number 23(10111) and 24(11000), the high part `1`  is same, the another part `0111` and `1000` is different. We can get the result of `11000` by the result of  number `10000` (set the low part to zero).

solution: **result[i] = result[i & (i-1)] + 1.**

### [344.Reverse String](https://leetcode.com/problems/reverse-string/)

A simple problem about string. Just reverse a string.

### [372.Super Pow](https://leetcode.com/problems/super-pow/)

求a^b,不过b可能非常的大，所以它以vector(c++)、list(python)为参数。

原本可以O(log(b))的复杂度解决的，现在由于这种参数形式，我们二进制的思路解法转化为十进制的解法，复杂度也就变成了O(log_10(b))。

如果用C++写，注意取模，不要溢出。