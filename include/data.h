#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <vector>
#include <map>



class Data
{
public:
    Data()
    {
        m_bet_result[111]=std::vector<int>(n111,n111+sizeof(n111)/sizeof(int));
        m_bet_result[112]=std::vector<int>(n112,n112+sizeof(n112)/sizeof(int));
        m_bet_result[113]=std::vector<int>(n113,n113+sizeof(n113)/sizeof(int));
        m_bet_result[114]=std::vector<int>(n114,n114+sizeof(n114)/sizeof(int));
        m_bet_result[115]=std::vector<int>(n115,n115+sizeof(n115)/sizeof(int));
        m_bet_result[116]=std::vector<int>(n116,n116+sizeof(n116)/sizeof(int));
        m_bet_result[122]=std::vector<int>(n122,n122+sizeof(n122)/sizeof(int));
        m_bet_result[123]=std::vector<int>(n123,n123+sizeof(n123)/sizeof(int));
        m_bet_result[124]=std::vector<int>(n124,n124+sizeof(n124)/sizeof(int));
        m_bet_result[125]=std::vector<int>(n125,n125+sizeof(n125)/sizeof(int));
        m_bet_result[126]=std::vector<int>(n126,n126+sizeof(n126)/sizeof(int));
        m_bet_result[133]=std::vector<int>(n133,n133+sizeof(n133)/sizeof(int));
        m_bet_result[134]=std::vector<int>(n134,n134+sizeof(n134)/sizeof(int));
        m_bet_result[135]=std::vector<int>(n135,n135+sizeof(n135)/sizeof(int));
        m_bet_result[136]=std::vector<int>(n136,n136+sizeof(n136)/sizeof(int));
        m_bet_result[144]=std::vector<int>(n144,n144+sizeof(n144)/sizeof(int));
        m_bet_result[145]=std::vector<int>(n145,n145+sizeof(n145)/sizeof(int));
        m_bet_result[146]=std::vector<int>(n146,n146+sizeof(n146)/sizeof(int));
        m_bet_result[155]=std::vector<int>(n155,n155+sizeof(n155)/sizeof(int));
        m_bet_result[156]=std::vector<int>(n156,n156+sizeof(n156)/sizeof(int));
        m_bet_result[166]=std::vector<int>(n166,n166+sizeof(n166)/sizeof(int));
        m_bet_result[222]=std::vector<int>(n222,n222+sizeof(n222)/sizeof(int));
        m_bet_result[223]=std::vector<int>(n223,n223+sizeof(n223)/sizeof(int));
        m_bet_result[224]=std::vector<int>(n224,n224+sizeof(n224)/sizeof(int));
        m_bet_result[225]=std::vector<int>(n225,n225+sizeof(n225)/sizeof(int));
        m_bet_result[226]=std::vector<int>(n226,n226+sizeof(n226)/sizeof(int));
        m_bet_result[233]=std::vector<int>(n233,n233+sizeof(n233)/sizeof(int));
        m_bet_result[234]=std::vector<int>(n234,n234+sizeof(n234)/sizeof(int));
        m_bet_result[235]=std::vector<int>(n235,n235+sizeof(n235)/sizeof(int));
        m_bet_result[236]=std::vector<int>(n236,n236+sizeof(n236)/sizeof(int));
        m_bet_result[244]=std::vector<int>(n244,n244+sizeof(n244)/sizeof(int));
        m_bet_result[245]=std::vector<int>(n245,n245+sizeof(n245)/sizeof(int));
        m_bet_result[246]=std::vector<int>(n246,n246+sizeof(n246)/sizeof(int));
        m_bet_result[255]=std::vector<int>(n255,n255+sizeof(n255)/sizeof(int));
        m_bet_result[256]=std::vector<int>(n256,n256+sizeof(n256)/sizeof(int));
        m_bet_result[266]=std::vector<int>(n266,n266+sizeof(n266)/sizeof(int));
        m_bet_result[333]=std::vector<int>(n333,n333+sizeof(n333)/sizeof(int));
        m_bet_result[334]=std::vector<int>(n334,n334+sizeof(n334)/sizeof(int));
        m_bet_result[335]=std::vector<int>(n335,n335+sizeof(n335)/sizeof(int));
        m_bet_result[336]=std::vector<int>(n336,n336+sizeof(n336)/sizeof(int));
        m_bet_result[344]=std::vector<int>(n344,n344+sizeof(n344)/sizeof(int));
        m_bet_result[345]=std::vector<int>(n345,n345+sizeof(n345)/sizeof(int));
        m_bet_result[346]=std::vector<int>(n346,n346+sizeof(n346)/sizeof(int));
        m_bet_result[355]=std::vector<int>(n355,n355+sizeof(n355)/sizeof(int));
        m_bet_result[356]=std::vector<int>(n356,n356+sizeof(n356)/sizeof(int));
        m_bet_result[366]=std::vector<int>(n366,n366+sizeof(n366)/sizeof(int));
        m_bet_result[444]=std::vector<int>(n444,n444+sizeof(n444)/sizeof(int));
        m_bet_result[445]=std::vector<int>(n445,n445+sizeof(n445)/sizeof(int));
        m_bet_result[446]=std::vector<int>(n446,n446+sizeof(n446)/sizeof(int));
        m_bet_result[455]=std::vector<int>(n455,n455+sizeof(n455)/sizeof(int));
        m_bet_result[456]=std::vector<int>(n456,n456+sizeof(n456)/sizeof(int));
        m_bet_result[466]=std::vector<int>(n466,n466+sizeof(n466)/sizeof(int));
        m_bet_result[555]=std::vector<int>(n555,n555+sizeof(n555)/sizeof(int));
        m_bet_result[556]=std::vector<int>(n556,n556+sizeof(n556)/sizeof(int));
        m_bet_result[566]=std::vector<int>(n566,n566+sizeof(n566)/sizeof(int));
        m_bet_result[666]=std::vector<int>(n666,n666+sizeof(n666)/sizeof(int));

    }
    std::map<int,std::vector<int> > GetMap()
    {
        return m_bet_result;
    }
private:
    std::map<int,std::vector<int> > m_bet_result;

};

#endif // DATA_H_INCLUDED
