import java.util.*;
 
public class Main {
	 
	static int path[];
	static int soltns;
	static int N;
	
	public static void Hamilton(int[][] vertices, boolean[] used, int node, int level){
		if (level == N-1 && soltns == 0){
			for (int i = 0; i < N; i++){
				if (vertices[path[level]][i] == path[0]){
					for (int j = 0; j < N; j++){
						System.out.printf("%d ", path[j]+1);
					}
					System.out.println(path[0]+1);
					soltns++;
					break;
				}
			}
			return;
		}
		if (soltns == 0){
			for (int i = 0; i < N; i++){
				int v = vertices[node][i];
				if (v != -1 && !used[v]){
					used[v] = true;
					path[level+1] = v;
					Hamilton(vertices,used,v,level+1);
					used[v] = false;
				}
			}
		}
	}
	
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while(scanner.hasNextLine()){
        	String line = scanner.nextLine();
        	N = Integer.parseInt(line);
        	int[][] vertices = new int[N][N];
        	int[] numEdges = new int[N];
        	boolean[] used = new boolean[N];
       		used[0] = true;
        	path = new int[N];
        	soltns = 0;
        	
        	for (int i = 0; i < N; i++){
        		for (int j = 0; j < N; j++){
        			vertices[i][j] = -1;
        		}
        	}
        	line = scanner.nextLine();
        	while (!line.equals("%")){
        		String[] edge = line.split(" ");
        		int v =  Integer.parseInt(edge[0])-1;
        		int w = Integer.parseInt(edge[1])-1;
        		vertices[v][numEdges[v]++] = w;
        		vertices[w][numEdges[w]++] = v;
        		line = scanner.nextLine();
        	}
        	
       		Hamilton(vertices,used,0,0);
        	if (soltns == 0) System.out.println("N");
        }
    }
}

