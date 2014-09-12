package Combinatorics;

import java.math.BigInteger;
import java.util.Scanner;

public class PiecesOfLand {
	
	public static BigInteger binomial(int n, int k)
    {
        if (n < k){
        	return new BigInteger("0");
        }
		if (k>n-k){
            k=n-k;
        }
        BigInteger b = new BigInteger("1");
        for (int i=1, m=n; i<=k; i++, m--){
            b = (b.multiply(new BigInteger(Integer.toString(m))).divide(new BigInteger(Integer.toString(i))));
        }
        return b;
    }
	

	public static void main(String[] args) {
       Scanner scanner = new Scanner(System.in);
       int cases = scanner.nextInt();
       for (int i = 0; i < cases; i++){
    	   int n = scanner.nextInt();
    	   System.out.println(new BigInteger("1").add(binomial(n,2)).add(binomial(n,4)));
       }
	}

}