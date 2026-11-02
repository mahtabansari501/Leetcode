class Solution {
public:
    using ll=long long;
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1;
        ll p=value;
        for(ll i=2;i*i<=value;i++) {
            if (value%i==0){
                p=i;
                break;
            }
        }
        if(index>0){
            if(value%2==0) {
                if(value<=2LL*index)return -1;
            } else {
                if (value-p-2LL*(index-1)<=0) return -1;
            }
        }
        ll rem=n-1-index;
        if (rem==0) return value;
        if (value%2==0) {
            return value+2LL*rem;
        } else {
            return value+p+2LL*(rem-1);
        }
    }
};