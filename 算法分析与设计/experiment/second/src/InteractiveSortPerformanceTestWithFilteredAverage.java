import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class InteractiveSortPerformanceTestWithFilteredAverage {
    private static final Random random = new Random();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 从用户获取测试次数
        System.out.print("请输入测试次数: ");
        int numTrials = scanner.nextInt();

        // 从用户获取数组大小
        System.out.print("请输入数组大小: ");
        int size = scanner.nextInt();

        // 关闭scanner
        scanner.close();

        // 执行排序测试并计算平均耗时和空间消耗
        testSorts(numTrials, size);
    }

    private static void testSorts(int numTrials, int size) {
        // 创建列表存储每种排序算法的所有耗时和空间消耗
        ArrayList<Long>[] times = new ArrayList[5];
        ArrayList<Long>[] spaces = new ArrayList[5];
        String[] sortNames = {
            "插入排序", "自顶向下归并排序", "自底向上归并排序", "随机快速排序", "Dijkstra 3-路划分快速排序"
        };
        for (int i = 0; i < 5; i++) {
            times[i] = new ArrayList<>();
            spaces[i] = new ArrayList<>();
        }

        for (int trial = 1; trial <= numTrials; trial++) {
            System.out.println("第 " + trial + " 轮测试：");
            int[] original = generateRandomArray(size);

            // 对每种排序方法进行测试，并记录耗时和空间消耗
            times[0].add(testSort(sortNames[0], original, InsertionSort::sort, spaces[0]));
            times[1].add(testSort(sortNames[1], original, TopDownMergeSort::sort, spaces[1]));
            times[2].add(testSort(sortNames[2], original, BottomUpMergeSort::sort, spaces[2]));
            times[3].add(testSort(sortNames[3], original, RandomQuickSort::sort, spaces[3]));
            times[4].add(testSort(sortNames[4], original, Dijkstra3WayQuickSort::sort, spaces[4]));

            System.out.println();
        }

        // 计算并打印每种排序算法的平均耗时和空间消耗（去掉最快和最慢的两个结果）
        System.out.println("平均耗时和空间消耗（毫秒/字节）：");
        for (int i = 0; i < 5; i++) {
            printAverageTimeAndSpace(sortNames[i], times[i], spaces[i]);
        }
    }

    private static void printAverageTimeAndSpace(String sortName, ArrayList<Long> times, ArrayList<Long> spaces) {
        if (times.size() > 4 && spaces.size() > 4) {
            Collections.sort(times);
            Collections.sort(spaces);
            // 去掉最快和最慢的两个结果
            times.remove(0);
            times.remove(0);
            times.remove(times.size() - 1);
            times.remove(times.size() - 1);
            spaces.remove(0);
            spaces.remove(0);
            spaces.remove(spaces.size() - 1);
            spaces.remove(spaces.size() - 1);

            // 计算平均值
            long sumTime = 0;
            long sumSpace = 0;
            for (long time : times) {
                sumTime += time;
            }
            for (long space : spaces) {
                sumSpace += space;
            }
            double averageTime = sumTime / (double) times.size() / 1e6;
            double averageSpace = sumSpace / (double) spaces.size();
            System.out.printf("%s 平均耗时: %.2f 毫秒, 平均空间消耗: %.2f 字节\n", sortName, averageTime, averageSpace);
        } else {
            System.out.println(sortName + " 测试次数不足以去掉四个结果。");
        }
    }

    private static long testSort(String sortName, int[] original, SortFunction sortFunction, ArrayList<Long> spaces) {
        int[] arr = Arrays.copyOf(original, original.length);
        long startTime = System.nanoTime();
        long startTotalMemory = Runtime.getRuntime().totalMemory();
        long startFreeMemory = Runtime.getRuntime().freeMemory();

        sortFunction.sort(arr);

        long endTime = System.nanoTime();
        long endTotalMemory = Runtime.getRuntime().totalMemory();
        long endFreeMemory = Runtime.getRuntime().freeMemory();
        long duration = endTime - startTime;
        long memoryConsumed = (endTotalMemory - endFreeMemory) - (startTotalMemory - startFreeMemory);

        System.out.printf("%s 总用时: %.2f 毫秒, 空间消耗: %d 字节\n", sortName, duration / 1e6, memoryConsumed);
        spaces.add(memoryConsumed);
        return duration;
    }

    private static int[] generateRandomArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt();
        }
        return array;
    }

    @FunctionalInterface
    interface SortFunction {
        void sort(int[] arr);
    }
}
