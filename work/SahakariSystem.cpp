//this is.......... program. wittre by colmen and 16.........

#include<iostream>
#include<fstream>
#include<string>
#include <conio.h> 
#include<limits>//gpt dai le vaneko to ignor input error.
//cin.ignore()
#include <sstream> // for stringstream
#include <cstdio>  // for remove() and rename()
using namespace std;


//this is class history
class history{
	
	
	public:
		void showhistory(){
			cout<<"\n\n";
			cout<<"  ============================================\n";
			cout<<"       History of Saza Phulwari Sahakari\n";
			cout<<"  ============================================\n";
			cout<<"\n----------------------------------------------\n";
			cout<<" Establish Year:   2043 B.S\n";
			cout<<" Founder:          Ms.Basanti Sunar\n";
			cout<<" Location:         Khajura('f' gaun)4 Banka\n";
			cout<<"\nObjectives:\n";
			cout<<" -To give every woman a chance to grow.\n";
			cout<<" -To make women able to work for themself and for there family.\n";
			cout<<" -To help people who are not getting there basic need.\n";
			cout<<" -To help childrean for there better eduction.\n";
			//code for milestonr
			cout << "\nMilestones:\n";
            cout << "- 2043 B.S: Established with 14 members.\n";
            cout << "- 2050 B.S: Registered under Cooperative Act.\n";
            cout << "- 2060 B.S: Opened first branch at Nepalgunj.\n";
            cout << "- 2075 B.S: Reached 1000+ active members.\n";
            cout << "---------------------------------------------\n";
                             
		}
};

//for general member ko lagi special
//..............................................................................................................
class member{
	public:
		
		//finction to add member.
		void add_member(){
			
			
		ofstream fout("memb.txt",ios::app);
	char c;
	if(fout.is_open()){
		int id;
		float loan,saving;
		string name,address,phone_number;
		//fout<<"  Sahakari ko General Member list\n";
		 
		//fout<<"ID\tNAME\tAddress\tContact\tLone(Rs)\tSaving\n";
		cout<<"You are in the section of adding member:\n";
		do{
		cout<<"Enter ID:";
		cin>>id;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		cout<<"Name:";
		getline(cin,name);
		cout<<"Address:";
		getline(cin,address);
		
		cout<<"Phone_Number:";
		getline(cin,phone_number);
		
		cout<<"Loan(Rs):";
		cin>>loan;
		
		cout<<"saving(Rs):";
		cin>>saving;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
		
		//putting this values in our file
	//	fout<<"id\tNAME\tAddress\tContact\tLone(Rs)\tSaving\n";
	   fout<<"  "<<id<<"\t\t   "<<name<<"\t\t  "<<address<<"\t    "
	   <<phone_number<<"\t\t \t " <<loan<<"\t\t\t"<<saving<<endl;
	   cout<<"enter 'y' to add another record or enter 'n' for exit:";
	   cin>>c;
	   cin.ignore();
		}while(c=='y');
			fout.close();
		cout<<"input save sucessfually.\n";
	}
	else{
		cout<<"Error....";
	}
	}
	
	
	void show_member(){
		
		
		ifstream fin("memb.txt");
		string text;
		if(fin.is_open()){
			while(getline(fin,text)){
				cout<<text<<endl;
			}
		//	cout<<"----------------------------------------------------------------------------------------------------------
		//	---\n";
		    cout<<"-------------------------------------------------------------------------------------------------------------\n";
				fin.close();
		}
		else{
			cout<<"\nsorry file didn't found.\n";
		}
	
	}
	
	//delete garna ko lagi.....
	void delete_member() {
    ifstream fin("memb.txt");
    ofstream temp("temp.txt");
    
    int delete_id;
    string line;
    bool found = false;

    cout << "Enter ID of the member you want to delete: ";
    cin >> delete_id;

    if (!fin || !temp) {
        cout << "Error opening file.\n";
        return;
    }

    while (getline(fin, line)) {
        stringstream ss(line);
        int id;
        ss >> id;

        // If the ID doesn't match, copy the line to temp.txt
        if (id != delete_id) {
            temp << line << endl;
        } else {
            found = true; // ID found and skipped
        }
    }

    fin.close();
    temp.close();

    if (found) {
        remove("memb.txt");
        rename("temp.txt", "memb.txt");
        cout << "Member with ID " << delete_id << " has been deleted successfully.\n";
    } else {
        remove("temp.txt"); // delete temp if nothing was deleted
        cout << "Member with ID " << delete_id << " not found.\n";
    }
}

//ddddddddddddddddddddddddd
//oooooooooooooooooooooo
    void search_member() {
    ifstream fin("memb.txt");
    string line;
    int choice;
    cout << "Search by:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    bool found = false;

    if (choice == 1) {
        int id_to_search;
        cout << "Enter ID: ";
        cin >> id_to_search;
        while (getline(fin, line)) {
            stringstream ss(line);
            int id;
            ss >> id;
            if (id == id_to_search) {
            	cout<<   " \tID	           NAME	                  Address	    Contact	          Lone(Rs)	         Saving	";
                cout << "\nFound: " << line << endl;
                found = true;
                break;
            }
        }
    } else if (choice == 2) {
        string name_to_search;
        cout << "Enter Name: ";
        getline(cin, name_to_search);
        while (getline(fin, line)) {
            if (line.find(name_to_search) != string::npos) {
            	cout<<   " \tID	           NAME	                  Address	    Contact	          Lone(Rs)	         Saving	";
                cout << "\nFound: " << line << endl;
                found = true;
            }
        }
    } else {
        cout << "Invalid choice.\n";
    }

    if (!found) {
        cout << "Member not found.\n";
    }

    fin.close();
}

   //,................................
   //oooooooooooooooooooooooooooooooo
   //yuttttttttttttttyyyyyyyyyyyyyyy
   void update_member() {
    ifstream fin("memb.txt");
    ofstream temp("temp.txt");

    int update_id;
    cout << "Enter ID of the member to update: ";
    cin >> update_id;
    cin.ignore();

    string line;
    bool found = false;

    while (getline(fin, line)) {
        stringstream ss(line);
        int id;
        ss >> id;

        if (id == update_id) {
            found = true;
            string name, address, phone;
            float loan, saving;

            cout << "Enter new name: ";
            getline(cin, name);
            cout << "Enter new address: ";
            getline(cin, address);
            cout << "Enter new phone number: ";
            getline(cin, phone);
            cout << "Enter new loan amount: ";
            cin >> loan;
            cout << "Enter new saving amount: ";
            cin >> saving;
            cin.ignore();

            temp << "  " << id << "\t\t   " << name << "\t\t  " << address << "\t    "
                 << phone << "\t\t \t " << loan << "\t\t\t" << saving << endl;
        } else {
            temp << line << endl;
        }
    }

    fin.close();
    temp.close();

    if (found) {
        remove("memb.txt");
        rename("temp.txt", "memb.txt");
        cout << "Member updated successfully.\n";
    } else {
        remove("temp.txt");
        cout << "Member with ID " << update_id << " not found.\n";
    }
}
//,................................
 
   


//,................................
   
   
   
   void calculate_interest(){
    float loan, rate, time;
    cout << "Calculate Interest.\n";
    cout << "Enter Loan Amount: ";
    cin >> loan;
    cout << "Enter Annual Interest Rate (%): ";
    cin >> rate;
    cout << "Enter Time (years): ";
    cin >> time;

    float interest = (loan * rate * time) / 100;
    float total = loan + interest;

    cout << "Interest Amount: Rs. " << interest << endl;
    cout << "Total Amount to be paid: Rs. " << total << endl;
}


	
};//..............................................


//this is class member
class Member: public member {
	
	
public:
	int colmen;
    void showMemberOptions() {
    	do{
		
        int option;
        cout << "\n\nMembers:\n";
        cout << "Choose your option\n";
        cout << "1. Board Member / Committee Member\n";
        cout << "2. Employee Member\n";
        cout << "3. General Member\n";
        cout << "   -view Member.\n"; 
        cout << "   -Delete member.\n"; 
        cout << "   -Search Member\n";
        cout << "   -Update Member\n";
          
		  
         
        
       

      //  cout << "4. GOTO main\n";
        cout << "Enter option (1-3): ";
        cin >> option;

        // Using switch case
        switch(option) {
            case 1:
            	cout<< "\n\n------------------------------\n";
                cout<< " Board/Committee Members:\n";
                cout<< "------------------------------\n";
                cout<< " Chairperson        :Ms.Basanti Sunar\n";
                cout<< " Vice Chairperson   :Ms.Purnakal Bhandari\n";
                cout<< " Treasurer          :Ms.Khima Oli\n";
                cout<< "------------------------------\n";
                break;
            case 2:
            	cout<< "\n\n------------------------------\n";
                cout<< "\n Employee Members:\n";
                cout<< " Manager           :Mr.Binaya Taru\n";
                cout<< " Accountant        :Ms.Chandrakala Pun Magar\n";
                cout<< " Loan officer      :Ms.Usha BK\n";
                cout<< "------------------------------\n";
                break;
            case 3:
            {
//            		string correct_password = "123";
//            	string input_password;
//                cout << "Enter password to access General Member section: ";
//                cin >> input_password;
//
//                   if (input_password != correct_password) {
//                   cout << "Access Denied! Incorrect password.\n";
//                   break; // return to main member menu
//                   }

string correct_password = "123";
string input_password = "";
char ch;

cout << "Enter password to access General Member section: ";
ch = _getch();  // First character

while (ch != 13) {  // 13 is ASCII for Enter key
    if (ch == 8) {  // Backspace
        if (!input_password.empty()) {
            input_password.pop_back();
            cout << "\b \b"; // Erase '*'
        }
    } else {
        input_password += ch;
        cout << '*';
   }
    ch = _getch();
}
cout << endl;

if (input_password != correct_password) {
   cout << "Access Denied! Incorrect password.\n";
   break;
}



			}

            	
            	
            	
            	//..................................
            	int option_member;
            	cout<< "\n\n------------------------------\n";
            	cout<< " choose option\n";
            	cout<< " 1.view Member.\n";
            	cout<< " 2.Add Member.\n";
            	cout<< " 3.Delete member.\n";
            //	cout<< " 4.Loan & Saving Summary.\n";
                cout<< " 4.Search Member.\n";
                cout<< " 5.Update Member.\n";
                //cout<< " 6.Calculate Interest.\n";
            	
            	cin>>option_member;
            	// switch inside switch =nested switch case
            	switch (option_member){
            		case 1:           		   
            		show_member();
            		break;
            			
            			case 2:
            		    add_member();           			
            			break;
            			
            			case 3:      		   
            			delete_member();            		
            			break;
//            			case 4:
//            				
//                        loan_saving_summary();
//                         break;

                         case 4:
                        search_member();
                        break;

                        case 5:
                          update_member();
                          break;

                  default:
                cout <<" Invalid option. Please choose between 1 and 6.\n";

				}
            	





                //cout<< "------------------------------\n";
                break;
            default:
                cout <<" Invalid option. Please choose between 1 and 6.\n";
        }
        
        cout<<"chose(1.Member main, 2.Main manu: ";
        cin>>colmen;
        }while(colmen==1);
    }
};


//main class 
class face:public history,public Member{
	
	
	public:
		int option;
	void welcome(){
   cout<<"================================================================\n";		
			cout<<"      Welcome to Saza Phulbari Sahakari Sanstha\n";
			cout<<"           Organization Management System\n";
   cout<<"================================================================\n";
   cout<<" Main:";
  do{

     cout<<"\n";
  	 cout<<" Choose your option\n";
  	 cout<< "------------------------------\n";
   cout<<" 1.Information/History of Sahakari\n";
   cout<<" 2.View Members\n";
   cout<<"      -Board Member / Committee Member.\n";
   cout<<"      -Employee Member.\n";
   cout<<"      -General Member.\n";
   cout<<" 3.Calculation.\n";
  
   cout<<" 4.Exit\n";
    cout<<"---------------------------------\n";
   cout<<" Enter your option:";
   //cout<< "\n------------------------------\n";
   cin>>option;
   //now the switch case
                 switch(option){
                 	case 1:
                 		showhistory();
                 	break;
                 	
                 	case 2:
                 		showMemberOptions();
                 	break;
                 	case 3:
                 		 calculate_interest();
						  break;
                 	case 4:
                 		
                 	break;
                 	
               	default :
              		cout<<"sorry the option is invalid plese chose numer (1-4)\n";                 	                 		                 		                       
				 }
				  int next;
       cout<<"\n\n---------------------------------\n";
        cout << "chose(1. Return to Main Menu, 2. Exit)\n";
     
        cout << "Enter your choice: ";
        cin >> next;

        if (next != 1) {
            
            break; // exit the do-while loop
        }
				// q++;
				
  }while(option !=4);
  cout<<"........THANK YOU..........\n";
		}
};
int main(){
	face x;
	x.welcome();
//	x.showMemberOptions();
	//x.History();
//	x.Member();
	return 0;
}
