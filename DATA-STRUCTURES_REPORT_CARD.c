#include <stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#define MAX 20

char arr[5];

typedef struct list{
    char uname[10],password[10];
    int roll_no;
    char gender;
    struct list *next;
}list;



typedef struct 
{  
   list * start; 
}head;


typedef struct node
{
 char name[8],roll_no[8];
 float p,c,m,mec,bee;
 struct node *next;
}node;

typedef struct head1{
      node *start;
}head1;


int checkr(head1 *t ,char num[])
{   if(t->start==NULL)
        return -1;
     node *q;
	    q=t->start;
	    while(q!=NULL)
	    {
	    	if(strcmp(q->roll_no,num)==0)
	    	return 1;
	    	q=q->next;
		}
	return 0;
}



void sort1(head1 *t)
{  node *q,*i,*j;
   q=t->start;
   
   for(i=t->start;i->next!=NULL;i=i->next)
   for(j=t->start;j->next!=NULL;j=j->next)
       {   if(strcmp(j->roll_no,j->next->roll_no)>0)
                 {   char t1[30];
                     strcpy(t1,j->roll_no);
                     strcpy(j->roll_no,j->next->roll_no);
                     strcpy(j->next->roll_no,t1);
                     
                     strcpy(t1,j->name);
                     strcpy(j->name,j->next->name);
                     strcpy(j->next->name,t1);
                     
                     float t;
                     t=j->p;
                     j->p=j->next->p;
                     j->next->p=t;
                     
                     t=j->c;
                     j->c=j->next->c;
                     j->next->c=t;
                     
                     t=j->m;
                     j->m=j->next->m;
                     j->next->m=t;
                     
                     t=j->mec;
                     j->mec=j->next->mec;
                     j->next->mec=t;
                     
                     t=j->bee;
                     j->bee=j->next->bee;
                     j->next->bee=t;
                     
                 }
           
       }   
    
}

void insertbeg1(head1 *t,char num[],char namee[],float sub1,float sub2,float sub3,float sub4,float sub5)
{ node *q;
   q=(node *)malloc(sizeof(node));
   
  int i;
   for(i=0;num[i];i++)q->roll_no[i]=num[i];
   

   for( i=0;namee[i];i++)q->name[i]=namee[i];
   q->p=sub1;
   q->c=sub2; 
   q->m=sub3;
   q->mec=sub4;
   q->bee=sub5;
   
   q->next=t->start;
   t->start=q;
    
}

void display1(head1 *t)
{
    if(t->start==NULL)
       {
           return;
       }
    node *q;
    q=t->start;
    while(q!=NULL)
       {
           printf("\n ROLL_NO: ");
           puts(q->roll_no);
           
           printf("\n NAME: ");
           puts(q->name);
           printf("\n MARKS OF PHYSICS: %5.2f",q->p);
           printf("\n MARKS OF CHEMISTRY: %5.2f",q->c);
           printf("\n MARKS OF MATHS: %5.2f",q->m);
           printf("\n MARKS OF MECHANICS: %5.2f",q->mec);
           printf("\n MARKS OF ELECTRONICS: %5.2f",q->bee);
           
           q=q->next;
       }
    
}

void create1(head1 *t)
{
    
  float sub1,sub2,sub3,sub4,sub5,n=0;
  char Name[20],Num[20];
  char yr[20],dig[10];
  getchar();
  printf("\nEnter the student data");
  
  
  printf("\nENTER YEAR (20XX):");
  gets(yr);
  
  if(strlen(yr)!=2)
     {
         printf("\nRE-ENTER DATA CORRECTLY!!"); return;
     }
  
  printf("\n BRANCH (CE): ");
char  br[]={'C','E'};
  puts(br);
  
  if(strlen(br)>4)
     {
         printf("\nRE-ENTER DATA CORRECTLY!!"); return;
     }
  
  
  int i;
  for(i=0;br[i];i++)br[i]=toupper(br[i]);
  
  strcat(yr,br);
  
  printf("\nENTER ROLL_NO DIGITS: ");
  gets(dig);
  
  if(strlen(dig)==0)
     {
         printf("\nRE-ENTER DATA CORRECTLY!!"); return;
     }
  
  
  strcat(yr,dig);
  
  strcpy(Num,yr);
  
  
  printf("%s",Num);
  
  if(checkr(t,Num)==1)
   { printf("\nRECORD ALREADY PRESENT!! ");
   	return ;
	  }   
  
  
  printf("\nENTER NAME: ");
  gets(Name);
  
  printf("\nENTER MARKS OF PHYSICS: ");
  scanf("%f",&sub1);
  
  printf("\nENTER MARKS OF CHEMISTRY: ");
  scanf("%f",&sub2);
  
  printf("\nENTER MARKS OF MATHS: ");
  scanf("%f",&sub3);
  
  printf("\nENTER MARKS OF MECHANICS: ");
  scanf("%f",&sub4);
  
  printf("\nENTER MARKS OF ELECTRONICS: ");
  scanf("%f",&sub5);
  
  printf("\n%d %d %d",strlen(yr),strlen(br),strlen(dig));
  if((sub1>100 || sub1<0) || (sub2>100 || sub2<0) || (sub3>100 || sub3<0) || (sub4>100 || sub4<0) || (sub5>100 || sub5<0) || (strlen(yr)==0 || strlen(br)==0 || strlen(dig)==0))
    { printf("\nRE-ENTER DATA CORRECTLY!!"); return ;}
insertbeg1(t,Num,Name,sub1,sub2,sub3,sub4,sub5);
  }

void displayr(head1 *t,char ele[])
{    node *q;
     q=t->start;
     while(q!=NULL)
       {
           if(strcmp(q->roll_no,ele)==0)
               break;
            q=q->next;   
       }
    if(q==NULL)
    {
        printf("\nRECORD ABSENT!! ");
        return;
    }
           printf("\nROLL_NO: %s",q->roll_no);
           printf("\n NAME: ");
           puts(q->name);
           printf("\n MARKS OF PHYSICS: %5.2f",q->p);
           printf("\n MARKS OF CHEMISTRY: %5.2f",q->c);
           printf("\n MARKS OF MATHS: %5.2f",q->m);
           printf("\n MARKS OF MECHANICS: %5.2f",q->mec);
           printf("\n MARKS OF ELECTRONICS: %5.2f",q->bee);
           
           float tot=q->p+q->c+q->m+q->mec+q->bee;
                     printf("\n TOTAL MARKS: %5.2f",tot);
                     printf("\n TOTAL PERCENTAGE : %5.2f",tot/5);
 


  
}
void delete1(head1 *t,char ele[])
{
    node *q,*pp=NULL;
    q=t->start;
    
    while(strcmp(q->roll_no,ele)!=0)
    {   pp=q;
        q=q->next;
        
    }
    
    if(q==NULL)
     {
        printf("\nRECORD ABSENT!! ");
        return;
    }
    
    if(pp==NULL)
    {
        t->start=t->start->next; 
        return;
    }
    pp->next=q->next;
    
}

int digits(int n)
{   int c=0;
    while(n!=0)
     {
         n=n/10;
         c++;
     }
    return c;
}

char spe(char v)
{   switch(v)
     {  case '0': return '~';
        case '1': return '!';
        case '2': return ')';
        case '3': return '#';
        case '4': return '$';
        case '5': return '%';
        case '6': return '^';
        case '7': return '&';
        case '8': return '*';
        case '9': return '(';
     }
    
}

char captcha()
{  srand(time(0));
    int x=rand();
    //printf("\n%d",x);
    int dig=digits(x);
    int raised=dig-7;
    int z=(int)x*pow(10,-(raised));
    //printf("\n%d",z);
    dig=7;
    int i=dig-3;
    while(dig>5)
      {  char v='0'+z%10;
        // printf("\n%c\t",v);
         z=z/10;
         for(i;i<dig;i=i+3)
             arr[i]=v;
            i=i-4; 
          dig--;
      }
    char v='0'+z%10;
    z=z/10;
    dig--;
    arr[dig-2]=spe(v);
    int sum=0;
    i=0;
      while(dig>2)
         {   sum=sum+(z%10);
              z=z/10;
              dig--;
         }
         arr[1]='a'+(char)sum;
      
      while(dig>0)
         {   sum=sum+(z%10);
              z=z/10;
              dig--;
         }
      arr[0]='A'+(char)sum;
      printf("\nCAPTCHA: ");
      for(i=0;i<6;i++)
          printf("%c",arr[i]);
        
}

int check(head *t,char uname[],char pass[])
{
    if(t->start==NULL)
        return -1;
    list *q;
    q=t->start;
    while(q!=NULL)
       {   
           if(strcmp(q->password,pass)==0)
             return 1;
            q=q->next; 
       }
    return 0;
}

int isempty(head *t)
{
    if(t->start==NULL)
        return 1;
    return 0;    
}
void insertbegl(head *t,char unam[],char pass[])
{   int rol;
    char g;
    char nam[10];
    list *newnode;
          newnode=(list *)malloc(sizeof(list));
    printf("\nPRESS ENTER TO CONTINUE ");
  fflush(stdin);
  fflush(stdout);
  printf("\nENTER ROLL NO: ");
  scanf("%d",&rol); 
  fflush(stdin);
  fflush(stdout);
  fflush(stdin);
  fflush(stdout);
  printf("\nENTER GENDER (M/F): ");
  scanf("%c",&g); 
     fflush(stdin);
     fflush(stdout);
	 strcpy(newnode->uname,unam);
  
  newnode->gender=g;
  
     fflush(stdin);
     fflush(stdout);
    
    strcpy(newnode->password,pass);

     fflush(stdin);
     fflush(stdout);
  
    newnode->roll_no=rol;
    newnode->next=t->start;
    t->start=newnode;
    
}

void display(head *t)
{  if(t->start==NULL) return;
   list *q;
   q=t->start;
   while(q!=NULL)
   {
       printf("\n%s  %d   %s     %c",q->uname,q->roll_no,q->password,q->gender);
       q=q->next;
   }
    
}

void create_signin(head *t) 
{   int n;
    char uname[6],password[6],conpass[6],captchaa[6],c=NULL;
    printf("\nPress enter: ");
      getchar();
    
     printf("\nENTER USERNAME NAME: ");
      gets(uname);
    getchar();
    printf("\nENTER PASSWORD (LENGTH 6 characters) : ");
    int i=0;
    while((c=getch())!=' ')
         {   password[i]=c;
             printf("*");
             i++;
         }
     password[6]='\0';
     printf("\n%d",strlen(password));
         printf("\n");
         puts(password);
    
    if(check(t,uname,password)==1)
        {   printf("\nPASSWORD ALREADY PRESENT!! PRESS ENTER TO CONTINUE "); getchar();
            create_signin(t);  }
    
    
    printf("\nCONFIRM PASSWORD (LENGTH 6 characters) : ");
    
    
    i=0;
    while((c=getch())!=' ')
         {   conpass[i]=c;
             printf("*");
             i++;
         }
    conpass[6]='\0';
         printf("\n");
      puts(conpass);
    if(strlen(conpass)!=6)
         {  
             printf("\n PASSWORD LENGTH 6 CHARACTERS REQUIRED "); return;}
    
    captcha();
    printf("\nENTER CAPTCHA: ");
    gets(captchaa);
    puts(captchaa);
    
    if(strcmp(captchaa,arr)!=0)
      {
          printf("\nINVALID CAPTCHA!!");
          return;
      }
   
    int z=strcmp(conpass,password);
    printf("\n%d",z);
        
        if(z==0)
        {
            printf("\nCONGRATULATIONS %s you have succesfully singed in!! ",uname);
            insertbegl(t,uname,password);
            printf("\n");
            display(t);
            
        }
       else
           {   printf("\nPASSWORD NOT MATCHED PRESS ENTER TO CONTINUE "); getchar();
               return;
           }
              
}


int login(head *t,char name[],char pass[])
{      char captchaa[6],c=NULL;
  
    list *q;
    q=t->start;
 
    captcha();
    printf("\nENTER CAPTCHA: ");
    gets(captchaa);
    puts(captchaa);
    
    if(strcmp(captchaa,arr)!=0)
      {
          printf("\nINVALID CAPTCHA!!");
          return;
      }
 
 
 
    
    while(q!=NULL)
      {   if(strcmp(q->uname,name)==0 && strcmp(q->password,pass)==0) return 1;   
            q=q->next;
      }     
    return 0;   
}

void report()
{
    head1 y;
      y.start=NULL;
   printf("Project check\n");
   int ch;
   
   while(1)
   {
   printf("\nENTER CHOICE: 1)CREATE REPORT CARD   2)DISPLAY REPORT CARD  3)SORT 4)DELETE RECORD ");
   scanf("%d",&ch);
   if(ch==0)
   break;
   
    switch(ch)
        {
            case 1: create1(&y); printf("\nENTERED DETAILS: "); display1(&y); break;
            case 2: if(y.start==NULL);
                    else{ char ele[50];
                          getchar();
                          printf("\nENTER ROLL_NO: ");
                           gets(ele);
                        displayr(&y,ele); 
                                            }
                    break;
            case 3: if(y.start==NULL);
                    else{ sort1(&y);
                          display1(&y);
                         
                    }
                    break;
            case 4:if(y.start==NULL);
                   else
                       {
                           char ele[50];
                          getchar();
                          printf("\nENTER ROLL_NO: ");
                           gets(ele);
                        delete1(&y,ele);
                        
                        printf("\nUPDATED: ");
                          display1(&y); 
                       }
                      break; 
        }
   
   
   }
    
}

int main()
{   head x;
    x.start=NULL;
    int choice;
    char uname[MAX],password[MAX];
    
    while(1)
    {
    printf("\nENTER CHOICE 1)SIGN_IN 2)LOGIN\n");
    scanf("%d",&choice);
    if(choice==3)
       break;
       
    switch(choice)
    {
        case 1: create_signin(&x); break;
        
        case 2: printf("\nENTER USERNAME: ");
                getchar();
                gets(uname);
                printf("\nENTER Password: ");
               // gets(password);
                char c;
				 int i =0;
                 while((c=getch())!=' ')
                    {   password[i]=c;
                          printf("*");
                           i++;
                    }
                       
                if(isempty(&x))
                  {     printf("\nUSERNAME/PASSWORD NOT FOUND");  }
                else
                    {
                        int z=login(&x,uname,password);
                        if(z==1)
                            {printf("\nHELLO %s you are logged in!!",uname); report(); }
                        else 
                            printf("\nUSERNAME/PASSWORD NOT FOUND");
                        
                    }
                   break;
        default: printf("\nENTER VALID CHOICE ");
        
    }
    }
    return 0;
}

