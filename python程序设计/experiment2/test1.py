def count_characters():
    s = input("请输入一个字符串：")  # 从用户输入中获取字符串
    upper_count = 0  # 大写字母数量
    lower_count = 0  # 小写字母数量
    digit_count = 0  # 数字数量
    other_count = 0  # 其他字符数量

    # 遍历字符串中的每个字符
    for char in s:
        if char.isdigit():  # 判断是否为数字
            digit_count += 1
        elif char.isupper():  # 判断是否为大写字母
            upper_count += 1
        elif char.islower():  # 判断是否为小写字母
            lower_count += 1
        else:  # 其他字符
            other_count += 1
        
        # 打印每个字符及其被识别的类别
        print(f"字符：'{char}' - 类别：", end='')
        if char.isdigit():
            print("数字")
        elif char.isupper():
            print("大写字母")
        elif char.islower():
            print("小写字母")
        else:
            print("其他字符")

    # 打印总计结果
    print(f"大写字母总数：{upper_count}")
    print(f"小写字母总数：{lower_count}")
    print(f"数字总数：{digit_count}")
    print(f"其他字符总数：{other_count}")

    return (upper_count, lower_count, digit_count, other_count)

# 调用函数
print("开始统计字符...")
result = count_characters()
print(f"最终统计结果：大写={result[0]}, 小写={result[1]}, 数字={result[2]}, 其他={result[3]}")
