#include <iostream>
#include <string>

using namespace std;

// Base class
class Account {
protected:
    int accountNumber;
    double balance;
    string customerName;

public:
    Account(int accNumber, double initialBalance, string name)
        : accountNumber(accNumber), balance(initialBalance), customerName(name) {}

    virtual ~Account() {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    void displayInfo() const {
        cout << " --  USER DETAILS  -- " << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Customer Name: " << customerName << endl;
    }

    // Overloaded comparison operators
    bool operator>(const Account& other) const {
        return balance > other.balance;
    }

    bool operator<(const Account& other) const {
        return balance < other.balance;
    }

    bool operator==(const Account& other) const {
        return balance == other.balance;
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;
    static constexpr double MIN_BALANCE = 100.0; // Minimum balance for savingsaccount

public:
    SavingsAccount(int accNumber, double initialBalance, string name, double rate)
        : Account(accNumber, initialBalance, name), interestRate(rate) {}

    void deposit(double amount) override {
        balance += amount;
        // Add interest on deposit
        balance += balance * interestRate / 100;
    }

    void withdraw(double amount) override {
        if (balance - amount < MIN_BALANCE) {
            cout << " -- Withdrawal denied. Minimum balance requirement not met." << endl;
        } else {
            balance -= amount;
        }
    }
};

// Derived class: CheckingAccount
class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNumber, double initialBalance, string name, double limit)
        : Account(accNumber, initialBalance, name), overdraftLimit(limit) {}

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance - amount < -overdraftLimit) {
            cout << " -- Withdrawal denied. Overdraft limit exceeded." << endl;
        } else {
            balance -= amount;
        }
    }
};

// Derived class: InvestmentAccount
class InvestmentAccount : public Account {
private:
    int investmentDuration; // in months
    double riskFactor; // Percentage impact on balance

public:
    InvestmentAccount(int accNumber, double initialBalance, string name, int duration, double risk)
        : Account(accNumber, initialBalance, name), investmentDuration(duration), riskFactor(risk) {}

    void deposit(double amount) override {
        balance += amount;
        // Apply risk factor on deposit
        balance += amount * riskFactor / 100;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << " -- Withdrawal denied. Insufficient funds." << endl;
        } else {
            balance -= amount;
            // Apply risk factor on withdrawal
            balance -= amount * riskFactor / 100;
        }
    }
};

int main() {
    // Create account objects using pointers
    Account* savingsaccount = new SavingsAccount(101, 5000.0, "Alisha", 2.5);
    Account* checkingaccount = new CheckingAccount(102, 1000.0, "Fatma", 500.0);
    Account* investmentaccount = new InvestmentAccount(103, 2000.0, "Asma", 12, 5.0);

    // Display initial info
    cout << "Initial Account Info:" << endl;
    savingsaccount->displayInfo();
    checkingaccount->displayInfo();
    investmentaccount->displayInfo();

    cout << endl;

    // Perform operations
    savingsaccount->deposit(500);
    checkingaccount->withdraw(200);
    investmentaccount->withdraw(300);

    cout << "Updated Account Info:" << endl;
    savingsaccount->displayInfo();
    checkingaccount->displayInfo();
    investmentaccount->displayInfo();

    cout << endl;

    // Compare accounts
    if (*savingsaccount > *checkingaccount) {
        cout << " -- savingsaccount account has more balance than checkingaccount account." << endl;
    } else if (*savingsaccount < *checkingaccount) {
        cout << " -- checkingaccount account has more balance than savingsaccount account." << endl;
    } else {
        cout << " -- savingsaccount and checkingaccount accounts have equal balance." << endl;
    }

    if (*investmentaccount == *checkingaccount) {
        cout << " -- investmentaccount account has the same balance as checkingaccount account." << endl;
    } else {
        cout << " -- investmentaccount account and checkingaccount account have different balances." << endl;
    }

    // Clean up allocated memory
    delete savingsaccount;
    delete checkingaccount;
    delete investmentaccount;
    cout << "dynamic memory is freed succesfully :)" << endl;


    return 0;
}
