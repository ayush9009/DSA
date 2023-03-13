unordered_set<int>res,cur1,cur2;
        for(auto i:arr){
            cur2={i};
            for(auto j:cur1)cur2.insert(i|j);
            for(auto t:cur1=cur2)res.insert(t);
        }
        return res.size();
