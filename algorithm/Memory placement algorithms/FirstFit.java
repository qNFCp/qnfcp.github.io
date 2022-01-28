import java.util.Scanner;

//样例ok,其他数据未测试
public class FirstFit {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.print("Total of pages to place: ");
		int N=sc.nextInt();
		
		int[][] prelist=new int[7+50][3];	//[1][0]=number; 
										//[1][1]=kind  1=Free,2=X,3=R
										//[1][2]=free place
		prelist[0][0]=100;
		prelist[0][1]=1;
		prelist[0][2]=100;
		
		prelist[1][0]=20;
		prelist[1][1]=2;
		prelist[1][2]=0;
		
		prelist[2][0]=80;
		prelist[2][1]=1;
		prelist[2][2]=80;
		
		prelist[3][0]=50;
		prelist[3][1]=3;
		prelist[3][2]=0;
		
		prelist[4][0]=50;
		prelist[4][1]=1;
		prelist[4][2]=50;
		
		prelist[5][0]=120;
		prelist[5][1]=2;
		prelist[5][2]=0;
		
		prelist[6][0]=100;
		prelist[6][1]=1;
		prelist[6][2]=100;
		
		String[] out=new String[N+50];
		
		int[] list=new int [N]; 
		boolean[] checklist=new boolean[N];
		System.out.print("List of pages to place (in Kb): ");
		for(int i=0;i<N;i++) {
			list[i]=sc.nextInt();
			
			for(int j=0;j<N+7;j++) {
				if(prelist[j][2]>=list[i]&&prelist[j][1]==1) {
					prelist[j][2]-=list[i];
					checklist[i]=true;
					if(out[j]==null) {
						out[j]=list[i]+", ";
						break;
					}
					else {
						out[j]+=list[i]+", ";
						break;
					}
				}
			}
		}
		
		System.out.print("Placement result: ");
		for(int i=0;i<=N+7;i++) {
			if(prelist[i][1]==2)
				System.out.print("X, ");
			else if(prelist[i][1]==3)
				System.out.print("R, ");
			else if(prelist[i][0]==prelist[i][2]&prelist[i][1]!=0) 
				System.out.print("-, ");
			else {
				if(out[i]!=null)
					System.out.print(out[i]);
			}
		}	
	}
}
