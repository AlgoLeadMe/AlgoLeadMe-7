package DFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ1167_트리의지름구하기 {

    static ArrayList<Edge>[] edges;
    static boolean[] visited;
    static int max;
    static int farthest;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int V = Integer.parseInt(br.readLine());
        edges = new ArrayList[V + 1];
        for (int i = 0; i < V + 1; i++) {
            edges[i] = new ArrayList<>();
        }

        for (int i = 0; i < V; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());

            while (true) {
                int node = Integer.parseInt(st.nextToken());
                if (node == -1) break;

                int cost = Integer.parseInt(st.nextToken());
                edges[a].add(new Edge(node, cost));
            }
        }

        max = 0;
        visited = new boolean[V+1];
        dfs(1, 0);

        max = 0;
        visited = new boolean[V+1];
        dfs(farthest, 0);

        System.out.println(max);
    }

    public static void dfs(int node, int cost) {
        visited[node] = true;
        if (cost > max) {
            farthest = node;
            max = cost;
        }

        for (Edge edge : edges[node]) {
            if (!visited[edge.node]) {
                dfs(edge.node, cost + edge.cost);
            }
        }
    }

    static class Edge {
        int node;
        int cost;

        public Edge(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }
    }
}
