#include <stdio.h>
#include <string.h>

#include "BankAccount.h"

BankAccount InitBankAccount(char* newName, double chBalance, double sBalance)
{
    BankAccount newAccount;

    strcpy(newAccount.customerName, newName);

    newAccount.checkingAccountBalance = chBalance;

    newAccount.savingsAccountBalance = sBalance;

    return newAccount;

}

BankAccount SetName(char* newName, BankAccount account)
{
    strcpy(account.customerName, newName);

    return account;
}

void GetName(char* customerName, BankAccount account)
{
    strcpy(customerName, account.customerName);
}

BankAccount SetChkBalance(double balance, BankAccount account)
{
    account.checkingAccountBalance = balance;
    return account;
}

double GetChkBalance(BankAccount account)
{
    return account.checkingAccountBalance;
}

BankAccount SetSavBalance(double balance, BankAccount account)
{
    account.savingsAccountBalance = balance;
    return account;
}

double GetSavBalance(BankAccount account)
{
    return account.savingsAccountBalance;
}

BankAccount DepositChecking(double amt, BankAccount account)
{
    if (amt > 0)
    {
    account.checkingAccountBalance += amt;
    }
    return account;
}

BankAccount DepositSavings(double amt, BankAccount account)
{
    if (amt > 0)
    {
    account.savingsAccountBalance += amt;
    }
    return account;
}

BankAccount WithdrawChecking(double amt, BankAccount account)
{

    if (amt > 0)
    {
    account.checkingAccountBalance -= amt;
    }
    return account;
}

BankAccount WithdrawSavings(double amt, BankAccount account)
{
    if (amt > 0)
    {
    account.savingsAccountBalance -= amt;
    }
    return account;
}

BankAccount TransferToChecking(double amt, BankAccount account)
{
    if (amt > 0)
    {
        account.checkingAccountBalance += amt;
        account.savingsAccountBalance -= amt;
    }

    return account;
}