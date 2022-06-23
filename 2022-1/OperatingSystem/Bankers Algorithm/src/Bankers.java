import java.util.Scanner;
public class Bankers {
	private int need[][],allocate[][],max[][],avail[],numP,numR;

	private void input()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("202001506 Hyeyoung Moon");
		System.out.print("Enter no. of processes and resources : ");
		numP=sc.nextInt();  //# of process
		numR=sc.nextInt();  //# of resources
		need=new int[numP][numR];  //initializing arrays
		max=new int[numP][numR];
		allocate=new int[numP][numR];
		avail=new int[numR];

		System.out.println("Enter allocation matrix -->");
		for(int i=0;i<numP;i++)
			for(int j=0;j<numR;j++)
				allocate[i][j]=sc.nextInt();  //allocation matrix

		System.out.println("Enter max matrix -->");
		for(int i=0;i<numP;i++)
			for(int j=0;j<numR;j++)
				max[i][j]=sc.nextInt();  //max matrix

		System.out.println("Enter available matrix -->");
		for(int j=0;j<numR;j++)
			avail[j]=sc.nextInt();  //available matrix

		sc.close();
	}

	private int[][] calc_need(){
		for(int i=0;i<numP;i++)
			for(int j=0;j<numR;j++)  //calculating need matrix
				need[i][j]=max[i][j]-allocate[i][j];

		return need;
	}

	private boolean check(int i){
		//checking if all resources for ith process can be allocated
		for(int j=0;j<numR;j++) 
			if(avail[j]<need[i][j])
				return false;

		return true;
	}

	public void isSafe(){
		input();
		calc_need();
		boolean[] fin  = new boolean[numP];
		for(int i=0;i<numP;i++) {
			for(int j=0;j<numP;j++) {
				if(fin[j]==false && check(j)) {
					System.out.println("Allocated process : " + j);
					fin[j] = true;
					for(int k=0;k<numR;k++) avail[k] += allocate[i][k];
					break;
				}
			}
		}
		
		for(int i=0;i<numP;i++) {
			for(int j=0;j<numR;j++) {
				if(!check(j)) {
					System.out.println("All process cant be allocated safely");
					System.exit(0);
				}
			}
		}
		System.out.println("");
		System.out.println("Safely allocated");
	}

	public static void main(String[] args) {
		new Bankers().isSafe();
	}

}
