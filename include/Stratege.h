#ifndef STRATEGE_H
#define STRATEGE_H
#include "Calculate.h"
#include <vector>

class Stratege
{
public:
    Stratege() {}
    virtual ~Stratege() {}
    virtual std::vector<int> GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map,unsigned int all_golden_count,unsigned int all_silver_count)=0;
    virtual std::vector<int> GetSysWin()=0;
    /** \brief
    *根据押注情况和开骰结果计算系统需要返还金币和银币
    * \param
    * \param
    * \return
    *
    */
    static bool GetSingleResultBySel(const std::vector<int>& goal_vector,const Calculate::CoinsAreaMap_t& bet_map,unsigned int& cur_sys_golden_out,unsigned int& cur_sys_silver_out);
    /** \brief
    *根据押注情况和开骰区域计算系统需要返还金币和银币
    * \param
    * \param
    * \return
    *
    */
    static bool GetSingleResultByArea(const std::vector<int>& area_vector,const Calculate::CoinsAreaMap_t& bet_map,unsigned int& cur_sys_golden_out,unsigned int& cur_sys_silver_out);


    static bool GetNewSingleResultBySel(const std::vector<int>& goal_vector,const Calculate::CoinsAreaMap_t& bet_map,unsigned int& cur_sys_golden_out,unsigned int& cur_sys_silver_out,int&max_odd);

    static bool GetNewSingleResultByArea(const std::vector<int>& area_vector,const Calculate::CoinsAreaMap_t& bet_map,unsigned int& cur_sys_golden_out,unsigned int& cur_sys_silver_out,int&max_odd);

};



class RandomStratege
    :public Stratege
{
public:

    RandomStratege()
    {
        m_sys_win.assign(3,0);
    }
    virtual std::vector<int> GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map,unsigned int all_golden_count,unsigned int all_silver_count);

    virtual ~RandomStratege() {}
    virtual  std::vector<int> GetSysWin()
    {
        return  m_sys_win;
    }
private:
    std::vector<int> m_sys_win;

};


class  BalanceStrage
    :public Stratege
{
public:
    BalanceStrage();
    virtual ~BalanceStrage() {}
    virtual std::vector<int> GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map,unsigned int all_golden_count,unsigned int all_silver_count);
    virtual std::vector<int> GetSysWin()
    {
        return m_sys_win ;
    }
private:
    std::vector<int> m_sys_win;;

};


class NewStrage:
    public Stratege
{
public:
    NewStrage();
    virtual ~NewStrage() {}
    virtual std::vector<int> GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map,unsigned int all_golden_count,unsigned int all_silver_count);
    virtual std::vector<int> GetSysWin()
    {
        return m_sys_win ;
    }
private:
    std::vector<int> m_sys_win;;

};

#endif // STRATEGE_H
