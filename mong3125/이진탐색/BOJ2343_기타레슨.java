package 이진탐색;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class BOJ2343_기타레슨 {

    static int N;
    static int M;
    static int[] lectures;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        lectures = new int[N];
        st = new StringTokenizer(br.readLine());

        int sum = 0;
        int max = 0;
        for(int i = 0; i < N; i++) {
            lectures[i] = Integer.parseInt(st.nextToken());
            sum += lectures[i];
            max = Math.max(max, lectures[i]);
        }

        // 블루레이의 크기는 max부터 sum 사이 일것이다.
        int result = minimumBlueray(max, sum);

        System.out.println(result);
    }

    public static int minimumBlueray(int start, int end) {
        if (start < end) return -1;

        int mid = (start + end) / 2;

        if (can(mid)) {
            int more = minimumBlueray(start, mid - 1);
            return more != -1 ? more : mid;
        }
        else return minimumBlueray(mid + 1, end);
    }

    public static boolean can(int blueray) {
        int count = M;
        int i = 0;
        int stack = blueray;
        while (count > 0) {
            while (stack - lectures[i] > 0) {
                if (i == N) return true;
                stack -= lectures[i];
                i++;
            }

            stack = blueray;
            count--;
        }

        return false;
    }
}
