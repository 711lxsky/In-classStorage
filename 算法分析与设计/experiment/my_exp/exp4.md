## 实验四 文本索引(Text Indexing)

## 一、 实验目的 

编写一个构建大块文本索引的程序，然后进行快速搜索，来查找某个字符串在该文本中的出现位置。 

## 二、 实验内容 

例如，有两个文本文件，分别为 $corpus.txt$ 和 $pattern.txt$。$corpus.txt$ 文件中存有大量文本，$pattern.txt$ 存有一些字符串，以换行分隔。我们的任务是找到 $patterns.txt$ 中的每个字符串在 $corpus.txt$ 文本中首次出现的位置并输出。 

例如 $corpus.txt$ 文本如下:

it was the best of times it was the worst of times it was the age of wisdom it was the age of foolishness it was the epoch of belief it was the epoch of incredulity it was the season of light it was the season of darkness it was the spring of hope it was the winter of despair 

$patterns.txt$ 文本如下:


wisdom  
season  
age of foolishness 
age of fools  

最终查询输出如下:

18 wisdom 

40 season 

22 ge of foolishness 

23 age of fools 

Wisdom 出现在位置18，season 出现在位置40，age of foolishness 出现在位置22，age of fools 未出现。 

## 三、 实验方法 

有很多种算法可以用来解决这个问题，这些方法都有着不同的时间复杂度和空间复杂度。 

首先我们可以考虑暴力搜索(Brute-Force)算法。这种方法不需要建立指针,只用在corpus 语料库中搜索patterns 中的每一个字符串即可。如果corpus 语料库很小或者待查询的字符串不多,这种方法是很好的。一旦corpus 很大或待查询的字符串很多,这种方法就十分低效。 

一种快速搜索的方法是在语料库(每个字符位置一个指针)上进行指针排序,然后使用折半搜索(binary search)。这种方法需要构建指针索引,按照排序顺序访问关键字,并找出调用bsearch 的必要接口使用索引执行查询。 

我将使用后一种完成实验

## 四、 源代码
```java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class TextIndexer {

    /**
     * 位置类，用于存储字符在语料库中的位置及其查询结果索引。
     */
    private static class Position {
        int index; // 字符在语料库中的位置
        int resultIndex; // 记录查询结果索引，便于排序和打印

        Position(int index, int resultIndex) {
            this.index = index;
            this.resultIndex = resultIndex;
        }
    }

    public static void main(String[] args) throws IOException {
//        if (args.length != 2) {
//            System.out.println("Usage: java TextIndexer <corpus_file> <query_file>");
//            return;
//        }

        String corpusFileName = "D:\\WorkSpace\\XDU\\AlgorithmAnalasis\\experiment\\four\\source.txt"; // 语料库文件路径
        String corpus = readFile(corpusFileName); // 读取语料库文件
        String queryFileName = "D:\\WorkSpace\\XDU\\AlgorithmAnalasis\\experiment\\four\\query.txt"; // 查询文件路径
        String[] queries = readQueries(queryFileName); // 读取查询文件

        Position[] positions = createPositions(corpus); // 创建指针数组
        Arrays.sort(positions, new PositionComparator(corpus)); // 对指针数组进行排序

        searchQueries(corpus, queries, positions); // 搜索查询并打印结果
    }

    /**
     * 读取文件内容为字符串。
     *
     * @param filePath 文件路径
     * @return 文件内容字符串
     * @throws IOException 如果读取文件时发生错误
     */
    private static String readFile(String filePath) throws IOException {
        StringBuilder content = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                content.append(line).append(" ");
            }
        }
        return content.toString().trim();
    }

    /**
     * 读取查询文件，每行为一个查询。
     *
     * @param filePath 查询文件路径
     * @return 查询字符串数组
     * @throws IOException 如果读取文件时发生错误
     */
    private static String[] readQueries(String filePath) throws IOException {
        ArrayList<String> queries = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                queries.add(line);
            }
        }
        return queries.toArray(new String[0]);
    }

    /**
     * 创建指针数组。
     *
     * @param corpus 语料库字符串
     * @return 指针数组
     */
    private static Position[] createPositions(String corpus) {
        Position[] positions = new Position[corpus.length()];
        for (int i = 0; i < corpus.length(); i++) {
            positions[i] = new Position(i, -1);
        }
        return positions;
    }

    /**
     * 搜索每个查询并打印结果。
     *
     * @param corpus 语料库字符串
     * @param queries 查询字符串数组
     * @param positions 指针数组
     */
    private static void searchQueries(String corpus, String[] queries, Position[] positions) {
        for (String query : queries) {
            Position result = binarySearch(corpus, query, positions);
            if (result != null) {
                System.out.println(result.index + " " + query);
            } else {
                System.out.println("-- " + query);
            }
        }
    }

    /**
     * 二分搜索查询。
     *
     * @param corpus 语料库字符串
     * @param query 查询字符串
     * @param positions 指针数组
     * @return 匹配的指针位置，如果没有匹配则返回 null
     */
    private static Position binarySearch(String corpus, String query, Position[] positions) {
        int left = 0;
        int right = positions.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cmp = compare(corpus, positions[mid].index, query);
            if (cmp == 0) {
                return positions[mid];
            } else if (cmp < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return null;
    }

    /**
     * 比较函数，用于二分搜索。
     *
     * @param corpus 语料库字符串
     * @param index 指针位置
     * @param query 查询字符串
     * @return 比较结果
     */
    private static int compare(String corpus, int index, String query) {
        for (int i = 0; i < query.length(); i++) {
            if (index + i >= corpus.length() || corpus.charAt(index + i) != query.charAt(i)) {
                return corpus.charAt(index + i) - query.charAt(i);
            }
        }
        return 0;
    }

    /**
         * 指针比较器，用于排序。
         */
        private record PositionComparator(String corpus) implements Comparator<Position> {

        @Override
            public int compare(Position a, Position b) {
                int minLength = Math.min(corpus.length() - a.index, corpus.length() - b.index);
                for (int i = 0; i < minLength; i++) {
                    char charA = corpus.charAt(a.index + i);
                    char charB = corpus.charAt(b.index + i);
                    if (charA != charB) {
                        return charA - charB;
                    }
                }
                return a.index - b.index;
            }
        }
}

```

## 五、实验结果
```txt
69 wisdom
203 season
87 age of foolishness
-- age of fools
```

## 六、实验体会

通过本次实验，我对文本索引和快速搜索算法有了更深入的理解。以下是我在实验过程中的一些体会：

1. **算法选择的重要性**：
   - 在实验初期，我考虑了多种算法，包括暴力搜索和基于指针排序的二分搜索。通过对比，我发现暴力搜索虽然简单易实现，但在处理大规模数据时效率低下。而基于指针排序的二分搜索虽然实现较为复杂，但能够显著提高搜索速度，特别是在处理大量查询时。

2. **数据结构的设计**：
   - 为了实现高效的搜索，我设计了一个 `Position` 类来存储字符在语料库中的位置及其查询结果索引。这使得在排序和搜索过程中能够方便地获取和处理相关信息。同时，使用 `PositionComparator` 来对指针数组进行排序，确保了搜索的高效性。

3. **文件读取与处理**：
   - 在读取文件内容时，我使用了 `BufferedReader` 来逐行读取文件，并将其拼接成一个完整的字符串。这种方式不仅提高了读取效率，还避免了内存溢出的问题。此外，通过将查询文件中的每一行转换为查询字符串数组，简化了后续的搜索逻辑。

4. **二分搜索的实现**：
   - 二分搜索是本次实验的核心部分。通过对指针数组进行排序，并使用二分搜索算法，我能够在较短的时间内找到查询字符串在语料库中的位置。在实现过程中，我特别注意了边界条件的处理，确保了搜索的准确性。

5. **调试与优化**：
   - 在实验过程中，我遇到了一些调试问题，如指针越界和比较函数的实现细节。通过逐步调试和优化，我最终解决了这些问题，确保了程序的稳定性和正确性。此外，我还对代码进行了适当的注释，提高了代码的可读性和可维护性。

6. **实际应用的思考**：
   - 通过本次实验，我认识到文本索引和快速搜索算法在实际应用中的重要性。例如，在搜索引擎、数据库查询等领域，高效的文本索引和搜索算法能够显著提升系统的性能和用户体验。未来，我将继续学习和探索更多高级的文本处理技术，以应对更复杂的实际问题。

通过这次实验，我不仅巩固了理论知识，还提升了实际编程能力和问题解决能力。希望在今后的学习和工作中，能够将这些经验和技能应用到更多的实际项目中。

