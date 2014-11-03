#include <iostream>
#include <algorithm>
using namespace std;

typedef struct number
{
	int data;
	number * next;
} number;

number* form(int data)
{
	number* temp=(number*)malloc(sizeof(number));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

int sum(number* num1,number* num2,int carry,int total)
{

}

int main(int argc, char const *argv[])
{
	number * num1=form(4);
	num1->next=form(8);
	num1->next->next=form(9);
	num1->next->next->next=form(6);
	
	number * num2=form(7);
	num2->next=form(5);

    
    return 0;
}