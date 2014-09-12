import java.math.BigInteger;

public class Test {
	
	public static void triangle_of_death(){
		
		BigInteger[] arr = new BigInteger[205];
		BigInteger[] temp = new BigInteger[205];
		BigInteger one = new BigInteger("1");
		BigInteger max = new BigInteger("10").pow(60);
		
		arr[0] = one;
		int lim = 0;
		boolean flag = false;
		
		while (flag == false){
			temp[0] = one;
			temp[lim] = one;
			for (int i = 1; i < lim; i++){
				temp[i] = arr[i-1].add(arr[i]);
				if (temp[i].compareTo(max) == 1) flag = true;
			}
			for (int j = 0; j < lim; j++){
				System.out.print(temp[j] + " ");
			}
			System.out.println(temp[lim]);
			
			for (int i = 0; i <= lim; i++){
				arr[i] = temp[i];
			}
			lim++;
		}
	}
	
	public static void main(String[] args) {
		triangle_of_death();
	}
}
