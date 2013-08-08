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
    virtual bool GetSingleResultBySel(const std::vector<int>& goal_vector,const Calculate::CoinsAreaMap_t& bet_map,unsigned int& cur_sys_golden_out,unsigned int& cur_sys_silver_out);
    virtual int GetSilverSysWin()=0;
};



class RandomStratege
    :public Stratege
{
public:

    RandomStratege():m_sys_win(0) {}
    virtual std::vector<int> GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map,unsigned int all_golden_count,unsigned int all_silver_count);

    virtual ~RandomStratege() {}
    virtual int GetSilverSysWin()
    {
        return m_sys_win;
    }
private:
    int m_sys_win;

};

class ReduceSilverStrage
    :public Stratege
{
public:
    explicit ReduceSilverStrage(int count=2);
    virtual ~ReduceSilverStrage() {}
    virtual std::vector<int> GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map,unsigned int all_golden_count,unsigned int all_silver_count);
    virtual int GetSilverSysWin()
    {
        return m_sys_win ;
    }
private:
    int m_count;
    int m_sys_win;
};

class  BalanceStrage
    :public Stratege
{
public:
    BalanceStrage();
    virtual ~BalanceStrage(){}
    virtual std::vector<int> GetDiceResult(const Calculate::CoinsAreaMap_t& bet_map,unsigned int all_golden_count,unsigned int all_silver_count);
    virtual int GetSilverSysWin()
    {
        return m_sys_win ;
    }
private:
    int m_sys_win;

};

#endif // STRATEGE_H
