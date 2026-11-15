
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n,vector<double>(n,0));
        dp[row][column]=1.0;
        int dx[8]={-2,-2,-1,-1,1,1,2,2};
        int dy[8]={-1,1,-2,2,-2,2,-1,1};
        for(int t=0;t<k;t++){
            vector<vector<double>> ndp(n,vector<double>(n,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int d=0;d<8;d++){
                        int x=i+dx[d];
                        int y=j+dy[d];
                        if(x>=0 && x<n && y>=0 && y<n){
                            ndp[x][y]+=dp[i][j]/8.0;
                        }
                    }
                }
            }
            dp=ndp;
        }
        double ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
