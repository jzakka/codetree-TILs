import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static StringBuilder res = new StringBuilder();


    public static void main(String[] args) throws Exception {
        int n = Integer.parseInt(br.readLine());
        int[][] A = new int[n][];
        for (int i = 0; i < n; i++) {
            A[i] = Arrays.stream(getInts()).map(j -> {
                if (j == 0) {
                    return Integer.MAX_VALUE / 2;
                }
                return j;
            }).toArray();
        }

        solution(n, A);

        printRes();
    }

    private static void solution(int n, int[][] A) {
        int m = 1 << n;
        int[][] DP = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                DP[i][j] = Integer.MAX_VALUE / 2;
            }
        }
        for (int i = 1; i < n; i++) {
            DP[1 << i][i] = A[i][0];
        }

        for (int visited = 0; visited < m; visited++) {
            for (int i = 0; i < n; i++) {
                if ((visited >> i & 1) == 1) {
                    int remain = visited - (1 << i);
                    for (int j = 0; j < n; j++) {
                        if ((remain >> j & 1) == 1) {
                            DP[visited][i] = Math.min(DP[visited][i], DP[remain][j] + A[i][j]);
                        }
                    }
                }
            }
        }

        res.append(DP[m - 1][0]);
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