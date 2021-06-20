#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "ConsoleColor.h"
#include <vector>
#include <conio.h>
#include <time.h>
#include <cstring>
#include <string.h>
#include <sstream>
#include <cstdlib>

using namespace std;

int index = 0; //GLOBAL VARIABLE FOR BOOK NUMBER

class Admin{    //PARENT CLASS
	protected:
		int puk;
       	string password;
    	string padmin;
	public:
		string fornewpassword;
		string newpassword;
		Admin()   //CONSTRUCTOR
		{
			puk=3;
			password="proje";
			padmin="Admin did not enter!";
		}
		
		//ENCAPSULATION FOR PUK
		void pukSet(int puk)
		{
			this->puk = puk;
		}
		int pukGet()
		{
			return puk;
		}
		//ENCAPSULATION FOR PASSWORD
		void passwordSet(string password)
		{
			this->password = password;
		}
		string passwordGet()
		{
			return password;
		}
		
		//ENCAPSULATION FOR THE PASSWORD THAT ADMIN WILL ENTER
		void pAdminSet(string padmin)
		{
			this->padmin = padmin;
		}
		string pAdminGet()
		{
			return padmin;
		}
		
    	void Menu();  //WE DEFINED MENU FUNCTION
    	void login()   //THIS IS LOGIN FUNCTION
		{
    	cout<<red<<"~~~~~~~~~~~~~~AYBUKE BOOKSHOP~~~~~~~~~~~~~~\n";
    	cout<<"             Telephone:054372637293\n             Pin Code: "<<password<<endl;
    	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<green;
    	do{
        	cout<<green<<"Enter password: ";
        	cin>>padmin;
        	if(padmin==password)
        	{
        		cout<<"Do you want to change this password?(yes or no)";
        		cin>>fornewpassword;
        		if(fornewpassword == "yes")
        		{
        			cout<<"Please enter New Password:";
        			cin>>newpassword;
        			passwordSet(newpassword);    //THIS CODE CHANGES THE PASSWORD.
        			cout<<"Password has been changed successfully.";
        			Menu();
        			break;
				}
				else if(fornewpassword == "no")
				{
					Menu();
					break;
				}
        		else
        		{
        			cout<<"Invalid word entered. Please try again!"<<endl;
				}
        	}
        	else
        	{
     	     	puk--;
	        	if(puk!=0)
	        	{
	            	cout<<red<<"WRONG PASSWORD ! TRY AGAIN ! \n";
        	    	cout<<"You have "<<puk<<" chance to enter right password!\n";
        	    }
        	}
        }while(puk!=0);
        if(puk==0)
		{
             cout<<red<<"Sorry :( You entered wrong 3 times! GOODBYE...";
        }
    }
    //DESTRUCTOR OF ADMIN CLASS
    virtual ~Admin()
    {
    	cout<<"";
	}

};

//CHILD CLASS OF ADMIN CLASS
class BookStore : public Admin   
{
	private:
    	string book_id;
		string how_many;
    	string book_category;
    	string book_name;
    	string book_author;
	    string book_price;
	public:
		BookStore();
		BookStore(string,string,string,string,string,string); 
		
		void idSet(string);
		string getId();              
		
		void howManySet(string);
		string howManyGet();
		
		void bookCategorySet(string);
		string bookCategoryGet();
		
		void bookNameSet(string);
		string bookNameGet();
		
		void bookAuthorSet(string);
		string bookAuthorGet();
		
		void setPrice(string);
		string getPrice();
		
		void display(BookStore*,int);
		
		void Delete(BookStore*,int,string);
		
		void Update(BookStore*,int,string);
		
		void Search(BookStore*,int);
		
		void ReadFile(BookStore *A);
		
		void WriteFile(BookStore*,int);
		
		//DESTRUCTOR OF BOOKSTORE CLASS
		~BookStore() 
		{
			cout<<"";
		}
        
};

//DEFAULT CONSTRUCTOR
BookStore :: BookStore(){
	book_id="0";
	how_many="0";
	book_category="There is no category";
	book_name="No book name";
	book_author="There is no author like that";
	book_price="0";
}

//CONSTRUCTOR
BookStore :: BookStore(string id,string how_many,string book_category,string book_name,string book_author,string book_price){
	this->book_id = book_id;
	this->how_many = how_many;
	this->book_category = book_category;
	this->book_name = book_name;
	this->book_author = book_author;
	this->book_price = book_price;
}

//ENCAPSULATION FOR BOOK ID
void BookStore :: idSet(string book_id)
{
	this->book_id = book_id;
}
string BookStore :: getId()
{
	return book_id;
}

//ENCAPSULATION FOR NUMBER OF STOCK
void BookStore :: howManySet(string how_many)
{
	this->how_many = how_many;
}
string BookStore :: howManyGet()
{
	return how_many;
}

//ENCAPSULATION FOR BOOK CATEGORY
void BookStore :: bookCategorySet(string book_category)
{
	this->book_category = book_category;
}
string BookStore :: bookCategoryGet()
{
	return book_category;
}

//ENCAPSULATION FOR NAME OF BOOK
void BookStore :: bookNameSet(string book_name)
{
	this->book_name=book_name;
}
string BookStore :: bookNameGet()
{
	return book_name;
}

//ENCAPSULATION FOR AUTHOR OF BOOK
void BookStore :: bookAuthorSet(string book_author)
{
    this->book_author = book_author;
}
string BookStore ::bookAuthorGet()
{
	return book_author;
}

//ENCAPSULATION FOR PRICE
void BookStore :: setPrice(string book_price)
{
	this->book_price = book_price;
}
string BookStore :: getPrice()
{
    return book_price;
}

//THIS FUNCTION SHOWS WHOLE BOOK INFORMATIONS
void BookStore :: display(BookStore *A,int index)
{
	int i;
	if(index==0)
	{
		cout<< red<<"NO BOOK ADDED YET !!!"<<endl;
	}
	else
	{
    	cout<<blue<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    	cout <<left<<setw(20)<<blue<<"ID"<<setw(20)<<"STOCK"<<setw(20)<<"CATEGORY"<<setw(20)<<"BOOK NAME"<<setw(20)<<"AUTHOR"<<setw(20)<<"PRICE"<<endl;
    	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    	for(i=0 ; i<index ; i++)
		{
    		cout<<left<<setw(20)<<A[i].getId()<<setw(20)<<A[i].howManyGet()<<setw(20)<<A[i].bookCategoryGet()<<setw(20)<<A[i].bookNameGet()<<setw(20)<<A[i].bookAuthorGet()<<A[i].getPrice()<<"TL"<<endl;
		}
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
}

//THIS FUNCTION DELETE BOOK THAT WANTED BY ID FROM FILE AND CLASS
void BookStore :: Delete(BookStore *A,int ind,string id)
{
	int i;
	int userindex;
	for(i=0 ; i<ind ; ++i)
	{
		if(A[i].getId() == id)
		{
			userindex=i;
		}
	}
	for(i=userindex ; i<ind-1 ; ++i)
	{
	    A[i]=A[i+1];
	}
	index=index-1;
	A->WriteFile(A,index);//DELETES BOOK FROM FILE IN THIS CODE
}

//THIS FUNCTION UPDATES REQUESTED INFORMATIONS BY ADMIN
void BookStore :: Update (BookStore *A,int index,string id)
{
	string newid;
	string newhowmany;
    string newcategory;
    string newname;
    string newauthor;
	string newprice;
	int i,userindex,choice;
	for(i=0 ; i<index ; ++i)
	{
		if(A[i].getId() == id)
		{
			userindex=i;
		}
	}
	do{  //MENU SYSTEM FOR UPDATE STEP
		cout<<"\n1-Update Book ID\n";
		cout<<"2-Update Stock\n";
		cout<<"3-Update Category of the Book\n";
		cout<<"4-Update Book Name\n";
		cout<<"5-Update Author of the Book\n";
		cout<<"6-Update Price\n";
		cout<<"7-Exit\n";
		cout<<"Please Enter Your Selection:";
    	cin>>choice;
    	cout<<endl;
    	switch(choice)//SWITCH-CASE MENU SYSTEM FOR UPDATE STEP
    	{
    		case 1:
    			cout<<"Enter New ID of the Book:";
    			cin>>newid;
    			A[userindex].book_id = newid;
    			A->WriteFile(A,index); //UPDATES ENTERED ID IN THE FILE
    			cout<<"ID Updated!\n";
    			break;
    			
    		case 2:
    			cout<<"Enter New Stock of the Book:";
    			cin>>newhowmany;
    			A[userindex].how_many = newhowmany;
    			A->WriteFile(A,index);//UPDATES ENTERED STOCK IN THE FILE
    			cout<<"Stock Updated!\n";
    			break;
    			
    		case 3:
    			cout<<"Enter New Category of the Book:";
    			getline(cin>>ws,newcategory);
    			A[userindex].book_category = newcategory;
    			A->WriteFile(A,index);//UPDATES ENTERED CATEGORY IN THE FILE
    			cout<<"Category Updated!\n";
    			break;
    			
    		case 4:
    			cout<<"Enter New Book Name:";
    			getline(cin>>ws,newname);// IF ADMIN ENTERED WRONG BOOK NAME THIS STEP CHANGE WITH CORRECT NAME IN THE ARRAY
    			A[userindex].book_name = newname;
    			A->WriteFile(A,index);//UPDATES ENTERED NAME IN THE FILE
    			cout<<"Name Updated!\n";
    			break;
    			
    		case 5:
    			cout<<"Enter New Author of the Book:";
    			getline(cin>>ws,newauthor);// IF ADMIN ENTERED WRONG AUTHOR OF BOOK THIS STEP CHANGE WITH CORRECT AUTHOR IN THE ARRAY
    			A[userindex].book_author = newauthor;
    			A->WriteFile(A,index);//UPDATES ENTERED AUTHOR IN THE FILE
    			cout<<"Author Updated!\n";
    			break;
    			
    		case 6:
    			cout<<"Enter New Price:";
    			cin>>newprice;
    			A[userindex].book_price = newprice;
    			A->WriteFile(A,index);//UPDATES ENTERED PRICE IN THE FILE
    			cout<<"Price Updated!\n";
    			break;
    			
    		default:
    			if(choice!=7 && choice!=6 && choice!=5 && choice!=4 && choice!=3 && choice!=2 && choice!=1){
			       cout << "Invalid choice!" << endl;
		    	}
		    	break;
		}
    }while(choice != 7);
    
}

//SEARCH STEP FOR ENTERED INFORMATION BY ADMIN
void BookStore :: Search(BookStore *A,int index)
{
	int choice,i;
	string searchid,searchhowmany;
    string searchcategory;
    string searchname;
    string searchauthor;
	string searchprice;
	do{
		cout<<green<<"1-Search Book By ID\n";
		cout<<"2-Search Book By Stock\n";
		cout<<"3-Search Book By Category\n";
		cout<<"4-Search Book By Name\n";
		cout<<"5-Search Book By Author\n";
		cout<<"6-Search Book By Price\n";
		cout<<"7-Exit\n";
		cout<<"Please Enter Your Selection:";
    	cin>>choice;
    	cout<<endl;
    	switch(choice)//SEARCH AND DISPLAY'S SWITCH-CASE
    	{
    		case 1:
    			cout<<"Enter the ID that you want to search:";
    			cin>>searchid;
    			cout<<blue<<"*********************************************************************************************************************\n";
    	        cout <<left<<setw(20)<<red<<"|ID|"<<blue<<setw(20)<<"STOCK"<<setw(20)<<"CATEGORY"<<setw(20)<<"BOOK NAME"<<setw(20)<<"AUTHOR"<<setw(20)<<"PRICE"<<endl;
                cout<<"*********************************************************************************************************************\n";
    			for(i=0 ; i<index ; ++i)
    			{
    				if(A[i].getId() == searchid)
    				{
                    	cout<<left<<setw(20)<<red<<A[i].getId()<<blue<<setw(20)<<A[i].howManyGet()<<setw(20)<<A[i].bookCategoryGet()<<setw(20)<<A[i].bookNameGet()<<setw(20)<<A[i].bookAuthorGet()<<A[i].getPrice()<<"TL"<<endl;
					}
				}
				cout<<"*********************************************************************************************************************\n";
				break;
			case 2:
				cout<<"Enter the STOCK that you want to search:";
				cin>>searchhowmany;
				cout<<blue<<"*********************************************************************************************************************\n";
    	        cout <<left<<setw(20)<<"ID"<<setw(20)<<red<<"|STOCK|"<<setw(20)<<blue<<"CATEGORY"<<setw(20)<<"BOOK NAME"<<setw(20)<<"AUTHOR"<<setw(20)<<"PRICE"<<endl;
                cout<<"*********************************************************************************************************************\n";
				for(i=0 ; i<index ; ++i)
    			{
    				if(A[i].howManyGet() == searchhowmany)
    				{
                    	cout<<left<<setw(20)<<A[i].getId()<<setw(20)<<red<<A[i].howManyGet()<<blue<<setw(20)<<A[i].bookCategoryGet()<<setw(20)<<A[i].bookNameGet()<<setw(20)<<A[i].bookAuthorGet()<<A[i].getPrice()<<"TL"<<endl;	
					}
				}
				cout<<"*********************************************************************************************************************\n";
				break;
			case 3:
				cout<<"Enter the CATEGORY that you want to search:";
				getline(cin>>ws,searchcategory);
				cout<<blue<<"*********************************************************************************************************************\n";
    	        cout <<left<<setw(20)<<"ID"<<setw(20)<<"STOCK"<<setw(20)<<red<<"|CATEGORY|"<<setw(20)<<blue<<"BOOK NAME"<<setw(20)<<"AUTHOR"<<setw(20)<<"PRICE"<<endl;
                cout<<"*********************************************************************************************************************\n";
				for(i=0 ; i<index ; ++i)
    			{
    				if(A[i].bookCategoryGet() == searchcategory)
    				{
                    	cout<<left<<setw(20)<<A[i].getId()<<setw(20)<<A[i].howManyGet()<<setw(20)<<red<<A[i].bookCategoryGet()<<blue<<setw(20)<<A[i].bookNameGet()<<setw(20)<<A[i].bookAuthorGet()<<A[i].getPrice()<<"TL"<<endl;
					}
				}
				cout<<blue<<"*********************************************************************************************************************\n";
				break;
			case 4:
				cout<<"Enter the NAME that you want to search:";
				getline(cin>>ws,searchname);
				cout<<blue<<"*********************************************************************************************************************\n";
    	        cout <<left<<setw(20)<<"ID"<<setw(20)<<"STOCK"<<setw(20)<<"CATEGORY"<<setw(20)<<red<<"|BOOK NAME|"<<setw(20)<<blue<<"AUTHOR"<<setw(20)<<"PRICE"<<endl;
                cout<<"*********************************************************************************************************************\n";
				for(i=0 ; i<index ; ++i)
    			{
    				if(A[i].bookNameGet() == searchname)
    				{
                    	cout<<left<<setw(20)<<A[i].getId()<<setw(20)<<A[i].howManyGet()<<setw(20)<<A[i].bookCategoryGet()<<setw(20)<<red<<A[i].bookNameGet()<<blue<<setw(20)<<A[i].bookAuthorGet()<<A[i].getPrice()<<"TL"<<endl;
					}
				}
				cout<<"*********************************************************************************************************************\n";
				break;
			case 5:
				cout<<"Enter the AUTHOR that you want to search:";
				getline(cin>>ws,searchauthor);
				cout<<blue<<"*********************************************************************************************************************\n";
    	        cout <<left<<setw(20)<<"ID"<<setw(20)<<"STOCK"<<setw(20)<<"CATEGORY"<<setw(20)<<"BOOK NAME"<<setw(20)<<red<<"|AUTHOR|"<<setw(20)<<blue<<"PRICE"<<endl;
                cout<<"*********************************************************************************************************************\n";
				for(i=0 ; i<index ; ++i)
    			{
    				if(A[i].bookAuthorGet()== searchauthor)
    				{
                    	cout<<left<<setw(20)<<A[i].getId()<<setw(20)<<A[i].howManyGet()<<setw(20)<<A[i].bookCategoryGet()<<setw(20)<<A[i].bookNameGet()<<setw(20)<<red<<A[i].bookAuthorGet()<<blue<<A[i].getPrice()<<"TL"<<endl;
					}
				}
				cout<<"*********************************************************************************************************************\n";
				break;
			case 6:
                cout<<"Enter the PRICE that you want to search:";
                cin>>searchprice;
                cout<<blue<<"*********************************************************************************************************************\n";
                cout <<left<<setw(20)<<"ID"<<setw(20)<<"STOCK"<<setw(20)<<"CATEGORY"<<setw(20)<<"BOOK NAME"<<setw(20)<<"AUTHOR"<<setw(20)<<red<<"|PRICE|"<<endl;
                cout<<blue<<"*********************************************************************************************************************\n";
                for(i=0;i<index;i++)
                {
                   if(A[i].getPrice() == searchprice)
                   {
                        cout<<left<<setw(20)<<A[i].getId()<<setw(20)<<A[i].howManyGet()<<setw(20)<<A[i].bookCategoryGet()<<setw(20)<<A[i].bookNameGet()<<setw(20)<<A[i].bookAuthorGet()<<red<<A[i].getPrice()<<"TL"<<blue<<endl; 
                   }
                }
                cout<<blue<<"*********************************************************************************************************************\n";
                break;
    		default:
    			if(choice!=7 && choice!=6 && choice!=5 && choice!=4 && choice!=3 && choice!=2 && choice!=1){
			       cout << "Invalid choice!\n" << endl;
		    	}
		    	break;
	   }
	}while(choice!=7);
}

//CHECKS WHETHER THERE IS A BOOK IN THE ENTERED ID FOR ADD BOOK
bool addcheck(BookStore *A,int index,string id)
{
	int i;
	for(i=0 ; i<index ; i++)
	{
		if(A[i].getId() == id)
		{
			return 0;
		}
	}
	return 1;
}

//CHECKS WHETHER THERE IS A BOOK IN THE ENTERED ID FOR DELETE BOOK
bool deletecheck(BookStore *A,int index,string id)
{
	int i;
	for(i=0 ; i<index ; i++)
	{
		if(A[i].getId() == id)
		{
			return 1;
		}
	}
	return 0;
}

//THIS FUNCTION WRITES INFORMATIONS OF BOOKS TO TXT FILE
void BookStore :: WriteFile(BookStore *A,int ind)
{
	int i;
	ofstream bookfile;
	bookfile.open("books.txt");//OPENS TXT FILE
	if(!bookfile)//CHECKS WHETHER THERE IS SUCH A FILE
	{
		cerr<<"File is not found...\n";
		exit(1);
	}
	else
	{
		for(i=0 ; i<ind ; ++i)
		{
	    	bookfile<<A[i].getId()<<"-"<<A[i].howManyGet()<<"-"<<A[i].bookCategoryGet()<<"-"<<A[i].bookNameGet()<<"-"<<A[i].bookAuthorGet()<<"-"<<A[i].getPrice()<<endl;
    	}
	}
	bookfile.close();//CLOSES TXT FILE
}

//THIS FUNCTION,READS THE INFORMATINOS IN THE FILE AND SAVES IT INTO THE CLASS.
void BookStore :: ReadFile(BookStore *A)
{
	string line,flag;
	vector<string>line1;
	char const sign ='-';
	ifstream bookfile("books.txt");
	if(!bookfile)
	{
		cerr<<"File is not found...\n";
		exit(1);
	}
	else{
    	int i;
     	while(bookfile)
    	{
    		getline(bookfile, line);
    		stringstream l(line);
    		while(getline(l, flag, sign))
    		{
    			line1.push_back(flag);
    		}
    		for(i=0 ; i<line1.size() ; i++)
    		{
        	    if(i==0)
    	    	{
    	    		A[index].idSet(line1[i]);
        		}
    	    	else if(i==1)
        		{
        			A[index].howManySet(line1[i]);
        		}
        		else if(i==2)
        		{
            		A[index].bookCategorySet(line1[i]);
        		}
        		else if(i==3)
        		{
        			A[index].bookNameSet(line1[i]);
        		}
         		else if(i==4)
        		{
        			A[index].bookAuthorSet(line1[i]);
        		}
            	else if(i==5)
        		{
        			A[index].setPrice(line1[i]);
        		}
	    	}
	    	index++;
		
    		line1.clear();
    		line.clear();
    	}
    }
    index--;
}

//CHILD CLASS OF ADMIN CLASS
class Offers : public Admin
{
	protected:
		string offer;
	public:
		int choice;
		string want;
		Offers()//DEFAULT CONSTRUCTOR
		{
			offer="No offer";
		}
		//ENCAPSULATION FOR OFFER
		void offerSet(string o)
		{
			offer=o;
		}
		string offerGet(void)
		{
			return offer;
		}
		void make()
		{
			cout<<blue<<"Do you want to add offers?(yes or no):";
			if(offer!="No offer")
			{
				cout<<endl<<"Old Offers : "<<offer<<endl;
			}
			cin>>want;
			if(want=="yes")
			{
				do{
                    cout<<red<<"1.BRING THE OLD BOOK,TAKE THE NEW BOOK!"<<endl;
                    cout<<"2.BUY 1, GET 1 FOR FREE"<<endl;
                    cout<<"3.FREE SHIPPING"<<endl;
                    cout<<"4.BUY 2 GET 3"<<endl;
                    cout<<"5.SECOND BOOK 1 TL"<<endl;
                    cout<<"6.RETURNS WITHIN 15 DAYS WARRANTY"<<endl;
                    cout<<"7.EXIT"<<endl;
                    cout<<"Enter your choice: ";
                    cin>>choice;
                    cout<<yellow;
                    cout<<endl;
                    switch(choice)//UPDATES WANTED OFFER
                    {
                    	case 1:
                    		offer="BRING THE OLD BOOK,TAKE THE NEW BOOK!";
                    		cout<<"Current Offer: "<<offer<<endl;
                    		break;
                    	case 2:
                    		offer="BUY 1, GET 1 FOR FREE";
                    		cout<<"Current Offer: "<<offer<<endl;
                    		break;
                    	case 3:
                    		offer="FREE SHIPPING";
                    		cout<<"Current Offer: "<<offer<<endl;
                    		break;
                    	case 4:
                    		offer="BUY 2 GET 3";
                    		cout<<"Current Offer: "<<offer<<endl;
                    		break;
                    	case 5:
                    		offer="SECOND BOOK 1 TL";
                    		cout<<"Current Offer: "<<offer<<endl;
                    		break;
                    	case 6:
                    		offer="RETURNS WITHIN 15 DAYS WARRANTY";
                    		cout<<"Current Offer: "<<offer<<endl;
                    		break;
                    	default:
                    		if(choice!=7 && choice!=6 && choice!=5 && choice!=4 && choice!=3 && choice!=2 && choice!=1){
			                    cout << "Invalid choice!\n" << endl;
		                	}
		                	break;
					}

                }while(choice!=7);
			}
			else if(want!="no" && want!="yes")
			{
				cout<<"You entered invalid word!"<<endl;
			}
		}
};


//MENU FUNCTION OF ADMIN CLASS
void Admin :: Menu()
{
	BookStore A[1000];
	Offers O;
	string id,howmany;
    string category;
    string name;
    string author;
	string price;
	int choice;
	bool foradd,fordelete;
	A->ReadFile(A);
	do{
		cout<<yellow<<"\n\n1.ADD NEW BOOKS"<<endl;
		cout<<"2.DISPLAY ALL BOOKS"<<endl;
		cout<<"3.SEARCH BOOKS"<<endl;
		cout<<"4.DELETE BOOKS"<<endl;
		cout<<"5.UPDATE BOOKS"<<endl;
		cout<<"6.OFFERS FOR CUSTOMERS"<<endl;
		cout<<"7.HELP"<<endl;
		cout<<"8.EXIT"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 1:
				cout<<"Enter book id:";
				cin>>id;
				cout<<"How many do you want to add:";
				cin>>howmany;
				cout<<"Enter category of book:";
				getline(cin>>ws,category);
				cout<<"Enter book name:";
				getline(cin>>ws,name);
				cout<<"Enter author of book:";
				getline(cin>>ws,author);
				cout<<"Enter book price:";
				cin>>price;
				foradd = addcheck(A,index,id);//IF THERE IS NO SAME BOOK IN THE ENTERED ID FORADD WILL BE 1
				if(foradd == 1)
				{
					A[index].idSet(id);
					A[index].howManySet(howmany);
					A[index].bookCategorySet(category);
					A[index].bookNameSet(name);
					A[index].bookAuthorSet(author);
					A[index].setPrice(price);
					A->WriteFile(A,index+1);//WRITES THE ENTERED BOOK INTO THE FILE 
					index++;
					cout<<green<<"Entered book has been added!\n";	
				}
				else
				{
					cout<<red<<"The book that you entered already exist!!"<<endl;
				}
				break;
			case 2:
				A->display(A,index);
				break;
			case 3:
				A->Search(A,index);
				break;
			case 4:
				cout << "Enter the ID of the book that you want to delete:";
				cin>>id;
				fordelete = deletecheck(A,index,id);//IF THERE IS NO SAME BOOK IN THE ENTERED ID FORDELETE WILL BE 1
				if(fordelete == 1)
				{
					A->Delete(A,index,id);
					cout<<green<<"The requested book has been deleted!\n";
				}
				else
				{
					cout<<red<<"Sorry,The given book ID is not found.\n"<<endl;
				}
		    	break;
			case 5:
				cout<<"Please enter the ID of the book that you want to update:";
				cin>>id;
				A->Update(A,index,id);
				break;
			case 6:
				O.make();//SEND TO OFFERS CLASS
				break;
			case 7:
				cout<<green<<"---------------------------WORKING PRINCIPLE OF THE PROGRAM---------------------------"<<endl;
                cout<<red<<"This program does everything necessary to customize your bookstore."<<endl;
				cout<<"To explain, There is a general menu system in program which allows to customize your books."<<endl;
                cout<<"You can add new book from first step.Also saved new books to txt file."<<endl;
				cout<<"Second step shows whole registered books.Contains book that you added and previous registered books."<<endl;
				cout<<"Third step is search step. If you want to reach specific part of the book you should use this step."<<endl;
				cout<<"Also allows search by Book ID,Stock,Category,Name or Author. You can search by that you want to find any book."<<endl;
				cout<<"Fourth step is delete step. If you want to delete any book or you added wrong book you can remove from database."<<endl;
				cout<<"Fifth step is update step. Don't you want to delete whole book's information or you want to add new stock? "<<endl;
				cout<<"This step is here for that.You can access any properity of book like ID,stock etc.Then change any value!"<<endl;
				cout<<"The sixth step is offers step. Add some sales for your customers!"<<endl;
				cout<<"Final step is as you can predict exit to quit from program :)"<<endl;
                cout<<green<<"If you have a any question or technical support please contact c1811031@student.cankaya.edu.tr "<<endl;
				cout<<"-----------------------------------------------------------------------------------------------------------\n";
				break;
			default:
				if(choice!=8 && choice!=7 && choice!=6 && choice!=5 && choice!=4 && choice!=3 && choice!=2 && choice!=1)
				{
			       cout << "Invalid choice!" << endl;
		    	}
		    	break;
		}
	}while(choice!=8);
	
	cout<<"Goodbyee!";
}

int main()//MAIN FUNCTION
{
	Admin *admin=new Admin();
	admin->login();
	delete admin;
	return 0;
}
