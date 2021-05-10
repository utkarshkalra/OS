#include <iostream>
#define MAX_PROCESS 10
using namespace std;

class process{
    public:
int arrival;
int burst;
int completion;
int priority;
int tat;
int wt;
int process_num;
void input_process(int);
};

void process::input_process(int count){
    process_num=count +1;
cout<<"\n enter priority for process "<<count +1<<":";
cin>>priority;
cout<<"\n enter arrival time for process "<<count +1<<":";
cin>>arrival;
cout<<"\n enter burst time for process"<<count +1<<":";
cin>>burst;
}

void display(process*,int);
void average(process*,int);

int main()
{
process p[MAX_PROCESS],temp;
int is_completed[100]={0};

int n,i;
cout<<"enter number of process :";
cin>>n;
cout<<"\n priority assign to each process must be from 0-10"<<endl;
// taking input//
for(i=0;i<n;i++){
    p[i].input_process(i);
}

int current_time=0;
int completed=0;

while(completed!=n){
    int idx=-1;
    int mn=100;
 // finding process with least priority among the ready queue//
 for(i=0;i<n;i++){
    if(p[i].arrival<=current_time && is_completed[i]==0){
        if(p[i].priority<mn){
            mn=p[i].priority;
            idx=i;
        } //if priority is equal then on arrival time//
        if(p[i].priority==mn){
           if(p[i].arrival<p[idx].arrival){
            mn=p[i].priority;
            idx=i;
        }
       }
    }
 }  //putting process in CPU //
 if (idx!=-1){
    current_time= current_time+p[idx].burst;
    p[idx].completion=current_time;
    completed++;
    is_completed[idx]=1;
 }
 else
  current_time++;
}
 // TurnAround_time & Waiting_time //
for(i=0;i<n;i++){
    p[i].tat=p[i].completion - p[i].arrival;
}
for(i=0;i<n;i++){
    p[i].wt = p[i].tat - p[i].burst;
}

display(p,n);
average(p,n);


    return 0;
}

void display (process*p,int n)
{

  cout <<"PROCESS"<<"  "<<"ARRIVAL_TIME"<<"  "<<"BURST_TIME"<<"  "<<"COMPLETION_TIME"<<"  "<<"TURNAROUND_TIME"<<"  "<<"WAITING_TIME\n";
for( int i=0;i<n;i++){
cout<<"\nP"<<p[i].process_num<<"\t"<<p[i].arrival<<"\t"<<p[i].burst<<"\t"<<p[i].completion<<"\t"<<p[i].tat<<"\t"<<p[i].wt;
  }
}

void average(process*p,int n){
    float Avg_wt=0,Avg_tat=0;
  for(int i=0;i<n;i++)
    {
    Avg_wt=Avg_wt + p[i].wt;
    Avg_tat=Avg_tat + p[i].tat;
  }
  Avg_wt=Avg_wt/n;
  Avg_tat=Avg_tat/n;
  cout<<"\n AVERAGE_WAITING_TIME :"<<Avg_wt;
  cout<<"\n AVERAGE_TURNAROUND_TIME :"<<Avg_tat;
}
