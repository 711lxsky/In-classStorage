/**
 * Percolation类用于模拟渗透系统
 * 它使用并查集算法来高效地识别系统是否渗透
 */
public class Percolation {

    // N代表网格的大小
    private final int N;

    // uf1是用于识别系统是否渗透的并查集对象
    private final QuickFindUF uf1;

    // grid用于表示网格中每个位置的状态，0代表阻塞，1代表开放
    private final int[][] grid;

    /**
     * 构造函数，初始化渗透系统
     * @param N 网格的大小
     */
    public Percolation(int N) {
        this.N = N;
        grid = new int[1+N][1+N];
        uf1 = new QuickFindUF(N*N+2);
        // 初始化网格，所有位置默认为阻塞状态
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                grid[i][j] = 0;
            }
        }
        // 初始化并查集，将最上方和最下方的虚拟节点与第一行和最后一行的节点连接
        for(int i=1;i<=N;i++) {
            uf1.union(0, i);
            uf1.union(N*N+1, N*N-i);
        }
    }

    /**
     * 打开指定位置的网格
     * @param row 行号
     * @param col 列号
     */
    public void open(int row,int col) {
        grid[row][col] = 1;
        int recentKey = (row-1)*N+col;
        // 判断周围网格的状态，如果开放则将它们连接
        if(row-1>=1&&row-1<=N&&col>=1&&col<=N) {
            int key = (row-1-1)*N+col;
            if(grid[row-1][col]==1) {
                uf1.union(recentKey, key);
            }
        }
        if(row + 1 <= N && col >= 1 && col <= N) {
            int key = (row+1-1)*N+col;
            if(grid[row+1][col]==1) {
                uf1.union(recentKey, key);
            }
        }
        if(row >= 1 && row <= N && col + 1 <= N) {
            int key = (row-1)*N+col+1;
            if(grid[row][col+1]==1) {
                uf1.union(recentKey, key);
            }
        }
        if(row>=1&&row<=N&&col-1>=1&&col-1<=N) {
            int key = (row-1)*N+col-1;
            if(grid[row][col-1]==1) {
                uf1.union(recentKey, key);
            }
        }
    }

    /**
     * 判断指定位置的网格是否开放
     * @param row 行号
     * @param col 列号
     * @return 如果开放返回true，否则返回false
     */
    public boolean isOpen(int row,int col) {
        return grid[row][col] == 1;
    }

    /**
     * 判断指定位置的网格是否充满
     * @param row 行号
     * @param col 列号
     * @return 如果充满返回true，否则返回false
     */
    public boolean isFull(int row,int col) {
        return uf1.connected(0, (row-1)*N+col)&&isOpen(row,col);
    }

    /**
     * 判断系统是否渗透
     * @return 如果渗透返回true，否则返回false
     */
    public boolean percolates() {
        return uf1.connected(0, N*N+1);
    }
}
