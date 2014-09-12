import java.util.HashMap;
import java.util.Scanner;

public class Test {
	static int casenum = 1;
	
	public static void find_cycle(int Z, int I, int M, int L){
		int length = 0, next = 0, nextMod = L;
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		while (true){
			next = Z*nextMod + I;
			nextMod = next % M;
			if (!map.containsKey(nextMod)){
				map.put(nextMod, 0);
				length++;
			}
			else break;
		}
		System.out.println("Case " + casenum + ": " + length);
		casenum++;
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int Z, I, M, L;
		while (scanner.hasNextInt()){
			Z = scanner.nextInt();
			I = scanner.nextInt();
			M = scanner.nextInt();
			L = scanner.nextInt();
			if (Z == 0 && I == 0 && M == 0 && L == 0) break;
			find_cycle(Z,I,M,L);
		}
	}
}
