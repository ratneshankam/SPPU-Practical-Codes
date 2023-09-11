import java.util.*;
public class fcfs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no. of process: ");
        int n = sc.nextInt();
        int processId[] = new int[n];
        int arrival[] = new int[n];
        int burst[] = new int[n];
        int complete[] = new int[n];
        int turnAround[] = new int[n];
        int waiting[] = new int[n];
        int temp;   float avgwaiting = 0, avgTurnAround = 0;

        for (int i = 0; i<n; i++) {
            System.out.println("Enter process " + (i+1) + " arrival time: ");
            arrival[i] = sc.nextInt();
            System.out.println("Enter process " + (i+1) + " brust time: ");
            burst[i] = sc.nextInt();
            processId[i] = i+1;
        }

        for (int i=0; i<arrival.length-1; i++) {
            int Swap=0;
            for (int j=0; j<arrival.length-1-i; j++) {
                if (arrival[j] > arrival[j+1]) {
                    // Swap
                    temp = arrival[j];
                    arrival[j] = arrival[j+1];
                    arrival[j+1] = temp;
                    temp = burst[j];
                    burst[j] = burst[j+1];
                    burst[j+1] = temp;
                    temp = processId[j];
                    processId[j] = processId[j+1];
                    processId[j+1] = temp;
                    Swap++;
                }
            }
            if (Swap == 0) {break;}                   // Used only when array is already sorted
            // System.out.print(Swap + " ");
        }
        
        for (int i=0; i<n; i++) {
            if (i==0) {
                complete[i] = arrival[i] + burst[i];
            } else {
                if (arrival[i] > complete[i-1]) {
                    complete[i] = arrival[i] + burst[i];
                } else {
                    complete[i] = complete[i-1] + burst[i];
                }
            }
                turnAround[i] = complete[i] - arrival[i];
                waiting[i] = turnAround[i] - burst[i];
                avgwaiting += waiting[i];
                avgTurnAround += turnAround[i];
        }
        System.out.println();
        System.out.println("processid arrival brust complete Turn waiting");
        for (int i=0; i<n; i++) {
            System.out.printf("%d\t%d\t%d\t%d\t%d\t%d", processId[i], arrival[i], burst[i], complete[i], turnAround[i], waiting[i]);
            System.out.println();
        }
        sc.close();
        System.out.println("Average waiting time: " + (avgwaiting/n));
        System.out.println("Average turnAround time: " + (avgTurnAround/n));
    }
}













//  OUTPUT :
// Enter the no. of process: 
// 4
// Enter the process 0 arrival time
// 0
// Enter the process 0 burst time
// 3
// Enter the process 1 arrival time
// 1
// Enter the process 1 burst time
// 4
// Enter the process 2 arrival time
// 2
// Enter the process 2 burst time
// 2
// Enter the process 3 arrival time
// 3
// Enter the process 3 burst time
// 1
// 1       0       3       3       3       0
// 2       1       4       7       6       2
// 3       2       2       9       7       5
// 4       3       1       10      7       6
// Average turnaround time: 5.75
// Average waiting time: 3.25