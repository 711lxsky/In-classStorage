import java.util.NoSuchElementException;

public class IndexMinPQ<Key extends Comparable<Key>> {
    private final int maxN;        // 最大元素数量
    private int n;                 // 当前元素数量
    private final int[] pq;        // 基于1索引的二叉堆
    private final int[] qp;        // pq的逆序数组，qp[pq[i]] = pq[qp[i]] = i
    private final Key[] keys;      // keys[i] = 优先级为i的键

    /**
     * 创建一个最大容量为 maxN 的索引最小优先队列。
     *
     * @param maxN 最大元素数量
     */
    public IndexMinPQ(int maxN) {
        if (maxN < 0) throw new IllegalArgumentException();
        this.maxN = maxN;
        n = 0;
        keys = (Key[]) new Comparable[maxN + 1];
        pq = new int[maxN + 1];
        qp = new int[maxN + 1];
        for (int i = 0; i <= maxN; i++)
            qp[i] = -1;
    }

    /**
     * 检查优先队列是否为空。
     *
     * @return 如果优先队列为空则返回 true，否则返回 false
     */
    public boolean isEmpty() {
        return n == 0;
    }

    /**
     * 检查索引 i 是否在优先队列中。
     *
     * @param i 索引
     * @return 如果索引 i 在优先队列中则返回 true，否则返回 false
     */
    public boolean contains(int i) {
        return qp[i] != -1;
    }

    /**
     * 将索引 i 和键 key 插入优先队列。
     *
     * @param i 索引
     * @param key 键
     */
    public void insert(int i, Key key) {
        if (contains(i)) throw new IllegalArgumentException("索引已存在于优先队列中");
        n++;
        qp[i] = n;
        pq[n] = i;
        keys[i] = key;
        swim(n);
    }

    /**
     * 删除并返回优先队列中的最小键对应的索引。
     *
     * @return 最小键对应的索引
     */
    public int delMin() {
        if (n == 0) throw new NoSuchElementException("优先队列下溢");
        int min = pq[1];
        exch(1, n--);
        sink(1);
        qp[min] = -1;        // 删除
        keys[min] = null;    // 帮助垃圾回收
        pq[n+1] = -1;        // 不需要
        return min;
    }

    /**
     * 减少索引 i 对应的键为新的键 key。
     *
     * @param i 索引
     * @param key 新的键
     */
    public void decreaseKey(int i, Key key) {
        if (!contains(i)) throw new NoSuchElementException("索引不在优先队列中");
        if (keys[i].compareTo(key) <= 0)
            throw new IllegalArgumentException("调用 decreaseKey() 会使键不严格减小");
        keys[i] = key;
        swim(qp[i]);
    }

    /**
     * 上浮操作，维护堆的性质。
     *
     * @param k 元素索引
     */
    private void swim(int k) {
        while (k > 1 && greater(k/2, k)) {
            exch(k, k/2);
            k = k/2;
        }
    }

    /**
     * 下沉操作，维护堆的性质。
     *
     * @param k 元素索引
     */
    private void sink(int k) {
        while (2*k <= n) {
            int j = 2*k;
            if (j < n && greater(j, j+1)) j++;
            if (!greater(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    /**
     * 比较两个键的大小。
     *
     * @param i 第一个键的索引
     * @param j 第二个键的索引
     * @return 如果 keys[pq[i]] > keys[pq[j]] 返回 true，否则返回 false
     */
    private boolean greater(int i, int j) {
        return keys[pq[i]].compareTo(keys[pq[j]]) > 0;
    }

    /**
     * 交换两个元素的位置。
     *
     * @param i 第一个元素的索引
     * @param j 第二个元素的索引
     */
    private void exch(int i, int j) {
        int swap = pq[i];
        pq[i] = pq[j];
        pq[j] = swap;
        qp[pq[i]] = i;
        qp[pq[j]] = j;
    }
}
