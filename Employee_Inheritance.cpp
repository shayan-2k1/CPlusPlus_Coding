														// Name: Muhammad Shayan Khan
															   // ID: 19I-0743
															  // Assignment # 04
#include <iostream>  
using namespace std;  
class Employee
{
    protected:
        string Name;
        int Emp_number;
        string hire_Date;
    public:
        Employee(string N, int Emp_num, string h_D) 
        {
            Name=N;
            Emp_number=Emp_num;
            hire_Date=h_D;
        }

        void set_Name(string N)
        {
            Name=N;
        }   

        string get_Name()
        {
            return Name;
        } 

        void set_Emp_Number(int num)
        {
            Emp_number=num;
        } 

        int get_Emp_Number()
        {
            return Emp_number;
        } 

        void set_Hire_Date(string h_D)
        {
            hire_Date=h_D;
        }

        string get_Hire_Date()
        {
            return hire_Date;
        }

        void print()
        {
            cout<<"Name of Employee is "<<Name<<"."<<endl;
            cout<<"Number of Employee is "<<Emp_number<<"."<<endl;
            cout<<"Hiring date is "<<hire_Date<<"."<<endl;
        }
};

class ProductionWorker : public Employee 
{  
        int shift;
        double hourly_Pay;
    public:
        ProductionWorker(string N, int Emp_num, string h_D, int s, double h_P):Employee(N, Emp_num, h_D) 
        {
            hourly_Pay=h_P;
            shift=s;
        }

        void set_shift(int s)
        {
            shift=s;
        }

        int get_shift()
        {
            return shift;
        }

        void set_Hourly_Pay(double h_P)
        {
            hourly_Pay=h_P;
        }

        double get_Hourly_Pay()
        {
            return hourly_Pay;
        }

        void print()
        {
            Employee::print();
            if(shift==1)
                cout<<"Shift of Employee is day."<<endl;
            else
            {
                cout<<"Shift of Employee is night."<<endl;
            }
            cout<<"Hourly pay of Employee is "<<hourly_Pay<<"."<<endl;
        }
}; 

int main() 
{
    string N, H_D;
    int num=0, s=0;
    double p=0;
    cout<<"Enter the name of Employee."<<endl;
    cin>>N;
    cout<<"Enter the number of Employee."<<endl;
    cin>>num;
    cout<<"Enter the hiring date in the format DD/MM/YYYY."<<endl;
    cin>>H_D;
    cout<<"Enter the shift number.\n1. Day\n2. Night"<<endl;
    cin>>s;
    cout<<"Also enter the hourly pay."<<endl;
    cin>>p;
    ProductionWorker e1(N, num, H_D, s, p);
    e1.print();
    return 0;
}
