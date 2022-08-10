														// Name: Muhammad Shayan Khan
															   // ID: 19I-0743
															  // Assignment # 04
#include<iostream>
#include<string>
using namespace std;

class milTime
{
    protected:
		int milHours;
		int milSeconds;
	public:
        milTime()
        {
            milHours=0;
            milSeconds=0;
        }

		milTime(int h_m, int s=0)
		{
			if(h_m>2359 || h_m<0 || h_m%100>59)
			{
				cout<<"Value for military hours is invalid. Please re-enter."<<endl;
				cin>>h_m;
			}
			if(s>59 || s<0)
			{
				cout<<"Value for second is invalid. Please re-enter."<<endl;
				cin>>s;
			}
			milHours=h_m;
			milSeconds=s;
		}
		
		void setTime(int h_m, int s)
		{
			if(h_m>2359 || h_m<0)
			{
				cout<<"Value for military hours is invalid. Please re-enter."<<endl;
				cin>>h_m;
			}
			if(s>59 || s<0)
			{
				cout<<"Value for second is invalid. Please re-enter."<<endl;
				cin>>s;
			}
			milHours=h_m;
			milSeconds=s;
		}
		
		string getHour()
		{
			return "The time in military format is "+to_string(milHours)+" hours.";
		}

        friend milTime operator -(milTime t1, milTime t2);
        friend ostream& operator <<(ostream& output, milTime t);
};

milTime operator -(milTime t1, milTime t2)
{
    milTime t3;
    t3.milHours=t1.milHours-t2.milHours;
    t3.milSeconds=t1.milSeconds-t2.milSeconds;
	if(t3.milHours<0)
	{
		t3.milHours+=24;
	}
    return t3;
}


ostream& operator <<(ostream& output, milTime t)
{
    output<<t.milHours<<" hours."<<endl;
    return output;
}

class TimeClock : public milTime
{
    public:
        milTime Time_Elapsed(milTime t1, milTime t2)
        {
            milTime t3;
            t3=t2-t1;
            return t3;
        }     
};

int main()
{
    int x=0;
    cout<<"Enter any time in military format."<<endl;
    cin>>x;
    milTime t1(x);
    cout<<"Enter another time in military format."<<endl;
    cin>>x;
    milTime t2(x);
    TimeClock t3;
    milTime diff;
    diff=t3.Time_Elapsed(t1,t2);
    cout<<diff;
    return 0;
}