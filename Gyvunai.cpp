#include <iostream>
#include <locale>
#include <fstream>

using namespace std;
struct gyv
{
    int hn;
    int hi;
    int mn;
    int mi;
};
int main()
{
    ifstream in("U1.txt");
    ofstream out("U1rez.txt");
    int n;
    in >> n;
    gyv info[n];
    for (int i = 0; i < n; i++)
    {
        in >> info[i].hn >> info[i].hi >> info[i].mn >> info[i].mi;
    }
    for (int i = 0; i < n; i++)
    {
        if (info[i].hn < 24)
        {
            info[i].hn += 24;
        }
        if (info[i].hi < 24)
        {
            info[i].hi += 24;
        }
        if (info[i].mn < 24)
        {
            info[i].mn += 24;
        }
        if (info[i].mi < 24)
        {
            info[i].mi += 24;
        }
        else{}
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n-1)
        {
            cout << info[i].hn << " " << info[i+1].hn << endl;
            if (info[i].hn > info[i+1].hn)
            {
                info[i+1].hn = info[i].hn;
                info[i+1].mn = info[i].mn;
            }
            else if (info[i].hn < info[i+1].hn)
            {
                info[i+1].hn = info[i+1].hn;
                info[i+1].mn = info[i+1].mn;
            }
            else if ((info[i].hn == info[i+1].hn) && (info[i].mn < info[i+1].mn))
            {
                info[i+1].hn = info[i].hn;
                info[i+1].mn = info[i].mn;
            }
            else if ((info[i].hn == info[i+1].hn) && (info[i].mn > info[i+1].mn))
            {
                info[i+1].hn = info[i+1].hn;
                info[i+1].mn = info[i+1].mn;
            }
        }
       /* else if (i == n-1){
            if (info[i].hn > info[i-1].hn)
            {
                info[i].hn = info[i].hn;
                info[i].mn = info[i].mn;
            }
            else if (info[i].hn < info[i-1].hn)
            {
                info[i].hn = info[i-1].hn;
                info[i].mn = info[i-1].mn;
            }
            else if ((info[i].hn == info[i+1].hn) && (info[i].mn < info[i-1].mn))
            {
                info[i].hn = info[i].hn;
                info[i].mn = info[i].mn;
            }
            else if ((info[i].hn == info[i+1].hn) && (info[i].mn > info[i-1].mn))
            {
                info[i].hn = info[i-1].hn;
                info[i].mn = info[i-1].mn;
            }
        }*/
    }
        for (int i = 0; i < n; i++)
    {
        if (info[i].hn > 24)
        {
            info[i].hn -= 24;
        }
        if (info[i].hi > 24)
        {
            info[i].hi -= 24;
        }
        if (info[i].mn > 24)
        {
            info[i].mn -= 24;
        }
        if (info[i].mi > 24)
        {
            info[i].mi -= 24;
        }
    }
    for (int i = 0; i < n; i++){
        out << info[i].hn << " " << info[i].hi << " " << info[i].mn << " " << info[i].mi << endl;
    }
    return 0;
}
