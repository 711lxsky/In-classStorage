import numpy as np
import time
from scipy.optimize import line_search


# 定义目标函数
def f(x):
    return sum((1 - x[i]) ** 2 + 100 * (x[i + 1] - x[i] ** 2) ** 2 for i in range(5))


# 定义梯度
def grad_f(x):
    grad = np.zeros_like(x)
    for i in range(5):
        if i < 4:
            grad[i] += -2 * (1 - x[i]) - 400 * x[i] * (x[i + 1] - x[i] ** 2)
            grad[i + 1] += 200 * (x[i + 1] - x[i] ** 2)
        else:
            grad[i] += -2 * (1 - x[i])
    return grad


# 定义Hessian
def hessian_f(x):
    hess = np.zeros((6, 6))
    for i in range(5):
        hess[i][i] += 2 + 1200 * x[i] ** 2 - 400 * x[i + 1]
        if i < 4:
            hess[i][i + 1] = -400 * x[i]
            hess[i + 1][i] = -400 * x[i]
            hess[i + 1][i + 1] += 200
    return hess


# 最速下降法
def steepest_descent(x0, max_iter=10):
    x = x0.copy()
    f_values = []
    times = []
    start_time = time.time()

    for k in range(max_iter):
        grad = grad_f(x)
        alpha = line_search(f, grad_f, x, -grad)[0]  # 使用线搜索确定步长
        if alpha is None:
            alpha = 0.001  # 如果线搜索失败，使用默认步长
        x -= alpha * grad
        f_values.append(f(x))
        times.append(time.time() - start_time)

    return f_values, times


# 牛顿法
def newton_method(x0, max_iter=10):
    x = x0.copy()
    f_values = []
    times = []
    start_time = time.time()
    B = np.eye(len(x0))  # 初始化近似Hessian矩阵

    for k in range(max_iter):
        grad = grad_f(x)
        p = -np.linalg.solve(B, grad)  # 使用近似Hessian矩阵求解方向
        alpha = line_search(f, grad_f, x, p)[0]  # 使用线搜索确定步长
        if alpha is None:
            alpha = 0.001  # 如果线搜索失败，使用默认步长
        s = alpha * p  # 计算步长
        x_new = x + s
        y = grad_f(x_new) - grad  # 计算梯度差
        rho = 1 / (y @ s)
        B += rho * np.outer(y, y) - rho * B @ np.outer(s, s) @ B  # 更新近似Hessian矩阵
        x = x_new
        f_values.append(f(x))
        times.append(time.time() - start_time)

    return f_values, times


# 初始化
x0 = np.zeros(6)
# 最速下降法
start_time_sd = time.time()
f_values_sd, times_sd = steepest_descent(x0)
time_sd = time.time() - start_time_sd

# 牛顿法
start_time_nm = time.time()
f_values_nm, times_nm = newton_method(x0)
time_nm = time.time() - start_time_nm

# 打印结果表格
print("迭代次数 k\t最速下降法\t牛顿法\t\t最速下降法时间\t牛顿法时间")
for k in range(10):
    print(f"{k + 1}\t\t{f_values_sd[k]:.8f}"
          f"\t{f_values_nm[k]:.8f}"
          f"\t{times_sd[k]:.4f}\t\t{times_nm[k]:.4f}")

# 打印总耗时
print(f"\n最速下降法总耗时: {time_sd:.6f} 秒")
print(f"牛顿法总耗时: {time_nm:.6f} 秒")
