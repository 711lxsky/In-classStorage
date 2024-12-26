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
