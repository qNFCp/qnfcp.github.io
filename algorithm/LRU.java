import java.util.LinkedList;
import java.util.Scanner;

public class LRU {

	public static void main(String[] args) {
		LinkedList<Integer> q = new LinkedList<>();
		LinkedList<Integer> all = new LinkedList<>();
        Scanner sc=new Scanner(System.in);
        int f;//帧大小
		int n;//总数
		int temp,i;
		int lruans=0;
		
		int p;//要被覆盖掉的
		System.out.print("F:");
		f=sc.nextInt();
		System.out.print("N:");
		n=sc.nextInt();
		
		lruans+=f;
		
		boolean[] check=new boolean[f];
		int checkall=0;
		
		System.out.print("Demands:");
		for(i=0;i<f;i++) {
			temp=sc.nextInt();
			q.add(temp);
			all.add(temp);
            System.out.print("q: "+q);
            System.out.println("\t F");
		}
		
		for(;i<n;i++) {
			temp=sc.nextInt();
			all.add(temp);
			if(q.contains(temp)) {
				System.out.println("q: "+q);
				continue;
			}else {
				for(int j=i;j>=0;j--) {
					for(int k=0;k<f;k++) {
						if(!check[k]?q.get(k)==all.get(j):false) {
							check[k]=true;
							p=q.get(k);
							checkall++;
							if(checkall==f) {
								q.set(q.indexOf(all.get(j)),temp);
								lruans++;
								System.out.print("q: "+q); 
								System.out.println("\t F");
							}
						}
					}
				}
			}
			for(int k=0;k<f;k++) {
				check[k]=false;
			}
			checkall=0;
		}
		System.out.println("Number of page faults produced = "+lruans);
	}
}
