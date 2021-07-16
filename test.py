import bisect
arr = [3,3,5,6]
beg = bisect.bisect_left(arr, 3)
print(beg)