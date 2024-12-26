import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ShortestPath {
    public static void main(String[] args) {
        Scanner consoleScanner = new Scanner(System.in);
//        System.out.println("Please enter the file path:");
//        String filePath = consoleScanner.nextLine();
        String filePath = "D:\\WorkSpace\\XDU\\AlgorithmAnalasis\\experiment\\third\\usa.txt";
        try (Scanner scanner = new Scanner(new File(filePath))) {
            int V = scanner.nextInt(); // 顶点数
            int E = scanner.nextInt(); // 边数
            Graph graph = new Graph(V);

            for (int i = 0; i < V; i++) {
                int id = scanner.nextInt();
                int x = scanner.nextInt();
                int y = scanner.nextInt();
                graph.addPoint(new Point(id, x, y));
            }

            // 假设边的信息是顶点ID对
            for (int i = 0; i < E; i++) {
                int v = scanner.nextInt();
                int w = scanner.nextInt();
                // 由于文件格式未明确给出边的权重，我们假设这是一个无向图，并计算两点之间的欧氏距离作为边的权重
                double weight = Point.distance(graph.getPoint(v), graph.getPoint(w));
                graph.addEdge(new Edge(v, w, weight));
                graph.addEdge(new Edge(w, v, weight)); // 如果是无向图，需要添加反向边
            }

            // 需要指定源点和目标点，这里假设用户输入
            System.out.println("Enter source vertex:");
            int source = consoleScanner.nextInt();
            System.out.println("Enter destination vertex:");
            int destination = consoleScanner.nextInt();
            long startTime = System.nanoTime();
            Dijkstra dijkstra = new Dijkstra(graph, source);
            if (dijkstra.hasPathTo(destination)) {
                System.out.println("Shortest distance from " + source + " to " + destination + " is " + dijkstra.distTo(destination));
                System.out.println("Path (in reverse order):");
                for (Edge e : dijkstra.pathTo(destination)) {
                    System.out.println(e.from() + " -> " + e.to() + " [" + e.weight() + "]");
                }
            } else {
                System.out.println("No path found from " + source + " to " + destination);
            }
            long endTime = System.nanoTime();
            long duration = (endTime - startTime);  // 获取差值，单位为纳秒
            System.out.println("Execution time: " + duration/1e9 + " seconds");
        } catch (FileNotFoundException e) {
            System.out.println("File not found: " + filePath);
        }
    }
}
