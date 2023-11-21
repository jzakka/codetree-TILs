import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static StringBuilder res = new StringBuilder();


    public static void main(String[] args) throws Exception {
        int n = Integer.parseInt(br.readLine());

        solution(n);

        printRes();
    }

    private static void solution(int n) {
        int[] seq = IntStream.rangeClosed(-n, -1).toArray();
        do {
            Arrays.stream(seq).forEach(i -> res.append(-i).append(" "));
            res.append("\n");
        } while (nextPermutation(seq));
    }

    private static boolean nextPermutation(int[] seq) {
        int n = seq.length;

        for (int i = n-1; i >= 1; i--) {
            if (seq[i - 1] < seq[i]) {
                int minIdx = i;
                int minVal = Integer.MAX_VALUE;
                for (int j = i; j < n; j++) {
                    if (seq[j] > seq[i-1] && seq[j] < minVal) {
                        minVal = seq[j];
                        minIdx = j;
                    }
                }

                if (minVal < Integer.MAX_VALUE) {
                    seq[minIdx] = seq[i-1];
                    seq[i-1] = minVal;
                    Arrays.sort(seq, i, n);
                    return true;
                }
            }
        }

        return false;
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