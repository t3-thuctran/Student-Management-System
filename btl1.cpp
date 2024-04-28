#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

const string INPUT_FILE = "input.txt";
const string OUTPUT_FILE = "input.txt";
void enter() {
    ofstream outFile(OUTPUT_FILE, ios::app); 
    if (!outFile) {
        cerr << "Khong the mo file output.txt." << endl;
        return;
    }

    int ch = 0;
    cout << "Nhap so luong sinh vien muon them: ";
    cin >> ch;

    for (int i = 0; i < ch; i++) {
        string id, name, Class, course, sdt, alldiem;
        cout << "\nNhap thong tin cua sinh vien " << i + 1 << endl;
        cout << "Roll NO: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Class: ";
        cin >> Class;
        cout << "Course: ";
        cin >> course;
        cout << "Mobile NO: ";
        cin >> sdt;
        cout << "Admission Year: ";
        cin >> alldiem;

        outFile << id << " " << name << " " << Class << " " << course << " " << sdt << " " << alldiem << endl;
    }

    outFile.close(); 
}

void show() {
    ifstream inFile(OUTPUT_FILE);

    if (!inFile) {
        cerr << "Khong the mo file output.txt." << endl;
        return;
    }
    string id, name, Class, course, sdt, alldiem;
    while (inFile >> id >> name >> Class >> course >> sdt >> alldiem) {
        cout << "\nThong tin sinh vien:" << endl;
        cout << "Roll NO: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << Class << endl;
        cout << "Course: " << course << endl;
        cout << "Mobile NO: " << sdt << endl;
        cout << "Admission Year: " << alldiem << endl;
    }

    inFile.close(); 
}
void search() {
    ifstream inFile(OUTPUT_FILE); 
    if (!inFile) {
        cerr << "Khong the mo file output.txt." << endl;
        return;
    }
    string search_id;
    cout << "Nhap Roll NO cua sinh vien muon tim kiem: ";
    cin >> search_id;

    string id, name, Class, course, sdt, alldiem;
    bool found = false;
    while (inFile >> id >> name >> Class >> course >> sdt >> alldiem) {
        if (id == search_id) {
            found = true;
            cout << "\nThong tin sinh vien:" << endl;
            cout << "Roll NO: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Class: " << Class << endl;
            cout << "Course: " << course << endl;
            cout << "Mobile NO: " << sdt << endl;
            cout << "Admission Year: " << alldiem << endl;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay sinh vien co Roll NO: " << search_id << endl;
    }

    inFile.close();
}

void update() {
    ifstream inFile(OUTPUT_FILE);
    ofstream outFile("temp.txt");

    if (!inFile || !outFile) {
        cerr << "Khong the mo file output.txt hoac temp.txt." << endl;
        return;
    }

    string update_id;
    cout << "Nhap Roll NO cua sinh vien muon cap nhat: ";
    cin >> update_id;

    string id, name, Class, course, sdt, alldiem;
    bool found = false;
    while (inFile >> id >> name >> Class >> course >> sdt >> alldiem) {
        if (id == update_id) {
            found = true;
            cout << "Nhap thong tin moi cho sinh vien:" << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Class: ";
            cin >> Class;
            cout << "Course: ";
            cin >> course;
            cout << "Mobile NO: ";
            cin >> sdt;
            cout << "Admission Year: ";
            cin >> alldiem;

            outFile << id << " " << name << " " << Class << " " << course << " " << sdt << " " << alldiem << endl;
        } else {
           
            outFile << id << " " << name << " " << Class << " " << course << " " << sdt << " " << alldiem << endl;
        }
    }

    inFile.close();
    outFile.close(); 

    remove(OUTPUT_FILE.c_str());

    rename("temp.txt", OUTPUT_FILE.c_str());

    if (!found) {
        cout << "Khong tim thay sinh vien co Roll NO: " << update_id << endl;
    } else {
        cout << "Da cap nhat thanh cong thong tin cho sinh vien co Roll NO: " << update_id << endl;
    }
}

void Delete() {
    ifstream inFile(OUTPUT_FILE); // Mở file output.txt để đọc dữ liệu từ
    ofstream outFile("temp.txt"); // Mở file tạm để ghi dữ liệu vào

    if (!inFile || !outFile) {
        cerr << "Khong the mo file output.txt hoac temp.txt." << endl;
        return;
    }

    string delete_id;
    cout << "Nhap Roll NO cua sinh vien muon xoa: ";
    cin >> delete_id;

    string id, name, Class, course, sdt, alldiem;
    bool found = false;
    while (inFile >> id >> name >> Class >> course >> sdt >> alldiem) {
        if (id == delete_id) {
            found = true;
            cout << "Da xoa thanh cong thong tin cho sinh vien co Roll NO: " << delete_id << endl;
        } else {
            outFile << id << " " << name << " " << Class << " " << course << " " << sdt << " " << alldiem << endl;
        }
    }
    inFile.close(); 
    outFile.close(); 
//    remove(OUTPUT_FILE.c_str());
//
//    rename("temp.txt", OUTPUT_FILE.c_str());

    if (!found) {
        cout << "Khong tim thay sinh vien co Roll NO: " << delete_id << endl;
    }
}

int main() {
    int value;
    while (true) {
        cout << "\nChon chuc nang:" << endl;
        cout << "1. Nhap du lieu" << endl;
        cout << "2. Hien thi du lieu" << endl;
        cout << "3. Tim kiem du lieu" << endl;
        cout << "4. Cap nhat du lieu" << endl;
        cout << "5. Xoa du lieu" << endl;
        cout << "6. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> value;

        switch (value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                Delete();
                break;
            case 6:
                cout << "Ket thuc chuong trinh." << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
                break;
        }
    }

    return 0;
}
