import random

# 生成包含20个随机数的列表，随机数范围为0到100
random_numbers = [random.randint(0, 100) for _ in range(20)]

print("原始随机数列表:")
print(random_numbers)

# 将前10个元素升序排列
first_part_sorted = sorted(random_numbers[:10])

# 将后10个元素降序排列
second_part_sorted = sorted(random_numbers[10:], reverse=True)

# 合并两部分
sorted_numbers = first_part_sorted + second_part_sorted

print("\n排序后的列表：")
print("前10个元素升序排列:", first_part_sorted)
print("后10个元素降序排列:", second_part_sorted)

# 使用分隔符来打印整个排序后的列表
print("\n整个排序后的列表（'|'为分隔符）:")
print(*first_part_sorted, '|', *second_part_sorted)
