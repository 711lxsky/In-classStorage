def calculate_y(x):
    """
    根据给定的x值计算分段函数的y值。
    分段函数定义如下：
    - x < 0: y = 0
    - 0 <= x < 5: y = x
    - 5 <= x < 10: y = 3x - 5
    - 10 <= x < 20: y = 0.5x - 2
    - 20 <= x: y = 0
    """
    if x < 0:
        return 0
    elif 0 <= x < 5:
        return x
    elif 5 <= x < 10:
        return 3 * x - 5
    elif 10 <= x < 20:
        return 0.5 * x - 2
    else:  # 20 <= x
        return 0

# 获取用户输入
x_input = float(input("请输入x的值："))

# 计算并打印y的值
y_output = calculate_y(x_input)
print(f"对于x = {x_input}, 分段函数的y值为：{y_output}")
