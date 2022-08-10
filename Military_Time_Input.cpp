														// Name: Muhammad Shayan Khan
															   // ID: 19I-0743
															  // Assignment # 04
#include <iostream>
#include<string>
using namespace std;

class Time
{
	protected:
		int hour;
		int min;
		int sec;
	public:
		Time()
		{
			hour=0;
			min=0;
			sec=0;
		}
		
		Time(int h, int m, int s)
		{
			if(h>23 || h<0)
			{
				cout<<"Value for hour is invalid. Please re-enter."<<endl;
				cin>>h;
			}
			if(m>59 || m<0)
			{
				cout<<"Value for minute is invalid. Please re-enter."<<endl;
				cin>>s;
			}			
			if(s>59 || s<0)
			{
				cout<<"Value for second is invalid. Please re-enter."<<endl;
				cin>>s;
			}
			hour=h;
			min=m;
			sec=s;
		}
		
		int getHour() const
		{
			return hour;
		}
		
		int getMin() const
		{
			return min;
		}
		int getSec() const
		{
			return sec;
		}	
};

class milTime : public Time
{
		int milHours;
		int milSeconds;
	public:
		milTime(int h_m, int s=0):Time()
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
            Time::hour=h_m/100;
			Time::min=h_m%100; 
			Time::sec=s;
		}
		
		void setTime(int h_m, int s)
		{
			if(h_m>2359 || h_m<0, h_m%100>59)
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
			Time::hour=h_m/100;
			Time::min=h_m%100; 
			Time::sec=s;
		}
		
		string getHour()
		{
			return "The time in military format is "+to_string(milHours)+" hours.";
		}
		
		string getStandHr()
		{
		
			return "The time in standard format is "+to_string(hour)+":"+to_string(min)+":"+to_string(sec);
		}
};

int main()
{
	int h=0;
	cout<<"Enter the time in military hours."<<endl;
	cin>>h;
	milTime t1(h);
	cout<<t1.getHour()<<endl;
	cout<<t1.getStandHr()<<endl;
	return 0;	
}