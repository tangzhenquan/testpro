#include "../include/Stratege.h"
#include "algorithm"
#include "stdio.h"

#define SYS_GOLDEN_MAX_LOSE  (1000000)
#define SYS_SILVER_MAX_LOSE  (1000000)
#define SYS_GOLDEN_RECYLE    (100)
#define SYS_SILVER_RECYLE    (100)
#define SYS_GOLDEN_PERCENT   0.01
#define SYS_SILVER_PERCENT   0.01
bool Stratege::GetSingleResultBySel(const std::vector<int>& goal_vector, const Calculate::CoinsAreaMap_t& bet_map, unsigned int& cur_sys_golden_out, unsigned int& cur_sys_silver_out)
{
    std::vector<int> tem=goal_vector;
    std::sort(tem.begin(),tem.begin()+3);
    int goal=tem.at(0)*100+tem.at(1)*10+tem.at(2);
    std::vector<int> res;
    if(!(Helper::GetInstance()->GetResByGoal(goal,res)))
    {
        return false;
    }
    return GetSingleResultByArea(res,bet_map,cur_sys_golden_out,cur_sys_silver_out);

}


bool Stratege::GetSingleResultByArea(const std::vector<int>& area_vector, const Calculate::CoinsAreaMap_t& bet_map, unsigned int& cur_sys_golden_out, unsigned int& cur_sys_silver_out)
{
    int pre_area=0;
    for(std::vector<int>::const_iterator it=area_vector.begin();
            it!=area_vector.end();
            ++it)
    {
        int area=*it;
        int odd=Helper::GetInstance()->GetOddbyArea(area);
        if(odd==0)
        {
            continue;
        }
        if (area!=pre_area)
        {
            odd+=1;
        }
        pre_area=area;

        Calculate::CoinsAreaMap_t::const_iterator c_it=bet_map.find(area);
        if(c_it==bet_map.end())
        {
            continue;
        }
        int golden_count=c_it->second.golden_count ;
        cur_sys_golden_out+=(odd*golden_count);
        int sliver_count=c_it->second.silver_count ;
        cur_sys_silver_out+=(odd*sliver_count);

    }
    return true;
}


std::vector<int> RandomStratege::GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map,unsigned int all_golden_count,unsigned int all_silver_count)
{
    int b[3]= {0};
    Helper::GetInstance()->Gen(b);

    return std::vector<int>(b,b+3);
}





BalanceStrage::BalanceStrage()
{
       m_sys_win.assign(3,0);

}

std::vector<int> BalanceStrage::GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map, unsigned int all_golden_count, unsigned int all_silver_count)
{

    int b[3]= {0};
    std::vector<int> goal_vector;
    int retry_time=5;

    unsigned int sys_out_silver_count=0;
    unsigned int sys_out_golden_count=0;
    int sys_recyle_golden_count=all_golden_count*SYS_GOLDEN_PERCENT;
    int  sys_recyle_silver_count=all_silver_count*SYS_SILVER_PERCENT;
    for(int i=0; i<=retry_time; ++i)
    {
        m_sys_win[2]++;
        printf("第%d次\n",i+1);
        Helper::GetInstance()->Gen(b);
        goal_vector.assign(b, b+3);
        printf("%d,%d,%d\n",b[0],b[1],b[2]);
        GetSingleResultBySel(goal_vector,bet_map,sys_out_golden_count,sys_out_silver_count);
        printf("all_golden_count:%u,all_silver_count:%u,sys_out_golden_count:%u,sys_out_silver_count:%u\n",all_golden_count,all_silver_count,sys_out_golden_count,sys_out_silver_count);
        if(i==5)
        {
            break;
        }
        bool golden_reset=false;
        bool silver_reset=false;
        if((all_golden_count-sys_out_golden_count>0&& _GP_HELPER_->g_sys_gloab.sys_golden_get>0)||
                (all_golden_count-sys_out_golden_count<0&& _GP_HELPER_->g_sys_gloab.sys_golden_get<0))//只有当系统和本次输赢相同
        {
             float chance=static_cast<float>(abs(_GP_HELPER_->g_sys_gloab.sys_golden_get))/SYS_GOLDEN_MAX_LOSE;
             golden_reset=_GP_HELPER_->RandomPick(chance);
             printf("golden_chance:%f,golden_reset:%d\n",chance,golden_reset);

        }
        if(!golden_reset && i>=3)
        {
            printf("no change\n");
                 break;
        }
        if((all_silver_count-sys_out_silver_count>0&& _GP_HELPER_->g_sys_gloab.sys_silver_get>0)||
                (all_silver_count-sys_out_silver_count<0&& _GP_HELPER_->g_sys_gloab.sys_silver_get<0))//只有当系统和本次输赢相同
        {
             float chance=static_cast<float>(abs(_GP_HELPER_->g_sys_gloab.sys_silver_get))/SYS_SILVER_MAX_LOSE;
             silver_reset=_GP_HELPER_->RandomPick(chance);
             printf("silver_chance:%f,silver_reset:%d\n",chance,silver_reset);
        }
        if(!golden_reset&&!silver_reset)
        {
             printf("no change2\n");
            break;
        }

    }

    _GP_HELPER_->g_sys_gloab.sys_golden_in_count+=all_golden_count;
    _GP_HELPER_->g_sys_gloab.sys_silver_in_count+=all_silver_count;
    _GP_HELPER_->g_sys_gloab.sys_golden_out_count+=sys_out_golden_count;
    _GP_HELPER_->g_sys_gloab.sys_silver_out_count+=sys_out_silver_count;
    _GP_HELPER_->g_sys_gloab.sys_golden_get+=(all_golden_count-sys_out_golden_count-sys_recyle_golden_count);
     m_sys_win[0]=all_golden_count-sys_out_golden_count;
     m_sys_win[1]=all_silver_count-sys_out_silver_count;
    _GP_HELPER_->g_sys_gloab.sys_silver_get+=(all_silver_count-sys_out_silver_count-sys_recyle_silver_count);
    _GP_HELPER_->g_sys_gloab.sys_golden_recyle+=sys_recyle_golden_count;
    _GP_HELPER_->g_sys_gloab.sys_silver_recyle+=sys_recyle_silver_count;

    printf("sys_golden_in_count:%u,sys_silver_in_count:%u,sys_golden_out_count:%u,sys_silver_out_count:%u\n",
           _GP_HELPER_->g_sys_gloab.sys_golden_in_count,
           _GP_HELPER_->g_sys_gloab.sys_silver_in_count,
           _GP_HELPER_->g_sys_gloab.sys_golden_out_count,
           _GP_HELPER_->g_sys_gloab.sys_silver_out_count
           );
    printf("sys_golden_get:%d,sys_silver_get:%d\n", _GP_HELPER_->g_sys_gloab.sys_golden_get, _GP_HELPER_->g_sys_gloab.sys_silver_get);

    return goal_vector;

}


