## Heap

### Sift-up
Sift-up
输入：数组H[1...n]及中间索引i
输出：上移H[i]，使得它不大于父节点
```
Sift-up
done = false
while !done && i>1
    if H[i] > H[i/2] 
    then 交换H[i],H[i/2]
    else
        done = true
    end if
    i = i/2
end while
```
### Sift-down
```
Sift-down:
done = false
while 2i<=n && !done
    i = 2i
    if i+1 < n && i+1 > i then i = i+1
    if H[i] > H[i/2] then 交换H[i],H[i/2]
    else
        done = true
    end if
end while
```
### Makeheap
从最小的非叶子节点开始，到根节点，逐渐规整子树。
```
Makeheap:
for i = n/2 to 1
    Sift-down(H,i)
end for
```
O(nlogn)
### Heapsort
每次把最大的元素放在后面,然后减少堆的大小
```
HeapSort:
Makeheap(A,n);
for i = n down to 2 //错点！
    swap(A[1],A[i])
    Sift-down(A[1...i-1],1)
```