package DataStructures;

import java.util.HashMap;
import java.util.Scanner;

public class Hartals {
	
	public static int hartals(HashMap map,HashMap forbidden, int interval, int days) {
		int hartals = 0;
		for (int i = interval; i<=days; i+= interval){
			if (!map.containsKey(i)){
				map.put(i, i);
				if (i%7 != 0 && !forbidden.containsKey(i))
					hartals++;
			}
		}
		return hartals;
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		
		for (int i = 0; i<cases; i++){
			HashMap map = new HashMap();
			HashMap forbidden = new HashMap();
			int days = scanner.nextInt();
			int days_lost = 0;
			
			for (int k = 6; k<=days; k += 7){
				forbidden.put(k, k);
			}
			int num_parties = scanner.nextInt();
			for (int j = 0; j<num_parties; j++){
				days_lost += hartals(map, forbidden, scanner.nextInt(), days);
			}
			System.out.println(days_lost);
		}
	}
}