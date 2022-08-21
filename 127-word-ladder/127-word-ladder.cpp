class Solution {
    int diff(string a,string b){
        int n = a.length();
        int count = 0;
        for(int i = 0;i<n;i++){
            if(a[i] != b[i]) count++;
        }
        return count;
    }
    int bfs(string beginWord, string endWord, vector<string>& wordList){
        map<string,vector<string>> mp;
        //"hit" => "hot"
        //"hot" => "lot","dot"
        
        //forming adjancency list
        for(int i = 0;i<wordList.size();i++){//n
            for(int j = i+1;j<wordList.size();j++){//n
                if(diff(wordList[i],wordList[j]) == 1){//m
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        //O(n*n*m) time complexity(size of word m, size of word list n)
        //for beginword
        for(int i = 0;i<wordList.size();i++){
            if(diff(beginWord,wordList[i]) == 1){
                mp[beginWord].push_back(wordList[i]);
                mp[wordList[i]].push_back(beginWord);
            }
        }
        
        
        //shortest path in unweighted undirected graph
        set<string> visited;
        queue<pair<string,int>> q; // string and it's level
        q.push({beginWord,1});
        visited.insert(beginWord);
        while(!q.empty()){
            string temp = q.front().first;
            int level = q.front().second;
            q.pop();
            
            for(auto it : mp[temp]){
                
                //check if not visited
                if(visited.find(it) == visited.end()){
                    q.push({it,level+1});
                    visited.insert(it);
                    
                    if(it == endWord) return level+1;
                }
                
            }
        }
        
        return 0;
        
    }
    
    int solve(string beginWord, string endWord, vector<string>& wordList){
        map<string,vector<string>> mp;
        
        int msize = beginWord.size();
        //forming adjacency list
        for(int i = 0;i<wordList.size();i++){
            for(int j = 0;j<msize;j++){
                string x = wordList[i].substr(0,j) + "*" + wordList[i].substr(j+1,msize-j-1);
                mp[x].push_back(wordList[i]);
            }
        }
        //adding beginword
        for(int j = 0;j<msize;j++){
            string x = beginWord.substr(0,j) + "*" + beginWord.substr(j+1,msize-j-1);
            mp[x].push_back(beginWord);
        }
        
        set<string> vis;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        vis.insert(beginWord);
        
        while(!q.empty()){
            string temp = q.front().first;
            int level = q.front().second;
            q.pop();
            
            for(int i = 0;i<msize;i++){
                string x = temp.substr(0,i)+"*"+temp.substr(i+1,msize-1-i);
             for(auto it : mp[x]){
                 
                 //check if not visited
                 if(vis.find(it) == vis.end()){
                     vis.insert(it);
                     q.push({it,level+1});
                     
                     if(it == endWord) return level+1;
                 }
             }   
            }
        }
        return 0;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //return bfs(beginWord,endWord,wordList);    
        //normal bfs takes O(n*n*m) which is 5k*5k*10
        //optimised to O(m*m*n) which is 10*10*5k
        
        return solve(beginWord,endWord,wordList);    

    }
};