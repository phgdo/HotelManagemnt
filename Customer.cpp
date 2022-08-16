#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
    int cmnd;
    string name;
    string sdt;
    string from_date;
    string to_date;
    string diachi;
    int maPhong;

public:
    Customer()
    {
        this->cmnd = 0;
        this->name = ' ';
        this->sdt = ' ';
        this->from_date = ' ';
        this->to_date = ' ';
        this->diachi = ' ';
    }
    Customer(int cmnd, string name, string sdt, string from_date, string to_date, string diachi, int maPhong)
    {
        this->cmnd = cmnd;
        this->name = name;
        this->sdt = sdt;
        this->from_date = from_date;
        this->to_date = to_date;
        this->diachi = diachi;
        this->maPhong = maPhong;
    }
    int getCmnd()
    {
        return this->cmnd;
    }

    void setCmnd(int cmnd)
    {
        this->cmnd = cmnd;
    }

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getSdt()
    {
        return this->sdt;
    }

    void setSdt(string sdt)
    {
        this->sdt = sdt;
    }

    string getFrom_date()
    {
        return this->from_date;
    }

    void setFrom_date(string from_date)
    {
        this->from_date = from_date;
    }

    string getTo_date()
    {
        return this->to_date;
    }

    void setTo_date(string to_date)
    {
        this->to_date = to_date;
    }

    string getDiachi()
    {
        return this->diachi;
    }

    void setDiachi(string diachi)
    {
        this->diachi = diachi;
    }

    int getmaPhong()
    {
        return this->maPhong;
    }

    void setmaPhong(int maPhong)
    {
        this->maPhong = maPhong;
    }

    void displayCustomer()
    {
        cout << "Thong tin khach hang: " << endl;
        cout << "CMND: " << cmnd << endl;
        cout << "Ho va ten: " << name << endl;
        cout << "Dia chi: " << diachi << endl;
        cout << "Ngay thue: " << from_date << endl;
        cout << "Ngay tra: " << to_date << endl;
    }

    void addCustomer()
    {
        cout << "Nhap thong tin cua khach hang: " << endl;
        cout << "Nhap ho va ten: ";
        getline(cin, this->name);
        for (int i = 0; i < this->name.length(); i++)
        {
            if (this->name[i] >= 'a' && this->name[i] <= 'z')
            {
                this->name[i] -= 32;
            }
        }
        cout << "Nhap chung minh nhan dan hoac ho chieu: ";
        cin >> this->cmnd;
        fflush(stdin);
        cout << "Nhap so dien thoai: ";
        getline(cin, sdt);
        cout << "Nhap dia chi cua khach hang: ";
        getline(cin, this->diachi);
        cout << "Nhap ma phong: ";
        cin >> this->maPhong;
        fflush(stdin);
        cout << "Nhap ngay checkin (dd/mm/yyyy): ";
        getline(cin, this->from_date);
        cout << "Nhap ngay checkout (dd/mm/yyyy): ";
        getline(cin, this->to_date);
    }

    int totalDays()
    {
        string temp_day = this->from_date.substr(0, 2);
        string temp_month = this->from_date.substr(3, 2);
        string temp_day2 = this->to_date.substr(0, 2);
        string temp_month2 = this->to_date.substr(3, 2);
        short day1 = stoi(temp_day);
        short month1 = stoi(temp_month);
        short day2 = stoi(temp_day2);
        short month2 = stoi(temp_month2);

        short sum = 0;
        if (month1 == month2)
        {
            sum = abs(month2 - month1) + 1;
        }
        else
        {
            if (month1 == 1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 11)
            {
                day1 = 31 - day1;
            }
            if (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11)
            {
                day1 = 30 - day1;
            }
            if (month1 == 2)
            {
                day1 = 28 - day1;
            }

            if (month2 == 1 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 8 || month2 == 10 || month2 == 11)
            {
                day2 = day2 - 0;
            }
            if (month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11)
            {
                day2 = day2 - 0;
            }
            if (month2 == 2)
            {
                day2 = day2 - 0;
            }
            sum = day1 + day2 + 1;
        }
        return sum;
    }
};
