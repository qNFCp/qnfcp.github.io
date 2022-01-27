import java.util.Scanner;

//memory placement algorithms
public class BestFit {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.print("Total of pages to place: ");
		int N=sc.nextInt();
		int temp;
		
		int p=0;//指针
		int ans=999999;//对比用结果
		
		boolean check;
		
		PAGES[] pages=new PAGES[7+N+1];
		pages[0]=new PAGES(100,"-",100);
		pages[1]=new PAGES(20,"X",0);
		pages[2]=new PAGES(80,"-",80);
		pages[3]=new PAGES(50,"R",0);
		pages[4]=new PAGES(50,"-",50);
		pages[5]=new PAGES(120,"X",0);
		pages[6]=new PAGES(100,"-",100);
		
		System.out.print("List of pages to place (in Kb): ");
		for(int i=7;i<=(6+N);i++) {
			ans=999999;
			temp=sc.nextInt();
			pages[i]=new PAGES(temp);
			
			check=false;
			for(int j=0;j<=7;j++) {
				if(pages[j].get_free()>=temp) {
					if(((pages[j].get_free()-temp)<ans)&&((pages[j].get_free()-temp)>=0)) {
						p=j;
						ans=pages[j].get_free()-temp;
						check=true;
						
					}
				}

			}
			
			if(!check) {
				System.err.println("i="+i+" Error: the remaining memory is not enough to place more pages");
				return;
			}
			
			pages[i].set_place(p);
			pages[p].set_added(true);
			pages[p].set_free(pages[p].get_free()-temp);
		}
		
		System.out.print("Placement result: ");
		
		for(int i=0;i<=(6+N);i++) {
			if(pages[i].get_added()) {
				
				//System.out.println(pages[i].get_added());
				
				for(int j=7;j<=(6+N);j++) {
					if(pages[j].get_place()==i) {
						System.out.print(pages[j].get_data()+", ");
					}
				}
			}
			else {
				if(pages[i].get_state()=="X") {
					System.out.print("X"+", ");
					continue;
				}
				if(pages[i].get_free()==pages[i].get_data()) {
					System.out.print("-"+", ");
					continue;
				}
				if(pages[i].get_state()=="R") {
					System.out.print("R"+", ");
					continue;
				}
			}
		}
	}

}

class PAGES{
	int data;
	String state;
	boolean added=false;
	int free=0;
	int place;
	PAGES(){
	}
	PAGES(int data){
		this.data=data;
	}
	PAGES(int data,String state,int free){
		this.data=data;
		this.state=state;
		this.free=free;
	}
	void set_state(String state){
		this.state=state;
	}
	void set_added(boolean added) {
		this.added=added;
	}
	void set_free(int free) {
		this.free=free;
	}
	void set_place(int place) {
		this.place=place;
	}
	int get_data() {
		return data;
	}
	String get_state() {
		return state;
	}
	boolean get_added() {
		return added;
	}
	int get_free() {
		return free;
	}
	int get_place(){
		return place;
	}
}