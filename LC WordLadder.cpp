class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
         // QUEUE FOR BFS
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        // SET FOR CHECKING IF UPDATED WORD IN WORDLIST
        unordered_set<string> st(wordList.begin(), wordList.end());
        // ERASE SO THAT IF ENCOUNTER AGAIN DO NOT REVISIT
        st.erase(beginWord);
        
        while(!q.empty()){
            
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            int n = word.size();
            // CHECK IF WORD BECAMES EQUAL TO ENDWORD
            if(word == endWord){
                return steps;
            }
            
            for(int i=0; i<n; i++){
                // CHANGING EACH CHAR
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        // IF IN WORDLIST PUSH IN QUEUE AND ERASE FROM WORDLIST
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                // REGNERATE THE ORG WORD
                word[i] = org;
            }
        }
        // AT END RETUEN ZERO IF WORD NOT BECAMES EQUAL TO ENDWORD 
        return 0;
    }
};
