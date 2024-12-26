/**
 * 自底向上归并排序类
 * 该类提供了一个静态方法来对数组进行归并排序
 */
public class BottomUpMergeSort {

    /**
     * 归并排序的核心方法，用于将数组的两个部分合并成一个有序的部分
     *
     * @param arr 待排序的数组
     * @param aux 辅助数组，用于在合并过程中临时存储元素
     * @param lo 本次合并的左边界
     * @param mid 本次合并的中间点，左边部分的最后一个元素
     * @param hi 本次合并的右边界
     */
    private static void merge(int[] arr, int[] aux, int lo, int mid, int hi) {
        // 将arr[lo..hi]复制到aux[lo..hi]
        for (int k = lo; k <= hi; k++) {
            aux[k] = arr[k];
        }

        // 归并过程
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if      (i > mid)              arr[k] = aux[j++];  // 左半边用尽
            else if (j > hi)               arr[k] = aux[i++];  // 右半边用尽
            else if (aux[j] < aux[i])      arr[k] = aux[j++];  // 右半边的元素小于左半边
            else                           arr[k] = aux[i++];  // 左半边的元素小于等于右半边
        }
    }

    /**
     * 对外提供的静态方法，用于对数组进行归并排序
     *
     * @param arr 待排序的数组
     */
    public static void sort(int[] arr) {
        int N = arr.length;
        int[] aux = new int[N];
        // 从数组的最小单元开始，逐步扩大排序的范围，直到覆盖整个数组
        for (int sz = 1; sz < N; sz = sz + sz) {
            // 在当前排序范围下，对数组进行归并排序
            for (int lo = 0; lo < N - sz; lo += sz + sz) {
                merge(arr, aux, lo, lo + sz - 1, Math.min(lo + sz + sz - 1, N - 1));
            }
        }
    }
}
