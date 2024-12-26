public class Edge {
    private final int v; // 起点顶点
    private final int w; // 终点顶点
    private final double weight; // 边的权重（距离）

    /**
     * 构造函数，创建一条连接顶点 v 和 w 的边，并赋予权重 weight。
     *
     * @param v 起点顶点
     * @param w 终点顶点
     * @param weight 边的权重
     */
    public Edge(int v, int w, double weight) {
        this.v = v;
        this.w = w;
        this.weight = weight;
    }

    /**
     * 获取边的起点顶点。
     *
     * @return 起点顶点
     */
    public int from() {
        return v;
    }

    /**
     * 获取边的终点顶点。
     *
     * @return 终点顶点
     */
    public int to() {
        return w;
    }

    /**
     * 获取边的权重。
     *
     * @return 边的权重
     */
    public double weight() {
        return weight;
    }
}
