## Select
* 输入：n个元素的数组A[1...n]和整数k，1 <= k <= n
* 输出：A中的第k个元素
    
    select(A,1,n,k)
* procedure:
select(A,low,high,k)
```
p <- high - low + 1
if p<44 then 将A排序并输出A[k]

令 q = p/5。将A分为q组，每组5个元素。若5不整除p，则排除剩余元素。
将 q 组中的每一组元素单独排序，取出中项，所有中项的集合为M。
mm <- select(M,1,q,q/2向上取) 
comment:mm为中项的中项 
将A[low...high]分成三组：
A1 = {a | a < mm}
A2 = {a | a = mm}
A3 = {a | a > mm}
case:
 |A1| >= k return select(A1,1,|A1|,k)
 |A1| + |A2| = k return mm
 |A1| + |A2| < k return select(A3,1,|A3|,k-|A1|-|A2|)
```
### 时间复杂度：
首先求|A1|,|A3|的规模.（画书上那个图）
可知|A1|(或|A3|) <= 0.7n + 1.2
希望用0.7n的整数倍来表示|A1|大小的上界:
0.7n + 1.2 <= 0.75n ===>  n >= 44
T(n) = T(n/5) + T(0.75n) + cn
因为n/5 + 0.75n < n 故T(n) = O(n)
