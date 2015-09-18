import java.util.Scanner;

public class Main {

	int[] S = {0,6,5,7,3};
	boolean[] used = new boolean[S.length];
	int N = S.length-1;
	int d = 15;

	public void print_soltn(){
		for (int i = 1; i <= N; i++){
			if (used[i]){
				System.out.printf("%d ", S[i]);
			}
		}
		System.out.println("-->" + d);
	}

	public boolean isPromising(int pos, int currSum, int rem){
		if (currSum + rem < d || currSum > d){
			return false;
		}
		return true;
	}

	public void backtrack(int pos, int currSum, int rem){
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
       Main m = new Main();
       int sum = 0;
       for (int i = 0; i < m.S.length; i++){
    	   sum += m.S[i];
       }
       m.backtrack(0, 0, sum);
    }
}
