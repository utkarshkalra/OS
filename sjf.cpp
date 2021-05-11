#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>
using namespace std;

class process
{
public:
    int pid;
    int at;
    int bt;
    int st;
    int ct;
    int tat;
    int wt;
    int rt;
};

int main()
{

    int n;
    process p[100];
    float avg_tat;
    float avg_wt;
    float avg_rt;

    int total_tat = 0;
    int total_wt = 0;
    int total_rt = 0;

    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));

    cout << setprecision(2) << fixed;

    //getting input

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].at;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].bt;
        p[i].pid = i + 1;
        cout << endl;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while (completed != n)
    {
        int idx = -1;
        int mn = 10000000;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= current_time && is_completed[i] == 0)
            {
                if (p[i].bt < mn)
                {
                    mn = p[i].bt;
                    idx = i;
                }
                if (p[i].bt == mn)
                {
                    if (p[i].at < p[idx].at)
                    {
                        mn = p[i].bt;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            p[idx].st = current_time;
            p[idx].ct = p[idx].st + p[idx].bt;
    
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].rt = p[idx].st - p[idx].at;

            total_tat += p[idx].tat;
            total_wt += p[idx].wt;
            total_rt += p[idx].rt;

            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].ct;
            prev = current_time;
        }
        else
        {
            current_time++;
        }
    }


    avg_tat = (float)total_tat / n;
    avg_wt = (float)total_wt / n;
    avg_rt = (float)total_rt / n;

    cout << endl
         << endl;

    cout << "#P\t"
         << "AT\t"
         << "BT\t"
         << "ST\t"
         << "CT\t"
         << "TAT\t"
         << "WT\t"
         << "RT\t"
         << "\n"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\t"
             << "\n"
             << endl;
    }
    cout << "Average Turnaround Time = " << avg_tat << endl;
    cout << "Average Waiting Time = " << avg_wt << endl;
    cout << "Average Response Time = " << avg_rt << endl;

}