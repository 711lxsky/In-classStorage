import pickle
import unittest


class ListInstanceAttr:
    def __str__(self):
        attr_list = []
        for attr in sorted(dir(self)):  # 排序属性以获得更可预测的输出
            if not attr.startswith('__') and not callable(getattr(self, attr)):
                value = getattr(self, attr)
                attr_list.append(f"{attr} = {value}")
        if not attr_list:  # 如果没有属性，则返回提示信息
            return "此实例没有可显示的自定义属性。"
        return "实例属性如下:\n" + "\n".join(attr_list)

    def __getstate__(self):
        state = {}
        for attr in sorted(dir(self)):
            if not attr.startswith('__') and not callable(getattr(self, attr)):
                state[attr] = getattr(self, attr)
        return state

    def __setstate__(self, state):
        for attr, value in state.items():
            setattr(self, attr, value)


# 示例类1
class A:
    def __init__(self):
        self.alpha = 123
        self.beta = 'beta 的值'

# 示例类2
class B:
    def __init__(self):
        self.gamma = 456
        self.delta = 'delta 的值'

# 多重继承，继承 ListInstanceAttr 和其他两个类
class C(A, B, ListInstanceAttr):
    def __init__(self):
        A.__init__(self)
        B.__init__(self)
        self.omega = True

# 创建一个 C 类的实例
c_instance = C()

# 打印实例 c 的所有可访问的属性及其值
print(c_instance)


class TestC(unittest.TestCase):
    def test_c_instance_attributes(self):
        self.assertIsInstance(c_instance, C)
        self.assertEqual(c_instance.alpha, 123)
        self.assertEqual(c_instance.beta, 'beta 的值')
        self.assertEqual(c_instance.gamma, 456)
        self.assertEqual(c_instance.delta, 'delta 的值')
        self.assertTrue(c_instance.omega)

    def test_pickle_serialization(self):
        serialized_data = pickle.dumps(c_instance)
        deserialized_instance = pickle.loads(serialized_data)

        self.assertIsInstance(deserialized_instance, C)
        self.assertEqual(deserialized_instance.alpha, c_instance.alpha)
        self.assertEqual(deserialized_instance.beta, c_instance.beta)
        self.assertEqual(deserialized_instance.gamma, c_instance.gamma)
        self.assertEqual(deserialized_instance.delta, c_instance.delta)
        self.assertEqual(deserialized_instance.omega, c_instance.omega)


if __name__ == '__main__':
    unittest.main()

if __name__ == "__test__":
    unittest.main(argv=['first-arg-is-ignored'], exit=False)