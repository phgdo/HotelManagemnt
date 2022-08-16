#include <iostream>
using namespace std;

class Employee
{
private:
    int maNV;
    string hoten;
    string ngSinh;
    string sdt;
    string diachi;
    int luong;
    short ca;
    short chamcong;

public:
    Employee() {}
    Employee(int maNV, string hoten, string ngSinh, string sdt, string diachi, int luong, short ca, short chamcong)
    {
        this->maNV = maNV;
        this->hoten = hoten;
        this->ngSinh = ngSinh;
        this->sdt = sdt;
        this->diachi = diachi;
        this->luong = luong;
        this->ca = ca;
        this->chamcong = chamcong;
    }

    // Getter and setter
    int getMaNV()
    {
        return this->maNV;
    }

    void setMaNV(int maNV)
    {
        this->maNV = maNV;
    }

    string getHoten()
    {
        return this->hoten;
    }

    void setHoten(string hoten)
    {
        this->hoten = hoten;
    }

    string getNgSinh()
    {
        return this->ngSinh;
    }

    void setNgSinh(string ngSinh)
    {
        this->ngSinh = ngSinh;
    }

    string getSdt()
    {
        return this->sdt;
    }

    void setSdt(string sdt)
    {
        this->sdt = sdt;
    }

    string getDiachi()
    {
        return this->diachi;
    }

    void setDiachi(string diachi)
    {
        this->diachi = diachi;
    }

    int getLuong()
    {
        return this->luong;
    }

    void setLuong(int luong)
    {
        this->luong = luong;
    }

    short getCa()
    {
        return this->ca;
    }

    void setCa(short ca)
    {
        this->ca = ca;
    }

    short getChamcong()
    {
        return this->chamcong;
    }

    void setChamcong(short chamcong)
    {
        this->chamcong = chamcong;
    }

    void addEmployee()
    {
        cout << "Nhap ma nhan vien: ";
        cin >> this->maNV;
        fflush(stdin);
        cout << "Nhap ho va ten: ";
        getline(cin, this->hoten);
        cout << "Nhap ngay sinh: ";
        getline(cin, this->ngSinh);
        cout << "Nhap so dien thoai: ";
        getline(cin, this->sdt);
        cout << "Nhap dia chi: ";
        getline(cin, this->diachi);
        cout << "Nhap luong: ";
        cin >> this->luong;
        cout << "Nhap ca lam viec: ";
        cin >> this->ca;
        fflush(stdin);
        this->chamcong = 0;
    }

    void chinhSua(short luachon)
    {
        switch (luachon)
        {
        case 1:
            cin >> this->maNV;
            break;
        case 2:
            getline(cin, this->hoten);
            break;
        case 3:
            getline(cin, this->ngSinh);
            break;
        case 4:
            getline(cin, this->sdt);
            break;
        case 5:
            getline(cin, this->diachi);
            break;
        case 6:
            cin >> this->luong;
            break;
        case 7:
            cin >> this->ca;
            break;

        default:
            break;
        }
        //     cout << "Sua thong tin nhan vien: " << endl;
        //     cout << "1. ma nhan vien: " << endl
        //          << "2. Sua ho va ten: " << endl
        //          << "3. Sua ngay sinh: " << endl
        //          << "4. Sua so dien thoai: " << endl
        //          << "5. Sua dia chi: " << endl
        //          << "6. Sua luong: " << endl
        //          << "7. Sua ca lam viec: " << endl
        //          << "0. Quay lai.";
    }

    void chamCong()
    {
        getChamcong() + 1;
    }

    void displayEmployee()
    {
        cout << "Ma nhan vien: " << this->maNV << endl;
        cout << "Ngay sinh: " << this->ngSinh << endl;
        cout << "So dien thoai: " << this->sdt << endl;
        cout << "Dia chi: " << this->diachi << endl;
        cout << "Luong: " << this->luong << endl;
        cout << "Ca lam viec: " << this->ca << endl;
        cout << "So ngay cong: " << this->chamcong << endl;
        cout << endl;
    }
};