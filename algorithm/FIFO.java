package SSK3313LAB7;
import java.util.LinkedList;
import java.util.Scanner;

public class FIFO {

	public static void main(String[] args) {
		LinkedList<Integer> q = new LinkedList<>();
        Scanner sc=new Scanner(System.in);
        int f;
		int n;
		int temp,i;
		int fifoans=0;
		int p=0;
		System.out.print("F:");
		f=sc.nextInt();
		System.out.print("N:");
		n=sc.nextInt();
		System.out.print("Demands:");
        for (i = 0; i < f; i++) {
            q.add(sc.nextInt());
            System.out.println("q: "+q);
        }
        while(i<n) {
        	temp=sc.nextInt();
        	if(q.contains(temp)) {
        		i++;
        		System.out.println("q: "+q);
        		continue;
        	}else {
        		fifoans++;
        		q.set(p, temp);
        		if(p>=f-1) {
        			p=0;
        		}else {
        			p++;
        		}
        		i++;
        	}
        	System.out.println("q: "+q);
        }
        fifoans+=f;
        System.out.println("Number of page faults produced = "+fifoans);
	}
}
