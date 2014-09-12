import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Ordering {
	
	public static void add_edge(int[][] graph, int v, int w){
		graph[v-1][w-1] = 1;
	}
	
	public static int[] indegree(int[][] graph){
		int M = graph.length;
		int[] indegree = new int[M];
		for (int i = 0; i < M; i++){
			for (int j = 0; j < M; j++){
				if (graph[i][j] == 1){
					indegree[j] += 1;
				}
			}
		}
		return indegree;
	}
	
	public static void top_sort(int[][] graph){
		Queue<Integer> q = new LinkedList<Integer>();
		int[] indegree = indegree(graph);
		
		for (int i = 0; i < indegree.length; i++){
			if (indegree[i] == 0){
				q.add(i);
			}
		}
		
		while (!q.isEmpty()){
			int v = q.remove();
			System.out.print((v+1) + " ");
			for (int i = 0; i < graph.length; i++){
				if (graph[v][i] == 1){
					indegree[i]--;
					if (indegree[i] == 0){
						q.add(i);
					}
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int m,n, v, w, count = 0;
		while (true){
			m = scanner.nextInt();
			n = scanner.nextInt();
			if (m == 0 && n == 0) break;
			if (count != 0){
				System.out.print('\n');
			}
			int[][] graph = new int[m][m];
			for (int i = 0; i < n; i++){
				v = scanner.nextInt();
				w = scanner.nextInt();
				add_edge(graph,v,w);
			}
			top_sort(graph);
			count++;
		}
	}
}
