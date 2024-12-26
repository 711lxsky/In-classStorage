/**
 * WeightedQuickUnionUF类的实现旨在解决并查集问题，它通过加权quick-union算法
 * 实现了动态连通性的高效检测和合并。这种算法通过在union操作中将较小的树
 * 接到较大的树上，从而保持树的平衡，提高了算法的效率。
 */
public class WeightedQuickUnionUF {

    // id数组用于存储每个节点的父节点，以构建森林
    private final int[] id;

    // sz数组用于存储每棵树的大小，用于加权合并
    private final int[] sz;

    // count用于记录当前的连通分量的数量
    private int count;

    /**
     * 构造函数初始化WeightedQuickUnionUF对象
     * @param N 初始化连通分量的数量，也是id数组和sz数组的大小
     */
    public WeightedQuickUnionUF(int N)
    {
        count = N;
        id = new int[N];
        for(int i=0;i<N;i++)
        {
           id[i] = i;
        }
        sz = new int[N];
        for(int i=0;i<N;i++)
        {
           sz[i] = 1;
        }
    }

    /**
     * 返回当前的连通分量数量
     * @return 连通分量的数量
     */
    public int count()
    {
        return count;
    }

    /**
     * 查找元素p所在的连通分量的根节点
     * @param p 要查找的元素
     * @return 元素p所在连通分量的根节点
     */
    public int find(int p)
    {
        while(p!=id[p])
           p = id[p];
        return p;
    }

    /**
     * 判断两个元素p和q是否在同一个连通分量中
     * @param p 第一个元素
     * @param q 第二个元素
     * @return 如果p和q连通返回true，否则返回false
     */
    public boolean connected(int p,int q)
    {
        return find(p) == find(q);
    }

    /**
     * 合并两个元素p和q所在的连通分量
     * @param p 第一个元素
     * @param q 第二个元素
     */
    public void union(int p,int q)
    {
        int pid = find(p);
        int qid = find(q);
        if(pid == qid)
           return;
        if(sz[pid]<sz[qid])
        {
           id[pid] = qid;
           sz[qid]+= sz[pid];
        }
        else
        {
           id[qid] = pid;
           sz[pid] += sz[qid];
        }
        count--;
    }
}
