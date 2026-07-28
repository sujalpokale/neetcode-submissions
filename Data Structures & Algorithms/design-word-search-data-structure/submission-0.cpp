class WordDictionary {
    struct TrieNode{
        TrieNode* chi[26];
        bool isEnd;

        TrieNode(){
            isEnd = false;

            for(int i=0;i<26;i++){
                chi[i] = NULL;
            }
        }
    };
    TrieNode* root;

    bool dfs(string& word,int pos,TrieNode* node){
        if(node == NULL){
            return false;
        }
        if(pos == word.size()){
            return node->isEnd;
        }

        char ch = word[pos];

        if(ch != '.'){
            int idx = ch - 'a';
            return dfs(word,pos + 1,node->chi[idx]);
        }

        for(int i =0 ;i<26;i++){
            if(node->chi[i] && dfs(word,pos + 1,node->chi[i])){
                return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node =root;

        for(char ch: word){
            int idx = ch - 'a';

            if(node->chi[idx] == NULL){
                node->chi[idx] = new TrieNode();
            }
            node = node->chi[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};
