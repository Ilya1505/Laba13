// с++.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include <iostream>
#include <string>

using namespace std;

class MyException : public exception// класс наследник exception
{
private:
	int CodeError;// код ошибки
public:
	MyException(char *msg, int CodeError) :exception(msg)
	{
		this->CodeError = CodeError;
	}
	int Code()
	{
		return CodeError;
	}
};
template<typename T> class Sizeof// шаблон класса
{
private:
	T value;
public:
	Sizeof(T value)
	{
		this->value = value;
	}
	void SetValue(T value)
	{
		this->value = value;
	}
	T GetValue()
	{
		return value;
	}
	void DataTypeSize()
	{
		cout << "Размер элемента: " << sizeof(value) << " байт" << endl;
	}
};





class avtoshop// абстрактный класс
{
public:
	virtual void addTov() = 0;// чисто виртуальный метод
};

class engine// двигатель
{
private:
	int power;// мощность (л.с.)
	string name;// марка двигателя
	double weight;// вес
	int probeg;// пробег
	int resurs;// ресурс двигателя
public:
	engine &operator=(const engine &other)// перегрузка опрератора =
	{
		this->power = other.power;
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
		return *this;
	}
	engine(string init_name, double weight, int power, int probeg, int resurs)// конструктор с параметрами
	{
		this->name = init_name;
		this->weight = weight;
		this->power = power;
		this->probeg = probeg;
		this->resurs = resurs;
	}
	engine(string name)
	{
		this->name = name;
		this->weight = 50;
		this->power = 100;
		this->probeg = 0;
		this->resurs = 100;
	}
	engine()// конструктор без параметров
	{
		name = "No_Name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 300;
	}

	// сеттеры и геттеры
	void SetName(string name)
	{
		this->name = name;
	}
	void SetWeight(double weight)
	{
		this->weight = weight;
	}
	void SetPower(int power)
	{
		this->power = power;
	}
	void SetProbeg(int probeg)
	{
		this->probeg = probeg;
	}
	void SetResurs(int resurs)
	{
		this->resurs = resurs;
	}
	string GetName()
	{
		return name;
	}
	double GetwWight()
	{
		return weight;
	}
	int GetPower()
	{
		return power;
	}
	int GetProbeg()
	{
		return probeg;
	}
	int GetResurs()
	{
		return resurs;
	}
	void Remont()// ремонт двигателя
	{
		probeg = 0;
	}
	void Read()// ввод данных
	{
		fflush(stdin);
		cout << endl << "Марка двигателя: ";
		getline(cin, name);
		if (name == "") throw exception("Введена пустая строка марки двигателя!!!");
		cout << "Вес двигателя: ";
		cin >> weight;
		if (weight <10 || weight>5000) throw exception("Введен неккоректный вес двигателя!!!");
		cout << "Мощность двигателя: ";
		cin >> power;
		if (power <10 || power>1500) throw exception("Введена неккоректная мощность двигателя!!!");
		cout << "Пробег двигателя: ";
		cin >> probeg;
		if (probeg <0 || probeg>1000000) throw exception("Введен неккоректный пробег!!!");
		cout << "Ресурс двигателя: ";
		cin >> resurs;
		if (resurs <100 || resurs>5000000) throw exception("Введен неккоректный ресурс двигателя!!!");
	}
	void Print()// вывод данных
	{
		cout << "Марка двигателя: " << name << endl;
		cout << "Мощность двигателя: " << power << endl;
		cout << "Пробег двигателя: " << probeg << endl;
		cout << "Ресурс двигателя: " << resurs << endl;
		cout << "Масса двигателя: ";
		printf("%.4lf\n", weight);
	}
	~engine()// деструктор
	{

	}
};
class technika :public avtoshop// родительский класс всей техники, наследник абстрактного класса avtoshop
{
protected:
	int year;// год выпуска
	string name;// марка техники
	string color;// цвет техники
	double price;// цена
	int count;
	int petrol;// количество бензина (в литрах)
public:
	technika(const technika &other)// конструктор копирования
	{
		this->year = other.year;
		this->name = other.name;
		this->color = other.color;
		this->price = other.price;
		this->count = other.count;
		this->petrol = other.petrol;
	}
	technika(int year, string name, string color, double price, int count)// конструктор с параметрами
	{
		this->name = name;
		this->color = color;
		this->year = year;
		this->price = price;
		this->count = count;
		this->petrol = 0;
	}
	technika()// конструктор без параметров
	{
		name = "No_Name";
		color = "No_Color";
		year = 2020;
		price = 1000;
		count = 0;
		zapravka();// вызов виртуальной функции из функции базового класса
	}
	// сеттеры и геттеры
	void SetName(string name)
	{
		this->name = name;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	void SetYear(int year)
	{
		this->year = year;
	}
	void SetPrice(double price)
	{
		this->price = price;
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	string GetName()
	{
		return name;
	}
	string GetColor()
	{
		return color;
	}
	int GetYear()
	{
		return year;
	}
	double GetPrice()
	{
		return price;
	}
	int GetCount()
	{
		return count;
	}
	int GetPetrol()
	{
		return petrol;
	}
	virtual void zapravka()// виртуальная функция
	{
		if (petrol == 0)
		{
			petrol = 100;
			cout << "Полный бак!(100л)" << endl;
		}
		else
		{
			cout << "ошибка, бак не пустой!" << endl;
		}
	}
	int Sell()
	{
		count--;
		cout << "Техника продана!" << endl;
		cout << "текущее количество: " << count << endl;
		return count;
	}
	friend void operator<<(ostream &o, technika t);
	friend technika operator>>(istream &o, technika &t);
	void addTov() override
	{
		count++;
		cout << "Добавлена 1 новая техника" << endl;
	}
	void Zapravit()// функция, вызывающая виртуальную функцию или переопределенную функцию
	{
		zapravka();
	}
};
void operator<<(ostream &o, technika t)// функкция вывода данных
{
	cout << endl << "Марка: " << t.name << endl;
	cout << "Цвет: " << t.color << endl;
	cout << "Год выпуска: " << t.year << endl;
	cout << "Цена: ";
	printf("%.4lf\n", t.price);
	cout << "Количество: " << t.count << endl;
}
technika operator >>(istream &o, technika &t)// функция ввода данных
{
	fflush(stdin);
	cout << "Марка: ";
	getline(cin, t.name);
	if (t.name == "") throw exception("Введена пустая строка марки!!!");
	fflush(stdin);
	cout << "Цвет: ";
	getline(cin, t.color);
	if (t.color == "") throw exception("Введена пустая строка цвета!!!");
	cout << "Год выпуска: ";
	cin >> t.year;
	if (t.year<2000 || t.year>2020) throw exception("Введен неккоректный год выпуска!!!");
	cout << "Цена: ";
	cin >> t.price;
	if (t.price <= 0) throw exception("Введена неккоректная цена!!!");
	cout << "Количесвто: ";
	cin >> t.count;
	if (t.count <= 0) throw exception("Введено неккоректное количество!!!");
	return t;
}
class cars :public technika// производный класс "машины" от класса "техника"
{
private:
	engine dvs;// двигатель
	double timeToHundred;// время разгона до сотни

public:
	cars()
	{
		timeToHundred = 0;
	}
	cars(engine &dvs, double time, int year, string name, string color, double price, int count) :technika(year,
		name, color, price, count)
	{
		this->dvs = dvs;//установка двигателя
		this->timeToHundred = time;
	}
	void SetTime(double time)
	{
		this->timeToHundred = time;
	}
	double GetTime()
	{
		return timeToHundred;
	}
	void Modern(double NewWeight, int NewPower, int NewResurs)// модернизация
	{
		if (NewWeight<10 || NewWeight>500) throw MyException("Ошибка, некорректные данные модернизации!", 3);
		if (NewPower<50 || NewPower>1500) throw MyException("Ошибка, некорректное данные модернизации!", 4);
		if (NewResurs<500 || NewResurs>500000) throw MyException("Ошибка, некорректное данные модернизации!", 5);
		dvs.SetWeight(NewWeight);
		dvs.SetPower(NewPower);
		dvs.SetResurs(NewResurs);
		dvs.Remont();
	}
	int Sell(int count)// перегрузка метода базового класса
	{
		if (this->count < count) throw exception("неккоректное количество продаваемых машин!");
		this->count -= count;
		cout << "Техника продана!" << endl;
		cout << "текущее количество: " << this->count << endl;
	}
	void operator=(technika other)
	{
		this->name = other.GetName();
		this->color = other.GetColor();
		this->year = other.GetYear();
		this->price = other.GetPrice();
		this->count = other.GetCount();
		this->petrol = other.GetPetrol();
		this->timeToHundred = 0;
	}
	void zapravka() override// переопределенная функция базового класса
	{
		if (petrol != 100)
		{
			petrol += 10;
			cout << "заправка на 10 литров!" << endl;
		}
		else
		{
			cout << "не удалось заправиться, бак полный" << endl;
		}
	}
	void addTov() override
	{
		count += 3;
		cout << "Добавлено 3 новые машины" << endl;
	}
	int Drive(cars *avto, int km);
	friend void operator<<(ostream &o, cars c);// перегрузка оператора cout
	friend cars operator>>(istream &o, cars &c);// перегрузка оператора cin
};
void operator<<(ostream &o, cars c)
{
	cout << endl << "машина:" << endl;
	cout << "Марка: " << c.name << endl;
	cout << "Цвет: " << c.color << endl;
	cout << "Год выпуска: " << c.year << endl;
	cout << "Цена: ";
	printf("%.4lf\n", c.price);
	cout << "Количество: " << c.count << endl;
	cout << "Время разгона до сотни: " << c.timeToHundred << " секунд" << endl;
	c.dvs.Print();
}
cars operator>>(istream &o, cars &c)// перегрузка оператора cin
{
	cout << "машина:" << endl;
	fflush(stdin);
	cout << "Марка: ";
	getline(cin, c.name);
	if (c.name == "") throw exception("Введена пустая строка марки!!!");
	fflush(stdin);
	cout << "Цвет: ";
	getline(cin, c.color);
	if (c.color == "") throw exception("Введена пустая строка цвета!!!");
	cout << "Год выпуска: ";
	cin >> c.year;
	if (c.year<2000 || c.year>2020) throw exception("Введен неккоректный год выпуска!!!");
	cout << "Цена: ";
	cin >> c.price;
	if (c.price <= 0) throw exception("Введена неккоректная цена!!!");
	cout << "Количесвто: ";
	cin >> c.count;
	if (c.count <= 0) throw exception("Введено неккоректное количество!!!");
	cout << "время разгона до сотни: ";
	cin >> c.timeToHundred;
	if (c.timeToHundred<0 || c.timeToHundred>100000) throw exception("введено неккоректное время!!!");
	c.dvs.Read();
	return c;
}

int cars::Drive(cars *avto, int km)// возврат значений через указатель
{
	if (km<1) throw MyException("Ошибка, некорректное расстояние тест-драйва!", 0);
	if (km>100)throw MyException("Ошибка, некорректное расстояние тест-драйва!", 1);
	int ProbegAfterDrive;
	ProbegAfterDrive = avto->dvs.GetProbeg() + km;
	avto->dvs.SetProbeg(ProbegAfterDrive);
	avto->petrol -= 10;
	return ProbegAfterDrive;
}

class plane :public technika// производный класс "самолет" от класса "техника"
{
private:
	double MaxHeight;// максимальная высота полета (в метрах)
	double HourFly;// налет в часах
public:
	plane()
	{
		MaxHeight = 10000;
		HourFly = 0;
	}
	plane(double maxheight, double hourfly, int year, string name, string color, double price, int count) :technika(year,
		name, color, price, count)
	{
		MaxHeight = maxheight;
		HourFly = hourfly;
	}
	void SetHeight(double height)
	{
		this->MaxHeight = height;
	}
	void SetHourFly(double hour)
	{
		this->HourFly = hour;
	}
	double GetHeight()
	{
		return MaxHeight;
	}
	double GetHour()
	{
		return HourFly;
	}
	double Fly(double hour)// функция полета на определенное количество часов
	{
		if (hour < 0) throw exception("неккоректная продолжительность полета!");
		HourFly += hour;
		return HourFly;
	}
	void addTov() override
	{
		count += 2;
		cout << "Добавлено 2 новых самолета" << endl;
	}
	friend void operator<<(ostream &o, plane p);// перегрузка оператора cout
	friend plane operator>>(istream &o, plane &p);// перегрузка оператора cin
};
void operator<<(ostream &o, plane p)// перегрузка оператора cout
{
	cout << "самолет:" << endl;
	cout << "Марка: " << p.name << endl;
	cout << "Цвет: " << p.color << endl;
	cout << "Год выпуска: " << p.year << endl;
	cout << "Цена: ";
	printf("%.4lf\n", p.price);
	cout << "Количество: " << p.count << endl;
	cout << "максимальная высота полета: ";
	cin >> p.MaxHeight;
	cout << "время налета (в часах): ";
	cin >> p.HourFly;
}
plane operator>>(istream &o, plane &p)// перегрузка оператора cin
{
	cout << "самолет:" << endl;
	fflush(stdin);
	cout << "Марка: ";
	getline(cin, p.name);
	if (p.name == "") throw exception("Введена пустая строка марки!!!");
	fflush(stdin);
	cout << "Цвет: ";
	getline(cin, p.color);
	if (p.color == "") throw exception("Введена пустая строка цвета!!!");
	cout << "Год выпуска: ";
	cin >> p.year;
	if (p.year<2000 || p.year>2020) throw exception("Введен неккоректный год выпуска!!!");
	cout << "Цена: ";
	cin >> p.price;
	if (p.price <= 0) throw exception("Введена неккоректная цена!!!");
	cout << "Количесвто: ";
	cin >> p.count;
	if (p.count <= 0) throw exception("Введено неккоректное количество!!!");
	cout << "максимальная высота полета: " << p.MaxHeight << endl;
	cout << "время налета: " << p.HourFly << "часов(а)" << endl;
	return p;
}

void addTov(avtoshop *ptr)
{
	ptr->addTov();
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// подключение русскоязычного ввода/вывода
	SetConsoleOutputCP(1251);
	//класс машина:
	engine dvs("св-01", 10, 100, 0, 400);
	technika *tk = new technika(2020, "No_Name", "No_Color", 15000, 5);
	cars *avto = new cars(dvs, 5, 2020, "No_Name", "No_Color", 1000, 8);
	int a = 4;
	Sizeof<int> size1(a);
	size1.DataTypeSize();
	tk->Zapravit();// вызов функции, вызывающей виртуальную функцию базового класса
	*avto = *tk;// перегрузка оператора =
	cout << *avto;
	Sizeof<cars> size2(*avto);
	size2.DataTypeSize();
	bool f;
	do{
		f = false;
		try{ cin >> *avto; }
		catch (exception &ex)
		{
			cout << "Ошибка ввода: " << ex.what() << endl;
			cout << "Повторите попытку ввода!" << endl;
			f = true;
		}
	} while (f);
	printf("\nДанные после ввода:");
	cout << *avto;
	int probeg = 0;
	try{ probeg = avto->Drive(avto, 10); }
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		cout << "Код ошибки: " << ex.Code() << endl;
		cout << "завершение работы программы!";
		getch();
		exit(1);
	}
	avto->Zapravit();// функция, вызывающая функцию производного класса
	printf("\nПробег после тест-драйва: ");
	cout << probeg << endl;
	try{ avto->Modern(100, 200, 500); }
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		cout << "Код ошибки: " << ex.Code() << endl;
		cout << "завершение работы программы!";
		getch();
		exit(1);
	}
	printf("\nПосле модернизации:");
	cout << *avto;
	avto->technika::Sell();// вызов перегруженного метода базового класса
	try{ avto->Sell(5); }
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		cout << "завершение работы программы!";
		getch();
		exit(1);
	}
	addTov(avto);
	//класс самолет
	plane pl(20000, 0, 2020, "No_Name", "No_Color", 150000, 5);
	cout << pl;
	do{
		f = false;
		try{ cin >> pl; }
		catch (exception &ex)
		{
			cout << "Ошибка ввода: " << ex.what() << endl;
			cout << "Повторите попытку ввода!" << endl;
			f = true;
		}
	} while (f);
	printf("\nДанные после ввода:");
	cout << pl;
	try{ pl.Fly(1); }
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		cout << "завершение работы программы!";
		getch();
		exit(1);
	}
	cout << "Налет (в часах) после полета: " << pl.GetHour() << endl;
	pl.Sell();
	getch();
	return 0;
}

