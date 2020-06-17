#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>


using namespace std;

void randcheck(int id, int arg)
{
char str[80];
while(arg != rand() % 10000 + 1)
{
//do nothing
}
string i = to_string(id);
const char * c = i.c_str();
strcpy(str, "\n Thread ");
strcat(str, c);
strcat(str, " completed.\n ");
cout<<str;

}

int main(int argc, char* argv[])
{
int cmd_arg = stoi(argv[1]);
int i = 0;
vector <thread* > threads;
for(i=0;i<10;i++)
{
thread *t  = new thread(randcheck, i, cmd_arg);
threads.push_back(t);
}
for(i = 0; i<10; i++)
{
  threads[i]->join();
}
cout<<"All threads have completed execution, exiting .... \n";
}
