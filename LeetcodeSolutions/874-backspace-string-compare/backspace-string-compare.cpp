class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(auto ch: s){
            if(ch != '#') st1.push(ch);
            else if (st1.size()  > 0) st1.pop();
        }
        for(auto ch: t){
            if(ch != '#') st2.push(ch);
            else if (st2.size()  > 0) st2.pop();
        }
        while(st1.size()>0 || st2.size()>0){
            if(st1.size() == 0 || st2.size() == 0) return false;
            if(st1.top() != st2.top()) return false;
            st1.pop();
            st2.pop();
        }

        return true;
    }
};