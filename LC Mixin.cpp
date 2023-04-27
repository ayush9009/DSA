class OrderedStream {
public:
    int ptr = 1;
    vector<string> s;
    OrderedStream(int n) {
        s.resize(n+1);
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ret;
        s[idKey] = value;
        while(ptr<s.size() && !s[ptr].empty())
            ret.push_back(s[ptr++]);
        return ret;
    }
};
