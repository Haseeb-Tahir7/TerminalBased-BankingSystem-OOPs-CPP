
#include <iostream>
#include <vector>
using namespace std;

class Account {
protected:
    int accNo;
    string name;
    float balance;

public:
    Account(int n, string nm, float b) {
        accNo = n;
        name = nm;
        balance = b;
    }

    void deposit(float amt) {
        balance += amt;
        cout << "Deposited: " << amt << endl;
    }

    void withdraw(float amt) {
        if (amt <= balance) {
            balance -= amt;
            cout << "Withdrawn: " << amt << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display() {
        cout << "Account No: " << accNo << ", Name: " << name << ", Balance: " << balance << endl;
    }

    int getAccNo() {
        return accNo;
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    void createAccount(int no, string name, float bal) {
        accounts.push_back(Account(no, name, bal));
        cout << "Account created successfully!\n";
    }

    void depositAmount(int no, float amt) {
        for (auto &acc : accounts) {
            if (acc.getAccNo() == no) {
                acc.deposit(amt);
                return;
            }
        }
        cout << "Account not found!\n";
    }

    void withdrawAmount(int no, float amt) {
        for (auto &acc : accounts) {
            if (acc.getAccNo() == no) {
                acc.withdraw(amt);
                return;
            }
        }
        cout << "Account not found!\n";
    }

    void showAccount(int no) {
        for (auto &acc : accounts) {
            if (acc.getAccNo() == no) {
                acc.display();
                return;
            }
        }
        cout << "Account not found!\n";
    }
};

int main() {
    Bank b;
    int choice, accNo;
    string name;
    float amount;

    while (true) {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Show Account\n5. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account No, Name, Balance: ";
                cin >> accNo >> name >> amount;
                b.createAccount(accNo, name, amount);
                break;
            case 2:
                cout << "Enter Account No and amount to deposit: ";
                cin >> accNo >> amount;
                b.depositAmount(accNo, amount);
                break;
            case 3:
                cout << "Enter Account No and amount to withdraw: ";
                cin >> accNo >> amount;
                b.withdrawAmount(accNo, amount);
                break;
            case 4:
                cout << "Enter Account No: ";
                cin >> accNo;
                b.showAccount(accNo);
                break;
            case 5:
                return 0;
        }
    }
}
