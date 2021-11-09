class Solution {
public:
    
    void show_binary(int num){
        while(num){
            cout << num%2;
            num/=2;
        }
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
           
        unordered_map<int,int> word_map;
        
        for(auto word:words){//對每個word先做字母出現的統計
            
            int occurance = 0;
            for(auto c:word)
                occurance = occurance | ( 1 << ( c-'a') );
            
            word_map[occurance]++;
            //show_binary(occurance) ;
            //cout  << endl;
        }
        vector<int> ans;
        cout << endl;
        for(auto puzzle:puzzles){//對每個puzzle做計算           
            int b_occurance = 0;//當前puzzle的occurance(二進制)
            for(auto c:puzzle)
                b_occurance |= (1<<(c-'a'));
            
            //show_binary(b_occurance);
            //cout << " ";
            char first_c = puzzle[0];
            int b_first_c = (1<<(first_c -'a'));//第一個字母的occurance(二進制)
            int count = 0;
            int sub = b_occurance;
            while(true){
                
                if( (sub & b_first_c) == b_first_c && word_map.count(sub)){
                    count += word_map[sub];  
                }
                if(sub == 0)
                    break;
                sub = (sub-1) & b_occurance;//滑動sub ex: 100 -> 011 -> 010 -> 001 
            }
            

            ans.push_back(count);
            
            
        }
        
        return ans;
    }
};


/*
    word    10001
    
    pizzel 111001



*/
