class Solution {
public:
    int mirrorReflection(int p, int q) {
        // m is even & n is odd => return 0.
        // m is odd & n is odd => return 1.
        // m is odd & n is even => return 2.
        //Divide p,q by 2 until at least one odd.
        while((p%2==0) && (q%2==0)){
            p/=2;
            q/=2;
        }
        //both p qnd q can't be even
        if((p%2)==0 && (q%2)!=0){
            return 2;//when p is even and q is odd
        } 
        if((p%2)!=0 && (q%2)!=0){
            return 1;// when p is odd and q is odd
        } 
        return 0;// when p is odd and q is even
    }
};