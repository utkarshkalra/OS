#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <string.h> 
using namespace std;

struct process {
    int pid;
    int at;
    int bt;
    int priority;
    int st;
    int ct;
    int tt;
    int wt;
    int rt;
};

int main() {

    int n;
    struct process p[100];
    float avg_tt;
    float avg_wt;
    float avg_rt;
 
    int total_tt = 0;
    int total_wt = 0;
    int total_rt = 0;

    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes: ";
    cin>>n;

    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].at;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].bt;
        cout<<"Enter priority of the process "<<i+1<<": ";
        cin>>p[i].priority;
        p[i].pid = i+1;
        burst_remaining[i] = p[i].bt;
        cout<<endl;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while(completed != n) {
        int idx = -1;
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(p[i].at <= current_time && is_completed[i] == 0) {
                if(p[i].priority > mx) {
                    mx = p[i].priority;
                    idx = i;
                }
                if(p[i].priority == mx) {
                    if(p[i].at < p[idx].at) {
                        mx = p[i].priority;
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            if(burst_remaining[idx] == p[idx].bt) {
                p[idx].st = current_time;
              
            }
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;
            
            if(burst_remaining[idx] == 0) {
                p[idx].ct = current_time;
                p[idx].tt = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tt - p[idx].bt;
                p[idx].rt = p[idx].st - p[idx].at;

                total_tt += p[idx].tt;
                total_wt += p[idx].wt;
                total_rt += p[idx].rt;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else {
             current_time++;
        }  
    }



    avg_tt = (float) total_tt / n;
    avg_wt = (float) total_wt / n;
    avg_rt = (float) total_rt / n;


    cout<<endl<<endl;

    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"PRI\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].priority<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tt<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_tt<<endl;
    cout<<"Average Waiting Time = "<<avg_wt<<endl;
    cout<<"Average Response Time = "<<avg_rt<<endl;



}