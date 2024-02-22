package CH05_탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ_11724 {
    static int N, M;
    static int[][] edges;
    static int[] cache;

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 노드의 수, 엣지의 수 입력
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        edges = new int[N + 1][N + 1];
        cache = new int[N + 1];

        // 엣지 입력
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            // 양방향 입력
            edges[a][b] = 1;
            edges[b][a] = 1;
        }

        // 개수 세기
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (dfs(i, i)) {
                count++;
            }
        }

        System.out.println(count);

        br.close();
    }

    public static boolean dfs(int id, int check) {
        // 이미 왔었던 노드일때 false 반환
        if (cache[id] != 0) return false;

        // 영역 표시
        cache[id] = check;

        // 엣지를 찾아서 dfs 방식으로 다음 노드를 찾아서 반복
        for (int i = 1; i <= N; i++) {
            if (edges[id][i] == 1) {
                dfs(i, check);
            }
        }

        // 새로운 영역을 발견했을때 true 반환
        return true;
    }
}
