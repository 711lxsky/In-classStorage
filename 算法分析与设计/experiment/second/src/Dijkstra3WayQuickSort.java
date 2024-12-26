import java.util.Random;

/**
 * Dijkstra 三向切分快速排序算法实现。
 */
public class Dijkstra3WayQuickSort {
    /**
     * 对数组进行递归排序。
     *
     * @param arr 要排序的数组
     * @param lo  数组的起始索引
     * @param hi  数组的结束索引
     */
    private static void sort(int[] arr, int lo, int hi) {
        if (hi <= lo) return;

        int lt = lo, gt = hi;
        int pivot = arr[lo];
        int i = lo + 1;

        // 三向切分
        while (i <= gt) {
            if (arr[i] < pivot) swap(arr, lt++, i++);
            else if (arr[i] > pivot) swap(arr, i, gt--);
            else i++;
        }

        // 递归排序左右两部分
        sort(arr, lo, lt - 1);
        sort(arr, gt + 1, hi);
    }

    /**
     * 对数组进行排序。
     *
     * @param arr 要排序的数组
     */
    public static void sort(int[] arr) {
        shuffle(arr);  // 打乱数组以避免最坏情况性能
        sort(arr, 0, arr.length - 1);
    }

    /**
     * 打乱数组以避免最坏情况性能。
     *
     * @param arr 要打乱的数组
     */
    private static void shuffle(int[] arr) {
        Random rnd = new Random();
        for (int i = arr.length; i > 1; i--) {
            swap(arr, i - 1, rnd.nextInt(i));
        }
    }

    /**
     * 交换数组中的两个元素。
     *
     * @param arr 数组
     * @param i   第一个元素的索引
     * @param j   第二个元素的索引
     */
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
