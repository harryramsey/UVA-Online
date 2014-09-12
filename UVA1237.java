import java.util.Scanner;

public class Test {
	
	public static void test(int[] query, String[] maker, int[][] price_bounds){
		int poss_answers = 0;
		String ans = "";
		
		for (int i = 0; i < query.length; i++){
			poss_answers = 0;
			int price = query[i];
			ans = "";
			for (int j = 0; j < maker.length; j++){
				if (price >= price_bounds[j][0] && price <= price_bounds[j][1]){
					ans = maker[j];
					poss_answers++;
				}
			}
			if (poss_answers == 0 || poss_answers > 1){
				System.out.println("UNDETERMINED");
			}
			else{
				System.out.println(ans);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		int count = 0;
		for (int i = 0; i < cases; i++){
			int N = scanner.nextInt();
			String[] maker = new String[N];
			int[][] price_bounds = new int[N][2];
			for (int j = 0; j < N; j++){
				maker[j] = scanner.next();
				price_bounds[j][0] = scanner.nextInt();
				price_bounds[j][1] = scanner.nextInt();
			}
			int M = scanner.nextInt();
			int[] query = new int[M];
			for (int k = 0; k < M; k++){
				query[k] = scanner.nextInt();
			}
			test(query,maker,price_bounds);
			count++;
			if (count != cases){
				System.out.println();
			}
		}
	}
}
