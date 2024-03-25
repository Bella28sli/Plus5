#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <random>
#include "Plus5.h"

using namespace std;

class BankAccount
{
	friend bool Transfer(BankAccount* acc1, BankAccount* acc2, double summ);
private:
	int accountNumber;
	double balance;
	double interestRate;
public:
	double newbalance;
	BankAccount(int accountNumber, double balance) {
		this->accountNumber = accountNumber;
		this->balance = balance;
		this->interestRate = 0;
	}
	void Deposit() {
		cout << "\nВведите сумму: ";
		cin >> newbalance;
		this->balance += newbalance;
		getBalance();
	}
	void Withdraw() {
		cout << "\nВведите сумму: ";
		cin >> newbalance;
		if (this->balance >= newbalance) {
			this->balance -= newbalance;
			getBalance();
		}
		else {
			cout << "Недостаточно средств";
		}
	}
	void getBalance() {
		cout << "\nВаш баланс: " << this->balance;
	}
	void getInterest() {
		double pr;
		pr = (this->interestRate*0.01)*(this->balance*0.83);
		cout << "\nСумма заработанных процентов: " << pr;

	}
	void setInterestRate() {
		cout << "\nВведите новую ставку: ";
		cin >> this->interestRate;

	}
	void getAccountNumber() {
		cout << "\nНомер вашего счёта: ";
		cout << this->accountNumber;
	}

};

int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	string choice;
	BankAccount person1{ 123, 0 };
	BankAccount person2{ 321, 0 };
	BankAccount* per1 = &person1;
	BankAccount* per2 = &person2;
	BankAccount activeperson = person1;
	bool person = true;

	do {
		cout << "\nВыберете операцию\n1.Пополнить\n2.Снять\n3.Посмотреть баланс\n4.Посмотреть заработанные проценты\n5.Обновить процентную ставку\n6.Посмотреть номер аккаунта\n7.Перевести деньги\n8.Сменить пользователя\n";
		cin >> choice;
		if (choice == "1") {
			activeperson.Deposit();
		}
		else if (choice == "2") {
			activeperson.Withdraw();
		}
		else if (choice == "3") {
			activeperson.getBalance();
		}
		else if (choice == "4") {
			activeperson.getInterest();
		}
		else if (choice == "5") {
			activeperson.setInterestRate();
		}
		else if (choice == "6") {
			activeperson.getAccountNumber();
		}
		else if (choice == "7") {
			double summ;
			cout << "\nВведите сумму перевода: ";
			cin >> summ;
			if (person) {
				Transfer(per1, per2, summ);
			}
			else {
				Transfer(per2, per1, summ);
			}
		}
		else if (choice == "8") {
			if (person) {
				activeperson = person2;
				person = false;
			}
			else {
				activeperson = person1;
				person = true;
			}
			cout << "\nПользователь изменён";
			activeperson.getAccountNumber();
		}
		if (person) {
			person1 = activeperson;
		}
		else {
			person2 = activeperson;
		}
	} while (true);

}
bool Transfer(BankAccount* acc1, BankAccount* acc2, double summ) {
	if (acc1->balance >= summ) {
		acc1->balance -= summ;
		acc2->balance += summ;
		cout << "Операция завершена";
		return true;
	}
	else {
		cout << "Недостаточно средств";
		return false;
	}
}