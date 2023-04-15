#include "HouseType.h"

class SortedType {
public:
	SortedType();
	int LengthIs() const;
	void RetrieveItem(HouseType& house, bool& found);
	void InsertItem(HouseType house);
	void DeleteItem(HouseType house);
	void PrintList();
	HouseType ReturnItem(int index);
private:
	int length;
	HouseType info[MAX_ITEMS];
};