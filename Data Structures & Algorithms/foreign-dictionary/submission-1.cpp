class Solution {
public:

    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>> graph;
        unordered_map<char,int> indegree;

        for(auto &word : words){
            for(char ch: word){
                indegree[ch] = 0;
            }
        } 

        for(int i=0; i < words.size() - 1;i++){
            string a = words[i];
            string b = words[i + 1];

            if(a.size() > b.size() && a.substr(0,b.size()) == b)
                return "";
            
            int len = min(a.size(),b.size());

            for(int j=0;j<len;j++){
                if(a[j] != b[j]){
                    graph[a[j]].push_back(b[j]);
                    indegree[b[j]]++;

                    break;
                }
            }
        }

        queue<char> q;

        for(auto &p : indegree){
            if(p.second == 0){
                q.push(p.first);
            }
        }

        string ans;
        while(!q.empty()){
            char node = q.front();
            q.pop();

            ans += node;

            for(char nei : graph[node]){
                indegree[nei]--;

                if(indegree[nei] == 0)
                    q.push(nei);
            }
        }

        if(ans.size() != indegree.size())
            return "";
        
        return ans;
    }
};
