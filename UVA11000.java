import java.util.Scanner;

public class Bees {

	public static void fibbonacci(String N){
		long x = Long.parseLong(N);
		long a = 1;
		long b = 1;
		long c = 0;
		long d = 0;
		long total = 0;
		
		for (int i = 0; i<Integer.parseInt(N); i++){
			c = a+b-1;
			d = a;
			a = b;
			b = b+d;
			total = a+b-1;
			
		}
		System.out.println(c + " " + total);
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		while (scanner.hasNext()){
			String N = scanner.next();
			if (N.equals("0")){System.out.println("0 1");}
			else if (N.equals("-1")){System.exit(0);}
			else fibbonacci(N);
		}
	}

}
