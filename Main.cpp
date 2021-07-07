#include<list>
#include<conio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <WinUser.h>
#include<iostream.h>
#include<iomanip.h>
#include <tchar.h>

#include "DirectoryManager.cpp"
#include "File.cpp"
#include "Heapsort.cpp"
#include "merge.cpp"
#include "mylib.cpp"
#include "Ve_Hinh.cpp"
#include "Marcro.cpp"

char* const Test  = "./DanhBaTest.csv";
char* const NotTest = "./DanhBa.csv";
char* const FreightFile = "./freight.csv";
char* const DanhBaInRa = "./DanhBaInRa.csv";

using std::string;
using std::cout;
using std::setw;
using std::setfill;

void AdminMenu()
{
    std::cout<<"1. Cap Nhap Danh Da  "<<endl;
    std::cout<<"2. Luu danh ba."<<endl;
    std::cout<<"3. Sap xep danh ba."<<endl;
    std::cout<<"4. Tim kiem."<<endl;
    std::cout<<"5. That toan cuoc dien thoai"<<endl;
    std::cout<<"6. In ra danh ba"<<endl;
    std::cout<<"ESC. De thoat "<<endl;
}
void UpdateDirectoryMenu()
{
    std::cout << "1. Them 1 vao danh ba.  " << endl;
    std::cout << "2. Sua 1 phan tu trong danh ba. " << endl;
    std::cout << "3. Xoa 1 phan tu trong danh ba. " << endl;
}
void GuestMenu()
{
    std::cout<<"1. Luu danh ba."<<endl;
    std::cout<<"2. Sap xep danh ba."<<endl;
    std::cout<<"3. Tim kiem."<<endl;
    std::cout<<"4. Xem  cuoc dien thoai"<<endl;
    std::cout<<"5. In ra danh ba. "<<endl;
    std::cout<<"ESC. De thoat"<<endl;
}
bool ConfrimAction()
{
    std::cin.ignore();
    std::cout<<"An Y de tiep tuc . An bat ki de huy  ";
    char confrim;
    cin>>confrim;
    if(confrim=='Y'||confrim == 'y') return true;
    else return false;
}

void AlgorithmMenu(int x, int y)
{
    gotoxy(x,y);
    cout<<" 1. HEAPSORT "<<endl;
    gotoxy(x,y+2);
    cout<<" 2. MERGESORT "<<endl;
}

void PropertyMenu(int x, int y)
{
    gotoxy(x,y);
    cout<<"      1. ID      ";
    gotoxy(x,y+2);
    cout<<"   2. TIEM NANG  ";
    gotoxy(x,y+4);
    cout<<"   3. HO VA TEN  ";
    gotoxy(x,y+6);
    cout<<"    4. KHU VUC   ";
    gotoxy(x,y+8);
    cout<<"   5. DIEN THOAI ";
}
void IncreasMenu(int x, int y)
{
    gotoxy(x,y);
    cout<<" 1. INCREAS "<<endl;
    gotoxy(x,y+2);
    cout<<" 2. DESCREAS"<<endl;
}

void ShowListDirSmall (	DirectoryManager manager , list<DanhBa> &showList,int page,int &record, int &totalPage)
{
    //manager.setList(showList);
     manager.setList(showList);
    do
    {
        manager.printPageSmall(page,record);
        gotoxy(5, yHotkey );
        SetColor(WHITE);
        cout << "ESC - De thoat, -> Trang tiep, <- Lui trang";
        ShowCur(false);
        _getch();
        if(GetAsyncKeyState(VK_RIGHT) <0) page++;
        if(GetAsyncKeyState(VK_LEFT) <0 ) page--;
        if(GetAsyncKeyState(VK_ESCAPE)) break;
        if(page < 1 )  page = 1;
        if(page > totalPage) page--;
        //system("cls");
    }
    while(0<page&&page<=totalPage);
    system("cls");
}

void ShowListDir (	DirectoryManager manager , list<DanhBa> &showList,int page,int &record, int &totalPage)
{
    system("color 37");
    manager.setList(showList);
    do
    {
        system("cls");
        manager.printPage(page,record);
        gotoxy(53, yHotkey );
        SetColor(WHITE);
        cout << "ESC - De thoat, -> Trang tiep, <- Lui trang,  Home - So trang";
        ShowCur(false);
        _getch();
        if(GetAsyncKeyState(VK_RIGHT) <0) page++;
        if(GetAsyncKeyState(VK_LEFT) <0 ) page--;
        if(GetAsyncKeyState(VK_ESCAPE)) break;
        if(GetAsyncKeyState(VK_HOME)<0)
        {
        	gotoxy(57, yHotkey + 2);
            cout<<"Moi ban nhap vao trang muon toi trong "<<totalPage<<" trang:  ";
            cin>>page;
        }
        if(page < 1 )  page = 1;
        if(page > totalPage) page--;
        system("cls");
    }
    while(0<page&&page<=totalPage);
}

void UpdateDirectory( DirectoryManager &manager , list<DanhBa> &showList,int page,int &record, int &totalPage)
{
    do
    {
        system("cls");
        system("color 3E");
        normalBGColor();
    	gotoxy(27,1);
    	cout<<"~~~  CAP NHAT DANH BA  ~~~";
        manager.printPageSmall(page,record);
        gotoxy(5, yHotkey );
        SetColor(WHITE);
        cout << "ESC - De thoat, 1 - Them, 2 - Sua, 3 - Xoa, -> Trang tiep, <- Lui trang, Home - So trang";
        ShowCur(false);
        int i = (char)_getch();
        if (i == 49 || i == 79)
        {
            manager.insertOne();
        }
        else if (i == 50 || i == 80)
        {
            manager.updateOne();
        }
        else if (i == 51 || i == 81)
        {
            manager.removeOne();
        }

        if(GetAsyncKeyState(VK_RIGHT) <0) page++;
        if(GetAsyncKeyState(VK_LEFT) <0 ) page--;
        if(GetAsyncKeyState(VK_ESCAPE)) break;
        if(GetAsyncKeyState(VK_HOME)<0)
        {
            BangNhapSoTrang();
            gotoxy(103,38);
            cout<<"MOI BAN NHAP VAO TRANG MUON TOI TRONG "<<totalPage<<" TRANG:  ";
            cin>>page;
        }
        if(page < 1 )  page = 1;
        if(page > totalPage) page--;
        system("cls");
    }
    while(0<page&&page<=totalPage);
    showList = manager.getList();
}
void FindDir( list<DanhBa> &setList )
{
    system("cls");
    system("color 3E");
    string k;
    ifstream inFile("book.txt", ios::in);
    gotoxy(80,39);
    if (inFile.good()) 
    {
        while (!inFile.eof())
        {
            getline(inFile, k);
            SetColor(WHITE);
            cout << k<<endl;
        }
    }
    else  
    {
    	gotoxy(90,40);
        cout << "Lien ket voi File book khong thanh cong! " << "\n";
    }
    BangNhapSXTK();
    gotoxy(103,8);
    cout<<"TIM KIEM THEO: ";
    PropertyMenu(118,8);
    ShowCur(false);
    int c =0;
    int property = 1;
    while (c != ENTER)
    {
        SetColor(LIGHT_GREEN);
        gotoxy(118 - 1, 7 + property);
        cout << ">>";
        gotoxy(118 + 19, 7 + property);
        cout << "<<";
        c = _getch();
        if (c == KEY_DOWN)
        {
            gotoxy(118 - 1, 7 + property);
            cout << "   ";
            gotoxy(118 + 19, 7 + property);
            cout << "   ";
            if (property == 1)
                property = 3;
            else if (property == 3)
                property = 5;
            else if(property == 5)
                property = 7;
            else if(property == 7)
                property = 9;
            else if(property == 9)
                property = 1;
        }
        else if(c == KEY_UP)
        {
            gotoxy(118 - 1, 7 + property);
            cout << "   ";
            gotoxy(118 + 19, 7 + property);
            cout << "   ";
            if (property == 9)
                property = 7;
            else if (property == 7)
                property = 5;
            else if(property == 5)
                property = 3;
            else if(property == 3)
                property = 1;
            else if(property == 1)
                property = 9;
        }
    }
	int choise = 0 ;
	if (property == 1)
        choise = 1;
    else if (property == 3)
        choise = 2;
    else if(property == 5)
        choise = 3;
    else if(property == 7)
        choise = 4;
    else if(property == 9)
		choise = 5;
    DanhBa sreach;
    BangNhapTK();
    gotoxy(93,27);
    cout<<"MOI NHAP THONG TIN CAN TIM KIEM :  ";
    string temp;
   	getline(std::cin,temp);
    if(choise == 1)	sreach.setID(atoi(temp.c_str()));
    else if(choise == 2)	sreach.setRank(atoi(temp.c_str()));
    else if(choise == 3)	sreach.setFullName(temp);
    else if(choise == 4)	sreach.setArea((temp));
    else if(choise == 5)	sreach.setPhone((temp));
    bool flag = false;
    DirectoryManager dm;
    list<DanhBa> :: iterator itr = setList.end();
    //ShowSmall(keyShowSmall, 5, xShowSmall);
    normalBGColor();
    CreateBox(92, 32, "NOTIFICATIONS:  ", 59);
    int a=5;
    SetColor(WHITE);
    list<DanhBa> listSearch ;
    while(itr != setList.begin())
    {
        itr--;
        DanhBa single = *itr;
        if(equalsDirectory(single,sreach,choise))
        {
            listSearch.push_back(single);
            flag = true;
        }
    }
    ShowCur(false);
    if(!flag)
    {
        gotoxy(108,32);
        SetColor(BLUE);
        cout<<"KHONG TIM THAY THONG TIN TREN \n";
        cin.ignore();
    } else{
    	normalBGColor();
    	gotoxy(32,1);
    	cout<<"~~~ TIM KIEM ~~~";
    	DirectoryManager dm;
    	int page = 1;
    	int record = 22;
    	int totalPage = (listSearch.size()/record) > 1 ?  listSearch.size()/record : 1;
    	ShowListDirSmall(dm,listSearch,page,record,totalPage);
    }
    
}

void SortDir( DirectoryManager manager,  list<DanhBa> &showList ,int &page,int &record, int &totalPage )
{
    system("cls");
    system("color 3E");
    ShowCur(false);
    int c =0;
    int property = 1;
    SetColor(BRIGHT_WHITE);
    BangNhapSXTK();
    gotoxy(103,8);
    cout<<"SAP XEP THEO : ";
    PropertyMenu(118,8);
    while (c != ENTER)
    {
        SetColor(LIGHT_GREEN);
        gotoxy(118 - 1, 7 + property);
        cout << ">>";
        gotoxy(118 + 19, 7 + property);
        cout << "<<";
        c = _getch();
        if (c == KEY_DOWN)
        {
            gotoxy(118 - 1, 7 + property);
            cout << "   ";
            gotoxy(118 + 19, 7 + property);
            cout << "   ";
            if (property == 1)
                property = 3;
            else if (property == 3)
                property = 5;
            else if(property == 5)
                property = 7;
            else if(property == 7)
                property = 9;
            else if(property == 9)
                property = 1;
        }
        else if(c == KEY_UP)
        {
            gotoxy(118 - 1, 7 + property);
            cout << "   ";
            gotoxy(118 + 19, 7 + property);
            cout << "   ";
            if (property == 9)
                property = 7;
            else if (property == 7)
                property = 5;
            else if(property == 5)
                property = 3;
            else if(property == 3)
                property = 1;
            else if(property == 1)
                property = 9;
        }
    }
    BangNhapSX1();
    gotoxy(103,26);
    cout<<"KIEU : ";
    AlgorithmMenu(112,26);
    list<DanhBa> ::iterator itr = showList.begin();
    size_t listSize = showList.size() ;
    DanhBa* arraylist  = new  DanhBa[(int)listSize];
    int i = 0;
    while (itr != showList.end())
    {
        arraylist[i++] = *itr;
        itr++;
    }
    int a = 0, b = 0;
    while (a != ENTER)
    {
        SetColor(LIGHT_GREEN);
        gotoxy(112 - 2, 26 + b);
        cout << ">>";
        gotoxy(112 + 14, 26 + b);
        cout << "<<";
        a = _getch();
        if (a == KEY_UP || a == KEY_DOWN)
        {
            gotoxy(112 - 2, 26 + b);
            cout << "   ";
            gotoxy(112 + 14, 26 + b);
            cout << "   ";
            if (b == 0)
                b = 2;
            else if (b == 2)
                b = 0;
        }
    }
    BangNhapSX2();
    gotoxy(103,36);
    cout<<"THU TU : ";
    IncreasMenu(112,36);
    int a1 = 0, b1 = 0;
    	int choise = 0 ;
		if (property == 1)
            choise = 1;
        else if (property == 3)
            choise = 2;
        else if(property == 5)
            choise = 3;
        else if(property == 7)
            choise = 4;
        else if(property == 9)
			choise = 5;
    if(b==0)
    {
        while (a1 != ENTER)
        {
            SetColor(LIGHT_GREEN);
            gotoxy(112 - 2, 36 + b1);
            cout << ">>";
            gotoxy(112 + 14, 36 + b1);
            cout << "<<";
            a1 = _getch();
            if (a1 == KEY_UP || a1 == KEY_DOWN)
            {
                gotoxy(112 - 2, 36 + b1);
                cout << "   ";
                gotoxy(112 + 14, 36 + b1);
                cout << "   ";
                if (b1 == 0)
                    b1 = 2;
                else if (b1 == 2)
                    b1 = 0;
            }
        }
        
        if (b1==0)
            heapSort(arraylist, (int)listSize,true,choise);
        else if(b1==2)
            heapSort(arraylist, (int)listSize,false,choise);
    }
    else if(b==2)
    {
        while (a1 != ENTER)
        {
            SetColor(LIGHT_GREEN);
            gotoxy(112 - 2, 36 + b1);
            cout << ">>";
            gotoxy(112 + 14, 36 + b1);
            cout << "<<";
            a1 = _getch();
            if (a1 == KEY_UP || a1 == KEY_DOWN)
            {
                gotoxy(112 - 2, 36 + b1);
                cout << "   ";
                gotoxy(112 + 14, 36 + b1);
                cout << "   ";
                if (b1 == 0)
                    b1 = 2;
                else if (b1 == 2)
                    b1 = 0;
            }
        }
        if(b1 == 0)
            mergeSort(arraylist,0,listSize-1,false,choise);
        else if (b1==2)
            mergeSort(arraylist,0, listSize-1,true,choise);
    }
    showList.clear();
    for (size_t i = 0; i < listSize; i++)
    {
        showList.push_back(arraylist[i]);

    }
    showList.reverse();
    normalBGColor();
    gotoxy(32,1);
    cout<<"~~~  SAP XEP  ~~~";
    ShowListDirSmall(manager,showList,page, record,totalPage);

}

void PrintFile(list<DanhBa> setList, FileAction &file )
{
    system("cls");
    system("color 3E");
    file.WriteFlie(setList,DanhBaInRa);
    string a;
    ifstream inFile("ASCII-5.txt", ios::in);
    if (inFile.good())  // Kiem tra xem file co ket noi duoc hay khong?
    {
        while (!inFile.eof())
        {
            getline(inFile, a);
            SetColor(BLACK);
            cout << a << endl;
        }
    }
    else  //Tra ve loi
    {
    	gotoxy(63,5);
        cout << "Lien ket voi File ASCII-5 khong thanh cong! " << "\n";
    }
    cin.ignore();
}
void SaveFile(DirectoryManager	manager, FileAction &file )
{
    list<DanhBa> showList;
    system("cls");
    system("color 3E");

    showList = manager.getList();
    //showList.reverse();
    file.WriteFlie(showList,NotTest);
    string a;

    // lay tu file o che do chi doc
    ifstream inFile("ASCII-5.txt", ios::in);
    if (inFile.good())  // Kiem tra xem file co ket noi duoc hay khong?
    {
        while (!inFile.eof())
        {
            getline(inFile, a);
            SetColor(BLACK);
            cout << a << endl;
        }
    }
    else  //Tra ve loi
    {
    	gotoxy(63,5);
        cout << "Lien ket voi File ASCII-5 khong thanh cong! " << "\n";
    }
    cin.ignore();
}
list<DanhBa> ReadFileFreight(list<DanhBa> &showtList, FileAction &file, DirectoryManager manager)
{
    clrscr();
    system("color 3E");
    string a;
    gotoxy(10,53);
    // lay tu file o che do chi doc
    ifstream inFile("oto.txt", ios::in);
    if (inFile.good())  // Kiem tra xem file co ket noi duoc hay khong?
    {
        while (!inFile.eof())
        {
            getline(inFile, a);
            SetColor(BLACK);
            Sleep(100);
            cout << a << endl;
        }
    }
    else  //Tra ve loi
    {
    	gotoxy(65,5);
        cout << "Lien ket voi File oto khong thanh cong! " << "\n";
    }
    SetColor(LIGHT_YELLOW);
    gotoxy(63,7);
    cout<<"~~~ THAT TOAN CUOC DIEN THOAI ~~~";
    SetColor(LIGHT_YELLOW);
    gotoxy(15, 14);
    cout << "  ID  ";
    gotoxy(30, 14);
    cout << "  FULL NAME  ";
    gotoxy(65, 14);
    cout << "  PHONE  ";
    gotoxy(90, 14);
    cout << "  AREA  ";
    gotoxy(120, 14);
    cout << "  RANK  ";
    gotoxy(140,14);
    cout << "DEBT";
    SetColor(WHITE);
    list<DanhBa> temp = file.ReadFileFreight( showtList,FreightFile, manager);
    if(temp.size()!=0)
    {
    	SetColor(LIGHT_GREEN);
        gotoxy(72,10);
        cout<<"LAY XONG DU LIEU"<<endl;
    }
    cin.ignore();
    return temp;
}
void ViewFreight(DanhBa &dir)
{
    clrscr();
    system("color 3E");
    string a;
    ifstream inFile("ASCII-2.txt", ios::in);
    if (inFile.good())  // Kiem tra xem file co ket noi duoc hay khong?
    {
        while (!inFile.eof())
        {
            getline(inFile, a);
            SetColor(BLACK);
            cout << a << endl;
        }
    }
    else  //Tra ve loi
    {
    	gotoxy(63,5);
        cout << "Lien ket voi File ASCII-2 khong thanh cong! " << "\n";
    }
    //BangHienThiCDT();
    SetColor(LIGHT_YELLOW);
    gotoxy(33,31);
    cout<<"THUE BAO: "<< dir.getPhone()<<endl;
    gotoxy(33,33);
    cout<<"CUOC CHUA THANH TOAN: "<<dir.getFare()<<endl;
}

void Introduce()
{
    PlaySound(TEXT("Chao_mung.wav"), NULL, SND_ASYNC);
    system("color 3E");
    ShowCur(false);
    string a;

    gotoxy(10,8);
    // lay tu file o che do chi doc
    ifstream inFile("gioithieu.txt", ios::in);
    if (inFile.good())  // Kiem tra xem file co ket noi duoc hay khong?
    {
        while (!inFile.eof())
        {
            getline(inFile, a);
            SetColor(BRIGHT_WHITE);
            Sleep(100);
            cout << a << endl;
        }
    }
    else  //Tra ve loi
    {
    	gotoxy(63,5);
        cout << "Lien ket voi File gioithieu khong thanh cong! " << "\n";
    }
    SetColor(LIGHT_GREEN);
    gotoxy(75, 38);
    cout <<"THANH VIEN NHOM 5";
    gotoxy(xTen, yTen);
    cout << "- 17103100397 - NGUYEN THI TRA";
    gotoxy(xTen, yTen + 2);
    cout << "- 17103100414 - DO DINH TIEN";
    gotoxy(75, 36);
    cout << "LOP   : DHTI11A5HN";
    CayLoading(LIGHT_YELLOW);
    ShowCur(false);

    // nhan enter de thoat vong lap
    gotoxy(67, 53);
    SetBGColor(BLUE);
    cout << "Please ! Press ENTER to continue. ";
    cin.ignore();
    normalBGColor();
    while (!_kbhit())
    {
        gotoxy(62, 48);
        SetColor(1 + rand() % 15);
        Sleep(100);
        cout << "TRUONG DAI HOC KINH TE - KY THUAT CONG NGHIEP";
    }
    SetBGColor(AQUA);
    SetColor(AQUA);
    cin.ignore();
    return;
}

void ManHinhChinh()
{
    system("color 3E");
    clrscr();
    normalTextColor();
    ShowCur(false);
    VeKhungMenu();

    normalBGColor();
    MainMenu(keyMainMenu, 4);
    normalBGColor();

    string a;
    int y = 1;
    //lay tu file va chi doc
    ifstream inFile("menuchinh.txt", ios::in);

    // Kiem tra xem file co ket noi duoc hay khong?
    if (inFile.good())
    {
        while (!inFile.eof())
        {
            getline(inFile, a);
            SetColor(15);
            gotoxy(10, y++);
            cout << a << endl;
        }
    }
    else  //Tra ve loi
    {
    	gotoxy(63,5);
        cout << "Lien ket voi File menuchinh khong thanh cong! " << "\n";
    }
    inFile.close();
    normalTextColor();
    normalBGColor();
    SetBGColor(BLACK);
    ChuChay();

    return;
}

void ManHinhPhu()
{
    system("color 3E");
    clrscr();
    normalTextColor();
    ShowCur(false);
    VeKhungMenu();
    normalBGColor();
    int y = 1;

    //lay tu file va chi doc
    ifstream inFile("menuphu.txt", ios::in);

    // Kiem tra xem file co ket noi duoc hay khong?
    if (inFile.good())
    {
        while (!inFile.eof())
        {
            char temp[255];
            inFile.getline(temp, 255);
            std::string line = temp;
            SetColor(15);
            gotoxy(10, y++);
            std::cout << line << std::endl;
        }
    }
    else  //Tra ve loi
    {
    	gotoxy(63,5);
        cout << "Lien ket voi File menuphu khong thanh cong! " << "\n";
    }
    normalBGColor();
    SetBGColor(BLACK);
    return;
}

int main()
{
    SetConsoleTitle(_T("QUAN LY DANH BA DIEN THOAI"));
    resizeConsole(GWIDTH, GHEIGHT);
    Introduce();
    //PlaySound(TEXT("nhacnen.wav"), NULL, SND_ASYNC);
    FileAction file;
    DirectoryManager manager;
    list<DanhBa> showList = file.ReadFile(NotTest);
    manager.setList(showList);
    int record = showList.size();
    int recordShow = 22;
    int totalPage = (int)(record / recordShow);
    if (record>recordShow && record % recordShow != 0)totalPage++;
    if (record < recordShow) totalPage = 1;
    bool run = true;
    bool isSort = false;
    char keyPress;
    while (run)
    {
        //totalPage = (int)(showList.size() / recordShow);
        int page = 1;
        ManHinhChinh();
        int i = ChooseMainMenu(4);
        if(i==0)
        {
            char user[30];
            char password[30];
            do
            {
				ADMIN:
                BangDangNhap();
                gotoxy(66,35);
                cout<<"* Nhap vao ten dang nhap: ";
                cin.getline(user,30);
                gotoxy(66,37);
                cout<<"* Nhap vao mat khau: ";
                cin.getline(password,30);
                if(strcmp(user,"admin")!=0 || strcmp(password,"admin")!=0)
                {
                    //PlaySound(TEXT("Sai_tk_mk.wav"), NULL, SND_ASYNC);
                    gotoxy(73,39);
                    cout<<"Ban nhap sai thong tin.";
                    gotoxy(75,40);
                    cout<<"Xin kiem tra lai!";
                    Sleep(2000);
                }
                Beep(600, 50);
            }
            while(strcmp(user,"admin")!=0 || strcmp(password,"admin")!=0);
            if (strcmp(user, "admin") == 0 && strcmp(password, "admin") == 0)
            {
                bool signin = true;
                int reset = 0;
                while (signin)
                {
                    system("cls");
                    ManHinhPhu();
                    SubMainMenuAdmin(keySubMainMenuAdmin,7);
                    normalBGColor();
                    SetBGColor(BLACK);
                    ChuChay();
                    int result = ChooseSubMenu(keySubMainMenuAdmin, xSubMainMenusAdmin, ySubMainMenusAdmin, 7);
                    if (GetAsyncKeyState(VK_TAB) < 0) goto GEST;
                    switch (result)
                    {
                    case 0:
                        UpdateDirectory(manager,showList,page,recordShow,totalPage);
                        break;
                    case 1:
                        SaveFile(manager, file);
                        break;
                    case 2:
                        SortDir(manager,showList,page,recordShow,totalPage);
                        isSort = true;
                        break;
                    case 3:
                        FindDir(showList);
                        break;
                    case 4:
                    	ManHinhLoading();
                        ReadFileFreight(showList, file, manager);
                        break;
                    case 5:
                        ShowListDir(manager,showList,page,recordShow,totalPage);
                        break;
                    case 6:
                        signin = false;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        else if (i == 1)
        {
            char number[11];
			GEST:
            BangDangNhap();
            gotoxy(68,42);
            cout<<"* Luu y: Vui long nhap du 10 so";
            gotoxy(68,33);
            cout<<"Nhap vao so dien thoai cua ban : ";
            gotoxy(79,36);
            cin.getline(number,11);
            bool signin = false;
            list<DanhBa> :: iterator itr = showList.begin();
            DanhBa newDir;
            while(itr != showList.end())
            {
                newDir = *itr;
                if(newDir.getPhone().compare(string(number))==0)
                {
                    signin = true;
                    break;
                }
                itr++;
            }
            if(!signin)
            {
            	gotoxy(71,39);
                cout<<"Ban nhap sai so dien thoai.";
                gotoxy(73,40);
				cout<<"Vui long kiem tra lai!";
				Sleep(2000);
            }
            Beep(600, 50);
            while (signin)
            {
                system("cls");
                ManHinhPhu();
                SubMainMenuGuest(keySubMainMenuGuest,6);
                normalBGColor();
                SetBGColor(BLACK);
                ChuChay();
                int result = ChooseSubMenu(keySubMainMenuGuest, xSubMainMenusGuest, ySubMainMenusGuest, 6);
                if (GetAsyncKeyState(VK_RIGHT) < 0) i = 1000;
                if (GetAsyncKeyState(VK_LEFT) < 0) i = 1001;
                if (GetAsyncKeyState(VK_TAB) < 0) goto ADMIN;
                switch (result)
                {
                case 0:
                    PrintFile(showList, file);
                    break;
                case 1:
                    SortDir(manager,showList,page,recordShow,totalPage);
                    isSort = true;
                    break;
                case 2:
                    FindDir(showList);
                    break;
                case 3:
                    ViewFreight(newDir);
                    std::cin.ignore();
                    break;
                case 4:
                    ShowListDir(manager,showList,page,recordShow,totalPage);
                    break;
                case 5:
                    signin = false;
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
        	gotoxy(70,22);
            break;
        }

    }
}
