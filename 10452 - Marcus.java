import java.util.Scanner;
 
public class Main {
	
	static char[] arr = {'I','E','H','O','V','A'};
	static boolean[] used = {false,false,false,false,false,false};

	static void escape(int m, int n, char[][] lines, int x, int y)
	{

		for (int i = 0; i < 6; i++){
			if (x-1 >= 0 && lines[x-1][y] == arr[i] && !used[i]){
				used[i] = true;
				System.out.print("forth ");
				escape(m,n,lines,x-1,y);
			}
			else if (x-1 >= 0 && lines[x-1][y] == '#'){
				System.out.print("forth\n");
				return;
			}
			else if (y+1 < n && lines[x][y+1] == arr[i] && !used[i]){
				used[i] = true;
				System.out.print("right ");
				escape(m,n,lines,x,y+1);
			}
			else if (y+1 < n && lines[x][y+1] == '#'){
				System.out.print("right\n");
				return;
			}
			else if (y-1 >= 0 && lines[x][y-1] == arr[i] && !used[i]){
				used[i] = true;
				System.out.print("left ");
				escape (m,n,lines,x,y-1);
			}
			else if (y-1 >= 0 && lines[x][y-1] == '#'){
				System.out.print("left\n");
				return;
			}
		}
	}
 
    public static void main(String[] args){
       Scanner scanner = new Scanner(System.in);
       int N = scanner.nextInt();
       int j;
       
       for (int i = 0; i < N; i++){
    	   int m = scanner.nextInt();
    	   int n = scanner.nextInt();
    	   char[][] lines = new char[m][n];
    	   
    	   for (j = 0; j < 6; j++){
    		   used[j] = false;
    	   }
    	   
    	   for (j = 0; j < m; j++){
    		   String str = scanner.next();
    		   for (int k = 0; k < n; k++){
    			   lines[j][k] = str.charAt(k);
    		   }
    	   }
    	   
    	   for (j = 0; j < n; j++){
       		if (lines[m-1][j] == '@'){
       			break;
       		}
       	}
    	   escape(m,n,lines,m-1,j);
       }
    }
}
