def is_prime(num):
    """判断一个数是否为质数"""
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def prime_generator(start, end):
    """在指定的范围内生成质数，并打印每个质数的详情"""
    prime_count = 0  # 初始化质数计数器
    for num in range(start, end + 1):
        if is_prime(num):
            prime_count += 1
            print(f"发现第 {prime_count} 个目标质数：{num}")
            yield num

def get_prime_sum(start, end):
    """计算指定范围内质数的和，同时打印详细的计算过程"""
    total = 0
    for prime in prime_generator(start, end):
        total += prime
        print(f"添加质数 {prime} 后当前质数和更新为：{total} \n")
    return total

def main():
    print("计算指定范围内的质数和")
    try:
        start = int(input("请输入起始数字："))
        end = int(input("请输入结束数字："))
        if start > end:
            print("起始数字必须小于或等于结束数字。")
        else:
            print(f"开始计算从 {start} 到 {end} 范围内的质数和。")
            result = get_prime_sum(start, end)
            print(f"从 {start} 到 {end} 范围内的质数和是：{result}")
    except ValueError:
        print("输入错误，请输入有效的整数。")

if __name__ == "__main__":
    main()
