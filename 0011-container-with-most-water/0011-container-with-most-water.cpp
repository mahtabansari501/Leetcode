class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_left=-1,max_right=-1;
        int idx_left=-1,idx_right=-1;
        int n=height.size();
        int st=0,end=n-1;
        int ans=-1;
        while(st<end){
            if(height[st]>max_left){
                max_left=height[st];
                idx_left=st;
            }
            if(height[end]>max_right){
                max_right=height[end];
                idx_right=end;
            }
            ans=max(ans,(min(max_left,max_right)*abs(idx_left-idx_right)));
            if(max_left>=max_right){
                end--;
            }
            else st++;
        }
        return ans;
    }
};