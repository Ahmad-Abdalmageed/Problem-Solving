class Solution {
public:
int countOrders(int n){
    const long long MOD = 1e9+7;
    long long pickups = 1;
    long long deliver = 1;

    // Calculate all possible pick up senarios
    // NPN --- n!
    for(int i = 2; i <= n; i++){
        pickups = (pickups * i)%MOD;
    }

    // Calculate all possible delivery options
    // 2n-1 --- 3, 1
    for(int i = 3; i < (2*n); i=i+2){
        deliver = (deliver * i)%MOD;
    }
    return (deliver * pickups)%MOD;
}

};