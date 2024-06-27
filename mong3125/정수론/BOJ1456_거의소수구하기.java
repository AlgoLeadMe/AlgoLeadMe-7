package 정수론;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ1456_거의소수구하기 {
    static long A, B;
    static boolean[] isPrime;
    public static void main(String[] args) {
        // 입력
        Scanner sc = new Scanner(System.in);
        A = sc.nextLong();
        B = sc.nextLong();
        isPrime = new boolean[10000001];

        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i < 10000001; i++) {
            if (!isPrime[i]) continue;

            for (int j = i+i; j < 10000001; j += i) {
                isPrime[j] = false;
            }
        }

        int count = 0;
        int max = (int) Math.min(10000001, Math.sqrt(B));
        for (int i = 2; i < max; i++) {
            if (isPrime[i]) {
                long now = i;
                while ((double) i <= (double) B / (double) now) {
                    if ((double) i >= (double) A / (double) now) count += 1;
                    now *= i;
                }
            }
        }

        System.out.println(count);
    }
}
