package 이진탐색;

import java.util.Scanner;

public class BOJ1300_K번째수 {
    static int n;
    static int k;
    static int answer;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();

        index(0, k);
        System.out.println(answer);
    }

    public static void index(int front, int back) {
        if (front > back) return;

        int mid = (front + back) / 2;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += Math.min(mid / i, n);
        }

        if (sum < k) {
            index(mid + 1, back);
        } else {
            answer = mid;
            index(front, mid - 1);
        }
    }
}
