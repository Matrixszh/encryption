#include <iostream>
#include <fstream>
#include<string>
#include<math.h>
using namespace std;

class login 
{
    private:    
        string username;
        string password;
    public:
        int attempts;
        login()
        {
            attempts = 0;
        }
        ~login() {}
        void loginfunc()
        {
            string x,y;
            cout << "Enter username : ";
            cin >> x;

            username = getfile("zain.txt");
            if (x == username)
            {
                cout << "\nEnter password : ";
                cin >> y;
                password = getfile("pass.txt");
                if ( y == password) 
                {
                    cout << "login succesful";
                    return;
                }
                else
                {
                    cout << "wrong username or password please try again." << endl;
                    loginfunc();

                }
            }
            else
            {
                cout << "wrong username or password please try again." << endl;
                loginfunc();

            }
            
        }
        void signup()
        {
            string a, b;
            cout << "Enter new username : ";
            cin >> a;
            savefilesu("a", "zain.txt");
            username=getfile("zain.txt");
            a == username;
            cout << "\nEnter new password : ";
            cin >> b;
            savefilesu("b", "pass.txt");
            password = getfile("pass.txt");
            b == password; 
            cout << "sign up is succesful\n";
            return;
         }
        string getfile(const char* p)
        {
            string line;
            fstream zfile;
            long long int echar;
            zfile.open(p, ios::in);
            while (1)
            {
                zfile >> echar;
                if (echar == 0)
                {
                    zfile.close();
                    return line;
                }

                line += (char)decrypt(echar);
            }
        }
        void savefile(string s, const char* file)
        {
            fstream nfile;
            nfile.open(file,ios::out);
            for (int i = 0; i < s.length(); i++)
            {
                nfile << encrypt(s[i]);
                nfile << "\n";
                
            }
            nfile << "0\n";
            nfile.close();
        }
       void savefilesu(string p, const char* file)
        {
            fstream nfile;
            nfile.open(file, ios::out);
            for (int i = 0; i < p.length(); i++)
            {
                nfile << encrypt(p[i]);
                nfile << "\n";

            }
            nfile << 0;
            nfile.close();
        }

        long long int encrypt(int letter)
        {
            return powf(letter,3);
        }
        int decrypt(long long int letter)
        {
            return powf(letter,1/3.f);
        }

      
};
int main()
{
    login A;
    A.loginfunc();
    
}
