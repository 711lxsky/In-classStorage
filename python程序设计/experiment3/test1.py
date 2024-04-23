import pickle
import unittest


class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.is_empty():
            return "栈为空，无法弹出。"
        return self.items.pop()

    def peek(self):
        if self.is_empty():
            return "栈为空，无法查看。"
        return self.items[-1]

    def size(self):
        return len(self.items)

    def __str__(self):
        return '栈中内容: ' + str(self.items)

    def serialize(self):
        """
        将当前栈实例序列化为字节流。
        """
        return pickle.dumps(self)

    @classmethod
    def deserialize(cls, serialized_data):
        """
        反序列化字节流为 `Stack` 实例。
        """
        return pickle.loads(serialized_data)


class TestStack(unittest.TestCase):
    def setUp(self):
        self.stack = Stack()

    def test_is_empty(self):
        self.assertTrue(self.stack.is_empty())
        self.stack.push('item')
        self.assertFalse(self.stack.is_empty())

    def test_push(self):
        self.stack.push('item1')
        self.assertEqual(self.stack.size(), 1)
        self.stack.push('item2')
        self.assertEqual(self.stack.size(), 2)

    def test_pop(self):
        self.assertEqual(self.stack.pop(), "栈为空，无法弹出。")
        self.stack.push('item1')
        self.stack.push('item2')
        self.assertEqual(self.stack.pop(), 'item2')
        self.assertEqual(self.stack.pop(), 'item1')
        self.assertEqual(self.stack.pop(), "栈为空，无法弹出。")

    def test_peek(self):
        self.assertEqual(self.stack.peek(), "栈为空，无法查看。")
        self.stack.push('item')
        self.assertEqual(self.stack.peek(), 'item')

    def test_size(self):
        self.assertEqual(self.stack.size(), 0)
        self.stack.push('item')
        self.assertEqual(self.stack.size(), 1)

    def test_str(self):
        self.assertEqual(str(self.stack), "栈中内容: []")
        self.stack.push('item')
        self.assertEqual(str(self.stack), "栈中内容: ['item']")

    def test_serialization(self):
        self.stack.push('item1')
        self.stack.push('item2')

        serialized_data = self.stack.serialize()
        deserialized_stack = Stack.deserialize(serialized_data)

        self.assertEqual(str(deserialized_stack), str(self.stack))


def main():
    stack = Stack()
    while True:
        print("\n当前栈状态:", str(stack))
        print("选择操作：")
        print("1: 入栈（添加元素）")
        print("2: 出栈（移除元素）")
        print("3: 查看栈顶元素")
        print("4: 检查栈是否为空")
        print("5: 获取栈的大小")
        print("6: 退出程序")
        
        operation = input("请输入您的选择（1-6）: ")
        
        if operation == '1':
            item = input("请输入要入栈的元素: ")
            stack.push(item)
            print("元素已入栈。")
        elif operation == '2':
            result = stack.pop()
            print("出栈元素:", result)
        elif operation == '3':
            result = stack.peek()
            print("栈顶元素:", result)
        elif operation == '4':
            if stack.is_empty():
                print("栈为空。")
            else:
                print("栈不为空。")
        elif operation == '5':
            print("栈的大小为:", stack.size())
        elif operation == '6':
            print("退出程序。")
            break
        else:
            print("无效输入，请输入1-6之间的数字。")


if __name__ == "__main__":
    main()


# 单元测试执行部分（与主函数分离，便于独立运行测试）
if __name__ == "__test__":
    unittest.main(argv=['first-arg-is-ignored'], exit=False)