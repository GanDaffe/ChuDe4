#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string>

using namespace std;

struct employee 
{
string name;
string ID;
string exp;
int ngaycong[12];
};
void timkiem() 
{
    system("cls");
    string ID;
    string name;
    string exp;
    string checkID;
    ifstream file("NhanVien.txt");

    cout << "\n\t\t\tNhap ID muon tim kiem: ";
    cin >> ID;

    if(!file) 
    {
        cout << "\n\t\t\tKHONG CO DU LIEU";
        system("pause");
        return;
    }
    else 
    {   
        getline(file, name);
        getline(file, checkID);
        getline(file, exp);
        while(!file.eof()) 
        {
            if(checkID == ID) 
            {
                cout << "\n\t\t\t***TIM THAY NHAN VIEN***";
                cout << "\n\t\t\t-HO VA TEN: " << name;
                cout << "\n\t\t\t-ID: " << checkID;
                cout << "\n\t\t\t-CHUC DANH: " << exp << '\n';
                system("pause");
                return;
            }
            getline(file, name);
            getline(file, checkID);
            getline(file, exp);
        }
    file.close();
    }
    cout << "\n\t\t\t KHONG TON TAI DU LIEU";
    system("pause");

}
//Kiem tra so ngay cong cua nhan vien
void checkngaycong() 
{  
    int check;
    int getID;
    int index = 0;
    //Neu khong ton tai file thi in ra man hinh
    ifstream file("WorkDay.txt"); //Mo lay du lieu tu file 
    if(!file) 
    {
        cout << "\n\t\t\tKHONG TON TAI DU LIEU";
        system("pause");
        return;
    }
    int ngaycong[12];
    cout << "\n\t\t\tNhap ID cua nhan vien can kiem tra: ";
    cout << "\n\n\tInput here ->";
    cin >> check;
    
    file >> getID;
    while(!file.eof()) 
    {
        if(check == getID) 
        {
            while(!file.eof() && index != 12) 
            {
                file >> getID;
                ngaycong[index] = getID;
                index++;
            }
        }
        file >> getID;
    }
    file.close();
    system("cls");
    cout << "\n\t\t\tID Nhan vien: " << check;
    for(int i = 0; i < 12; i++) cout << "\n\t\t -So ngay cong thang " << i + 1 << ": " << ngaycong[i] << '\n';
    system("pause");

}
//Lap bang thong ke
void thongke() 
{   
    int stt = 1;
    string name = "";
    int ID = 0; 
    string exp = "";
    char ch;
    //Mo file NhanVien.txt de lay thong tin
    ifstream file("NhanVien.txt");
    cout << setfill('-');
    cout << setw(110) << '\n';
    cout << setw(55) << "DU LIEU THONG KE" << setw(55) << '\n';
    cout << setfill('_');
    cout << setw(110) <<'\n';
    if(!file) 
    {
        cout << "\n\t\t\t---KHONG CO DU LIEU---\n";
        system("pause");
        return;
    }
    //Lap bang du lieu thong ke
    else
    {
        getline(file, name);
        file >> ID;
        file.ignore();
        getline(file, exp);
        cout << '|' << "STT" << "\t\t\t" << "ID" << "\t\t\t" <<  "Ho Ten" << "\t\t\t\t" << "Chuc danh" << "|\n" ;
            while(!file.eof()) 
            {
                cout << '|' << stt++ << "\t\t\t" << ID << "\t\t\t" <<  name << "\t\t\t" << exp << "|\n";
                getline(file, name);
                file >> ID;
                file.ignore();
                getline(file, exp);
            }
        file.close();
    }

    cout << "\n\t\t\tBam [Y] de kiem tra ngay cong cua nhan vien hoac bam [N] de thoat";
    cout << "\n\n\t\tInput here -> ";
    cin >> ch;
    cin.clear();
    fflush(stdin);

    if(ch == 'n' || ch == 'N') return;
    else if(ch == 'y' || ch == 'Y') checkngaycong();
    else 
    { 
        cout << "\n\t\t\tVui long chi nhap [Y] hoac [N] ";
        return;
    }
    cin.ignore();
}

void ngaycong(employee emp[], int size)
{
    system("cls");
    int temp;
    int index = 0;

    fstream file;
    file.open("WorkDay.txt", ios::app | ios::out);
    for(int i = 0 ; i < size; i++) {
        system("cls");
        cout << "\n\t\t\tBan dang nhap ngay cong cho nhan vien " << emp[i].name;
        
        for(int j = 0 ; j < 12; j++) {
            cout << "\n\t\t\tNhap ngay cong thang thu " << j + 1 << ": ";
            cin >> temp;
            cin.clear();
            fflush(stdin);
            if(temp <= 26 && temp >= 0) emp[i].ngaycong[j] = temp;
            else { 
                cout << "\n\t\t\tSo ngay lam khong hop le!";
                emp[i].ngaycong[j] = 0;
            }
        }
        file << "\n" << emp[i].ID << '\n' << emp[i].ngaycong[0] << '\n' << emp[i].ngaycong[1] << '\n' << emp[i].ngaycong[2] << '\n' << emp[i].ngaycong[3] << '\n' << emp[i].ngaycong[4] << '\n' << emp[i].ngaycong[5] << '\n' << emp[i].ngaycong[6] << '\n' << emp[i].ngaycong[7] << '\n' << emp[i].ngaycong[8] << '\n' << emp[i].ngaycong[9] << '\n' << emp[i].ngaycong[10] << '\n' << emp[i].ngaycong[11];

    }
    file.close();
    system("pause");
    
}
void nhapdulieu(employee emp[], int size) 
{
    system("cls");
    fstream file;
    //mo file bang fstream
    file.open("NhanVien.txt" , ios::app | ios::out);
    for(int i = 0; i < size; i++) {
        cout << "\n\t\t\tNhap ten nhan vien thu " << i + 1 << " :";
        getline(cin, emp[i].name); 
        cout << "\n\t\t\tNhap ID[4 chu so]: ";
        cin >> emp[i].ID;
        cin.ignore();
        cout << "\n\t\t\tNhap chuc danh nhan vien: ";
        getline(cin, emp[i].exp);
        cout << "\n\t\t\t------------------------------------------------------";
        file << " " << emp[i].name << "\n" << emp[i].ID << "\n" << emp[i].exp << '\n'; //luu du lieu ra file theo tung dong

    }
    file.close();
    system("pause");
    
}

void passwordUser() 
{   
    int select;
    int size;
    char ch;

    do { 
        system("cls");
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\tHE THONG QUAN LI NHAN VIEN";
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\t1.Thong ke nhan vien";
        cout << "\n\t\t\t2.Them nhan vien";
        cout << "\n\t\t\t3.Xoa nhan vien";
        cout << "\n\t\t\t4.Tim kiem";
        cout << "\n\t\t\t5.Thoat";
        cout << "\n\t\t\tNhap 1 / 2 / 3 / 4 / 5 : ";
        cin >> select;
        cin.clear();
        fflush(stdin);

        switch(select) {
            case 1: 
                system("cls");
                thongke();
                break;
            case 2: 
                {
                    system("cls");
                    cout << "\n\t\t\tNhap so luong nhan vien can them: ";
                    cin >> size;

                    if(size == 0) break;
                
                    employee emp[size];
                    cin.ignore();

                    nhapdulieu(emp, size);
                    cout << "\n\t\t\tBan co muon nhap so ngay cong theo thang cho nhan vien <Y|N>\n";
                    cout << "Nhap tai day: ";
                    cin >> ch;
                    if(ch == 'y' || ch == 'Y') ngaycong(emp, size);
                    break;
                }
            case 3:
                system("cls");
                // xdelete();
                break;
            case 4: 
                system("cls");
                timkiem();
                break;
            case 5: 
                {   
                    system("cls");
                    cout << "\n\t\t\t  HE THONG QUAN LI NHAN VIEN";
                    cout << "\n\t\t\t\t----Da tat----\n";
                    exit(0);
                    break;
                } 
            default: 
                system("cls");
                cout << "\n\t\t\tKhong hop le";
                break;
        }

    } while(select != 5);
}

void user() 
{
    string name_c = "";
    string pass_c = "";
    string name = "";
    string pass = "";
    int count;
    int choice;
    char ch;
    ifstream file;

    cout << "\n\t\t\t ----------------------------";
    cout << "\n\t\t\tChuong trinh quan li nhan vien";
    cout << "\n\t\t\t ----------------------------";
    cout << "\n\t\t\tNhap [1] de dang nhap hoac nhap [2] de dang ky tai khoan ADMIN ";
    cin >> choice;

    if(choice == 1) {
        system("cls");
        file.open("AdminAccount.txt");
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\tDang nhap tai khoan ADMIN";   
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\tUsername: ";
        cin >> name;
        cout << "\n\t\t\tPassword: ";
        ch = _getch();

        while(ch != 13) {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        getline(file, name_c);
        while(!file.eof()) {
            if(name == name_c) {
                getline(file, pass_c);
                if(pass == pass_c) {
                    count = 1;
                    break;
                }
            }
            else getline(file, name_c);
        }
        file.close();
        if(count == 1) {
            cout << "\n\t\t\tDang nhap thanh cong!";
            passwordUser();
        }
        else {
            cout << "\n\t\t\tTai khoan khong ton tai!\n";
            system("pause");
            system("cls");
            user();
        }
   } 
    else if(choice == 2) {
        system("cls");
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\tDang ky tai khoan ADMIN: ";
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\tUsername: ";
        cin >> name_c;
        cout << "\n\t\t\tPassword(Chi 4 chu so): ";
        ch = _getch();

        while(ch != 13) {
            pass_c.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        ofstream file("AdminAccount.txt", ios::app);
        file << name_c << " " << pass_c << '\n';
        file.close();
        cout << "\n\t\t\tDang ky moi tai khoan ADMIN thanh cong";
        getch();
        user();
    }
    else { 
        cout << "\n\t\t\tInput khong hop le!";
        cout << "\n\t\t\t ----------------------------";
        user();
    }
}

void xdelete() 
{

}
int main() 
{
user();
return 0;
}
