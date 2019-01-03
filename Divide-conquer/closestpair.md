## 最近点对问题
* 用暴力枚举法解决这个问题需要O(n^2)复杂度。故考虑用分治降低复杂度。
* 先将点集按照坐标排序，分成两个集合Sl和Sr。之后，求出Sl，Sr中的最近点距dl，dr。令d = min{dl,dr}，那么，仅需求出Sl，Sr中互相之间的点距dp，如果dp < d 则最近点距为dp，否则为d。
* 现在的关键是求dp，暴力找dp同样需要O(n^2)的复杂度，需要用巧方法
* 要得到dp < d ，那么要求的点一定在距离dl，dr分割线d以内的区域。具体下来，由于两点的水平距离和垂直距离都不能大于d，故一定在长为2d，宽为d的矩形区域内。
* 由于d = min{dl,dr}，故由鸽巢原理，2d * d的矩形区域内最多有8个点。
* 因此，点集中的每个点最多需要和7个点进行比较即可。但是，为了找到这是哪7个点，我们还要对y坐标进行排序，与y坐标增序下的7个点比较。

### 时间复杂度
* 时间复杂度为，排序所花时间（找那7个点），求子集合之间的最短距离的时间，分别求子集合的最近点的时间。三项加起来为：
```
T(n) = O(nlogn) + 2T(n/2) + O(n)
     = 2T(n/2) + O(nlogn) (n>3)
```
这样得到T(n) = O(n*(logn)^2),这不是我们想要的结果。
* 如果能够提前对y坐标排好序，并用数组储存，那么就不需要每次分治都排序了。
```
T(n) = 2T(n/2) + O(n) (n>3)
```
得到T(n) = O(nlogn)

### 算法
```
以x坐标增序对S中的点排序
Y <- 以y增序对S中的点排序
d <- cp(1,n)
```
过程：
```
cp(low,high):
if high-low+1 <= 3 then 直接计算d
else
    mid = (low + high)/2
    dl = cp(low,mid)
    dr = cp(mid+1,high)
    d = min{dl,dr}
    k = 0
    x0 = x(S[mid]) //x0是中点的坐标，相当于中间那条竖线
    //接下来从全点集S中抽取子点集T，
    //该子点集位于两条距中心线为d的虚线之间
    for i = 1 to n
        if |x(Y[i]) - x0| <= d then
            k = k + 1
            T[k] = Y[i]
        end if
    end for //此时k是子点集的大小.
    dp = 2*d //初始化dp为2d
    \\求dp
    for i = 1 to k-1
        for j = i+1 to min{i+7,k}
            if d(T[i],T[j]) < dp then
                dp = d(T[i],T[j])
        end for
    end for
    d = min{d,dp}
end if
return d