package 이진탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ1920_수찾기 {

    static int[] A;
    static int[] targets;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        A = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < A.length; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int M = Integer.parseInt(br.readLine());
        targets = new int[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < targets.length; i++) {
            targets[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(A);

        for (int i = 0; i < targets.length; i++) {
            int now = targets[i];
            System.out.println(binary(0, A.length - 1, now) ? 1 : 0);
        }
    }

    public static boolean binary(int from, int to, int n) {
        if (from > to) return false;
        int mid = (from + to) / 2;

        if (A[mid] == n) return true;
        else if (A[mid] > n) return binary(from, mid - 1, n);
        else return binary(mid + 1, to, n);
    }
}
