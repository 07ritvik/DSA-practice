class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0;
        int n=heights.size();
        priority_queue<int> maxh;
        for(;i<n-1;i++){
            if(heights[i]>=heights[i+1]){
                continue;
            }
               int diff=heights[i+1]-heights[i];
            if(bricks>=diff){
                maxh.push(diff);
                bricks-=diff;
                
            }
            else if(ladders>0){
                if(!maxh.empty() && maxh.top()>diff){
                 
                    bricks+=maxh.top()-diff;
                    maxh.pop();
                    maxh.push(diff);
                    
                }
                ladders--;
            }
            else break;
        }
        return i;
    }
};