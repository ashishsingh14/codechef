#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#define max 5000
using namespace std;

void findsubstr(int i, string str1, string str2)
{
	 //string str="abab";
    int a = str1.size();
    int j =0;
//int <vector> result;
int total=0;
    while(i<(a-j+1))
    {
        string temp = str1.substr (j,i);
       // cout<<temp<<endl;
        

                int  positions=0; // holds all the positions that sub occurs within str

		size_t pos = str2.find(temp, 0);


		while(pos != string::npos)
		{
		    positions++;
		    pos = str2.find(temp,pos+1);
		}
		total = total + positions;
		
		   //cout<<positions<<endl;

		   j++;
    }
cout<<total<<" ";
   
}

int main()
{


	int t,l;
	cin>>t;
	string str1;
	string str2;
	while(t--)
	{
		cin>>str1;
		cin>>str2;
		cin>>l;
		int a = str1.size();
		int b = str2.size();

		for(int i = 1;i<=l;i++)
		{
				findsubstr(i,str1, str2);
				
		}
		cout<<endl;

	}
	/* code */
	return 0;
}	
