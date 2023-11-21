import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static StringBuilder res = new StringBuilder();


    public static void main(String[] args) throws Exception {
        int n = Integer.parseInt(br.readLine());
        int[][] matrix = new int[n][];

        for (int i = 0; i < n; i++) {
            matrix[i] = getInts();
        }

        solution(matrix);

        printRes();
    }

    private static void solution(int[][] matrix) {
        int n = matrix.length;
        int m = 1 << n;

        int[][] DP = new int[n][m];
        for (int[] row : DP) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }
        for (int i = 0; i < n; i++) {
            DP[0][1 << i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    if ((j >> k & 1) == 1) {
                        DP[i][j] = Math.max(DP[i][j], DP[i - 1][(j) - (1 << k)] + matrix[i][k]);
                    }
                }
            }
        }

        res.append(Arrays.stream(DP[n - 1]).max().getAsInt());
    }


    private static int[] getInts() throws IOException {
        return Arrays.stream(br.readLine().split("\\s+"))
                .mapToInt(Integer::parseInt)
                .toArray();
    }

    private static long[] getLongs() throws IOException {
        return Arrays.stream(br.readLine().split("\\s+"))
                .mapToLong(Long::parseLong)
                .toArray();
    }


    public static void printRes() throws IOException {
        bw.write(res.toString());
        bw.close();
    }
}