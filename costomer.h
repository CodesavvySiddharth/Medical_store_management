#include <conio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int id;
    char med_name[50];
    int quantity;
    float price;
    struct node *next;
};
struct node *head=NULL,*last=NULL,*p,obj,*q=NULL;
struct node *headc=NULL,*head_s=NULL,*newnode,*tailc=NULL;
int found=0,i,n;
//customer section
//reading the Medical database
void readdatabase()
	{
	int i,filempty=0;
	FILE *infile=fopen("Medicine_database.txt","r");
	p=head;
	fseek(infile,0,SEEK_END);
	if(p==NULL)
	{
	p=(struct node*)malloc(sizeof(struct node));
	head=p;
	}
	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	printf("File empty");
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(infile);
	while(fscanf(infile,"\n%d\t\t %s\t\t %d\t\t %f",&(p->id),p->med_name,&(p->quantity),&(p->price)))
{
	if(feof(infile))
	{
	break;
	}
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
	p->next=NULL;
}}}
void addMed()
{
    readdatabase();
    p=head;
    found=0;
    int id,quantity;
    printf("\n-------------------------\n");
    printf("Medicine No|| Quantity ||");
    printf("\n------------------------\n   ");
    scanf("\t%d %d",&id,&quantity);
    for(i=1;p!=NULL;i++)
    {
        if(p->id==id)
            {
                found=1;
                break;
            }
            p=p->next;

    }
    if(found==0)
        printf(">>>>Medicine not found->>>>\n");
    if(found==1)
    {
     if(quantity<p->quantity){
      newnode = (struct node*)malloc(sizeof(struct node));
      newnode->id = id;
      newnode->price = (quantity)*(p->price);
      newnode-> quantity = quantity;
      strcpy(newnode->med_name,p->med_name);
      newnode->next = NULL;
      struct node *temp=headc;
      if(temp==NULL)
            headc = newnode;
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=newnode;
        }
       printf(">>>>Medicine successfully added to your purchase list->>>>\n");
    }
     else{
        printf(">>>>Oops Not enough quantity present\n");
        printf("\n-------------------------\n");
        printf("Medicine No|| Quantity ||");
        printf("\n------------------------\n   ");
        printf("\n%d\t %s\t\t %d\t\t %f",(p->id),p->med_name,(p->quantity),p->price);
     }
    }
}
//display the list of medicines
void displayList(struct node *head)
{
    printf("\t---------------------------------------------------------------------------------\n");
    printf("\t|    Medicine No.\tMedicine Name\t\tQuantity\t Total Price\t|");
    struct node *temp1 = head;
    if(temp1==NULL)
    {
        printf("\n\t\t\t\t\tList is empty!!\n\n");
    }
    else
    {
        printf("\n");
        while(temp1!=NULL)
        {
            if(temp1->quantity==0)
                printf("\t|\t%d\t\t%s\t\t%0.2f\t|\n",temp1->id,temp1->med_name,temp1->price);
            else
            {
                printf("\t|\t%d\t\t%s\t\t\t%d\t\t%0.2f\t|\n",temp1->id,temp1->med_name,temp1->quantity,temp1->price);
            }

            temp1 = temp1->next;
        }
    }
    printf("\t|                                                                               |");
    printf("\n\t---------------------------------------------------------------------------------\n");

}

struct node* delete(int id,struct node *head, struct node* tail)
{
    if(head==NULL)
    {
        printf("\n\t\t\t\t\t\t\tList is empty\n");
    }
    else
    {
        struct node* temp,*q;
        if(id==head->id)
        {
            temp = head;
            if(head->next!=NULL)
                head=head->next;
            else
                head=NULL;
            free(temp);
        }
        else
        {
            temp = head;
            while(id!=temp->id)
            {
                q=temp;
                temp = temp->next;
            }
            q->next=temp->next;
            free(temp);
        }
    }
    return head;
}
int delCustMed()
{
    printf("\n\t\t\t\t\tEnter medicine id to be deleted: ");
    int num;
    scanf("%d",&num);

    struct node* temp=headc;
    while(temp!=NULL)
    {
        if (temp->id == num)
        {
            headc = delete(num, headc, tailc);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}
//total bill generated
void displaybill()
{
    displayList(headc);
    struct node *temp = headc;
    float total_price = 0;
    while (temp!=NULL)
    {
        total_price +=temp->price;
        temp = temp->next;
    }

    printf("\t\t\t\t\t\t\tTotal price: %0.02f\n",total_price);

}

void costomer()
{
     system("CLS");
    printf("\n                                 |-------------------------------------------------------------------------|\n");
    printf("                                 |                      WELCOME TO CUSTOMER SECTION                        |\n");
    printf("                                 |-------------------------------------------------------------------------|\n\n");
   
    int choice2;
    do{
    printf("<<<<-Press 1 for adding medicine to your purchase list->>>>\n");
    printf("<<<<-Press 2 for Deleting medicine from purchase list->>>>\n");
    printf("<<<<-Press 3 for Searching medicines by medicine id or name->>>>\n");
    printf("<<<<-Press 4 Generating the bill->>>>\n");
    printf("<<<<-Press 5 to view your purchase list\n");
    printf("<<<<-Press 0 for Exit->>>>\n\n");
    printf("Enter your choice ");
    scanf("%d",&choice2);
    switch(choice2){
        case 1:
            addMed();
            printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n") ;
            getch();
            break;
        case 2:
            if(delCustMed())
                printf("<<<<-Medicine successfully deleted->>>>>\n");
            else
                printf("<<<<-Oops medicine with this id is not in your purchase list->>>>\n");

            printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n") ;
            getch();
            break;
        case 3:
            SearchMed();
            printf("\n\n\n0. MAIN MENU\t\t\t");
            printf("1. SUB MENU\n\n");
            printf("Choice:\t");
            scanf("%d",&choice2);
            break;
        case 4:
            printf("\n\t\t\t\t\t\t\t<<<<-Final Bill->>>>\n");
            displaybill();
            printf("\n\n\n0. MAIN MENU\t\t\t");
            printf("1. SUB MENU\n\n");
            printf("Choice:\t");
            scanf("%d",&choice2);
            break;
        case 5:
            displayList(headc);
            printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n") ;
            getch();
            break;
        default:
            break;
    }
    }while(choice2!=0);
}
