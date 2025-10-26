class Bank {
public:
    int n;
    vector<long long> bank;
    Bank(vector<long long>& balance) {
        n = balance.size();
        bank.resize(n+1);
        for (int i=0; i<n; i++) bank[i+1] = balance[i];
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 > n) return false;
        long long b = bank[account1];
        if (b < money) return false;
        bank[account2] += money;
        bank[account1] -= money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > n) return false;
        bank[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > n) return false;
        long long b = bank[account];
        if (b < money) return false;
        bank[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
