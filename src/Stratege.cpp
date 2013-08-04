#include "../include/Stratege.h"
#include "algorithm"
#include "stdio.h"


bool Stratege::GetSingleResultBySel(std::vector<int>& goal_vector, const Calculate::CoinsAreaMap_t& bet_map, unsigned int& cur_sys_golden_out, unsigned int& cur_sys_silver_out)
{
    std::sort(goal_vector.begin(),goal_vector.begin()+3);
    int goal=goal_vector.at(0)*100+goal_vector.at(1)*10+goal_vector.at(2);
    std::vector<int> res;
    if(!(Helper::GetInstance()->GetResByGoal(goal,res)))
    {
        return false;
    }
    int pre_area=0;
    for(std::vector<int>::iterator it=res.begin();
            it!=res.end();
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
        printf("area:%d odd:%d ",area,odd);

        Calculate::CoinsAreaMap_t::const_iterator c_it=bet_map.find(area);
        if(c_it==bet_map.end())
        {
            printf("no \n");
            continue;
        }
        int golden_count=c_it->second.golden_count ;
        printf("golden_count:%d ",golden_count);
        cur_sys_golden_out+=(odd*golden_count);
        printf("golden odd*golden_count:%d\n",odd*golden_count);

        int sliver_count=c_it->second.silver_count ;
        printf("sliver_count:%d ",sliver_count);
        cur_sys_silver_out+=(odd*sliver_count);
        printf("sliver odd*sliver_count:%d\n",odd*sliver_count);
    }
    return true;

}




std::vector<int> RandomStratege::GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map,unsigned int all_golden_count,unsigned int all_silver_count)
{
    int b[3]= {0};
    Helper::GetInstance()->Gen(b);

    return std::vector<int>(b,b+3);
}


ReduceSilverStrage::ReduceSilverStrage(int count)
    :m_count(count)
    ,m_sys_win(0)
{

}
std::vector<int> ReduceSilverStrage::GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map,unsigned int all_golden_count,unsigned int all_silver_count)
{

    printf("all_golden_count:%u,all_silver_count:%u\n",all_golden_count,all_silver_count);
    int b[3]= {0};
    std::vector<std::vector<int> > all_res;
    int min_index=0;

    for (int i=0; i<m_count; ++i)
    {
        Helper::GetInstance()->Gen(b);
        std::vector<int> goal_vector(b, b+3);
        printf("%d,%d,%d\n",b[0],b[1],b[2]);
        all_res.push_back(goal_vector);

        unsigned  sys_out_silver_count=0;
        unsigned  sys_out_golden_count=0;

        if(!(GetSingleResultBySel(goal_vector,bet_map,sys_out_golden_count,sys_out_silver_count)))
        {
            continue;
        }
        int in_count=all_silver_count-sys_out_silver_count;
        printf("第%d次,all_silver_count:%u,sys_out_silver_count:%u\n",i,all_silver_count,sys_out_silver_count);
        printf("第%d次,all_golden_count:%u,sys_out_golden_count:%u\n",i,all_golden_count,sys_out_golden_count);
        if(in_count<=0)//如果输钱，直接给出去
        {
            m_sys_win=in_count;
            return all_res.at(i);
        }

        if((i==0)||(m_sys_win>in_count))
        {
            m_sys_win=in_count;
            min_index=i;
        }

    }
    return all_res.at(min_index);

}


BalanceStrage::BalanceStrage()
{

}

std::vector<int> BalanceStrage::GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map, unsigned int all_golden_count, unsigned int all_silver_count)
{
    printf("all_golden_count:%u,all_silver_count:%u\n",all_golden_count,all_silver_count);
    int b[3]= {0};
    std::vector<int> goal_vector;
    int retry_time=5;
    for(int i=0;i<retry_time;++i)
    {
        Helper::GetInstance()->Gen(b);
        goal_vector.assign(b, b+3);
        printf("%d,%d,%d\n",b[0],b[1],b[2]);
        unsigned  sys_out_silver_count=0;
        unsigned  sys_out_golden_count=0;
        GetSingleResultBySel(goal_vector,bet_map,sys_out_golden_count,sys_out_silver_count);
        if(i==4)
        {
            _GP_HELPER_->AddSysGoldenIn(sys_out_golden_count);
            _GP_HELPER_->AddSysSilverIn(sys_out_silver_count);
        }





    }

}


