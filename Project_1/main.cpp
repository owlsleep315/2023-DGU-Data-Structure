#include "SortedType.h"

void FileToList(SortedType& houseList, ifstream& masterIn) {
    if (masterIn.fail())
    {
        cout << "Cannot open file" << endl;
        exit(1);
    }
    string str;
    HouseType house;
    do {
        house.GetFromFile(masterIn);
        houseList.InsertItem(house);
    } while (getline(masterIn, str));
    houseList.DeleteItem(house); //�������� �߰��� �� ����
    masterIn.close();
}

void LostToFile(SortedType houseList, ofstream& masterOut) {
    if (masterOut.fail())
    {
        cout << "Cannot open file" << endl;
        exit(1);
    }
    int length = houseList.LengthIs();
    for (int i = 0; i < length; i++) {
        houseList.ReturnItem(i).WriteToFile(masterOut);
    }
    masterOut.close();
}

void AddHouse(SortedType& houseList){
    HouseType house;
    house.GetFromUser();
    bool found;
    houseList.RetrieveItem(house, found);
    if (found) {
        cout << "Duplicate name; operation aborted" << endl;  //�ߺ��� �̸��̸� �����޼���
    }
    else {
        houseList.InsertItem(house);  //�ߺ����� �ʾ����� ����Ʈ�� �߰�
        cout << "Operation completed." << endl;
    }
}

void DeleteHouse(SortedType& houseList){
    HouseType house;
    house.GetNameFromUser();
    bool found;
    houseList.RetrieveItem(house, found);
    if (found) {
        houseList.DeleteItem(house);  //ã������ ����
        cout << "Operation completed." << endl;
    }
    else {
        cout << "Person not found." << endl;  //ã�� ���ϸ� �����޼���
    }
}

void PrintHouse(SortedType houseList){
    HouseType house;
    house.GetNameFromUser();
    bool found;
    houseList.RetrieveItem(house, found);
    if (found) {
        house.PrintHouseToScreen();  //ã������ ���
    }
    else {
        cout << "Owner not in list." << endl;  //ã�� ���ϸ� �����޼���
    }
}

void PrintAllHouse(SortedType houseList) {
    houseList.PrintList();
}

void PrintHelp() {
    cout << endl << "Operations are listed below." << endl;
    cout << "Enter the appropriate uppercase letter and" << endl;
    cout << "Press return" << endl;
    cout << "A: Add a house to the list of house." << endl;
    cout << "D: Delete a specific owner's house." << endl;
    cout << "P: Print the information about an owner's house." << endl;
    cout << "L: Print all the names on the screen." << endl;
    cout << "Q: Quit processing." << endl;
    cout << endl;
}

int main(void)
{
    SortedType houseList;
    ifstream masterIn("house.mf");
    FileToList(houseList, masterIn);

    char cmd;

    PrintHelp();

    do
    {
        cout << endl << "Command: ";
        cin >> cmd;

        switch (cmd)
        {
        case 'A': case 'a':
            AddHouse(houseList);
            break;

        case 'D': case 'd':
            DeleteHouse(houseList);
            break;

        case 'P': case 'p':
            PrintHouse(houseList);
            break;

        case 'L': case 'l':
            PrintAllHouse(houseList);
            break;

        case 'Q': case 'q':
            break;

        default:
            cout << "Inactive or invalid command" << endl;
        }
    } while (cmd != 'Q' && cmd != 'q');

    ofstream masterOut("house.mf");
    LostToFile(houseList, masterOut);

    return 0;
}