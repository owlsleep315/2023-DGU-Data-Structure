#include "HouseType.h"

HouseType::HouseType() {
	name = "";
	address = "";
	price = 0;
	pyung = 0;
	bedrooms = 0;
}

void HouseType::GetFromFile(ifstream& file)
{
	string str;
	getline(file, str);
	this->name = str;
	getline(file, str);
	this->address = str;

	string str1;
	string str2;
	int num[3];
	int a = 0;
	int i = 0;
	getline(file, str1);
	getline(file, str2);
	str = str1 + str2;  //���ݰ� ��,�� ������ �ִ� ���ڿ� ��ġ��
	for (char c : str) {
		if (c >= 48 && c <= 57) {
			a = a * 10 + (c - 48);
		}
		else if (a != 0) {
			num[i] = a;  //���ڿ����� ���ڸ� �����Ͽ� �迭�� ����
			a = 0;
			i++;
		}
	}
	num[2] = a;
	this->price = num[0];
	this->pyung = num[1];
	this->bedrooms = num[2];
}

void HouseType::WriteToFile(ofstream& file)
{
	file << name << endl;
	file << address << endl;
	file << "����: " << price << "��" << endl;
	file << "����: " << pyung << "��, ��: " << bedrooms << endl << endl;
}

RelationType HouseType::ComparedTo(HouseType house) const {  //�ٸ� house�� name�� ���Ͽ� ����
	if (this->name < house.name)
		return LESS;
	else if (this->name > house.name)
		return GREATER;
	else return EQUAL;
}

void HouseType::PrintHouseToScreen() const  //house�� ���� ���
{
	cout << name << endl;
	cout << address << endl;
	cout << "����: " << price << "��" << endl;
	cout << "����: " << pyung << "��,��: " << bedrooms << endl;
	cout << endl;
}

void HouseType::GetFromUser()  //�����κ��� ���� �Է¹ޱ�
{
	cout << "Enter name; press return. ";
	cin >> this->name;
	cin.ignore();  //����Ű ����
	cout << "Enter address; press return. ";
	getline(cin, this->address);
	cout << "Enter price, square meter(pyung), number of bedrooms; press return. ";
	cin >> this->price;
	cin >> this->pyung;
	cin >> this->bedrooms;
}

void HouseType::GetNameFromUser()  //�����κ��� �̸� �Է¹ޱ�
{
	cout << "Enter name; press return. ";
	cin >> this->name;
}

string HouseType::GetName()  // �̸� ����
{
	return name;
}
