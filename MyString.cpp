#include "MyString.h"
#include<string.h>
#include<iostream>
using namespace std;

// ------------------------------------ MEMBER FUNCTIONS ------------------------------------

// ham tao
MyString::MyString()
{
	m_size = 0;
	string = NULL;
}

// ham tao co doi so
MyString::MyString(const char* a)
{
	if (a == NULL)
	{
		m_size = 0;
		string = NULL;
	}

	int temp = 0;
	m_size = 0;
	while (a[temp] != NULL)
	{
		string = (char*)realloc(string, (temp + 1) * sizeof(char));
		string[temp] = a[temp];
		temp++;
		m_size++;
	}
	string[m_size] = NULL;
}

MyString::MyString(const char* a, int m)
{
	m_size = m;
	string = new char[m_size];
	for (int i = 0; i < m_size; i++)
	{
		string[i] = a[i];
	}

	string[m_size] = NULL;
}

MyString::MyString(int m, char a)
{
	m_size = m;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		string[i] = a;
	}
	string[m_size] = NULL;
}

// ham tao sao chep
MyString::MyString(const MyString& other)
{
	m_size = other.m_size;
	char* string = (char*)malloc((m_size + 1) * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		string[i] = other.string[i];
	}
	string[m_size] = NULL;
}

MyString::MyString(const MyString& other, int pos, int len)
{
	if (pos >= 0 && pos <= other.m_size && len >= 0)
	{
		m_size = len;
		string = (char*)realloc(string, m_size * sizeof(char));
		for (int i = 0; i < m_size; i++)
		{
			string[i] = other.string[i + pos];
		}
		string[m_size] = NULL;
	}
	else
		throw "Sai thong so truyen vao ham tao";
}

// Ham huy
MyString::~MyString()
{
//	m_size = 0;
//	string = NULL;
}

// toan tu gan bang
MyString& MyString::operator=(const MyString& p)
{
	m_size = p.m_size;
	string = (char*)realloc(string, m_size* sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		string[i] = p.string[i];
	}
	string[m_size] = NULL;
	return *this;
}

MyString& MyString::operator=(const char* s)
{
	int l = 0;
	while (s[l] != NULL)
	{
		l++;
	}

	m_size = l;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		string[i] = s[i];
	}

	return *this;
}

MyString& MyString::operator=(const char c)
{
	m_size = 1;
	string = (char*)realloc(string, m_size * sizeof(char));
	string[0] = c;
	string[m_size] = NULL;
	return *this;
}








// ------------------------------------------ CAPACITY  ---------------------------------------

// lay chieu dai thuc cua chuoi
int MyString::size() const
{
	if (string == NULL)
		return 0;
	int l = 0;
	while (string[l] != NULL)
	{
		l++;
	}
	return l;
}

int MyString::length() const
{
	return size();
}

// lay do dai toi da cua chuoi
int MyString::max_size() const
{
	return m_size;
}

// cap nhat kich thuoc chuoi
MyString MyString::resize(int num)
{
	m_size = num;
	if (num < 0 || num > m_size)
		throw "Sai thong so truyen vao resize";
	string = (char*)realloc(string, num * sizeof(char));
	string[num] = NULL;
	return *this;
}

MyString MyString::resize(int num, char s)
{
	if (num < m_size)
		throw "Sai thong so truyen vao resize";

	int a_size = m_size;
	char* a_string = (char*)malloc(a_size * sizeof(char));
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	m_size = num;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < a_size)
			string[i] = a_string[i];
		else
			string[i] = s;
	}
	string[m_size] = NULL;
	return *this;
}

// suc chua co the cua chuoi
int MyString::opacity()
{
	return length() + 2;
}

// xoa chuoi
void MyString::clear()
{
	m_size = 0;
	string = NULL;
}

// kiem tra chuoi rong
bool MyString::empty()
{
	if (string == NULL)
		return true;
	else
		return false;
}

//
int MyString::shrink_to_fit()
{
	return m_size;
}

// Nhap, xuat
void MyString::Input()
{
	char key;
	int value;
	while (1)
	{
		key = _getch();
		value = key;
		if (value == 13)
			break;
		cout << key;
		++m_size;
		string = (char*)realloc(string, m_size * sizeof(char));
		string[m_size - 1] = key;
	}
	string[m_size] = '\0';
	cout << endl;
}

void MyString::Output()
{
	if (string == NULL)
	{
		cout << "Chuoi rong" << endl;
		return;
	}
	for (int i = 0; i < m_size; ++i)
		cout << string[i];
	cout << endl;
}







//------------------------------------  ELEMENT ACCESS  -------------------------------------

// toan tu lay phan tu o vi tri i
char& MyString::operator[](int i)
{
	if (i < 0 || i > m_size)
		throw "Sai vi tri";
	if (i >= 0 && i < length())
		return string[i];
}

//  lay ki tu o i tri i
char MyString::at(int i)
{
	if (i < 0 || i > m_size)
		throw "Sai vi tri";
	return string[i];
}

// lay ky tu cuoi cung
char MyString::back()
{
	if (string == NULL)
		throw "string rong";
	return string[length() - 1];
}

// lay ky tu dau tien
char MyString::front()
{
	if (string == NULL)
		throw "string rong";
	return string[0];
}

// gan ki tu o i tri i
void MyString::GanKyTu(char s, int vt)
{
	if (vt < 0 || vt > m_size)
		throw "Sai vi tri";
	string[vt] = s;
}









// ------------------------------------------ MODIFIERS ------------------------------------

// toan tu cong chuoi
MyString& MyString::operator+=(const MyString& b)
{
	int a_size = m_size;
	char* a_string = (char*)malloc(a_size * sizeof(char));
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;


	m_size = a_size + b.m_size;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < a_size)
			string[i] = a_string[i];
		else
			string[i] = b.string[i - a_size];
	}
	string[m_size] = NULL;
	return *this;
}

MyString& MyString::operator+= (const char* s)
{
	int a_size = m_size;
	char* a_string = (char*)malloc(a_size * sizeof(char));
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;


	m_size = a_size + strlen(s);
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < a_size)
			string[i] = a_string[i];
		else
			string[i] = s[i - a_size];
	}
	string[m_size] = NULL;
	return *this;
}

MyString& MyString::operator+= (const char c)
{
	m_size++;
	string = (char*)realloc(string, m_size * sizeof(char));
	string[m_size - 1] = c;
	string[m_size] = NULL;
	return *this;
}

// append chuoi
MyString& MyString::append(const MyString& p)
{
	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	m_size = m_size + p.m_size;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < a_size)
			string[i] = a_string[i];
		else
			string[i] = p.string[i - a_size];
	}
	string[m_size] = NULL;
	return *this;
}

MyString& MyString::append(const MyString& p, int pos, int len)
{
	if (pos < 0 || pos > m_size || len < 0)
		throw "Sai thong so truyen vao append";
	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	m_size = m_size + len;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < a_size)
			string[i] = a_string[i];
		else
			string[i] = p.string[i - a_size + pos];
	}
	string[m_size] = NULL;
	return *this;
}

MyString& MyString::append(const char* s, int num)
{
	if (num < 0)
		throw "Sai thong so truyen vao append";
	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	m_size = m_size + num;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < a_size)
			string[i] = a_string[i];
		else
			string[i] = s[i - a_size];
	}
	string[m_size] = NULL;
	
	return *this;
}

MyString& MyString::append(int num, char s)
{
	if (num < 0)
		throw "Sai thong so truyen vao append";
	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	m_size = m_size + num;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < a_size)
			string[i] = a_string[i];
		else
			string[i] = s;
	}
	string[m_size] = NULL;
	return *this;
}

MyString& MyString::append(const char* s)
{
	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	int l = 0;
	while (s[l] != NULL)
	{
		l++;
	}

	m_size = m_size + l;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < a_size)
			string[i] = a_string[i];
		else
			string[i] = s[i - a_size];
	}
	string[m_size] = NULL;

	return *this;
}

// them ky tu vao cuoi
MyString& MyString::push_back(char s)
{
	m_size++;
	string = (char*)realloc(string, m_size * sizeof(char));
	string[m_size - 1] = s;
	string[m_size] = NULL;
	return *this;
}

// lay chuoi trong chuoi
MyString& MyString::assign(MyString& p)
{
	*this = p;
	return *this;
}

MyString& MyString::assign(MyString& p, int pos, int num)
{
	if (pos >= 0 && pos <= p.length())
	{
		m_size = num;
		string = (char*)realloc(string, m_size * sizeof(char));
		for (int i = 0; i < m_size; i++)
		{
			string[i] = p.string[i + pos];
		}
		string[m_size] = NULL;	
	}
	else 
		throw"Sai thong so truyen vao assign";

	return *this;
}

MyString& MyString::assign(MyString& p, int num)
{
	if (num > 0)
	{
		m_size = num;
		string = (char*)realloc(string, m_size * sizeof(char));
		for (int i = 0; i < num; i++)
		{
			string[i] = p.string[i];
		}
		string[m_size] = NULL;
	}
	else 
		throw"Sai thong so truyen vao assign";

	return *this;
}


MyString& MyString::assign(int num, char s)
{
	if (num > 0)
	{
		m_size = num;
		string = (char*)realloc(string, m_size * sizeof(char));
		for (int i = 0; i < m_size; i++)
			string[i] = s;
		string[m_size] = NULL;
	}
	else 
		throw"Sai thong so truyen vao assign";

	return *this;
}

MyString& MyString::assign(int x, int y)
{
	if (x < 0 || y < x)
		throw "Sai thong so truyen vao assign";

	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	if (x >= 0 && y >= x)
	{
		m_size = y - x  + 1;
		string = (char*)realloc(string, m_size * sizeof(char));
		for (int i = 0; i < m_size; i++)
		{
			string[i] = a_string[i + x];
		}
		string[m_size] = NULL;
	}

	return *this;
}


// chen ki tu vao vi tri cho truoc
MyString& MyString::insert(int pos, MyString& p)
{
	if (pos >= 0 && pos <= m_size)
	{
		int a_size = m_size;
		char* a_string = new char[a_size];
		for (int i = 0; i < a_size; i++)
		{
			a_string[i] = string[i];
		}
		a_string[a_size] = NULL;

		m_size = m_size + p.length();
		string = (char*)realloc(string, m_size * sizeof(char));
		for (int i = 0; i < m_size; i++)
		{
			if (i < pos)
				string[i] = a_string[i];
			else if (i >= pos && i < pos + p.length())
			{
				string[i] = p.string[i - pos];
			}
			else
			{
				string[i] = a_string[i - p.length()];
			}
		}
		string[m_size] = NULL;
	}
	else
		throw "Sai thong so truyen vao insert";

	return *this;
}

MyString& MyString::insert(int pos, MyString& p, int x, int y)
{
	if (pos >= 0 && pos <= m_size && x >= 0 && y >= x)
	{
		int a_size = m_size;
		char* a_string = new char[a_size];
		for (int i = 0; i < a_size; i++)
		{
			a_string[i] = string[i];
		}
		a_string[a_size] = NULL;

		m_size += y - x + 1;
		string = (char*)realloc(string, m_size * sizeof(char));
		for (int i = 0; i < m_size; i++)
		{
			if (i < pos)
				string[i] = a_string[i];
			else if (i >= pos && i < pos + (y - x + 1))
			{
				string[i] = p.string[i - pos + x];
			}
			else
			{
				string[i] = a_string[i - (y - x + 1)];
			}
		}
		string[m_size] = NULL;
	}
	else
		throw "Sai thong so truyen vao insert";

	return *this;
}

MyString& MyString::insert(int pos, MyString& p, int num)
{
	if (pos >= 0 && pos <= m_size && num >= 0)
	{
		int a_size = m_size;
		char* a_string = new char[a_size];
		for (int i = 0; i < a_size; i++)
		{
			a_string[i] = string[i];
		}
		a_string[a_size] = NULL;

		m_size = m_size + num;
		string = (char*)realloc(string, m_size * sizeof(char));
		for (int i = 0; i < m_size; i++)
		{
			if (i < pos)
				string[i] = a_string[i];
			else if (i >= pos && i < pos + num)
			{
				string[i] = p.string[i - pos];
			}
			else
			{
				string[i] = a_string[i - num];
			}
		}
		string[m_size] = NULL;
	}
	else
		throw "Sai thong so truyen vao insert";

	return *this;
	
}

MyString& MyString::insert(int pos, int num, char s)
{
	if (pos >= 0 && pos <= m_size && num >= 0)
	{
		int a_size = m_size;
		char* a_string = new char[a_size];
		for (int i = 0; i < a_size; i++)
		{
			a_string[i] = string[i];
		}
		a_string[a_size] = NULL;

		m_size = m_size + num;
		string = (char*)realloc(string, m_size * sizeof(char));
		for (int i = 0; i < m_size; i++)
		{
			if (i < pos)
				string[i] = a_string[i];
			else if (i >= pos && i < pos + num)
			{
				string[i] = s;
			}
			else
			{
				string[i] = a_string[i - num];
			}
		}
		string[m_size] = NULL;
	}
	else
		throw "Sai thong so truyen vao insert";

	return *this;
}

MyString& MyString::insert(int pos, char s)
{
	if (pos >= 0 && pos <= length())
	{
		m_size++;
		string = (char*)realloc(string, m_size * sizeof(char));
		for (int i = m_size - 1; i > pos; i--)
		{
			string[i] = string[i - 1];
		}
		string[pos] = s;
		string[m_size] = NULL;
	}
	else
		throw "Sai thong so truyen vao insert";

	return *this;
}


// xoa 
MyString& MyString::erase(int pos, int num)
{
	int a = m_size;
	if (pos >= 0 && pos < m_size)
	{
		m_size -= num;
		for (int i = pos; i < a - num; i++)
		{
			string[i] = string[i + num];
		}
		string = (char*)realloc(string, m_size * sizeof(char));
		string[m_size] = NULL;
	}
	else
		throw "Sai thong so truyen vao erase";
	return *this;
}

MyString& MyString::erase(int pos)
{
	int a = m_size;
	if (pos >= 0 && pos <= m_size)
	{
		m_size--;
		for (int i = pos; i < a - 1; i++)
		{
			string[i] = string[i + 1];
		}
		string = (char*)realloc(string, m_size * sizeof(char));
		string[m_size] = NULL;	
	}
	else
		throw "Sai thong so truyen vao erase";
	return *this;
}

MyString& MyString::_erase(int x, int y)
{
	if (x >= 0 && x <= y)
	{
		m_size = m_size - (y - x + 1);
		for (int i = x; i < m_size; i++)
		{
			string[i] = string[i + (y - x + 1)];
		}
		string = (char*)realloc(string, m_size * sizeof(char));
		string[m_size] = NULL;	
	}
	else
		throw "Sai thong so truyen vao _erase";
	return *this;
}


// ham replace
MyString& MyString::replace(int pos, int len, const MyString& p)
{
	if (pos < 0 || pos > m_size || len < 0)
		throw "Sai thong so truyen vao replace";
	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	m_size = m_size - len + p.length() + 1;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < pos)
			string[i] = a_string[i];
		else if (i >= pos && i < pos + p.length())
			string[i] = p.string[i - pos];
		else
			string[i] = a_string[i - p.length() + len];
	}
	string[m_size] = NULL;

	return *this;
}

MyString& MyString::replace(int pos, int len, const MyString& p, int p_pos, int p_len)
{
	if (pos < 0 || pos > m_size || len < 0 || p_pos < 0 || p_pos > p.m_size || p_len < 0)
		throw "Sai thong so truyen vao replace";
	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	m_size = m_size - len + p_len + 1;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < pos)
			string[i] = a_string[i];
		else if (i >= pos && i < pos + p_len)
			string[i] = p.string[i - pos + p_pos];
		else
			string[i] = a_string[i - p_len + len];
	}
	string[m_size] = NULL;

	return *this;
}

MyString& MyString::replace(int pos, int len, const char* s)
{
	if (pos < 0 || pos > m_size || len < 0)
		throw "Sai thong so truyen vao replace";

	int l = 0;
	while (s[l] != NULL)
	{
		l++;
	}

	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	m_size = m_size - len + l + 1;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < pos)
			string[i] = a_string[i];
		else if (i >= pos && i < pos + l)
			string[i] = s[i - pos];
		else
			string[i] = a_string[i - l + len];
	}
	string[m_size] = NULL;

	return *this;
}

MyString& MyString::replace(int pos, int len, const char* s, int n)
{
	if (pos < 0 || pos > m_size || len < 0 || n < 0)
		throw "Sai thong so truyen vao replace";

	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	m_size = m_size - len + n + 1;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < pos)
			string[i] = a_string[i];
		else if (i >= pos && i < pos + n)
			string[i] = s[i - pos];
		else
			string[i] = a_string[i - n + len];
	}
	string[m_size] = NULL;

	return *this;
}

MyString& MyString::replace(int pos, int len, int n, char c)
{
	if (pos < 0 || pos > m_size || len < 0 || n < 0)
		throw "Sai thong so truyen vao replace";

	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	m_size = m_size - len + n + 1;
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; i++)
	{
		if (i < pos)
			string[i] = a_string[i];
		else if (i >= pos && i < pos + n)
			string[i] = c;
		else
			string[i] = a_string[i - n + len];
	}
	string[m_size] = NULL;
	
	return *this;
}

// hoan doi
MyString& MyString::swap(MyString& p)
{
	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;


	int t = m_size;
	m_size = p.m_size;
	p.m_size = t;
	
	string = (char*)realloc(string, m_size * sizeof(char));
	for (int i = 0; i < m_size; ++i)
	{
		string[i] = p.string[i];
	}

	p.string = (char*)realloc(p.string, p.m_size * sizeof(char));
	for (int i = 0; i < p.m_size; i++)
	{
		p.string[i] = a_string[i];
	}

	string[m_size] = NULL;
	p.string[p.m_size] = NULL;

	return *this;
}

// xoa ky tu cuoi cung
MyString& MyString::pop_back()
{
	m_size--;
	string = (char*)realloc(string, m_size * sizeof(char));
	string[m_size] = NULL;
	return *this;
}











// -------------------------------------------- STRING OPERATIONS -----------------------------------


// tra ve con tro cua mang
const char* MyString::c_str() const
{
	return const_cast<const char*>(string);
}

const char* MyString::data() const
{
	char* string = &this->string[0];
	return string;
}

// copy
int MyString::copy(char*& p, int len, int pos) const
{
	if (pos < 0 || pos > m_size || len < 0)
		throw "Sai thong so truyen vao copy";

	if (pos + len > m_size)
		len = m_size - pos;
	p = new char[len];
	for (int i = pos; i < pos + len; i++)
		p[i - pos] = string[i];
	
	return len;
}

// tim kiem
int MyString::find(const MyString& p)
{
	for (int i = 0; i < m_size; i++)
	{
		if (string[i] == p.string[0])
		{
			int temp = 0;
			for (int j = 1; j < p.m_size; j++)
			{
				if (string[i + j] != p.string[j])
					temp++;
			}
			if (temp == 0)
				return i;
		}
	}
	return -1;
}

int MyString::find(char* s)
{
	for (int i = 0; i < m_size; i++)
	{
		if (string[i] == s[0])
		{
			int temp = 0;
			for (int j = 1; j < strlen(s); j++)
			{
				if (string[i + j] != s[j])
					temp++;
			}
			if (temp == 0)
				return i;
		}
	}
	return -1;
}

int MyString::find(char* s, int pos, int len)
{
	if (pos < 0 || len < 0 || pos > len)
		throw "Sai thong so truyen vao rfind";

	for (int i = 0; i < m_size; i++)
	{
		if (string[i] == s[pos])
		{
			int temp = 0;
			for (int j = pos + 1; j < len; j++)
			{
				if (string[i + j - pos] != s[j])
					temp++;
			}
			if (temp == 0)
				return i;
		}
	}
	return -1;
}

int MyString::find(char c)
{
	for (int i = 0; i < m_size; i++)
	{
		if (string[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int MyString::rfind(const MyString& p)
{
	for (int i = m_size - 1; i >= 0; i--)
	{
		if (string[i] == p.string[p.m_size - 1])
		{
			int i_t = i;
			int temp = 0;
			for (int j = p.m_size - 2; j >= 0; j--)
			{
				if (string[--i_t] != p.string[j])
					temp++;
			}
			if (temp == 0)
				return i - p.m_size + 1;
		}
	}
	return -1;
}

int MyString::rfind(char* s)
{
	for (int i = m_size - 1; i >= 0; i--)
	{
		if (string[i] == s[strlen(s) - 1])
		{
			int i_t = i;
			int temp = 0;
			for (int j = strlen(s) - 2; j >= 0; j--)
			{
				if (string[--i_t] != s[j])
					temp++;
			}
			if (temp == 0)
				return i - strlen(s) + 1;
		}
	}
	return -1;
}

int MyString::rfind(char* s, int pos, int len)
{
	if (pos < 0 || len < 0 || pos > len)
		throw "Sai thong so truyen vao rfind";

	int last = pos + len - 1; // vi tri cuoi cua chuoi con can tim
	for (int i = m_size - 1; i >= 0; i--)
	{
		if (string[i] == s[last])
		{
			int i_t = i;
			int temp = 0;
			for (int j = last - 1; j >= pos; j--)
			{
				if (string[--i_t] != s[j])
					temp++;
			}
			if (temp == 0)
				return i - len + 1;
		}
	}
	return -1;
}

int MyString::rfind(char c)
{
	for (int i = m_size - 1; i >= 0; i--)
	{
		if (string[i] == c)
		{
			return i;
		}
	}
	return -1;
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	if (pos < 0 || pos >= m_size || str.m_size > m_size)
		return MyString::npos;

	for (size_t i = pos; i < m_size; i++)
	{
		for (size_t j = 0; j < str.m_size; j++)
		{
			if (string[i] == str.string[j])
				return i;
		}
	}
	return npos;
}

size_t MyString::find_first_of(const char* s, size_t pos) const
{
	int s_len = strlen(s);
	if (pos < 0 || pos >= m_size || s_len > m_size)
		return MyString::npos;

	for (size_t i = pos; i < m_size; i++)
	{
		for (size_t j = 0; j < s_len; j++)
		{
			if (string[i] == s[j])
				return i;
		}
	}
	return npos;
}

size_t MyString::find_first_of(char c, size_t pos) const
{
	if (pos < 0 || pos >= m_size)
		return MyString::npos;
	for (size_t i = pos; i < m_size; i++)
		if (string[i] == c)
			return i;
	return npos;
}

size_t MyString::find_last_of(const MyString& str, size_t pos) const
{
	if (pos < 0 || pos >= m_size || str.m_size > m_size)
		return MyString::npos;

	for (int i = m_size; i >= 0; i--)
	{
		for (int j = 0; j < str.m_size; j++)
		{
			if (string[i] == str.string[j])
				return i;
		}
	}
	return npos;
}

size_t MyString::find_last_of(const char* s, size_t pos) const
{
	int s_len = strlen(s);
	if (pos < 0 || pos >= m_size)
		return MyString::npos;
	for (int i = m_size - 1; i >= 0; i--)
	{
		for (int j = 0; j < s_len; j++)
		{
			if (string[i] == s[j])
				return i;
		}
	}
	return npos;
}

size_t MyString::find_last_of(char c, size_t pos) const
{
	if (pos < 0 || pos >= m_size)
		return MyString::npos;
	for (int i = m_size - 1; i >= 0; i--)
		if (string[i] == c)
			return i;
	return npos;
}

size_t MyString::find_first_not_of(const MyString& str, size_t pos) const
{
	for (size_t i = pos; i < m_size; i++)
	{
		size_t flag = 1;
		for (size_t j = 0; j < str.m_size; j++)
		{
			if (string[i] == str.string[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) 
			return i;
	}
	return npos;
}

size_t MyString::find_first_not_of(const char* s, size_t pos) const
{
	size_t s_len = strlen(s);
	for (size_t i = pos; i < m_size; i++)
	{
		size_t flag = 1;
		for (size_t j = 0; j < s_len; j++)
		{
			if (string[i] == s[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) return i;
	}
	return npos;
}

size_t MyString::find_first_not_of(char c, size_t pos) const
{
	for (size_t i = pos; i < m_size; i++)
		if (string[i] != c)
			return i;
	return npos;
}

size_t MyString::find_last_not_of(const MyString& str, size_t pos) const
{
	for (int i = m_size - 1; i >= 0; i--)
	{
		int flag = 1;
		for (int j = 0; j < str.m_size; j++)
		{
			if (string[i] == str.string[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) 
			return i;
	}
	return npos;
}

size_t MyString::find_last_not_of(const char* s, size_t pos) const
{
	int s_len = strlen(s);
	for (int i = m_size - 1; i >= 0; i--)
	{
		int flag = 1;
		for (int j = 0; j < s_len; j++)
		{
			if (string[i] == s[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) 
			return i;
	}
	return npos;
}

size_t MyString::find_last_not_of(char c, size_t pos) const
{
	for (int i = m_size - 1; i >= 0; i--)
		if (string[i] != c)
			return i;
	return npos;
}

MyString MyString::substr(int pos, int len)
{
	if (pos >= 0 && pos < m_size)
	{
		MyString result;
		if (pos + len > m_size)
			len = m_size - pos;
		result.string = new char[len];
		result.m_size = len;
		for (int i = pos; i < pos + len; ++i)
			result.string[i] = string[i];
		result.string[result.m_size] = NULL;
		return result;
	}
	else
		throw "Sai thong so truyen vao substr";
}

char MyString::compare(const MyString& p)
{
	int new_size;
	if (m_size > p.m_size) 
		new_size = p.m_size;
	else 
		new_size = m_size;

	for (int i = 0; i < m_size; i++)
	{
		if (string[i] > p.string[i]) 
			return 1;
		if (string[i] < p.string[i])
			return -1;
	}
	if (m_size > p.m_size) 
		return 1;
	else if (m_size < p.m_size) 
		return -1;
	else 
		return 0;
}

MyString MyString::ChuanHoa()
{
	while (string[0] == ' ') 
		erase(0);
	while (string[m_size - 1] == ' ' && m_size >= 0) 
		erase(m_size - 1);
	for (int i = 0; i < m_size - 1; i++)
	{
		while (string[i] == ' ' && string[i + 1] == ' ')
			erase(i);
	}
	return *this;
}

MyString MyString::DaoChuoi()
{
	for (int i = 0; i < m_size / 2; ++i)
	{
		char t = string[i];
		string[i] = string[m_size - i - 1];
		string[m_size - i - 1] = t;
	}
	return *this;
}







// --------------------------------------- NON-MEMBER FUNCTION OVERLOADS----------------------------

bool MyString::operator>(const MyString& b)
{
	int new_size;

	if (m_size > b.m_size) 
		new_size = b.m_size;
	else 
		new_size = m_size;

	for (int i = 0; i < new_size; i++)
	{
		if (string[i] > b.string[i]) 
			return true;
		if (string[i] < b.string[i])
			return false;
	}

	if (m_size > b.m_size) 
		return true;
	return false;
}

bool MyString::operator>=(const MyString& b)
{
	int new_size;

	if (m_size > b.m_size)
		new_size = b.m_size;
	else
		new_size = m_size;

	for (int i = 0; i < new_size; i++)
	{
		if (string[i] >= b.string[i])
			return true;
		if (string[i] < b.string[i])
			return false;
	}

	if (m_size >= b.m_size)
		return true;
	return false;
}

bool MyString::operator<(const MyString& b)
{
	int new_size;

	if (m_size > b.m_size)
		new_size = b.m_size;
	else
		new_size = m_size;

	for (int i = 0; i < new_size; i++)
	{
		if (string[i] < b.string[i])
			return true;
		if (string[i] > b.string[i])
			return false;
	}

	if (m_size < b.m_size)
		return true;
	return false;
}

bool MyString::operator<=(const MyString& b)
{
	int new_size;

	if (m_size > b.m_size)
		new_size = b.m_size;
	else
		new_size = m_size;

	for (int i = 0; i < new_size; i++)
	{
		if (string[i] < b.string[i])
			return true;
		if (string[i] > b.string[i])
			return false;
	}

	if (m_size <= b.m_size)
		return true;
	return false;
}

bool MyString::operator==(const MyString& b)
{
	if (m_size != b.m_size)
		return false;

	for (int i = 0; i < m_size; i++)
	{
		if (string[i] != b.string[i])
			return false;
	}
	return true;
}

bool MyString::operator!=(const MyString& b)
{
	if (m_size != b.m_size)
		return true;

	for (int i = 0; i < m_size; i++)
	{
		if (string[i] == b.string[i])
			return false;
	}
	return true;
}

bool MyString::operator>(const char* s)
{
	int new_size;

	if (m_size > strlen(s))
		new_size = strlen(s);
	else
		new_size = m_size;

	for (int i = 0; i < new_size; i++)
	{
		if (string[i] > s[i])
			return true;
		if (string[i] < s[i])
			return false;
	}

	if (m_size > strlen(s))
		return true;
	return false;
}

bool MyString::operator>=(const char* s)
{
	int new_size;

	if (m_size >= strlen(s))
		new_size = strlen(s);
	else
		new_size = m_size;

	for (int i = 0; i < new_size; i++)
	{
		if (string[i] >= s[i])
			return true;
		if (string[i] < s[i])
			return false;
	}

	if (m_size >= strlen(s))
		return true;
	return false;
}

bool MyString::operator<(const char* s)
{
	int new_size;

	if (m_size > strlen(s))
		new_size = strlen(s);
	else
		new_size = m_size;

	for (int i = 0; i < new_size; i++)
	{
		if (string[i] < s[i])
			return true;
		if (string[i] > s[i])
			return false;
	}

	if (m_size < strlen(s))
		return true;
	return false;
}

bool MyString::operator<=(const char* s)
{
	int new_size;

	if (m_size >= strlen(s))
		new_size = strlen(s);
	else
		new_size = m_size;

	for (int i = 0; i < new_size; i++)
	{
		if (string[i] <= s[i])
			return true;
		if (string[i] > s[i])
			return false;
	}

	if (m_size <= strlen(s))
		return true;
	return false;
}

bool MyString::operator==(const char* s)
{
	if (m_size != strlen(s))
		return false;

	for (int i = 0; i < m_size; i++)
	{
		if (string[i] != s[i])
			return false;
	}
	return true;
}

bool MyString::operator!=(const char* s)
{
	if (m_size != strlen(s))
		return true;

	for (int i = 0; i < m_size; i++)
	{
		if (string[i] == s[i])
			return false;
	}
	return true;
}

// ham hoa doi vi tri
void swap(MyString& a, MyString& b)
{
	// bien tam
	MyString t;
	t.m_size = a.m_size;
	t.string = (char*)realloc(t.string, t.m_size * sizeof(char));
	for (int i = 0; i < t.m_size; i++)
	{
		t.string[i] = a.string[i];
	}
	t.string[t.m_size] = NULL;
	// gan a = b
	a.m_size = b.m_size;
	a.string = (char*)realloc(a.string, a.m_size * sizeof(char));
	for (int i = 0; i < a.m_size; i++)
	{
		a.string[i] = b.string[i];
	}
	a.string[a.m_size] = NULL;
	// gan b = t
	b.m_size = t.m_size;
	b.string = (char*)realloc(b.string, b.m_size * sizeof(char));
	for (int i = 0; i < b.m_size; i++)
	{
		b.string[i] = t.string[i];
	}
	b.string[b.m_size] = NULL;
}

// toan tu cong
MyString MyString::operator+(const MyString& b)
{
	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	MyString result;
	result.m_size = a_size + b.m_size;
	result.string = (char*)realloc(result.string, result.m_size * sizeof(char));
	for (int i = 0; i < result.m_size; i++)
	{
		if (i < a_size)
			result.string[i] = a_string[i];
		else
			result.string[i] = b.string[i - a_size];
	}
	result.string[result.m_size] = NULL;

	return result;
}

MyString MyString::operator+(const char* b)
{
	int a_size = m_size;
	char* a_string = new char[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a_string[i] = string[i];
	}
	a_string[a_size] = NULL;

	MyString result;
	result.m_size = a_size + strlen(b);
	result.string = (char*)realloc(result.string, result.m_size * sizeof(char));
	for (int i = 0; i < result.m_size; i++)
	{
		if (i < a_size)
			result.string[i] = a_string[i];
		else
			result.string[i] = b[i - a_size];
	}
	result.string[result.m_size] = NULL;

	return result;
}

MyString MyString::operator+(const char b)
{
	MyString result;
	result.m_size = m_size + 1;
	result.string = (char*)realloc(result.string, result.m_size * sizeof(char));
	for (int i = 0; i < result.m_size; i++)
	{
		if (i < m_size - 2)
			result.string[i] = string[i];
		else
			result.string[i] = b;
	}
	result.string[result.m_size] = NULL;

	return result;
}

// toan tu xuat
ostream& operator<<(ostream& out, MyString& p)
{
	for (int i = 0; i < p.length(); i++)
		out << p.string[i];
	return out;
}

// toan tu nhap
istream& operator>>(istream& in, MyString& p)
{
	char key;
	int val;
	p.m_size = 0;
	p.string = new char[p.m_size];
	while (1)
	{
		key = _getch();
		val = key;
		if (val == 13)
			break;
		cout << key;
		p.m_size++;
		p.string = (char*)realloc(p.string, p.m_size * sizeof(char));
		p.string[p.m_size - 1] = key;
	}
	p.string[p.m_size] = NULL;
	cout << endl;
	return in;
}

void getline(MyString p)
{
	char key;
	int val;
	p.m_size = 0;
	p.string = new char[p.m_size];
	while (1)
	{
		key = _getch();
		val = key;
		if (val == 13)
			break;
		cout << key;
		p.m_size++;
		p.string = (char*)realloc(p.string, p.m_size * sizeof(char));
		p.string[p.m_size - 1] = key;
	}
	p.string[p.m_size] = NULL;
	cout << endl;
}

istream & getline(istream & is, MyString & str)
{
	char *c = new char[100];
	is.get(c, 100);
	int i = 0;
	while (c[i] != '\n' && i < strlen(c))
	{
		str += c[i];
		++i;
	}
	str.string[str.m_size] = NULL;
	delete[]c;
	return is;
}

istream & getline(istream & is, MyString & str, char delim)
{
	char *c = new char[100];
	is.get(c, 100, delim);
	int i = 0;
	while (c[i] != delim && i < strlen(c))
	{
		str += c[i];
		++i;
	}
	str.string[str.m_size] = NULL;
	delete[]c;
	return is;
}