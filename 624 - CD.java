import java.util.Scanner;
 
public class Main {
	
	static int[] S = new int[21];
	static boolean[] used = new boolean[21];
	static int N;
	static int d;
	static boolean soltn;
	static int numSoltns;
	
	public static void print_soltn(){
		if (numSoltns == 0){
			for (int i = 1; i <= N; i++){
				if (used[i]){
					System.out.printf("%d ", S[i]);
				}
			}
			System.out.println("sum:" + d);
			soltn = true;
			numSoltns++;
		}
	}
	
	public static boolean isPromising(int pos, int currSum, int rem){
		if (currSum + rem < d || currSum > d){
			return false;
		}
		return true;
	}
	
	public static void backtrack(int pos, int currSum, int rem){
		if (pos == N){
			if (currSum == d){
				print_soltn();
			}
			return;
		}
		if (isPromising(pos+1,currSum+S[pos+1],rem-S[pos+1])){
			used[pos+1] = true;
			backtrack(pos+1,currSum+S[pos+1],rem-S[pos+1]);
		}
		used[pos+1] = false;
		if (isPromising(pos+1,currSum,rem-S[pos+1])){
			backtrack(pos+1,currSum,rem-S[pos+1]);
		}
	}
 
    public static void main(String[] args){
       Scanner scanner = new Scanner(System.in);
       while (scanner.hasNextInt()){
    	   d = scanner.nextInt();
    	   N = scanner.nextInt();
    	   soltn = false;
    	   numSoltns = 0;
    	   S[0] = 0;
    	   int sum = 0;
    	   
    	   for (int i = 1; i <= N; i++){
    		   int trackLength = scanner.nextInt();
    		   S[i] = trackLength;
    		   sum += trackLength;
    	   }
    	   for (int i = 1; i <= N; i++){
    		   used[i] = false;
    	   }
    	   if (d > sum){
    		   d = sum;
    	   }
    	   while (!soltn){
    		   backtrack(0,0,sum);
    		   d--;
    	   }
       }
    }
}
