class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        long long sum=0;
        priority_queue<int> pq;
        for(int i:target){
            sum+=i;
            pq.push(i);
        }
        while(pq.top() != 1){
            int x=pq.top();
            pq.pop();
            sum-=x;
            if(x==1||sum==1) return true;
            if(sum == 0 || sum >= x) return false;
            int updatedx=x%sum;
            if(updatedx==0) return false;
            sum=sum+updatedx;
            pq.push(updatedx);
            
        }
        
        return true;
    }
};