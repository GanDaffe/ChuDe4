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

void xdelete();

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
    cout << "\n\t\t\tKhong tim thay nhan vien.\n";
    system("pause");
}
//Kiem tra so ngay cong cua nhan vien
void checkngaycong() 
{  
    int check;
    int getID, found = 0;
    int index = 0;
    int ngaycong[12];
    //Neu khong ton tai file thi in ra man hinh
    ifstream file("WorkDay.txt"); //Mo lay du lieu tu file 
    if(!file) 
    {
        cout << "\n\t\t\tKHONG TON TAI DU LIEU";
        system("pause");
        return;
    } 
    else 
    {
    cout << "\n\t\t\tNhap ID cua nhan vien can kiem tra: ";
    cout << "\n\n\t\t\tNhap tai day: ->";
    cin >> check;
    
    file >> getID;
        while(!file.eof()) 
        {
            if(check == getID) 
            {
                found = 1;
                while(!file.eof() && index != 12) 
                {
                    file >> getID;
                    ngaycong[index] = getID;
                    index++;
                }
            }
            file >> getID;
        }
    }
    file.close();
    system("cls");
    if(found == 0) 
    {
        cout << "\n\t\t\t----Khong tim thay nhan vien----\n";
        system("pause");
    }
    else
    {
        cout << "\n\t\t\tID Nhan vien: " << check;
        for(int i = 0; i < 12; i++) cout << "\n\t\t -So ngay cong thang " << i + 1 << ": " << ngaycong[i] << '\n';
        system("pause");
    }

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
    cout << setw(40) << "---DU LIEU THONG KE---" << setw(55) << "\n\n";
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
        cout << setfill(' ');
        cout << "----------------------------------------------------------------------\n";
        cout << setw(3) << "STT" << setw(4)<< '\t' << "ID" << setw(12) << "\t " <<  "Ho Ten" << setw(10) << "\t" << "Chuc danh" << "\n" ;
        cout << "----------------------------------------------------------------------\n";
            while(!file.eof()) 
            {                                                      
                cout << setw(1) << stt++ << setw(4) << '\t' << ID << setw(12) << '\t'  <<  name << setw(10) << "\t" << exp << "\n";
                getline(file, name);
                file >> ID;
                file.ignore();
                getline(file, exp);
            } 
        cout << "----------------------------------------------------------------------\n";
        file.close();
    }

    cout << "\n\t\t\tBam [W] de kiem tra ngay cong cua nhan vien, bam [X] de xoa nhan vien hoac bam [Q] de thoat";
    cout << "\n\t\t\tNhap tai day: ";
    cin >> ch;
    cin.clear();
    fflush(stdin);

    if(ch == 'q' || ch == 'Q') return;
    else if(ch == 'w' || ch == 'W') checkngaycong();
    else if(ch == 'x' || ch == 'X' ) xdelete();
    else 
    { 
        cout << "\n\t\t\tVui long chi nhap [W] [X] va [N]\n ";
        system("pause");
        return;
    }
    cin.ignore();
    thongke();
}

void ngaycong(employee emp[], int size)
{
    system("cls");
    cout << "-------------------------------------------NHAP NGAY CONG----------------------------------------------\n";
    int temp;
    int index = 0;

    fstream file;
    file.open("WorkDay.txt", ios::app | ios::out);
    for(int i = 0 ; i < size; i++) {
        system("cls");
        cout << "\n\t\t\tBan dang nhap ngay cong cho nhan vien " << emp[i].name;
        cout << "\n\t\t\t---------------------------------------------";
        
        for(int j = 0 ; j < 12; j++) {
            cout << "\n\t\t\tNhap ngay cong thang thu " << j + 1 << ": ";
            cin >> temp;
            cout << "\n\t\t\t---------------------------------------------";
            cin.clear();
            fflush(stdin);
            while(temp > 26 || temp < 0) 
            {
                cout << "\n\t\t\tNgay cong khong hop le!\n\t\t\tNhap lai: ";
                cin >> temp;
            }
            emp[i].ngaycong[j] = temp;
        }
        file << emp[i].ID << ' ' << emp[i].ngaycong[0] << ' ' << emp[i].ngaycong[1] << ' ' << emp[i].ngaycong[2] << ' ' << emp[i].ngaycong[3] << ' ' << emp[i].ngaycong[4] << ' ' << emp[i].ngaycong[5] << ' ' << emp[i].ngaycong[6] << ' ' << emp[i].ngaycong[7] << ' ' << emp[i].ngaycong[8] << ' ' << emp[i].ngaycong[9] << ' ' << emp[i].ngaycong[10] << ' ' << emp[i].ngaycong[11] << '\n';

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
        cout << "\n\t\t\t------------------------------------------------------\n";
        file << emp[i].name << "\n" << emp[i].ID << "\n" << emp[i].exp << '\n'; //luu du lieu ra file theo tung dong

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
                    cout << "\n\t\t\tInput ->: ";
                    cin >> ch;
                    if(ch == 'y' || ch == 'Y') ngaycong(emp, size);
                    break;
                }
            case 3:
                system("cls");
                xdelete();
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

    cin.clear();
    fflush(stdin);

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
        file << '\n' <<name_c << '\n' << pass_c << '\n';
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
    string deleteID, checkID, name, exp;
    char choice;
    string getworkday;
    bool found = false;

    cout << "\n\t\t\tNhap ID nhan vien muon xoa: "; 
    cin >> deleteID;

    ifstream file1("NhanVien.txt");
    ifstream file2("WorkDay.txt");
    
    if(!file1) 
    {
        cout << "\n\t\t\tKhong co du lieu";
        file1.close();
        file2.close();
    }
    else 
    {   
        ofstream file3("Record1.txt", ios::app | ios::out);
        ofstream file4("Record2.txt", ios::app | ios::out);

        getline(file1, name);
        getline(file1, checkID);
        getline(file1, exp);
        getline(file2, getworkday);

        while(!file1.eof()) 
        {   

            if(checkID != deleteID) 
            {   
                file3 << name << "\n" << checkID << "\n" << exp << '\n';
                if(!file2.eof()) file4 << getworkday << '\n';
                getline(file2, getworkday);
            }
            else 
            {
                cout << "\n\t\t\tNhan vien: " << name;
                cout << "\n\t\t\tID: " << checkID;
                cout << "\n\t\t\tChuc danh: " << exp;
                cout << "\n\t\t\tDa xoa nhan vien\n";
                getline(file2, getworkday);
                found = true;
            }
            getline(file1, name);
            getline(file1, checkID);
            getline(file1, exp);
        }
    
        file1.close();
        file2.close();
        file3.close();
        file4.close();
        remove("NhanVien.txt");
        remove("WorkDay.txt");
        rename("Record1.txt", "NhanVien.txt");
        rename("Record2.txt", "WorkDay.txt");
    }
    if(!found) 
    {
        cout << "\n\t\t\tKhong co nhan vien nay!";
    }
    system("pause");

}
int main() 
{
user();
return 0;
}
