package Strings;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CryptKickerII {

	public static void decrypt(String[] encrypted_lines){
		int QBFloc = findQBF(encrypted_lines);
		if (QBFloc < 0){
			System.out.println("No solution.");
		}
		else{
			char[][] decrypted_alphabet = get_alphabet(encrypted_lines[QBFloc]);
			int i = 0;
			while (encrypted_lines[i] != null){
				System.out.println(decrypt_sentence(decrypted_alphabet, encrypted_lines[i]));
				i++;
			}
		}
	}
	
	public static String decrypt_sentence(char[][] alphabet, String sentence){
		int i = 0;
		String decryption = "";
		while (i < sentence.length()){
			if (sentence.charAt(i) != ' '){
				int letter = sentence.charAt(i)-'a';
				decryption += alphabet[letter][1];
			}
			else decryption += " ";
			i++;
		}
		return decryption;
	}
	
	
	public static int findQBF(String[] encryptedlines){
		int i = 0;
		while( i!= encryptedlines.length && encryptedlines[i] != null){
			if (isQBF(encryptedlines[i])){
				return i;
			}
			i++;
		}
		return -1;
	}
	
	public static boolean isQBF(String str){
		if (str.length() != "the quick brown fox jumps over the lazy dog".length()){
			return false;
		}
		else{
			for (int i = 0; i < 3; i++){
				if (str.charAt(i) != str.charAt(i+31)){
					return false;
				}
			}
			if (str.charAt(12) != str.charAt(17) || str.charAt(12) != str.charAt(26) || str.charAt(12) != str.charAt(41)){
				return false;
			}
			if (str.charAt(11) != str.charAt(29)){
				return false;
			}
			if (str.charAt(5) != str.charAt(21)){
				return false;
			}
			int[] alphabet = new int[26];
			int i = 0;
			while (i < str.length()){
				if (str.charAt(i) != ' '){
					int letter = str.charAt(i)-'a';
					alphabet[letter]++;
				}
				i++;
			}
			insertionsort(alphabet);
			if(alphabet[0] != 0 && alphabet[19] == 1){
				return true;
			}
			
		}
			return false;
	}
	
	public static char[][] get_alphabet(String qbf){
		String template = "the quick brown fox jumps over the lazy dog";
		char[][] alphabet = new char[26][2];
		int i = 0;
		while (i < template.length()){
			if (template.charAt(i) != ' '){
				int letter = qbf.charAt(i)-'a';
				alphabet[letter][0] = qbf.charAt(i);
				alphabet[letter][1] = template.charAt(i);
			}
			i++;
		}
		return alphabet;
	}
	
	public static void insertionsort(int[] a){
		int N = a.length;
		for (int i = 1; i < N; i++){ // Insert a[i] among a[i-1], a[i-2], a[i-3]... ..
			for (int j = i; j > 0 && less(a[j], a[j-1]); j--){
				exch(a, j, j-1);
			}
		}
	}
	
	public static void exch(int[] a, int j, int i) {
		int t = a[i]; a[i] = a[j]; a[j] = t;
		
	}

	public static boolean less(int i, int j) {
		return i < j;
	}
	
	
	public static void main(String[] args) {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			try{
				int cases = Integer.parseInt(in.readLine());
				in.readLine();
				for (int i = 0; i < cases; i++){
					String[] encryptedlines = new String[101]; int pos = 0;
					String line;
					while ((line = in.readLine()) != null){
						if (line.length() > 0){
							encryptedlines[pos++] = line;
						}
						else break;
					}
					decrypt(encryptedlines);
					if (i != cases-1) System.out.print("\n");
				}
			}
			catch(IOException e){
				System.out.printf("IO Exception Error!\n");
			}
	}
}
