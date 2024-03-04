import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ10986 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] remainders = new int[N + 1];  // 부분 합을 M으로 나눈 리스트
        int[] remainders_count = new int[M];     // 나머지 개수
        for (int i = 1; i <= N; i++) {
            remainders[i] = (remainders[i - 1] + Integer.parseInt(st.nextToken())) % M;
            remainders_count[remainders[i]] += 1;
        }

        long count = 0;
        for (int i = 0; i < M; i++) {
            count += (long) remainders_count[i] * (remainders_count[i] - 1) / 2;   // 조합
        }

        count += remainders_count[0];  // 나머지가 0일때 (i = j 일때)

        System.out.println(count);
    }
}
