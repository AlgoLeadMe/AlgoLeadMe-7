package CH05_탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P023_11724 {
    static int N, M;
    static boolean[][] edges;
    static boolean[] cache;

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 노드의 수, 엣지의 수 입력
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        edges = new boolean[N + 1][N + 1];
        cache = new boolean[N + 1];

        // 엣지 입력
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            // 양방향 입력
            edges[a][b] = true;
            edges[b][a] = true;
        }

        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (dfs(i)) {
                count++;
            }
        }

        System.out.println(count);

        br.close();
    }

    public static boolean dfs(int id) {
        if (cache[id]) return false;

        cache[id] = true;

        for (int i = 1; i <= N; i++) {
            if (edges[id][i]) {
                dfs(i);
            }
        }

        return true;
    }
}
