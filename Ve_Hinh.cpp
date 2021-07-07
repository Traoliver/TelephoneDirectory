#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iomanip>      

#include "Marcro.cpp"
#include "mylib.cpp"

using std::string;  
using std::cout;
using std::setw;
using std::setfill;
	
// Ten cac danh muc trong Menu chinh
string keyMainMenu[4] = { " ***MENU CHINH*** ","  ADMIN  ", "  GUEST  ", "  THOAT  " };

								
string keySubMainMenuGuest[6] = { "       ~~~ LUU DANH BA ~~~       ",
								  "      ~~~ SAP XEP DANH BA ~~~    ",
							      "         ~~~ TIM KIEM ~~~        ",
							      "   ~~~ XEM CUOC DIEN THOAI ~~~   ",
							      "        ~~~ IN DANH BA ~~~       ",
							      "          ~~~ THOAT ~~~          "};


string keySubMainMenuAdmin[7]={ "            ~~~ CAP NHAT DANH BA ~~~            ",
								"               ~~~ LUU DANH BA ~~~              ",
								"             ~~~ SAP XEP DANH BA ~~~            ",
								"                 ~~~ TIM KIEM ~~~               ",
								"       ~~~ THAT TOAN CUOC DIEN THOAI ~~~        ",
								"                ~~~ IN DANH BA ~~~              ",
								"                   ~~~ THOAT ~~~                "};


string keyBangSuaAdmin[10] = {"             ~~~ SUA 1 PHAN TU VAO DANH BA ~~~              ",
							"                                                            ",
							" Nhap ho va ten        :",
							"                                                            ",
							" Nhap so dien thoai    :",
							"                                                            ",
							" Nhap khu vuc          :",
							"                                                            ",
							" Nhap tiem nang [1 - 5]:",
							"                                                            "};
							

string keyBangNhapAdmin[10] = {"             ~~~ THEM 1 PHAN TU VAO DANH BA ~~~             ",
							"                                                            ",
							" Nhap ho va ten        :",
							"                                                            ",
							" Nhap so dien thoai    :",
							"                                                            ",
							" Nhap khu vuc          :",
							"                                                            ",
							" Nhap tiem nang [1 - 5]:",
							"                                                            "};


// ten cac danh muc hien thi  trong bang hien thi danh ba admin
string keyShowSmall[5] = { "ID", "     FULL NAME     ", "    PHONE    ", "         AREA         ", "RANK" };


// ten cac danh muc trong muc Guides
string keyGuide[5] =  { "                       ~~~GUIDES~~~                         ",
						"-> HO TEN        : Toi da 7 ky tu, chi lay ky tu chu.       ",
						"-> SO DIEN THOAI : Toi da 10 ky tu, chi lay ky tu so.       ",
						"-> KHU VUC       : Toi da 11 ky tu, chi lay ky tu chu.      ",
						"-> TIEM NANG     : Chon trong khoang tu 1 den 5.            "};
						

// Cac diem toa do x trong bang hien thi doc gia
int xShowSmall[6] = { 3,10, 32,47,72, 79 };

// Cac diem toa do x trong main menu
int xMainMenus[4] = {32,69,97,125};
// Cac diem toa do y trong  menu con
int ySubMainMenusAdmin[7] = { 24, 28, 32, 36, 40, 44, 48};
int ySubMainMenusGuest[6] = { 26, 30, 34, 38, 42, 46};

// tao o hinh chu nhat thay doi theo chieu dai text truyen vao
void CreateBox(int x, int y, string text, int length)
{
	gotoxy(x - 2, y - 1);
	cout << char(201)<< setw(length) << setfill(char(205)) << char(205) << char(187);

	gotoxy(x - 2, y);
	cout << char(186) << text << setw(length - text.length() + 1) << setfill(' ') << char(186);

	gotoxy(x - 2, y + 1);
	cout << char(200) << setw(length) << setfill(char(205)) << char(205) << char(188);
}
// in ra dong chu chay vao console
void chuChay(char dChu[], int x, int y)
{
	SetColor(WHITE);
	ShowCur(false);
	char c[40];
	int length = (int)strlen(dChu);
	for (int i = 0; i < length; i++) {
		strncpy(c, dChu + i, 40);  // copy tu phan tu thu i den cuoi chuoi
		c[39] = '\0';
		Sleep(100);
		gotoxy(x, y);
		cout << "                                       ";
		gotoxy(x, y); // vi tri de in dong chu chay
		cout << c;
		if (i == length - 1) i = 0;  // chay vo han

		if (_kbhit()) {
			normalBGColor();
			return;  // Co phim nhan vao thi dung
		}
	}
}
void ChuChay()
{
	char dongChuChay[] = "   TRUONG DAI HOC KINH TE - KY THUAT CONG NGHIEP";
	// set khung
	gotoxy(xOrdinal + 64, yOrdinal + 53);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);

	gotoxy(xOrdinal + 64, yOrdinal + 54);
	cout << char(186) << setw(40) << setfill(' ') << char(186);

	gotoxy(xOrdinal + 64, yOrdinal + 55);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);

	chuChay(dongChuChay, xOrdinal + 65, yOrdinal + 54);
	return;
}
// ve hinh bang nhap.
/*void VeHinhBangNhap(int x, int y, int dorong, string str)
{
	SetBGColor(LIGHT_AQUA);
	SetColor(BLUE);
	gotoxy(x, y - 1);
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x, y );
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x, y + 1);
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x + (int)str.length()/ 3, y + 1);
	cout << setw((int)str.length() / 3  + 3) << setfill('~') << "~";
	
	gotoxy(x, y );
	cout << str;
	gotoxy(x, y + 2);
	cout << setw(4) << setfill(' ') << " ";
	gotoxy(x + dorong - 4, y + 2);
	cout << setw(4) << setfill(' ') << " ";
	gotoxy(x, y + 3);
	cout << setw(dorong) << setfill(' ') << " ";
	normalBGColor();
}*/
//ve cay loading
void CayLoading(int Color)
{
	SetColor(Color);
	for (int i = xLoading; i <= xLoading + 100; i++)
	{
		gotoxy(i, yLoading);
		Sleep(15);
		cout << char(219);
	}
}

void ManHinhLoading()
{
	system("cls");
	SetColor(WHITE);
	gotoxy(75,25);cout << "Dang lay du lieu ......";
	for( int i = 0 ; i <= 50 ; i++ ){
		Textcolor(13);
		gotoxy(59 + i,27);cout << char(219);
		Textcolor(23);
		gotoxy(82,29);cout << i * 2 << "%";
			Sleep(50);
		}
}

//ve khung vien
void VeKhungMenu()
{
	ShowCur(false);
	int i;
	gotoxy(xOrdinal, yOrdinal);
	// ve hang ngang tren
	for (i = 0; i <= xMax; i++)
	{
		SetColor(WHITE);
		cout << char(219);
	}

	// ve hang ngang duoi
	gotoxy(xOrdinal, yOrdinal + 20);
	for (i = 0; i <= xMax; i++)
	{
		SetColor(WHITE);
		cout << char(219);
	}

	// ve hang doc trai
	for (int i = 1; i < yOrdinal + 20; i++)
	{
		gotoxy(xOrdinal, yOrdinal + i);
		SetBGColor(WHITE);
		cout << "  ";
	}

	// ve hang doc phai
	for (int i = 1; i < yOrdinal + 20; i++)
	{
		gotoxy(xMax - 1, yOrdinal + i);
		SetBGColor(WHITE);
		cout << "   ";
	}
}

// highlight o Main Menu
/*void HighLight(string key, int index, int newColor, int oldColor)
{
	// den dia chi can highlight
	gotoxy(xMainMenus[index] - 1, yMainMenu);
	SetBGColor(newColor);
	SetColor(WHITE);
	cout << key;
	SetBGColor(oldColor);
}*/
// highlight o Menu con
void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor)
{
	// den dia chi can highlight
	gotoxy(x - 1, y[index]);
	SetBGColor(newColor);
	SetColor(WHITE);
	cout << key;
	SetBGColor(oldColor);
}
// ve Menu chinh
void MainMenu(string key[], int nKey)
{
	normalBGColor();
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xMainMenus[i], yMainMenu, key[i],(int)key[i].length());
	}
}

void BangDangNhap()
{
	//normalBGColor();
	SetBGColor(BLACK);
	
	// set khung
	gotoxy(xOrdinal + 64, yOrdinal + 29);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);
	for(int i = 30;i<45;i++)
	{
		gotoxy(xOrdinal + 64, yOrdinal + i);
		cout << char(186) << setw(40) << setfill(' ') << char(186);
	}
	gotoxy(xOrdinal + 64, yOrdinal + 45);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);
}
// ve cac Menu con
void SubMainMenuAdmin(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenusAdmin, ySubMainMenusAdmin[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenuAdmin[0], 0, xSubMainMenusAdmin, ySubMainMenusAdmin, GREEN, AQUA);
	ShowCur(false);
}

void SubMainMenuGuest(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenusGuest, ySubMainMenusGuest[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenuGuest[0], 0, xSubMainMenusGuest, ySubMainMenusGuest, GREEN, AQUA);
	ShowCur(false);
}

void BangNhapSXTK()
{
	normalBGColor();
	SetBGColor(BLACK);
	
	// set khung
	gotoxy(xOrdinal + 100, yOrdinal + 5);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);
	for(int i = 6;i<20;i++)
	{
		gotoxy(xOrdinal + 100, yOrdinal + i);
		cout << char(186) << setw(40) << setfill(' ') << char(186);
	}
	gotoxy(xOrdinal + 100, yOrdinal + 20);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);
}

void BangNhapSoTrang()
{
	normalBGColor();
	SetBGColor(BLACK);
	
	// set khung
	gotoxy(xOrdinal + 98, yOrdinal + 36);
	cout << char(201) << setw(60) << setfill(char(205)) << char(187);
	for(int i = 37;i<40;i++)
	{
		gotoxy(xOrdinal + 98, yOrdinal + i);
		cout << char(186) << setw(60) << setfill(' ') << char(186);
	}
	gotoxy(xOrdinal + 98, yOrdinal + 40);
	cout << char(200) << setw(60) << setfill(char(205)) << char(188);
}

void BangNhapSX1()
{
	normalBGColor();
	SetBGColor(BLACK);
	
	// set khung
	gotoxy(xOrdinal + 100, yOrdinal + 24);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);
	for(int i = 25;i<30;i++)
	{
		gotoxy(xOrdinal + 100, yOrdinal + i);
		cout << char(186) << setw(40) << setfill(' ') << char(186);
	}
	gotoxy(xOrdinal + 100, yOrdinal + 30);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);
}

void BangNhapSX2()
{
	normalBGColor();
	SetBGColor(BLACK);
	
	// set khung
	gotoxy(xOrdinal + 100, yOrdinal + 34);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);
	for(int i = 35;i<40;i++)
	{
		gotoxy(xOrdinal + 100, yOrdinal + i);
		cout << char(186) << setw(40) << setfill(' ') << char(186);
	}
	gotoxy(xOrdinal + 100, yOrdinal + 40);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);
}

void BangNhapTK()
{
	normalBGColor();
	SetBGColor(BLACK);
	
	// set khung
	gotoxy(xOrdinal + 90, yOrdinal + 25);
	cout << char(201) << setw(60) << setfill(char(205)) << char(187);
	for(int i = 26;i<29;i++)
	{
		gotoxy(xOrdinal + 90, yOrdinal + i);
		cout << char(186) << setw(60) << setfill(' ') << char(186);
	}
	gotoxy(xOrdinal + 90, yOrdinal + 29);
	cout << char(200) << setw(60) << setfill(char(205)) << char(188);
}

void BangHienThiCDT()
{
	normalBGColor();
	SetBGColor(BLACK);
	
	// set khung
	gotoxy(xOrdinal + 55, yOrdinal + 15);
	cout << char(201) << setw(50) << setfill(char(205)) << char(187);
	for(int i = 16;i<25;i++)
	{
		gotoxy(xOrdinal + 55, yOrdinal + i);
		cout << char(186) << setw(50) << setfill(' ') << char(186);
	}
	gotoxy(xOrdinal + 55, yOrdinal + 25);
	cout << char(200) << setw(50) << setfill(char(205)) << char(188);
}
// ham hien thi bang thong tin
void ShowSmall(string key[], int nKey, int xShowSmall[])
{
	ShowCur(true);
	normalBGColor();

	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++)
	{
		gotoxy(xShowSmall[i] + 2, yShowSmall + 1);
		cout << key[i];
	}

	//hien thi cot hai ben 
	SetColor(WHITE);
	for (int j = yShowSmall+1; j <= yShowSmall + 47; j++)
	{
		for (int i = 0; i < nKey +1; i++)
		{
			gotoxy(xShowSmall[i], j);

			cout << char(186);
		}
	}

	//hien thi dong hai ben
	for (int i = xShowSmall[0]; i <= xShowSmall[nKey]; i++)
	{
		gotoxy(i, yShowSmall);
		if (i == xShowSmall[1] || i == xShowSmall[2] || i == xShowSmall[3] || i == xShowSmall[4] )
			cout << char(203);//nga 3
		else if (i == xShowSmall[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xShowSmall[nKey])
		{
			cout << char(187);//moc trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yShowSmall + 2);
		if (i == xShowSmall[1] || i == xShowSmall[2] || i == xShowSmall[3] || i == xShowSmall[4] )
			cout << char(206); //nga 4
		else if (i == xShowSmall[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xShowSmall[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yShowSmall + 48);
		if (i == xShowSmall[nKey])
		{
			cout << char(188); //nga 3 sang trai
		}
		else if (i == xShowSmall[1] || i == xShowSmall[2] || i == xShowSmall[3] || i == xShowSmall[4] )
			cout << char(202);
		else if (i == xShowSmall[0])
			cout << char(200); //nga 3 sang phai
		else
		{
			cout << char(205); //duong thang ngang
		}
	}
}

void EffectiveMenu(int pos, int flag)
{
	if (flag == 1)
	{
		ShowCur(false);
		gotoxy(xMainMenus[pos + 1] - 1, yMainMenu);
		SetBGColor(GREEN);
		SetColor(WHITE);
		cout << keyMainMenu[pos + 1];

		gotoxy(xMainMenus[(pos + 2) % 3 + 1] - 1, yMainMenu);
		normalBGColor();
		cout << keyMainMenu[(pos + 2) % 3 + 1];
	}
}

void EffectiveSubMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag)
{
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1)
	{
		ShowCur(false);

		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(GREEN);
		SetColor(WHITE);
		cout << key[pos];

		gotoxy(xSubMenu - 1, ykey[(pos + nkey - 1) % nkey]);
		SetBGColor(BLACK);
		SetColor(LIGHT_YELLOW);
		cout << key[(pos + nkey - 1) % nkey];
	}
	else if (flag == 2) 
	{
		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);

		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(GREEN);
		SetColor(WHITE);
		cout << key[pos];

		gotoxy(xSubMenu - 1, ykey[(pos + 1) % nkey]);
		SetBGColor(BLACK);
		SetColor(LIGHT_YELLOW);
		cout << key[(pos + 1) % nkey];
	}
}

int ChooseMainMenu(int nKey)
{
	int currposMainMenu = -1;
	ShowCur(false);

	int kb_hit;
	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
			{
				kb_hit = _getch();
			}

			switch (kb_hit)
			{
			case TAB: 
				Beep(400, 50);
				if (currposMainMenu < nKey - 2)
				{
					currposMainMenu = currposMainMenu + 1;
				}
				else {
					currposMainMenu = 0;//move to first value in menu system
				}
				EffectiveMenu(currposMainMenu, 1);
				break;

			case ENTER: 
				Beep(600, 50);
				return currposMainMenu;
			}
		}
	}

}

int ChooseSubMenu(string key[], int xSubMenu, int ykey[], int nkey)
{
	int currposSubMainMenu = 0;
	ShowCur(false);

	int kb_hit;
	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit)
			{
			case KEY_UP:
				if (currposSubMainMenu > 0)
				{
					currposSubMainMenu = currposSubMainMenu - 1;
				}
				else {
					currposSubMainMenu = nkey - 1;
				}
				Beep(300, 50);
				EffectiveSubMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 2);
				break;

			case KEY_DOWN:
				if (currposSubMainMenu < nkey - 1)
				{
					currposSubMainMenu = currposSubMainMenu + 1;
				}
				else {
					currposSubMainMenu = 0;
				}
				Beep(300, 50);
				EffectiveSubMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 1);
				break;

			case ENTER:
				Beep(600, 50);
				return currposSubMainMenu;
			}
		}
	}
}
// ve bang nhap thong tin
void BangNhap(int x, int y, int nngang, string key[], int nkey)
{
	int i;
	// ve khung
	SetBGColor(BLACK);
	SetColor(WHITE);
	for (i = 0; i < nkey + 2; i++)
	{
		gotoxy(x, y + i);
		if (i == 0)
		{
			cout << char(218) << setw(nngang) << setfill(char(196)) << char(191);
		}
		else if (i == nkey + 1)
		{
			cout << char(192) << setw(nngang) << setfill(char(196)) << char(217);
		}
		else {
			cout << char(179);
			cout << key[i - 1];
			gotoxy(x + nngang, y + i);
			cout << char(179);
		}
	}
	normalBGColor();
}
// ve bang huong dan Guides
void BangGuides(int x, int y, int nngang, string key[], int nkey)
{
	int i;
	// ve khung
	SetBGColor(BLACK);
	SetColor(GREEN);
	for (i = 0; i < nkey + 2; i++)
	{
		gotoxy(x, y + i);
		if (i == 0)
		{
			cout << char(218) << setw(nngang) << setfill(char(196)) << char(191);
		}
		else if (i == nkey + 1)
		{
			cout << char(192) << setw(nngang) << setfill(char(196)) << char(217);
		}
		else {
			cout << char(179);
			cout << key[i - 1];
			gotoxy(x + nngang, y + i);
			cout << char(179);
		}
	}
	normalBGColor();
}