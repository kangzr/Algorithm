#### 动态规划(Dynamic Programming)

动态规划是一种在数学、管理科学、计算机科学、经济学和生物信息学中使用的，通过把原问题分解为相对简单的子问题的方式求解复杂问题的方法。

动态规划常常适用于有重叠子问题和最优子结构性质的问题，动态规划方法所耗时间往往远少于朴素解法.

动态规划背后的基本思想非常简单。大致上，若要解一个给定问题，我们需要解其不同部分（即子问题），再根据子问题的解以得出原问题的解。
即整体最优解依赖各子问题最优解, 子问题可能重复，因此可采用自下而上的方法求解(自上而下分析), 一般把子问题解存起来


*解题步骤*

1. 寻找状态方程