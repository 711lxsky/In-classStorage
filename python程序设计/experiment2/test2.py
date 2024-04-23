def get_user_input():
    # 获取用户输入，并给出提示
    input_string = input("请输入一系列整数，用空格分隔：")
    # 将输入字符串按空格分隔并转换为整数列表
    try:
        numbers = list(map(int, input_string.split()))
        return numbers
    except ValueError:
        print("输入包含非整数字符，请重新输入只包含整数的序列。")
        return None

def max_and_sum(numbers):
    if not numbers:  # 检查是否有输入的数字
        print("没有提供有效的整数序列。")
        return None, None

    max_number = max(numbers)  # 计算最大值
    total_sum = sum(numbers)   # 计算所有数字的总和

    print(f"最大值是：{max_number}")
    print(f"总和是：{total_sum}")
    
    return max_number, total_sum

# 主程序
numbers = None
while numbers is None:  # 确保只有有效输入才会停止循环
    numbers = get_user_input()

# 计算并打印最大值和总和
max_value, total = max_and_sum(numbers)
