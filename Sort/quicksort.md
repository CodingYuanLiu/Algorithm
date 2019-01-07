## QuickSort

### 伪代码
```
Split(A,low,high):

x = A[low], i = low,
for j = low + 1 to n
    if A[j] < low then i+=1
    end if
    if i!=j then 交换A[i],A[j]
    end if  
交换 A[low],A[i]
return A,i
```
```
QuickSort(A,low,high):

if low<high then
    w = Split(A,low,high)
    QuickSort(A,low,w-1)
    QuickSort(A,w+1,high)
end if
```
用非递归：
```
QuickSort(A,n):

stack<int> st;
st.push(1)
st.push(n)
while st非空
    high = st.pop
    low = st.pop
    if high < low then continue
    w = Split(A,low,high)
    st.push(low)
    st.push(w-1)
    st.push(w+1)
    st.push(high)

