// интерфейс класса Man
#ifndef MAN_H
#define MAN_H

const int l_name = 30;
const int l_year = 5;
const int l_pay = 10;
const int l_buf = l_name + l_year + l_pay;

class Man {
public:
	Man(int lName = 30);
	~Man();

	char* GetName() const { return pName; }
	int GetBirthYear() const { return birth_year; }
	float GetPay() const { return pay; }

	void SetName(const char*);
	void SetBirthYear(const char*);
	void SetPay(const char*);

	void Print();
	bool CompareName(const char*);
private:
	char* pName;
	int birth_year;
	float pay;

};

#endif // !MAN_H
