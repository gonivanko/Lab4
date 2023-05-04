#include "Date.h"

/*7. ��������� ���� "����" ��� ������ �� ������ � ����� ����.
������� ����� � �����, ����� �� ��.
���������� ��� ����� ������� ������������, �������, ����� ���������� ���� ����, �� ������� �������� ���.
������������� ��������� : "+=" ��� ��������� ���� �� ������� ������� ����, "-" - ��� ����������� ��������� �� ����� ������.
�������� ��� ��'����-���� (D1, D2, D3), �������������� ���� ������������.
�������� ���� D1 �� 9 ����, � ���� D2 �� 14 ����.
��������� ��������� ��������� �� ������ D1 � D2.
��� ���� D3 ��������� ���� ����, ��� ������� �� ����.*/

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Date D1, D2(1, 1, 2000), D3(D2);
	char flag;
	D1.fill();
	cout << "������� ���� D2: " << D2.stringDate() << ". �� ������ ������ ��? (�/�) "; cin >> flag;
	if (flag == '�' || flag == '�') D2.fill();
	cout << "=========================================================" << endl;
	cout << "����� �������� ��������� ���� D3, ���������� D2" << endl; 
	cout << "D3: " << D3.stringDate() << endl;
	cout << "���� ���� D3: " << D3.getSeason() << endl;
	cout << "=========================================================" << endl;
	cout << "��������� ���� D1 �� 9 ����, � D2 �� 14 ����, �������� ��� ����:" << endl;
	D1 += 9; D2 += 14;
	cout << "D1: " << D1.stringDate() << " D2: " << D2.stringDate() << endl;
	cout << "=========================================================" << endl;
	cout << "����, �������� �� D1 �� D2 ���� " << abs(D1 - D2) << " ����" << endl;
	
}