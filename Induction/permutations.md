## 生成排列
两种算法如下
### Permutations1

```
Permutations1:
for i = 1 to n
    A[i] = i
end for
    perm1(1)
```
```
Perm1(m):
    if m = n
        then 输出A[1...n]//错点！
        exit
    end if
    for i = m to n // 错点！m 不是 m+1
        交换A[i],A[m]
        perm(i+1)
        交换A[i],A[m]
    end for
```

### Permutations2
递归顺序可以从m到0也可从1到m+1.这里根据书上的来，从m到0
```
Permutations2:
for i = 1 to n
    A[i] = 0
end for
perm2(n)
```
```
Perm2(m):
if m = 0 then
    print(A[1...n])
    exit
end if
end if
for i = 1 to n
    if A[i] = 0 then
        A[i] = m
        Perm2(m-1)
        A[i] = 0
    end if
end for
```