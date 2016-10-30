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

### [29.Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)

给定两个整数，求他们两个的整除结果。不能使用乘、除、取模。

解法明确，二分binary search。

要注意几个地方：1）`dividend`和`divisor`可能为负数。2）结果可能溢出32的整型，比如-2^31 / -1 = 2^31

可恶的是，python本来不要注意溢出，也要强行判断是否溢出32位有符号数。

C++最好转化为`long long`来做，因为进行二分的时候可能会相加溢出。

### [*41.First Missing Positive](https://leetcode.com/problems/first-missing-positive/)

输入一串整数，输出一个最小的不在其中出现的正整数。

输入中负数和大于输入长度的整数可以排除掉，不会影响结果。就在剩下的[1,length]中找到第一个没出现的就好。可以把它看成一种特殊的排序--桶排序。通过不断的把一个数字移动到它应该在的位置，检查第一个不在它应有位置的数字。

### [50.Pow(x, n)](https://leetcode.com/problems/powx-n/)

题目思路并不难,进行移位操作，复杂度O(log(n))。但是注意一下:

1.n可能是负数。

2.n可能是-2^31.这种情况比较极端，在我们做法中，先进行转化为正数，然后对结果取倒数，再取反。在转化为正数的时候，就有问题，`n = -n`，得到的还是`-2^31`，无效。然后，进行右移的位操作`>>`，当int时负数的时候，右移的时候左面补的是符号位`1`，永远不可能为0，所以TLE。

解决办法就是转化为long long，就避免了这个极端情况出现的问题。

### [60.Permutation Sequence](https://leetcode.com/problems/permutation-sequence/)

给定n,k。求在1~n的全排列中字典序为k的排列是哪个。

可以通过[康拓展开](https://zh.wikipedia.org/zh/%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80)，它是一个双射，由一个排列到其字典顺序的一个双射，也是它的一个哈希函数。

### [69.Sqrt(x)](https://leetcode.com/problems/sqrtx/)

比较简单，实现`int sqrt(int x)`。

由于结果是一个整数，直接二分就好，复杂度O(log(x))。

### [191.Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

求32-bit integer中写成二进制`1`的个数。从末尾依次找即可，O(log(n)) 解决。

### [233.Number of Digit One](https://leetcode.com/problems/number-of-digit-one/)

给一个n，求[1,n]中所有数字含有`1`的数量。题目一看，有点数位DP的意思。

把这个问题分解成，求[1,n]中只含有1个`1`的数字的个数、只含有两个`1`的数字的个数，……，只含有len(n)个`1`的数字的个数。

这些子问题，分别用动态规划来解，dp(i,j)表示不达到最大值`n`边界的情况下，在第i位（从高位算起），在状态为j的情况下数字的个数。假设求区间内包含k个`1`的数字个数，j就取得0~k，表示从第i位到最后一位包含`1`的个数为j。状态转移见代码吧，不好描述。

可以用记忆化搜索来实现。如果在边界，就不能用到已有的dp(i,j)的值。如果输入足够大，结果会溢出，但是OJ并没有这样的数据。

好久没写这样的题目，竟然1A，感动。

### [338. Counting Bits](https://leetcode.com/problems/counting-bits/)

It's easy to solve this problem by O(n*log(n)) algorithm. 

But we can make use of what we have produced already. The time complexity of this dynamic programming algorithm is **O(n)**. 

For num`i` and `i-1` , it's only different for the low part in their binary format. For example, number 23(10111) and 24(11000), the high part `1`  is same, the another part `0111` and `1000` is different. We can get the result of `11000` by the result of  number `10000` (set the low part to zero).

solution: **result[i] = result[i & (i-1)] + 1.**

### [344.Reverse String](https://leetcode.com/problems/reverse-string/)

A simple problem about string. Just reverse a string.

### [367.Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/)

判断一个数是否是完全平方数。

和[69.Sqrt(x)](https://leetcode.com/problems/sqrtx/) 类似。二分，复杂度O(log(n))。

### [372.Super Pow](https://leetcode.com/problems/super-pow/)

求a^b,不过b可能非常的大，所以它以vector(c++)、list(python)为参数。

原本可以O(log(b))的复杂度解决的，现在由于这种参数形式，我们二进制的思路解法转化为十进制的解法，复杂度也就变成了O(log_10(b))。

如果用C++写，注意取模，不要溢出。