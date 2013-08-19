#include "../include/Calculate.h"
#include  "../include/Stratege.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include<cassert>



static const int n111[]= {301, 601, 401, 2201, 2201, 2201};
static const int n112[]= {601, 701, 2201, 2201, 2301};
static const int n113[]= {601, 801, 2201, 2201, 2401};
static const int n114[]= {601, 901, 2201, 2201, 2501};
static const int n115[]= {601, 1001, 2201, 2201, 2601};
static const int n116[]= {601, 1101, 2201, 2201, 2701};
static const int n122[]= {701, 602, 2201, 2301, 2301};
static const int n123[]= {701, 801, 1201, 2201, 2301, 2401};
static const int n124[]= {701, 901, 1301, 2201, 2301, 2501};
static const int n125[]= {701, 1001, 1401, 2201, 2301, 2601};
static const int n126[]= {701, 1101, 1501, 2201, 2301, 2701};
static const int n133[]= {801, 603, 2201, 2401, 2401};
static const int n134[]= {801, 901, 1601, 2201, 2401, 2501};
static const int n135[]= {801, 1001, 1701, 2201, 2401, 2601};
static const int n136[]= {801, 1101, 1801, 2201, 2401, 2701};
static const int n144[]= {901, 604, 2201, 2501, 2501};
static const int n145[]= {901, 1001, 1901, 2201, 2501, 2601};
static const int n146[]= {901, 1101, 2001, 2201, 2501, 2701};
static const int n155[]= {1001, 605, 2201, 2601, 2601};
static const int n156[]= {1001, 1101, 2101, 2201, 2601, 2701};
static const int n166[]= {1101, 606, 2201, 2701, 2701};
static const int n222[]= {301, 602,402, 2301, 2301, 2301};
static const int n223[]= {602, 1201, 2301, 2301, 2401};
static const int n224[]= {602, 1301, 2301, 2301, 2501};
static const int n225[]= {602, 1401, 2301, 2301, 2601};
static const int n226[]= {602, 1501, 2301, 2301, 2701};
static const int n233[]= {1201, 603, 2301, 2401, 2401};
static const int n234[]= {1201, 1301, 1601, 2301, 2401, 2501};
static const int n235[]= {1201, 1401, 1701, 2301, 2401, 2601};
static const int n236[]= {1201, 1501, 1801, 2301, 2401, 2701};
static const int n244[]= {1301, 604, 2301, 2501, 2501};
static const int n245[]= {1301, 1401, 1901, 2301, 2501, 2601};
static const int n246[]= {1301, 1501, 2001, 2301, 2501, 2701};
static const int n255[]= {1401, 605, 2301, 2601, 2601};
static const int n256[]= {1401, 1501, 2101, 2301, 2601, 2701};
static const int n266[]= {1501, 606, 2301, 2701, 2701};
static const int n333[]= {301, 603,403, 2401, 2401, 2401};
static const int n334[]= {603, 1601, 2401, 2401, 2501};
static const int n335[]= {603, 1701, 2401, 2401, 2601};
static const int n336[]= {603, 1801, 2401, 2401, 2701};
static const int n344[]= {1601, 604, 2401, 2501, 2501};
static const int n345[]= {1601, 1701, 1901, 2401, 2501, 2601};
static const int n346[]= {1601, 1801, 2001, 2401, 2501, 2701};
static const int n355[]= {1701, 605, 2401, 2601, 2601};
static const int n356[]= {1701, 1801, 2101, 2401, 2601, 2701};
static const int n366[]= {1801, 606, 2401, 2701, 2701};
static const int n444[]= {301, 604, 404, 2501, 2501, 2501};
static const int n445[]= {604, 1901, 2501, 2501, 2601};
static const int n446[]= {604, 2001, 2501, 2501, 2701};
static const int n455[]= {1901, 605, 2501, 2601, 2601};
static const int n456[]= {1901, 2001, 2101, 2501, 2601, 2701};
static const int n466[]= {2001, 606, 2501, 2701, 2701};
static const int n555[]= {301, 605,405, 2601, 2601, 2601};
static const int n556[]= {605, 2101, 2601, 2601, 2701};
static const int n566[]= {2101, 606, 2601, 2701, 2701};
static const int n666[]= {301, 606,406, 2701, 2701, 2701};

extern const int areas[]= {401,402,403,404,405,406,301,601,602,603,604,605,606
    ,701,801,901,1001,1101,1201,1301,1401,1501,1601,1701,
    1801,1901,2001,2101,2201,2301,2401,2501,2601,2701
};
static const int odds[]= {180,30,10,5,1};




Helper* Helper::m_instance=NULL;

Helper* Helper::GetInstance()
{
    if(NULL==m_instance)
    {
        m_instance=new Helper;
    }
    return m_instance;
}

Helper::Helper()
    :m_bet_result(new NumResultMap_t)
    ,m_odds_map(new OddsMap_t)

{

    srand(time(NULL));
    m_bet_result->insert(std::make_pair(111,std::vector<int>(n111,n111+sizeof(n111)/sizeof(int))));
    m_bet_result->insert(std::make_pair(112,std::vector<int>(n112,n112+sizeof(n112)/sizeof(int))));
    m_bet_result->insert(std::make_pair(113,std::vector<int>(n113,n113+sizeof(n113)/sizeof(int))));
    m_bet_result->insert(std::make_pair(114,std::vector<int>(n114,n114+sizeof(n114)/sizeof(int))));
    m_bet_result->insert(std::make_pair(115,std::vector<int>(n115,n115+sizeof(n115)/sizeof(int))));
    m_bet_result->insert(std::make_pair(116,std::vector<int>(n116,n116+sizeof(n116)/sizeof(int))));
    m_bet_result->insert(std::make_pair(122,std::vector<int>(n122,n122+sizeof(n122)/sizeof(int))));
    m_bet_result->insert(std::make_pair(123,std::vector<int>(n123,n123+sizeof(n123)/sizeof(int))));
    m_bet_result->insert(std::make_pair(124,std::vector<int>(n124,n124+sizeof(n124)/sizeof(int))));
    m_bet_result->insert(std::make_pair(125,std::vector<int>(n125,n125+sizeof(n125)/sizeof(int))));
    m_bet_result->insert(std::make_pair(126,std::vector<int>(n126,n126+sizeof(n126)/sizeof(int))));
    m_bet_result->insert(std::make_pair(133,std::vector<int>(n133,n133+sizeof(n133)/sizeof(int))));
    m_bet_result->insert(std::make_pair(134,std::vector<int>(n134,n134+sizeof(n134)/sizeof(int))));
    m_bet_result->insert(std::make_pair(135,std::vector<int>(n135,n135+sizeof(n135)/sizeof(int))));
    m_bet_result->insert(std::make_pair(136,std::vector<int>(n136,n136+sizeof(n136)/sizeof(int))));
    m_bet_result->insert(std::make_pair(144,std::vector<int>(n144,n144+sizeof(n144)/sizeof(int))));
    m_bet_result->insert(std::make_pair(145,std::vector<int>(n145,n145+sizeof(n145)/sizeof(int))));
    m_bet_result->insert(std::make_pair(146,std::vector<int>(n146,n146+sizeof(n146)/sizeof(int))));
    m_bet_result->insert(std::make_pair(155,std::vector<int>(n155,n155+sizeof(n155)/sizeof(int))));
    m_bet_result->insert(std::make_pair(156,std::vector<int>(n156,n156+sizeof(n156)/sizeof(int))));
    m_bet_result->insert(std::make_pair(166,std::vector<int>(n166,n166+sizeof(n166)/sizeof(int))));
    m_bet_result->insert(std::make_pair(222,std::vector<int>(n222,n222+sizeof(n222)/sizeof(int))));
    m_bet_result->insert(std::make_pair(223,std::vector<int>(n223,n223+sizeof(n223)/sizeof(int))));
    m_bet_result->insert(std::make_pair(224,std::vector<int>(n224,n224+sizeof(n224)/sizeof(int))));
    m_bet_result->insert(std::make_pair(225,std::vector<int>(n225,n225+sizeof(n225)/sizeof(int))));
    m_bet_result->insert(std::make_pair(226,std::vector<int>(n226,n226+sizeof(n226)/sizeof(int))));
    m_bet_result->insert(std::make_pair(233,std::vector<int>(n233,n233+sizeof(n233)/sizeof(int))));
    m_bet_result->insert(std::make_pair(234,std::vector<int>(n234,n234+sizeof(n234)/sizeof(int))));
    m_bet_result->insert(std::make_pair(235,std::vector<int>(n235,n235+sizeof(n235)/sizeof(int))));
    m_bet_result->insert(std::make_pair(236,std::vector<int>(n236,n236+sizeof(n236)/sizeof(int))));
    m_bet_result->insert(std::make_pair(244,std::vector<int>(n244,n244+sizeof(n244)/sizeof(int))));
    m_bet_result->insert(std::make_pair(245,std::vector<int>(n245,n245+sizeof(n245)/sizeof(int))));
    m_bet_result->insert(std::make_pair(246,std::vector<int>(n246,n246+sizeof(n246)/sizeof(int))));
    m_bet_result->insert(std::make_pair(255,std::vector<int>(n255,n255+sizeof(n255)/sizeof(int))));
    m_bet_result->insert(std::make_pair(256,std::vector<int>(n256,n256+sizeof(n256)/sizeof(int))));
    m_bet_result->insert(std::make_pair(266,std::vector<int>(n266,n266+sizeof(n266)/sizeof(int))));
    m_bet_result->insert(std::make_pair(333,std::vector<int>(n333,n333+sizeof(n333)/sizeof(int))));
    m_bet_result->insert(std::make_pair(334,std::vector<int>(n334,n334+sizeof(n334)/sizeof(int))));
    m_bet_result->insert(std::make_pair(335,std::vector<int>(n335,n335+sizeof(n335)/sizeof(int))));
    m_bet_result->insert(std::make_pair(336,std::vector<int>(n336,n336+sizeof(n336)/sizeof(int))));
    m_bet_result->insert(std::make_pair(344,std::vector<int>(n344,n344+sizeof(n344)/sizeof(int))));
    m_bet_result->insert(std::make_pair(345,std::vector<int>(n345,n345+sizeof(n345)/sizeof(int))));
    m_bet_result->insert(std::make_pair(346,std::vector<int>(n346,n346+sizeof(n346)/sizeof(int))));
    m_bet_result->insert(std::make_pair(355,std::vector<int>(n355,n355+sizeof(n355)/sizeof(int))));
    m_bet_result->insert(std::make_pair(356,std::vector<int>(n356,n356+sizeof(n356)/sizeof(int))));
    m_bet_result->insert(std::make_pair(366,std::vector<int>(n366,n366+sizeof(n366)/sizeof(int))));
    m_bet_result->insert(std::make_pair(444,std::vector<int>(n444,n444+sizeof(n444)/sizeof(int))));
    m_bet_result->insert(std::make_pair(445,std::vector<int>(n445,n445+sizeof(n445)/sizeof(int))));
    m_bet_result->insert(std::make_pair(446,std::vector<int>(n446,n446+sizeof(n446)/sizeof(int))));
    m_bet_result->insert(std::make_pair(455,std::vector<int>(n455,n455+sizeof(n455)/sizeof(int))));
    m_bet_result->insert(std::make_pair(456,std::vector<int>(n456,n456+sizeof(n456)/sizeof(int))));
    m_bet_result->insert(std::make_pair(466,std::vector<int>(n466,n466+sizeof(n466)/sizeof(int))));
    m_bet_result->insert(std::make_pair(555,std::vector<int>(n555,n555+sizeof(n555)/sizeof(int))));
    m_bet_result->insert(std::make_pair(556,std::vector<int>(n556,n556+sizeof(n556)/sizeof(int))));
    m_bet_result->insert(std::make_pair(566,std::vector<int>(n566,n566+sizeof(n566)/sizeof(int))));
    m_bet_result->insert(std::make_pair(666,std::vector<int>(n666,n666+sizeof(n666)/sizeof(int))));

    m_odds_map->insert(std::make_pair(areas[0],odds[0]));
    m_odds_map->insert(std::make_pair(areas[1],odds[0]));
    m_odds_map->insert(std::make_pair(areas[2],odds[0]));
    m_odds_map->insert(std::make_pair(areas[3],odds[0]));
    m_odds_map->insert(std::make_pair(areas[4],odds[0]));
    m_odds_map->insert(std::make_pair(areas[5],odds[0]));
    m_odds_map->insert(std::make_pair(areas[6],odds[1]));
    m_odds_map->insert(std::make_pair(areas[7],odds[2]));
    m_odds_map->insert(std::make_pair(areas[8],odds[2]));
    m_odds_map->insert(std::make_pair(areas[9],odds[2]));
    m_odds_map->insert(std::make_pair(areas[10],odds[2]));
    m_odds_map->insert(std::make_pair(areas[11],odds[2]));
    m_odds_map->insert(std::make_pair(areas[12],odds[2]));
    m_odds_map->insert(std::make_pair(areas[13],odds[3]));
    m_odds_map->insert(std::make_pair(areas[14],odds[3]));
    m_odds_map->insert(std::make_pair(areas[15],odds[3]));
    m_odds_map->insert(std::make_pair(areas[16],odds[3]));
    m_odds_map->insert(std::make_pair(areas[17],odds[3]));
    m_odds_map->insert(std::make_pair(areas[18],odds[3]));
    m_odds_map->insert(std::make_pair(areas[19],odds[3]));
    m_odds_map->insert(std::make_pair(areas[20],odds[3]));
    m_odds_map->insert(std::make_pair(areas[21],odds[3]));
    m_odds_map->insert(std::make_pair(areas[22],odds[3]));
    m_odds_map->insert(std::make_pair(areas[23],odds[3]));
    m_odds_map->insert(std::make_pair(areas[24],odds[3]));
    m_odds_map->insert(std::make_pair(areas[25],odds[3]));
    m_odds_map->insert(std::make_pair(areas[26],odds[3]));
    m_odds_map->insert(std::make_pair(areas[27],odds[3]));
    m_odds_map->insert(std::make_pair(areas[28],odds[4]));
    m_odds_map->insert(std::make_pair(areas[29],odds[4]));
    m_odds_map->insert(std::make_pair(areas[30],odds[4]));
    m_odds_map->insert(std::make_pair(areas[31],odds[4]));
    m_odds_map->insert(std::make_pair(areas[32],odds[4]));
    m_odds_map->insert(std::make_pair(areas[33],odds[4]));



}

Helper::~Helper()
{

}

void Helper::Gen(int* out)
{
    out[0]=rand()%6+1;
    out[1]=rand()%6+1;
    out[2]=rand()%6+1;
}

NumResultMap_t * Helper::GetNumResult()
{
    return m_bet_result;
}

OddsMap_t* Helper::GetOdds()
{
    return m_odds_map;
}

bool Helper::GetResByGoal(int goal, std::vector<int>& res)
{
    NumResultMap_t::iterator it= m_bet_result->find(goal);
    if(it!=m_bet_result->end())
    {
        res=it->second;
        return true;
    }
    return false;

}
int Helper::GetOddbyArea(int area)
{
    OddsMap_t::iterator it=m_odds_map->find(area);
    if(it!=m_odds_map->end())
    {
        return it->second;
    }
    return 0;

}

bool Helper::RandomPick(float chance )
{
     float c=DoubleRand(0,1);
     return c<chance;
}

double Helper::DoubleRand(double a, double b)
{
    double r;
    unsigned int as=rand();
    r=(double)as/RAND_MAX;
    //printf("as;%u,r:%f\n",as,r);
    return a+r*(b-a);
}




Calculate::Calculate()
    :m_all_golden_count(0)
    ,m_all_sliver_count(0)
    ,m_stratege(NULL)
{

    //ctor
}

Calculate::~Calculate()
{
    //dtor
    if(m_stratege!=NULL)
    {
        delete m_stratege;
    }
}


bool Calculate::AddBet(unsigned int golden_coins, unsigned int silver_coins, unsigned int area)
{
    CoinsAreaMap_t::iterator it=m_coins_area_map.find(area);
    if(it!=m_coins_area_map.end())
    {
        it->second.golden_count+=golden_coins;
        it->second.silver_count+=silver_coins;

    }
    else
    {
        CoinsCount_t count;
        count.golden_count=golden_coins;
        count.silver_count=silver_coins;
        m_coins_area_map.insert(CoinsAreaMap_t::value_type(area,count));
    }
    m_all_golden_count+=golden_coins;
    m_all_sliver_count+=silver_coins;
    return true;
}

std::vector<int> Calculate::GetResult()
{
    if(m_stratege==NULL)
    {
        m_stratege=new RandomStratege;
    }
    return m_stratege->GetDiceResult(m_coins_area_map,m_all_golden_count,m_all_sliver_count);
}
std::vector<int>  Calculate::GetSysWin()
{
    return m_stratege->GetSysWin();
}

void Calculate::SetStratege(Stratege* stratege)
{
    assert(stratege!=NULL);
    if(m_stratege)
    {
        delete m_stratege;
    }
    m_stratege=stratege;

}
void Calculate::Dump()
{
    for(CoinsAreaMap_t::iterator it=m_coins_area_map.begin();
            it!=m_coins_area_map.end(); ++it)
    {
        printf("%u,%u,%u\n",it->first,it->second.golden_count,it->second.silver_count);
    }
}
void Calculate::Clear()
{
  m_all_golden_count =0;
  m_all_sliver_count=0;
  m_coins_area_map.clear();


}
