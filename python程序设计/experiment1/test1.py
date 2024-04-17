import random
from collections import Counter

# 生成1000个0到100之间的随机整数
random_numbers = [random.randint(0, 100) for _ in range(1000)]

# 使用Counter来统计每个数字的出现次数
number_counts = Counter(random_numbers)

# 打印所有生成的随机数字，每行打印10个数字，使用制表符进行分隔
print("生成的随机数字为：")
for i in range(0, len(random_numbers), 10):
    print('\t'.join(f"{num:3d}" for num in random_numbers[i:i+10]))

# 打印每个数字及其出现的次数，使用格式化字符串来对齐文本
print("\n每个数字的出现次数：")
print(f"{'数字':<5}{'出现次数':>12}")
for number, count in sorted(number_counts.items()):
    print(f"{number:<5}{count:>12}")
