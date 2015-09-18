import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	static int[] color = new int[5000+5];
	static int[] dist = new int[5000+5];
	static int[][] graph = new int[5000+5][5000+5];
	static int totalNames;
	
	public static void bfs(int start){ //already initialized
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(start);
		color[start] = 0;
		
		while (!q.isEmpty()){
			int u = q.remove();
			for (int i = 0; i < totalNames; i++){
				if (graph[u][i] == 1 && color[i] == 1){
					q.add(i);
					dist[i] = dist[u]+1;
					color[i] = 0;
				}
			}
			color[u] = -1;
		}
	}

	public static void initialize(int s){
		for (int i = 0; i < totalNames; i++){
			color[i] = 1;
			dist[i] = 1000000000;
		}
		dist[s] = 0;
	}
	
	public static void clear(){
		for (int i = 0; i < totalNames; i++){
			for (int j = 0; j < totalNames; j++){
				graph[i][j] = 0;
			}
		}
	}
	
	public static String[] extractNames (String str){
		int count = 0;
		String[] names;
		
		for (int i = 0; i<str.length(); i++){
			if (str.charAt(i) == ','){
				count++;
			}
		}
		if (count %2 == 0){
			names = new String[count/2];
		}
		else names = new String[(count/2) + 1];
		
		int pos = 0, last = 0, loc = 0;
		for (int j = 0; j<str.length(); j++){
			if (str.charAt(j) == '.' && str.charAt(j+1) == ','){
				last = j+1;
				String aName = str.substring(pos, last);
				names[loc++] = aName.trim();
				pos = j+3;
			}
			else if (str.charAt(j) == '.' && str.charAt(j+1) == ':'){
				last = j+1;
				String aName = str.substring(pos, last);
				names[loc++] = aName.trim();
				break;
			}
		}
		return names;
	}
	
	public static void classify(String[] names, HashMap<String, Integer> map){
		
		for (int i = 0; i < names.length; i++){
			if (!map.containsKey(names[i])){
				map.put(names[i], totalNames);
				totalNames++;
			}
		}
		
		for (int i = 0; i < names.length; i++){
			for (int j = 0; j < names.length; j++){
				if (i != j){
					int v = map.get(names[i]);
					int w = map.get(names[j]);
					graph[v][w] = 1;
					graph[w][v] = 1;
				}
			}
		}
	}
	
	public static void printErdosNumber(String str, HashMap<String,Integer> map){
		if (!map.containsKey(str)){	
			System.out.println(str + " infinity");
		}
		else if (dist[map.get(str)] == 1000000000){
			System.out.println(str + " infinity");
		}
		else {
			int erdosNum = dist[map.get(str)];
			System.out.println(str + " " + erdosNum);
		}
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		int case_counter = 1;
		String line = null;
		
		for (int i = 0; i < cases; i++){
			HashMap<String, Integer> map = new HashMap<String, Integer>();
			map.put("Erdos, P.", 0);
			int numLines = scanner.nextInt();
			int num_names = scanner.nextInt();
			totalNames = 1;
			
			scanner.nextLine();
			for (int j = 0; j < numLines; j++){
				line = scanner.nextLine();
				String[] s = extractNames(line);
				classify(s, map);
			}
			
			System.out.println("Scenario " + case_counter);
			case_counter++;
			initialize(0);
			bfs(0);
			for (int k = 0; k < num_names; k++){
				printErdosNumber(scanner.nextLine(), map);
			}
			clear();
		}
	}
}
