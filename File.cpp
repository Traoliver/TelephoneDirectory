#include<iostream.h>
#include <stdio.h>
#include <fstream.h>
#include <conio.h>
#include <string.h>
#include<list>
#include "DanhBa.cpp"
#include "DirectoryManager.cpp"
#define defaultPath D:/DoAn1/danhba.csv
using namespace std;
class FileAction{
	public: 
	void StringToDirectory(string line, list<DanhBa> &li){
 		list<DanhBa>  :: iterator itr=li.begin();
	 	int n = line.length();
	 	int lastPosition = 0;
	 	int property = 0;
	 	DanhBa c1 ;
		 //cout<<n<<endl;
		for(int i = 0 ; i < n; i++){
  		 // cout<<line[i]<<endl;
		   string value;
			if(line[i]==','){
			    if(i>1){
 		 		 	value = line.substr(lastPosition,i-lastPosition);	
    				lastPosition = i+1;	
    			//	cout<<i<<endl;    
			    }else{
			         value = line.substr(lastPosition,i);
			        lastPosition = i+1;	
			     //  cout<<i<<endl;   
			    }
			 	if(i==n-2) {
			    c1.setRank(atoi( line.substr(lastPosition,1).data()));
				}
				switch(property){
					case 0: 
						c1.setID(atoi(value.data()));
						break;
					case 1:
						c1.setFullName(value);
						break;
					case 2:
						c1.setPhone(value);
						break;
					case 3:
						c1.setArea(value);
						break;

				}
				property++;		
			}	
		}
		li.insert(itr,c1);
 	}
 	
	DanhBa StringToFreight(string line){
	 	int n = line.length()-1;
 		//	for(int i = 0; i<n ;i++)cout<<line[i]<<" ";
		int lastPosition = 0;
	 	int property = 0;
		string phone ;
		long freight;
 		//cout<<n<<endl;
		for(int i = 0 ; i <= n; i++){
  		 // cout<<line[i]<<endl;
		   string value;
			if(line[i]==','){
			    if(i>1){
		 		 	phone = line.substr(lastPosition,i-lastPosition);	
					lastPosition = i+1;	
					
				//	cout<<value<<" ";    
			    }
 				/*if(i==n-2) {
			    c1.setRank(atoi( line.substr(lastPosition,1).data()));
				}
				if(property==0)
						c1.setID(atoi(value.data()));
				property++;	*/	
			}	
			else if(i==n){
					freight = atol(line.substr(lastPosition,i).data());
				//	cout<<value<<" "; 	
				}
		}
		DanhBa temp;
		temp.setPhone(phone);
		temp.setFreight(freight);
		return temp;		
	}
	
 	list<DanhBa> ReadFile(char filepath[]){
 	//	cout<<"Enter file path: ";
	 //	cin.getline(filepath,200);
	 //	if(filepath=="") 
  		//strcpy(filepath,);
 		ifstream getfile; 
	 	getfile.open(filepath);
	 	string line;
 		list<DanhBa>  li;
	
	 	if(getfile.is_open()){
	 		getline(getfile,line);
	 		while(getline(getfile,line)){
	 		//	cout<<line<<endl;
	 			StringToDirectory(line,li);
		 	}
		 	getfile.close();
	 	}else {
	 	 cout<<"can't open file: "<<filepath<<endl;
	 	}
		 //cout<< li.size();
	 	return li;
 	}
	 //id,full name,phone,area,ran
 
 	void WriteFlie(list<DanhBa> &li,char filepath[]){
 		ofstream  file;
		 file.open(filepath);
 		if(file.is_open()){
 			list<DanhBa> :: iterator itr = li.begin();
		 	file<<"id,full name,phone,area,rank\n";
		 	
		 	while(itr != li.end()){	
		 		DanhBa a = *itr;
		 		file<<a.writeCsv()<<"\n";
		 		itr++;
	 		}
		 }
 		file.close();
 	}
 	list<DanhBa> ReadFileFreight(list<DanhBa>  &listDir, char filepath[] , DirectoryManager manager ){
	 	ifstream getfile; 
	 	getfile.open(filepath);
	 	string line;
	 	if(getfile.is_open()){
	 		getline(getfile,line);
	 		int i = 15;
	 		while(getline(getfile,line)){
				DanhBa temp = StringToFreight(line);
				list<DanhBa> :: iterator itr = listDir.begin();
 				while(itr!=listDir.end()){
 					DanhBa newDir = *itr;
					if(newDir.getPhone().compare(temp.getPhone())==0){
						newDir.setFreight(temp.getFreight());
						manager.printf5(newDir,i+=2);
						*itr = newDir;
						break;
					}
					itr++;
				}
		 	}
		 	getfile.close();
		 	return listDir;
	 	}else {
	 	 cout<<"can't open file: "<<filepath<<endl;
	 	}
 	}
};
/* int main(){
 	FileAction action ;
 	list<DanhBa> listDir;
 	DanhBa a ;
	a.setPhone("0366947190");
	list<DanhBa>  :: iterator itr=listDir.begin();	
		
 		listDir.push_front(a);
 		

 	action.WriteFlie(listDir, "D:/DoAn1/DanhBaInRa.csv");
 //	list<DanhBa> :: iterator itr = listDir.begin();
 //	a = *itr;
 //	cout<<" "<<a<<endl;
 }*/