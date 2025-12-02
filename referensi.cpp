#include<iostream>
#include<stdlib.h>
#include<conio.h> 
#include<string>
using namespace std;
struct bankmanagement
{
    int accno;
    string name, address;
    char actype; 
    float amount; 
    
    
    bool checkavailabilty();
    bool searchaccount(int);
    void newaccount(); 
    void deposit(); 
    void withdraw();
    void check_account();
    void modifyaccount(); 
    void deleteaccount();
    
    bankmanagement()
    {
        accno=0;
        name="";
        address="";
        actype='\0';
        amount=0.0; 
    }
     
};

int main()
{
    bankmanagement b[5]; 

    int x,an;
    bool check; 
    while(1)
    {   
        system("CLS"); 
        cout<<"             =================              "<<endl;
        cout<<"             |   Bank Menu   |              "<<endl;
        cout<<"=========================================="<<endl;
        cout<<" Tekan 1 untuk membuat akun baru.\n Tekan 2 untuk Deposit.\n Tekan 3 untuk Withdraw.\n Tekan 4 untuk cek akun.\n Tekan 5 untuk edit.\n Tekan 6 untuk hapus.\n Tekan 7 untuk tampilkan semua akun.\n Tekan 8 untuk keluar";
        cout<<"\n=========================================="<<endl;
        cout<<" Masukkan pilihan nomor: ";
        cin>>x; 
        
        switch(x)
        {
            case 1: 
            {
                check=false;
                for(int i=0; i<5; i++)
                {
                    if(b[i].checkavailabilty()) 
                    {
                        check=true;
                        b[i].newaccount(); 
                        cout<<" sedang bekerja.";
                        break;
                    }   
                }
                if(check==false)
                    cout<<"Batas akun terlampaui."; 
                break;  
            }
            case 2: 
            {
                check=false;
                cout<<" Masukkan nomor akun. : ";
                cin>>an; 
                for(int i=0; i<5; i++)
                {
                    if(b[i].searchaccount(an)) 
                    {
                        check=true;
                        b[i].deposit(); 
                        break;
                    }   
                }
                if(check==false)
                    cout<<" Tidak ada akum yang ditemukan .";
                break;
            }
            case 3:
            {
                check=false;
                cout<<" Masukkan nomor akun. : ";
                cin>>an; 
                for(int i=0; i<5; i++)
                {
                    if(b[i].searchaccount(an)) 
                    {
                        check=true;
                        b[i].withdraw(); 
                        break;
                    }   
                }
                if(check==false)
                    cout<<" Tidak ada akun yang ditemukan ."; 
                break;      
            }
            case 4: 
            {
                check=false;
                cout<<" Masukkan nomor akun. : ";
                cin>>an; 
                for(int i=0; i<5; i++)
                {
                    if(b[i].searchaccount(an)) 
                    {
                        check=true;
                        b[i].check_account(); 
                        break;
                    }   
                }
                if(check==false)
                    cout<<" Tidak ada akun yang ditemkuan ."; 
                break;      
                
            }
            case 5: 
            {
                check=false;
                cout<<" Masukkan nomor akun. : ";
                cin>>an; 
                for(int i=0; i<5; i++)
                {
                    if(b[i].searchaccount(an)) 
                    {
                        check=true;
                        b[i].modifyaccount(); 
                        break;
                    }   
                }
                if(check==false)
                    cout<<" Tidak ada akun yang ditemukan ."; 
                break;      
            }
            case 6: 
            {
                check=false;
                cout<<" Masukkan nomor akun. : ";
                cin>>an; 
                for(int i=0; i<5; i++)
                {
                    if(b[i].searchaccount(an)) 
                    {
                        check=true;
                        b[i].deleteaccount(); 
                        break;
                    }   
                }
                
                if(check==false)
                    cout<<" Tidak ada akun yang ditemukan ."; 
                    
                break;      
            }
            case 7: 
            {
                check=false;
                for(int i=0; i<5; i++)
                {
                    if(!b[i].checkavailabilty()) 
                    {
                        
                        check=true;
                        cout<<"\nDetail akun "<<i+1<<":\n ";
                        b[i].check_account(); 
                        cout<<"\n==========================================\n";
                    }   
                }
                if(check==false)
                    cout<<" Tidak ada akun yang ditemukan ."; 
                break;      
            }
            case 8: 
            {
                exit(0); 
            }
        }
        getch(); 
    }
    
    return 0;
}
bool bankmanagement::checkavailabilty()
{
    if(accno==0 && name=="" && address=="" && actype=='\0' && amount==0.0)
        return true;
    else
        return false;
}
bool bankmanagement::searchaccount(int a)
{
    if(accno==a )
        return true;
    else
        return false;
}
void bankmanagement::newaccount()
{
    cout<< " Masukkan nomor akun anda: ";
    cin>> accno; 
    cout<< " Masukkan nama lengkap: ";
    cin>> name;
    cout<< " Masukkan alamat: ";
    cin>> address;
    cout<< " Tipe Akun bagaimana yang akan anda buat? :";
    cin>> actype; 
    cout<< " Masukkan berapa nominal deposit: ";
    cin>> amount; 
    cout << "Akun telah sukses dibuat";	    
}
void bankmanagement::deposit()
{
    float d;
    cout<<"\n Masukkan Nominal = ";
    cin>>d; 
    amount += d; 
    cout<<" Jumlah diperbarui = "<<amount; 
}
void bankmanagement::withdraw()
{
    int wd;
    cout<<"\n Masukkan Nomimal = ";
    cin>>wd; 
    if(wd<=amount) 
    {
        amount -= wd;
        cout<<"\n Amount is withdrawed.";
    }
    else
    {
        cout<<"\n Dana tidak mencukupi.."; 
    }
    cout<<"\n Remaining amount: "<<amount; 
}
void bankmanagement::check_account()
{
    cout<< "\n Nama anda: "<<name; 
    cout<< "\n Alamat anda: "<<address; 
    cout<< "\n Tipe akun: "<<actype;
    cout<< "\n Jumlah= "<<amount; 
}
void bankmanagement::modifyaccount()
{
    cout<<"\n Nomor akun : "<<accno; 
    cout<<"\n Modify Account Holder Name : ";
    cin>>name; 
    cout<< "\n Modify your address: ";
    cin>> address;
    cout<<"\n Modify Type of Account: saving (s) or Current (c): ";
    cin>>actype; 
    cout<<"\n Account is modified.";
}


void bankmanagement::deleteaccount()
{
    accno=0; 
    name=""; 
    address=""; 
    actype='\0'; 
    amount=0.0; 
    cout<<"\n Berhasil dihapus."; 
}
    
