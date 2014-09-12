package Strings;

import java.util.Scanner;

public class AutomaticJudge {
	static int run = 1;

	public static void classify(String[] correct, String[] unsure){
		if (correct.length != unsure.length){
			String every_line_correct = extractall(correct);
			String every_line_unsure = extractall(unsure);
			
			if (extractnums(every_line_correct).equals(extractnums(every_line_unsure))){
				System.out.println("Run #" + run + ": Presentation Error");
				run++;
			}
			else {
				System.out.println("Run #" + run + ": Wrong Answer");
				run++;
			}
		}
		else {
			int min_val = 100;
			for (int i = 0; i < unsure.length; i++){
				min_val = min(min_val,linetype(correct[i], unsure[i]));
			}
			if (min_val == 1){
				System.out.println("Run #" + run + ": Accepted");
				run++;
			}
			else {
				String every_line_correct = extractall(correct);
				String every_line_unsure = extractall(unsure);
				
				if (extractnums(every_line_correct).equals(extractnums(every_line_unsure))){
					System.out.println("Run #" + run + ": Presentation Error");
					run++;
				}
				else {
					System.out.println("Run #" + run + ": Wrong Answer");
					run++;
				}
			}
		}
	}
	
	public static int linetype(String correct, String unsure){
		if (isCE(correct, unsure)){
			return 1;
		}
		else if (isPE(correct,unsure)){
			return 0;
		}
		else return -1;
	}
	
	public static boolean isCE(String correct, String unsure){
		if (correct.equals(unsure)){
			return true;
		}
		return false;
	}
	
	public static boolean isPE(String correct, String unsure){
		String correctnums = extractnums(correct);
		String unsurenums = extractnums(unsure);
		
		if (correctnums.equals(unsurenums) && !correct.equals(unsure)){
			return true;
		}
		return false;
	}
	
	public static String extractnums(String str){
		String nums = "";
		for (int i = 0; i < str.length(); i++){
			if (Character.isDigit(str.charAt(i))){
				nums += str.charAt(i);
			}
		}	
		return nums;
	}
	
	public static String extractall(String[] str){
		String newstr = "";
		for (int i = 0; i < str.length; i++){
			for (int j = 0; j < str[i].length(); j++){
				if (str[i].charAt(j) != ' '){
					newstr += str[i].charAt(j);
				}
			}
		}
		return newstr;
	}
	
	public static int min(int a, int b){
		return (a < b)? a : b;  
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNextLine()){
			int totallines = Integer.parseInt(scanner.nextLine());
			if (totallines == 0) break;
			String[] correctanswers = new String[totallines];
			int pos = 0;
			for (int i = 0; i < totallines; i++){
				String sentence = scanner.nextLine();
				correctanswers[pos++] = sentence;
			}
			int answerlines = Integer.parseInt(scanner.nextLine());
			String[] answers = new String[answerlines];
			int pos1 = 0;
			for (int i = 0; i < answerlines; i++){
				String sentence = scanner.nextLine();
				answers[pos1++] = sentence;
			}
			classify(correctanswers, answers);
		}
	}
}
