#include "SortedType.h"

SortedType::SortedType() {  //������
	length = 0;
}

int SortedType::LengthIs() const {  //���� ����
	return length;
}

void SortedType::RetrieveItem(HouseType& house, bool& found) {  //�̸��� ��ġ�ϴ� house�� ã�Ƽ� �����ϰ�, found�� ã�Ҵ��� ����
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
	info[location] = house;  //ã�� ��ġ�� house�� insert
	length++;
}

void SortedType::DeleteItem(HouseType house) {
	int location = 0;

	while (house.ComparedTo(info[location]) != EQUAL)
		location++;
	for (int index = location + 1; index < length; index++)
		info[index - 1] = info[index];  //ã�� ��ġ�� �� delte
	length--;
}

void SortedType::PrintList()
{
	for (int i = 0; i < length; i++) {
		info[i].PrintHouseToScreen();
	}
}

HouseType SortedType::ReturnItem(int index)  //�ε����� �޾� info�迭���� �ش� �ε��� ���� ��ȯ
{
	return info[index];
}
