def simulated_sorted(array):
    # 插入排序实现
    sorted_array = array.copy()
    for i in range(1, len(sorted_array)):
        current_value = sorted_array[i]
        position = i
        
        while position > 0 and sorted_array[position - 1] > current_value:
            sorted_array[position] = sorted_array[position - 1]
            position -= 1
        
        sorted_array[position] = current_value
    return sorted_array

def get_input_and_sort():
    # 打印模拟sorted函数的提示
    print("此程序模拟内置的sorted()函数。请输入一系列整数，用空格分隔：")
    
    # 提示用户输入一系列整数，用空格分隔
    input_string = input()
    # 尝试将输入的字符串分割并转换为整数列表
    try:
        numbers = list(map(int, input_string.split()))
    except ValueError:
        print("输入错误，请确保您输入的是用空格分隔的整数。")
        return

    # 使用模拟的sorted函数进行排序
    sorted_numbers = simulated_sorted(numbers)
    print("排序后的列表:", sorted_numbers)

# 调用函数
get_input_and_sort()
