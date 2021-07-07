#include<iostream>
#include<list>
#include<string>
#include<iterator>  
#include "DanhBa.cpp"
#include "Ve_Hinh.cpp"
#include "marcro.cpp"
#include "mylib.cpp"
using namespace std;
#ifndef Directory_Manager
#define Directory_Manager
class DirectoryManager {
	private : 
		list<DanhBa> listDir;
	 	//int  maxIndex  ;
	public :
	
		list<DanhBa> getList(){
			return listDir;
		}	
		
		bool isNumber(string line) {
			bool number = true;
			int n = line.length();
			for (int i = 0; i<n; i++)
				if (isalpha(line[i])) {
					return false;
				}
			return true;
		}
		
		void setList(list<DanhBa> &li){
			listDir.clear();
			list<DanhBa> :: iterator itr = li.begin();
			while(itr != li.end()){
		 		this->listDir.push_front(*itr);
				itr++;
			}
		}
		// insert into the last of list
		void insertOne(){
			int nngang = (int)keyBangNhapAdmin[0].length();
			CreateBox(X_NOTIFY, Y_NOTIFY, "NOTIFICATIONS: ", 62);
			BangNhap(xShowSmall[5] + 14, yShowSmall + 10, nngang, keyBangNhapAdmin, 10);
			BangGuides(xShowSmall[5] + 14, yShowSmall + 30, nngang, keyGuide, 5);
			gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall +13);
			string param[4];
			getline(std::cin, param[0]);
			bool check = false;
			do {
			gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall + 15);
			getline(std::cin, param[1]);
			check = !isNumber(param[1]);
			if (	param[1].length() < 10 || param[1].length() > 10)
			{
				check = true;
				gotoxy(110,30);
				cout<<"Ban nhap chua du so dien thoai";
				Sleep(1000);
				gotoxy(110,30);
				cout<<"                                ";
				gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall + 15);
				cout<<"                           ";
			}
			else check = false;
			if(!check){
				for(list<DanhBa> :: iterator itr = listDir.begin();itr != listDir.end() ;itr++){
					DanhBa temp = *itr;
					if(temp.getPhone().compare(param[1])==0){
						check = true;
						gotoxy(108,30);
						cout<<"So dien thoai bi trung. Vui long kiem tra lai!";
						Sleep(1000);
						gotoxy(108,30);
						cout<<"                                              ";
						gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall + 15);
						cout<<"                           ";
						break;
					}
				}
			}
		} while(check);
		gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall + 17);
		getline(std::cin,param[2]);
		check = false;
		do {
			gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall + 19);
			getline(std::cin, param[3]);
			if (isNumber(param[3])) {
				if (atoi(param[3].c_str()) < 1 || atoi(param[3].c_str()) > 5) {
					check = true;
				} else check = false;
			} else check = true;
		} while (check);
			int Id = (listDir.back().getID()<0)? 1 : listDir.back().getID()+1;
			DanhBa Newdirec;
			Newdirec.Input(Id,param[0],param[1],param[2],atoi(param[3].c_str()));
			list<DanhBa> :: iterator  itr = listDir.end();
			//Newdirec.Input(Id,param[0],param[1],param[2],atoi(param[3].c_str()));
			listDir.push_back(Newdirec);
			//cin.ignore();
		}
		
		// remove . take the object need to remove , to last of list and delete it
		void removeOne(){
			int ID;
			string a = " * NHAP VAO ID CUA PHAN TU CAN XOA:           ";
			SetBGColor(BLACK);
			SetColor(WHITE);
			CreateBox(xShowSmall[5] + 20, yShowSmall + 5, a, (int)a.length());
			gotoxy(135, 8);
			cin>>ID;
			list<DanhBa> :: iterator  itr = listDir.begin();
			DanhBa Direc;
			Direc.setID(ID);
			bool have = false;
			while(itr != listDir.end()){
				if(*itr == Direc){
					list<DanhBa> :: iterator  Newitr = itr;
					while(Newitr != listDir.end()){				
						Newitr++;
						if(Newitr != listDir.end()) *itr  = *Newitr;
						itr++;
					}
					have = true;
					break;	
				}
				itr++;
			}
			if(have) listDir.pop_back();
		}
		// find the object by Id and change it
		void updateOne(){
			int ID;
			string a = " * NHAP VAO ID CUA PHAN TU CAN SUA:           ";
			SetBGColor(BLACK);
			SetColor(WHITE);
			CreateBox(xShowSmall[5] + 20, yShowSmall + 5, a, (int)a.length());
			gotoxy(135, 8);
			cin>>ID;
			list<DanhBa> :: iterator  itr = listDir.begin();
			DanhBa Direc;
			int nngang = (int)keyBangSuaAdmin[0].length();
			normalBGColor();
			CreateBox(X_NOTIFY, Y_NOTIFY, "NOTIFICATIONS: ", 59);
			BangNhap(xShowSmall[5] + 14, yShowSmall + 10, nngang, keyBangSuaAdmin, 10);
			BangGuides(xShowSmall[5] + 14, yShowSmall + 30, nngang, keyGuide, 5);
			gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall +13);
			Direc.setID(ID);
			cin.ignore();
			while(itr != listDir.end()){			
				if(*itr == Direc){
					
					string param[4];
					gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall +13);
					getline(std::cin, param[0]);
					bool check = false;
					do {
						gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall + 15);
						getline(std::cin, param[1]);
						check = !isNumber(param[1]);
						if (param[1].length() < 10 || param[1].length() > 10)
						{
							check = true;
							gotoxy(110,30);
							cout<<"Ban nhap chua du so dien thoai";
							Sleep(1000);
							gotoxy(110,30);
							cout<<"                                ";
							gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall + 15);
							cout<<"                           ";
						}
						else check = false;
						if(!check){
							int i = 1;
							for(list<DanhBa> :: iterator itr = listDir.begin();itr != listDir.end() ;itr++){
								DanhBa temp = *itr;
								if(i != ID){
									if(temp.getPhone().compare(param[1])==0){
									check = true;
									break;
									}
								}								
								i++;
							}
						}
					} while (check);
					gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall + 17);
					getline(std::cin, param[2]);
					check = false;
					do {
						gotoxy((xShowSmall[5] + 16 + nngang / 2), yShowSmall + 19);
						getline(std::cin, param[3]);
						if (isNumber(param[3])) {
							if (atoi(param[3].c_str()) < 1 || atoi(param[3].c_str()) > 5) {
								check = true;
							}
							else check = false;
						}
						else check = true;
					} while (check);
					Direc.setFullName(param[0]);
					Direc.setPhone(param[1]);
					Direc.setArea(param[2]);
					Direc.setRank(atoi(param[3].c_str()));
					*itr = Direc;
				}
			itr++;
			}
		}
		// find by id
		void Find(){
			int ID;
			cout<<" Nhap vao Id: ";
			cin>>ID;
			list<DanhBa> :: iterator  itr = listDir.begin();
			DanhBa Direc;
			Direc.setID(ID);
			while(itr != listDir.end()){
				if(*itr == Direc){
					cout<< 	*itr;
				}
			}
		}
		
		void printPageSmall(int page,int record){
			list<DanhBa> :: iterator  itr = listDir.begin();
			int start = ((page < 2)? 0 : page-1)*record;
			int end   = page*record;
			int count = 0;
			int i = 5;
			ShowSmall(keyShowSmall, 5, xShowSmall);
			while(itr != listDir.end()){
				if(count >= start && count <end)printfShowSmall(*itr,i+=2);
				if(count > end) break;
				itr++;
				count++;
			}
		}
		
		// print the list by page 
		void printPage(int page,int record){
			list<DanhBa> :: iterator  itr = listDir.begin();
			int start = ((page < 2)? 0 : page-1)*record;
			int end   = page*record;
			int count = 0;
			int i = 6;
			normalTextColor();
			string text = "    IN DANH BA DIEN THOAI   ";
			CreateBox(70, 2, text, (int)text.length());
			SetBGColor(GREEN);
			
			gotoxy(69, 2);
			cout << "    IN DANH BA DIEN THOAI   ";
			gotoxy(20, 5);
			cout << "  ID  ";
			gotoxy(42, 5);
			cout << "  FULL NAME  ";
			gotoxy(80, 5);
			cout << "  PHONE  ";
			gotoxy(110, 5);
			cout << "  AREA  ";
			gotoxy(135, 5);
			cout << "  RANK  ";
			normalBGColor();
			SetColor(WHITE);
			while(itr != listDir.end()){
				
				if(count >= start && count <end)printfDic(*itr,i+=2);
				if(count > end) break;
				itr++;
				count++;
			}
		}
		
		void printAll(){
			list<DanhBa> :: iterator  itr = listDir.begin();
			while(itr != listDir.end()){
			cout<<*itr;
			itr++;	
			}
		}
		void printfShowSmall(DanhBa dic,int i){
				gotoxy(5,i);
	 			cout<<dic.getID();
	 			gotoxy(12,i);
			 	cout<<dic.getFullName();
			 	gotoxy(35.5,i);
			 	cout<<dic.getPhone();
			 	gotoxy(49,i);
			 	cout<<dic.getArea();
			 	gotoxy(75,i);
			 	cout<<dic.getRank();
		 }
		 void printfDic(DanhBa dic,int i){
				gotoxy(23,i);
	 			cout<<dic.getID();
	 			gotoxy(40,i);
			 	cout<<dic.getFullName();
			 	gotoxy(80,i);
			 	cout<<dic.getPhone();
			 	gotoxy(110,i);
			 	cout<<dic.getArea();
			 	gotoxy(138,i);
			 	cout<<dic.getRank();
		 }
		 void printf5(DanhBa dic,int i){
				gotoxy(17,i);
	 			cout<<dic.getID();
	 			gotoxy(30,i);
			 	cout<<dic.getFullName();
			 	gotoxy(65,i);
			 	cout<<dic.getPhone();
			 	gotoxy(91,i);
			 	cout<<dic.getArea();
			 	gotoxy(124,i);
			 	cout<<dic.getRank();
			 	gotoxy(140,i);
			 	cout<<dic.getFare();
		 }
};
#endif Directory_Manager

