class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i: tokens){
            if(i=="+" || i=="-" || i=="*"|| i=="/"){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                int c;
                if(i=="+") c=b+a;
                if(i=="-") c=b-a;
                if(i=="*") c=b*a;
                if(i=="/") c=b/a;
                s.push(c);    
            }
            else s.push(stoi(i));
        }
        return s.top();
    }
};