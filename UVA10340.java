import java.util.Scanner;


public class AllInAll {

	public static void isEncrytption(String a, String b) {
		if (b.contains(a)){
			System.out.println("Yes");
		}
		else if (!b.contains(a)){ 
			String pieces = "";
			int location = 0; //location ensures order of letters so that "BUG UnBaG" doesn't come out as "BUG", but rather "BG"
			for (int i = 0; i<a.length(); i++){
				for (int j = location; j<b.length(); j++){ //j = location so that it doesn't waste time going back from 0 -->starts on new letter 
					if (a.charAt(i) == b.charAt(j) && j>location){ //where it left off in string "b"
						pieces = pieces + a.charAt(i);
						location = j;
						break; //ends current letter and begins on new one
					}
				}
			}
			if (a.equals(pieces)){System.out.println("Yes");}
			else {System.out.println("No");}
		}
		
	}
	
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		
		while (scanner.hasNext()){
			String a = scanner.next();
			String b = scanner.next();
			isEncrytption(a,b);
		}
	}

}
