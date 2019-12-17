#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class MyString
{
private:
	int m_size;	  // so phan tu toi da cua mang ki tu
	char* string;  // mang chua cac ki tu
	static const int npos = -1;




public:  // ------------------------------------ MEMBER FUNCTIONS ------------------------------------
	
	// Ham tao khong doi so
	MyString();

	// ham tao sao chep
	MyString(const MyString& other);
	MyString(const MyString& other, int pos, int len);

	// ham tao co doi so
	MyString(const char* a);
	MyString(const char* a, int n);
	MyString(int m, char a);

	// Ham huy
	virtual ~MyString();

	// toan tu gan bang
	MyString& operator=(const MyString& p);
	MyString& operator=(const char* s);
	MyString& operator=(const char c);




	// ---------------------------------------- ITERATORS ---------------------------------------

	class iterator
	{
	public:
		typedef char value_type;
		typedef char& reference;
		typedef forward_iterator_tag iterator_category;
		typedef int difference_type;
		iterator(char* ptr) : pointer(ptr) { }
		iterator operator++(int) { iterator i = *this; pointer++; return i; }
		iterator operator++() { pointer++; return *this; }
		reference operator*() { return *pointer; }
		char* operator->() { return pointer; }
		bool operator==(const iterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const iterator& rhs) { return pointer != rhs.pointer; }
	private:
		char* pointer;
	};
	class const_iterator
	{
	public:
		typedef char value_type;
		typedef char& reference;
		typedef int difference_type;
		typedef forward_iterator_tag iterator_category;
		const_iterator(char* ptr) : pointer(ptr) { }
		const_iterator operator++(int) { const_iterator i = *this; pointer++; return i; }
		const_iterator operator++() { pointer++; return *this; }
		const reference operator*() { return *pointer; }
		const char* operator->() { return pointer; }
		bool operator==(const const_iterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const const_iterator& rhs) { return pointer != rhs.pointer; }
	private:
		char* pointer;
	};
	class reverse_iterator
	{
	public:
		typedef char value_type;
		typedef char& reference;
		typedef random_access_iterator_tag iterator_category;
		typedef int difference_type;
		reverse_iterator(char* ptr) : pointer(ptr) { }
		reverse_iterator operator--(int) { reverse_iterator i = *this; pointer--; return i; }
		reverse_iterator operator--() { pointer--; return *this; }
		reference operator*() { return *pointer; }
		char* operator->() { return pointer; }
		bool operator==(const reverse_iterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const reverse_iterator& rhs) { return pointer != rhs.pointer; }
	private:
		char* pointer;
	};
	class const_reverse_iterator
	{
	public:
		typedef char value_type;
		typedef char& reference;
		typedef random_access_iterator_tag iterator_category;
		typedef int difference_type;
		const_reverse_iterator(char* ptr) : pointer(ptr) { }
		const_reverse_iterator operator--(int) { const_reverse_iterator i = *this; pointer--; return i; }
		const_reverse_iterator operator--() { pointer--; return *this; }
		reference operator*() { return *pointer; }
		char* operator->() { return pointer; }
		bool operator==(const const_reverse_iterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const const_reverse_iterator& rhs) { return pointer != rhs.pointer; }
	private:
		char* pointer;
	};


	iterator begin() { return iterator(string); }
	iterator end() { return iterator(string + m_size); }
	reverse_iterator rbegin() { return reverse_iterator(string + m_size - 1); };
	reverse_iterator rend() { return reverse_iterator(string - 1); }
	const_iterator cbegin() const { return const_iterator(string); }
	const_iterator cend() const { return const_iterator(string + m_size); }
	const_iterator crbegin() const { return const_iterator(string + m_size - 1); }
	const_iterator crend() const { return const_iterator(string - 1); }







public:           // ---------------------------------CAPACITY-----------------------------------
	// Lay do dai chuoi
	int size() const;
	int length() const;

	// lay do dai toi da cua chuoi
	int max_size() const;

	// cap nhat kich thuoc chuoi
	MyString resize(int num);
	MyString resize(int num, char s);

	// suc chua co the cua chuoi
	int opacity();

	// xoa chuoi
	void clear();

	// kiem tra chuoi rong
	bool empty();

	int shrink_to_fit();
	
	// Nhap, xuat
	void Input();
	void Output();






public:    	//--------------------------------ELEMENT ACCESS--------------------------------

	// toan tu lay phan tu o vi tri i
	char& operator[](int i);

	// Lay ky tu trong chuoi
	char at(int vt);

	// lay ky tu cuoi cung
	char back();

	// lay ky tu dau tien
	char front();

	// gan ky tu vao chuoi
	void GanKyTu(char c, int vt);






public:  // ------------------------------------------ MODIFIERS ------------------------------------
	// Toan tu cong bang
	MyString& operator+=(const MyString& b);
	MyString& operator+= (const char* s);
	MyString& operator+= (const char c);
	
	// append chuoi
	MyString& append(const MyString&);
	MyString& append(const MyString&, int, int);
	MyString& append(const char*, int);	
	MyString& append(int, const char);
	MyString& append(const char* s);	

	// them ky tu vao cuoi
	MyString& push_back(char s);

	// lay chuoi trong chuoi
	MyString& assign(MyString&);
	MyString& assign(MyString&, int, int);
	MyString& assign(MyString&, int);
	MyString& assign(int, char);
	MyString& assign(int, int);

	// chen ki tu vao ci tri cho truoc
	MyString& insert(int pos, MyString& p);
	MyString& insert(int pos, MyString& p, int x, int y);
	MyString& insert(int pos, MyString& p, int num);
	MyString& insert(int pos, int num, char s);
	MyString& insert(int pos, char s);

	// xoa 
	MyString& erase(int pos, int num);
	MyString& erase(int pos);
	MyString& _erase(int x, int y);

	// thay doi chuoi
	MyString& replace(int pos, int len, const MyString& p);
	MyString& replace(int pos, int len, const MyString& p, int p_pos, int p_len);
	MyString& replace(int pos, int len, const char* s);
	MyString& replace(int pos, int len, const char* s, int n);
	MyString& replace(int pos, int len, int n, char c);

	// hoan doi
	MyString& swap(MyString& p);

	// xoa ky tu cuoi cung
	MyString& pop_back();






public:  		// ---------------------------- STRING OPERATIONS -----------------------------------
	
	// tra ve con tro cua mang
	const char* c_str() const;
	const char* data() const;

	// copy
	int copy(char*& p, int len, int pos) const;

	// tim kiem
	int find(const MyString& p);
	int find(char* s);
	int find(char* s, int pos, int len);
	int find(char c);

	int rfind(const MyString& p);
	int rfind(char* s);
	int rfind(char* s, int pos, int len);
	int rfind(char c);
	
	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(char c, size_t pos = 0) const;

	size_t find_last_of(const MyString& str, size_t pos) const;
	size_t find_last_of(const char* s, size_t pos) const;
	size_t find_last_of(char c, size_t pos ) const;

	size_t find_first_not_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;

	size_t find_last_not_of(const MyString& str, size_t pos) const;
	size_t find_last_not_of(const char* s, size_t pos) const;
	size_t find_last_not_of(char c, size_t pos) const;

	MyString substr(int pos, int len);
	
	char compare(const MyString& p);

	
	// Toan tu dao chuoi
	MyString DaoChuoi();

	// Toan tu chuan hoa chuoi
	MyString ChuanHoa();








public:  // --------------------------------------- NON-MEMBER FUNCTION OVERLOADS----------------------------
	// So sanh cac chuoi >, >=, <, <=, ==, !=
	bool operator>(const MyString& p);
	bool operator>=(const MyString& p);
	bool operator<(const MyString& p);
	bool operator<=(const MyString& p);
	bool operator==(const MyString& p);
	bool operator!=(const MyString& p);

	bool operator>(const char* s);
	bool operator>=(const char* s);
	bool operator<(const char* s);
	bool operator<=(const char* s);
	bool operator==(const char* s);
	bool operator!=(const char* s);

public:

	// ham hoa doi vi tri
	friend void swap(MyString& a, MyString& b);


	// toan tu cong
	MyString operator+(const MyString& b);
	MyString operator+(const char* b);
	MyString operator+(const char b);

	// Toan tu nhap xuat
	friend istream& operator>>(istream& in, MyString& p);
	friend ostream& operator<<(ostream& out, MyString& p);


	friend void getline(MyString p);
	friend istream& getline(istream& is, MyString& str);
	friend istream& getline(istream& is, MyString& str, char delim);

	friend int strlen(char* s)
	{
		int l = 0;
		while (s[l] != NULL)
		{
			l++;
		}
		return l;
	}

};

