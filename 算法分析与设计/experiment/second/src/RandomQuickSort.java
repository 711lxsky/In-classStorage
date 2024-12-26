import java.util.Random;

public class RandomQuickSort {
    /**
     * 交换数组中的两个元素。
     *
     * @param arr 数组
     * @param i 第一个元素的索引
     * @param j 第二个元素的索引
     */
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    /**
     * 对数组进行分区操作。
     *
     * @param arr 数组
     * @param lo 分区起始索引
     * @param hi 分区结束索引
     * @return 分区点的索引
     */
    private static int partition(int[] arr, int lo, int hi) {
        int i = lo, j = hi + 1;
        int v = arr[lo];
        while (true) {
            while (arr[++i] < v) if (i == hi) break;
            while (v < arr[--j]) if (j == lo) break;
            if (i >= j) break;
            swap(arr, i, j);
        }
        swap(arr, lo, j);
        return j;
    }

    /**
     * 对数组进行快速排序。
     *
     * @param arr 数组
     * @param lo 排序起始索引
     * @param hi 排序结束索引
     */
    private static void sort(int[] arr, int lo, int hi) {
        if (hi <= lo) return;
        int pivot = lo + new Random().nextInt(hi - lo + 1);
        swap(arr, lo, pivot);  // 将枢轴移到数组开头
        int j = partition(arr, lo, hi);
        sort(arr, lo, j - 1);
        sort(arr, j + 1, hi);
    }

    /**
     * 对数组进行排序。
     *
     * @param arr 需要排序的数组
     */
    public static void sort(int[] arr) {
        shuffle(arr);  // 为了保证性能，先打乱数组
        sort(arr, 0, arr.length - 1);
    }

    /**
     * 打乱数组中的元素顺序。
     *
     * @param arr 需要打乱的数组
     */
    private static void shuffle(int[] arr) {
        Random rnd = new Random();
        for (int i = arr.length; i > 1; i--) {
            swap(arr, i - 1, rnd.nextInt(i));
        }
    }
}
