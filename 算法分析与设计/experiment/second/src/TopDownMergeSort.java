/**
 * 自顶向下归并排序类
 * 该类提供了一个静态方法来对数组进行归并排序
 */
public class TopDownMergeSort {
    /**
     * 合并两个已排序的子数组。
     *
     * @param arr 原始数组
     * @param aux 辅助数组，用于存储临时数据
     * @param lo 子数组起始索引
     * @param mid 子数组中间索引
     * @param hi 子数组结束索引
     */
    private static void merge(int[] arr, int[] aux, int lo, int mid, int hi) {
        for (int k = lo; k <= hi; k++) {
            aux[k] = arr[k];
        }

        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid) arr[k] = aux[j++];
            else if (j > hi) arr[k] = aux[i++];
            else if (aux[j] < aux[i]) arr[k] = aux[j++];
            else arr[k] = aux[i++];
        }
    }

    /**
     * 递归地对数组进行归并排序。
     *
     * @param arr 原始数组
     * @param aux 辅助数组，用于存储临时数据
     * @param lo 排序起始索引
     * @param hi 排序结束索引
     */
    private static void sort(int[] arr, int[] aux, int lo, int hi) {
        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sort(arr, aux, lo, mid);
        sort(arr, aux, mid + 1, hi);
        merge(arr, aux, lo, mid, hi);
    }

    /**
     * 对数组进行自顶向下的归并排序。
     *
     * @param arr 需要排序的数组
     */
    public static void sort(int[] arr) {
        int[] aux = new int[arr.length];
        sort(arr, aux, 0, arr.length - 1);
    }
}
