builtin:
__builtin_popcount(x)  计算x二进制中含1的个数


字符串：
tolower(ch) 
toupper(ch)
isalnum(ch)        
string b(s.rbegin(), s.rend())  
stol(s)
atoi(c)
to_string(n)

最小值和最大值
*max_element(beg, end) *min_element(beg, end)


二分
递增序列中
1、找第一个大于等于val的元素  lower_bound(beg, end, val)  lower_bound(beg, end, val, cmp)
2、找第一个大于val的元素  upper_bound(beg, end, val) upper_bound(beg, end, val, cmp)