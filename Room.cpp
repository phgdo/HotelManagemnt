#include <iostream>
using namespace std;

class Room
{
private:
    int maPhong;
    int loaiPhong;
    int gia;
    bool status;

public:
    Room() {}
    Room(int maPhong, int loaiPhong, int gia, bool status)
    {
        this->maPhong = maPhong;
        this->loaiPhong = loaiPhong;
        this->gia = gia;
        this->status = status;
    }

    int getMaPhong()
    {
        return this->maPhong;
    }

    void setMaPhong(int maPhong)
    {
        this->maPhong = maPhong;
    }

    int getLoaiPhong()
    {
        return this->loaiPhong;
    }

    void setLoaiPhong(int loaiPhong)
    {
        this->loaiPhong = loaiPhong;
    }

    int getGia()
    {
        return this->gia;
    }

    void setGia(int gia)
    {
        this->gia = gia;
    }

    bool isStatus()
    {
        return this->status;
    }

    void setStatus(bool status)
    {
        this->status = status;
    }

    void displayRoom()
    {
        cout << "Thong tin phong " << maPhong << ": " << endl;
        cout << "Loai phong: " << loaiPhong << endl;
        cout << "Gia tien: " << gia << endl;
        cout << "Tinh trang: ";
        if (status == true)
        {
            cout << "Phong da duoc thue." << endl;
        }
        else
        {
            cout << "Phong con trong." << endl;
        }
    }

    void addRoom()
    {
        cout << "Nhap ma so phong: ";
        cin >> this->maPhong;
        fflush(stdin);
        cout << "Nhap gia tien: ";
        cin >> this->gia;
        fflush(stdin);
        cout << "Loai phong: \n"
             << "1. Phong pho thong 1 giuong doi.\n"
             << "2. Phong pho thong 2 giuong doi.\n"
             << "3. Phong thuong gia 1 giuong doi.\n"
             << "Phong tong thong 1 giuong doi.\n";
        cout << "Nhap loai phong: ";
        cin >> this->loaiPhong;
        fflush(stdin);
        cout << "Nhap trang thai: ";
        cin >> this->status;
        fflush(stdin);
    }
};
