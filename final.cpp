#include<iostream>
#include<bits/stdc++.h>
#include <omp.h>
using namespace std;

int main()
{
map<pair<int,string>, int> m;
bool b = true;
short choice;

while(b)
{

cout<<endl;
cout<<"1.Parllel Search"<<endl;
cout<<"2.Series Search"<<endl;
cout<<"3.Exit"<<endl;

cin >> choice;

if (choice == 1)
{
string str="";

string list[1000][6];
std::fill(list[0], list[0] + 1000 * 6, "0");
int count = 0;

int temp;
int numthreds;


cout<<"Enter no of threads"<<endl;
cin>>numthreds;
double start_time = omp_get_wtime();


#pragma omp parallel for private(temp) num_threads(numthreds)
for(int j=1;j<=5;j++)
{
string temp3;
temp3 = "file" + to_string(j) + ".txt";
ifstream fi(temp3); //"file" + temp2 + ".txt"

while (fi >> str)
{

int flag=0;
int i;
int temp23;
int flag2 = 1;
#pragma omp parallel for num_threads(numthreds)
for (i = 0; i <count; ++i)
{
if(list[i][0]==str&&flag2==1)
{ 
flag=1;

flag2 = 0;
//break;

}


}



if(flag==0)
{

//#pragma omp critical
{
list[count][0] = str;
//m[str]++;
list[count][j] = '1';
count++;

}


}



}
}



string str1;
double time = omp_get_wtime() - start_time;

cout<<"Enter the term to be searched:"<<endl;
cin>>str1;
int flag1=0;
int result;
int freq=0;
int tmp=0;


//#pragma omp parallel for
for (int i = 0; i < count; ++i)
{


if(list[i][0] == str1)
{
flag1=1;
result = i;
freq++;

}
else
{

}
tmp++;
}



if(flag1==0)
cout<<"No Results Found!!!"<<endl;

int totalcount=0;

for(int j=1;j<=5;j++)
{
cout<<"the occurence of the word"<<str1 <<" in file"<<j<<" is :"<<" "<<m[{j,str1}]<<endl;
totalcount+=m[{j,str1}];
}
cout<<"Total count :"<<totalcount<<endl;
cout<<"Size :"<<m.size()<<endl;
double percent=(totalcount*100/m.size());
cout<<"The Relationship between the files and the word is"<<" "<<percent<<endl;


cout<<"Time for search"<<" ";
printf("%lf",time);

}


else if (choice == 2)
{
string str;


string list[10000][6];
std::fill(list[0], list[0] + 10000 * 6, "0");
int count = 0;
int temp;

double start_time = omp_get_wtime();

for(int j=1;j<=5;j++)
{
string temp3;
temp3 = "file" + to_string(j) + ".txt";
ifstream fi(temp3); //"file" + temp2 + ".txt"

while (fi >> str)
{



int flag=0;
int i;
int temp23;
int flag2 = 1;
for (i = 0; i < count; ++i)
{

if(list[i][0]==str&&flag2==1)
{ 
m[{j,list[i][0]}]++;
flag=1;
temp = atoi(list[i][j].c_str());
temp++;


stringstream convert;

convert << temp;

list[i][j] = convert.str();
flag2 = 0;

}


}


if(flag==0)
{ //count++;
list[count][0] = str;
m[{j,str}]++;
list[count][j] = '1';
count++;




}


}


}


string str1;


cout<<"Enter the term to be searched:"<<endl;
cin>>str1;
int flag1=0;
int result;

for (int i = 0; i < count; ++i)
{

if(list[i][0] == str1)
{

flag1=1;
result = i;

}
}

if(flag1==0)
cout<<"No Results Found!!!"<<endl;

else
{



double time = omp_get_wtime() - start_time;

for(int j=1;j<=5;j++)
{
cout<<"the occurence of the word"<<str1 <<" in file"<<j<<"is :"<<" "<<m[{j,str1}]<<endl;
}

cout<<"The time for search is"<<" ";
printf("%lf",time);
cout<<endl;

}
else if (choice == 3)
{
b=false;
}
}

return 0;

}
