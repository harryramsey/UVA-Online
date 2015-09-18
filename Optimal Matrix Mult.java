import java.util.*;
 
public class Main {
	
	static int[][] s = new int[6][6];
	
	public static int memoized_matrix_chain(int[] p){
		int n = (p.length/2)-1;
		int[][] m = new int[n+1][n+1];
		for (int i = 0; i <= n; i++){
			for (int j = i; j <= n; j++){
				m[i][j] = Integer.MAX_VALUE;
			}
		}
		return lookup_chain(m,p,0,n);
	}
	
	public static int lookup_chain(int[][] m, int[] p, int i, int j){
		if (m[i][j] < Integer.MAX_VALUE){
			return m[i][j];
		}
		if (i == j){
			m[i][j] = 0;
		}
		else{
			for (int k = i; k < j; k++){
				int q = lookup_chain(m,p,i,k)+lookup_chain(m,p,k+1,j)+p[i*2]*p[(k*2)+1]*p[(j*2)+1];
				if (q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
		return m[i][j];
	}
	 
	public static void print_optimal(int i, int j){
		if (i == j) System.out.print("A"+i);
		else{
			System.out.print("(");
			print_optimal(i,s[i][j]);
			print_optimal(s[i][j]+1,j);
			System.out.print(")");
		}
	}
		
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] p = {30,35,35,15,15,5,5,10,10,20,20,25};
        int min = memoized_matrix_chain(p);
        System.out.println(min);
        print_optimal(0,5);
        
    }
}
