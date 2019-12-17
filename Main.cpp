#include <iostream>
using namespace std;
#include "MyString.h"

int main()
{
	try
	{
		cout << "========================  TEST LOP MyStirng DA TAO  =========================\n" << endl;
		
		MyString A = "Hello world";
		MyString B = "in C language";
		cout << "  Chuoi A: " << A << endl;
		cout << "  Chuoi B: " << B << endl;
		cout << "     - Max_size(A) = " << A.max_size() << endl;
		cout << "     - length(A) = " << A.length() << endl;
		cout << "     - size(A) = " << A.size() << endl;
		cout << "-------------------------------------------------------------------------------\n" << endl;
		

		MyString _str("Test string");
		cout << "  Chuoi str = \"" << _str << "\"" << endl;
		cout << "\n     -> Xuat chuoi str (su dung iterator): ";
		for (MyString::iterator it = _str.begin(); it != _str.end(); ++it)
			std::cout << *it;
		cout << "\n     -> Xuat chuoi str (su dung reverse_iterator): ";
		for (MyString::reverse_iterator it = _str.rbegin(); it != _str.rend(); --it)
			cout << *it;
		cout << "-------------------------------------------------------------------------------\n" << endl;




		MyString C;
		cout << "  Nhap chuoi C (kieu toan tu >>): ";
		cin >> C;
		cout << "     Chuoi C: " << C << endl;
		MyString D;
		cout << "  Nhap chuoi D (kieu getline()): ";
		getline(cin, D);
		cout << "     Chuoi D: " << D << endl;
		MyString E;
		E = A;
		cout << "     -> E = A = " << E << endl;
		cout << "-------------------------------------------------------------------------------\n" << endl;




		MyString A1 = "The gioi quan ";
		MyString A2 = "tu duy vat bien chung";
		cout << "  A1 = \"" << A1 << "\"" << endl;
		cout << "  A2 = \"" << A2 << "\"" << endl;
		A1.append(A2, 3, 8);
		cout << "     - A1.append(A2, 3, 8)  =  \"" << A1 << "\"" << endl;
		A1.append(A2);
		cout << "     - A1.append(A2)        =  \"" << A1 << "\"" << endl;
		A1.resize(8);
		cout << "     - A1.resize(8)         =  \"" <<  A1 << "\"" << endl;
		A2.resize(25, '*');
		cout << "     - A2.resize(25, '*')   =  \"" << A2 << "\"" << endl;
		A2.clear();
		cout << "     - A2.clear() -> A2.empty()  = " << A2.empty() << endl;
		cout << "-------------------------------------------------------------------------------\n" << endl;




		MyString B1 = "0123456789";
		cout << "  B1 = \"" << B1 << "\"" << endl;
		cout << "     - B1.at(2)   =  " << B1.at(2) << endl;
		cout << "     - B1.back()  =  " << B1.back() << "   B1.begin() = " << B1.front() << endl;
		cout << "     - B1[3] = " << B1[3] << endl;
		cout << "-------------------------------------------------------------------------------\n" << endl;



		MyString C1 = "Xuan ";
		MyString C2 = "da ve roi";
		MyString C3 = "2020 ";
		cout << "  C1 = \"" << C1 << "\"" << endl;
		cout << "  C2 = \"" << C2 << "\"" << endl;
		cout << "  C3 = \"" << C3 << "\"" << endl;
		C1 += C2;
		cout << "     - C1 += C2 -> \"" << C1 << "\"" << endl;
		C1.push_back('!');
		cout << "     - C1.push_back('!') =  \"" << C1 << "\"" << endl;
		C1.pop_back();
		cout << "     - C1.pop_back()     =  \"" << C1 << "\"" << endl;
		C1.insert(5, C3);
		cout << "     - C1.insert(5, C3)  =  \"" << C1 << "\"" << endl;
		cout << "-------------------------------------------------------------------------------\n" << endl;


		
		MyString D1 = "Truong Khoa hoc Tu nhien";
		cout << "  D1 = \"" << D1 << "\"" << endl;
		MyString D2 = "Dai hoc Cao hoc";
		cout << "  D2 = \"" << D2 << "\"" << endl;
		D1.insert(7, D2, 0, 7);
		cout << "     - D1.insert(7, D2, 0, 7) = \"" << D1 << "\"" << endl << endl;
		D1.erase(0,7);
		cout << "     - D1.erase(0,7) =  \"" << D1 << "\"" << endl;
		cout << "-------------------------------------------------------------------------------\n" << endl;






		MyString E1 = "Xuan ve";
		MyString E2 = "Tet den";
		cout << "  E1 = \"" << E1 << "\"" << endl;
		cout << "  E2 = \"" << E2 << "\"" << endl;
		E1.swap(E2);
		cout << "     - E1.swap(E2) " << endl;
		cout << "       E1 = \"" << E1 << "\"" << endl;
		cout << "       E2 = \"" << E2 << "\"" << endl;
		cout << "-------------------------------------------------------------------------------\n" << endl;




		char *s;
		MyString str0("Test string...");
		cout << "  str0 = \"" << str0 << "\"" << endl;
		int length = str0.copy(s, 6, 5);
		cout << "     -> length = str.copy(s, 6, 5) = " << length << endl;
		s[length] = '\0';
		cout << "     -> s = \"" << s << "\"" << endl;
		cout << "-------------------------------------------------------------------------------\n" << endl;

		


		MyString F1(" Dau    lia ngo y con vuon to    long   ");
		cout << "  F1 = \"" << F1 << "\"" << endl;
		MyString F2("ngo y");
		cout << "  F2 = \"" << F2 << "\"" << endl;
		cout << "     -> F1.find(F2) = " << F1.find(F2) << endl;
		F2.DaoChuoi();
		cout << "     -> Dao chuoi F2 = \"" << F2 << "\"" << endl;
		F1.ChuanHoa();
		cout << "     -> Chuan hoa F1 = \"" << F1 << "\"" << endl;
		cout << "-------------------------------------------------------------------------------\n" << endl;



		MyString str1("Tet tet tet tet den roi, tet den trong tim moi nguoi");
		cout << "  str1 = \"" << str1 << "\"" << endl;
		MyString s1("tet den");
		cout << "  s1 = \"" << s1 << "\"" << endl;
		cout << "     -> str1.rfind(s1) = " << str1.rfind(s1) << endl;
		cout << "-------------------------------------------------------------------------------\n" << endl;
	

		MyString G1("khoa cong nghe - thong tin - dai hoc khoa hoc tu nhien");
		MyString G2("tlyn");
		MyString G3("abcdefghijklmnopqrstuvwxyz ");
		cout << "  Chuoi G1 = \"" << G1 << "\"" << endl;
		cout << "  Chuoi G2 = \"" << G2 << "\"" << endl;
		cout << "  Chuoi G3 = \"" << G3 << "\"" << endl;
		int found2 = G1.find_first_not_of(G3);
		if (found2 != std::string::npos)
		{
			cout << "     -> Ki tu khac dau tien la \"" << G1[found2] << "\"";
			cout << " o vi tri " << found2 << '\n';
		}

		int found1 = G1.find_first_of(G2);
		while (found1 != std::string::npos)
		{
			G1[found1] = '?';
			found1 = G1.find_first_of(G2, found1 + 1);
		}
		cout << "     -> Chuoi ket qua: " << G1 << endl;


		cout << "-------------------------------------------------------------------------------\n" << endl;

}
	catch (const char * s)
	{
		cout << s;
	}

	system("pause");
	return 0;
}