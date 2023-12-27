#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int startTime;
    int finishTime;
    int turnaroundTime;
    int waitingTime;
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    float avg_turnaround_time;
    float avg_waiting_time;
};
bool comparePriority(Process a, Process b) {

    return a.priority < b.priority;
}
bool compareArrivalTime(Process a, Process b) {

    return a.arrival_time < b.arrival_time;
}
bool compareBurstTime(Process a, Process b) {

    return a.burst_time < b.burst_time;
}
float FCFS()
 {
    int n;
    int i = 0;
    struct Process p[100];
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    float avg_turnaround_time;
    float avg_waiting_time;


    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrivalTime;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burstTime;
        p[i].id = i+1;
        cout<<endl;
    }
    cout<< "\n";
    cout<< "\t" "We have the following data for calculating gantt chart "<< "\n";
    cout<<endl<< "\t"<<"______________________________________" <<endl;
    cout<< "\t"<< "Proceeses | Arrival time | Burst time "<<endl;
    for(int i = 0; i<n ; i++)
    {
        cout<<"\t"<<"P" << i + 1<<"        |"<<p[i].arrivalTime<<"             |"<<p[i].burstTime<<endl;
    }
    cout<< "\t"<<"_______________________________________"<<endl;
    cout<<"\n";

    int current_Time = 0;
    for ( i = 0; i < n; i++)
    {
        if (current_Time < p[i].arrivalTime)
        {
            current_Time = p[i].arrivalTime;
        }

        p[i].startTime = current_Time;
        current_Time += p[i].burstTime;
        p[i].finishTime = current_Time;

        p[i].turnaroundTime = p[i].finishTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;

        total_turnaround_time += p[i].turnaroundTime;
        total_waiting_time += p[i].waitingTime;


    }

    cout << "\t"<< "Gantt Chart: "<<endl;
    for ( i = 0; i < n; i++)
    {
        cout<< "__________";
    }
    cout<<endl;
    for (i = 0; i < n; i++)
    {
    cout << "P" << p[i].id << "       |";
    }
    cout<<endl;
    for (i = 0; i < n; i++)
    {
        cout<< "__________";
    }
    cout<<endl;
    cout<< "0";
    for (i = 0; i < n; i++)
    {
        cout<<"\t"<<p[i].finishTime<< "     ";
    }

    cout<<endl;
    cout<< "Turn Around Time is:"<<endl;
    for (i = 0; i < n; i++)
    {
       cout<< "p"<< p[i].id<< "="<<p[i].turnaroundTime<<endl;
    }
    cout<< "Waiting Time is:"<<endl;
    for (i = 0; i < n; i++)
    {
       cout<< "p"<< p[i].id<< "="<<p[i].waitingTime<<endl;
    }

    int totalProcesses = n;
    avg_turnaround_time = static_cast<double>(total_turnaround_time) / totalProcesses;
    avg_waiting_time = static_cast<double>(total_waiting_time)/totalProcesses;
    double throughput = static_cast<double>(totalProcesses) / current_Time;
    cout << "Average Turnaround Time: = "<<total_turnaround_time<< "/"<<totalProcesses<< "\t"<< "=" << avg_turnaround_time << endl;
    cout << "Average Waiting Time: = " <<total_waiting_time<< "/"<< totalProcesses<< "\t"<< "="<< avg_waiting_time << endl;
    cout << "Throughput: = " << throughput << " processes per time unit" << endl;

    return avg_waiting_time;
}

float SJF_Non_Preemptive()
 {
    int n;
    int i = 0;
    struct Process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrivalTime;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burstTime;
        p[i].id = i+1;
        cout<<endl;
    }
    cout<< "\n";
    cout<< "\t" "We have the following data for calculating gantt chart "<< "\n";
    cout<<endl<< "\t"<<"________________________________________________" <<endl;
    cout<< "\t"<< "Proceeses | Arrival time | Burst time |"<<endl;
    for(int i = 0; i<n ; i++)
    {
        cout<<"\t"<<"P" << i + 1<<"        |"<<p[i].arrivalTime<<"             |"<<p[i].burstTime<<endl;
    }
    cout<< "\t"<<"_________________________________________________"<<endl;
    cout<<"\n";


    // Sort from the second element if arrival times are the same
    for ( i = 0; i < n; i++)
    {


        if (p[0].arrivalTime == p[1].arrivalTime)
        {
        sort(p,p+n, compareBurstTime);
        }
        else
        {
        sort(p,p+n, compareArrivalTime);
        }
    }
    int current_Time = 0;
    for ( i = 0; i < n; i++)
    {
        if (current_Time < p[i].arrivalTime)
        {
            current_Time = p[i].arrivalTime;
        }

        p[i].startTime = current_Time;
        current_Time += p[i].burstTime;
        p[i].finishTime = current_Time;

        p[i].turnaroundTime = p[i].finishTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;

        total_turnaround_time += p[i].turnaroundTime;
        total_waiting_time += p[i].waitingTime;


    }

    cout << "\t"<< "Gantt Chart: "<<endl;
    for ( i = 0; i < n; i++)
    {
        cout<< "__________";
    }
    cout<<endl;
    for (i = 0; i < n; i++)
    {
    cout << "P" << p[i].id << "       |";
    }
    cout<<endl;
    for (i = 0; i < n; i++)
    {
        cout<< "__________";
    }
    cout<<endl;
    cout<< "0";
    for (i = 0; i < n; i++)
    {
        cout<<"\t"<<p[i].finishTime<< "     ";
    }

    cout<<endl;
    cout<< "Turn Around Time is:"<<endl;
    for (i = 0; i < n; i++)
    {
       cout<< "p"<< p[i].id<< "="<<p[i].turnaroundTime<<endl;
    }
    cout<< "Waiting Time is:"<<endl;
    for (i = 0; i < n; i++)
    {
       cout<< "p"<< p[i].id<< "="<<p[i].waitingTime<<endl;
    }

    int totalProcesses = n;
    avg_turnaround_time = static_cast<double>(total_turnaround_time) / totalProcesses;
    avg_waiting_time = static_cast<double>(total_waiting_time)/totalProcesses;
    double throughput = static_cast<double>(totalProcesses) / current_Time;
    cout << "Average Turnaround Time: = "<<total_turnaround_time<< "/"<<totalProcesses<< "\t"<< "=" << avg_turnaround_time << endl;
    cout << "Average Waiting Time: = " <<total_waiting_time<< "/"<< totalProcesses<< "\t"<< "="<< avg_waiting_time << endl;
    cout << "Throughput: = " << throughput << " processes per time unit" << endl;

    return avg_waiting_time;
}

float SRTF_Preemptive()
{
    int n;
    struct Process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        p[i].pid = i+1;
        burst_remaining[i] = p[i].burst_time;
        cout<<endl;
    }
    cout<< "\n";
    cout<< "\t" "We have the following data for calculating gantt chart "<< "\n";
    cout<<endl<< "\t"<<"______________________________________" <<endl;
    cout<< "\t"<< "Proceeses | Arrival time | burst_time "<<endl;
    for(int i = 0; i<n ; i++)
    {
        cout<<"\t"<<"P" << i + 1<<"        |"<<p[i].arrival_time<<"           |"<<p[i].burst_time<<endl;
    }
    cout<< "\t"<<"_______________________________________"<<endl;
    cout<<"\n";

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while(completed != n) {
        int idx = -1;
        int mn = 10000000;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) {
                if(burst_remaining[i] < mn) {
                    mn = burst_remaining[i];
                    idx = i;
                }
                if(burst_remaining[i] == mn) {
                    if(p[i].arrival_time < p[idx].arrival_time) {
                        mn = burst_remaining[i];
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            if(burst_remaining[idx] == p[idx].burst_time) {
                p[idx].start_time = current_time;
                total_idle_time += p[idx].start_time - prev;
            }
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;

            if(burst_remaining[idx] == 0) {
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

                total_turnaround_time += p[idx].turnaround_time;
                total_waiting_time += p[idx].waiting_time;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else {
             current_time++;
        }
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for(int i = 0; i < n; i++) {
        min_arrival_time = min(min_arrival_time,p[i].arrival_time);
        max_completion_time = max(max_completion_time,p[i].completion_time);
    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;

    throughput = float(n) / (max_completion_time - min_arrival_time);

    cout<<endl<<endl;
    cout << "\t"<< "Gantt Chart: "<<endl;
    for(int i = 0; i < n; i++){
    cout<< "___________________";
    }
    cout<<endl;
   for(int i = 0; i < n; i++)
    {
        if (p[0].arrival_time == p[1].arrival_time)
        {
        sort(p,p+n, compareBurstTime);
         cout << "P" << p[i].pid <<"      |";
        }
        else
        {
            do
            {
                sort(p,p+n, compareArrivalTime);
                 cout << "P" << p[i].pid <<"      |";

                i++;
            }
            while(i<n-1);
            for(int i = 0; i < n; i++)
            {

                sort(p,p+n, compareBurstTime);
                cout << "P" << p[i].pid <<"      |";
            }
        }
    }



    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<< "___________________";
    }
    cout<<endl;
    cout<<"0";

    for(int i = 0; i < n; i++)
    {
        if (p[0].arrival_time == p[1].arrival_time)
        {
        sort(p,p+n, compareBurstTime);
        cout<<"\t"<<p[i].completion_time;
        }
        else
        {
            do
            {
                sort(p,p+n, compareArrivalTime);
                cout<< "\t"<<p[i+1].arrival_time;

                i++;
            }
            while(i<n-1);
            for(int i = 0; i < n; i++)
            {

                sort(p,p+n, compareBurstTime);
                cout<<"\t"<<p[i].completion_time;
            }
        }
    }

    cout<<"\n";
    cout<< "Turn Around Time is:"<<endl;
    for(int i = 0; i < n; i++)
    {
       cout<< "p"<< p[i].pid<< "="<<p[i].turnaround_time<<endl;
    }
    cout<< "Waiting Time is:"<<endl;
    for(int i = 0; i < n; i++)
    {
       cout<< "p"<< p[i].pid<< "="<<p[i].waiting_time<<endl;
    }
    cout<<endl;
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
    cout<<"Throughput = "<<throughput<<" process/unit time"<<endl;
    return avg_waiting_time + avg_turnaround_time;

    return avg_waiting_time;
}

float Priority_Non_Preemptive()
 {
    int n;
    int i = 0;
    struct Process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrivalTime;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burstTime;
        cout<<"Enter priority of process "<<i+1<<": ";
        cin>>p[i].priority;
        p[i].id = i+1;
        cout<<endl;
    }
    cout<< "\n";
    cout<< "\t" "We have the following data for calculating gantt chart "<< "\n";
    cout<<endl<< "\t"<<"________________________________________________" <<endl;
    cout<< "\t"<< "Proceeses | Arrival time | Burst time | Priority "<<endl;
    for(int i = 0; i<n ; i++)
    {
        cout<<"\t"<<"P" << i + 1<<"        |"<<p[i].arrivalTime<<"             |"<<p[i].burstTime<<"           |"<<p[i].priority<<endl;
    }
    cout<< "\t"<<"_________________________________________________"<<endl;
    cout<<"\n";


    // Sort from the second element if arrival times are the same
    for ( i = 0; i < n; i++)
    {


    if (p[0].arrivalTime == p[1].arrivalTime) {
        sort(p,p+n, comparePriority);
    } else {
        sort(p,p+n, compareArrivalTime);
    }
    }



    int current_Time = 0;

    for ( i = 0; i < n; i++)
    {
        if (current_Time < p[i].arrivalTime)
        {
            current_Time = p[i].arrivalTime;
        }

        p[i].startTime = current_Time;

        current_Time += p[i].burstTime;
        p[i].finishTime = current_Time;

        p[i].turnaroundTime = p[i].finishTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;

        total_turnaround_time += p[i].turnaroundTime;
        total_waiting_time += p[i].waitingTime;


    }

    cout << "\t"<< "Gantt Chart: "<<endl;
    for ( i = 0; i < n; i++)
    {
        cout<< "________________";
    }
    cout<<endl;
    for (i = 0; i < n; i++)
    {
    cout << "P" << p[i].id << "       |";
    }
    cout<<endl;
    for (i = 0; i < n; i++)
    {
        cout<< "________________";
    }
    cout<<endl;
    cout<< "0";
    for (i = 0; i < n; i++)
    {
        cout<<"\t"<<p[i].finishTime<< "     ";
    }

    cout<<endl;
    cout<< "Turn Around Time is:"<<endl;
    for (i = 0; i < n; i++)
    {
       cout<< "p"<< p[i].id<< "="<<p[i].turnaroundTime<<endl;
    }
    cout<< "Waiting Time is:"<<endl;
    for (i = 0; i < n; i++)
    {
       cout<< "p"<< p[i].id<< "="<<p[i].waitingTime<<endl;
    }

    int totalProcesses = n;
    avg_turnaround_time = static_cast<double>(total_turnaround_time) / totalProcesses;
    avg_waiting_time = static_cast<double>(total_waiting_time)/totalProcesses;
    double throughput = static_cast<double>(totalProcesses) / current_Time;
    cout << "Average Turnaround Time: = "<<total_turnaround_time<< "/"<<totalProcesses<< "\t"<< "=" << avg_turnaround_time << endl;
    cout << "Average Waiting Time: = " <<total_waiting_time<< "/"<< totalProcesses<< "\t"<< "="<< avg_waiting_time << endl;
    cout << "Throughput: = " << throughput << " processes per time unit" << endl;

    return avg_waiting_time;
}

float Priority_Preemptive()
{
    int n;
    struct Process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        cout<<"Enter priority of process "<<i+1<<": ";
        cin>>p[i].priority;
        p[i].pid = i+1;
        burst_remaining[i] = p[i].burst_time;
        cout<<endl;
    }
    cout<< "\n";
    cout<< "\t" "We have the following data for calculating gantt chart "<< "\n";
    cout<<endl<< "\t"<<"______________________________________" <<endl;
    cout<< "\t"<< "Proceeses | Arrival time | burst_time "<<endl;
    for(int i = 0; i<n ; i++)
    {
        cout<<"\t"<<"P" << i + 1<<"        |"<<p[i].arrival_time<<"            |"<<p[i].burst_time<<endl;
    }
    cout<< "\t"<<"_______________________________________"<<endl;
    cout<<"\n";

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while(completed != n) {
        int idx = -1;
        int mn = 10000000;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) {
                if(burst_remaining[i] < mn) {
                    mn = burst_remaining[i];
                    idx = i;
                }
                if(burst_remaining[i] == mn) {
                    if(p[i].arrival_time < p[idx].arrival_time) {
                        mn = burst_remaining[i];
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            if(burst_remaining[idx] == p[idx].burst_time) {
                p[idx].start_time = current_time;
                total_idle_time += p[idx].start_time - prev;
            }
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;

            if(burst_remaining[idx] == 0) {
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

                total_turnaround_time += p[idx].turnaround_time;
                total_waiting_time += p[idx].waiting_time;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else {
             current_time++;
        }
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for(int i = 0; i < n; i++) {
        min_arrival_time = min(min_arrival_time,p[i].arrival_time);
        max_completion_time = max(max_completion_time,p[i].completion_time);
    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;

    throughput = float(n) / (max_completion_time - min_arrival_time);

    cout<<endl<<endl;
    cout << "\t"<< "Gantt Chart: "<<endl;
    for(int i = 0; i < n; i++){
    cout<< "___________________";
    }
    cout<<endl;
   for(int i = 0; i < n; i++)
    {
        if (p[0].arrival_time == p[1].arrival_time)
        {
        sort(p,p+n, comparePriority);
         cout << "P" << p[i].pid <<"      |";
        }
        else
        {
            do
            {
                sort(p,p+n, compareArrivalTime);
                 cout << "P" << p[i].pid <<"      |";

                i++;
            }
            while(i<n-1);
            for(int i = 0; i < n; i++)
            {

                sort(p,p+n, comparePriority);
                cout << "P" << p[i].pid <<"      |";
            }
        }
    }



    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<< "___________________";
    }
    cout<<endl;
    cout<<"0";

    for(int i = 0; i < n; i++)
    {
        if (p[0].arrival_time == p[1].arrival_time)
        {
        sort(p,p+n, comparePriority);
        cout<<"\t"<<p[i].completion_time;
        }
        else
        {
            do
            {
                sort(p,p+n, compareArrivalTime);
                cout<< "\t"<<p[i].arrival_time;

                i++;
            }
            while(i<n-1);
            for(int i = 0; i < n; i++)
            {

                sort(p,p+n, compareBurstTime);
                cout<<"\t"<<p[i].completion_time;
            }
        }
    }

    cout<<"\n";
    cout<< "Turn Around Time is:"<<endl;
    for(int i = 0; i < n; i++)
    {
       cout<< "p"<< p[i].pid<< "="<<p[i].turnaround_time<<endl;
    }
    cout<< "Waiting Time is:"<<endl;
    for(int i = 0; i < n; i++)
    {
       cout<< "p"<< p[i].pid<< "="<<p[i].waiting_time<<endl;
    }
    cout<<endl;
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
    cout<<"Throughput = "<<throughput<<" process/unit time"<<endl;
    return avg_waiting_time + avg_turnaround_time;

    return avg_waiting_time;

}

float compareProcesses()
{
    float a = FCFS();
    float b = SJF_Non_Preemptive();
    float c = SRTF_Preemptive();
    float d = Priority_Non_Preemptive();
    float e = Priority_Preemptive();
    float efficient = 0;
    if(a<b && a<c && a<d && a<e)
    {
        cout<< "FCFS is the efficient Algorithm of All :";
    }
    else if(b<a && b<c && b<d && b<e)
    {
        cout<< "SJF_non_preemptive is the efficient Algorithm of All :";
    }
    else if(c<a && c<b && c<d && c<e)
    {
        cout<< "SRTF_preemptive is the efficient Algorithm of All :";
    }
    else if(d<a && d<b && d<c && d<e)
    {
        cout<< "Priority_non_preemptive is the efficient Algorithm of All :";
    }
    else if(e<a && e<b && e<c && e<d)
    {
        cout<< "Priority_preemptive is the efficient Algorithm of All :";
    }
}

int main()
{

while(true)
{
    cout<< "\n";
    cout<< "\t"<< "Here are the following algorithms to find the Gantt chart"<<"\n";
    cout<< "\n\t1. FCFS Algorithm:";
    cout<< "\n\t2. SJF Non Preeemptive Algorithm:";
    cout<< "\n\t3. SRTF Preeemptive Algorithm:";
    cout<< "\n\t4.Priority Non Preeemptive Algorithm:";
    cout<< "\n\t5.Priority Preeemptive Algorithm:";
    cout<< "\n\t6.Priority Preeemptive Algorithm:";
    cout<< "\n";
    int choice;
    cout<< "\n\tEnter Any option:";
    cin>>choice;
    cout<< "\n";
    switch(choice)
    {
        case 1:
            cout<<"\t"<< "First come first serve Algorithm!"<<endl;
            cout<< "______________________________________________________"<<"\n";
            FCFS();
            cout<< "______________________________________________________"<<"\n";
        break;
        case 2:
            cout<<"\t"<< "Shortest job first Algorithm!"<<endl;
            cout<< "______________________________________________________"<<"\n";
            SJF_Non_Preemptive();
            cout<< "______________________________________________________"<<"\n";
        break;
        case 3:
            cout<<"\t"<< "Shortest Remaining job first Algorithm!"<<endl;
            cout<< "______________________________________________________"<<"\n";
            SRTF_Preemptive();
            cout<< "______________________________________________________"<<"\n";
        break;
        case 4:
            cout<<"\t"<< "Priority Non Preemptive Algorithm!"<<endl;
            cout<< "______________________________________________________"<<"\n";
            Priority_Non_Preemptive();
            cout<< "______________________________________________________"<<"\n";
        break;
        case 5:
            cout<<"\t"<< "Priority Preemptive Algorithm!"<<endl;
            cout<< "______________________________________________________"<<"\n";
            Priority_Preemptive();
            cout<< "______________________________________________________"<<"\n";
        break;
        case 6:
            cout<<"\t"<< "Comparison of Waiting Time of Algorithms!"<<endl;
            cout<< "______________________________________________________"<<"\n";
            compareProcesses();
            cout<< "______________________________________________________"<<"\n";

}
}

return 0;
}














