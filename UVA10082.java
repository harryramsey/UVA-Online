package Strings;

import java.util.HashMap;
import java.util.Scanner;

public class WERTYU {
			
	public static void decode(String line, HashMap h) {
		String str = "";
		for (int i = 0; i < line.length(); i++){
			str += h.get(line.charAt(i));
		}
		System.out.print(str + "\n");
	}
	
	public static void main(String[] args) {
		char[][] keyboard = {
				{'`','1','2','3','4','5','6','7','8','9','0','-','='},
				{'Q','W','E','R','T','Y','U','I','O','P','[',']',(char) 92},
				{'A','S','D','F','G','H','J','K','L',';', (char) 39},
				{'Z','X','C','V','B','N','M',',','.','/'},
				{' '}
		};
		HashMap h = new HashMap();
		for (int i = 0; i < 5; i++){
			char[] boardline = keyboard[i];
			for (int j = 0; j < boardline.length; j++){
				if (j == 0){
					h.put(boardline[j], boardline[j]);
				}
				else h.put(boardline[j], boardline[j-1]);
			}
		}
	Scanner scanner = new Scanner(System.in);
	while (scanner.hasNext()){
		String line = scanner.nextLine();
		decode(line, h);
	}
	}
}

