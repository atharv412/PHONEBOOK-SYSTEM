#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<windows.h>
using namespace std;

class contact
{
    private:
        string c_firstname,c_lastname,c_email,c_address;
        int c_phone_no;
    public:
        void add_contact();
        void order_contact();
        void search_contact(string name);
        void delete_contact(string cname);
        void edit_contact(string cname);
};
void contact::add_contact()
{
    system("cls");
    
    ofstream fout("phonebook.txt",ios::app);
    if (fout.fail())
    {
        cout<<"Error opening phonebook";
    }

    contact temp_con;
    cout<<"Enter the First name of the person\n>>";
    cin.ignore();
    getline(cin,temp_con.c_firstname);
    cout<<"Enter the Last Name of the person\n>>";
    cin.ignore();
    getline(cin,temp_con.c_lastname);
    cout<<"Enter the Phone.NO of the person\n>>";  
    cin>>temp_con.c_phone_no;
    cout<<"Enter the Email of the person\n>>";
    cin.ignore();
    getline(cin,temp_con.c_email);    
    cout<<"Enter the Address of the person\n>>";
    cin.ignore();
    getline(cin,temp_con.c_address);

    cout<<"The contact has been added successfully"<<endl;

    fout<<temp_con.c_firstname<<" "<<temp_con.c_lastname<<" "<<temp_con.c_phone_no<<" "<<temp_con.c_email<<" "<<temp_con.c_address<<"\n";
    
    fout.close();
    Sleep(4000);
}
void contact::order_contact()
{
    vector<contact> temp_con_vec;
    contact temp_con;
    string sort_choice;
    string temp;
    ifstream fin("phonebook.txt",ios::in);
    if (fin.fail()) 
    {
        cout<<"Error opening Phonebook";
        system("cls");
        Sleep(6000);
    }
    while (fin>>temp_con.c_firstname>>temp_con.c_lastname>>temp_con.c_phone_no>>temp_con.c_email>>temp_con.c_address)
    {
       temp_con_vec.push_back(temp_con);
    }
    fin.close();
    system("cls");

    cout<<"enter the way the contacts to be ordered\n(a-z) or (z-a)"<<endl;
    cin>>sort_choice;

    if (sort_choice=="a-z"||sort_choice=="A-Z")
    {
        for (int i = 0; i < temp_con_vec.size()-i; i++)
        {
            for (int j = 0; j < temp_con_vec.size()-1-i; j++)
            {
                if (temp_con_vec[j].c_firstname>temp_con_vec[j+1].c_firstname)
                {
                    swap(temp_con_vec[j].c_firstname,temp_con_vec[j+1].c_firstname);
                    swap(temp_con_vec[j].c_lastname,temp_con_vec[j+1].c_lastname);
                    swap(temp_con_vec[j].c_phone_no,temp_con_vec[j+1].c_phone_no);
                    swap(temp_con_vec[j].c_email,temp_con_vec[j+1].c_email);
                    swap(temp_con_vec[j].c_address,temp_con_vec[j+1].c_address);
                }
            }
        }
    }
    else if(sort_choice=="z-a"||sort_choice=="Z-A")
    {
        for (int i = 0; i < temp_con_vec.size()-i; i++)
        {
            for (int j = 0; j < temp_con_vec.size()-i-1; j++)
            {
                if (temp_con_vec[j].c_firstname<temp_con_vec[j+1].c_firstname)
                {
                    swap(temp_con_vec[j].c_firstname,temp_con_vec[j+1].c_firstname);
                    swap(temp_con_vec[j].c_lastname,temp_con_vec[j+1].c_lastname);
                    swap(temp_con_vec[j].c_phone_no,temp_con_vec[j+1].c_phone_no);
                    swap(temp_con_vec[j].c_email,temp_con_vec[j+1].c_email);
                    swap(temp_con_vec[j].c_address,temp_con_vec[j+1].c_address);
                }                
            }            
        }
    }
    
    ofstream fout("phonebook.txt",ios::out);
    for (int i = 0; i < temp_con_vec.size(); i++)
    {
       fout<<temp_con_vec[i].c_firstname<<" "<<temp_con_vec[i].c_lastname<<" "<<temp_con_vec[i].c_phone_no<<" "<<temp_con_vec[i].c_email<<" "<<temp_con_vec[i].c_address<<"\n";
    }
    
    cout<<"contacts successfully ordered";
    Sleep(3000);
}
void contact::search_contact(string name)
{
    vector <contact> temp_con_vec;
    contact temp_con;
    ifstream fin("phonebook.txt",ios::in);
    if (fin.fail())
    {
        cout << "Error opening Phonebook";
        system("cls");
        Sleep(6000);
    }
    else
    {
        while (fin >> temp_con.c_firstname >> temp_con.c_lastname >> temp_con.c_phone_no >> temp_con.c_email >> temp_con.c_address)
        {
            if (temp_con.c_firstname == name)
            {
                cout<<"Contact exists\n"<<endl;
                cout << "the contact exists: " << endl;
                cout << "first name:" << temp_con.c_firstname << endl;
                cout << "last name name:" << temp_con.c_lastname << endl;
                cout << "phone NO.:" << temp_con.c_phone_no << endl;
                cout << "E-mail:" << temp_con.c_email << endl;
                cout << "Address:" << temp_con.c_address << endl;
            }
        }
        fin.close();
    }
}
void contact::edit_contact(string name)
{
    vector <contact> temp_con;
    contact c1;
    string temp;
    int temp_no ,edit_choice;
    ifstream fin("phonebook.txt",ios::in);
    if (fin.fail())
    {
        cout << "Error opening Phonebook";
        Sleep(6000);
        system("cls");
    }
    else
    {
        while (fin >> c1.c_firstname >> c1.c_lastname >> c1.c_phone_no >> c1.c_email >> c1.c_address)
        {
            temp_con.push_back(c1);
        }

        fin.close();
        // std::system("cls");
        ofstream fout("phonebook.txt", ios::out);
        for (int i = 0; i < temp_con.size(); i++)
        {
            if (temp_con[i].c_firstname == name)
            {
                cout << "what do you want to change in the contact";
                cout << "\n>1first name\t>2last name\t>3phone no\t>4e-mail\t>5address\n>>";
                cin >> edit_choice;
                switch (edit_choice)
                {
                case 1:
                    cout << "enter the new first name:  ";
                    cin >> temp;
                    temp_con[i].c_firstname = temp;
                    cout << "contact successfully updated" << endl;

                    break;

                case 2:
                    cout << "enter the new last name:  ";
                    cin >> temp;
                    temp_con[i].c_lastname = temp;
                    cout << "contact successfully updated" << endl;

                    break;

                case 3:
                    cout << "enter the new Phone no:  ";
                    cin >> temp_no;
                    temp_con[i].c_phone_no = temp_no;
                    cout << "contact successfully updated" << endl;

                    break;

                case 4:
                    cout << "enter the new email:  ";
                    cin >> temp;
                    temp_con[i].c_email = temp;
                    cout << "contact successfully updated" << endl;

                    break;

                case 5:
                    cout << "enter the new address:  ";
                    cin >> temp;
                    temp_con[i].c_address = temp;
                    cout << "contact successfully updated" << endl;

                    break;
                }
            }
            else if (temp_con[i].c_firstname != name && i == temp_con.size() - 1)
            {
                cout << "contact does not exists";
            }
            fout << temp_con[i].c_firstname << " " << temp_con[i].c_lastname << " " << temp_con[i].c_phone_no << " " << temp_con[i].c_email << " " << temp_con[i].c_address << "\n";
        }
        fout.close();
    }
    temp_con.clear();
    Sleep(4000);
    std::system("cls");
}
void contact::delete_contact(string name)
{
    vector <contact> temp_con;
    contact c1;
    ifstream fin("phonebook.txt",ios::in);
    if (fin.fail())
    {
        cout << "Error opening Phonebook";
        Sleep(6000);
        system("cls");
    }
    else
    {
        while (fin>>c1.c_firstname >> c1.c_lastname >> c1.c_phone_no >> c1.c_email >> c1.c_address)
        {
           temp_con.push_back(c1);
        }
        fin.close();
        std::system("cls");
        ofstream fout("phonebook.txt", ios::out);

        for (int  i = 0; i < temp_con.size(); i++)
        {
            if(temp_con[i].c_firstname==name)
            {
                // char choice;
                // cout<<"Are you sure to delete the selected contact";
                // cin>>choice;
                // (choice=='yes');
                temp_con[i].c_firstname.erase();
                temp_con[i].c_lastname.erase();
                // temp_con[i].c_phone_no.erase()
                // ^dont know how to delete class object with an int data member from a class vector
                temp_con[i].c_email.erase();
                temp_con[i].c_address.erase();
                cout<<"contact successfully deleted";
            }
        fout << temp_con[i].c_firstname << " " << temp_con[i].c_lastname << " " << temp_con[i].c_phone_no << " " << temp_con[i].c_email << " " << temp_con[i].c_address << "\n";
        }
        fout.close();
    }
        temp_con.clear();
        Sleep(6000);
        std::system("cls");
}
int main()
{
    int choice;
    contact c1;
    string temp_name;
    do
    {
        cout<<"\n>1.Add contact \n>2.Search contact \n>3.Edit contact \n>4.Delete Contact \n>5.Exit \n>>";
        cin>>choice;
        switch (choice)
        {
        case 1:
            c1.add_contact();
            system("cls");
            c1.order_contact();
            break;
        
        case 2:
            cout<<"Enter the first name of the contact to be searched"<<endl<<">>";
            cin>>temp_name;
            c1.search_contact(temp_name);
            break;

        case 3:
            cout<<"Enter the name of the contact to be edited";
            cin>>temp_name;
            c1.edit_contact(temp_name);
            system("cls");
            break;

        case 4:
            cout<<"Enter the name of the contact to be deleted";
            cin>>temp_name;
            c1.delete_contact(temp_name);
            system("cls");
        }
    } while (choice<5);
    
    return 0;
}