import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ13023 {

    static int N, M;    // 사람의 수, 친구 관계 수
    static List<Integer>[] friends;
    static boolean[] visited;   // 방문한 노드인지
    static boolean isExist = false;

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        friends = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            friends[i] = new ArrayList<>();
        }
        visited = new boolean[N+1];

        // 양방향 친구관계 맺어주기
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            friends[a].add(b);
            friends[b].add(a);
        }

        for (int i = 0; i < N; i++) {
            dfs(i, 1);
            if (isExist) break;
        }

        int answer = isExist ? 1 : 0;
        System.out.println(answer);
    }

    public static void dfs(int personId, int depth) {
        if (depth >= 5 || isExist) {
            isExist = true;
            return;
        }

        visited[personId] = true;
        for (int i : friends[personId]) {
            if (!visited[i]) {
                dfs(i, depth + 1);
            }
        }
        visited[personId] = false;
    }
}
