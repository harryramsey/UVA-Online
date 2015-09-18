import java.util.*;
 
public class Main {
	
	static int[][] c;
	
	public static int memoized_lcs(String str1, String str2){
		int m = str1.length();
		int n = str2.length();
		c = new int[m+1][n+1];
		
		for (int i = 0; i <= m; i++){
			for (int j = 0; j <= n; j++){
				c[i][j] = Integer.MAX_VALUE;
			}
		}
		return lcs(str1,str2,m,n);
	}
	
	public static int lcs(String str1, String str2, int i, int j){
		if (c[i][j] < Integer.MAX_VALUE){
			return c[i][j];
		}
		if (i == 0 || j == 0){
			c[i][j] = 0;
		}
		else if (str1.charAt(i-1) == str2.charAt(j-1)){
			c[i][j] = 1+lcs(str1,str2,i-1,j-1);
		}
		else c[i][j] = Math.max(lcs(str1,str2,i-1,j),lcs(str1,str2,i,j-1));
		return c[i][j];
	}
		
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()){
			String word1 = scanner.nextLine();
			String word2 = scanner.nextLine();
			System.out.println(memoized_lcs(word1,word2));
		}
    }
}

