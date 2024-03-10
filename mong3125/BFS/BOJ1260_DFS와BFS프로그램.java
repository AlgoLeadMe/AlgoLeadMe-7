import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ1260_DFS와BFS프로그램 {

    static ArrayList<Integer>[] edges;
    static boolean[] visited;
    static StringBuilder answer = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());   // 노드 수
        int m = Integer.parseInt(st.nextToken());   // 간선 수
        int v = Integer.parseInt(st.nextToken());   // 출발 노드

        edges = new ArrayList[n + 1];   // 간선 배열
        for (int i = 0; i < n + 1; i++) {
            edges[i] = new ArrayList<>();
        }

        // 간선 연결
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            edges[a].add(b);
            edges[b].add(a);
        }

        for (int i = 0; i < n + 1; i++) {
            Collections.sort(edges[i]);
        }

        visited = new boolean[n + 1];       // 방문 여부 배열
        dfs(v);
        answer.append('\n');

        visited = new boolean[n + 1];
        bfs(v);
        answer.append('\n');

        System.out.print(answer);
    }

    public static void dfs(int now) {
        answer.append(now);
        answer.append(' ');

        visited[now] = true;

        for (int next : edges[now]) {
            if (!visited[next]) {
                dfs(next);
            }
        }
    }

    public static void bfs(int start) {
        Queue<Integer> queue = new LinkedList<>();

        // 시작 노드 삽입하기
        queue.add(start);
        visited[start] = true;

        // 큐가 빌때까지 반복
        while (!queue.isEmpty()) {
            int now = queue.poll();
            answer.append(now);
            answer.append(' ');

            // now에 연결된 node들을 queue에 삽입한다.
            for (int next : edges[now]) {
                if (!visited[next]) {
                    queue.add(next);
                    visited[next] = true;
                }
            }
        }
    }
}
