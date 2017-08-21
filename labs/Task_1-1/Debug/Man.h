// интерфейс класса Man
#ifndef MAN_H
#define MAN_H

class Man {
public:
	Man(int lName = 30);
	~Man();

	char* GetName() const { return pName; }
	int GetBirthYear() const { return birth_year; }
	float GetPay() const { return pay; }

	void SetName(const char* fromBuf);
	//void SetBirthYear(const char*);
	//void SetPay(const char*);
private:
	char* pName;
	int birth_year;
	float pay;

};

#endif // !MAN_H
