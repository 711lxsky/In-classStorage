import edu.princeton.cs.algs4.StdRandom;

/**
 * 统计类，使用加权并查集
 * 这里仅仅需要改变其中的并查集类就行了，跟 quickfind 的统计类大致形似
 */
public class PercolationStatsWeighted {

    // 实验次数
    private final int T_number;

    // 每次实验的渗透阈值
    private final double[] threshold;

    // 平均值
    private double mean;

    // 标准偏差
    private double stddev;

    /**
     * 构造函数，执行 T 次独立的计算实验，网格大小为 N
     * @param N 网格大小
     * @param T 实验次数
     */
    public PercolationStatsWeighted(int N, int T) {
        T_number = T;
        mean = 0;
        threshold = new double[T];

        for(int i=0; i<T; i++) {
            Percolation percolation = new Percolation(N);
            int count = 0;
            do {
                int row = StdRandom.uniformInt(N) +1;
                int col = StdRandom.uniformInt(N) +1;
                if(percolation.isOpen(row, col)) {
                    continue;
                } else {
                    ++count;
                    percolation.open(row, col);
                }
            } while(!percolation.percolates());
            threshold[i] = (double)1.0 * count / (N * N);
        }
    }

    /**
     * 计算并返回渗透阈值的样本平均值
     * @return 渗透阈值的样本平均值
     */
    public double mean() {
        for (double v : threshold) {
            mean += v;
        }
        return mean = mean / threshold.length;
    }

    /**
     * 计算并返回渗透阈值的样本标准偏差
     * @return 渗透阈值的样本标准偏差
     */
    public double stddev() {
        double result = 0;
        for(int i=0; i<threshold.length; i++) {
            result += (threshold[i] - mean) * (threshold[i] - mean);
        }
        result /= (T_number - 1);
        return stddev = Math.sqrt(result);
    }

    /**
     * 返回 95% 置信区间的下界
     * @return 95% 置信区间的下界
     */
    public double confidenceLo() {
        double confidenceLow;
        return confidenceLow = (mean - stddev * 1.96 / Math.sqrt(T_number));
    }

    /**
     * 返回 95% 置信区间的上界
     * @return 95% 置信区间的上界
     */
    public double confidenceHi() {
        double confidenceHigh;
        return confidenceHigh = (mean + stddev * 1.96 / Math.sqrt(T_number));
    }
}
