package Sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class VitosFamily {

	public static int[] parse(String str){
		int i = -1, count = 0, pos = 0;
		int[] streets = null;
		while (i < str.length()){
			String token = "";
			i++;
			while (i < str.length() && str.charAt(i) != ' '){
				token += str.charAt(i);
				i++;
			}
			if (count == 0){
				streets = new int[Integer.parseInt(token)];
				count++;
			}
			else {
				streets[pos++] = Integer.parseInt(token);
			}
		}
		return streets;
	}
	
	public static void sort(int[] a, int lo, int hi){
		if (hi <= lo) return;
		int j = partition(a, lo, hi); 
		sort(a, lo, j-1);
		sort(a, j+1, hi);
	}
	
	public static int partition(int[] a, int lo, int hi){ 
		int i = lo, j = hi+1;
		int v = a[lo];
		while (true){
			while (less(a[++i], v)) if (i == hi) break;
			while (less(v, a[--j])) if (j == lo) break;
			if (i >= j) break;
			exch(a, i, j);
		}
		exch(a, lo, j);
		return j;
	}
	
	public static boolean less(int v, int w){ 
		return v < w;
	}
	
	public static void exch(int[] a, int i, int j){
		int t = a[i]; a[i] = a[j]; a[j] = t; 
	}
	
	public static int getDistance(int[] streets){
		int median = find_median(streets);
		int sum = 0;
		for (int i = 0; i < streets.length; i++){
			sum += absdiff(median-streets[i]);
		}
		return sum;
	}
	
	public static int absdiff(int a){
		if (a < 0){
			return -a;
		}
		return a;
	}
	
	public static int find_median(int[] streets){
		if (streets.length % 2 == 1){
			return streets[(streets.length-1)/2];
		}
		return (streets[(streets.length-1)/2] + streets[streets.length/2])/2;
	}
	
	public static void main(String[] args) {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		try{
			int cases = Integer.parseInt(in.readLine());
			for (int i = 0; i < cases; i++){
				String line;
				while ((line = in.readLine()) != null){
					if (line.length() > 0){
						int[] streets = parse(line);
						sort(streets,0,streets.length-1);
						System.out.println(getDistance(streets));
					}
					else break;
				}
			}
		}
		catch(IOException e){
			System.out.printf("IO Exception Error!\n");
		}
	}
}
