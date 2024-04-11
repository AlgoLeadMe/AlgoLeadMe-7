package 그래프;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ7569_토마토 {

    static int M, N, H;
    static int[][][] box;

    static Queue<int[]> ripen = new LinkedList<>();   // 익은 토마토 위치
    static int notRipenTomatos = 0;
    static int result = 1;
    static int[][] directions = {
            {1, 0, 0},
            {-1, 0, 0},
            {0, 1, 0},
            {0, -1, 0},
            {0, 0, 1},
            {0, 0, -1},
    };

    public static void main(String[] args) throws IOException {
        // == 입력 == //
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        box = new int[H][N][M];

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < M; k++) {
                    box[i][j][k] = Integer.parseInt(st.nextToken());

                    // 익은 토마토 위치 저장
                    if (box[i][j][k] == 1) ripen.add(new int[]{i, j, k});
                    else if (box[i][j][k] == 0) notRipenTomatos++;
                }
            }
        }

        // == 풀이 == //
        bfs();

        // 모든 토마토가 익은게 아니라면 -1 반환
        if (notRipenTomatos > 0) {
            result = 0;
        }

        // == 출력 == //
        System.out.println(result - 1);
    }

    public static void bfs() {
        while (!ripen.isEmpty()) {
            int[] tomato = ripen.remove();
            for (int[] direction : directions) {
                int z = tomato[0] + direction[0];
                int y = tomato[1] + direction[1];
                int x = tomato[2] + direction[2];

                if (isInRange(z, y, x)) {
                    if (box[z][y][x] == 0) {
                        box[z][y][x] = box[tomato[0]][tomato[1]][tomato[2]] + 1;
                        result = Math.max(result, box[z][y][x]);
                        notRipenTomatos--;

                        ripen.add(new int[]{z, y, x});
                    }
                }
            }
        }
    }

    public static boolean isInRange(int z, int y, int x) {
        return (x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < H);
    }
}
