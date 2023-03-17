#include <bits/stdc++.h>
using namespace std;
struct input
{
    int pid;
    int at;
    int bt;
    int priority;
};
bool comp(input a, input b)
{   if(a.priority==b.priority){
    a.at>b.at;
}
    return (a.priority < b.priority);
}
void findTurnAroundTime(input proc[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}
void findWaitingTime(input proc[], int n, int wt[])
{
    int service[50];

    // Initialising initial elements of the arrays
    service[0] = proc[0].at;
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        service[i] = proc[i - 1].bt + service[i - 1];

        wt[i] = service[i] - proc[i].at;

        // If waiting time is negative, change it into zero

        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
    }
}
void findAvg(input proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    wt[0] = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    cout << "\nStart_time  "
         << " Complete time "
         << " Waiting time  "
         << " Turn around time\n";

    int stime[50], ctime[50];

    stime[0] = proc[0].at;
    ctime[0] = stime[0] + tat[0];

    // calculating starting and ending time
    for (int i = 1; i < n; i++)
    {
        stime[i] = ctime[i - 1];
        ctime[i] = stime[i] + tat[i] - wt[i];
    }

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout <<stime[i]<< "\t\t" << ctime[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "  " << proc[i].priority << endl;
    }

    float avg_wt = total_wt /n;
    float avg_tat = total_tat /n;
    cout << "Average wait time is " << avg_wt << endl;
    cout << "Average turn around time is " << avg_tat << endl;
}
void prioritySchel(input proc[], int n)
{
    // Sort processes by priority
    sort(proc, proc + n, comp);

    cout << "Order in which processes gets executed \n";
    for (int i = 0; i < n; i++)
        cout << proc[i].pid << " ";
    cout << endl;
    findAvg(proc, n);

    // calculating waiting time
    // for (int  i = 1; i < n ; i++ )
    //     wt[i] =  bt[i] + wt[i-1] ;

    // turnaround time by adding initial by burst time
    // for (int  i = 0; i < n ; i++)
    //     tat[i] = bt[i] + wt[i];

    // for(int i=0;i<n;i++){
    //     total_wt=total_wt+wt[i];
    //     total_tat = total_tat+tat[i];
    //     cout<<proc[i].pid<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"  "<<proc[i].priority<<endl;
    // }

    // int avg_wt = total_wt/n;
    // int avg_tat = total_tat/n;
    // cout<<"Average wait time is "<<avg_wt<<endl;
    // cout<<"Average turn around time is "<<avg_tat<<endl;
}
int main()
{
    // input p[] = {{1,0,5,2},{2,1,4,1},{3,2,6,3}};
    input c[] = {{1, 0, 4, 4}, {2, 1, 5, 5}, {3, 2, 1, 7}, {4, 3, 2, 2}, {5, 4, 3, 1}, {6, 5, 6, 6}};
    int n = 3;
    prioritySchel(c, 6);
}