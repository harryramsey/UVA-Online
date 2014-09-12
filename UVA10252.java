package Strings;

import java.util.Scanner;

public class CommonPermutation {
	
	public static int[] find_common_perm(String word) {
		int[] alphabet = new int[26];
		
		for (int i = 0; i < word.length(); i++){
			int letter = word.charAt(i)-'a';
			alphabet[letter]++;
		}
		return alphabet;
	}
	
	public static void print_common_perm(int[]alphabet1, int[]alphabet2){
		String perm = "";
		for (int i = 0; i < alphabet1.length; i++){
			for (int j = 0; j < min(alphabet1[i], alphabet2[i]); j++){
				perm += (char) (i + 'a');
			}
		}
		System.out.println(perm);
	}
	
	public static int min(int a, int b){
		return (a < b)? a : b;  
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNext()){
			String word1= scanner.nextLine();
			String word2 = scanner.nextLine();
			int[] alphabet1 = find_common_perm(word1);
			int[] alphabet2 = find_common_perm(word2);
			print_common_perm(alphabet1, alphabet2);
		}
	}
}
