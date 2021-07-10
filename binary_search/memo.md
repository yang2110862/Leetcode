**153 灵活的运用二分

思考：
question1 ：若 right = mid 是否会陷入死循环
具体问题具体分析，没有固定模板 

question2 ：当含有两个元素时，mid总是取左边的元素***，所有如果right = mid的话，除非元素只剩下一个，不然不会陷入死循环而使区间不变
但如果left = mid，当只有两个元素使，可以会陷入死循环导致一直包含两个元素

question3:在一个数组vec中，如果要使(left + right) >> 1可以取到数组最右边的值， right的起始位置应该是vec.len() - 1
递增序列中
1、找第一个大于等于val的元素  lower_bound(beg, end, val)  lower_bound(beg, end, val, cmp)
2、找第一个大于val的元素  upper_bound(beg, end, val) upper_bound(beg, end, val, cmp)