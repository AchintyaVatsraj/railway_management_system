#include<stdio.h>


struct train
{
    int tno,plat;                                                     //Train no,Platform
    char arr[10],dep[10],from[30],to[30];                             //Arrival,Departure,From,To
};
void insert();															 //Inserts Details into File
void display();															//Displays Contents of File
void search();															//Searches for Train No in File
void Delete();															//Deletes Details of specified Train
void main()
{
    int ch;
    while(ch!=5)
    {
    	
        system("cls");
        printf("1)Read\n2)Display\n3)Search\n4)Delete\n5)Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        	
            case 1:insert();break;
            case 2:display();break;
            case 3:search();break;
            case 4:Delete();break;
            case 5:break;
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
void search()
{
	
	int item,f=0;
	struct train t;
	FILE *fp;
	system("cls");
	fp=fopen("train.bin","r");
	printf("Enter the Train No: ");
	scanf("%d",&item);
	while(fread(&t,sizeof(struct train),1,fp))
	{
		if(item==t.tno)
		{
			f=1;
			printf("Train Found!\n");
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
		}
	}
	if(f==0)
	{
		printf("Train not Found!");
	}
	fclose(fp);
	getch();
}
void Delete()
{
	int item,f=0;
	char ch;
	struct train t;
	FILE *f1,*f2;
	system("cls");
	f1=fopen("train.bin","r");
	f2=fopen("temp.bin","a");
	printf("Enter the Train No: ");
	scanf("%d",&item);
	while(fread(&t,sizeof(struct train),1,f1))
	{
		if(item==t.tno)
		{
			f=1;
			printf("Train Found!\n");								//Prints details on screen before deleting
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
		    
			printf("Confirm Delete ?: ");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='n'||ch=='N')
			fwrite(&t,sizeof(struct train),1,f2);
			else
			printf("Delete Successful");
		}
		else
		fwrite(&t,sizeof(struct train),1,f2);		
	}
	if(f==0)
	{
		printf("Train not Found!");
	}
	fclose(f1);
	fclose(f2);
	remove("train.bin");
	rename("temp.bin","train.bin");
	getch();
}
