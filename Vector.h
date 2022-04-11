#include <iostream>
using namespace std;
template <class T> //T - �������� �������
class Vector
{
public:
	//����������� � �����������: �������� ������ ��� s ��������� � ��������� ��
	//��������� k
	Vector(int s, T k);
	//����������� � �����������
	Vector(const Vector<T>& a);
	//����������
	~Vector();
	//�������� ������������
	Vector& operator=(const Vector<T>& a);
	//�������� ������� �� �������
	T& operator[](int index);
	//�������� ��� ���������� ���������
	Vector operator+(const T k);
	Vector operator+(const int k);
	//��������, ������������ ����� �������
	int operator()();
	//������������� �������� �����-������
	// <> - ��������� �� ��, ��� ������� �������� ��������
	friend ostream& operator<< <>(ostream& out, const Vector<T>& a);
	friend istream& operator>> <>(istream& in, Vector<T>& a);
private:
	int size;//������ �������
	T* data;//�������� �� ������������ ������ �������� �������
};
//���e������� �������
//����������� � �����������
template <class T>
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
//����������� �����������
template <class T>
Vector<T>::Vector(const Vector& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
//����������
template <class T>
Vector<T>::~Vector()
{
	delete[]data;
	data = 0;
}
//�������� ������������
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
//�������� ������� �� �������
template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//�������� ��� ���������� ���������
template <class T>
Vector<T> Vector<T>::operator+(const T k)//+k
{
	Vector<T> temp(size, k);//�������������� ��������� ������ ����� ���������
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] + k;
	return temp;
}
//�������� ��� ���������� �����
template <class T>
Vector<T> Vector<T>::operator+(const int k)//+k
{
	if (size > 0) 
	{
		Vector<T> temp(size, data[0]);//�������������� ��������� ������ ����� ���������
		for (int i = 0; i < size; ++i)
			temp.data[i] = data[i] + k;
		return temp;
	}
	else cout << "\nError! size = 0";
	 
}
//�������� ��� ��������� ����� �������
template <class T>
int Vector<T>::operator ()()
{
	return size;
}
//�������� ��� �����-������
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