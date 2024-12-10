#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

typedef struct BankAccount_struct
{
    char customerName[20];
    double savingsAccountBalance;
    double checkingAccountBalance;
} BankAccount;

BankAccount InitBankAccount(char* newName, double chBalance, double sBalance);

BankAccount SetName(char* newName, BankAccount account);
void GetName(char* customerName, BankAccount account);

BankAccount SetChkBalance(double balance, BankAccount account);
double GetChkBalance(BankAccount account);

BankAccount SetSavBalance(double balance, BankAccount account);
double GetSavBalance(BankAccount account);

BankAccount DepositChecking(double amt, BankAccount account);
BankAccount DepositSavings(double amt, BankAccount account);

BankAccount WithdrawChecking(double amt, BankAccount account);
BankAccount WithdrawSavings(double amt, BankAccount account);

BankAccount TransferToChecking(double amt, BankAccount account);

#endif