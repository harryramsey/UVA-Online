package Strings;

import java.util.Scanner;

public class Waldorf { 
	static char grid[][];

	public static int upLeft(int i, int j, String keyword){
		if (grid[i][j] == keyword.charAt(0)){
			int count = 0; int x = i; int y = j;
			while (keyword.charAt(count) == grid[x][y]){
				count++; x--; y--;
				if (x < 0 || y < 0 || count == keyword.length()){
					break;
				}
			}
			if (count == keyword.length()){
				System.out.println((i+1) + " " + (j+1));
				return 1;
			}
		}
		return 0;
	}
	
	public static int up(int i, int j, String keyword){
		if (grid[i][j] == keyword.charAt(0)){
			int count = 0; int x = i; int y = j;
			while (keyword.charAt(count) == grid[x][y]){
				count++; x--;
				if (x < 0 || count == keyword.length()){
					break;
				}
			}
			if (count == keyword.length()){
				System.out.println((i+1) + " " + (j+1));
				return 1;
			}
		}
		return 0;
	}
	
	public static int upRight(int i, int j, String keyword){
		if (grid[i][j] == keyword.charAt(0)){
			int count = 0; int x = i; int y = j;
			while (keyword.charAt(count) == grid[x][y]){
				count++; x--; y++;
				if (x < 0 || y == grid[i].length || count == keyword.length()){
					break;
				}
			}
			if (count == keyword.length()){
				System.out.println((i+1) + " " + (j+1));
				return 1;
			}
		}
		return 0;
	}
	
	public static int left(int i, int j, String keyword){
		if (grid[i][j] == keyword.charAt(0)){
			int count = 0; int x = i; int y = j;
			while (keyword.charAt(count) == grid[x][y]){
				count++; y--;
				if (y < 0 || count == keyword.length()){
					break;
				}
			}
			if (count == keyword.length()){
				System.out.println((i+1) + " " + (j+1));
				return 1;
			}
		}
		return 0;
	}
	
	public static int right(int i, int j, String keyword){
		if (grid[i][j] == keyword.charAt(0)){
			int count = 0; int x = i; int y = j;
			while (keyword.charAt(count) == grid[x][y]){
				count++; y++;
				if (y == grid[i].length || count == keyword.length()){
					break;
				}
			}
			if (count == keyword.length()){
				System.out.println((i+1) + " " + (j+1));
				return 1;
			}
		}
		return 0;
	}
	
	public static int down(int i, int j, String keyword){
		if (grid[i][j] == keyword.charAt(0)){
			int count = 0; int x = i; int y = j;
			while (keyword.charAt(count) == grid[x][y]){
				count++; x++;
				if (x == grid.length || count == keyword.length()){
					break;
				}
			}
			if (count == keyword.length()){
				System.out.println((i+1) + " " + (j+1));
				return 1;
			}
		}
		return 0;
	}
	
	public static int downLeft(int i, int j, String keyword){
		if (grid[i][j] == keyword.charAt(0)){
			int count = 0; int x = i; int y = j;
			while (keyword.charAt(count) == grid[x][y]){
				count++; x++; y--;
				if (x == grid.length || y < 0 || count == keyword.length()){
					break;
				}
			}
			if (count == keyword.length()){
				System.out.println((i+1) + " " + (j+1));
				return 1;
			}
		}
		return 0;
	}
	
	public static int downRight(int i, int j, String keyword){
		if (grid[i][j] == keyword.charAt(0)){
			int count = 0; int x = i; int y = j;
			while (keyword.charAt(count) == grid[x][y]){
				count++; x++; y++;
				if (x == grid.length || y == grid[i].length || count == keyword.length()){
					break;
				}
			}
			if (count == keyword.length()){
				System.out.println((i+1) + " " + (j+1));
				return 1;
			}
		}
		return 0;
	}
	
	
	public static void find_match(String keyword){
		for (int row = 0; row < grid.length; row++){
			for (int j = 0; j < grid[row].length; j++){
				if (up(row, j, keyword) ==1) return;
				else if (down(row, j, keyword) == 1) return;
				else if (left(row, j,  keyword) == 1) return;
				else if (right(row, j, keyword) == 1) return;
				else if (upRight(row, j, keyword) == 1) return;
				else if (upLeft(row, j, keyword) == 1) return;
				else if (downRight(row, j, keyword) == 1) return;
				else if (downLeft(row, j, keyword) == 1) return;
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		for (int i = 0; i < cases; i++){
			int n = scanner.nextInt();
			int m = scanner.nextInt();
			grid = new char[n][m];
			for (int j = 0; j < n; j++){
				String str = scanner.next();
				for (int k = 0; k < m; k++){
					grid[j][k] = Character.toLowerCase(str.charAt(k));
				}
			}
			int numKeyWords = scanner.nextInt();
			for (int l = 0; l < numKeyWords; l++){
				String str = "";
				String key = scanner.next();
				for (int j = 0; j < key.length(); j++){
					str += Character.toLowerCase(key.charAt(j));
				}
				find_match(str);
			}
			if (i != cases-1) System.out.print("\n");
		}
	}
}
