## Exp
### 一般算法
power(x,m):
```
    if m = 0 then
        return 1
    end if
    result = power(x,m/2)
    result = result * result
    if m is odd then
        result = result * x
    end if
    return result
```

### 利用二进制的算法
```
y = 1
将n用二进制数dk...d1d0表示
for j = k down to 0
    y = y^2
    if dj = 1 then
        y = x*y
    end if
end for
return y
```