 <!-- 滑动窗口模板 -->
left,right = 0, (0 or 1)
ret = total = 0
while right < len(nums):
   更新total值
   while 窗口内数据不满足要求
      1. 更新total值
      2. 收缩左边界
   更新ret最大值
返回 ret