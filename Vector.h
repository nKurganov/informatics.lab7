#include <iostream>
using namespace std;
template <class T> //T - параметр шаблона
class Vector
{
public:
	//конструктор с параметрами: выделяет память под s элементов и заполняет их
	//значением k
	Vector(int s, T k);
	//конструктор с параметрами
	Vector(const Vector<T>& a);
	//деструктор
	~Vector();
	//оператор присваивания
	Vector& operator=(const Vector<T>& a);
	//операция доступа по индексу
	T& operator[](int index);
	//операция для добавление константы
	Vector operator+(const T k);
	Vector operator+(const int k);
	//операция, возвращающая длину вектора
	int operator()();
	//перегруженные операции ввода-вывода
	// <> - указывают на то, что функция является шаблоном
	friend ostream& operator<< <>(ostream& out, const Vector<T>& a);
	friend istream& operator>> <>(istream& in, Vector<T>& a);
private:
	int size;//размер вектора
	T* data;//укзатель на динамический массив значений вектора
};
//опрeделение функций
//конструктор с параметрами
template <class T>
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
//деструктор
template <class T>
Vector<T>::~Vector()
{
	delete[]data;
	data = 0;
}
//операция присваивания
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}
//операция доступа по индексу
template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//операция для добавления константы
template <class T>
Vector<T> Vector<T>::operator+(const T k)//+k
{
	Vector<T> temp(size, k);//инициализируем временный вектор любым значением
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] + k;
	return temp;
}
//операция для добавления числа
template <class T>
Vector<T> Vector<T>::operator+(const int k)//+k
{
	if (size > 0) 
	{
		Vector<T> temp(size, data[0]);//инициализируем временный вектор любым значением
		for (int i = 0; i < size; ++i)
			temp.data[i] = data[i] + k;
		return temp;
	}
	else cout << "\nError! size = 0";
	 
}
//операция для получения длины вектора
template <class T>
int Vector<T>::operator ()()
{
	return size;
}
//операции для ввода-вывода
template <class T>
ostream& operator<< (ostream& out, const Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator>> (istream& in, Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}