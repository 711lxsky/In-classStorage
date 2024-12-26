import java.util.Arrays;
import java.util.Random;

public class SortPerformanceTest {
    private static final int NUM_TRIALS = 50; // 测试次数
    private static final Random random = new Random();

    public static void main(String[] args) {
        int[] sizes = {1000, 5000, 10000, 20000, 50000, 100000}; // 不同的数组大小
        for (int size : sizes) {
            System.out.println("正在测试数组大小: " + size);
            testSorts(size);
            System.out.println();
        }
    }

    private static void testSorts(int size) {
        long startTime, endTime;
        double[] times = new double[5]; // 存储每种排序的时间

        for (int i = 0; i < NUM_TRIALS; i++) {
            int[] original = generateRandomArray(size); // 生成随机数组

            // 测试插入排序
            int[] arr = Arrays.copyOf(original, original.length);
            startTime = System.nanoTime();
            InsertionSort.sort(arr);
            endTime = System.nanoTime();
            times[0] += (endTime - startTime) / 1e6; // 转换为毫秒

            // 测试自顶向下归并排序
            arr = Arrays.copyOf(original, original.length);
            startTime = System.nanoTime();
            TopDownMergeSort.sort(arr);
            endTime = System.nanoTime();
            times[1] += (endTime - startTime) / 1e6;

            // 测试自底向上归并排序
            arr = Arrays.copyOf(original, original.length);
            startTime = System.nanoTime();
            BottomUpMergeSort.sort(arr);
            endTime = System.nanoTime();
            times[2] += (endTime - startTime) / 1e6;

            // 测试随机快速排序
            arr = Arrays.copyOf(original, original.length);
            startTime = System.nanoTime();
            RandomQuickSort.sort(arr);
            endTime = System.nanoTime();
            times[3] += (endTime - startTime) / 1e6;

            // 测试Dijkstra 3-路划分快速排序
            arr = Arrays.copyOf(original, original.length);
            startTime = System.nanoTime();
            Dijkstra3WayQuickSort.sort(arr);
            endTime = System.nanoTime();
            times[4] += (endTime - startTime) / 1e6;
        }

        // 打印每种排序算法的平均执行时间
        System.out.printf("插入排序平均时间: %.2f 毫秒\n", times[0] / NUM_TRIALS);
        System.out.printf("自顶向下归并排序平均时间: %.2f 毫秒\n", times[1] / NUM_TRIALS);
        System.out.printf("自底向上归并排序平均时间: %.2f 毫秒\n", times[2] / NUM_TRIALS);
        System.out.printf("随机快速排序平均时间: %.2f 毫秒\n", times[3] / NUM_TRIALS);
        System.out.printf("Dijkstra 3-路划分快速排序平均时间: %.2f 毫秒\n", times[4] / NUM_TRIALS);
    }

    private static int[] generateRandomArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt(); // 填充随机数
        }
        return array;
    }
}
