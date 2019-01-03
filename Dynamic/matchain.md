## 矩阵链相乘
### 观察结论
* Mi的列数一定等于M(i+1)的行数，所以制定每个矩阵的行数和最右面矩阵Mn的列数就够了。它们分别是r1，r2，...，rn，r(n+1)

* 设MiM(i+1)...Mj为一串矩阵链，k为i、j间的一个索引，那么Mi,j = Mi,(k-1) Mk,j, 即先计算两个矩阵乘法，再把两个矩阵乘起来即可。k的划分点不同，导致矩阵乘法的乘法次数不同。
* 因此，从i到j遍历k，找到最小的乘法次数。
* C[i,j] = min(C[i,k-1]+C[k,j] + ri * rk * rj).k>i && k<=j

### 算法
MATCHAIN
* 输入：n个矩阵的维数r1，r2，...，rn，r(n+1)，出最后一项是Mn的列数外，其余的ri即为Mi的行数。
* 输出：相乘的最小次数。
```
for i = 1 to n
    C[i,i] = 0
end for

//填表的时候，按照对角线来填。
for d = 1 to n-1
    for i = 1 to n - d
        j = i+d
        C[i,j] = MAX
        //由递推公式开始填表
        for k = i+1 to j
            if C[i,j] > C[i,k-1] + C[k,j] + ri * rj * rk
            then C[i,j] = C[i,k-1] + C[k,j] + ri * rj * rk
        end for
    end for
end for
return C[1,n]
```
