#include<iostream.h>
#include<conio.h>
#include <sstream>

using namespace std;
#ifndef DANH_BA
#define DANH_BA 

class DanhBa{
	private:
		int Id;
		string fullname;
		string phone;
		string area;
		int rank;
		long freight;
	public: 
		DanhBa(){
			Id = 0;
		 	fullname = "";
		 	phone = "";
		 	area = "";
		 	rank = 0; 
		 	freight = 0;
		}
		~DanhBa(){
		}
		void setFreight( long	 freight){
			this->freight = freight;
		}
		void setID(int Id){
			this->Id = Id;
		}
		void setFullName(string fullname){
			this->fullname = fullname;
		}
		void setPhone( string phone){
			this->phone = phone;
		}
		void setArea(string area){
			this->area = area;
		}
		void setRank(int rank){
			this->rank = rank;
		}
		long getFreight(){
			return this->freight;
		}
		int getID(){
			return Id;
		}
		string getFullName(){
			return fullname;
		}
		string getPhone(){
			return phone;
		}
		string getArea(){
			return area;
		}
		int getRank(){
			return rank;
		}
		void Input( int Id , string fullname, string phone, string area, int rank){
			this->Id = Id;
			this->fullname = fullname;
			this->phone = phone;
			this->area = area;
			this->rank = rank;
		}
		string writeCsv(){
			// if want to fix , fix here
			stringstream  ostr; 
			string csvString ;
			ostr<<Id;
			csvString.append(ostr.str());
			csvString.append(",");
			csvString.append(fullname);
			csvString.append(",");
			csvString.append(phone);
			csvString.append(",");
			csvString.append(area);
			csvString.append(",");
			ostr<<rank;
			//csvString.append(ostr.str());
		//	csvString.append("\n");
		
			return 	csvString;	
		}
		long getFare(){
			return this->freight*200;
		}
		
	 	friend  ostream & operator << ( ostream &out,  DanhBa &directory){
		 return	out<<"Id :"<<directory.getID()<<",Full name : "<<directory.getFullName()<<", Phone : "<<directory.getPhone()<<"\n , Area: "<<directory.getArea()<<", Favourite: "<<directory.getRank()<<", Debt :"<<directory.getFare()<<endl;		
	 	}
	 	
	 	friend  bool operator == ( DanhBa &A,  DanhBa &B){
		 return	(A.getID() == B.getID()) ?true : false;
	 	}
	 /*	friend  DanhBa operator = ( DanhBa &A,  DanhBa &B){
			A.setID(B.getID());
			A.setFullName(B.getFullName());
			A.setPhone(B.getPhone());
			A.setArea(B.getArea());
			A.setRank(B.getRank());
	 	}*/
	 	friend bool operator < (DanhBa &A,  DanhBa &B){
	 		return (A.getFullName().compare(B.getFullName())<0)?true:false;
	 	}
	 	
	 	friend bool operator > (DanhBa &A, DanhBa &B){
	 		return (A.getArea().compare(B.getArea())<0)?true:false;
	 	}
	 	
	 	 friend bool sortDirectory(DanhBa &a , DanhBa&b , int choise){
 	 		if(choise == 1) return (a.getID()> b.getID())? true : false;
			if(choise == 2) return (a.getRank()>b.getRank())  ? true : false;
			if(choise == 3)	return (strcmpi(a.getFullName().c_str(),b.getFullName().c_str())>0)?true : false;
			if(choise == 4) return (strcmpi(a.getArea().data(),b.getArea().data())>0)? true : false; 
			if(choise == 5) return (a.getPhone().compare(b.getPhone())>=0)? true : false; 
 	 	}
 	 	friend bool equalsDirectory(DanhBa &a , DanhBa&b , int choise){
 	 		if(choise == 1) return (a.getID()== b.getID())? true : false;
			if(choise == 2) return (a.getRank() == b.getRank())  ? true : false;
			if(choise == 3)	return (strcmpi(a.getFullName().data(),b.getFullName().data()) == 0)?true : false;
			if(choise == 4) return (strcmpi(a.getArea().data(),b.getArea().data())== 0)? true : false; 
			if(choise == 5) return (a.getPhone().compare(b.getPhone())==0)? true : false; 
 	 	}
};
#endif