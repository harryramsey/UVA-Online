import java.util.Scanner;
import java.lang.Math;

public class TreasureEverywhere {
	static int count = 1;

	public static String[] get_directions(String[] directions, int N){
		String[] arr = new String[N];
		for (int i = 0; i < N; i++){
			String str = "";
			for (int j = 0; j < directions[i].length(); j++){
				if(Character.isAlphabetic(directions[i].charAt(j))){
					str += directions[i].charAt(j);
				}
			}
			arr[i] = str;
		}
		return arr;
	}
	
	public static String[] num_steps(String[] directions, int N){
		String[] arr = new String[N];
		for (int i = 0; i < N; i++){
			String str = "";
			for (int j = 0; j < directions[i].length(); j++){
				if(Character.isDigit(directions[i].charAt(j))){
					str += directions[i].charAt(j);
				}
			}
			arr[i] = str;
		}
		return arr;
	}
	
	public static void calculate(String[] which_way, String[] num_steps){
		double x = 0, y = 0, steps, sqrtsteps;
		int size = which_way.length;
		for (int i = 0; i < size; i++){
			steps = Double.parseDouble(num_steps[i]);
			sqrtsteps = steps/Math.sqrt(2);
			if (which_way[i].equals("N")){
				y += steps;
			}
			else if(which_way[i].equals("S")){
				y -= steps;
			}
			else if (which_way[i].equals("E")){
				x += steps;
			}
			else if (which_way[i].equals("W")){
				x -= steps;
			}
			else if (which_way[i].equals("NE")){
				y += sqrtsteps;
				x += sqrtsteps;
			}
			else if (which_way[i].equals("NW")){
				y += sqrtsteps;
				x -= sqrtsteps;
			}
			else if (which_way[i].equals("SE")){
				y -= sqrtsteps;
				x += sqrtsteps;
			}
			else {						
				y -= sqrtsteps;
				x -= sqrtsteps;
			}
		}
		double dist = Math.sqrt(x*x + y*y);
		String finalx = String.format("%.3f",x);
		String finaly = String.format("%.3f",y);
		String finaldist = String.format("%.3f",dist);
		
		System.out.println("Map #" + count++);
		System.out.println("The treasure is located at (" + finalx + "," + finaly + ")."); 
		System.out.println("The distance to the treasure is "+ finaldist + ".");
		System.out.println();
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String line;
		while (!(line = scanner.nextLine()).equals("END")){
			int count = 0;
			int N = line.length();
			for (int i = 0; i < N; i++){
				if (line.charAt(i) == ','){
					count++;
				}
			}
			String[] directions = line.split(",");
			String[] which_way = get_directions(directions,count+1);
			String[] num_steps = num_steps(directions,count+1);
			calculate(which_way,num_steps);
		}
	}
}

