
//display medicines
void displayMed()
{
    readdatabase();
	p=head;
	if(p==NULL)
	{
	printf("list is empty");
	}
	else
{
    printf("\n-------------------------------------------------\n");
    printf("Medicine No|| Name || Quantity || Price ||");
    printf("\n--------------------------------------------------\n   ");
    for(i=0;p!=NULL;i++)
	{
     printf("\n%d\t %s\t\t %d\t\t %f",(p->id),p->med_name,(p->quantity),p->price);
     p=p->next;
	}}}