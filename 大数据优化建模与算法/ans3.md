## 梯度下降与牛顿迭代

### 问题描述

&emsp;&emsp;对函数$f(x) = \sum_{i=1}^{5} \left[ (1 - x_i)^2 + 100(x_{i+1} - x_i^2)^2 \right]$，初始点取为$x_0 = (0,0, \ldots, 0) \in \mathbb{R}^6$，分别用最速下降法和牛顿编程迭代10次，结果记录：


| 迭代次数$k$ | 最速下降法 | 牛顿法 |
| --- | --- | --- |
| 1 | 5.288480 | 106.099596 |
| 2 | 4.913402 | 70.481665 |
| 3 | 5.251538 | 31.273002 |
| 4 | 4.834204 | 6.786548 |
| 5 | 5.229902 | 1.474542 |
| 6 | 4.763847 | 2.223019 |
| 7 | 5.225366 | 2.650898 |
| 8 | 4.704232 | 3.274205 |
| 9 | 5.241785 | 3.569193 |
| 10 | 4.660017 | 3.966048 |
|10 次迭代两个方法
所花时间|1.021毫秒|1.093毫秒|


### 运行结果分析

#### 1. 迭代过程中的函数值变化
- **最速下降法**:
  - 在前几次迭代中，函数值有较大的下降，从初始值5.288480下降到第4次迭代的4.834204。
  - 从第5次迭代开始，函数值的变化逐渐减小，最终在第10次迭代时达到4.660017。
  - 整体来看，最速下降法的收敛速度较慢，但相对稳定。

- **牛顿法**:
  - 在前几次迭代中，函数值有非常大的下降，从初始值106.099596下降到第4次迭代的6.786548。
  - 从第5次迭代开始，函数值的变化逐渐减小，最终在第10次迭代时达到3.966048。
  - 整体来看，牛顿法的收敛速度非常快，尤其是在前几次迭代中。

#### 2. 收敛速度
- **最速下降法**:
  - 收敛速度相对较慢，但在多次迭代后仍然能够逐步接近最优解。
  - 适合于函数较为平滑且梯度方向较为明确的情况。

- **牛顿法**:
  - 收敛速度非常快，尤其是在前几次迭代中。
  - 适合于函数具有较好的二阶导数性质的情况，能够快速找到最优解。
  - 但由于牛顿法需要计算和求解Hessian矩阵，计算复杂度较高，可能在高维问题中效率较低。

#### 3. 计算时间
- **最速下降法**:
  - 10次迭代耗时1.021毫秒。
  - 计算简单，每次迭代只需计算梯度，因此计算时间较短。

- **牛顿法**:
  - 10次迭代耗时1.093毫秒。
  - 尽管收敛速度更快，但由于需要计算和求解Hessian矩阵，每次迭代的计算时间较长，总体耗时略高于最速下降法。

#### 4. 总结
- **最速下降法**:
  - 适用于对计算时间要求较高且函数较为平滑的情况。
  - 收敛速度较慢，但计算简单，适合大规模问题。

- **牛顿法**:
  - 适用于对收敛速度要求较高且函数具有较好二阶导数性质的情况。
  - 收敛速度快，但计算复杂度较高，适合中低维度的问题。

通过对比可以看出，牛顿法在前几次迭代中表现出色，能够快速降低函数值，但随着迭代次数增加，其优势逐渐减弱。而最速下降法虽然收敛速度较慢，但计算简单，适合对计算时间敏感的应用场景。

### 源代码
```python
import numpy as np
import time

def f(x):
    """
    计算函数f的值。

    参数:
    x -- 输入向量

    返回:
    f(x)的计算结果
    """
    return sum((1 - x[i])**2 + 100 * (x[i+1] - x[i]**2)**2 for i in range(5))

def gradient_f(x):
    """
    计算函数f的梯度。

    参数:
    x -- 输入向量

    返回:
    f(x)的梯度向量
    """
    grad = np.zeros_like(x)
    grad[0] = -2 * (1 - x[0]) - 400 * (x[1] - x[0]**2) * x[0]
    for i in range(1, 5):
        grad[i] = 2 * (1 - x[i]) - 400 * (x[i+1] - x[i]**2) * x[i] + 200 * (x[i] - x[i-1]**2)
    grad[5] = 200 * (x[5] - x[4]**2)
    return grad

def hessian_f(x):
    """
    计算函数f的Hessian矩阵。

    参数:
    x -- 输入向量

    返回:
    f(x)的Hessian矩阵
    """
    n = len(x)
    H = np.zeros((n, n))
    H[0, 0] = 2 - 400 * (x[1] - 3 * x[0]**2)
    H[0, 1] = H[1, 0] = -400 * x[0]
    for i in range(1, 5):
        H[i, i] = 2 - 400 * (x[i+1] - 3 * x[i]**2) + 200
        H[i, i-1] = H[i-1, i] = -400 * x[i-1]
        H[i, i+1] = H[i+1, i] = -400 * x[i]
    H[5, 5] = 200
    return H

def steepest_descent(f, gradient_f, x0, max_iter=10, alpha=0.01):
    """
    最速下降法优化函数f。

    参数:
    f -- 目标函数
    gradient_f -- 目标函数的梯度
    x0 -- 初始点
    max_iter -- 最大迭代次数
    alpha -- 学习率

    返回:
    每次迭代后的函数值列表
    """
    x = x0.copy()
    results = []
    for k in range(max_iter):
        grad = gradient_f(x)
        x -= alpha * grad
        results.append(f(x))
    return results

def newton_method(f, gradient_f, hessian_f, x0, max_iter=10):
    """
    牛顿法优化函数f。

    参数:
    f -- 目标函数
    gradient_f -- 目标函数的梯度
    hessian_f -- 目标函数的Hessian矩阵
    x0 -- 初始点
    max_iter -- 最大迭代次数

    返回:
    每次迭代后的函数值列表
    """
    x = x0.copy()
    results = []
    for k in range(max_iter):
        grad = gradient_f(x)
        H = hessian_f(x)
        delta_x = np.linalg.solve(H, -grad)
        x += delta_x
        results.append(f(x))
    return results

if __name__ == "__main__":
    x0 = np.zeros(6)

    # 最速下降法
    start_time = time.time()
    sd_results = steepest_descent(f, gradient_f, x0)
    sd_time = time.time() - start_time

    # 牛顿法
    start_time = time.time()
    newton_results = newton_method(f, gradient_f, hessian_f, x0)
    newton_time = time.time() - start_time

    # 打印结果
    print("迭代次数 k | 最速下降法 f(xk) | 牛顿法 f(xk)")
    for k in range(10):
        print(f"{k+1:10d} | {sd_results[k]:18.6f} | {newton_results[k]:18.6f}")

    print(f"\n10 次迭代两个方法所花时间:")
    print(f"最速下降法: {sd_time:.6f} 秒")
    print(f"牛顿法: {newton_time:.6f} 秒")

```

