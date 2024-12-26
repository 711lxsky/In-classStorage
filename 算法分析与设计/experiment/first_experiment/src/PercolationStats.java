public class PercolationStats {

    // 实验次数
    private final int T_number;

    // 存储每次实验的渗透阈值
    private final double[] threshold;

    // 渗透阈值的平均值
    private double mean;

    // 渗透阈值的标准差
    private double stddev;

    /**
     * 构造函数，执行 T 次独立的计算实验，每次实验在一个 N x N 的网格上进行
     * @param N 网格大小
     * @param T 实验次数
     */
    public PercolationStats(int N, int T) {
        T_number = T;
        mean = 0;
        threshold = new double[T];
        for(int i = 0; i < T; i++) {
            Percolation percolation = new Percolation(N);
            int count = 0;
            do {
                int row = StdRandom.uniformInt(N) + 1;
                int col = StdRandom.uniformInt(N) + 1;
                if(percolation.isOpen(row, col)) {
                    continue;
                } else {
                    ++count;
                    percolation.open(row, col);
                }
            } while(!percolation.percolates());
            threshold[i] = 1.0 * count / (N * N);
        }
    }

    /**
     * 计算并返回渗透阈值的样本均值
     * @return 渗透阈值的样本均值
     */
    public double mean() {
        for(int i = 0; i < threshold.length; i++) {
            mean += threshold[i];
        }
        return mean = mean / threshold.length;
    }

    /**
     * 计算并返回渗透阈值的样本标准差
     * @return 渗透阈值的样本标准差
     */
    public double stddev() {
        double result = 0;
        for(int i = 0; i < threshold.length; i++) {
            result += (threshold[i] - mean) * (threshold[i] - mean);
        }
        result /= (T_number - 1);
        return stddev = Math.sqrt(result);
    }

    /**
     * 返回 95% 置信区间的下限
     * @return 95% 置信区间的下限
     */
    public double confidenceLo() {
        double confidenceLow;
        return confidenceLow = (mean - stddev * 1.96 / Math.sqrt(T_number));
    }

    /**
     * 返回 95% 置信区间的上限
     * @return 95% 置信区间的上限
     */
    public double confidenceHi() {
        double confidenceHigh;
        return confidenceHigh = (mean + stddev * 1.96 / Math.sqrt(T_number));
    }

    public static void main(String[] args) {
    // 固定 N，变化 T
    int fixedN = 100;
//    runExperiment(200, 30);
    for (int t = 10; t <= 100; t += 10) {
        runExperiment(fixedN, t);
    }

    // 变化 N，固定 T
    int fixedT = 30;
    for (int n = 10; n <= 200; n *= 2) {
        runExperiment(n, fixedT);
    }
}

private static void runExperiment(int n, int t) {
    long starttime = System.currentTimeMillis();
    // 使用 quickfind 算法
    PercolationStats quickfind = new PercolationStats(n, t);
    long endtime = System.currentTimeMillis();
    long realtime = endtime - starttime;
    System.out.println("使用 quickfind 算法实现，所使用的 n 为 " + n + ", t 是 " + t);
    System.out.println("mean()        " + quickfind.mean());
    System.out.println("stddev()    " + quickfind.stddev());
    System.out.println("confidenceLo()    " + quickfind.confidenceLo());
    System.out.println("confidenceHi()    " + quickfind.confidenceHi());
    System.out.println("运行时间 " + realtime + " 毫秒");

    starttime = System.currentTimeMillis();
    // 使用 WeightedquickUnion 算法
    PercolationStatsWeighted weightedQuickUnion = new PercolationStatsWeighted(n, t);
    endtime = System.currentTimeMillis();
    realtime = endtime - starttime;
    System.out.println("使用 WeightedquickUnion 算法实现，所使用的 n 为 " + n + ", t 是 " + t);
    System.out.println("mean()        " + weightedQuickUnion.mean());
    System.out.println("stddev()    " + weightedQuickUnion.stddev());
    System.out.println("confidenceLo()    " + weightedQuickUnion.confidenceLo());
    System.out.println("confidenceHi()    " + weightedQuickUnion.confidenceHi());
    System.out.println("运行时间 " + realtime + " 毫秒");
    System.out.println("---------------------分割线-----------------------------");
}

}
