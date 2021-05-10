#include <bits/stdc++.h>
using namespace std;

class process
{
public:
    int pid, at, bt, btrem, st, ct, tt, wt, rt;

};

void display(process *p, int n)
{
    cout << "Pi"
         << "\t"
         << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "CT"
         << "\t"
         << "TaT"
         << "\t"
         << "WT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nP" << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tt << "\t" << p[i].wt;
    }
}

bool sortfunction(process p1, process p2)
{
    return p1.at < p2.at;
}

bool compare2(process p1, process p2)
{
    return p1.pid < p2.pid;
}

int main()
{
    int n;
    int timeQ;
    int index;

    int total_tt = 0;
    int total_wt = 0;
    int total_rt = 0;

    cout << "Enter Number of processes :";
    cin >> n;
    cout << endl;

    cout << "Enter Time Quantum :";
    cin >> timeQ;
    cout << endl;

    process p[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].at;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].bt;
        p[i].btrem = p[i].bt;
        p[i].pid = i + 1;
        cout << endl;
    }

    sort(p, p + n, sortfunction);

    queue<int> rq; //index store for ready state

    int timer = 0;
    rq.push(0);
    int doneprocess = 0;
    int mark[100];
    memset(mark, 0, sizeof(mark));

    mark[0]=1;

    while (doneprocess != n)
    {
        index = rq.front();
        rq.pop();

        if (p[index].btrem == p[index].bt)
        {
            p[index].st = max(timer, p[index].at); //idle time ka khyal
            timer = p[index].st;
        }

        if (p[index].btrem-timeQ > 0)
        {
            p[index].btrem -= timeQ;
            timer += timeQ;
        }

        else
        {
            timer += p[index].btrem;
            p[index].btrem = 0;
            doneprocess++;
            
            p[index].ct = timer;
            p[index].tt = p[index].ct - p[index].at;
            p[index].wt = p[index].tt - p[index].bt;
            p[index].rt = p[index].st - p[index].at;

            total_tt += p[index].tt;
            total_wt += p[index].wt;
            total_rt = p[index].rt;
            
            
        }

        //ab unhe daal jo timeQ hone tak queue m aajaaye hongi

        for (int i = 1; i < n; i++)
        {
            if (p[i].btrem > 0 && p[i].at <= timer && mark[i] == 0)
            {
                rq.push(i);
                mark[i] == 1;
            }
        }

        //agar process abhi bhi bachi h to usse bhi daal dubara

        if (p[index].btrem > 0)
            rq.push(index);

        //jab queue khali hojaaye

        if (rq.empty())
        {
            for (int i = 1; i < n; i++)
            {
                if (p[i].btrem > 0)
                {
                    rq.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }

       
    }

    float avg_tt;
    float avg_wt;
    float avg_rt;

    float throughput;


    avg_tt = total_tt / n;
    avg_wt = total_wt / n;
    avg_rt = total_rt / n;

    cout<<endl;

    //display
    display(p,n);

    cout << "\n AVERAGE_WAITING_TIME :" << avg_wt;
    cout << "\n AVERAGE_TURNAROUND_TIME :" << avg_tt;
    cout << "\nAVERAGE_RESPONSE_TIME :" << avg_rt << endl;

    return 0;
}