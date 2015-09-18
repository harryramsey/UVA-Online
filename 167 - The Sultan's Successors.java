import java.util.*;
 
public class Main {
   
	static int N = 8;
	static int soltns = 0;
	static int[] Queens = new int[8];
	static int[][] boardConfigs = new int[92][8];
	
	public static void findSafeCol(int row){
		if (row == N){
			for (int i = 0; i < 8; i++){
				boardConfigs[soltns][i] = Queens[i];
			}
			soltns++;
			return;
		}
		for (int j = 0; j < N; j++){
			boolean legal_move = true;
			for (int i = 0; i < row; i++){
				if (Queens[i] == j || Queens[i] == j+row-i || Queens[i] == j-row+i){
					legal_move = false;
					break;
				}
			}
			if (legal_move){
				Queens[row] = j;
				findSafeCol(row+1);
			}
		}
	}
	
	public static int positionVal(int n, int[][] values){
		int sum = 0;
		for (int i = 0; i < 8; i++){
			int col = boardConfigs[n][i];
			sum += values[i][col];
		}
		return sum;
	}
 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
	    findSafeCol(0);
	    
	    int N = scanner.nextInt();
	    for (int i = 0; i < N; i++){
	    	int[][] values = new int[8][8];
	    	for (int j = 0; j < 8; j++){
	    		for (int k = 0; k < 8; k++){
	    			values[j][k] = scanner.nextInt();
	    		}
	    	}
		    int max = -1;
		    for (int j = 0; j < 92; j++){
		    	int sum = positionVal(j,values);
		    	if (sum > max){
		    		max = sum;
		    	}
		    }
		    System.out.printf("%5d\n",max);
	    }
    }
}

