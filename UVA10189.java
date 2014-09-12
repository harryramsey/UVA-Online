package Beginning;

import java.util.Scanner;

public class Minesweeper {
	static int count = 1;

	public void build(int x, int y, Scanner scanner) {
		int[][] field = new int[x][y];
		for (int i = 0; i<x;i++){
			String str= scanner.next();
			for (int j = 0; j < y; j++){
				if (str.charAt(j) == '*'){
					field = addCount(field, i, j,x,y);
				}
			}
		}
		output(field,x,y);
	} 
	
	public void output(int[][] field, int x, int y) {
		System.out.println("Field #" + count +  ":");
		count++;
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y ; j++){
				if (field[i][j] >= 42){ //being lazy since '*' is 42 and it may be added to
					System.out.print('*');
				}
				else System.out.print(field[i][j]);
			}
		System.out.print("\n");
		}
	}
	
	public int[][] addCount(int[][] field,int i, int j, int x, int y) {
		field[i][j] = '*';
		if (j+1 < y){
			field[i][j+1]++;
		}
		if (j-1 >= 0){
			field[i][j-1]++;
		}
		if (i+1 < x){
			field[i+1][j]++;
		}
		if (i - 1 >= 0){
			field[i-1][j]++;
		}
		if (i+1 < x && j+1 < y){
			field[i+1][j+1]++;
		}
		if (i+1 < x && j-1 >= 0){
			field[i+1][j-1]++;
		}
		if (i-1 >= 0 && j+1 < y){
			field[i-1][j+1]++;
		}
		if (i-1 >= 0 && j-1 >= 0){
			field[i-1][j-1]++;
		}
		return field;
	}
	
	public static void main(String[] args) {
		Minesweeper m = new Minesweeper();
		Scanner scanner = new Scanner(System.in);
		while (true){
			int x = scanner.nextInt();
			int y = scanner.nextInt();
			if (x == 0 && y == 0){System.exit(0);}
			if (count != 1){System.out.println();}
			m.build(x,y,scanner);
		}
	}
}


	
