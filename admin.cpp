#include <iostream>
#include <conio.h>
#include"book.h"
#include"person.h"
#include"book.cpp"
#include"person.cpp"
#include"file.cpp"
#include <chrono>
#include <thread>

void Register(Staff& s, string &username, string &password) {
    int i = 0;
    for(i=0;i< sf.size();i++){ 
        if(sf[i].Getaccount() == username){
            cout << "Tai khoan da ton tai " << endl;
            return;
        }
    }
    s.setAccount(username);
    s.setPassword(password);
    cout << "Dang ki thanh cong" << endl;
    s.set_info();
    sf.push_back(s);
    updateFile3(sf);
}

bool Login(const string username, string password){
    for(auto& staff : sf ){ 
        if(staff.Getaccount() == username && staff.Getpassword() == password){
            return true;
            break;
        }
    }
    cout << "Tai khoan hoac mat khau sai" << endl;
    return false;
}

void changePassword(Staff* &s, string username, string currentPassword, string newPassword) {
    if (s->Getpassword() == currentPassword) { 
        for(auto& staff : hs ){ 
            if(staff.Getaccount() == username ){
                staff.setPassword(newPassword);
            }
        }
        cout << "Doi mat khau thanh cong!" << endl;
        updateFile3(sf);
    } else {
        cout << "Sai mat khau hien tai! Khong the doi mat khau." << endl;
    }
}

void displayMenu(char choice) {
    system("cls"); 
    std::cout << "Library System:" << std::endl;
    if (choice == '1') {
        std::cout << "\033[1;31m"; 
    }
    std::cout << "1. Dang ky tai khoan" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '2') {
        std::cout << "\033[1;32m";
    }
    std::cout << "2. Dang nhap " << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '3') {
        std::cout << "\033[1;34m"; 
    }
    std::cout << "3. Thoat" << std::endl;
    std::cout << "\033[0m";

}

void displayMenuCustom(char choice)
{
	system("cls"); 
    std::cout << "Ban dang nhap voi tu cach admin" << std::endl;
    if (choice == '1') {
        std::cout << "\033[1;31m"; 
    }
    std::cout << "1. Chinh sua thong tin" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '2') {
        std::cout << "\033[1;32m";
    }
    std::cout << "2. Quan ly sach" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '3') {
        std::cout << "\033[1;33m"; 
    }
    std::cout << "3. Thong ke" << std::endl;
    std::cout << "\033[0m";
    
    if (choice == '4') {
        std::cout << "\033[1;34m"; 
    }
    std::cout << "4. Tim kiem sinh vien" << std::endl;
    std::cout << "\033[0m";
    
    if (choice == '5') {
        std::cout << "\033[1;35m"; 
    }
    std::cout << "5. Dang xuat" << std::endl;
    std::cout << "\033[0m";

}

void displayMenuCustom_2(char choice)
{
	system("cls"); 
    std::cout << "Library System:" << std::endl;
    if (choice == '1') {
        std::cout << "\033[1;31m"; 
    }
    std::cout << "1. Xem thong tin nguoi dung" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '2') {
        std::cout << "\033[1;32m";
    }
    std::cout << "2. Xoa tai khoan" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '3') {
        std::cout << "\033[1;34m"; 
    }
    std::cout << "3. Quay lai trang chu" << std::endl;
    std::cout << "\033[0m";

}

int main() 
{
	
	Staff myStaff;
    Staff *myStaffPtr = new Staff;
    string username, password, currentPassword, newPassword;
    docfile1(hs, sach);
    docfile2(sf);
    bool isLoggedIn = false; 
    bool isSearch = false; 

    char choice = '1';
    char keyPressed;

    while (true) 
	{
    	
        displayMenu(choice);
       
        keyPressed = _getch(); 
        switch (keyPressed) 
		{
            case 72: 
                choice = (choice == '1') ? '3' : static_cast<char>(choice - 1);
                break;
            case 80:
                choice = (choice == '3') ? '1' : static_cast<char>(choice + 1);
                break;
            case 13:
                switch(choice)
                {
                	case '1':
                		{
                			std::string username, password;
	                        std::cout << "Nhap ten dang nhap: ";
	                        std::cin >> username;
	                        std::cout << "Nhap mat khau: ";
	                        std::cin >> password;
	                        Register(myStaff, username, password); 
	                        break;
						}
                    case '2':
                        system("cls");
                    	cout << "Nhap ten dang nhap: ";
		                cin >> username;
		                cout << "Nhap mat khau: ";
		                cin >> password;	
						
						if(Login(username,password))
						{
		                    isLoggedIn = true;
		
		                    for (auto& staff : sf) {
		                        if (staff.Getaccount() == username && staff.Getpassword() == password) 
								{
			                        myStaffPtr = &staff;
			                        break;
		                        }
	                    }	
						
						while (isLoggedIn)
						{
							displayMenuCustom(choice);
						    
					        keyPressed = _getch();
					        switch (keyPressed) 
							{
					            case 72: 
					                choice = (choice == '1') ? '5' : static_cast<char>(choice - 1);
					                break;
					            case 80:
					                choice = (choice == '5') ? '1' : static_cast<char>(choice + 1);
					                break;
					            case 13: 
					            	switch(choice)
					            	{
					            		case '1':
                                            system("cls");
					            			myStaffPtr -> print_info(sach);
				                            myStaffPtr -> editInfor();
				                            break;
				                        case '2':
                                            system("cls");
				                            myStaffPtr->bookManager(sach);
				                            updateFile2(sach);
				                            break;
				                        case '3':
                                            system("cls");
				                            myStaffPtr->Statistical(sach, hs);
				                            break;
				                        case '4':
                                            system("cls");
				                            if(myStaff.searchUser(hs))
                                            std::this_thread::sleep_for(std::chrono::seconds(10));
											{
				                                isSearch = true;
				                                while(isSearch)
												{
				                                    displayMenuCustom_2(choice);
				                                    keyPressed = _getch();
											        switch (keyPressed) 
													{
											            case 72: 
											                choice = (choice == '1') ? '3' : static_cast<char>(choice - 1);
											                break;
											            case 80:
											                choice = (choice == '3') ? '1' : static_cast<char>(choice + 1);
											                break;
											            case 13: 
						                                    switch (choice)
						                                    {
							                                    case '1':
							                                        myStaffPtr -> print_infoUser(hs, sach); 
							                                    	break;
							                                    case '2':
							                                        myStaffPtr -> deleteUser(hs, sach); 
							                                        updateFile1(hs);
							                                    	break;
							                                    case '3': 
							                                        isSearch = false;
							                                    	break;
							                                    
															}
														}
													}
				                                }
				                            }
				                            case '5':
					                        	isLoggedIn = false;
					                        	break;
				                        	default :
				                        		break;
				                        }
				                        
									}
								}
								break; 
					            case 3:
					                return 0;
					            default:
					                cout << "Lua chon khong hop le!" << endl;
					                break;
							}
						}
				}
		delete myStaffPtr;
		return 0;
	}