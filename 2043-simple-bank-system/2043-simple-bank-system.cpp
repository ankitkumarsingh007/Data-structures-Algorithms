class Bank {
public:
    typedef long long ll;
    
    ll n;
    vector<ll> val;
    
    Bank(vector<long long>& balance) {
        n=balance.size();
        val=balance;
    }
    
    bool helper(int a){
        if(a>=1 && a<=n)
            return true;
        else
            return false;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(helper(account1) && helper(account2) && val[account1-1]>=money){
            val[account1-1]-=money;
            val[account2-1]+=money;
            return true;
        }
        else
            return false;
    }
    
    bool deposit(int account, long long money) {
        if(helper(account)){
            val[account-1]+=money;
            return true;
        }
        else
            return false;
    }
    
    bool withdraw(int account, long long money) {
        if(helper(account) && val[account-1]>=money){
            val[account-1]-=money;
            return true;
        }
        else
            return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */