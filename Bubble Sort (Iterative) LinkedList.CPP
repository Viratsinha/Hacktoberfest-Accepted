Bubble Sort (Iterative) LinkedList
Send Feedback
Sort a given linked list using Bubble Sort (iteratively). While sorting, you need to swap the entire nodes, not just the data.
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5






			PRACTICE

node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
}



					SOLUTION


node* swap_nodes(node *head,int i,int j)
{
    //write your code here
  node*temp1=NULL;node*x=head;
  node*temp2=NULL;node*y=head;
  for(int k=0;k<j;k++){
   temp2=y;
    y=y->next;
  }
 
  for(int k=0;k<i;k++){
    temp1=x;
    x=x->next;
  }
  
  //if x is not head of the list
  if (temp1 != NULL) 
       temp1->next = y; 
   else // Else make y as new head 
       head = y;   
  
   // If y is not head of linked list 
   if (temp2 != NULL) 
       temp2->next = x; 
   else  // Else make x as new head 
       head = x; 
  
   // Swap next pointers 
    node *temp = y->next; 
   y->next = x->next; 
   x->next  = temp; 
 
  
    
  
  return head;
}

int length(node *head) {
  return head==NULL ? 0 : 1 + length(head->next);
  //terniary operator
}

node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
  int k=1;
  int l=length(head);
  node*x=head;
 	for(int i=0;i<l;i++){
      x=head;k=1;
      for(int j=0;j<l-i-1;j++){
        if(x->data > x->next->data){
        head=swap_nodes(head,j,k);
          k++;
        }
        else{x=x->next;
            k++;}
      }
    }
  return head;
}

//bubble sort iterative
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
#include "solution.h"
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}

