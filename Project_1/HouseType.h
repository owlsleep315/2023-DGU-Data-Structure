#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ITEMS = 10;
enum RelationType{LESS, EQUAL, GREATER};

class HouseType
{
public:
	HouseType();
	void GetFromFile(ifstream& file);
	void WriteToFile(ofstream& file);
	RelationType ComparedTo(HouseType house) const;
	void PrintHouseToScreen() const;
	void GetFromUser();
	void GetNameFromUser();
	string GetName();
private:
	string name;
	string address;
	int price;
	int pyung;
	int bedrooms;
};