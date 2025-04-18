#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;

class hospital_management
{
private:
    
    string name; 
    string contact; 
    string blood; 
    string aadhar; 
    string dr; 
    string disease; 
    int age; 
	int id; 
    string address; 

public:
    
    void menu(); 
    void waitForEnter(); 
    void insert(); 
    void display(); 
    void modify(); 
   	void search(); 
    void deleted(); 
};

void hospital_management::menu() 
{
    
    while (true)
    {
        int choice;
        char x; // 
        system("cls"); 
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> HOSPITAL MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. NEW ENTRY AND TOKEN GENERATION" << endl;
        cout << "\t\t\t\t\t 2. DISPLAY PATIENT\'S INFORMATION" << endl;
        cout << "\t\t\t\t\t 3. MODIPHY PATIENT\'S HISTORY/DATABASE" << endl;
        cout << "\t\t\t\t\t 4. SEARCH PATIENT\'S INFORMATION" << endl;
        cout << "\t\t\t\t\t 5. DELETE PATIENT\'S HISTORY/DATABASE" << endl;
        cout << "\t\t\t\t\t 6. EXIT" << endl;

        cout << "\t\t\t\t\t......................................................." << endl;
        cout << "\t\t\t\t\t>> ENTER THE NUMBER OF THE OPTION WHICH YOU CHOESE : <<" << endl;
        cout << "\t\t\t\t\t......................................................." << endl;
        
        cin >> choice;
        
        switch (choice)
        {
        case 1:
        	
            do
            {
                insert(); 
                cout << "\n\n\t\t\t Add Another Patient Record Press  (Y, N) : ";
                cin >> x; 
            } while (x == 'y' || x == 'Y');
            waitForEnter();
            break;
        case 2:
            display(); 
            break;
        case 3:
            modify(); 
            break;
        case 4:
            search(); 
            break;
        case 5:
            deleted(); 
            break;
        case 6:
            system("cls");
            cout<<"\n\t\t\tTHANK YOU FOR GIVINIG US AN OPPORTUNITY TO SERVE YOU\n\t\t\t\t\tPLEASE VISIT US AGAIN \n";
            cout << "\n\n\t\t\t>> HOSPITAL MANAGEMENT SYSTEM - By  SAAARC CLINIC <<\n\n";
            Sleep(10);
            exit(0); 
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        getch();
    }
}

void hospital_management::insert()
{
    system("cls");
    id=0;
    fstream file;
    file.open("hospital_Record.txt"); 
    while(file) 
    
	file >> name >> id >> blood >> age >> aadhar  >> contact >> disease >> dr >> address;
    file.close(); 
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl; 
    cout << "------------------------------------------------------------- Patient Insert Data -----------------------------------------------------------------" << endl; 
    cout << "\n Enter Name of Patient : "; 
	cin >> name; 
	
    cout << "\n Enter Patient\'s Blood group : "; 
    cin >> blood ; 
    
    cout << "\n Enter Patient\'s Age : "; 
    cin >> age; 
    
    cout << "\n Enter Patient\'s Aadhar No. : "; 
    cin >> aadhar; 
	
	cout << "\n Enter Patient\'s Contact Number : "; 
	cin >> contact; 
    
	cout << "\n Enter Patient\'s Disease : "; 
	cin >> disease; 
	
	cout << "\n Enter Doctor\'s Name: "; 
	cin >> dr; 
	
	cout << "\n Enter Patient\'s address: "; 
	cin >> address; 
    
	id++; 
	
    file.open("hospital_Record.txt", ios::app | ios::out); 
    
	file << endl << name << endl << id << endl << blood  << endl << age << endl << aadhar << endl <<contact << endl << disease << endl << dr << endl << address << endl;
    file.close(); 
}
void hospital_management::display()
{
    
    system("cls");
    
    int total = 1;
    
    fstream file;
    
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    
    cout << "------------------------------------------------------------- Patient Record Data -----------------------------------------------------------------" << endl;
    
    file.open("hospital_Record.txt", ios::in);
    
    if (!file)
    {
        
        cout << "\n\t\t\tNo Data is Present... ";
        
        file.close();
    }
    
    else
    {
        
        file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
       
        cout << "\n -----------------------------------------------------------------------------------------------------------------------------------------------";
        
        cout << "\n ||  ID   ||    NAME      ||  BLOOD GROUP    ||    AGE      ||   AADHAR NUMBER  || CONTACT NUMBER ||    DISEASE    ||   DOCTOR NAME   || ADDRESS ||";
        
        cout << "\n -----------------------------------------------------------------------------------------------------------------------------------------------";
        
        while (!file.eof())
        {
           
            cout << "\n";
           
            cout <<" SAAARC-"<< id <<"\t"<< name <<"\t"<< blood <<"\t\t"<< age <<"\t\t"<< aadhar <<"\t"<< contact <<"\t\t"<< disease << " \tDr. " << dr <<"\t"<< address;
         
            file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        }
    }
    
    file.close();
    
    waitForEnter();
}
void temp(){
	cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------- Patient Modify Data -----------------------------------------------------------------" << endl;
}

void hospital_management::modify() 
{
    system("cls");
    int checkId;
	int x, y, z;   
	int found = 0; 
	fstream file, file1;
    temp(); 
	file.open("hospital_Record.txt", ios::in);
    
	if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close(); 
    }
    else
    {
        cout << "\nEnter patient\'s id: SAAARC-";
        
		cin >> checkId; 
        
		file1.open("record.txt", ios::out);
		
        file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        
       
		while (!file.eof())
        {
        	
            if (checkId == id)
            {
            	loop : 
				cout << "\n\tWhich data you want to modify : "<<endl;
            	cout << "\t 1. NAME" << endl;
        		cout << "\t 2. BLOOD GROUP" << endl;
        		cout << "\t 3. AGE" << endl;
        		cout << "\t 4. AADHAR NUMBER" << endl;
        		cout << "\t 5. CONTACT NUMBER" << endl;
        		cout << "\t 6. DISEASE" << endl;
        		cout << "\t 7. DOCTOR NAME" << endl;
        		cout << "\t 8. ADDRESS" << endl;
				loop2 :
				cout << "Enter your choice : ";
        		
        		cin >> x;
                
				
				if(x==1){
					cout << "\n Enter Name of Patient: "; 
                	cin >> name; 
				}
				else if (x==2){
                	cout << "\n Enter Patient\'s Blood Group: "; 
                	cin >> blood; 
				}
                else if(x==3){
					cout << "\n Enter Patient\'s Age: "; 
                	cin >> age; 
				}
				else if(x==4){
					cout << "\n Enter Patient\'s Aadhar number : "; 
                	cin >> aadhar; 
				}
                else if(x==5){
					cout << "\n Enter Patient\'s Contact number: "; 
                	cin >> contact; 
                }
                else if(x==6){
					cout << "\n Enter Patient\'s Disease : "; 
					cin >> disease; 
                }
                else if(x==7){
					cout << "\n Enter Doctor\'s Name: "; 
					cin >> dr; 
                }
                else if(x==8){
					cout << "\n Enter Patient\'s Address: "; 
                	cin >> address; 
				}
				
				else{
					cout << "\nInvalid Input.. Please Try Again..";  
					goto loop2; 
				}
				
				
                cout << "\n\nSuccessfully Modify Details Of Patient";
                cout << "\n\n\t\t\t If you want to modify another data :-"<<endl;
                cout << "\t\t\t\t 1. Press (1) for Yes"<<endl;
                cout << "\t\t\t\t 2. press (0) for No "<< endl;
                loop1 :
				cout << " Enter your choice : ";
                
				cin >> z;
                
				if(z==1){
                	system("cls");
                	temp(); 
                	goto loop; 
				}
				else if(z==0){
					
					file1 <<endl<< name << endl << id << endl << blood  << endl << age << endl << aadhar << endl <<contact << endl << disease << endl << dr << endl << address << endl;
                	found++; 
				}
				else{
					cout << "\nInvalid Input.. Please Try Again.."; 
					goto loop1; 
				}
            }
            else
            {
                
				file1 <<endl<< name << endl << id << endl << blood  << endl << age << endl << aadhar << endl << contact << endl << disease << endl << dr << endl << address << endl;

            }
            
        	file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        }
        
        if (found == 0)
        {
            cout << "\n\n\tPatient\'s ID Not Found.. Please Try Again"; 
        }
        
        file1.close(); 
        file.close(); 
        
        remove("hospital_Record.txt");
        
        rename("record.txt", "hospital_Record.txt");
    }
    waitForEnter();
}

void hospital_management::search() 
{                                  
    system("cls");
    fstream file;
    int checkId,x,found=0;
    string checkname;
	cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------- Patient Search Data -----------------------------------------------------------------" << endl;
    file.open("hospital_Record.txt", ios::in); 
    loop : 
    
	cout << "\n\t\t\t-| Press [1] for search by id |-"<<endl; 
    cout << "\t\t\t-| Press [2] for search by name |-"<<endl; 
    cout << "Enter your option : "<< endl; 
    cin >> x; 
	if(x==1){ 
	
		cout << "\n\nEnter Patient\'s ID: SAAARC-"; 
    	cin >> checkId; 
	}
	
    else if(x==2){ 
    	
		cout << "\n\nEnter Patient\'s name : "; 
    	cin >> checkname; 
	}
	
	else{
		cout << "\nInvalid Input.. Please Try Again.."; 
		goto loop;
	}
    if (!file) 
    {
    	
        cout << "\n\t\t\tNo Data is Present... "; 
        file.close(); 
    }
    else
    {
    	
        file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;

        while (!file.eof()) 
        {
        	
            if (checkId == id || checkname == name) 
            {
              
			    cout << "\n---------------------\n";
                cout << "Patient\'s Name : " << name << endl;
                cout << "Patient\'s ID. : SAAARC-" << id << endl;
                cout << "Patient\'s Blood Group : " << blood <<endl;
                cout << "Patient\'s Age : " << age << endl;
                cout << "Patient\'s Aadhar number : " << aadhar << endl;
				cout << "Patient\'s Contact number : " << contact << endl;
                cout << "Patient\'s Disease : " << disease << endl;
        		cout << "Doctor Name : " << dr << endl;
                cout << "Patient\'s Address: " <<  address << endl;
                cout << "---------------------\n" <<endl;
                found++; 
            }
            
            file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        }
        if (!found) 
        {
        	
            cout << "\n\n\tPatient\'s ID Not Found.. Please Try Again"; 
        }
    }
    file.close(); 
    waitForEnter(); 
}

void hospital_management::deleted() 
{
    system("cls"); 
    int checkId; 
    fstream file, file1;
    int found = 0;
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl; 
    cout << "------------------------------------------------------------- Patient Delete Data -----------------------------------------------------------------" << endl;
    file.open("hospital_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Patient\'s Id : SAARC-"; 
        cin >> checkId;
        file1.open("record.txt", ios::out);
        file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;//
        while (!file.eof())
        {
            if (checkId != id)
            {
				file1 <<endl<< name << endl << id << endl << blood  << endl << age << endl << aadhar << endl << contact << endl << disease << endl << dr << endl << address << endl; 
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data"; 
            }
            file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        }
        if (found == 0)
        {
            cout << "\n\n\tPatient\'s ID Not Found.. Please Try Again"; 
        }
       
    } file1.close();
        file.close();
        remove("hospital_Record.txt");
        rename("record.txt", "hospital_Record.txt");
        waitForEnter(); 
}

void hospital_management::waitForEnter()
{
    cout << "\n\nPress enter to go back: ";
    cin.get();
}


int main()
{
   
    hospital_management system;
    system.menu();
    return 0;
}