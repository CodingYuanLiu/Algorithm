## 并查集
### Data Structure
每个节点包含如下属性：rank，父节点指针，整个数据结构成树形。
### Find
输入：节点x

输出：root(x),及包含x的树的根
```
Find:
y = x
while(p(y) != null)
    y = p(y)
end while
root = y 
y = x
while(p(y) != null) //终止条件要注意防止segmentation fault
    w = p(y)
    p(y) = root
    y = w;
end while
return root;
```

### Union
输入：两个元素x和y

输出：包含x和y的两个树的合并，原来的树被破坏
```
Union:
if rank(x) > rank(y) then
    p(y) = x
else
    p(x) = y
    if rank(x) == rank(y) then
    rank(y) += 1
end if
```