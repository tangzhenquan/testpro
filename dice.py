#coding:utf-8
from __future__ import division
import random
import time
SYS_GOLDEN_MAX_LOSE=100000
SYS_SILVER_MAX_LOSE=100000
SYS_GOLDEN_RECYLE=100
SYS_SILVER_RECYLE=100
PEOPLE=10
TEST_TIMES=5000
ALL_CHANCE=[1,1,1,1,50,18,14,12,8,6,6,6,6,8,12,14,18,50,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,8,8,8,8,8,8,150,24,24,24,24,24,24,1,1,1,1,1,1]
MYCHANCE={401:150,402:150,403:150,404:150,405:150,406:150,301:24,601:8,602:8,603:8,604:8,605:8,606:8,701:5,801:5,901:5,1001:5,1201:5,1301:5,1401:5,1501:5,1601:5,
          1701:5,1801:5,1901:5,2001:5,2101:5,2201:1,2301:1,2401:1,2501:1,2601:1,2701:1}
SOME_DICT={(5,6):18,(4,6):19,(4,5):20,(5,6):21,(3,5):22,(3,4):23,(2,4):24,(2,5):25,(2,6):26,(2,3):27,(1,6):28,(1,5):29,(1,4):30,(1,3):31,(1,2):32,(6,6):33,(5,5):34,(4,4):35,(3,3):36,(2,2):37,(1,1):38}
AND_DICT={(1,1):601,(2,2):602,(3,3):603,(4,4):604,(5,5):605,(6,6):606,(1,2):701,(1,3):801,(1,4):901,(1,5):1001,(1,6):1101,(2,3):1201,
          (2,4):1301,(2,5):1401,(2,6):1501,(3,4):1601,(3,5):1701,(3,6):1801,(4,5):1901,(4,6):2001,(5,6):2101}
#################################change#########################
SYS_GOLDEN_GET=0
SYS_SILVER_GET=0
ALL_USER_DATA_INFO_DICT={}
QUAN_WEI=[]
ALL_GOLDEN=0
ALL_SILVER=0
SYS_GOLDEN_WIN_TIMES=0
SYS_SILVER_WIN_TIMES=0
ALL_TIMES=0
def get_bet_data():
    i=random.randint(3,15)
    ch_list=random.sample(range(0,51),i)
    res= [(ch,random.randint(50,500),random.choice([0,1])) for ch in ch_list]
    res=[(j,random.randint(50,500),random.choice([0,1])) for j in range(1)]
    
    return res

def random_pick(some_list,probabilities):
    x=random.uniform(0,1)
    cumulative_probability=0.0
    for item,item_probability in zip(some_list,probabilities):
        cumulative_probability+=item_probability
        if x < cumulative_probability: break
    return item

def Perm(g_list):
    return [(g_list[0],g_list[1]),(g_list[0],g_list[2]),(g_list[1],g_list[2])]


class CountTest(object):
    def __init__(self):
        self.cur_test_golden_count=0
        self.cur_test_silver_count=0
        self.cur_user_bet_dict={}
        self.cur_golden_all_bet_dict={}
        self.cur_silver_all_bet_dict={}

    def user_bet(self,t_bet,user):
        cur_user_golden_count=0
        cur_user_silver_count=0
        for bet in t_bet:
            i=bet[0]
            g_type=bet[2]
            count=bet[1]
            if g_type==0:
                if self.cur_golden_all_bet_dict.has_key(i):
                    self.cur_golden_all_bet_dict[i]+=count
                else :
                    self.cur_golden_all_bet_dict[i]=count
                cur_user_golden_count+=count
            elif g_type==1:
                if self.cur_silver_all_bet_dict.has_key(i):
                    self.cur_silver_all_bet_dict[i]+=count
                else :
                    self.cur_silver_all_bet_dict[i]=count
                cur_user_silver_count+=count
        self.cur_test_golden_count+=cur_user_golden_count
        self.cur_test_silver_count+=cur_user_silver_count
        global ALL_GOLDEN
        global ALL_SILVER
        ALL_GOLDEN+=cur_user_golden_count
        ALL_SILVER+=cur_user_silver_count
        self.cur_user_bet_dict[user]=t_bet,cur_user_golden_count,cur_user_silver_count
        
    def gen_dice(self):
        res= [random.choice(range(1,7)),random.choice(range(1,7)),random.choice(range(1,7))]
        res.sort()
        return res
    
   
    def get_a_reult(self,dice_list):
         a=sum(dice_list)
         result=[]
         d0=dice_list[0]
         if d0==dice_list[1] and d0==dice_list[2]:
             result.append(39) 
             result.append(46-d0)
         else:
             result.append(3 if a%2==0 else 2)
             result.append(0 if a in range(4,11) else 1)
             perm_list= Perm(dice_list)
             for p in perm_list:
                 i=SOME_DICT.get(p,None)

                 if  i and i not in result:
                      result.append(i)
             result.append(a)
         for j in dice_list:
              result.append(52-j)
         return result

    def get_b_result(self,dice_list):
        #print dice_list
        res=[]
        d0=dice_list[0]
        if d0==dice_list[1] and d0==dice_list[2]:
            res.append(301)
            res.append(400+d0)
            res.append(600+d0)
        else :
            perm_list= Perm(dice_list)
            for p in perm_list:
                 i=AND_DICT.get(p,None)
                 if  i and i not in res:
                      res.append(i)
        for j in dice_list:
              res.append(2101+j*100)
        return res

            
    
    def calculate(self):
        global ALL_TIMES
        ALL_TIMES+=1
        global QUAN_WEI
        a1=CountTest.gen_dice(self)
        result=CountTest.get_a_reult(self,a1)
        out_golden_count=0
        out_silver_count=0
        print result
        
        for r in result:
            chance=ALL_CHANCE[r]
            if self.cur_golden_all_bet_dict.has_key(r):
                bet=self.cur_golden_all_bet_dict[r]
                tmp=(bet)*(chance+1)
                #print "golden item:%d bet:%d,chance:%d,product:%d"%(r,bet,chance,tmp)
                out_golden_count+=tmp          
            if self.cur_silver_all_bet_dict.has_key(r):
                bet=self.cur_silver_all_bet_dict[r]
                tmp=(bet)*(chance+1)
                #print "silver item:%d bet:%d,chance:%d,product:%d"%(r,bet,chance,tmp)
                out_silver_count+=tmp
        print "tou:%s,res:%s,out_golden:%d,out_silver:%d,in_golden:%d,in_silver:%d"%(str(a1),str(result),out_golden_count,out_silver_count,self.cur_test_golden_count,self.cur_test_silver_count)
        if a1[0]==a1[1] and a1[0]==a1[2]:
            QUAN_WEI.append((a1,out_golden_count,out_silver_count,self.cur_test_golden_count,self.cur_test_silver_count))
        #ALL_OUT_DATA[4]+=out_golden_count
        return a1,out_golden_count,out_silver_count

    def draw(self):
        global SYS_GOLDEN_GET
        global SYS_SILVER_GET
        res_list=[]
        for i in range(0,6):
            print "praseing %d times"%(i+1)
            golden_reset=0
            silver_reset=0
            a1,out_golden_count,out_silver_count=CountTest.calculate(self)
            res_list=a1
            break;
            if i==5:
                break
            if (out_golden_count-self.cur_test_golden_count>0 and SYS_GOLDEN_GET<0) or(out_golden_count-self.cur_test_golden_count<0 and SYS_GOLDEN_GET>0):
                #print SYS_GOLDEN_GET
                chance=abs(SYS_GOLDEN_GET)/SYS_GOLDEN_MAX_LOSE
                golden_reset=random_pick([0,1],[1-chance,chance])
                print "golden_chance:%s,golden_reset:%d"%(str(chance),golden_reset)
                if golden_reset: 
                    if i==3:
                        break 
                    else:
                        continue
                else:
                    break
            else:
                break
            if (out_silver_count-self.cur_test_silver_count>0 and SYS_SILVER_GET<0) or (out_silver_count-self.cur_test_silver_count<0 and SYS_SILVER_GET>0) :
                silver_chance=abs(SYS_SILVER_GET)/SYS_SILVER_MAX_LOSE
                silver_reset=random_pick([0,1],[1-silver_chance,silver_chance])
                print "silver_chance:%s,silver_reset:%d"%(str(silver_chance),silver_reset)
            if silver_reset==0 and golden_reset==0:
                res_list=a1
                break
        SYS_GOLDEN_GET=SYS_GOLDEN_GET+self.cur_test_golden_count-out_golden_count-SYS_GOLDEN_RECYLE
        SYS_SILVER_GET=SYS_SILVER_GET+self.cur_test_silver_count-out_silver_count-SYS_SILVER_RECYLE
        if self.cur_test_golden_count-out_golden_count>0:
            global SYS_GOLDEN_WIN_TIMES
            SYS_GOLDEN_WIN_TIMES+=1
        if self.cur_test_silver_count-out_silver_count>0:
            global SYS_SILVER_WIN_TIMES
            SYS_SILVER_WIN_TIMES+=1
        print "final result:%s"%str(res_list)
    def start(self):
        print "user bet..."
        for i in range(PEOPLE):
            CountTest.user_bet(self,get_bet_data(),i)       
        #print self.cur_user_bet_dict 
        print "golden bet:%s"%str(self.cur_golden_all_bet_dict)
        print "silver bet:%s"%str(self.cur_silver_all_bet_dict)
        #print self.cur_test_golden_count
        #print self.cur_test_silver_count
        CountTest.draw(self)
        print SYS_GOLDEN_GET 
        print SYS_SILVER_GET



import BaseHTTPServer
class MyHTTPHandler(BaseHTTPServer.BaseHTTPRequestHandler):
    def do_GET(s):
        s.send_response(200)
        s.send_header("Content-type", "text/html") 
        s.end_headers()
        s.wfile.write("<html><head><title>Title goes here.</title></head>")
        s.wfile.write('<meta http-equiv="refresh" content="10">')
        s.wfile.write("<body><p>sys golden:%d</p>"%SYS_GOLDEN_GET)
        s.wfile.write("<body><p>sys silver:%d</p>"%SYS_SILVER_GET)
        s.wfile.write("<p>You accessed path: %s</p>"%s.path)

if __name__=='__main__':
    test=CountTest()
    gen_list=[]
    print test.get_b_result([3,3,3]) 
    for i in range(1,7):
        for j in range(1,7):
            for k in range(1,7):
                gen=[i,j,k]
                gen.sort()
                if gen not in gen_list:
                    
                    #print "%d%d%d=%s"%(gen[0],gen[1],gen[2],str(test.get_b_result(gen)))
                     print "static const n%d%d%d=%s;"%(gen[0],gen[1],gen[2],str(test.get_b_result(gen)))
                   # m_bet_result[111]=std::vector<int>(n111,sizeof(n111)/sizeof(int));
                    #print "m_bet_result[%d%d%d]=std::vector<int>(n%d%d%d,n%d%d%d+sizeof(n%d%d%d)/sizeof(int)); "%(gen[0],gen[1],gen[2],
                    #                                                                                          gen[0],gen[1],gen[2],
                     #                                                                                              gen[0],gen[1],gen[2],
                    #                                                                                          gen[0],gen[1],gen[2])
                     gen_list.append(gen)
    #for i in range(TEST_TIMES):
    #    print "####################test%d start########################"%(i+1)
    #    test=CountTest()
     #   test.start()
     #   print "####################test%d end##########################"%(i+1)
        #time.sleep(10)
    #print "golden get:%d,win:%d,win times chance:%s,count chance:%s"%(SYS_GOLDEN_GET,SYS_GOLDEN_WIN_TIMES,str(SYS_GOLDEN_WIN_TIMES/TEST_TIMES),str(SYS_GOLDEN_GET/ALL_GOLDEN))
    #print "silver get:%d,win:%d,win times chance:%s,count chance:%s"%(SYS_SILVER_GET,SYS_SILVER_WIN_TIMES,str(SYS_SILVER_WIN_TIMES/TEST_TIMES),str(SYS_SILVER_GET/ALL_SILVER) )
    #print "quan wei:%d"%len(QUAN_WEI)
    #print "all times:%d"%ALL_TIMES
    #print ALL_IN_DATA
    #print ALL_OUT_DATA
