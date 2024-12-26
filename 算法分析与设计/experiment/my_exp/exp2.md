## 实验二 几种排序算法的实验性能比较 

## 一、 实验目的 

在计算机上针对不同输入规模数据进行实验，对比排序算法的时间及空间占用性能。 

## 二、 实验内容 

实现插入排序$(Insertion Sort，IS)$，自顶向下归并排序$(Top-down Mergesort，TDM)$，自底向上归并排序$(Bottom-up Mergesort，BUM)$，随机快速排序$(Random Quicksort，RQ)$，$Dijkstra 3-$路划分快速排序$(Quicksort with Dijkstra 3-way Partition，QD3P)$。在你的计算机上针对**不同输入规模数据**进行实验，对比上述排序算法的时间及空间占用性能。要求对于每次输入运行 $10$ 次，记录每次时间/空间占用，取平均值。 

## 三、 实验方法 

### 1. 时间占用计算 

时间占用使用`JAVA`自带的`system.nanotime()`函数即可。`system.nanotime()`函数返回正在运行的`Java`进程的高精度时间源的当前值，以纳秒为单位。

我们只需在排序进程运行前后各调用一次`system.nanotime()`函数得到其起始时间和结束时间，两者做差即可求出时间占用。

### 2. 空间占用计算 

空间计算需要使用`JAVA runtime`类实例的两个对象函数，即`runtime.freememory()`和`runtime.totalmemory`。

`runtime.freememory()`返回`JVM`的空闲内存量，以字节为单位;

`runtime.totalmemory()`返回`JVM`已经从操作系统那里挖过来的内存大小，即进程当时所被分配的所有内存，以字节为单位; 

由此我们可以得知，`runtime.totalmemory()` − `runtime.freememory()`即为当时所占用的内存大小。与时间占用方法类似，我们只需在排序进程运行前后各求一次所占内存得到其其实占用内存和结束占用内存，两者做差即可求出内存占用。

## 四、 程序设计

### 1．插入排序函数
```java
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

```

### 2．自顶向下归并排序函数
```java
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

```

### 3．自底向上归并排序函数
```java
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

```

### 4．快速排序函数
```java
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

```

### 5．三路划分快速排序函数
```java
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

```

### 6. 测试类(主函数)
```java
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

```
## 五、 实验结果记录 

控制台输出日志：

```txt
请输入测试次数: 10
请输入数组大小: 100000
第 1 轮测试：
插入排序 总用时: 810.90 毫秒, 空间消耗: 0 字节
自顶向下归并排序 总用时: 9.60 毫秒, 空间消耗: 400016 字节
自底向上归并排序 总用时: 17.67 毫秒, 空间消耗: 400016 字节
随机快速排序 总用时: 15.42 毫秒, 空间消耗: 3874096 字节
Dijkstra 3-路划分快速排序 总用时: 15.86 毫秒, 空间消耗: 0 字节

第 2 轮测试：
插入排序 总用时: 815.09 毫秒, 空间消耗: 0 字节
自顶向下归并排序 总用时: 6.81 毫秒, 空间消耗: 400016 字节
自底向上归并排序 总用时: 6.66 毫秒, 空间消耗: 400016 字节
随机快速排序 总用时: 13.35 毫秒, 空间消耗: -13755768 字节
Dijkstra 3-路划分快速排序 总用时: 5.73 毫秒, 空间消耗: 0 字节

第 3 轮测试：
插入排序 总用时: 629.54 毫秒, 空间消耗: 0 字节
自顶向下归并排序 总用时: 7.06 毫秒, 空间消耗: 400016 字节
自底向上归并排序 总用时: 5.76 毫秒, 空间消耗: 400016 字节
随机快速排序 总用时: 10.44 毫秒, 空间消耗: 3778016 字节
Dijkstra 3-路划分快速排序 总用时: 5.94 毫秒, 空间消耗: 0 字节

第 4 轮测试：
插入排序 总用时: 633.95 毫秒, 空间消耗: 0 字节
自顶向下归并排序 总用时: 6.98 毫秒, 空间消耗: 400016 字节
自底向上归并排序 总用时: 5.50 毫秒, 空间消耗: 400016 字节
随机快速排序 总用时: 8.52 毫秒, 空间消耗: 3712656 字节
Dijkstra 3-路划分快速排序 总用时: 7.71 毫秒, 空间消耗: 0 字节

第 5 轮测试：
插入排序 总用时: 636.97 毫秒, 空间消耗: 0 字节
自顶向下归并排序 总用时: 6.72 毫秒, 空间消耗: 400016 字节
自底向上归并排序 总用时: 5.37 毫秒, 空间消耗: 400016 字节
随机快速排序 总用时: 8.39 毫秒, 空间消耗: 3712656 字节
Dijkstra 3-路划分快速排序 总用时: 5.43 毫秒, 空间消耗: 0 字节

第 6 轮测试：
插入排序 总用时: 625.00 毫秒, 空间消耗: 0 字节
自顶向下归并排序 总用时: 7.05 毫秒, 空间消耗: 400016 字节
自底向上归并排序 总用时: 5.58 毫秒, 空间消耗: 567808 字节
随机快速排序 总用时: 9.53 毫秒, 空间消耗: 3778024 字节
Dijkstra 3-路划分快速排序 总用时: 5.46 毫秒, 空间消耗: 0 字节

第 7 轮测试：
插入排序 总用时: 629.32 毫秒, 空间消耗: 0 字节
自顶向下归并排序 总用时: 6.79 毫秒, 空间消耗: 400016 字节
自底向上归并排序 总用时: 5.37 毫秒, 空间消耗: 400016 字节
随机快速排序 总用时: 8.35 毫秒, 空间消耗: 3803072 字节
Dijkstra 3-路划分快速排序 总用时: 5.41 毫秒, 空间消耗: 0 字节

第 8 轮测试：
插入排序 总用时: 619.08 毫秒, 空间消耗: 0 字节
自顶向下归并排序 总用时: 6.97 毫秒, 空间消耗: 400016 字节
自底向上归并排序 总用时: 5.40 毫秒, 空间消耗: 400016 字节
随机快速排序 总用时: 8.58 毫秒, 空间消耗: 3581680 字节
Dijkstra 3-路划分快速排序 总用时: 5.59 毫秒, 空间消耗: 0 字节

第 9 轮测试：
插入排序 总用时: 657.37 毫秒, 空间消耗: 0 字节
自顶向下归并排序 总用时: 6.67 毫秒, 空间消耗: 400016 字节
自底向上归并排序 总用时: 5.43 毫秒, 空间消耗: 400016 字节
随机快速排序 总用时: 8.28 毫秒, 空间消耗: 4207768 字节
Dijkstra 3-路划分快速排序 总用时: 5.41 毫秒, 空间消耗: 0 字节

第 10 轮测试：
插入排序 总用时: 627.15 毫秒, 空间消耗: 0 字节
自顶向下归并排序 总用时: 7.67 毫秒, 空间消耗: 400016 字节
自底向上归并排序 总用时: 5.41 毫秒, 空间消耗: 400016 字节
随机快速排序 总用时: 9.25 毫秒, 空间消耗: 3981704 字节
Dijkstra 3-路划分快速排序 总用时: 5.52 毫秒, 空间消耗: 0 字节

平均耗时和空间消耗（毫秒/字节）：
插入排序 平均耗时: 635.72 毫秒, 平均空间消耗: 0.00 字节
自顶向下归并排序 平均耗时: 6.94 毫秒, 平均空间消耗: 400016.00 字节
自底向上归并排序 平均耗时: 5.51 毫秒, 平均空间消耗: 400016.00 字节
随机快速排序 平均耗时: 9.12 毫秒, 平均空间消耗: 3776420.00 字节
Dijkstra 3-路划分快速排序 平均耗时: 5.61 毫秒, 平均空间消耗: 0.00 字节

```

## 六、 回答问题 

### 1. **在数据处于常数或递增顺序（即，已经排序的数据）情况下，哪种排序表现最好？为什么？**

   在已经排序的数据上，插入排序往往表现最佳。这是因为插入排序在遇到已排序或部分排序的数据时，可以达到近乎线性的时间复杂度。对于已排序的数据，插入排序的每个元素都不需要移动到其他位置，只需比较一次就能找到自己的位置，因此操作次数大大减少。

### 2. **同样的排序算法在大部分已排序的数据上表现如何？为什么？**

   是的，插入排序在大部分已排序的数据上同样表现良好。这是因为即使数据大部分已排序，插入排序也能有效地将每个新元素插入到适当的位置，而不需要进行太多的比较和移动操作。因此，它在这种情况下也能保持较高的效率。

### 3. **总的来说，输入数据的顺序是否影响了排序算法的性能？请引用你表格中的具体数据来支持你的回答。**

   是的，输入数据的顺序显著影响了排序算法的性能。例如，对于插入排序，当输入数据已经排序时，它的性能要远好于数据随机或逆序的情况。而像快速排序这样的算法，在随机数据上的性能通常比在已排序数据上要好，因为已排序的数据可能会导致快速排序的分区不平衡，从而降低效率。

### 4. **在较短的数据集（即，n=1,000）上，哪种排序表现最佳？在较长的数据集（即，n=10,000）上，是否有相同的排序算法表现更好？为什么？请使用你表格中的具体数据来支持你的回答。**

   在较短的数据集上，插入排序和快速排序可能表现较好，因为它们在处理小规模数据时开销较小。但在较长的数据集（n=10,000）上，归并排序或者快速排序可能会表现得更好，因为这些算法在处理大规模数据时更加高效，尽管它们在小数据集上的固定开销可能较大。具体哪种算法表现最好可能依赖于数据的具体特性以及算法的实现细节。

### 5. **总的来说，哪种排序表现更好？给出一个假设，为什么存在性能上的差异。**

   总体而言，快速排序和归并排序在多数情况下可能表现更好，特别是在数据规模较大时。这是因为这些算法能够更好地利用分治策略来减少数据比较和移动的次数。性能上的差异存在是因为不同的排序算法根据数据的不同特性（如数据分布、是否部分排序等）采取了不同的策略，这导致它们在处理特定类型的数据时效率不同。

### 6. **你的表格中是否有看起来不一致的结果？（例如，如果一个排序的运行时间看起来是这样的{1.3, 1.5, 1.6, 7.0, 1.2, 1.6, 1.4, 1.8, 2.0, 1.5}，7.0的条目与其它不一致）。你认为这是为什么？**

   如果表格中出现不一致的结果，可能是由于外部因素或特殊情况的影响。例如，7.0秒的耗时可能是因为以下几个原因：

- **系统负载**：在测试运行时，如果系统负载突然增加（如其他程序占用大量CPU或内存资源），可能会影响排序算法的执行时间。
- **缓存效果**：计算机的缓存策略可能导致某些运行实例的性能突出。如果数据突然不适合缓存，或者缓存失效，也可能导致运行时间异常增长。
- **数据特性**：如果排序的数据集中偶然包含某些特殊的数据模式，可能会对特定排序算法（特别是基于比较的算法如快速排序）产生不利影响，导致性能下降。
- **实现细节**：排序算法的具体实现方式也可能导致性能波动，比如递归深度过大引发的性能问题等。