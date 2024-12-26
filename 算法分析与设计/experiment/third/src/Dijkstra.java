import java.util.Arrays;

public class Dijkstra {
    private final double[] distTo; // distTo[v] = 最短路径 s->v 的距离
    private final Edge[] edgeTo; // edgeTo[v] = 最短路径 s->v 中最后一个边
    private final IndexMinPQ<Double> pq; // 顶点的优先队列

    /**
     * 构造函数，计算从起点 s 到图 G 中所有顶点的最短路径。
     *
     * @param G 图
     * @param s 起点顶点
     */
    public Dijkstra(Graph G, int s) {
        distTo = new double[G.V()];
        edgeTo = new Edge[G.V()];

        for (int v = 0; v < G.V(); v++)
            distTo[v] = Double.POSITIVE_INFINITY;
        distTo[s] = 0.0;

        pq = new IndexMinPQ<>(G.V());
        pq.insert(s, distTo[s]);
        while (!pq.isEmpty()) {
            int v = pq.delMin();
            for (Edge e : G.adj(v))
                relax(G, e);
        }
    }

    /**
     * 放松边 e，并更新最短路径信息。
     *
     * @param G 图
     * @param e 边
     */
    private void relax(Graph G, Edge e) {
        int v = e.from(), w = e.to();
        double newDist = distTo[v] + e.weight();
        if (distTo[w] > newDist) {
            distTo[w] = newDist;
            edgeTo[w] = e;
            if (pq.contains(w)) pq.decreaseKey(w, distTo[w]);
            else                pq.insert(w, distTo[w]);
        }
    }

    /**
     * 返回从起点到顶点 v 的最短路径距离。
     *
     * @param v 目标顶点
     * @return 最短路径距离
     */
    public double distTo(int v) {
        return distTo[v];
    }

    /**
     * 判断是否存在从起点到顶点 v 的路径。
     *
     * @param v 目标顶点
     * @return 如果存在路径则返回 true，否则返回 false
     */
    public boolean hasPathTo(int v) {
        return distTo[v] < Double.POSITIVE_INFINITY;
    }

    /**
     * 返回从起点到顶点 v 的最短路径。
     *
     * @param v 目标顶点
     * @return 最短路径上的边的集合，如果没有路径则返回 null
     */
    public Iterable<Edge> pathTo(int v) {
        if (!hasPathTo(v)) return null;
        Stack<Edge> path = new Stack<>();
        for (Edge e = edgeTo[v]; e != null; e = edgeTo[e.from()]) {
            path.push(e);
        }
        return path;
    }
}
