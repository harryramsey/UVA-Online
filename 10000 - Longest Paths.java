import java.util.Scanner;

class Main {
	
	static int[][] graph = new int[105][105];
	static int caseNum = 1;
	
	public static void floyd_warshall(int n){
		for (int i = 0; i < n; i++){
			graph[i][i] = 0;
		}
		
		for (int k = 0; k < n; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					graph[i][j] = Math.max(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}
	
	public static void findSoltn(int s, int n){
		int max = -10000;
		int vertex = s;
		
		for (int i = 0; i < n; i++){
			if (graph[s][i] > max){
				max = graph[s][i];
				vertex = i;
			}
		}
		System.out.printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",caseNum++,s+1,max,vertex+1);
		System.out.println();
	}
	
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int n,x,s,y;
		
		while (scanner.hasNextInt()){
			n = scanner.nextInt();
			if (n == 0) break;
			s = scanner.nextInt();
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					graph[i][j] = -100;
				}
			}
			
			while (scanner.hasNextInt()){
				x = scanner.nextInt();
				y = scanner.nextInt();
				if (x == 0 && y == 0) break;
				graph[x-1][y-1] = 1;
			}
			floyd_warshall(n);
			findSoltn(s-1,n);
			
		}
	}
}
