package ArithmeticAlgebra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ReverseAndAdd {

	public static void findpalindrome(long num){
		int count = 0;
		while (count < 1001){
			if (isPalindrome(num)){
				System.out.println(count + " " + num);
				break;
			}
			else{
				num = num+reverseNum(num);
			}
			count++;
		}
	}
	
	public static long reverseNum(long x){
		String num = Long.toString(x);
		String reversenum = "";
		for (int i = num.length()-1; i >= 0; i--){
			reversenum += num.charAt(i);
		}
		return Long.parseLong(reversenum);
	}
	
	public static boolean isPalindrome(long n){
		long r = 0;
		for (long k = n; k != 0; k /= 10){
			r = 10*r+(k%10);
		}
		return n == r;
	}
	
	public static void main(String[] args) {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		try{
			int cases = Integer.parseInt(in.readLine());
			int count = 0;
			while (count < cases){
				long num = Long.parseLong(in.readLine());
				findpalindrome(num);
				count++;
			}
		}
		catch(IOException e){
			System.out.printf("IO Exception Error!\n");
		}
	}
}
