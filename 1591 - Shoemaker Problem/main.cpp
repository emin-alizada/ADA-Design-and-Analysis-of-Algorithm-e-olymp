#include <cstdio>
#include <algorithm>
using namespace std;

int i, n, t, fine;

class Work
{
public:
    int time, fine, id;
    Work (int time = 0, int fine = 0, int id = 0) : time(time), fine(fine), id(id) {};
};

Work *Jobs;

int f(Work a, Work b)
{
    //  a.time   b.time
    //  ------ < ------
    //  a.fine   b.fine
    if (a.time * b.fine == b.time * a.fine) return a.id < b.id;
    return a.time * b.fine < b.time * a.fine;
}

int main(void)
{
    while(scanf("%d",&n) == 1)
    {
        Jobs = new Work[n];
        for(i = 0; i < n; i++)
        {
            scanf("%d %d",&t, &fine);
            Jobs[i] = Work(t,fine,i+1);
        }

        sort(Jobs,Jobs+n,f);

        printf("%d",Jobs[0].id);
        for(i = 1; i < n; i++)printf(" %d",Jobs[i].id);
        printf("\n");

        delete[] Jobs;
    }
}
