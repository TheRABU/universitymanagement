#include<stdio.h>
#define MAX 50
FILE *file;
char student_info;
struct student
{
 char name[100];
 char dept[100];
 char address[100];
 char id[100];
 float gpa;

};
struct faculty
{
    char name[100];
    char study[100];
    char address[100];
    float salary;

};

struct stuff
{
    char name[100];
    char address[100];
    float salary;

};
struct Campus
{
    char name[30];
    struct student list[MAX];
        int student_count;

};

void print_student(struct student s)
{
    printf("##############\n");
    printf("name:%s\n",s.name);
    printf("Department:%s\n",s.dept);
    printf("Address:%s\n",s.address);
    printf("Reg_Id: %s\n",s.id);
    printf("GPA: %.2f\n",s.gpa);
    printf("##############\n");

}
void print_faculty(struct faculty f)
{
    printf("##############\n");
    printf("name:%s\n",f.name);
    printf("Education:%s\n",f.study);
    printf("Address:%s\n",f.address);
    printf("Salary: %f\n",f.salary);
    printf("##############\n");
}
void print_stuff(struct stuff sf)
{
    printf("##############\n");
    printf("name:%s\n",sf.name);
    printf("Address:%s\n",sf.address);
    printf("Salary: %f\n",sf.salary);
    printf("##############\n");
}

int insert(struct student s, struct Campus *c)
{
 int studentcount = c->student_count;
 if(studentcount>=MAX)
 {
  return 0;
 }
 else
 {
  c->list[studentcount] = s;
  c->student_count++;
  return 1;
 }

}

void print_all(struct Campus *c)
{
 int studentcount = c->student_count;
 int i;
 for(i=1;i<studentcount;i++)
 {
  printf("student %d\n",i);
  print_student(c->list[i]);
 }
}

int search(char name[] , struct Campus *c)
{
 int studentcount= c->student_count;
 int i;
 for(i=0;i<studentcount;i++)
 {
  int match_results = strcmp(name, c->list[i],name);
  if(match_results == 0) return i++;
 }
 return -1;
}

int remove_student(char name[],struct Campus *c)
{
 int studentcount = c->student_count;
 int index = search (name,c);
 if(index == -1)return 0;
 if (index == studentcount-1)
 {
  c->student_count--;
  return 1;
 }
 else
 {
  c->list[index] = c->list[studentcount-1];
  c->student_count--;
  return 1;
 }
}

void save()
{

}


int main()
{
struct Campus c1,c2;
struct Campus current_campus;
struct faculty f;
struct stuff st;
int option,campus_no;

printf("student campus_details:\n");
printf("Enter your campus no:\n");
scanf("%d",&campus_no);
if(campus_no==1)
{
 current_campus=c1;
}
else
{
 current_campus=c2;
}


while (1)
{
 struct student s;
 char name[20];
 int f;
 printf("Enter your option no:\n");
 scanf("%d",&option);
 getchar();

 if(campus_no==1)
{

 c1=current_campus;

}
else
{
 c2=current_campus;

}


switch(option)
{
 case 1: ;
 //insert
    file=fopen("Student__Info.txt","a");
    if(file==NULL)
        printf("File not found");
    printf("Enter Student Name:");
 gets(s.name);
 fprintf(file,"Student Name: %s\n",s.name);
 printf("\nEnter Student Department:");
 gets(s.dept);
 getchar();
 printf("\nEnter Student Address:");
 gets(s.address);

 fprintf(file,"student Address:%s\n",s.address);

 printf("\nEnter Student Reg_ID:");
 gets(s.id);
 getchar();
 fprintf(file,"Reg_ID",s.id);

 printf("\nEnter Student GPA:");
 scanf("%.2f",&s.gpa);
 getchar();

 fprintf(file,"gpa",s.gpa);

 fclose(file);
 getchar();
 print_student(s);
 insert(s,&current_campus);
 break;
case 2:
 //search
 gets(name);
 int index = search(name,&current_campus);
 if(index== -1) printf("Not Found\n");
 else printf("Found at index: %d\n",index);
 break;

 case 4:
 //remove
 gets(name);
 f = remove_student(name,&current_campus);

 break;
 case 5:
 //print
 printf("printing Campus 1\n");
 print_all(&c1);
 printf("printing Campus 2\n");
 print_all(&c2);
 break;
 case 6:
  //save
 printf("\nStudent Info\n");
 file=fopen("Student__Info.txt","r");
 while((student_info=fgetc(file))!=EOF)
        printf("%c",student_info);
        fclose(file);
 break;
 case 7:
 //hospital change
 printf("Enter your campus no:\n");
 scanf("%d",&campus_no);
 if(campus_no==2)
{

 current_campus=c1;

}
else
{
 current_campus=c2;

}
 break;

 case 0:
 //exit
 save(1);
 exit(0);

 default:
 printf("Not a valid option\n");
  }

 }
 return 0;
}



