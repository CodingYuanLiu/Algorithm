## 最大公共子序列
### 观察结论:
对于a1a2a3...ai和b1b2...bj两个序列而言：
* if ai = bj, L(i,j) = L(i-1,j-1) + 1
* if ai != bj, L(i,j) = max{L(i,j-1),L(i-1,j)}
* if i = 0 or j = 0, L(i,j) = 0

### 算法 LCS
* 输入：两个字符串A,B，长度分别为n，m
* 输出：A、B的最长公共子序列的长度
```
for i = 1 to n
    L[i,0] = 0
end for
for i = 1 to m
    L[0,j] = 0
end for
for i = 1 to n
    for j = 1 to m
        if ai = aj then L[i,j] = L[i-1,j-1]+1
        else L[i,j] = max{L[i-1,j],L[i,j-1]}
        end if
    end for
end for
return L[n,m]
```
### 时间复杂度
时间复杂度和空间复杂度均为O(nm)。其中，空间复杂度可以简化至O(min{n,m})