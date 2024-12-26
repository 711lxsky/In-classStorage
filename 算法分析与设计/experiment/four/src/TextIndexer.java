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
