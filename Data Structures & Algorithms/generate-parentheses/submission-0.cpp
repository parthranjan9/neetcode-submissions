class Solution {
public:

    vector<string>ans;

    bool isvalid(string &curr){
        int cnt = 0 ;
        for(auto ch : curr){
            if(ch == '(') cnt++;
            else{
                cnt--;
                if(cnt < 0) return false;
            }
        }
        if(cnt == 0){
            return true;
        }
        return false;
    }

    void solve(int n , string curr , int open , int close){
        if(curr.length()==2*n){
            if(isvalid(curr)){
                ans.push_back(curr);
            }
            return ;
        }

        // do explore undo cycle
        curr.push_back('(');
        solve(n,curr,open++,close);
        curr.pop_back();

        curr.push_back(')');
        solve(n,curr,open,close++);
        curr.pop_back();

    }

    vector<string> generateParenthesis(int n) {
        int open  = 0 ; 
        int close = 0 ;
        string curr = "";
        solve(n,curr,open , close);
        return ans ;
    }
};
