#include <iostream>
#include "include/Calculate.h"
#include "stdio.h"
#include <vector>
#include <map>
#include "time.h"
#include "stdlib.h"
#include "algorithm"
#include "include/Stratege.h"
using namespace std;

int RandomNumber ()
{
    return (::rand()%33);
}


double doubleRand(double a,double b)
{
    double r;
    unsigned int as=rand();
    r=(double)as/RAND_MAX;
    //printf("as;%u,r:%f\n",as,r);
    return a+r*(b-a);
}
int intRand(int a,int b)
{
    return (int)doubleRand(a,b);
}

bool RankPik(float b)
{
    float c=doubleRand(0,1);
    return c<b;
}

int main()
{
    //Calculate test;
    // vector<int> a=test.GetResult();
    //printf("%d%d%d\n",a[0],a[1],a[2]);
    //printf("%d\n",Helper::GetInstance()->GetNumResult()->at(111).at(2));
//    srand(time(NULL));
//    rand();
//    printf( "%lf\n",doubleRand(0,1));
//    for(int i=0;i<100;i++)
//    {
//        printf("%d\n",RankPik(0.1));
//    }
//    return 0;
    int o_times=5000;
    int sys_win_times=0;
    unsigned int all_times_sliver=0;
    int all_sys_win=0;
    for(int j=0; j<o_times; j++)
    {

       printf("##############################################\n");
        Calculate test;
        int times=intRand(17,35);
       // printf("times:%d\n",times);
        std::vector<int > myvector(times);
        generate (myvector.begin(), myvector.end(), RandomNumber);
        for(int i=0; i<times; i++)
        {
            test.AddBet(intRand(50,1000),intRand(50,1000),areas[myvector.at(i)]);
        }
        //test.dump();
        Stratege *s=new BalanceStrage;
        test.SetStratege(s);
        std::vector<int> res= test.GetResult();
        int sys_win=test.GetSilverSysWin();
        if (sys_win>0)
        {
            sys_win_times++;
        }
        all_sys_win+=sys_win;
        unsigned int all_sliver_count=test.GetAllSliverCount();
        all_times_sliver+=all_sliver_count;
       // printf("all_sliver_count:%u,syswin:%d res:%d%d%d\n",all_sliver_count,sys_win,res[0],res[1],res[2]);
    }
    printf("o_times:%d,sys_win_times:%d,all_times_sliver:%d,all_golden_sys_win:%d,all_silver_sys_win:%d,real_times:%d\n",o_times,
           sys_win_times,all_times_sliver, _GP_HELPER_->g_sys_gloab.sys_golden_get, _GP_HELPER_->g_sys_gloab.sys_silver_get,all_sys_win);
    printf("sys_golden_recyle:%d,sys_silver_recyle:%d\n",_GP_HELPER_->g_sys_gloab.sys_golden_recyle,_GP_HELPER_->g_sys_gloab.sys_silver_recyle);
    getchar();
    // printf("%d\n",areas[2]);

    return 0;
}