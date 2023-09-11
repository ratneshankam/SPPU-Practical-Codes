import java.util.*;

public class sjf {
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
        int flag[] = new int[n];                    //it checks process is completed or not
        int st = 0, tot = 0;
        float avgwaiting = 0, avgTurnAround = 0;

        for (int i = 0; i < n; i++) {
            System.out.println("Enter process " + (i + 1) + " arrival time: ");
            arrival[i] = sc.nextInt();
            System.out.println("Enter process " + (i + 1) + " brust time: ");
            burst[i] = sc.nextInt();
            processId[i] = i + 1;
            flag[i] = 0;
        }

        while (true) {
            int c = n, min = Integer.MAX_VALUE;
            if (tot == n) {                         // total no of process = completed process loop will be terminated
                break;
            }
            for (int i = 0; i < n; i++) {
                if ((arrival[i] <= st) && (flag[i] == 0) && (burst[i] < min)) {         //if this condition satisfied that process will be executed first
                    min = burst[i];
                    c = i;
                }
            }
            if (c == n) {                           //c == n means c value can not updated because no process arrival time < system time so we increase the system time
                st++;
            } else {
                complete[c] = st + burst[c];
                st += burst[c];
                turnAround[c] = complete[c] - arrival[c];
                waiting[c] = turnAround[c] - burst[c];
                flag[c] = 1;
                tot++;
            }
        }
        
        for (int i=0; i<n; i++) {
            avgwaiting += waiting[i];
            avgTurnAround += turnAround[i];
            System.out.printf("%d\t%d\t%d\t%d\t%d\t%d", processId[i], arrival[i], burst[i], complete[i], turnAround[i], waiting[i]);
            System.out.println();
        }
        System.out.println("Average waiting time: " + (avgwaiting/n));
        System.out.println("Average turnAround time: " + (avgTurnAround/n));
            sc.close();
    }
}
