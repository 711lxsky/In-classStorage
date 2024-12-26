import java.util.ArrayList;
import java.util.List;

public class Graph {
    private final int V; // 顶点数量
    private int E; // 边的数量
    private final List<Edge>[] adj; // 邻接表
    private final Point[] points; // 顶点坐标

    /**
     * 构造函数，创建一个包含 V 个顶点的空图。
     *
     * @param V 顶点数量
     */
    public Graph(int V) {
        this.V = V;
        this.E = 0;
        adj = (List<Edge>[]) new ArrayList[V];
        points = new Point[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new ArrayList<>();
        }
    }

    /**
     * 向图中添加一条边。
     *
     * @param e 边
     */
    public void addEdge(Edge e) {
        int v = e.from();
        int w = e.to();
        adj[v].add(e);
        E++;
    }

    /**
     * 向图中添加一个顶点及其坐标。
     *
     * @param p 顶点及其坐标
     */
    public void addPoint(Point p) {
        points[p.id] = p;
    }

    /**
     * 获取与顶点 v 相邻的所有边。
     *
     * @param v 顶点
     * @return 与顶点 v 相邻的边的集合
     */
    public Iterable<Edge> adj(int v) {
        return adj[v];
    }

    /**
     * 获取顶点 v 的坐标。
     *
     * @param v 顶点
     * @return 顶点 v 的坐标
     */
    public Point getPoint(int v) {
        return points[v];
    }

    /**
     * 获取图中的顶点数量。
     *
     * @return 顶点数量
     */
    public int V() {
        return V;
    }

    /**
     * 获取图中的边数量。
     *
     * @return 边数量
     */
    public int E() {
        return E;
    }
}
