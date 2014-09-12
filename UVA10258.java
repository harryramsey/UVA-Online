package DataStructures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ContestScoreboard {
	
	public static void update_board(int[][] scoreboard, int team, int problem, int time_penalty, char type) {
		if (type == 'C'){
			if (scoreboard[team][problem] == 0){
				scoreboard[team][problem] = 1;
				scoreboard[team][19] += 1; //total questions answered
				scoreboard[team][20] += time_penalty + scoreboard[team][problem+9]*20; //total time penalty for question
				scoreboard[team][21] = 1; //did something
			}
		}
		else if (type == 'I'){
			scoreboard[team][problem+9] += 1; //another incorrect answer for this problem
			scoreboard[team][21] = 1;
		}
		else{
			scoreboard[team][21] = 1; //for those who tried something but may not have a score
		}
	}
	
	public static int[][] final_scores(int[][] scoreboard){
		int num_participants = active_players(scoreboard);
		int[][] team_info = new int[num_participants][3];
		int pos = 0;
		for (int i = 1; i < 101; i++){
			if (scoreboard[i][21] != 0){
				int[] info = {i, scoreboard[i][19], scoreboard[i][20]};
				team_info[pos++] = info;
			}
		}
		return team_info;
	}
	
	public static void insertionsort(int[][] a){ //group by number of correct answers
		int N = a.length;
		for (int i = 1; i < N; i++){ 
			for (int j = i; j > 0 ; j--){
				int[] jpos = a[j], kpos = a[j-1];
				if (less(kpos[1], jpos[1]))
					exch(a, j, j-1);
			}
		}
		secondsort(a);
	}
	
	public static void secondsort(int[][]a){ //group by penalty time
		int N = a.length;
		for (int i = 1; i < N; i++){ 
			for (int j = i; j > 0 ; j--){
				int[] jpos = a[j], kpos = a[j-1];
				if (jpos[1]==kpos[1] && less(jpos[2], kpos[2]))
					exch(a, j, j-1);
			}
		}
	}
	
	public static void exch(int[][] a, int j, int i) {
		int[] t = a[i]; a[i] = a[j]; a[j] = t;	
	}

	public static boolean less(int i, int j) {
		return i < j;
	}
	
	public static int active_players(int[][] scoreboard){
		int num_participants = 0;
		for (int i = 1; i < 101; i++){
			if (scoreboard[i][21] == 1){
				num_participants++;
			}
		}
		return num_participants;
	}
	
	public static void parse(String str, int[][]scoreboard){
		int i = -1, numtokens = 1, team = 0, problem = 0,time_penalty = 0;
		char type = '0';
		while (i < str.length()){
			String token = "";
			i++;
			while(i < str.length() && str.charAt(i) != ' ' ){
				token += str.charAt(i);
				i++;
			}
			if (numtokens == 1){
				team = Integer.parseInt(token);
				numtokens++;
			}
			else if (numtokens == 2){
				problem = Integer.parseInt(token);
				numtokens++;
			}
			else if (numtokens == 3){
				time_penalty = Integer.parseInt(token);
				numtokens++;
			}
			else {
				type = token.charAt(0);
			}
		}
		update_board(scoreboard, team, problem, time_penalty, type);
	}
	
	public static void print_final(int[][] board){
		for (int i = 0; i < board.length; i++){
			int[] team_stats = board[i];
			System.out.println(team_stats[0] + " " + team_stats[1] + " " + team_stats[2]);
		}
	}
	
	public static void main(String[] args) {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		try{
			int cases = Integer.parseInt(in.readLine());
			in.readLine();
			for (int i = 0; i < cases; i++){
				int[][] scoreboard = new int[101][22];
				String line;
				while ((line = in.readLine()) != null){
					if (line.length() > 0){
						parse(line, scoreboard);
					}
					else break;
				}
				int[][] final_scores = final_scores(scoreboard);
				insertionsort(final_scores);
				print_final(final_scores);
				if (i != cases-1){
					System.out.print("\n");
				}
			}
		}
		catch(IOException e){
			System.out.printf("IO Exception Error!\n");
		}
	}
}
