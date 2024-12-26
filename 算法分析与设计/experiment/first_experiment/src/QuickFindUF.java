/**
 * QuickFindUF类代表一个联合查找数据结构，它使用快速查询算法来解决动态连通性问题
 * 它提供了一种操作方式，可以有效地识别两个元素是否属于同一组，以及将两个元素所在的组合并
 */
public class QuickFindUF {

    // id数组，用于记录每个元素的根节点
    private final int[] id;

    // 记录当前的组数量
    private int count;

    /**
     * 构造函数，初始化QuickFindUF对象
     * @param N 初始化的元素数量，每个元素最初都属于不同的组
     */
    public QuickFindUF(int N)
    {
        count = N;
        id = new int[N];
        for(int i=0;i<N;i++)
        {
           id[i] = i;
        }
    }

    /**
     * 返回当前的组数量
     * @return 组的数量
     */
    public int count()
    {
        return count;
    }

    /**
     * 查找元素p所在的组的标识
     * @param p 要查找的元素
     * @return 元素p所在的组的标识
     */
    public int find(int p)
    {
        return id[p];
    }

    /**
     * 判断两个元素p和q是否属于同一个组
     * @param p 第一个元素
     * @param q 第二个元素
     * @return 如果p和q属于同一个组返回true，否则返回false
     */
    public boolean connected(int p,int q)
    {
        return find(p) == find(q);
    }

    /**
     * 合并元素p和q所在的组
     * @param p 第一个元素
     * @param q 第二个元素
     */
    public void union(int p,int q)
    {
        int pid = find(p);
        int qid = find(q);

        if(pid == qid)
           return;

        for(int i =0;i<id.length;i++)
        {
           if(id[i] == pid)
               id[i] = qid;
        }
        count--;
    }
}
