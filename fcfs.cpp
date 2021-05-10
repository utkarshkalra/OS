#include <iostream>
#define MAX_PROCESS 10
using namespace std;

class process
{
public:
  int arrival;
  int burst;
  int completion;
  int tat;
  int wt;
  int process_num;
  void input_process(int);
};
void process::input_process(int count)
{
  process_num = count + 1;
  cout << "\n enter arrival time for process " << count + 1 << ":";
  cin >> arrival;
  cout << "\n enter burst time for process" << count + 1 << ":";
  cin >> burst;
}
void display(process *, int);
void average(process *, int);
int main()
{
  process p[MAX_PROCESS], temp;
  int n, i, j;
  cout << "enter number of process :";
  cin >> n;
  for (i = 0; i < n; i++)
    p[i].input_process(i);

  //sorting

  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (p[i].arrival > p[j].arrival)
      {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }

  p[0].completion = p[0].arrival + p[0].burst;
  for (i = 1; i < n; i++)
  {
    if (p[i - 1].completion > p[i].arrival)
    {
      p[i].completion = p[i - 1].completion + p[i].burst;
    }
    else
      p[i].completion = p[i].arrival + p[i].burst;
  }

  for (i = 0; i < n; i++)
  {
    p[i].tat = p[i].completion - p[i].arrival;
  }
  for (i = 0; i < n; i++)
  {
    p[i].wt = p[i].tat - p[i].burst;
  }
  display(p, n);
  average(p, n);
  return 0;
}
void display(process *p, int n)
{
  cout << "process"
       << " "
       << "Arrival"
       << " "
       << "Bursttime"
       << " "
       << "COMPLETIONTIME"
       << " "
       << "TURNAROUND_TIME"
       << " "
       << "WAITING_TIME\n";
  for (int i = 0; i < n; i++)
  {
    cout << "\nP" << p[i].process_num << "\t\t" << p[i].arrival << "\t\t" << p[i].burst << "\t\t" << p[i].completion << "\t\t" << p[i].tat << "\t\t" << p[i].wt;
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
