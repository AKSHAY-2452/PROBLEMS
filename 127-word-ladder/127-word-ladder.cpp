class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        
        while(!q.empty()){
            string currWord = q.front().first;
            int currStep = q.front().second;
            q.pop();
            
            if(currWord == endWord) return currStep;
            
            for(int i = 0;i<currWord.size();i++){
                char original = currWord[i];
                for(char j = 'a';j<='z';j++){
                    currWord[i] = j;
                    
                    //word exists in set
                    if(st.find(currWord) != st.end()){
                        q.push({currWord,currStep+1});
                        st.erase(currWord);
                    }
                }
                currWord[i] = original;
            }
        }
        
        return 0;
    }
};