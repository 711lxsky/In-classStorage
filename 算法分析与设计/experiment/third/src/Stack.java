import java.util.Iterator;
import java.util.NoSuchElementException;

public class Stack<Item> implements Iterable<Item> {
    private Node<Item> first; // 栈顶节点
    private int n;            // 栈中元素的数量

    /**
     * 节点类，用于存储栈中的元素及其下一个节点。
     */
    private static class Node<Item> {
        private Item item;       // 节点存储的元素
        private Node<Item> next; // 指向下一个节点的引用
    }

    /**
     * 构造函数，初始化一个空栈。
     */
    public Stack() {
        first = null;
        n = 0;
    }

    /**
     * 检查栈是否为空。
     *
     * @return 如果栈为空则返回 true，否则返回 false
     */
    public boolean isEmpty() {
        return first == null;
    }

    /**
     * 获取栈中元素的数量。
     *
     * @return 栈中元素的数量
     */
    public int size() {
        return n;
    }

    /**
     * 向栈中添加一个元素。
     *
     * @param item 要添加的元素
     */
    public void push(Item item) {
        Node<Item> oldfirst = first; // 保存当前栈顶节点
        first = new Node<>();        // 创建新节点
        first.item = item;           // 设置新节点的值
        first.next = oldfirst;       // 新节点指向旧的栈顶节点
        n++;                         // 栈中元素数量加一
    }

    /**
     * 从栈中移除并返回栈顶元素。
     *
     * @return 栈顶元素
     * @throws NoSuchElementException 如果栈为空，则抛出此异常
     */
    public Item pop() {
        if (isEmpty()) throw new NoSuchElementException("栈下溢");
        Item item = first.item;      // 获取栈顶元素
        first = first.next;          // 将栈顶指针移动到下一个节点
        n--;                         // 栈中元素数量减一
        return item;                 // 返回栈顶元素
    }

    /**
     * 返回栈顶元素，但不移除它。
     *
     * @return 栈顶元素
     * @throws NoSuchElementException 如果栈为空，则抛出此异常
     */
    public Item peek() {
        if (isEmpty()) throw new NoSuchElementException("栈下溢");
        return first.item;           // 返回栈顶元素
    }

    /**
     * 返回一个迭代器，用于遍历栈中的元素。
     *
     * @return 迭代器
     */
    public Iterator<Item> iterator() {
        return new ListIterator<>(first);
    }

    /**
     * 内部类，实现 Iterator 接口，用于遍历栈中的元素。
     */
    private class ListIterator<Item> implements Iterator<Item> {
        private Node<Item> current;  // 当前节点

        /**
         * 构造函数，初始化迭代器。
         *
         * @param first 栈顶节点
         */
        public ListIterator(Node<Item> first) {
            current = first;
        }

        /**
         * 检查是否还有更多元素可以遍历。
         *
         * @return 如果还有更多元素则返回 true，否则返回 false
         */
        public boolean hasNext() {
            return current != null;
        }

        /**
         * 移除元素，不支持此操作。
         *
         * @throws UnsupportedOperationException 总是抛出此异常
         */
        public void remove() {
            throw new UnsupportedOperationException();
        }

        /**
         * 返回下一个元素，并将迭代器指针移动到下一个位置。
         *
         * @return 下一个元素
         * @throws NoSuchElementException 如果没有更多元素，则抛出此异常
         */
        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;  // 获取当前节点的值
            current = current.next;    // 将指针移动到下一个节点
            return item;               // 返回当前节点的值
        }
    }
}
