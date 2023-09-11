import java.util.*;
public class roundrobin {
    public static void main(String[] args) {
        int n, i, qt, count = 0, temp, sq = 0, bt[], wt[], tat[], rem_bt[];
        float awt = 0, atat = 0;
        bt = new int[10];
        wt = new int[10];
        tat = new int[10];
        rem_bt = new int[10];
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number of process (maximum 10) = ");
        n = s.nextInt();
        System.out.print("Enter the burst time of the process\n");
        for (i = 0; i < n; i++) {
            System.out.print("P" + i + " = ");
            bt[i] = s.nextInt();
            rem_bt[i] = bt[i];
        }
        System.out.print("Enter the quantum time: ");
        qt = s.nextInt();
        while (true) {
            for (i = 0, count = 0; i < n; i++) {
                temp = qt;
                if (rem_bt[i] == 0) {
                    count++;
                    continue;
                }
                if (rem_bt[i] > qt)
                    rem_bt[i] = rem_bt[i] - qt;
                else if (rem_bt[i] >= 0) {
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
                sq = sq + temp;
                tat[i] = sq;
            }
            if (n == count)
                break;
        }
        System.out.print("--------------------------------------------------------------------------------");
        System.out.print("\nProcess\t      Burst Time\t       Turnaround Time\t          Waiting Time\n");
        System.out.print("--------------------------------------------------------------------------------");
        for (i = 0; i < n; i++) {
            wt[i] = tat[i] - bt[i];
            awt = awt + wt[i];
            atat = atat + tat[i];
            System.out.print("\n " + (i + 1) + "\t " + bt[i] + "\t\t " + tat[i] + "\t\t " + wt[i] + "\n");
        }
        awt = awt / n;
        atat = atat / n;
        System.out.println("\nAverage waiting Time = " + awt + "\n");
        System.out.println("Average turnaround time = " + atat);
    }

}



























// //JAVA Program for implementing
// //Round Robin Algorithm
// // code by Sparsh_cbs
// import java.util.*;

// public class RoundRobin{
// 	private static Scanner inp = new Scanner(System.in);
// 	//Driver Code
// 	public static void main(String[] args){
// 		int n,tq, timer = 0, maxProccessIndex = 0;
// 		float avgWait = 0, avgTT = 0;
// 		System.out.print("\nEnter the time quanta : ");
// 		tq = inp.nextInt();
// 		System.out.print("\nEnter the number of processes : ");
// 		n = inp.nextInt();
// 		int arrival[] = new int[n];
// 		int burst[] = new int[n];
// 		int wait[] = new int[n];
// 		int turn[] = new int[n];
// 		int queue[] = new int[n];
// 		int temp_burst[] = new int[n];
// 		boolean complete[] = new boolean[n];

// 		System.out.print("\nEnter the arrival time of the processes : ");
// 		for(int i = 0; i < n; i++)
// 			arrival[i] = inp.nextInt();

// 		System.out.print("\nEnter the burst time of the processes : ");
// 		for(int i = 0; i < n; i++){
// 			burst[i] = inp.nextInt();
// 			temp_burst[i] = burst[i];
// 		}

// 		for(int i = 0; i < n; i++){ //Initializing the queue and complete array
// 			complete[i] = false;
// 			queue[i] = 0;
// 		}
// 		while(timer < arrival[0]) //Incrementing Timer until the first process arrives
// 			timer++;
// 		queue[0] = 1;
		
// 		while(true){
// 			boolean flag = true;
// 			for(int i = 0; i < n; i++){
// 				if(temp_burst[i] != 0){
// 					flag = false;
// 					break;
// 				}
// 			}
// 			if(flag)
// 				break;

// 			for(int i = 0; (i < n) && (queue[i] != 0); i++){
// 				int ctr = 0;
// 				while((ctr < tq) && (temp_burst[queue[0]-1] > 0)){
// 					temp_burst[queue[0]-1] -= 1;
// 					timer += 1;
// 					ctr++;

// 					//Updating the ready queue until all the processes arrive
// 					checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
// 				}
// 				if((temp_burst[queue[0]-1] == 0) && (complete[queue[0]-1] == false)){
// 					turn[queue[0]-1] = timer;	 //turn currently stores exit times
// 					complete[queue[0]-1] = true;
// 				}
				
// 				//checks whether or not CPU is idle
// 				boolean idle = true;
// 				if(queue[n-1] == 0){
// 					for(int k = 0; k < n && queue[k] != 0; k++){
// 						if(complete[queue[k]-1] == false){
// 							idle = false;
// 						}
// 					}
// 				}
// 				else
// 					idle = false;

// 				if(idle){
// 					timer++;
// 					checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
// 				}
			
// 				//Maintaining the entries of processes after each premption in the ready Queue
// 				queueMaintainence(queue,n);
// 			}
// 		}

// 		for(int i = 0; i < n; i++){
// 			turn[i] = turn[i] - arrival[i];
// 			wait[i] = turn[i] - burst[i];
// 		}

// 		System.out.print("\nProgram No.\tArrival Time\tBurst Time\tWait Time\tTurnAround Time"
// 						+ "\n");
// 		for(int i = 0; i < n; i++){
// 			System.out.print(i+1+"\t\t"+arrival[i]+"\t\t"+burst[i]
// 							+"\t\t"+wait[i]+"\t\t"+turn[i]+ "\n");
// 		}
// 		for(int i =0; i< n; i++){
// 			avgWait += wait[i];
// 			avgTT += turn[i];
// 		}
// 		System.out.print("\nAverage wait time : "+(avgWait/n)
// 						+"\nAverage Turn Around Time : "+(avgTT/n));
// 	}
// 	public static void queueUpdation(int queue[],int timer,int arrival[],int n, int maxProccessIndex){
// 		int zeroIndex = -1;
// 		for(int i = 0; i < n; i++){
// 			if(queue[i] == 0){
// 				zeroIndex = i;
// 				break;
// 			}
// 		}
// 		if(zeroIndex == -1)
// 			return;
// 		queue[zeroIndex] = maxProccessIndex + 1;
// 	}

// 	public static void checkNewArrival(int timer, int arrival[], int n, int maxProccessIndex,int queue[]){
// 		if(timer <= arrival[n-1]){
// 			boolean newArrival = false;
// 			for(int j = (maxProccessIndex+1); j < n; j++){
// 				if(arrival[j] <= timer){
// 					if(maxProccessIndex < j){
// 						maxProccessIndex = j;
// 						newArrival = true;
// 					}
// 				}
// 			}
// 			if(newArrival) //adds the index of the arriving process(if any)
// 				queueUpdation(queue,timer,arrival,n, maxProccessIndex);	
// 		}
// 	}

// 	public static void queueMaintainence(int queue[], int n){

// 		for(int i = 0; (i < n-1) && (queue[i+1] != 0) ; i++){
// 			int temp = queue[i];
// 			queue[i] = queue[i+1];
// 			queue[i+1] = temp;
// 		}
// 	}
// }
