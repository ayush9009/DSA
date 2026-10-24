class Solution:
   def countDaysTogether(self, ary: str, le: str, ans: str, lea: str) -> int:
        mi=0
        if int(ary[:2])*100+int(ary[3:])>=int(ans[:2])*100+int(ans[3:]):
            mi=int(ary[:2])*100+int(ary[3:])
        else:
            mi=int(ans[:2])*100+int(ans[3:])
        result=0
        if int(le[:2])*100+int(le[3:])>=int(lea[:2])*100+int(lea[3:]):
            result=int(lea[:2])*100+int(lea[3:])
        else:
           result=int(le[:2])*100+int(le[3:])
        
        arry_1={1,3,5,7,8,10,12}
        brry_1={4,6,9,11}
        c={2}
        ans=0
        while mi<=result:
            if len(str(mi))==3:
                if int(str(mi)[0]) in arry_1:
                    if int(str(mi)[1:])<=31:
                        mi+=1
                        ans+=1
                    else:
                        mi=((int(str(mi)[0])+1)*100)+1
                elif int(str(mi)[0]) in brry_1:
                    if int(str(mi)[1:])<=30:
                        mi+=1
                        ans+=1
                    else:
                        mi=(((int(str(mi)[0]))+1)*100)+1
                else:
                    if int(str(mi)[1:])<=28:
                        mi+=1
                        ans+=1
                    else:
                        mi=(((int(str(mi)[0]))+1)*100)+1
            elif len(str(mi))==4:
                if int(str(mi)[0:2]) in arry_1:
                    if int(str(mi)[2:])<=31:
                        mi+=1
                        ans+=1
                    else:
                        mi=((int(str(mi)[0:2])+1)*100)+1
                elif int(str(mi)[0:2]) in brry_1:
                    if int(str(mi)[2:])<=30:
                        mi+=1
                        ans+=1
                    else:
                        mi=(((int(str(mi)[0:2]))+1)*100)+1
        return ans
        