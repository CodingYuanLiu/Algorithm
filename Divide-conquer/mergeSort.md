## MergeSort
### mergesort(A,low,high):
* Input: Array with n elements A[12...n]
* Output: A[12...n] in ascending order.
```
if low < high then
    mid <- (low+high)/2
    mergeSort(A,low,mid)
    mergeSort(A,mid+1,high)
    MERGE(A,low,mid,high)
end if
```

### MERGE(A,low,mid,high):
* input: Array and its 3 index low, mid, high. A[low...mid] and A[mid+1...high] are in ascending order.
```
comment: B[low...high] is a supporting array.
s=low,t=mid+1,k=low
while s < mid and t < high
    if A[s]<=A[t] then
        B[k]=A[s]
        s <- s+1
    else
        B[k]=B[t]
        t <- t+1
    end if
    k <- k+1
if s = mid + 1 then 
    B[k...high] <- A[t...high]
else
    B[k...high] <- A[s...high]
end if
A[low...high] <- B[low...high]
```