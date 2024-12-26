/**
 * InsertionSort类提供了插入排序算法的实现
 * 插入排序是一种简单直观的排序算法，它通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入
 */
public class InsertionSort {
    /**
     * 对整数数组进行排序
     * 该方法使用插入排序算法，逐步将每个元素插入到已排序的部分，直到整个数组有序
     *
     * @param arr 待排序的整数数组
     */
    public static void sort(int[] arr) {
        // 从第二个元素开始遍历，因为第一个元素默认已排序
        for (int i = 1; i < arr.length; i++) {
            // 将arr[i]插入到已排序序列中，找到合适的位置，较大的元素会自动后移
            for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
                // 交换元素arr[j]和arr[j-1]
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}
