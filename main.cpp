#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <locale.h> 
using namespace std;
class Employee {
protected:
	string FIO;
	double oklad;
	double procent_nadb;
	int stazh;

public:
	Employee(string fio, double zarplata, double procent, int opiyt) {
		FIO = fio;
		oklad = zarplata;
		procent_nadb = procent;
		stazh = opiyt;
	}

	virtual double itogovya_zarplata() {
		return oklad + (oklad * procent_nadb * stazh / 100);
	}

	virtual void print_info_emplo() {
		cout << "ФИО: " << FIO << "." << endl;
		cout << "Оклад: " << oklad << " рублей." << endl ;
		cout << "Надбавка за год: " << procent_nadb << "%." << endl;
		cout << "Стаж: " << stazh <<  " лет." << endl;
	}
	void print_info_emplo(int code) {
		cout << "Код сотрудника: " << code << endl;
		
	}
};

class Manager : public Employee {
protected:
	double procent_nadbavk_manag;
	string name_of_otdel;

public:
	Manager(string fio, double zarplata, double procent, int opiyt, double pr_na_man, string nam_o_otd) : Employee(fio, zarplata, procent, opiyt) {
		procent_nadbavk_manag = pr_na_man;
		name_of_otdel = nam_o_otd;
	}
	double itogovya_zarplata() override {
		return oklad + (oklad * procent_nadb * stazh / 100) + (oklad*procent_nadbavk_manag/100);
	}
	void print_info_emplo() override {
		Employee::print_info_emplo();
		cout << "Надбавка руководителя: " << procent_nadbavk_manag << "%" << endl;
		cout << "Отдел: " << name_of_otdel << "." << endl;
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	Employee a("Федоров Иван Олегович", 65000, 2, 1);
	Manager b("Крысова Анна Юрьевна", 120000, 15, 10, 1, "2");
	Employee c("Баланов Алексей Дмитриевич", 70000, 2, 1);
	Manager d("Холин Максим Анатольевич", 145000, 15, 10, 1, "2");
	vector <Employee*> employees;
	employees.push_back(&a);
	employees.push_back(&b);
	employees.push_back(&c);
	employees.push_back(&d);
	double summa = 0;
	for (Employee* emp : employees) {
		emp->print_info_emplo();
		cout << "Зарплата итоговая: " << emp->itogovya_zarplata()  << " рублей." << endl;
		summa += emp->itogovya_zarplata();
		cout << "----------------------------------" << endl;
		
	}
	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "Итоговая сумма зарплат: " << summa << " рублей." << endl;
	cout << "----------------------------------" << endl;
	employees[0]->print_info_emplo();
	employees[0]->print_info_emplo(5000);
}	
