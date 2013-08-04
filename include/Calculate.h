#ifndef  _CALCULATE_H
#define  _CALCULATE_H
#include <map>
#include <vector>

extern const int areas[];

typedef std::map<int,std::vector<int> > NumResultMap_t;
typedef std::map<int,int> OddsMap_t;
#define   _GP_HELPER_ (Helper::GetInstance())
class Helper
{

public:
    static Helper* GetInstance();
    void  Gen(int *out);
    bool GetResByGoal(int goal, std::vector<int>& res);
    int  GetOddbyArea(int area);
    NumResultMap_t* GetNumResult();
    OddsMap_t*  GetOdds();
    int GetSysGoldenIn()
    {
       return m_sys_golden_in;
    }
    void AddSysGoldenIn(int sys_golden_in)
    {
        m_sys_golden_in+=sys_golden_in;
    }
    void AddSysSilverIn(int sys_silver_in)
    {
        m_sys_silver_in+=sys_silver_in;
    }
    int GetSysSilverIn()
    {
       return m_sys_silver_in;
    }

private:
    Helper();
    ~Helper();
    Helper(const Helper&) {}
    Helper& operator= (const Helper&) { return *this;}

private:
    static Helper* m_instance;
    NumResultMap_t *m_bet_result;
    OddsMap_t    *m_odds_map;
    int m_sys_golden_in;
    int m_sys_silver_in;

};

class Stratege;
class Calculate
{
public:
    typedef struct
    {
        unsigned int golden_count;
        unsigned int silver_count;
    } CoinsCount_t;
    typedef std::map<unsigned int ,CoinsCount_t> CoinsAreaMap_t;
    enum CoinsType
    {
        golden=0,
        silver=1
    };

public:
    Calculate(void);
    ~Calculate(void);

    bool AddBet(unsigned int golden_coins,unsigned int silver_coins,unsigned int area);
    void SetStratege(Stratege* stratege);

    std::vector<int> GetResult();
    int GetSysWin();
    unsigned int GetAllSliverCount()
    {
        return m_all_sliver_count;
    }
    void dump();

private:

    CoinsAreaMap_t m_coins_area_map;
    unsigned int m_all_golden_count;
    unsigned int m_all_sliver_count;
    Stratege *m_stratege;



};





#endif
