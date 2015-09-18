import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	static BigInteger one = new BigInteger("-1");
	
	public static BigInteger solve(BigInteger[][] dp, String word1, String word2, int i, int j){
		if (dp[i][j] != one){
			return dp[i][j];
		}
		else if (word1.charAt(i-1) == word2.charAt(j-1)){
			dp[i][j] = solve(dp,word1,word2,i-1,j-1).add(solve(dp,word1,word2,i,j-1));
		}
		else {
			dp[i][j] = solve(dp,word1,word2,i,j-1);
		}
		return dp[i][j];
	}
	
	public static void initialize(BigInteger[][] dp){
		for (int i = 0; i < dp.length; i++){
			for (int j = 0; j < dp[0].length; j++){
				dp[i][j] = one;
			}
		}
		for (int i = 0; i < dp.length; i++){
			dp[i][0] = BigInteger.ZERO;
		}
		for (int j = 0; j < dp[0].length; j++){
			dp[0][j] = BigInteger.ONE;
		}
	}
	
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		
		for (int i = 0; i < N; i++){
			String word1 = scanner.next();
			String word2 = scanner.next();
			BigInteger[][] dp = new BigInteger[word2.length()+1][word1.length()+1];
			initialize(dp);
			System.out.println(solve(dp,word2,word1,word2.length(),word1.length()));
		}
	}
}
