def is_leap_year(year):
    """
    判断指定的年份是否为闰年。
    如果年份能被400整除，则为闰年；
    如果年份能被4整除但不能被100整除也为闰年。
    """
    if year % 400 == 0:
        return True
    if year % 100 == 0:
        return False
    if year % 4 == 0:
        return True
    return False

# 获取用户输入
year_str = input("请输入一个4位整数作为年份：")

# 验证输入是否为4位整数
if not year_str.isdigit() or len(year_str) != 4:
    print("输入错误，请确保输入的是4位整数。")
else:
    year = int(year_str)
    # 判断是否为闰年并打印结果
    if is_leap_year(year):
        print(f"{year}年是闰年。")
    else:
        print(f"{year}年不是闰年。")
