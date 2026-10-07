#include <bits/stdc++.h>
#include <conio.h> 
using namespace std; 
 
// ================================================== 
// CAC HAM KIEM TRA 
// ================================================== 
 
bool kiemTraTaiKhoan(string taiKhoan) 
{ 
    if (taiKhoan.empty() || taiKhoan.length() > 12) 
        return false; 
 
    // Ky tu dau tien phai la chu cai 
    if (!isalpha((unsigned char)taiKhoan[0])) 
        return false; 
 
    // Chi gom chu cai va chu so 
    for (char c : taiKhoan) 
    { 
        if (!isalnum((unsigned char)c)) 
            return false; 
    } 
 
    return true; 
} 
 
 
// ================================================== 
// KIEM TRA MAT KHAU 
// - It nhat 8 ky tu 
// - Co chu hoa 
// - Co chu thuong 
// - Co ky tu dac biet 
// ================================================== 
 
bool kiemTraMatKhau(string matKhau) 
{ 
    bool chuHoa = false; 
    bool chuThuong = false; 
    bool kyTuDacBiet = false; 
 
    if (matKhau.length() < 8) 
        return false; 
 
    if (matKhau.find(' ') != string::npos) 
        return false; 
 
    for (char c : matKhau) 
    { 
        if (isupper((unsigned char)c)) 
            chuHoa = true; 
 
        else if (islower((unsigned char)c)) 
            chuThuong = true; 
 
        else if (ispunct((unsigned char)c)) 
            kyTuDacBiet = true; 
    } 
 
    return chuHoa && chuThuong && kyTuDacBiet; 
} 
 
 
// ================================================== 
// KIEM TRA HO TEN 
// Khong duoc de trong 
// ================================================== 
 
bool kiemTraHoTen(string hoTen) 
{ 
    if (hoTen.empty()) 
        return false; 
 
    // Kiem tra toan bo chuoi co ky tu thuc hay khong 
    bool coKyTu = false; 
 
    for (char c : hoTen) 
    { 
        if (!isspace((unsigned char)c)) 
        { 
            coKyTu = true; 
            break; 
        } 
    } 
 
    return coKyTu; 
} 
 
 
// ================================================== 
// KIEM TRA SO DIEN THOAI 
// Phai gom dung 10 chu so 
// ================================================== 
 
bool kiemTraSDT(string sdt) 
{ 
    if (sdt.length() != 10) 
        return false; 
 
    for (char c : sdt) 
    { 
        if (!isdigit((unsigned char)c)) 
            return false; 
    } 
 
    return true; 
} 
 
 
// ================================================== 
// HAM NHAP MAT KHAU 
// ================================================== 
 
string nhapMatKhau() 
{ 
    string matKhau; 
    char c; 
 
    while (true) 
    { 
        c = _getch(); 
 
        // Enter 
        if (c == 13) 
            break; 
 
        // Backspace 
        if (c == 8) 
        { 
            if (!matKhau.empty()) 
            { 
                matKhau.pop_back(); 
                cout << "\b \b"; 
            } 
        } 
        else 
        { 
            matKhau += c; 
            cout << "*"; 
        } 
    } 
 
    cout << endl; 
 
    return matKhau; 
} 
 
 
// ==================================================
// CLASS NGUOI DUNG 
// ================================================== 
 
class NguoiDung 
{ 
private: 
    string id; 
    string maND; 
    string taiKhoan; 
    string matKhau; 
    string vaiTro; 
    string hoTen; 
    string chucVu; 
    string sdt; 
    string diaChi; 
 
public: 
 
    NguoiDung() {} 
 
 
    NguoiDung( 
        string id, 
        string ma, 
        string tk, 
        string mk, 
        string vt, 
        string ten, 
        string cv, 
        string phone, 
        string dc 
    ) 
        : id(id), 
          maND(ma), 
          taiKhoan(tk), 
          matKhau(mk), 
          vaiTro(vt), 
          hoTen(ten), 
          chucVu(cv), 
          sdt(phone), 
          diaChi(dc) 
    { 
    } 
 
 
    // ================================================== 
    // GETTER 
    // ================================================== 
 
    string getID() 
    { 
        return id; 
    } 
 
    string getMaND() 
    { 
        return maND; 
    } 
 
    string getTaiKhoan() 
    { 
        return taiKhoan; 
    } 
 
    string getMatKhau() 
    { 
        return matKhau; 
    } 
 
    string getVaiTro() 
    { 
        return vaiTro; 
    } 
 
    string getHoTen() 
    { 
        return hoTen; 
    } 
 
    string getChucVu() 
    { 
        return chucVu; 
    } 
 
    string getSDT() 
    { 
        return sdt; 
    } 
 
    string getDiaChi() 
    { 
        return diaChi; 
    } 
 
 
    // ================================================== 
    // SETTER 
    // ================================================== 
 
    void setMatKhau(string mk) 
    { 
        matKhau = mk; 
    } 
 
    void setHoTen(string ten) 
    { 
        hoTen = ten; 
    } 
 
    void setChucVu(string cv) 
    { 
        chucVu = cv; 
    } 
 
    void setSDT(string phone) 
    { 
        sdt = phone; 
    } 
 
    void setDiaChi(string dc) 
    { 
        diaChi = dc; 
    } 
 
 
    // ================================================== 
    // NHAP NGUOI DUNG CHO ADMIN 
    // Chi ADMIN / STAFF 
    // ================================================== 
 
    void nhapAdmin( 
        int stt, 
        vector<NguoiDung>& ds 
    ) 
    { 
        id = "ND" + to_string(stt); 
 
        cout << "\nID tu dong: " << id << endl; 
 
 
        // ================================================== 
        // CHON VAI TRO 
        // ================================================== 
 
        int chonVaiTro; 
 
        do 
        { 
            cout << "\n========== CHON VAI TRO ==========\n"; 
            cout << "1. ADMIN\n"; 
            cout << "2. STAFF\n"; 
            cout << "Chon: "; 
            cin >> chonVaiTro; 
 
            if (chonVaiTro != 1 && chonVaiTro != 2) 
                cout << "Vai tro khong hop le!\n"; 
 
        } while (chonVaiTro != 1 && chonVaiTro != 2); 
 
 
        if (chonVaiTro == 1) 
            vaiTro = "ADMIN"; 
        else 
            vaiTro = "STAFF";
// ================================================== 
        // SINH MA TU DONG 
        // ================================================== 
 
        string prefix; 
 
        if (vaiTro == "ADMIN") 
            prefix = "admin"; 
        else 
            prefix = "staff"; 
 
 
        int soLonNhat = 99999; 
 
        for (auto &nd : ds) 
        { 
            string ma = nd.getMaND(); 
 
            if (ma.find(prefix) == 0) 
            { 
                string phanSo = ma.substr(prefix.length()); 
 
                bool hopLe = true; 
 
                if (phanSo.empty()) 
                    hopLe = false; 
 
                for (char c : phanSo) 
                { 
                    if (!isdigit((unsigned char)c)) 
                    { 
                        hopLe = false; 
                        break; 
                    } 
                } 
 
                if (hopLe) 
                { 
                    int so = atoi(phanSo.c_str()); 
 
                    if (so > soLonNhat) 
                        soLonNhat = so; 
                } 
            } 
        } 
 
        soLonNhat++; 
 
        stringstream ss; 
        ss << soLonNhat; 
 
        maND = prefix + ss.str(); 
 
        cout << "Ma nguoi dung tu dong: " 
             << maND 
             << endl; 
 
 
        // ================================================== 
        // TAI KHOAN 
        // ================================================== 
 
        do 
        { 
            cout << "\nTai khoan (toi da 12 ky tu): "; 
            cin >> taiKhoan; 
 
            if (!kiemTraTaiKhoan(taiKhoan)) 
            { 
                cout << "\nTai khoan khong hop le!\n"; 
                cout << "- Toi da 12 ky tu\n"; 
                cout << "- Ky tu dau tien phai la chu cai\n"; 
                cout << "- Chi gom chu cai va chu so\n"; 
            } 
 
            else if (trungTaiKhoan(ds, taiKhoan)) 
            { 
                cout << "Tai khoan da ton tai!\n"; 
            } 
 
        } while ( 
            !kiemTraTaiKhoan(taiKhoan) || 
            trungTaiKhoan(ds, taiKhoan) 
        ); 
 
 
        // ================================================== 
        // MAT KHAU 
        // ================================================== 
 
        do 
        { 
            cout << "\nMat khau:\n"; 
            cout << "- It nhat 8 ky tu\n"; 
            cout << "- Co chu hoa\n"; 
            cout << "- Co chu thuong\n"; 
            cout << "- Co ky tu dac biet\n"; 
 
            cout << "Nhap mat khau: "; 
 
            matKhau = nhapMatKhau(); 
 
            if (!kiemTraMatKhau(matKhau)) 
            { 
                cout << "\nMat khau khong hop le!\n"; 
            } 
 
        } while (!kiemTraMatKhau(matKhau)); 
 
 
        // ================================================== 
        // HO TEN 
        // ================================================== 
 
        cin.ignore(); 
 
        do 
        {
cout << "\nHo va ten: "; 
            getline(cin, hoTen); 
 
            if (!kiemTraHoTen(hoTen)) 
                cout << "Ho ten khong duoc de trong!\n"; 
 
        } while (!kiemTraHoTen(hoTen)); 
 
 
        // ================================================== 
        // CHUC VU 
        // ================================================== 
 
        int chonChucVu; 
 
        do 
        { 
            cout << "\n========== CHON CHUC VU ==========\n"; 
            cout << "1. Giam doc\n"; 
            cout << "2. Nhan vien\n"; 
            cout << "Chon: "; 
 
            cin >> chonChucVu; 
 
            if (chonChucVu != 1 && chonChucVu != 2) 
                cout << "Chuc vu khong hop le!\n"; 
 
        } while (chonChucVu != 1 && chonChucVu != 2); 
 
 
        if (chonChucVu == 1) 
            chucVu = "Giam doc"; 
        else 
            chucVu = "Nhan vien"; 
 
 
        // ================================================== 
        // SDT 
        // ================================================== 
 
        do 
        { 
            cout << "So dien thoai (10 chu so): "; 
            cin >> sdt; 
 
            if (!kiemTraSDT(sdt)) 
                cout << "SDT khong hop le!\n"; 
 
        } while (!kiemTraSDT(sdt)); 
 
 
        // ================================================== 
        // DIA CHI 
        // ================================================== 
 
        cin.ignore(); 
 
        cout << "Dia chi: "; 
        getline(cin, diaChi); 
    } 
 
 
    // ================================================== 
    // NHAP KHACH HANG 
    // ================================================== 
 
    void nhapKhachHang( 
        int stt, 
        vector<NguoiDung>& ds 
    ) 
    { 
        id = "ND" + to_string(stt); 
 
        cout << "\nID tu dong: " << id << endl; 
 
 
        // CUSTOMER tu dong 
        vaiTro = "CUSTOMER"; 
 
 
        // Sinh ma customer 
        string prefix = "customer"; 
 
        int soLonNhat = 99999; 
 
        for (auto &nd : ds) 
        { 
            string ma = nd.getMaND(); 
 
            if (ma.find(prefix) == 0) 
            { 
                string phanSo = ma.substr(prefix.length()); 
 
                bool hopLe = true; 
 
                if (phanSo.empty()) 
                    hopLe = false; 
 
                for (char c : phanSo) 
                { 
                    if (!isdigit((unsigned char)c)) 
                    { 
                        hopLe = false; 
                        break; 
                    } 
                } 
 
                if (hopLe) 
                { 
                    int so = atoi(phanSo.c_str()); 
 
                    if (so > soLonNhat) 
                        soLonNhat = so; 
                } 
            } 
        } 
 
        soLonNhat++; 
 
        stringstream ss; 
        ss << soLonNhat; 
 
        maND = prefix + ss.str(); 
 
        cout << "Ma nguoi dung tu dong: " 
             << maND 
             << endl;
// ================================================== 
        // TAI KHOAN 
        // ================================================== 
 
        do 
        { 
            cout << "\nTai khoan (toi da 12 ky tu): "; 
            cin >> taiKhoan; 
 
            if (!kiemTraTaiKhoan(taiKhoan)) 
            { 
                cout << "\nTai khoan khong hop le!\n"; 
                cout << "- Toi da 12 ky tu\n"; 
                cout << "- Ky tu dau tien phai la chu cai\n"; 
                cout << "- Chi gom chu cai va chu so\n"; 
            } 
 
            else if (trungTaiKhoan(ds, taiKhoan)) 
            { 
                cout << "Tai khoan da ton tai!\n"; 
            } 
 
        } while ( 
            !kiemTraTaiKhoan(taiKhoan) || 
            trungTaiKhoan(ds, taiKhoan) 
        ); 
 
 
        // ================================================== 
        // MAT KHAU 
        // ================================================== 
 
        do 
        { 
            cout << "\nMat khau:\n"; 
            cout << "- It nhat 8 ky tu\n"; 
            cout << "- Co chu hoa\n"; 
            cout << "- Co chu thuong\n"; 
            cout << "- Co ky tu dac biet\n"; 
 
            cout << "Nhap mat khau: "; 
 
            matKhau = nhapMatKhau(); 
 
            if (!kiemTraMatKhau(matKhau)) 
                cout << "Mat khau khong hop le!\n"; 
 
        } while (!kiemTraMatKhau(matKhau)); 
 
 
        // ================================================== 
        // HO TEN 
        // ================================================== 
 
        cin.ignore(); 
 
        do 
        { 
            cout << "Ho va ten: "; 
            getline(cin, hoTen); 
 
            if (!kiemTraHoTen(hoTen)) 
                cout << "Ho ten khong duoc de trong!\n"; 
 
        } while (!kiemTraHoTen(hoTen)); 
 
 
        // ================================================== 
        // SDT 
        // ================================================== 
 
        do 
        { 
            cout << "So dien thoai (10 chu so): "; 
            getline(cin, sdt); 
 
            if (!kiemTraSDT(sdt)) 
                cout << "SDT phai gom dung 10 chu so!\n"; 
 
        } while (!kiemTraSDT(sdt)); 
 
 
        // ================================================== 
        // DIA CHI 
        // ================================================== 
 
        cout << "Dia chi: "; 
        getline(cin, diaChi); 
 
        chucVu = "Khach hang"; 
    } 
 
 
    // ================================================== 
    // XUAT 
    // ================================================== 
 
    void xuat() 
    { 
        cout << left 
             << setw(8) << id 
             << setw(15) << maND 
             << setw(15) << taiKhoan 
             << setw(12) << vaiTro 
             << setw(25) << hoTen 
             << setw(15) << chucVu 
             << setw(13) << sdt 
             << diaChi 
             << endl; 
    }
// Khai bao truoc ham dung ben trong class 
    static bool trungTaiKhoan( 
        vector<NguoiDung>& ds, 
        string taiKhoan 
    ) 
    { 
        for (auto &nd : ds) 
        { 
            if (nd.getTaiKhoan() == taiKhoan) 
                return true; 
        } 
 
        return false; 
    } 
}; 
 
 
// ================================================== 
// CLASS SAN PHAM 
// ================================================== 
 
class SanPham 
{ 
private: 
    string id; 
    string maSP; 
    string tenSP; 
 
    int soLuong; 
    double donGia; 
 
public: 
 
    SanPham() {} 
 
 
    SanPham( 
        string id, 
        string ma, 
        string ten, 
        int sl, 
        double gia 
    ) 
        : id(id), 
          maSP(ma), 
          tenSP(ten), 
          soLuong(sl), 
          donGia(gia) 
    { 
    } 
 
 
    string getMaSP() 
    { 
        return maSP; 
    } 
 
    string getTenSP() 
    { 
        return tenSP; 
    } 
 
    int getSoLuong() 
    { 
        return soLuong; 
    } 
 
    double getDonGia() 
    { 
        return donGia; 
    } 
 
 
    void setTenSP(string ten) 
    { 
        tenSP = ten; 
    } 
 
    void setSoLuong(int sl) 
    { 
        soLuong = sl; 
    } 
 
    void setDonGia(double gia) 
    { 
        donGia = gia; 
    } 
 
 
    void giamSoLuong(int sl) 
    { 
        soLuong -= sl; 
    } 
 
 
    void tangSoLuong(int sl) 
    { 
        soLuong += sl; 
    } 
 
 
    void nhap(int stt) 
    { 
        id = "SP" + to_string(stt); 
 
        cout << "Ma san pham: "; 
        cin >> maSP; 
 
        cin.ignore(); 
 
        do 
        { 
            cout << "Ten san pham: "; 
            getline(cin, tenSP); 
 
            if (tenSP.empty()) 
                cout << "Ten san pham khong duoc de trong!\n"; 
 
        } while (tenSP.empty()); 
 
        do 
        { 
            cout << "So luong: "; 
            cin >> soLuong; 
 
            if (cin.fail() || soLuong < 0) 
            { 
                cout << "So luong phai la so nguyen khong am!\n"; 
                cin.clear(); 
                cin.ignore(1000, '\n'); 
            } 
 
        } while (cin.fail() || soLuong < 0); 
 
 
        do 
        { 
            cout << "Don gia: "; 
            cin >> donGia; 
 
            if (cin.fail() || donGia < 0) 
            { 
                cout << "Don gia phai la so thuc khong am!\n"; 
                cin.clear(); 
                cin.ignore(1000, '\n'); 
            } 
 
        } while (cin.fail() || donGia < 0); 
    } 
 
 
    void xuat() 
    { 
        cout << left 
             << setw(8) << id 
             << setw(15) << maSP 
             << setw(30) << tenSP 
             << setw(12) << soLuong 
             << fixed 
             << setprecision(0) 
             << donGia 
             << endl; 
    } 
}; 
 
 
// ================================================== 
// CLASS CHI TIET GIO HANG 
// ==================================================
class ChiTietGioHang 
{ 
private: 
    string maSP; 
    string tenSP; 
    int soLuong; 
    double donGia; 
 
public: 
 
    ChiTietGioHang() {} 
 
 
    ChiTietGioHang( 
        string ma, 
        string ten, 
        int sl, 
        double gia 
    ) 
        : maSP(ma), 
          tenSP(ten), 
          soLuong(sl), 
          donGia(gia) 
    { 
    } 
 
 
    string getMaSP() 
    { 
        return maSP; 
    } 
 
    string getTenSP() 
    { 
        return tenSP; 
    } 
 
    int getSoLuong() 
    { 
        return soLuong; 
    } 
 
    double getDonGia() 
    { 
        return donGia; 
    } 
 
 
    void tangSoLuong(int sl) 
    { 
        soLuong += sl; 
    } 
 
 
    double thanhTien() 
    { 
        return soLuong * donGia; 
    } 
}; 
 
 
// ================================================== 
// CLASS DON HANG 
// ================================================== 
 
class DonHang 
{ 
private: 
    string maDH; 
    string hoTen; 
    string sdt; 
    string diaChi; 
 
    vector<ChiTietGioHang> chiTiet; 
 
    double tongTien; 
 
public: 
 
    DonHang() {} 
 
 
    DonHang( 
        string ma, 
        string ten, 
        string phone, 
        string dc, 
        vector<ChiTietGioHang> gioHang 
    ) 
        : maDH(ma), 
          hoTen(ten), 
          sdt(phone), 
          diaChi(dc), 
          chiTiet(gioHang) 
    { 
        tongTien = 0; 
 
        for (auto &ct : chiTiet) 
            tongTien += ct.thanhTien(); 
    } 
 
 
    void xuat() 
    { 
        cout << "\n========================================\n"; 
        cout << "Ma don hang: " << maDH << endl; 
        cout << "Ho ten: " << hoTen << endl; 
        cout << "SDT: " << sdt << endl; 
        cout << "Dia chi: " << diaChi << endl; 
 
        cout << "\n----------- CHI TIET DON HANG -----------\n"; 
 
        cout << left 
             << setw(15) << "Ma SP" 
             << setw(30) << "Ten SP" 
             << setw(12) << "So luong" 
             << setw(15) << "Don gia" 
             << "Thanh tien" 
             << endl; 
 
        cout << string(90, '-') << endl; 
 
        for (auto &ct : chiTiet) 
        { 
            cout << left 
                 << setw(15) << ct.getMaSP() 
                 << setw(30) << ct.getTenSP() 
                 << setw(12) << ct.getSoLuong() 
                 << setw(15) 
                 << fixed 
                 << setprecision(0) 
                 << ct.getDonGia() 
                 << ct.thanhTien() 
                 << endl; 
        } 
 
        cout << string(90, '-') << endl; 
 
        cout << "Tong tien: " 
             << fixed 
             << setprecision(0) 
             << tongTien 
             << " VND" 
             << endl; 
    } 
}; 
 
 
// ================================================== 
// KIEM TRA TAI KHOAN TRUNG 
// ================================================== 
 
bool trungTaiKhoan( 
    vector<NguoiDung>& ds, 
    string taiKhoan 
) 
{ 
    for (auto &nd : ds) 
    {
if (nd.getTaiKhoan() == taiKhoan) 
            return true; 
    } 
 
    return false; 
} 
 
 
// ================================================== 
// QUAN LY SAN PHAM 
// ================================================== 
 
void xemSanPham(vector<SanPham>& ds) 
{ 
    if (ds.empty()) 
    { 
        cout << "\nDanh sach san pham rong!\n"; 
        return; 
    } 
 
    cout << "\n========== DANH SACH SAN PHAM ==========\n"; 
 
    cout << left 
         << setw(8) << "ID" 
         << setw(15) << "Ma SP" 
         << setw(30) << "Ten SP" 
         << setw(12) << "So luong" 
         << "Don gia" 
         << endl; 
 
    cout << string(80, '-') << endl; 
 
    for (auto &sp : ds) 
        sp.xuat(); 
} 
 
 
// ================================================== 
// THEM SAN PHAM 
// ================================================== 
 
void themSanPham(vector<SanPham>& ds) 
{ 
    SanPham sp; 
 
    sp.nhap(ds.size() + 1); 
 
    ds.push_back(sp); 
 
    cout << "\nThem san pham thanh cong!\n"; 
} 
 
 
// ================================================== 
// XOA SAN PHAM 
// ================================================== 
 
void xoaSanPham(vector<SanPham>& ds) 
{ 
    string ma; 
 
    cout << "Nhap ma san pham can xoa: "; 
    cin >> ma; 
 
    for (int i = 0; i < (int)ds.size(); i++) 
    { 
        if (ds[i].getMaSP() == ma) 
        { 
            char xacNhan; 
 
            cout << "Ban co chac chan muon xoa? (Y/N): "; 
            cin >> xacNhan; 
 
            if (xacNhan == 'Y' || xacNhan == 'y') 
            { 
                ds.erase(ds.begin() + i); 
 
                cout << "Xoa san pham thanh cong!\n"; 
            } 
            else 
            { 
                cout << "Da huy xoa.\n"; 
            } 
 
            return; 
        } 
    } 
 
    cout << "Khong tim thay san pham!\n"; 
} 
 
 
// ================================================== 
// SUA SAN PHAM 
// ================================================== 
 
void suaSanPham(vector<SanPham>& ds) 
{ 
    if (ds.empty()) 
    { 
        cout << "\nDanh sach san pham rong!\n"; 
        return; 
    } 
 
    xemSanPham(ds); 
 
    string ma; 
 
    cout << "\nNhap ma san pham can sua: "; 
    cin >> ma; 
 
    int viTri = -1; 
 
    for (int i = 0; i < (int)ds.size(); i++) 
    { 
        if (ds[i].getMaSP() == ma) 
        { 
            viTri = i; 
            break; 
        } 
    } 
 
    if (viTri == -1) 
    { 
        cout << "Khong tim thay san pham!\n"; 
        return; 
    } 
 
    cin.ignore(); 
 
    string tenMoi; 
    int soLuongMoi; 
    double donGiaMoi; 
 
    do 
    { 
        cout << "Ten san pham moi: "; 
        getline(cin, tenMoi); 
 
        if (tenMoi.empty()) 
            cout << "Ten san pham khong duoc de trong!\n"; 
 
    } while (tenMoi.empty()); 
 
    do 
    { 
        cout << "So luong moi: "; 
        cin >> soLuongMoi; 
 
        if (cin.fail() || soLuongMoi < 0) 
        {
cout << "So luong phai la so nguyen khong am!\n"; 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
        } 
 
    } while (cin.fail() || soLuongMoi < 0); 
 
    do 
    { 
        cout << "Don gia moi: "; 
        cin >> donGiaMoi; 
 
        if (cin.fail() || donGiaMoi < 0) 
        { 
            cout << "Don gia phai la so thuc khong am!\n"; 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
        } 
 
    } while (cin.fail() || donGiaMoi < 0); 
 
    char xacNhan; 
 
    cout << "\nBan co chac chan muon sua san pham nay? (Y/N): "; 
    cin >> xacNhan; 
 
    if (xacNhan == 'Y' || xacNhan == 'y') 
    { 
        ds[viTri].setTenSP(tenMoi); 
        ds[viTri].setSoLuong(soLuongMoi); 
        ds[viTri].setDonGia(donGiaMoi); 
 
        cout << "\nSua san pham thanh cong!\n"; 
    } 
    else 
    { 
        cout << "\nDa huy thao tac sua.\n"; 
    } 
} 
 
 
// ================================================== 
// MENU SAN PHAM 
// ================================================== 
 
void menuSanPham(vector<SanPham>& ds) 
{ 
    int chon; 
 
    do 
    { 
        cout << "\n========== QUAN LY SAN PHAM ==========\n"; 
        cout << "1. Them san pham\n"; 
        cout << "2. Xem san pham\n"; 
        cout << "3. Sua san pham\n"; 
        cout << "4. Xoa san pham\n"; 
        cout << "0. Quay lai\n"; 
        cout << "Chon: "; 
 
        cin >> chon; 
 
        if (chon == 1) 
            themSanPham(ds); 
 
        else if (chon == 2) 
            xemSanPham(ds); 
 
        else if (chon == 3) 
            suaSanPham(ds); 
 
        else if (chon == 4) 
            xoaSanPham(ds); 
 
        else if (chon != 0) 
            cout << "Lua chon khong hop le!\n"; 
 
    } while (chon != 0); 
} 
 
 
// ================================================== 
// XEM NGUOI DUNG 
// ================================================== 
 
void xemNguoiDung(vector<NguoiDung>& ds) 
{ 
    if (ds.empty()) 
    { 
        cout << "\nDanh sach nguoi dung rong!\n"; 
        return; 
    } 
 
    cout << "\n========== DANH SACH NGUOI DUNG ==========\n"; 
 
    cout << left 
         << setw(8) << "ID" 
         << setw(15) << "Ma ND" 
         << setw(15) << "Tai khoan" 
         << setw(12) << "Vai tro" 
         << setw(25) << "Ho ten" 
         << setw(15) << "Chuc vu" 
         << setw(13) << "SDT" 
         << "Dia chi" 
         << endl; 
 
    cout << string(120, '-') << endl; 
 
    for (auto &nd : ds) 
        nd.xuat(); 
} 
 
 
// ================================================== 
// THEM ADMIN / STAFF 
// ================================================== 
 
void themNguoiDungAdmin( 
    vector<NguoiDung>& ds 
) 
{ 
    NguoiDung nd; 
 
    nd.nhapAdmin( 
        ds.size() + 1, 
        ds 
    ); 
 
    ds.push_back(nd); 
 
    cout << "\nThem nguoi dung thanh cong!\n"; 
} 
 
 
// ================================================== 
// DANG KY CUSTOMER 
// ==================================================
void dangKyCustomer( 
    vector<NguoiDung>& ds 
) 
{ 
    NguoiDung nd; 
 
    nd.nhapKhachHang( 
        ds.size() + 1, 
        ds 
    ); 
 
    ds.push_back(nd); 
 
    cout << "\nDang ky tai khoan CUSTOMER thanh cong!\n"; 
} 
 
 
// ================================================== 
// DANG NHAP 
// ================================================== 
 
int dangNhap( 
    vector<NguoiDung>& ds 
) 
{ 
    string tk; 
    string mk; 
 
    cout << "\n========== DANG NHAP ==========\n"; 
 
    cout << "Tai khoan: "; 
    cin >> tk; 
 
    cout << "Mat khau: "; 
    mk = nhapMatKhau(); 
 
    for (int i = 0; i < (int)ds.size(); i++) 
    { 
        if ( 
            ds[i].getTaiKhoan() == tk && 
            ds[i].getMatKhau() == mk 
        ) 
        { 
            return i; 
        } 
    } 
 
    return -1; 
} 
 
 
// ================================================== 
// THEM SAN PHAM VAO GIO HANG 
// ================================================== 
 
void themVaoGioHang( 
    vector<SanPham>& dsSanPham, 
    vector<ChiTietGioHang>& gioHang 
) 
{ 
    if (dsSanPham.empty()) 
    { 
        cout << "\nDanh sach san pham rong!\n"; 
        return; 
    } 
 
    xemSanPham(dsSanPham); 
 
    string ma; 
    int soLuong; 
 
    cout << "\nNhap ma san pham muon mua: "; 
    cin >> ma; 
 
    int viTri = -1; 
 
    for (int i = 0; i < (int)dsSanPham.size(); i++) 
    { 
        if (dsSanPham[i].getMaSP() == ma) 
        { 
            viTri = i; 
            break; 
        } 
    } 
 
    if (viTri == -1) 
    { 
        cout << "\nKhong tim thay san pham!\n"; 
        return; 
    } 
 
    cout << "Nhap so luong muon mua: "; 
    cin >> soLuong; 
 
    if (soLuong <= 0) 
    { 
        cout << "\nSo luong khong hop le!\n"; 
        return; 
    } 
 
    // So luong dang co trong gio hang 
    int dangCo = 0; 
 
    for (auto &ct : gioHang) 
    { 
        if (ct.getMaSP() == ma) 
        { 
            dangCo = ct.getSoLuong(); 
            break; 
        } 
    } 
 
    if (dangCo + soLuong > dsSanPham[viTri].getSoLuong()) 
    { 
        cout << "\nKhong du so luong trong kho!\n"; 
        cout << "So luong hien co: " 
             << dsSanPham[viTri].getSoLuong() 
             << endl; 
 
        return; 
    } 
 
    // Neu san pham da co trong gio hang 
    for (auto &ct : gioHang) 
    { 
        if (ct.getMaSP() == ma) 
        { 
            ct.tangSoLuong(soLuong); 
 
            cout << "\nDa them them san pham vao gio hang!\n"; 
            return; 
        } 
    } 
 
    ChiTietGioHang ct( 
        dsSanPham[viTri].getMaSP(), 
        dsSanPham[viTri].getTenSP(), 
        soLuong, 
        dsSanPham[viTri].getDonGia() 
    ); 
 
    gioHang.push_back(ct); 
 
    cout << "\nThem san pham vao gio hang thanh cong!\n"; 
} 
 
 
// ================================================== 
// XEM GIO HANG 
// ================================================== 
 
void xemGioHang( 
    vector<ChiTietGioHang>& gioHang 
) 
{
if (gioHang.empty()) 
    { 
        cout << "\nGio hang dang rong!\n"; 
        return; 
    } 
 
    double tongTien = 0; 
 
    cout << "\n========== GIO HANG ==========\n"; 
 
    cout << left 
         << setw(15) << "Ma SP" 
         << setw(30) << "Ten SP" 
         << setw(12) << "So luong" 
         << setw(15) << "Don gia" 
         << "Thanh tien" 
         << endl; 
 
    cout << string(90, '-') << endl; 
 
    for (auto &ct : gioHang) 
    { 
        cout << left 
             << setw(15) << ct.getMaSP() 
             << setw(30) << ct.getTenSP() 
             << setw(12) << ct.getSoLuong() 
             << setw(15) 
             << fixed 
             << setprecision(0) 
             << ct.getDonGia() 
             << ct.thanhTien() 
             << endl; 
 
        tongTien += ct.thanhTien(); 
    } 
 
    cout << string(90, '-') << endl; 
 
    cout << "Tong tien: " 
         << fixed 
         << setprecision(0) 
         << tongTien 
         << " VND" 
         << endl; 
} 
 
 
// ================================================== 
// DAT MUA 
// ================================================== 
 
void datMua( 
    vector<ChiTietGioHang>& gioHang, 
    vector<SanPham>& dsSanPham, 
    vector<DonHang>& dsDonHang, 
    vector<NguoiDung>& dsNguoiDung, 
    int viTriNguoiDung 
) 
{ 
    if (gioHang.empty()) 
    { 
        cout << "\nGio hang dang rong!\n"; 
        cout << "Vui long them san pham vao gio hang truoc.\n"; 
        return; 
    } 
 
    string hoTen; 
    string sdt; 
    string diaChi; 
 
 
    // ================================================== 
    // KHACH DA DANG NHAP 
    // ================================================== 
 
    if (viTriNguoiDung != -1) 
    { 
        hoTen = dsNguoiDung[viTriNguoiDung].getHoTen(); 
        sdt = dsNguoiDung[viTriNguoiDung].getSDT(); 
        diaChi = dsNguoiDung[viTriNguoiDung].getDiaChi(); 
 
        cout << "\n========== THONG TIN DAT HANG ==========\n"; 
 
        cout << "Ho ten: " << hoTen << endl; 
        cout << "SDT: " << sdt << endl; 
        cout << "Dia chi: " << diaChi << endl; 
    } 
 
 
    // ================================================== 
    // KHACH CHUA DANG NHAP 
    // ================================================== 
 
    else 
    { 
        cin.ignore(); 
 
        cout << "\n========== THONG TIN DAT HANG ==========\n"; 
 
        do 
        { 
            cout << "Ho ten: "; 
            getline(cin, hoTen); 
 
            if (!kiemTraHoTen(hoTen)) 
                cout << "Ho ten khong duoc de trong!\n"; 
 
        } while (!kiemTraHoTen(hoTen)); 
 
 
        do 
        { 
            cout << "So dien thoai: "; 
            getline(cin, sdt); 
 
            if (!kiemTraSDT(sdt)) 
                cout << "SDT phai gom dung 10 chu so!\n"; 
 
        } while (!kiemTraSDT(sdt)); 
 
 
        cout << "Dia chi: "; 
        getline(cin, diaChi); 
    } 
 
 
    // ==================================================
// KIEM TRA TON KHO 
    // ================================================== 
 
    for (auto &ct : gioHang) 
    { 
        bool timThay = false; 
 
        for (auto &sp : dsSanPham) 
        { 
            if (sp.getMaSP() == ct.getMaSP()) 
            { 
                timThay = true; 
 
                if (ct.getSoLuong() > sp.getSoLuong()) 
                { 
                    cout << "\nSan pham " 
                         << ct.getMaSP() 
                         << " khong du so luong trong kho!\n"; 
 
                    return; 
                } 
 
                break; 
            } 
        } 
 
        if (!timThay) 
        { 
            cout << "\nSan pham " 
                 << ct.getMaSP() 
                 << " khong con ton tai!\n"; 
 
            return; 
        } 
    } 
 
 
    // ================================================== 
    // MA DON HANG 
    // ================================================== 
 
    string maDH = 
        "DH" + to_string(dsDonHang.size() + 1); 
 
 
    // ================================================== 
    // TAO DON HANG 
    // ================================================== 
 
    DonHang dh( 
        maDH, 
        hoTen, 
        sdt, 
        diaChi, 
        gioHang 
    ); 
 
 
    dsDonHang.push_back(dh); 
 
 
    // ================================================== 
    // TRU SO LUONG KHO 
    // ================================================== 
 
    for (auto &ct : gioHang) 
    { 
        for (auto &sp : dsSanPham) 
        { 
            if (sp.getMaSP() == ct.getMaSP()) 
            { 
                sp.giamSoLuong(ct.getSoLuong()); 
                break; 
            } 
        } 
    } 
 
 
    // ================================================== 
    // THONG BAO 
    // ================================================== 
 
    cout << "\n========================================\n"; 
    cout << "          DAT HANG THANH CONG!\n"; 
    cout << "========================================\n"; 
 
    dsDonHang.back().xuat(); 
 
 
    gioHang.clear(); 
} 
 
 
// ================================================== 
// MENU KHACH HANG 
// ================================================== 
 
void menuKhachHang( 
    vector<SanPham>& dsSanPham, 
    vector<NguoiDung>& dsNguoiDung, 
    vector<DonHang>& dsDonHang 
) 
{ 
    int chon; 
 
    int viTriNguoiDung = -1; 
 
    vector<ChiTietGioHang> gioHang; 
 
 
    do 
    { 
        cout << "\n"; 
        cout << "========================================\n"; 
        cout << "              KHACH HANG\n"; 
        cout << "========================================\n"; 
 
 
        if (viTriNguoiDung != -1) 
        { 
            cout << "Tai khoan: " 
                 << dsNguoiDung[viTriNguoiDung].getTaiKhoan() 
                 << endl; 
 
            cout << "Trang thai: DA DANG NHAP\n"; 
        } 
        else 
        { 
            cout << "Trang thai: CHUA DANG NHAP\n"; 
        }
cout << "\n"; 
        cout << "1. Xem danh sach san pham\n"; 
        cout << "2. Chon mua san pham\n"; 
        cout << "3. Xem gio hang\n"; 
        cout << "4. Dat mua\n"; 
        cout << "5. Dang ky tai khoan\n"; 
        cout << "6. Dang nhap\n"; 
        cout << "0. Quay lai\n"; 
 
        cout << "\nChon: "; 
        cin >> chon; 
 
 
        if (chon == 1) 
        { 
            xemSanPham(dsSanPham); 
        } 
 
 
        else if (chon == 2) 
        { 
            themVaoGioHang( 
                dsSanPham, 
                gioHang 
            ); 
        } 
 
 
        else if (chon == 3) 
        { 
            xemGioHang(gioHang); 
        } 
 
 
        else if (chon == 4) 
        { 
            datMua( 
                gioHang, 
                dsSanPham, 
                dsDonHang, 
                dsNguoiDung, 
                viTriNguoiDung 
            ); 
        } 
 
 
        else if (chon == 5) 
        { 
            cout << "\n========== DANG KY CUSTOMER ==========\n"; 
 
            dangKyCustomer(dsNguoiDung); 
        } 
 
 
        else if (chon == 6) 
        { 
            int vt = dangNhap(dsNguoiDung); 
 
            if (vt == -1) 
            { 
                cout << "\nSai tai khoan hoac mat khau!\n"; 
            } 
            else if ( 
                dsNguoiDung[vt].getVaiTro() == "CUSTOMER" 
            ) 
            { 
                viTriNguoiDung = vt; 
 
                cout << "\nDang nhap khach hang thanh cong!\n"; 
            } 
            else 
            { 
                cout << "\nTai khoan nay khong phai CUSTOMER!\n"; 
            } 
        } 
 
 
        else if (chon != 0) 
        { 
            cout << "\nLua chon khong hop le!\n"; 
        } 
 
    } while (chon != 0); 
} 
 
 
// ================================================== 
// XOA NGUOI DUNG 
// ================================================== 
 
void xoaNguoiDung( 
    vector<NguoiDung>& ds, 
    int viTriAdmin 
) 
{ 
    if (ds.empty()) 
    { 
        cout << "\nDanh sach rong!\n"; 
        return; 
    } 
 
 
    xemNguoiDung(ds); 
 
 
    string tk; 
 
    cout << "\nNhap tai khoan can xoa: "; 
    cin >> tk; 
 
 
    int viTri = -1; 
 
    for (int i = 0; i < (int)ds.size(); i++) 
    { 
        if (ds[i].getTaiKhoan() == tk) 
        { 
            viTri = i; 
            break; 
        } 
    } 
 
 
    if (viTri == -1) 
    { 
        cout << "Khong tim thay nguoi dung!\n"; 
        return; 
    } 
 
 
    // Khong cho admin xoa chinh minh 
    if (viTri == viTriAdmin) 
    { 
        cout << "\nKhong the xoa tai khoan ADMIN dang dang nhap!\n"; 
        return; 
    } 
 
 
    // Xac nhan 
    char xacNhan; 
 
    cout << "\nBan co chac chan muon xoa tai khoan nay? (Y/N): "; 
    cin >> xacNhan; 
 
 
    if (xacNhan == 'Y' || xacNhan == 'y') 
    { 
        ds.erase(ds.begin() + viTri); 
 
        cout << "\nXoa nguoi dung thanh cong!\n"; 
    } 
    else 
    {
cout << "\nDa huy thao tac xoa.\n"; 
    } 
} 
 
 
// ================================================== 
// SUA NGUOI DUNG 
// ================================================== 
 
void suaNguoiDung( 
    vector<NguoiDung>& ds, 
    int viTriAdmin 
) 
{ 
    if (ds.empty()) 
    { 
        cout << "\nDanh sach nguoi dung rong!\n"; 
        return; 
    } 
 
 
    xemNguoiDung(ds); 
 
 
    string tk; 
 
    cout << "\nNhap tai khoan can sua: "; 
    cin >> tk; 
 
 
    int viTri = -1; 
 
    for (int i = 0; i < (int)ds.size(); i++) 
    { 
        if (ds[i].getTaiKhoan() == tk) 
        { 
            viTri = i; 
            break; 
        } 
    } 
 
 
    if (viTri == -1) 
    { 
        cout << "Khong tim thay nguoi dung!\n"; 
        return; 
    } 
 
 
    cout << "\n========== THONG TIN NGUOI DUNG ==========\n"; 
    cout << "Tai khoan: " 
         << ds[viTri].getTaiKhoan() 
         << endl; 
 
    cout << "Vai tro: " 
         << ds[viTri].getVaiTro() 
         << endl; 
 
 
    // ================================================== 
    // SUA HO TEN 
    // ================================================== 
 
    cin.ignore(); 
 
    string tenMoi; 
 
    do 
    { 
        cout << "\nHo ten moi: "; 
        getline(cin, tenMoi); 
 
        if (!kiemTraHoTen(tenMoi)) 
            cout << "Ho ten khong duoc de trong!\n"; 
 
    } while (!kiemTraHoTen(tenMoi)); 
 
 
    // ================================================== 
    // SUA MAT KHAU 
    // ================================================== 
 
    string mkMoi; 
 
    do 
    { 
        cout << "\nMat khau moi: "; 
 
        mkMoi = nhapMatKhau(); 
 
        if (!kiemTraMatKhau(mkMoi)) 
            cout << "Mat khau khong hop le!\n"; 
 
    } while (!kiemTraMatKhau(mkMoi)); 
 
 
    // ================================================== 
    // SUA CHUC VU 
    // ================================================== 
 
    int chonCV; 
 
    do 
    { 
        cout << "\n========== CHON CHUC VU ==========\n"; 
        cout << "1. Giam doc\n"; 
        cout << "2. Nhan vien\n"; 
        cout << "Chon: "; 
 
        cin >> chonCV; 
 
    } while (chonCV != 1 && chonCV != 2); 
 
 
    string cvMoi; 
 
    if (chonCV == 1) 
        cvMoi = "Giam doc"; 
    else 
        cvMoi = "Nhan vien"; 
 
 
    // ================================================== 
    // SUA SDT 
    // ================================================== 
 
    string sdtMoi; 
 
    do 
    { 
        cout << "SDT moi: "; 
        cin >> sdtMoi; 
 
        if (!kiemTraSDT(sdtMoi)) 
            cout << "SDT phai gom dung 10 chu so!\n"; 
 
    } while (!kiemTraSDT(sdtMoi)); 
 
 
    // ================================================== 
    // SUA DIA CHI 
    // ================================================== 
 
    cin.ignore(); 
 
    string diaChiMoi; 
 
    cout << "Dia chi moi: "; 
    getline(cin, diaChiMoi); 
 
 
    // ================================================== 
    // XAC NHAN
// ================================================== 
 
    char xacNhan; 
 
    cout << "\nBan co chac chan muon luu thay doi? (Y/N): "; 
    cin >> xacNhan; 
 
 
    if (xacNhan == 'Y' || xacNhan == 'y') 
    { 
        ds[viTri].setHoTen(tenMoi); 
        ds[viTri].setMatKhau(mkMoi); 
        ds[viTri].setChucVu(cvMoi); 
        ds[viTri].setSDT(sdtMoi); 
        ds[viTri].setDiaChi(diaChiMoi); 
 
        cout << "\nSua thong tin thanh cong!\n"; 
    } 
    else 
    { 
        cout << "\nDa huy thao tac sua.\n"; 
    } 
} 
 
 
// ================================================== 
// XEM DON HANG 
// ================================================== 
 
void xemDonHang( 
    vector<DonHang>& dsDonHang 
) 
{ 
    if (dsDonHang.empty()) 
    { 
        cout << "\nChua co don hang nao!\n"; 
        return; 
    } 
 
 
    cout << "\n========== DANH SACH DON HANG ==========\n"; 
 
 
    for (auto &dh : dsDonHang) 
    { 
        dh.xuat(); 
 
        cout << endl; 
    } 
} 
 
 
// ================================================== 
// MENU ADMIN 
// ================================================== 
 
void menuAdmin( 
    vector<NguoiDung>& nd, 
    vector<SanPham>& sp, 
    vector<DonHang>& dsDonHang, 
    int viTriAdmin 
) 
{ 
    int chon; 
 
 
    do 
    { 
        cout << "\n"; 
        cout << "========================================\n"; 
        cout << "              MENU ADMIN\n"; 
        cout << "========================================\n"; 
 
        cout << "1. Them nguoi dung ADMIN / STAFF\n"; 
        cout << "2. Xem danh sach nguoi dung\n"; 
        cout << "3. Xoa nguoi dung\n"; 
        cout << "4. Sua nguoi dung\n"; 
        cout << "5. Xem danh sach don hang\n"; 
        cout << "6. Xem danh sach san pham\n"; 
        cout << "7. Quan ly san pham\n"; 
        cout << "0. Dang xuat\n"; 
 
        cout << "Chon: "; 
        cin >> chon; 
 
 
        // ================================================== 
        // THEM ADMIN / STAFF 
        // ================================================== 
 
        if (chon == 1) 
        { 
            themNguoiDungAdmin(nd); 
        } 
 
 
        // ================================================== 
        // XEM NGUOI DUNG 
        // ================================================== 
 
        else if (chon == 2) 
        { 
            xemNguoiDung(nd); 
        } 
 
 
        // ================================================== 
        // XOA NGUOI DUNG 
        // ================================================== 
 
        else if (chon == 3) 
        { 
            xoaNguoiDung( 
                nd, 
                viTriAdmin 
            ); 
        } 
 
 
        // ================================================== 
        // SUA NGUOI DUNG 
        // ================================================== 
 
        else if (chon == 4) 
        { 
            suaNguoiDung( 
                nd, 
                viTriAdmin 
            ); 
        }
// ================================================== 
        // XEM DON HANG 
        // ================================================== 
 
        else if (chon == 5) 
        { 
            xemDonHang(dsDonHang); 
        } 
 
 
        // ================================================== 
        // XEM SAN PHAM 
        // ================================================== 
 
        else if (chon == 6) 
        { 
            xemSanPham(sp); 
        } 
 
 
        // ================================================== 
        // QUAN LY SAN PHAM 
        // ================================================== 
 
        else if (chon == 7) 
        { 
            menuSanPham(sp); 
        } 
 
 
        else if (chon != 0) 
        { 
            cout << "\nLua chon khong hop le!\n"; 
        } 
 
    } while (chon != 0); 
} 
 
 
// ================================================== 
// MENU STAFF 
// ================================================== 
 
void menuStaff( 
    vector<SanPham>& sp 
) 
{ 
    cout << "\nDang nhap quyen STAFF thanh cong!\n"; 
 
    menuSanPham(sp); 
} 
 
 
// ================================================== 
// MAIN 
// ================================================== 
 
int main() 
{ 
    // ================================================== 
    // TAI KHOAN MAC DINH 
    // ================================================== 
 
    vector<NguoiDung> dsNguoiDung = 
    { 
        NguoiDung( 
            "ND1", 
            "admin100000", 
            "admin", 
            "Admin@123", 
            "ADMIN", 
            "Quan tri vien", 
            "Giam doc", 
            "0900000000", 
            "Ha Noi" 
        ), 
 
        NguoiDung( 
            "ND2", 
            "staff100000", 
            "staff", 
            "Staff@123", 
            "STAFF", 
            "Nhan vien", 
            "Nhan vien", 
            "0911111111", 
            "Ha Noi" 
        ) 
    }; 
 
 
    // ================================================== 
    // SAN PHAM MAU 
    // ================================================== 
 
    vector<SanPham> dsSanPham = 
    { 
        SanPham( 
            "SP1", 
            "SP001", 
            "Laptop Dell", 
            10, 
            15000000 
        ), 
 
        SanPham( 
            "SP2", 
            "SP002", 
            "Ban phim", 
            20, 
            500000 
        ), 
 
        SanPham( 
            "SP3", 
            "SP003", 
            "Chuot", 
            30, 
            300000 
        ) 
    }; 
 
 
    // ================================================== 
    // DANH SACH DON HANG 
    // ================================================== 
 
    vector<DonHang> dsDonHang; 
 
 
    // ================================================== 
    // MENU CHINH 
    // ================================================== 
 
    int chon; 
 
 
    do 
    { 
        cout << "\n"; 
        cout << "========================================\n";
cout << "       HE THONG QUAN LY BAN HANG\n"; 
        cout << "========================================\n"; 
 
        cout << "1. Quan tri\n"; 
        cout << "2. Khach hang\n"; 
        cout << "0. Thoat\n"; 
 
        cout << "Chon: "; 
        cin >> chon; 
 
 
        // ================================================== 
        // QUAN TRI 
        // ================================================== 
 
        if (chon == 1) 
        { 
            int loai; 
 
 
            cout << "\n========== QUAN TRI ==========\n"; 
 
            cout << "1. Admin\n"; 
            cout << "2. Staff\n"; 
            cout << "0. Quay lai\n"; 
 
            cout << "Chon: "; 
            cin >> loai; 
 
 
            if (loai == 1 || loai == 2) 
            { 
                int vt = dangNhap(dsNguoiDung); 
 
 
                if (vt == -1) 
                { 
                    cout << "\nSai tai khoan hoac mat khau!\n"; 
                } 
 
 
                // ================================================== 
                // ADMIN 
                // ================================================== 
 
                else if ( 
                    loai == 1 && 
                    dsNguoiDung[vt].getVaiTro() == "ADMIN" 
                ) 
                { 
                    cout << "\nDang nhap ADMIN thanh cong!\n"; 
 
                    menuAdmin( 
                        dsNguoiDung, 
                        dsSanPham, 
                        dsDonHang, 
                        vt 
                    ); 
                } 
 
 
                // ================================================== 
                // STAFF 
                // ================================================== 
 
                else if ( 
                    loai == 2 && 
                    dsNguoiDung[vt].getVaiTro() == "STAFF" 
                ) 
                { 
                    menuStaff(dsSanPham); 
                } 
 
 
                else 
                { 
                    cout << "\nTai khoan khong dung vai tro!\n"; 
                } 
            } 
        } 
 
 
        // ================================================== 
        // KHACH HANG 
        // ================================================== 
 
        else if (chon == 2) 
        { 
            menuKhachHang( 
                dsSanPham, 
                dsNguoiDung, 
                dsDonHang 
            ); 
        } 
 
 
        else if (chon != 0) 
        { 
            cout << "\nLua chon khong hop le!\n"; 
        } 
 
    } while (chon != 0); 
 
 
    cout << "\nCam on ban da su dung chuong trinh!\n"; 
 
 
    return 0; 
}
