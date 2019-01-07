## 寻找多数元素

### 伪代码
Majority

输入：n个元素的数组A[1...n]

输出：存在多数元素则输出，否则输出none
```
c = candidate(1)
count = 0
for i = i to n
    if A[i] = c
    then count++;
    end if
end for
if count > n/2 then return c
else return none
end if
```

``` 
candidate(m):
j = m
c = A[m]
count = 1
while j < n && count > 0
    j = j+1
    if A[j] = c then count++
    else count--
    end if
end while
if j = n then return c //错点！
else return candidate(j+1)
```