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

### [21.Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/?tab=Description)

把两个有序链表，合成一个有序链表。 更改指向就好了。

为了写法简单，可以初始化一个头指针，处理完返回它的.next

### [23.Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

把k个有序的链表合并为一个有序链表。暴力遍历不可行。有两种方法：

* 每次从k个链表头中取值最小的那个，这个过程可以建立一个堆来进行优化，每取一次复杂度O(log(k))。总复杂度O(m*log(k)),m是k个链表所有的节点数
* 采用merge sort的思想，分治来解决。每次合并两个有序链表。复杂度同上。

### [28.Implement strStr() #](https://leetcode.com/problems/implement-strstr/)

实现`strStr()`功能，返回一个串在另一个串第一次出现的位置。

笨方法，复杂度O(n*m)。KMP待补。

### [29.Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)

给定两个整数，求他们两个的整除结果。不能使用乘、除、取模。

解法明确，二分binary search。

要注意几个地方：1）`dividend`和`divisor`可能为负数。2）结果可能溢出32的整型，比如-2^31 / -1 = 2^31

可恶的是，python本来不要注意溢出，也要强行判断是否溢出32位有符号数。

C++最好转化为`long long`来做，因为进行二分的时候可能会相加溢出。

### [31.Next Permutation](https://leetcode.com/problems/next-permutation/)

找到一个排列的字典序下的下一个排列。如果已经是字典序上的最后一个排列，返回字典序最小的排列。

不用额外的空间。因为字典序，要从后往前考虑。从最后一位往前看，如果都是递增的，说明这一块是字典序较大的，还要往前找，找到一个不递增的，就是我们寻找next permutation的机会。

首先，从最后往前寻找，找到第一个递减的。例如，`51342`第一个递减的就是`4->3`。

然后，从这个递减的位置到最后一位中寻找到比递减位置数字大的最小的数字，和递减的位置进行交换。例如，`51342`递减的位置是第三位，数字`3`，后面数字`42`中比它大的最小的数字是`4`，进行交换，得到`51432`。

最后，对递减位置后面部分进行排序。例如，将上一步得到的`51432`，第三位后面的进行排序得到`23`。则结果为`51423`。

如果第一步找不到递减，则把这个排列进行排序。

### [36.Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)

判断数独是否是一个有效的（已知的是否有效）。判断3个就好。

### [37.Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)

让你补全一个数独，仅有一个解。

搜索，每一个空位的确定，影响到3个方向。我写的时候，找到一个解就直接返回，不过在中间少一个这个的判断，调试好久。

### [39.Combination Sum](https://leetcode.com/problems/combination-sum/)

给一个正整数的集合c，和目标值T。从c中取出数字，每个数字可以用多次，数字和为T,求这些组合。

直接搜索。

### [40.Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

和上一个类似，不过集合中每一个数字只能用一次。

还是搜索，只是每次不重复选择。

### [*41.First Missing Positive](https://leetcode.com/problems/first-missing-positive/)

输入一串整数，输出一个最小的不在其中出现的正整数。

输入中负数和大于输入长度的整数可以排除掉，不会影响结果。就在剩下的[1,length]中找到第一个没出现的就好。可以把它看成一种特殊的排序--桶排序。通过不断的把一个数字移动到它应该在的位置，检查第一个不在它应有位置的数字。

### [46.Permutations*](https://leetcode.com/problems/permutations/)

生成全排列，O(n!)。

递归来实现，第一位和他后面的分别进行交换，然后第二位和他后面的分别交换……这样依次得到的并不是字典序的。

### [47.Permutations II](https://leetcode.com/problems/permutations-ii/)

和上题类似，不过要求排列不重复。

通过例子，观察可知，如果重复出现，一定是在上题的步骤中，某一位和他后面的进行交换后，这位出现重复的数字。判断一下就解决了。

### [48.Rotate Image](https://leetcode.com/problems/rotate-image/)

给一个n*n的matrix，把它顺时针转一下。不借助额外的空间，找一下坐标对应就好。

### [49.Group Anagrams](https://leetcode.com/problems/anagrams/)

 给一些字符串，要求把只有字母顺序不同的字符串放在一起。

直接排序就好。

### [50.Pow(x, n)](https://leetcode.com/problems/powx-n/)

题目思路并不难,进行移位操作，复杂度O(log(n))。但是注意一下:

1.n可能是负数 。

2.n可能是-2^31.这种情况比较极端，在我们做法中，先进行转化为正数，然后对结果取倒数，再取反。在转化为正数的时候，就有问题，`n = -n`，得到的还是`-2^31`，无效。然后，进行右移的位操作`>>`，当int时负数的时候，右移的时候左面补的是符号位`1`，永远不可能为0，所以TLE。

解决办法就是转化为long long，就避免了这个极端情况出现的问题。

### [60.Permutation Sequence](https://leetcode.com/problems/permutation-sequence/)

给定n,k。求在1~n的全排列中字典序为k的排列是哪个。

可以通过[康拓展开](https://zh.wikipedia.org/zh/%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80)，它是一个双射，由一个排列到其字典顺序的一个双射，也是它的一个哈希函数。

### [69.Sqrt(x)](https://leetcode.com/problems/sqrtx/)

比较简单，实现`int sqrt(int x)`。

由于结果是一个整数，直接二分就好，复杂度O(log(x))。

### [75.Sort Colors](https://leetcode.com/problems/sort-colors/)

不要用STL中的sort，把含有`0 1 2`的串排序。

先统计一下分别的数量，然后写入。

### [77.Combinations](https://leetcode.com/problems/combinations/)

给n,k。从1...n里面取出k个，把不同的组合全部输出（c(k,n)个)。DFS一下就可以。

### [84.Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)*

直方图里面找最大的矩形块。比较直接的想法是，枚举每一小块，以它的高度为矩形的宽度，长度需要向左向右枚举，直接枚举的话，算法总复杂度是O(n^2)。可以设置l[],r[]，表示它向左可以多少，向右可以多少，减少重复计算。复杂度接近O(n)。

### [85.Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)*

给一个01矩阵，求里面只包含`1`的最大矩形块面积。

如果和上面这道题目结合，就没什么难度了。外面多循环一次。算法复杂度接近O(n^2)。

### [88.Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

给定两个有序的数列A,B，把两个和并成一个有序的数列，并且存放到A里面。

如果使用额外存储空间的话，很容易。不使用额外存储空间的话，可以倒序添加到A的末尾。

### [100.Same Tree](https://leetcode.com/problems/same-tree/)

判断两个二叉树是否完全一样。递归判断一下就可以了。

### [110.Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

判断一个二叉树是否是平衡二叉树。由底向上判断一下树的深度差小于1就好。

### [112.Path Sum I](https://leetcode.com/problems/path-sum/)

判断存在一个二叉树从根到底的和为给定值，遍历一下树就可以。

### [113.Path Sum II](https://leetcode.com/problems/path-sum-ii/)

在上一个的题意上，给出这个路径，思路一样。

### [135.Candy](https://leetcode.com/problems/candy/)

给N个小孩分糖吃，每个小孩有一个优先级。满足，每个小孩至少一个糖，如果这个小孩比旁边小孩的优先级高，那么他的糖的数量也要高。求最少给他们分多少个糖。（好抠）

考虑，如果是优先级升序，那么分的糖的数量也升序；如果优先级降序，那么分的糖是降序，不能出现1以下的数量。开始糖数，从左到右全部为1，如果优先级变高，那么比他左面人的糖数加一；同样从右向左搞一遍。然后每个人的糖数，是这两次处理的max。O(n)。

### [141.Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

对于一个链表，判断是否有环，最好不要用额外的空间。

泪目，当初面过某家的实习，被问到过，本来挺简单，后来问不要用额外的空间，怎么弄。当时有点懵。

设置两个指针，开始都指向头，一个指针一次跳一步，另一个一次跳两步。如果两个指针在不到达末尾之前可以相遇，那么有环。

### [*142.Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

和上到题目一样，要求出环的起始点。

在上一题的基础上，一个比较直观的想法是：先求出环的长度k，从链表的头开始向后找，如果这个当前这个节点向后k个节点是自己，这个点就是环的起始点。但是这样复杂度是O(n^2)，写了一下竟然A了，812ms，看了一下有比较快的算法，那么最优的算法估计复杂度还是O(n)。

假设起点是`X`，环的起点是`Y`，上个题目做法中第一次相遇的点是`Z`，`X`到`Y`的距离是a，`Y`到`Z`的距离是b，`Z`到`Y`的距离是c，环的长度为L=b+c。

那么，`2*(a+b) = a+n*L+b, n>=1`，即慢指针走过的距离的2倍等于快指针走过的距离。得到`a+b = n*L, n>=1`。

观察这个式子发现`a = n*L-b = (n-1)*L+c, n>=1`,即a的距离等于c的距离加上n-1倍的环的长度。那么，可以想到，设置两个指针，一个在起点`X`，一个在相遇点`Z`，两个指针每次都走一步，那么现在的相遇点就是环的起点`Y`了。这个算法复杂度O(n)。

### [148.Sort List*](https://leetcode.com/problems/sort-list/?tab=Description)

对于一个无序的链表，在O(log(n))的复杂度内对其排序，要求常数的空间复杂度。

采用归并排序的思想，分治来解决。(可以使用快慢指针来找出中间位置)

### [151.Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)

以词为单位翻转字符串。直接做就好喽，具体看代码。

### [162.Find Peak Element](https://leetcode.com/problems/find-peak-element/)

给定一个数列num[1~n] 假定`num[0] = num[n+1] = -INF`，求peak值的索引，peak值就是大于左右两个相邻的值。由于num[0], num[n+1]都是负无穷大，所以一定优解，要求O(log(n))的复杂度，可以进行二分。当二分到某个值，比较它的左右值，如果是peak，则找到任一解；如果是上升的，继续二分右区间；否则二分左区间。这样可以一定得到任一解。

### [165.Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/)

给两个版本号，比较那个版本高。

注意，`0.01 == 0.1`, `0.1.0 == 0.1`。

### [172.Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/)

给定整数n，问n!末尾有多少个0 。

老问题了，就是看n!中因子5和2的个数，5的个数少于2，所以看5的个数就好了。一个5因子可以产生一个末尾0,25可以产生两个，125产生3个。。。

### [191.Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

求32-bit integer中写成二进制`1`的个数。从末尾依次找即可，O(log(n)) 解决。

### [200.Number of Islands](https://leetcode.com/problems/number-of-islands/)

输入01矩阵，问有多少块连通。没啥可说的，DFS直接搞。

### [216.Combination Sum III](https://leetcode.com/problems/combination-sum-iii/)

和39,40类似。要求从[1,9]之间找出不重复的k个数之和等于n。还是直接搜索DFS

### [224.Basic Calculator](https://leetcode.com/problems/basic-calculator/)

给一个包含非负数、`+`、`-`、`(`、`)`和空格的字符串，求出它的值。

利用栈，依次入栈，遇到`)`的时候，依次出栈并计算，直到遇到`(`，并把计算的值入栈。最后对栈上的内容进行计算。

复杂度O(n)。

### [225.Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)

让你使用queue的相关操作，实现stack。

push、empty没啥可说的。pop()操作应该在queue上去队前的元素放到队后，最后一个元素只取出来。top()类似。

python中的queue使用`from collections import deque`。

### [227.Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/)

给一个包含非负数、`+`、`-`、`*`、`/`和空格的字符串，要求求出它的值，输入一定是合法的。

不用像224用栈来做了，只需要遇到加减，把之前的值全部处理完，遇到乘除把之前乘除块的值处理完。

O(n)。

### [231.Power of Two](https://leetcode.com/problems/power-of-two/)

判断一个数是否是2的幂。方法很多，随便一种就好。

### [232.Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)

使用Stack中的操作，来实现Queue。

和225类似，对于pop()和peek()需要借助两个queue倒腾一下。

### [233.Number of Digit One](https://leetcode.com/problems/number-of-digit-one/)

给一个n，求[1,n]中所有数字含有`1`的数量。题目一看，有点数位DP的意思。

把这个问题分解成，求[1,n]中只含有1个`1`的数字的个数、只含有两个`1`的数字的个数，……，只含有len(n)个`1`的数字的个数。

这些子问题，分别用动态规划来解，dp(i,j)表示不达到最大值`n`边界的情况下，在第i位（从高位算起），在状态为j的情况下数字的个数。假设求区间内包含k个`1`的数字个数，j就取得0~k，表示从第i位到最后一位包含`1`的个数为j。状态转移见代码吧，不好描述。

可以用记忆化搜索来实现。如果在边界，就不能用到已有的dp(i,j)的值。如果输入足够大，结果会溢出，但是OJ并没有这样的数据。

好久没写这样的题目，竟然1A，感动。

### [235.Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

在一个二叉查找树上找某两个节点的LCA，直接按照大小直接搜一下就好。复杂度大约是树的深度。

### [236.Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) *

在一个二叉树上找某两个节点的LCA。可以搜一遍，假设n个节点，复杂度O(n)。


### [237.Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)

删除链表中的一个节点（不是尾节点），不过只给出这个节点的访问。

我们可以把下一个节点的值复制到该节点，然后删除下一个节点。

### [242.Valid Anagram](https://leetcode.com/problems/valid-anagram/)

判断两个字符串是否包含的字母只是顺序不同。直接判断就好。

### [257.Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)

输出一个二叉树从根到叶子的所有路径。

直接递归搜索一下就好了。

### [282.Expression Add Operators](https://leetcode.com/problems/expression-add-operators/)

给一个只含有数字的字符串和一个目标整数值，可以往数字串里面添加`+`,`-`,`*`,来使得计算值等于目标整数值。

注意不能有前导0.

暴力枚举字符串每个间隔位的符号，+-*或者什么没有，然后计算。然而TLE。

看到有人用搜索，递归来写。

写了一发，就过了。amazing。

### [289.Summary Ranges](https://leetcode.com/problems/summary-ranges/)

给一个有序的整数串，要求返回它的各个整数区间，单个值返回自己，不返回区间。例如`[0,1,2,4,5,7]`,返回 `["0->2","4->5","7"].`

依次判断一下就好了，复杂度O(n).

### [326.Power of Three](https://leetcode.com/problems/power-of-three/) *

不用递归、循环判断一个数n是否是3的幂。

找到一个不超过2^31-1的最大的3^n，如果这个3^n mod n是否为0。

### [335.Self Crossing](https://leetcode.com/problems/self-crossing/) *

给一个整数串，依次代表一个点分别向上、向左、向下、向右……走的距离。问是否会出现交叉。

就是依次进行顺时针移动。可以发现，每个方向的时候，只有3中不同的相交情况。

1)第j条线撞到第j-3条线 。 2)第j条线追尾第j-4条线。 3)第j条线撞到第j-5条线。

细心判断下就好。

### [338. Counting Bits](https://leetcode.com/problems/counting-bits/)

It's easy to solve this problem by O(n*log(n)) algorithm. 

But we can make use of what we have produced already. The time complexity of this dynamic programming algorithm is **O(n)**. 

For num`i` and `i-1` , it's only different for the low part in their binary format. For example, number 23(10111) and 24(11000), the high part `1`  is same, the another part `0111` and `1000` is different. We can get the result of `11000` by the result of  number `10000` (set the low part to zero).

solution: **result[i] = result[i & (i-1)] + 1.**

### [342.Power of Four](https://leetcode.com/problems/power-of-four/)

判断一个整数n，是否是4的幂。不适用循环和递归。

那就用对数来判断，log4(n)是否是整数，注意浮点数0的判断。

### [343.Integer Break](https://leetcode.com/problems/integer-break/)

给一个数n，它可以写成k个数的和(k>1)，现在求这k个数乘积最大是多少。

假设，k是固定的，那么n分成尽可能均匀的k份是最优的，能得到最大的乘积。这时，乘积最大的方案唯一。

题目说n最大58，遍历k的长度就可以，复杂度O(n)。

还可以发现随着k从2开始增大到n，这个最优乘积先增大后减小。所以可以用三分进行找最优解，复杂度为$$O(log_3n)$$。

### [344.Reverse String](https://leetcode.com/problems/reverse-string/)

A simple problem about string. Just reverse a string.

### [345.Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/)

给一个字符串，把里面的元音字母在原来的串中倒序。

第一次遍历，取出其中的元音字母，把这些元音字母倒序。第二次遍历，对于依次遇到的元音字母用第一次取出的原因字母替换。

### [350.Intersection of Two Array II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

给两个整数数组，返回在两个中都出现的元素，如果有重复也要返回重复。

分别给两个数组排序，然后对两个数组从小到大依次判断是否重复。复杂度O(n\*log(n) + m\*log(m))。

其实，如果n或者m很大，可以采用O(n*m)的方法。 

### [367.Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/)

判断一个数是否是完全平方数。

和[69.Sqrt(x)](https://leetcode.com/problems/sqrtx/) 类似。二分，复杂度O(log(n))。

### [377.Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/?tab=Description)

给一个正整数集合，eg，`nums = [1, 2, 3]`，给一个目标值,eg,`target = 4`。

取nums里面一些数，其和为target。可以重复取，顺序不同算作不同的序列。求这些不同序列的个数。

动态规划，dp[i]表示用nums里面的数字，组成i大小的序列数。for num in nums : dp[i] =dp[i] + dp[i-num] 

如果按照背包的那种状态转移方式，得到的是不考虑次序的序列个数。

### [349.Intersection Of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)

给两个整数串，返回其中重复出现的整数，不要求有序，而且返回的整数中必须唯一。

把两个整数串分别放入两个set中，两个set取并。

### [372.Super Pow](https://leetcode.com/problems/super-pow/)

求a^b,不过b可能非常的大，所以它以vector(c++)、list(python)为参数。

原本可以O(log(b))的复杂度解决的，现在由于这种参数形式，我们二进制的思路解法转化为十进制的解法，复杂度也就变成了O(log_10(b))。

如果用C++写，注意取模，不要溢出。

### [389.Find the Difference](https://leetcode.com/problems/find-the-difference/)

找一个串比另一个串多出来的字母。随便做。

### [441.Arranging Coins](https://leetcode.com/problems/arranging-coins/)

O(1)就可以。

### [474.Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/)

给出许多只含有`0`,`1`的串，求当0和1的个数分别为m,n的情况下，能组成多少个串。

简单背包，DP。只是重量变成了二维，价值为1。