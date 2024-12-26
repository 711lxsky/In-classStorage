public class Point {
    public final int id; // 顶点ID
    public final int x; // x坐标
    public final int y; // y坐标

    /**
     * 构造函数，创建一个具有指定 ID、x 坐标和 y 坐标的点。
     *
     * @param id 顶点ID
     * @param x x坐标
     * @param y y坐标
     */
    public Point(int id, int x, int y) {
        this.id = id;
        this.x = x;
        this.y = y;
    }

    /**
     * 计算两点之间的欧氏距离。
     *
     * @param a 第一个点
     * @param b 第二个点
     * @return 两点之间的欧氏距离
     */
    public static double distance(Point a, Point b) {
        return Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2));
    }
}
