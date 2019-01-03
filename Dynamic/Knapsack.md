## 背包问题
### 观察结论
令V[i, j]表示从前i项{u1,u2...ui}装进剩余体积为j的背包的最大价值，每件物品的体积为si，价值为vi
* V[i, j] = V[i-1, j] si < j
* V[i, j] = max{ V[i-1, j],V[i-1, j-si] + vi }

### 算法
输入：物品集合 U = { u1,u2,...,ui },其体积分别为si，价值为vi
输出：背包装下的最大价值
```
for i = 0 to n
    V[0, i] = 0
end for
for j = 0 to C
    V[0, j] = 0
end for
for i = 1 to n
    for j = 1 to C
        V[i, j] = V[i-1,j]
        if si < j then
            V[i,j] = max{ V[i, j], V[i-1, j-si] + vi}
        end if
    end for
end for
return V[n,C]
```
### 复杂度
该算法能够在O(nC)的时间以及O(C)的空间得到。认为该算法是伪多项式时间算法。