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
	str = str1 + str2;  //가격과 평,방 정보가 있는 문자열 합치기
	for (char c : str) {
		if (c >= 48 && c <= 57) {
			a = a * 10 + (c - 48);
		}
		else if (a != 0) {
			num[i] = a;  //문자열에서 숫자를 추출하여 배열에 저장
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
	file << "가격: " << price << "억" << endl;
	file << "평형: " << pyung << "평, 방: " << bedrooms << endl << endl;
}

RelationType HouseType::ComparedTo(HouseType house) const {  //다른 house와 name값 비교하여 리턴
	if (this->name < house.name)
		return LESS;
	else if (this->name > house.name)
		return GREATER;
	else return EQUAL;
}

void HouseType::PrintHouseToScreen() const  //house의 정보 출력
{
	cout << name << endl;
	cout << address << endl;
	cout << "가격: " << price << "억" << endl;
	cout << "평형: " << pyung << "평,방: " << bedrooms << endl;
	cout << endl;
}

void HouseType::GetFromUser()  //유저로부터 정보 입력받기
{
	cout << "Enter name; press return. ";
	cin >> this->name;
	cin.ignore();  //엔터키 무시
	cout << "Enter address; press return. ";
	getline(cin, this->address);
	cout << "Enter price, square meter(pyung), number of bedrooms; press return. ";
	cin >> this->price;
	cin >> this->pyung;
	cin >> this->bedrooms;
}

void HouseType::GetNameFromUser()  //유저로부터 이름 입력받기
{
	cout << "Enter name; press return. ";
	cin >> this->name;
}

string HouseType::GetName()  // 이름 리턴
{
	return name;
}
