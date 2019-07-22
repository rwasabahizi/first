#include<stdio.h>

struct student
{
int id;
char name[25];
float marks;
int semester;

struct date
{
    int entryDay;
    int entryMonth;
    int entryYear;
}d;


}st[100];

int i,n,j;
FILE *p;

void record()
{
    p=fopen("records.txt","w");
    printf("enter the total number of student you want to record\n");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("enter student id\n");
        scanf("%d",&st[i].id);
        printf("enter student name\n");
        scanf("%s",st[i].name);

        printf("enter student marks\n");
        scanf("%f",&st[i].marks);

        printf("enter student semester\n");
        scanf("%d",&st[i].semester);
         printf("enter student entry day\n");
        scanf("%d",&st[i].d.entryDay);
        if(st[i].d.entryDay>31 || st[i].d.entryDay<=0)
        {
            printf("Invalid day!!!\n");
            printf("re-enter the day\n");
            scanf("%d",&st[i].d.entryDay);
        }
        printf("enter student entry month\n");
        scanf("%d",&st[i].d.entryMonth);
        if(st[i].d.entryMonth>12 || st[i].d.entryMonth<=0)
        {
            printf("Invalid month!!!\n");
            printf("re-enter the month\n");
            scanf("%d",&st[i].d.entryMonth);
        }

         printf("enter student entry year\n");
        scanf("%d",&st[i].d.entryYear);


         fprintf(p,"%d\t\t\t%s\t\t\t%.2f\t\t\t%d\t\t\t%d/%d/%d\n",st[i].id,st[i].name,st[i].marks,st[i].semester,st[i].d.entryDay,st[i].d.entryMonth,st[i].d.entryYear);

        }


     printf("\nStudent Information recorded Successfully");
     fclose(p);

}
void display()
{
    p=fopen("records.txt","r");
    printf("the  student info\n\n");
    printf("_________________\n\n");

    printf("ID\t\t\tNAMES\t\t\tMARKS\t\t\tSEMESTER\t\t\tEntry Date\n");
    printf("___\t\t\t_____\t\t\t_____\t\t\t________\t\t\t__________\n\n ");

    while(!feof(p))
    {
        fscanf(p,"%d\t\t\t%s\t\t\t%.2f\t\t\t%d\t\t\t%d/%d/%d\n",&st[n].id,st[n].name,&st[n].marks,&st[n].semester,&st[n].d.entryDay,&st[n].d.entryMonth,&st[n].d.entryYear);
      printf("%d\t\t\t%s\t\t\t%.2f\t\t\t%d\t\t\t%d/%d/%d\n",st[n].id,st[n].name,st[n].marks,st[n].semester,st[n].d.entryDay,st[n].d.entryMonth,st[n].d.entryYear);
    }



}
void sortById()
{
    struct student temp;
for(i=0;i<n;i++)
{

    for(j=0;j<n;j++)
    {
        if(st[i].id < st[j].id)
        {
            temp=st[i];
            st[i]=st[j];
            st[j]=temp;


        }

    }
}

display();
}
void sortByName()
{
   struct student temp;

   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           if(0<strcmp(st[i].name,st[j].name))
           {
               temp=st[i];
            st[i]=st[j];
            st[j]=temp;
           }
       }
   }




display();
}
void sortByMarks()
{
    struct student temp;
    for(i=0;i<n;i++)
{

    for(j=0;j<n;j++)
    {
        if(st[i].marks < st[j].marks)
        {
            temp=st[i];
            st[i]=st[j];
            st[j]=temp;


        }

    }
}



display();
}
void sortBySemester()
{
    struct student temp;
    for(i=0;i<n;i++)
{

    for(j=0;j<n;j++)
    {
        if(st[i].semester < st[j].semester)
        {
            temp=st[i];
            st[i]=st[j];
            st[j]=temp;


        }

    }
}





display();
}
void sortByDate()
{
struct student temp;

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        if(st[i].d.entryYear>st[j].d.entryYear)
        {
            temp=st[i];
            st[i]=st[j];
            st[j]=temp;
        }
        if(st[i].d.entryYear==st[j].d.entryYear && st[i].d.entryMonth>st[j].d.entryMonth)
        {
          temp=st[i];
            st[i]=st[j];
            st[j]=temp;
        }
        if(st[i].d.entryMonth==st[j].d.entryMonth && st[i].d.entryDay>st[j].d.entryDay)
        {
            temp=st[i];
            st[i]=st[j];
            st[j]=temp;
        }

    }
}



display();
}

void sort()
{
     int c;
    do
    {
    printf("\t\tmake your choice\n\t\t_________________\n\n\t\t1.SortById\n\t\t2.SortByName\n\t\t3.SortByMarks\n\t\t4.SortBySemester\n\t\t5.SortByDate\n\n");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            sortById();
            break;
        case 2:
            sortByName();
            break;
        case 3:
            sortByMarks();
            break;
        case 4:
            sortBySemester();
            break;
        case 5:
            sortByDate();
            break;

        default:
            printf("wrong choice !!!! please try again\n\n");

        }

    }while(c!=0);




}
void searchById()
{
 int newId;

 printf("enter the id you want to search\n");
 scanf("%d",&newId);

 for(i=1;i<=n;i++)
 {
     if(st[i].id==newId)
    {
    printf("the searched   student \n\n");
    printf("_________________\n\n");

    printf("ID\t\t\tNAMES\t\t\tMARKS\t\t\tSEMESTER\n");
    printf("___\t\t\t_____\t\t\t_____\t\t\t________\n\n ");
    printf("%d\t\t\t%s\t\t\t%.2f\t\t\t%d\n",st[i].id,st[i].name,st[i].marks,st[i].semester);

     }

 }


}
void searchByName()
{
    char n[25];
    printf("enter the name you want to search\n");
    scanf("%s",n);

  for(i=0;i<=n;i++)
  {
      if(st[i].name==n)
      {
        printf("the searched   student \n\n");
    printf("_________________\n\n");

    printf("ID\t\t\tNAMES\t\t\tMARKS\t\t\tSEMESTER\n");
    printf("___\t\t\t_____\t\t\t_____\t\t\t________\n\n ");
    printf("%d\t\t\t%s\t\t\t%.2f\t\t\t%d\n",st[i].id,st[i].name,st[i].marks,st[i].semester);

      }

  }
}
void searchByMarks()
{
    float m;
    printf("enter the marks you want to search\n");
    scanf("%f",&m);

    for(i=0;i<=n;i++)
    {
        if(st[i].marks==m)
        {
            printf("the searched   student \n\n");
    printf("_________________\n\n");

    printf("ID\t\t\tNAMES\t\t\tMARKS\t\t\tSEMESTER\n");
    printf("___\t\t\t_____\t\t\t_____\t\t\t________\n\n ");
    printf("%d\t\t\t%s\t\t\t%.2f\t\t\t%d\n",st[i].id,st[i].name,st[i].marks,st[i].semester);


        }


    }

}
void searchBySemester()
{
    int sem;
    printf("enter the semester you want to search\n");
    scanf("%d",&sem);

    for(i=0;i<=n;i++)
    {
        if(st[i].semester==sem)
        {
            printf("the searched   student \n\n");
    printf("_________________\n\n");

    printf("ID\t\t\tNAMES\t\t\tMARKS\t\t\tSEMESTER\n");
    printf("___\t\t\t_____\t\t\t_____\t\t\t________\n\n ");
    printf("%d\t\t\t%s\t\t\t%.2f\t\t\t%d\n",st[i].id,st[i].name,st[i].marks,st[i].semester);


        }


    }


}
void search()
{

    int c;
    do
    {
    printf("\t\tmake your choice\n\t\t_________________\n\n\t\t1.SearchById\n\t\t2.SearchByName\n\t\t3.SearchByMarks\n\t\t4.SearchBySemester\n\n");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            searchById();
            break;
        case 2:
            searchByName();
            break;
        case 3:
            searchByMarks();
            break;
        case 4:
            searchBySemester();
            break;

        default:
            printf("wrong choice !!!! please try again\n\n");

        }

    }while(c!=0);



}

void main()

{
    int v;
    do
    {
        printf("\t\tmake your choice\n\t\t_________________\n\n\t\t1.record\n\t\t2.display\n\t\t3.sort\n\t\t4.search\n\n");
        scanf("%d",&v);
        switch(v)
        {
        case 1:
            record();
            break;
        case 2:
            display();
            break;
        case 3:
            sort();
            break;
        case 4:
            search();
            break;

        default:
            printf("wrong choice !!!! please try again\n\n");



        }


    }while(v!=0);

}




