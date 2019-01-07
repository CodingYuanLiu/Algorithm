## 多项式求值
### Horner 规则
Horner:

输入：n+2个实数a0,a1,a2...an和x的序列

输出：Pn(x) = an*x^n + a(n-1) * x ^ (n-1)...
```
p = an
for j = n-1 to 0
    p = p*x + aj
end for
return p
```