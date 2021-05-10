#include <iostream>
using namespace std;

class process
{
public:
  int arrival;
  int burst;
  int completion;
  int start_time;
  int tat;
  int wt;
  int rt;
  int process_num;
  void input_process(int);
};


void display(process *, int);
void average(process *, int);

int main()
{
  process p[10];
  int burst_remaining[100];
  int is_completed[100] = {0};

  int n, i, j;
  cout << "enter number of process :";
  cin >> n;

  for (i = 0; i < n; i++)
  {
    p[i].process_num = i + 1;
    cout << "enter arrival time for process " << i + 1 << ":";
    cin >> p[i].arrival;
    cout << "enter burst time for process" << i + 1 << ":";
    cin >> p[i].burst;
    cout << endl;
    burst_remaining[i] = p[i].burst;
  }

  int current_time = 0;
  int completed = 0;

  while (completed != n)
  {
    int idx = -1;
    int mn = 100000;
    // finding process with least burst time among the ready queue//
    for (i = 0; i < n; i++)
    {
      if (p[i].arrival <= current_time && is_completed[i] == 0)
      {
        if (burst_remaining[i] < mn)
        {
          mn = burst_remaining[i];
          idx = i;
        } //if burst time is equal then on arrival time//
        if (burst_remaining[i] == mn)
        {
          if (p[i].arrival < p[idx].arrival)
          {
            mn = burst_remaining[i];
            idx = i;
          }
        }
      }
    }
    //  putting process into CPU after selecting from ready queue   //
    if (idx != -1)
    {
      if (burst_remaining[idx] == p[idx].burst)
      {
        p[idx].start_time = current_time;
      }
      burst_remaining[idx] -= 1;
      current_time++;

      if (burst_remaining[idx] == 0)
      {
        p[idx].completion = current_time;
        is_completed[idx] = 1;
        completed++;
      }
    }
    else
      current_time++;
  }
  
  for (i = 0; i < n; i++)
  {
    p[i].tat = p[i].completion - p[i].arrival;
  }
  for (i = 0; i < n; i++)
  {
    p[i].wt = p[i].tat - p[i].burst;
  }
  for (i = 0; i < n; i++)
    p[i].rt = p[i].start_time - p[i].arrival;

  display(p, n);
  average(p, n);

  return 0;
}

void display(process *p, int n)
{
  cout << "PROCESS"
       << " "
       << "ARRIVAL_TIME"
       << " "
       << "BURST_TIME"
       << " "
       << "COMPLETION_TIME"
       << " "
       << "TURNAROUND_TIME"
       << " "
       << "WAITING_TIME"
       << " "
       << "RESPONSE_TIME\n";
  for (int i = 0; i < n; i++)
  {
    cout << "\nP" << p[i].process_num << "\t\t" << p[i].arrival << "\t\t" << p[i].burst << "\t\t" << p[i].completion << "\t\t" << p[i].tat << "\t\t" << p[i].wt << "\t\t" << p[i].rt;
  }
}

void average(process *p, int n)
{
  float Avg_wt = 0, Avg_tat = 0;
  for (int i = 0; i < n; i++)
  {
    Avg_wt = Avg_wt + p[i].wt;
    Avg_tat = Avg_tat + p[i].tat;
  }
  Avg_wt = Avg_wt / n;
  Avg_tat = Avg_tat / n;
  cout << "\n AVERAGE_WAITING_TIME :" << Avg_wt;
  cout << "\n AVERAGE_TURNAROUND_TIME :" << Avg_tat;
}
