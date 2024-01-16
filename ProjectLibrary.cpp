#include <iostream>
#include <vector>
using namespace std;

struct Normal 
{
public:
    string userid;
    string username;
    Normal(string id, string name)
        : userid(id), username(name) {}

    virtual void nhapThongTin() 
	{
        cout << "Nhap ID: ";
        cin >> userid;

        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, username);
    }

    virtual void hienThiThongTin() const 
	{
		cout <<"\n--------------------------------------------------------"<<endl;
        cout << "User ID: " << userid << "| User name: " << username << "| Class: Normal " <<endl;
        cout <<"--------------------------------------------------------"<<endl;
    }
    virtual ~Normal() {}
    
};

struct Admin
{
public:
    string userid;
    string username;

    string password;

    Admin(string id, string name, string pass)
        : userid(id), username(name), password(pass) {}

    virtual void nhapThongTinAdmin() 
	{
        cout << "Nhap ID: ";
        cin.ignore();
        cin >> userid;

        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, username);
   
		cout << "Nhap password: ";
        cin>>password;
    }

    virtual void hienThiThongTinAdmin() const 
	{
		cout<<"\n----------------------------------------------------------------------"<<endl;
        cout << "User ID: " << userid << "| User name: " << username << "| Class: Admin " <<endl;
        cout<<"----------------------------------------------------------------------"<<endl;
    }
	
    virtual ~Admin() {}
    
};

struct Book 
{
	public:
		string isbn;
		string title;
		string subject;
		string author;
		string publisher;
		string date;
		int pages;
		int copies;
	Book (string id, string ten,string chude, string tacgia, string nhaxuatban, string ngayxuatban, int sotrang, int soban)
		: isbn(id),title(ten),subject(chude), author(tacgia),publisher(nhaxuatban),date(ngayxuatban),pages(sotrang),copies(soban){}
	virtual void nhapThongTinSach() 
	{
		cout<<"Nhap ma sach: ";
		cin.ignore();
		getline(cin,isbn);
		
		cout<<"Nhap ten sach: ";
		getline(cin,title);
		
		cout<<"Nhap chu de: ";
		getline(cin,subject);
		
		cout<<"Nhap tac gia: ";
		getline(cin,author);
		
		cout<<"Nhap nha xuat ban: ";
		getline(cin,publisher);
		
		cout<<"Nhap ngay san xuat (dd/mm/yyyy): ";
		getline(cin,date);
		
		cout<<"Nhap so trang: ";
		cin>>pages;
		
		cout<<"Nhap so ban: ";
		cin>>copies;
	}
	virtual void hienThiThongTinSach() const 
	{
		cout<<"\n----------------------------------------------------------------------------"<<endl;
		cout<< "Ma sach: "<<isbn<<"  |Ten sach: "<<title<<"  |Chu de: "<<subject<<"  |Tac gia: "<<author<<endl<<"Nha san xuat: "<<publisher<<"  |Ngay san xuat: "<<date<<"  |So trang: "<<pages<<"  |So ban: "<<copies<<endl;
		cout<<"----------------------------------------------------------------------------"<<endl;
	}
	virtual ~ Book() {}
};

struct quanLi {
private:
    vector<Normal*> normalList;
	vector<Admin*> adminList;
	vector<Book*> bookList;
public:
	void loginAdmin()
	{
		Admin* systemAdmin= new Admin("","","") ;
		systemAdmin->userid="12345678";
		systemAdmin->username="Phan Hoang Son";
		systemAdmin->password="12345678";
		adminList.push_back(systemAdmin);
		string pass;
		string id;
		cout<<"Nhap ID nguoi dung: ";
		cin>>id;

		cout<<"Nhap password: ";
		cin>>pass;
		
		bool temp=true;
		for (size_t i = 0; i < adminList.size(); ++i) 
		{
            if (adminList[i]->userid == id && adminList[i]->password==pass) 
			{
				cout<<"---------------------"<<endl;
				cout<<"Dang nhap thanh cong!"<<endl;
				cout<<"---------------------"<<endl;
				cout<<"Xin Chao!"<<endl;
                adminList[i]->hienThiThongTinAdmin();
                hienThiMenuAdmin();
                temp=false;
	        }
	    }
	    if (temp)
	    {
	    	cout<<"------------------"<<endl;
			cout<<"ID hoac Pass loi!"<<endl;
			cout<<"------------------"<<endl;
	    }
	}
	void loginNormal()
	{
		string id;
		cout<<"Nhap ID nguoi dung: ";
		cin.ignore();
		getline(cin,id);
		bool temp=true;
		for (size_t i = 0; i < normalList.size(); ++i) 
		{
			if (normalList[i]->userid==id)
			{	
				normalList[i]->hienThiThongTin();	
				hienThiMenuNormal();
				temp=false;
		    }
	    }
	    if (temp)
	    {
	    	cout<<"-------"<<endl;
			cout<<"ID loi!"<<endl;
			cout<<"-------"<<endl;
	    }
		
	}
    void themMoiNguoiDung() {
        int luaChon;
        cout << "1. Normal\n 2. Admin \n Chon Class: ";
        cin >> luaChon;
		Normal* normal=NULL;
		Admin* admin=NULL;
        switch (luaChon) 
		{
			case 1:
            	normal = new Normal("","");
            	normal->nhapThongTin();
            	normalList.push_back(normal);
                break;
            case 2:
                admin = new Admin("","","");
                admin->nhapThongTinAdmin();
                adminList.push_back(admin);
                break;
            
            default:
            	cout << "----------------------" <<endl;
                cout << "Lua chon khong hop le." << endl;
                cout << "----------------------" <<endl;
                return;
        }
       	cout << "--------------------" <<endl;
        cout << "Them moi thanh cong!" << endl;
        cout << "--------------------" <<endl;
    }
    
    void chinhSuaThongTinUser()
    {
    	string id,pass,name;
		cout<<"Nhap ID tai khoan can chinh sua: ";
		cin>>id;
		for (size_t i = 0; i < adminList.size(); ++i) 
		{
			if(adminList[i]->userid==id)
			{
				cout<<"Nhap Password:";
				cin>>pass;
				if(adminList[i]->password==pass)
				{
					cout<<"Nhap thong tin moi:"<<endl;
					adminList[i]->nhapThongTinAdmin();
			    }
				else
				{
					cout<<"Pass loi!";
					return;
				}
			}
		}
		for (size_t i = 0; i < normalList.size(); ++i) 
		{	
			if(normalList[i]->userid==id)
			{
				cout<<"Nhap thong tin moi:"<<endl;
				normalList[i]->nhapThongTin();
			}
			else
			{
				cout<<"ID loi!";
				return;
			}
		}
	
	}

    void timKiemTheoHoTen() {
        string hoTen;
        cout << "Nhap ho ten can tim kiem: ";
        cin.ignore();
        getline(cin, hoTen);
		bool temp=true;
        cout << "Ket qua tim kiem theo ho ten '" << hoTen << "':" << endl;
        for (size_t i = 0; i < normalList.size(); ++i)
		{
            if (normalList[i]->username == hoTen) 
			{
                normalList[i]->hienThiThongTin();
                temp=false;
            }
        }
        for (size_t i = 0; i < adminList.size(); ++i)
		{
            if (adminList[i]->username == hoTen) 
			{
                adminList[i]->hienThiThongTinAdmin();
                temp=false;
            }
        }
        if (temp)
        {
        	cout <<"------------------------" <<endl;
    		cout <<"Khong tim thay sach voi '"<<hoTen<<"'."<<endl;
    		cout <<"------------------------" <<endl;
    	}
    }

    void deleteUser() {
        string id;
        cout << "Nhap ma can xoa: ";
        cin >> id;
		
        for (size_t i = 0; i < normalList.size(); ++i) 
		{
            if (normalList[i]->userid == id) 
			{
                delete normalList[i];
                normalList.erase(normalList.begin() + i);
                cout <<"-----------------" <<endl;
                cout <<" Xoa thanh cong!" << endl;
                cout <<"-----------------" <<endl;
                return;
            }
        
        }
		for (size_t i = 0; i < adminList.size(); ++i) 
		{
            if (adminList[i]->userid == id) 
			{
                delete adminList[i];
                adminList.erase(adminList.begin() + i);
                cout <<"-----------------" <<endl;
                cout << "Xoa thanh cong!" << endl;
                cout <<"-----------------" <<endl;
                return;
            }
        
        }
        cout <<"-----------------------------------------------" <<endl;
        cout <<"Khong tim thay nguoi dung voi ma '" << id << "'." << endl;
        cout <<"-----------------------------------------------" <<endl;
    }

    void timKiemTheoUserId() 
	{
        string id;
        cout << "Nhap ma can hien thi thong tin: ";
        cin >> id;

        for (size_t i = 0; i < normalList.size(); ++i) 
		{
            if (normalList[i]->userid == id) 
			{
                normalList[i]->hienThiThongTin();
                return;
            }
        }
		for (size_t i = 0; i < adminList.size(); ++i) 
		{
            if (adminList[i]->userid == id) 
			{
                adminList[i]->hienThiThongTinAdmin();
                return;
            }
        }
        cout <<"-----------------------------------------------" <<endl;
        cout << "Khong tim thay nguoi dung voi ma '" << id << "'." << endl;
        cout <<"-----------------------------------------------" <<endl;
    }
    void themSachMoi()
    {
    	Book* book= new Book("","","","","","",0,0);
    	book->nhapThongTinSach();
        bookList.push_back(book);
        cout <<"-----------------------" <<endl;
        cout << "Them moi thanh cong!" << endl;
        cout <<"-----------------------" <<endl;
	}
    void timKiemTheoIdSach()
    {
    	string id;
    	cout<< "Nhap ID sach: ";
    	cin.ignore();
    	getline(cin,id);
    	
    	for (size_t i = 0; i < bookList.size(); ++i) 
		{
            if (bookList[i]->isbn == id) 
			{
                bookList[i]->hienThiThongTinSach();
                return;
            }
        }
        cout <<"-----------------------------------------------" <<endl;
    	cout<<"Khong tim thay sach voi '"<<id<<"'."<<endl;
    	cout <<"-----------------------------------------------" <<endl;
	}
	
	void timKiemTheoTenSach()
	{
		string name;
		cout<<"Nhap ten sach: ";
		cin.ignore();
		getline(cin,name);
		bool temp=true;
		for (size_t i = 0; i < bookList.size(); ++i) 
		{
            if (bookList[i]->title == name) 
			{
                bookList[i]->hienThiThongTinSach();
  				temp=false;	
            }
        }
        if (temp)
        {
        	cout <<"-----------------------------------------------" <<endl;
    		cout<<"Khong tim thay sach voi '"<<name<<"'."<<endl;
    		cout <<"-----------------------------------------------" <<endl;
    	}
	}
	
	void timKiemTheoChuDe()
	{
		string theme;
		cout<<"Nhap chu de sach: ";
		cin.ignore();
		getline(cin,theme);
		bool temp=true;
		for (size_t i = 0; i < bookList.size(); ++i) 
		{
            if (bookList[i]->subject == theme) 
			{
                bookList[i]->hienThiThongTinSach();
				temp=false;
            }
        }
        if (temp)
        {
        	cout <<"-----------------------------------------------" <<endl;
    		cout<<"Khong tim thay sach voi '"<<theme<<"'."<<endl;
    		cout <<"-----------------------------------------------" <<endl;
    	}
	}
	void timKiemTheoTacGia()
	{
		string author;
		cout<<"Nhap tac gia sach: ";
		cin.ignore();
		getline(cin,author);
		bool temp=true;
		for (size_t i = 0; i < bookList.size(); ++i) 
		{
            if (bookList[i]->author == author) 
			{
                bookList[i]->hienThiThongTinSach();
                temp=false;
            }
        }
        if (temp)
        {
        	cout <<"-----------------------------------------------" <<endl;
    		cout<<"Khong tim thay sach voi '"<<author<<"'."<<endl;
    		cout <<"-----------------------------------------------" <<endl;
    	}
	}
	
	void timKiemTheoNhaSanXuat()
	{
		string publisher;
		cout<<"Nhap nha san xuat sach: ";
		cin.ignore();
		getline(cin,publisher);
		bool temp=true;
		for (size_t i = 0; i < bookList.size(); ++i) 
		{
            if (bookList[i]->publisher == publisher) 
			{
                bookList[i]->hienThiThongTinSach();
                temp=false;
            }
        }
        if (temp)
        {
        	cout <<"-----------------------------------------------" <<endl;
    		cout<<"Khong tim thay sach voi '"<<publisher<<"'."<<endl;
    		cout <<"-----------------------------------------------" <<endl;
    	}
	}
	
	void timKiemTheoDate()
	{
		string date;
		cout<<"Nhap ngay san xuat sach(dd/mm/yy): ";
		cin.ignore();
		getline(cin,date);
		bool temp=true;
		for (size_t i = 0; i < bookList.size(); ++i) 
		{
            if (bookList[i]->date == date) 
			{
                bookList[i]->hienThiThongTinSach();
                temp=false;
            }
        }
        if (temp)
        {
        	cout <<"-----------------------------------------------" <<endl;
    		cout<<"Khong tim thay sach voi '"<<date<<"'."<<endl;
    		cout <<"-----------------------------------------------" <<endl;
    	}
	}
	
	void deleteBook() 
	{
        string id;
        cout << "Nhap ID sach can xoa: ";
        cin.ignore();
        getline(cin,id);
        for (size_t i = 0; i < bookList.size(); ++i) 
		{
            if (bookList[i]->isbn == id) 
			{
                delete bookList[i];
                bookList.erase(bookList.begin() + i);
                cout <<"-----------------" <<endl;
                cout << "Xoa thanh cong!" << endl;
                cout <<"-----------------" <<endl;
                return;
            }
        }
		cout <<"------------------------------------------------" <<endl;
        cout << "Khong tim thay sach voi ma '" << id << "'." << endl;
        cout <<"------------------------------------------------" <<endl;
    }
    
    void hienThiMenuAdmin()
    {
    	int luaChon;
		do 
		{
		    cout << "\n========= MENU ADMIN ==========" << endl;
		    cout << "1. Them nguoi dung moi" << endl;
		    cout << "2. Chinh sua thong tin tai khoan" << endl;
		    cout << "3. Xoa nguoi dung" << endl;
		   	cout << "4. Tim kiem theo ho ten" << endl;
		    cout << "5. Tim kiem theo ma nguoi dung" << endl;
		    cout << "6. Them sach moi"<<endl;
		    cout << "7. Xoa sach"<<endl;
		    cout << "8. Menu normal"<<endl;
		    cout << "0. Thoat" << endl;
		    cout << "================================" << endl;
		    cout << "Nhap lua chon cua ban: ";
		    cin >> luaChon;
		
		    switch (luaChon) 
			{
		    	case 1:
		            themMoiNguoiDung();
		            break;
		        case 2:
		        	chinhSuaThongTinUser();
					break;
		        case 3:
		            deleteUser();
		            break;
		    	case 4:
		            timKiemTheoHoTen();
		            break;
		        case 5:
		            timKiemTheoUserId();
		            break;
		        case 6:
		            themSachMoi();
		            break;
		        case 7:
		            deleteBook();
		            break;
		        case 8:
		        	hienThiMenuNormal();
		        	break;
		        case 0:
		            break;
		        default:
		            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
		            }
	        	} while (luaChon != 0);	
    }
    void hienThiMenuNormal()
    {
    	int luaChon;
				do 
				{
		            cout << "\n=========== MENU NORMAL ============" << endl;
					cout << "1.Tra cuu sach theo ID"<<endl;
					cout << "2.Tra cuu sach theo ten"<<endl;
					cout << "3.Tra cuu sach theo chu de"<<endl;
					cout << "4.Tra cuu sach theo tac gia"<<endl;
					cout << "5.Tra cuu sach theo nha san xuat"<<endl;
					cout << "6.Tra cuu sach theo ngay san xuat"<<endl;
					cout << "0.Thoat"<<endl;
					cout << "=====================================" << endl;
					cout << "Nhap lua chon cua ban than: ";
					cin>>luaChon;
				    switch (luaChon) 
					{
		                case 1:
		                    timKiemTheoIdSach();
		                    break;
		                case 2:
		                    timKiemTheoTenSach();
		                    break;
		                case 3:
		                    timKiemTheoChuDe();
		                    break;
		                case 4:
		                    timKiemTheoTacGia();
		                    break;
		                case 5:
		                    timKiemTheoNhaSanXuat();
		                    break;
		                case 6:
		                    timKiemTheoDate();
		                    break;
		                case 0:
		                    cout << "Tam biet!" << endl;
		                    break;
		                default:
		                    cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
		            }
		        } while (luaChon != 0);
	}
    void hienThiMenu() {
        int luaChon;

        do {
            cout << "\n===== MENU =====" << endl;
            cout << "1.Login for Admin"<<endl;
            cout << "2.Login for Normal"<<endl;
            cout << "0. Thoat" << endl;
            cout << "================" << endl;
            cout << "Nhap lua chon cua ban: ";
            cin >> luaChon;

            switch (luaChon) {
                case 1:
                    loginAdmin();
                    break;
                case 2:
                    loginNormal();
                case 0:
                    cout << "Tam biet!" << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            }
        } while (luaChon != 0);
    }

    ~quanLi() 
	{
        for (size_t i = 0; i < normalList.size(); ++i) 
		{
            delete normalList[i];
        }
        for (size_t i = 0; i < adminList.size(); ++i) {
            delete adminList[i];
        }
    }
    
};

int main() 
{
    quanLi qltv;
    cout << "=======================" << endl;
    cout << "=  WELCOME TO LIBRARY =" << endl;
    cout << "=======================" << endl;
    qltv.hienThiMenu();
    return 0;
}

