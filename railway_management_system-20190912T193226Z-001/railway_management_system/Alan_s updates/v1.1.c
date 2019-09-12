#include<stdio.h>


struct train
{
    int tno,plat;                                                     //Train no,Platform
    char arr[10],dep[10],from[30],to[30];                             //Arrival,Departure,From,To
};
void insert();														  //Inserts Details into File
void display();														  //Displays Contents of File
void main()
{
    int ch;
    while(ch!=3)
    {
        system("cls");
        printf("1)Read\n2)Display\n3)Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();break;
            case 2:display();break;
            case 3:break;
            default:printf("Invalid Choice");
        }
    }
}
void insert()
{
    struct train t;
    FILE *fp;
    fp=fopen("train.bin","a");
    system("cls");
    printf("Enter the details:\n");
    printf("Train No: ");
    scanf("%d",&t.tno);
    printf("Arrival Time: ");
    fflush(stdin);
    gets(t.arr);
    printf("Departure Time: ");
    gets(t.dep);
    printf("From: ");
    gets(t.from);
    printf("To: ");
    gets(t.to);
    printf("Platform No: ");
    scanf("%d",&t.plat);
    fwrite(&t,sizeof(struct train),1,fp);
    fclose(fp);
    
}
void display()
{
    FILE *fp;
    struct train t;
    fp=fopen("train.bin","r");
    system("cls");
    printf("TRAIN DETAILS:\n");
    while(fread(&t,sizeof(struct train),1,fp))
    {
    	printf("\n");
	    printf("Train No: ");
	    printf("%d\n",t.tno);
	    printf("Arrival Time: ");
	    printf("%s\n",t.arr);
	    printf("Departure Time: ");
	    printf("%s\n",t.dep);
	    printf("From: ");
	    printf("%s\n",t.from);
	    printf("To: ");
	    printf("%s\n",t.to);
	    printf("Platform No: ");
	    printf("%d\n",t.plat);	    
	    getch();
	}
	fclose(fp);
}
