#include<iostream>
using namespace std;

class Array
{
private:
    int* array;
    int size;
public:
    Array()
    {
        array=NULL;
        size=0;
    }

    Array(int s)
    {
        size=s;
        array=new int[size];
        for(int i=0;i<size;i++)
        {
            array[i]=0;
        }
    }

    Array(int* arr, int s)
    {
        size=s;
        array=new int[size];
        for(int i=0;i<size;i++)
        {
            array[i]=arr[i];
        }
    }

    Array(const Array &a)
    {
        size=a.size;
        array=new int[size];
        for(int i=0;i<size;i++)
        {
            array[i]=a.array[i];
        }
    }

    int getAt(int i)
    {
        return array[i];
    }

    void setAt(int i, int val)
    {
        array[i]=val;
    }

    Array subArr(int pos, int s)
    {
        Array a(*this);
        if(pos==size || s>size-pos)
        {
            cout<<"Sub-array is not possible."<<endl;
            return a;
        }
        else
        {   a.size=s;
            delete [] a.array;
            a.array=new int[s];
            for(int i=0;i<s;i++)
            {
                a.array[i]=0;
            }
            for(int j=0;j<s;j++,pos++)
            {
                a.array[j]=array[pos];
                if(pos==size-1)
                {
                return a;
                }
            }
        }
        return a;
    }

    Array subArr(int pos)
    {
        Array a(*this);
        if(pos==size)
        {
            cout<<"Sub-array is not possible."<<endl;
            return a;
        }
        else
        {   a.size=size-pos;
            a.array=new int[a.size];
            for(int i=0;i<a.size;i++)
            {
                a.array[i]=0;
            }

            for(int j=0;j<a.size;j++,pos++)
            {
                a.array[j]=array[pos];
                if(pos==size-1)
                {
                    return a;
                }
            }
        }
        return a;
    }

    int* subArrPointer(int pos, int s)
    {
        Array a(*this);
        int* x=a.array;
        if(pos==size || s>size-pos)
        {
            cout<<"Sub-array is not possible."<<endl;
            return x;
        }
        else
        {   a.size=s;
            a.array=new int[s];
            for(int i=0;i<s;i++)
            {
                a.array[i]=0;
            }
            for(int j=0;j<s;j++,pos++)
            {
                a.array[j]=array[pos];
                if(pos==size-1)
                {
                return x;
                }
            }
        }
        return x;        
    }

    int* subArrPointer(int pos)
    {
        Array a(*this);
        int* x=a.array;
        if(pos==size)
        {
            cout<<"Sub-array is not possible."<<endl;
            return x;
        }
        else
        {   a.size=size-pos;
            a.array=new int[a.size];
            for(int i=0;i<a.size;i++)
            {
                a.array[i]=0;
            }

            for(int j=0;j<a.size;j++,pos++)
            {
                a.array[j]=array[pos];
                if(pos==size-1)
                {
                    return x;
                }
            }
        }
        return x;
    }

    void push_back(int a)
    {
        Array b(*this);
        size=size+1;
        delete [] array;
        array=new int[size];
        for(int i=0;i<b.size;i++)
        {
            array[i]=b.array[i];
        }
        array[size-1]=a;
    }

    int pop_back()
    {
        Array b(*this);
        size=size-1;
        delete [] array;
        array=new int[size-1];
        for(int i=0;i<size;i++)
        {
            array[i]=b.array[i];
        }
        return array[size-1];
    }

    int insert(int idx, int val)
    {
        if(idx==size || idx>size || idx<0)
        {
            cout<<"Your insertion is not possible."<<endl;
            return -1;
        }
        else
        {
            int a[size];
            for(int i=0;i<size;i++)
            {
                a[i]=array[i];
            }
            delete [] array;
            size=size+1;
            array=new int[size];
            for(int i=0;i<idx;i++)
            {
                array[i]=a[i];
            }
            array[idx]=val;
            array[idx+1]=a[idx];
            for(int j=idx+2,k=1;j<size;j++,k++)
            {
                array[j]=a[idx+k];
            }
            cout<<"Your insertion was successful."<<endl;
            return 1;
        }
    }

    int erase(int idx, int val)
    {
        if(idx==size || idx>size || idx<0)
        {
            cout<<"Your erase is not possible."<<endl;
            return -1;
        }
        else
        {
            int a[size];
            for(int i=0;i<size;i++)
            {
                a[i]=array[i];
            }
            delete [] array;
            size=size-1;
            array=new int[size];
            for(int i=0;i<idx;i++)
            {
                array[i]=a[i];
            }
            for(int j=idx;j<size;j++)
            {
                array[j]=a[j+1];
                cout<<"Your erasing was successful."<<endl;
            }
            array[size-1]=a[size];
        }
        return 1;
    }

    void sizeArr()
    {
        cout<<"The size of your array is "<<sizeof(array)<<" bytes."<<endl;
    }

    int length()
    {
        return size;
    }

    void clear()
    {
        for(int i=0;i<size;i++)
        {
            array[i]=0;
        }
    }

    int value(int idx)
    {
        return array[idx];
    }

    void assign(int idx, int val)
    {
        array[idx]=val;
    }

    void copy(const Array &Arr)
    {
        size=Arr.size;
        delete [] array;
        array=new int[size];
        for(int i=0;i<size;i++)
        {
            array[i]=Arr.array[i];
        } 
    }

    void copy(int* arr, int s)
    {
        size=s;
        delete [] array;
        array=new int[size];
        for(int i=0;i<size;i++)
        {
            array[i]=arr[i];
        }
    }

    void display()
    {
        cout<<"The contents of the array is:"<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    bool isEmpty()
    {
        if(array==NULL)
        return true;
        else
        {
            return false;
        } 
    }

    Array find(int x)
    {
        Array a;
        for(int i=0;i<size;i++)
        {
            if(array[i]==x)
            {
                a.array=new int;
                *a.array=i;
                a.size++;
            }
            else if(i>0 && array[i]==x)
            {
                a.push_back(i);
                a.size++;
            }
        }
        return a;
    }

    bool equal(const Array &a)
    {
        bool check=false;
        if(size==a.size)
        {
            for(int i=0;i<size;i++)
            {
                if(array[i]!=a.array[i])
                {
                    check=false;
                    return check;
                }
                else
                {
                    check=true;
                }
            }
        }
        return check;
    }

    int sort()
    {
        int swap=0;
        int temp=0;
        do
        {
            swap=0;
            for(int i=0;i<size-1;i++)
            {
                if(array[i]>array[i])
                {
                    temp=array[i];
                    array[i]=array[i+1];
                    array[i+1]=temp;
                    swap=1;
                }
            }
        }
        while(swap);
    }

    void reverse()
    {
        Array a(*this);
        for(int i=0,j=size-1;i<size;i++,j--)
        {
            array[i]=a.array[j];
        }
    }

    ~Array()
    {
        delete [] array;
        array=NULL;
    }
};

int main()
{
    int s=0,i=0;
    cout<<"Enter the size of array."<<endl;
    cin>>s;
    Array a(s);
    a.display();
    int x=a.pop_back();
    cout<<"After calling 'pop_back' function:"<<endl;
    a.display();
    cout<<"Now enter the index at which you want to set value and also enter the value."<<endl;
    cin>>i>>x;
    a.setAt(i, x);
    cout<<"After using 'setAt' function:"<<endl;
    a.display();
    cout<<"Now enter the value you want to add at the end of array."<<endl;
    cin>>x;
    a.push_back(x);
    cout<<"After calling 'push_back' function:"<<endl;
    a.display();
    cout<<"Again enter the index at which you want to set value and also index."<<endl;
    cin>>i>>x;
    a.insert(i, x);
    cout<<"After using 'insert' function:"<<endl;
    a.display();
    cout<<"Now enter the index you want to remove and also its value."<<endl;
    cin>>i>>x;
    a.erase(i, x);
    cout<<"After calling 'erase' function:"<<endl;
    a.display();
    cout<<"Now enter the position from which you want to get another array and also size."<<endl;
    cin>>i>>x;
    Array b=a.subArr(i, x);
    b.display();
    return 0;
}

