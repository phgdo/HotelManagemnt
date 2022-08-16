#pragma once
#include "Room.cpp"
#include "Customer.cpp"
#include "Employee.cpp"
#include <fstream>
#include <vector>
#include <Windows.h>
using namespace std;
struct accout
{
    string username;
    string password;
};

static long long sum;
void MainMenu(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers);
void doanhThu();
void employeesManage(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers);
void showEmployeesByShifts(vector<Employee> employees, short ca);
void searchEmployeesWithID(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers);
void searchEmployeesWithName(vector<Employee> employees);
void searchEmployeesWithPhoneNumber(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers);
void showEmptyRooms(vector<Room> rooms);
void roomsManage(vector<Room> rooms, vector<Customer> customers);
void searchCustomerWithRoomID(vector<Room> rooms, vector<Customer> customers);
void searchCustomersWithName(vector<Room> rooms, vector<Customer> customers);
void searchCustomersWithPhoneNumber(vector<Room> rooms, vector<Customer> customers);
void searchCustomersWithID(vector<Room> rooms, vector<Customer> customers);
long thanhToan(vector<Room> rooms, Customer customer);
void checkout(vector<Room> rooms, vector<Customer> customers);
void checkin(vector<Room> rooms, vector<Customer> customers);
void setting(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers);
bool login();
void addroom(vector<Room> rooms);
void deleteroom(vector<Room> rooms);
void addemployee(vector<Employee> employees);
void deleteemployee(vector<Employee> employees);

int main()
{
    vector<Room> rooms;
    vector<Employee> employees;
    vector<Customer> customers;

    bool loginSucess = false;
    if (login())
    {
        loginSucess = true;
    }

    while (loginSucess == false)
    {
        login();
    }
    while (loginSucess == true)
    {
        MainMenu(rooms, employees, customers);
    }
    return 0;
}

///////////////////////////////////////////////////////////////
void MainMenu(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers)
{
    // cout << "                                    █\n";
    // cout << "                                   █ █\n";
    // cout << "                                  █   █\n";
    // cout << "                             █   █     █   █\n";
    // cout << "                            ██  █  ███  █  ██\n";
    // cout << "                           █ █  █  █ █  █  █ █\n";
    // cout << "                          █  █  █  ███  █  █  █\n";
    // cout << "                         █ ◾ █  █       █  █ ◾ █\n";
    // cout << "                     ██  █   █  █ █████ █  █   █  ██\n";
    // cout << "                    █ █  █ ◾ █  █ █   █ █  █ ◾ █  █ █\n";
    // cout << "                   █  █  █   █  █ █   █ █  █   █  █  █\n";
    // cout << "                 ▄▄▄█ █▄▄█ ◾ █▄▄█ █████ █▄▄█ ◾ █▄▄█ █▄▄▄\n";
    // cout << endl;
    // cout << "                   ▓▓   ▓▓▓    ▓ ▓  ▓▓  ▓▓▓ ▓▓▓ ▓\n";
    // cout << "                   ▓ ▓  ▓▓▓    ▓▓▓ ▓  ▓  ▓  ▓▓  ▓\n";
    // cout << "                   ▓▓   ▓      ▓ ▓  ▓▓   ▓  ▓▓▓ ▓▓▓\n";
    short choice = 0;
    cout << "Chao mung den voi khach san DP." << endl;
    cout << "Vui long lua chon tinh nang: " << endl;
    cout << "1. Quan ly phong." << endl;
    cout << "2. Quan ly nhan vien." << endl;
    cout << "3. Doanh thu." << endl;
    cout << "4. Cai dat." << endl;
    cout << "5. Thoat." << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    system("cls");

    switch (choice)
    {
    case 1:
        system("cls");
        roomsManage(rooms, customers);
        break;

    case 2:
        system("cls");
        employeesManage(rooms, employees, customers);
        break;

    case 3:
        system("cls");
        doanhThu();
        break;

    case 4:
    {
        system("cls");
        setting(rooms, employees, customers);
        break;
    }

    default:
        break;
    }
    fflush(stdin);
}

void doanhThu()
{
    cout << "Tong doanh thu la: " << sum << endl;
}

void employeesManage(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers)
{
    short choice = 0;
    cout << "Vui long lua chon tinh nang: " << endl;
    cout << "1. Tim kiem nhan vien." << endl;
    cout << "2. Danh sach nhan vien theo ca lam viec." << endl;
    cout << "3. Cham cong." << endl;
    cout << "Quay lai." << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        short choice2 = 0;
        cout << "Vui long lua chon tinh nang: " << endl;
        cout << "1. Tim kiem nhan vien theo chung minh nhan dan." << endl;
        cout << "2. Tim kiem nhan vien theo ho va ten." << endl;
        cout << "3. Tim kiem nhan vien theo so dien thoai." << endl;
        cout << "0. Quay lai." << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice2;
        switch (choice2)
        {
        case 1:
        {
            searchEmployeesWithID(rooms, employees, customers);
            break;
        }

        case 2:
        {
            searchCustomersWithName(rooms, customers);
            break;
        }

        case 3:
        {
            searchEmployeesWithPhoneNumber(rooms, employees, customers);
            break;
        }

        default:
        {
            employeesManage(rooms, employees, customers);
            break;
        }
        }
        break;
    }
    case 2:
    {
        short ca;
        cout << "Ca 1: 0 AM - 8AM." << endl;
        cout << "Ca 2: 8 AM - 4PM." << endl;
        cout << "Ca 3: 4 PM - 0AM." << endl;
        cout << "Nhap ca lam viec: ";
        cin >> ca;
        while (ca != 1 || ca != 2 || ca != 3)
        {
            cout << "Ca lam viec khong dung. Hay thu lai: ";
            cin >> ca;
        }
        showEmployeesByShifts(employees, ca);
        cout << "\n0. Quay lai.";
        cin >> ca;
        if (ca == 0)
        {
            employeesManage(rooms, employees, customers);
        }
        else
        {
            cout << "\n0. Quay lai.";
            cin >> ca;
        }
        break;
    }

    case 3:
    {
        short ca;
        int maNV;
        cout << "Nhap ma nhan vien: ";
        cin >> maNV;
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].getMaNV() == maNV)
            {
                employees[i].chamCong();
            }
        }
        cout << "\n0. Quay lai.";
        cin >> ca;
        if (ca == 0)
        {
            employeesManage(rooms, employees, customers);
        }
        else
        {
            cout << "\n0. Quay lai.";
            cin >> ca;
        }
        break;
    }

    default:
        MainMenu(rooms, employees, customers);
        break;
    }
}

void showEmployeesByShifts(vector<Employee> employees, short ca)
{
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].getCa() == ca)
        {
            employees[i].displayEmployee();
        }
    }
}

void searchEmployeesWithID(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers)
{
    int ID;
    bool kt = false;
    Employee temp;
    cout << "Nhap ma nhan vien: ";
    cin >> ID;

    for (int i = 0; i < employees.size(); i++)
    {
        if (ID == employees[i].getMaNV())
        {
            temp = employees[i];
            kt = true;
        }
    }

    if (kt == false)
    {
        cout << "Khong tim thay khach hang.";
        cout << "1. Nhap lai." << endl;
        cout << "2. Quay lai." << endl;
        short lc;
        switch (lc)
        {
        case 1:
        {
            searchEmployeesWithID(rooms, employees, customers);
            break;
        }
        default:
            employeesManage(rooms, employees, customers);
            break;
        }
    }
    else
    {
        temp.displayEmployee();
    }
}

void searchEmployeesWithName(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers)
{
    string hoten;
    Employee temp;
    bool kt = false;
    cout << "Nhap ho va ten nhan vien: ";
    getline(cin, hoten);
    for (int i = 0; i < hoten.length(); i++)
    {
        if (hoten[i] >= 'a' && hoten[i] <= 'z')
        {
            hoten[i] -= 32;
        }
    }
    for (int i = 0; i < employees.size(); i++)
    {
        if (hoten == employees[i].getHoten())
        {
            kt = true;
            temp = employees[i];
            break;
        }
    }
    if (kt == false)
    {
        cout << "Khong tim thay khach hang.";
        cout << "1. Nhap lai ten." << endl;
        cout << "2. Quay lai." << endl;
        short lc;
        switch (lc)
        {
        case 1:
        {
            searchEmployeesWithName(rooms, employees, customers);
            break;
        }
        default:
            employeesManage(rooms, employees, customers);
            break;
        }
    }
    else
    {
        temp.displayEmployee();
    }
}

void searchEmployeesWithPhoneNumber(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers)
{
    string sdt;
    Employee temp;
    bool kt = false;
    cout << "Nhap so dien thoai nhan vien: ";
    getline(cin, sdt);

    for (int i = 0; i < employees.size(); i++)
    {
        if (sdt == employees[i].getSdt())
        {
            kt = true;
            temp = employees[i];
            break;
        }
    }
    if (kt == false)
    {
        cout << "Khong tim thay khach hang.";
        cout << "1. Nhap lai." << endl;
        cout << "2. Quay lai." << endl;
        short lc;
        switch (lc)
        {
        case 1:
        {
            searchEmployeesWithPhoneNumber(rooms, employees, customers);
            break;
        }
        default:
            employeesManage(rooms, employees, customers);
            break;
        }
    }
    else
    {
        temp.displayEmployee();
    }
}

void showEmptyRooms(vector<Room> rooms)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i].isStatus() == false)
        {
            cout << rooms[i].getMaPhong() << "\t";
        }
    }
    cout << endl;
}

void roomsManage(vector<Room> rooms, vector<Customer> customers)
{
    short choice;
    cout << "1. Checkin." << endl;
    cout << "2. Checkout va thanh toan." << endl;
    cout << "3. Danh sach phong trong." << endl;
    cout << "4. Tim kiem khach hang." << endl;
    cout << "0. Quay lai." << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        checkin(rooms, customers);
        break;
    }

    case 2:
    {
        checkout(rooms, customers);
        break;
    }
    case 3:
    {
        showEmptyRooms(rooms);
        break;
    }
    case 4:
    {
        short choise2;
        cout << "1. Tim theo ho ten khach hang: " << endl;
        cout << "2. Tim theo so chung minh nhan dan." << endl;
        cout << "3. Tim theo so dien thoai." << endl;
        cout << "4. Tim theo ma so phong." << endl;
        cout << "0. Quay lai." << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choise2;
        system("cls");
        switch (choise2)
        {
        case 1:
        {
            searchCustomersWithName(rooms, customers);
            break;
        }
        case 2:
        {
            searchCustomersWithID(rooms, customers);
            break;
        }
        case 3:
        {
            searchCustomersWithPhoneNumber(rooms, customers);
            break;
        }
        case 4:
        {
            searchCustomerWithRoomID(rooms, customers);
            break;
        }
        default:
        {
            roomsManage(rooms, customers);
            break;
        }
        }

    default:
        break;
    }
        fflush(stdin);
    }
}

void searchCustomerWithRoomID(vector<Room> rooms, vector<Customer> customers)
{
    int ID;
    bool kt = false;
    vector<Customer> temp;
    cout << "Nhap ma so phong: ";
    cin >> ID;

    for (int i = 0; i < customers.size(); i++)
    {
        if (ID == customers[i].getmaPhong())
        {
            temp.push_back(customers[i]);
            kt = true;
        }
    }

    if (kt == false)
    {
        cout << "Khong tim thay khach hang.";
        cout << "1. Nhap lai." << endl;
        cout << "2. Quay lai." << endl;
        short lc;
        switch (lc)
        {
        case 1:
        {
            searchCustomersWithID(rooms, customers);
            break;
        }
        case 2:
        {
            roomsManage(rooms, customers);
            break;
        }
        default:
            roomsManage(rooms, customers);
            break;
        }
    }
    else
    {
        for (int i = 0; i < temp.size(); i++)
        {
            temp[i].displayCustomer();
        }
    }
}

void searchCustomersWithName(vector<Room> rooms, vector<Customer> customers)
{
    string hoten;
    Customer temp;
    bool kt = false;
    cout << "Nhap ho va ten khach hang: ";
    getline(cin, hoten);
    for (int i = 0; i < hoten.length(); i++)
    {
        if (hoten[i] >= 'a' && hoten[i] <= 'z')
        {
            hoten[i] -= 32;
        }
    }
    for (int i = 0; i < customers.size(); i++)
    {
        if (hoten == customers[i].getName())
        {
            kt = true;
            temp = customers[i];
            break;
        }
    }
    if (kt == false)
    {
        cout << "Khong tim thay khach hang.";
        cout << "1. Nhap lai ten." << endl;
        cout << "2. Quay lai." << endl;
        short lc;
        switch (lc)
        {
        case 1:
        {
            searchCustomersWithName(rooms, customers);
            break;
        }
        default:
            roomsManage(rooms, customers);
            break;
        }
    }
    else
    {
        temp.displayCustomer();
    }
}

void searchCustomersWithPhoneNumber(vector<Room> rooms, vector<Customer> customers)
{
    string sdt;
    Customer temp;
    bool kt = false;
    cout << "Nhap ho va ten khach hang: ";
    getline(cin, sdt);

    for (int i = 0; i < customers.size(); i++)
    {
        if (sdt == customers[i].getSdt())
        {
            kt = true;
            temp = customers[i];
            break;
        }
    }
    if (kt == false)
    {
        cout << "Khong tim thay khach hang.";
        cout << "1. Nhap lai ten." << endl;
        cout << "2. Quay lai." << endl;
        short lc;
        switch (lc)
        {
        case 1:
        {
            searchCustomersWithPhoneNumber(rooms, customers);
            break;
        }
        case 2:
        {
            roomsManage(rooms, customers);
            break;
        }
        default:
            roomsManage(rooms, customers);
            break;
        }
    }
    else
    {
        temp.displayCustomer();
    }
}

void searchCustomersWithID(vector<Room> rooms, vector<Customer> customers)
{
    int ID;
    bool kt = false;
    Customer temp;
    cout << "Nhap chung minh nhan dan cua khach hang: ";
    cin >> ID;
    for (int i = 0; i < customers.size(); i++)
    {
        if (ID == customers[i].getCmnd())
        {
            bool kt = true;
            temp = customers[i];
            break;
        }
    }
    if (kt == false)
    {
        cout << "Khong tim thay khach hang.";
        cout << "1. Nhap lai." << endl;
        cout << "2. Quay lai." << endl;
        short lc;
        switch (lc)
        {
        case 1:
        {
            searchCustomersWithID(rooms, customers);
            break;
        }
        case 2:
        {
            roomsManage(rooms, customers);
            break;
        }
        default:
            roomsManage(rooms, customers);
            break;
        }
    }
    else
    {
        temp.displayCustomer();
    }
}

long thanhToan(vector<Room> rooms, Customer customer)
{
    int gia = 0;
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i].getMaPhong() == customer.getmaPhong())
        {
            gia = rooms[i].getGia();
        }
    }

    sum += customer.totalDays() * gia;
    return customer.totalDays() * gia;
}

void checkout(vector<Room> rooms, vector<Customer> customers)
{
    short choise;
    cout << "1. Chekcout theo ho ten khach hang: " << endl;
    cout << "2. Chekcout theo so chung minh nhan dan." << endl;
    cout << "3. Chekcout theo so dien thoai." << endl;
    cout << "4. Chekcout theo ma so phong." << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> choise;
    system("cls");
    switch (choise)
    {
    case 1:
    {
        string hoten;
        cout << "Nhap ho va ten khach hang: ";
        getline(cin, hoten);
        for (int i = 0; i < hoten.length(); i++)
        {
            if (hoten[i] >= 'a' && hoten[i] <= 'z')
            {
                hoten[i] -= 32;
            }
        }
        for (int i = 0; i < customers.size(); i++)
        {
            if (hoten == customers[i].getName())
            {
                cout << "Tong tien can thanh toan la: " << thanhToan(rooms, customers[i]);
                customers.erase(customers.begin() + i);
                break;
            }
        }
        break;
    }

    case 2:
    {
        int ID;
        cout << "Nhap chung minh nhan dan cua khach hang: ";
        cin >> ID;
        for (int i = 0; i < customers.size(); i++)
        {
            if (ID == customers[i].getCmnd())
            {
                cout << "Tong tien can thanh toan la: " << thanhToan(rooms, customers[i]);
                customers.erase(customers.begin() + i);
                break;
            }
        }
        break;
    }

    case 3:
    {
        string sdt;
        cout << "Nhap ho va ten khach hang: ";
        getline(cin, sdt);
        for (int i = 0; i < customers.size(); i++)
        {
            if (sdt == customers[i].getSdt())
            {
                cout << "Tong tien can thanh toan la: " << thanhToan(rooms, customers[i]);
                customers.erase(customers.begin() + i);
                break;
            }
        }
        break;
    }

    case 4:
    {
        int maphong;
        cout << "Nhap chung minh nhan dan cua khach hang: ";
        cin >> maphong;
        for (int i = 0; i < customers.size(); i++)
        {
            if (maphong == customers[i].getmaPhong())
            {
                cout << "Tong tien can thanh toan la: " << thanhToan(rooms, customers[i]);
                customers.erase(customers.begin() + i);
                break;
            }
        }
        break;
    }

    default:
        break;
    }
}

void checkin(vector<Room> rooms, vector<Customer> customers)
{
    showEmptyRooms(rooms);
    int maphong;
    cout << "\nNhap ma so phong checkin: ";
    cin >> maphong;
    fflush(stdin);
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i].getMaPhong() == maphong)
        {
            break;
        }
        else
        {
            cout << "Sai ma so phong. Vui long thu lai: ";
            cin >> maphong;
        }
    }

    // add Customer
    Customer temp1;
    temp1.setmaPhong(maphong);
    temp1.addCustomer();
    customers.push_back(temp1);
    fflush(stdin);
}

void addroom(vector<Room> rooms)
{
    Room tempR;
    tempR.addRoom();
    rooms.push_back(tempR);
}

void deleteroom(vector<Room> rooms)
{
    int maphong;
    cout << "Nhap ma phong can xoa: ";
    cin >> maphong;

    for (int i = 0; i < rooms.size(); i++)
    {
        if (maphong == rooms[i].getMaPhong())
        {
            rooms.erase(rooms.begin() + i);
        }
    }
}

void addemployee(vector<Employee> employees)
{
    Employee tempE;
    tempE.addEmployee();
    employees.push_back(tempE);
}

void deleteemployee(vector<Employee> employees)
{
    string tennv;
    cout << "Nhap ho va ten nhan vien can tim: ";
    getline(cin, tennv);

    for (int i = 0; i < employees.size(); i++)
    {
        if (tennv == employees[i].getHoten())
        {
            employees.erase(employees.begin() + i);
        }
    }
}

void setting(vector<Room> rooms, vector<Employee> employees, vector<Customer> customers)
{
    short choice;
    cout << "1. Them phong." << endl;
    cout << "2. Xoa phong." << endl;
    cout << "3. Them nhan vien." << endl;
    cout << "4. Xoa nhan vien." << endl;
    cout << "0. Quay lai." << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        addroom(rooms);
        cout << "Tiep tuc them phong?(Y/N): ";
        char lc;
        cin >> lc;
        while (lc == 'y' || lc == 'Y')
        {
            addroom(rooms);
            cout << "Tiep tuc them phong?(Y/N): ";
            char lc;
            cin >> lc;
            if (lc == 'N' || lc == 'n')
            {
                break;
            }
        }
        break;
    }

    case 2:
    {
        deleteroom(rooms);
        cout << "Tiep tuc xoa phong?(Y/N): ";
        char lc;
        cin >> lc;
        while (lc == 'y' || lc == 'Y')
        {
            deleteroom(rooms);
            cout << "Tiep tuc xoa phong?(Y/N): ";
            char lc;
            cin >> lc;
            if (lc == 'N' || lc == 'n')
            {
                break;
            }
        }
        break;
    }

    case 3:
    {
        addemployee(employees);
        cout << "Tiep tuc them nhan vien?(Y/N): ";
        char lc;
        cin >> lc;
        while (lc == 'y' || lc == 'Y')
        {
            addemployee(employees);
            cout << "Tiep tuc them nhan vien?(Y/N): ";
            char lc;
            cin >> lc;
            if (lc == 'N' || lc == 'n')
            {
                break;
            }
        }
        break;
    }

    case 4:
    {
        deleteemployee(employees);
        cout << "Tiep tuc xoa nhan vien?(Y/N): ";
        char lc;
        cin >> lc;
        while (lc == 'y' || lc == 'Y')
        {
            deleteemployee(employees);
            cout << "Tiep tuc xoa nhan vien?(Y/N): ";
            char lc;
            cin >> lc;
            if (lc == 'N' || lc == 'n')
            {
                break;
            }
        }
        break;
    }
    case 0:
    {
        MainMenu(rooms, employees, customers);
        break;
    }

    default:
    {
        setting(rooms, employees, customers);
        break;
    }
    }
}

bool login()
{
    vector<accout> accs = {{"admin", "password"}, {"nhanvien1", "nhanvien1"}};
    accout temp;
    cout << "Nhap thong tin dang nhap he thong: " << endl;
    cout << "Username: ";
    getline(cin, temp.username);
    cout << "Password: ";
    getline(cin, temp.password);
    bool success = false;
    for (short i = 0; i < accs.size(); i++)
    {
        if ((temp.username == accs[i].username) && (temp.password == accs[i].password))
        {
            success = true;
            break;
        }
    }
    if (success == true)
    {
        cout << "Dang nhap thanh cong.";
        Sleep(1000);
    }
    else
    {
        cout << "Dang nhap that bai.";
        Sleep(1000);
        login();
    }
    return success;
}
