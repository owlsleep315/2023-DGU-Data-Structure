#include "SortedType.h"

SortedType::SortedType() {  //생성자
	length = 0;
}

int SortedType::LengthIs() const {  //길이 리턴
	return length;
}

void SortedType::RetrieveItem(HouseType& house, bool& found) {  //이름이 일치하는 house를 찾아서 저장하고, found에 찾았는지 저장
	int midPoint;
	int first = 0;
	int last = length - 1;
	bool moreToSearch = (first <= last);
	found = false;

	while (moreToSearch && !found) {  //binary search
		midPoint = (first + last) / 2;
		switch (house.ComparedTo(info[midPoint])) {
		case LESS: last = midPoint - 1;
			moreToSearch = (first <= last);
			break;
		case GREATER: first = midPoint + 1;
			moreToSearch = (first <= last);
			break;
		case EQUAL: found = true;
			house = info[midPoint];
			break;
		}
	}
}

void SortedType::InsertItem(HouseType house) {
	bool moreToSearch;
	int location = 0;

	moreToSearch = (location < length);
	while (moreToSearch) {
		switch (house.ComparedTo(info[location])) {
		case LESS: moreToSearch = false;
			break;
		case GREATER: location++;
			moreToSearch = (location < length);
			break;
		}
	}
	for (int index = length; index > location; index--)
		info[index] = info[index - 1];
	info[location] = house;  //찾은 위치에 house를 insert
	length++;
}

void SortedType::DeleteItem(HouseType house) {
	int location = 0;

	while (house.ComparedTo(info[location]) != EQUAL)
		location++;
	for (int index = location + 1; index < length; index++)
		info[index - 1] = info[index];  //찾은 위치에 값 delte
	length--;
}

void SortedType::PrintList()
{
	for (int i = 0; i < length; i++) {
		info[i].PrintHouseToScreen();
	}
}

HouseType SortedType::ReturnItem(int index)  //인덱스를 받아 info배열에서 해당 인덱스 값을 반환
{
	return info[index];
}
