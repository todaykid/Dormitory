#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define F "data.txt" //文件路径

typedef struct Student
{
	int lh;           //楼号 
	int roomnum;      //宿舍号 
	int bednum;       //床号
	int num;          //学号  
	char name[20];    //姓名 
	struct Student *next;
}Stu;

 //菜单界面
int menu_select()
{      
 	int a;
    do{
        system("cls");   // 清屏 
        printf("\n\n\t\t----------------------学生宿舍管理系统----------------------\n\n");
        printf("\t\t1. 添加学生信息     \n\n");
        printf("\t\t2. 显示学生信息     \n\n");
        printf("\t\t3. 按信息排序并显示 \n\n");
        printf("\t\t4. 插入学生信息     \n\n");
        printf("\t\t5. 查找学生信息     \n\n");
        printf("\t\t6. 修改学生信息     \n\n");
        printf("\t\t7. 删除学生信息     \n\n");
        printf("\t\t8. 将信息写入文件   \n\n");
        printf("\t\t9. 读取文件中的信息 \n\n");
		printf("\t\t0. 退出系统         \n\n");
        printf("\t------------------------------------------------------------\n");
        printf("\t请选择您要运行的选项按(0-9):");
        scanf("%d",&a);
    }while(a < 0 || a > 9);
    return a;
}

// 添加学生信息
Student *input(int n)
{
	int i;
	Stu *head,*l,*r;
	
	if(n <= 0)
		return NULL;
		
	l = (Stu *)malloc(sizeof(Stu));
	
	
	printf("\t\t输入楼号");
	scanf("%d",&l->lh); 
	printf("\t\t输入宿舍号");
	scanf("%d",&l->roomnum);
	printf("\t\t输入床号");
	scanf("%d",&l->bednum); 
	printf("\t\t输入学号");
	scanf("%d",&l->num); 
	printf("\t\t输入姓名");
	scanf("%s",&l->name) ;
	printf("\n");
	head = l;
	
	for(i = 1;i < n;i++)
	{
		r = (Stu *)malloc(sizeof(Stu));
		
		printf("\t\t输入楼号");
		scanf("%d",&l->lh); 
		printf("\t\t输入宿舍号");
		scanf("%d",&l->roomnum);
		printf("\t\t输入床号");
		scanf("%d",&l->bednum); 
		printf("\t\t输入学号");
		scanf("%d",&l->num); 
		printf("\t\t输入姓名");
		scanf("%s",&l->name) ;
		printf("\n");
		l->next = r;
		l = r;
		
		if(i==n-1)
			l->next = NULL;				 
	}
	return head;
 }
 //输出 
void output(Stu *head)
{
	Stu *p;
	p=head;
	if(head==NULL)
	{
		printf("\n\t\t\t学生信息为空！\n");
	}
	else
	{
		do
		{
			printf("\t\t楼号为：%5d   宿舍号：%5d   床号：%5d   学号：%5d   姓名：%5s\n",p->lh,p->roomnum,p->bednum,p->num,p->name);
			p=p->next;
		}while(p!=NULL);
	}  
} 
//排序菜单 
int sort_menu()
{
	int a;
    do{
    	system("cls");
		printf("\n\n\t\t------------------------------------------------------------\n\n"); 
        printf("\t\t\t1. 按照姓名排序\n\n");
        printf("\t\t\t2. 按照学号排序\n\n");
        printf("\t\t\t3. 按照宿舍号排序\n\n");
        printf("\t\t\t0. 返回到主菜单\n\n");
        printf("\t\t------------------------------------------------------------\n");
        printf("\t\t请选择您要运行的选项按(0-3):");
        scanf("%d",&a);
    }while(a<0||a>3);
    return a;
}
//排序选择菜单
int sort_select(Stu *head,int n) 
{
	Stu *p,*q;
	int lh;
	int roomnum;
	int bednum;
	int num; 
	char name[20];
    switch(n)
	{
		case 1://姓名 
			system("cls");   
			for(p=head;p!=NULL;p=p->next)
			{
			    for(q=p->next;q!=NULL;q=q->next)
			    {
			        if(p->name > q->name)
			        {
			            lh=q->lh;
			            roomnum=q->roomnum;
			            bednum=q->bednum;
			            num=q->num;
			            strcpy(name,q->name);
			            
		                q->lh=p->lh;
		                q->roomnum=p->roomnum;
			            q->bednum=p->bednum;
			            q->num=p->num;
			            strcpy(q->name,p->name);
			            
		                p->lh=lh;
		                p->roomnum=roomnum;
		                p->bednum=bednum;
		                p->num=num;
		                strcpy(p->name,name);
					}
			    }
			}
		    output(head);
	        system("pause");
	        return 1;
	    case 2://学号 
			system("cls");    
			for(p = head ;p!=NULL;p=p->next)
			{
			    for(q=p->next;q!=NULL;q=q->next)
			    {
			        if(p->num > q->num)
			        {
			        	lh=q->lh;
			            roomnum=q->roomnum;
			            bednum=q->bednum;
			            num=q->num;
			            strcpy(name,q->name);
			            
		                q->lh=p->lh;
		                q->roomnum=p->roomnum;
			            q->bednum=p->bednum;
			            q->num=p->num;
			            strcpy(q->name,p->name);
			            
		                p->lh=lh;
		                p->roomnum=roomnum;
		                p->bednum=bednum;
		                p->num=num;
		                strcpy(p->name,name);
					}
			    }
			}
		    output(head);
	    	system("pause");
			return 1;
	    case 3://宿舍号 
	    	system("cls");		    
			for(p=head;p!=NULL;p=p->next)
			{
			    for(q=p->next;q!=NULL;q=q->next)
			    {
			        if(p->roomnum > q->roomnum)
			        {
			            lh=q->lh;
			            roomnum=q->roomnum;
			            bednum=q->bednum;
			            num=q->num;
			            strcpy(name,q->name);
			            
		                q->lh=p->lh;
		                q->roomnum=p->roomnum;
			            q->bednum=p->bednum;
			            q->num=p->num;
			            strcpy(q->name,p->name);
			            
		                p->lh=lh;
		                p->roomnum=roomnum;
		                p->bednum=bednum;
		                p->num=num;
		                strcpy(p->name,name);
					}
			    }
			}
		    output(head);
	    	system("pause");
	    	return 1;	
	    case 0:
	    	system("pause");
	    	return 0;
	}
}

//插入学生信息
void insert(Stu *head)
{
    Stu *p,*pnew;
    int m;
	pnew=(Stu *)malloc(sizeof(Stu));
    printf("\t\t宿舍楼号:");
	scanf("%d",&pnew->lh);
	printf("\t\t房间号:");                
	scanf("%d",&pnew->roomnum);
	printf("\t\t床位号:");
	scanf("%d",&pnew->bednum);
	printf("\t\t学号:");
	scanf("%d",&pnew->num);
	printf("\t\t姓名:");
	scanf("%s",&pnew->name);
	printf("\n");
    printf("\t\t\t请输入想要插到的位置：");
	scanf("%d",&m);
	p=head;
	for(int j=1;j<m&&p!=NULL;j++)
	{
	    p=p->next;
	}
	pnew->next=p->next;
	p->next=pnew;
}
//查找菜单 
int find_menu()
{
	int a;
    do{
    	system("cls");
		printf("\n\n\t\t------------------------------------------------------------\n\n"); 
        printf("\t\t\t1. 按照姓名查找\n\n");
        printf("\t\t\t2. 按照学号查找\n\n");
        printf("\t\t\t3. 按照宿舍号查找\n\n");
        printf("\t\t\t0. 返回到主菜单\n\n");
        printf("\t\t------------------------------------------------------------\n");
        printf("\t\t请选择您要运行的选项按(0-3):");
        scanf("%d",&a);
    }while(a<0||a>8);
    return a;
}
//查找选择菜单 
int find_select(Stu *head,int n)
{
	Stu *p;
    switch(n)
	{
		case 1:
			system("cls");
			p=head;
			char g[20];
			printf("\n\t\t\t要查找的姓名为：");
			scanf("%s",&g);
			while(p!=NULL)
			{
				if(strcmp(p->name,g)==0)
					printf("\t\t楼号为：%5d   宿舍号：%5d   床号：%5d   学号：%5d   姓名：%5s\n",p->lh,p->roomnum,p->bednum,p->num,p->name);			
				p=p->next;
			}
			system("pause");
			return 1;
		case 2:
			system("cls");
			p=head;
			int f;
			printf("\n\t\t\t要查找的学号为：");
			scanf("%d",&f);
			while(p!=NULL)
			{
				if(p->num==f)
					printf("\t\t楼号为：%5d   宿舍号：%5d   床号：%5d   学号：%5d   姓名：%5s\n",p->lh,p->roomnum,p->bednum,p->num,p->name);			
				p=p->next;
			}
			system("pause");
			return 1; 
		case 3:
 			system("cls");
			p=head;
			int b;
			printf("\n\t\t\t要查找的宿舍号为：");
			scanf("%d",&b);
			while(p!=NULL)
			{
				if(p->roomnum==b)
					printf("\t\t楼号为：%5d   宿舍号：%5d   床号：%5d   学号：%5d   姓名：%5s\n",p->lh,p->roomnum,p->bednum,p->num,p->name);			
				p=p->next;
			}
	        system("pause");
	        return 1;
	    case 0:
	    	system("pause");
	    	return 0;
	}
}
//修改学生信息 
void correct(Stu *head)
{
	int a;
	printf("\n\t\t\t请输入将要修改的学生的学号：");
	scanf("%d",&a);
	Stu *p;
    p = head;
	while(p!=NULL)
    {
    	if(a==p->num)
    	{
			printf("\t\t要修改的宿舍楼号:");
		    scanf("%d",&p->lh);
		    printf("\t\t要修改的宿舍号:");                
		    scanf("%d",&p->roomnum);
		    printf("\t\t要修改的床位号:");
		    scanf("%d",&p->bednum);
		    printf("\t\t要修改的学号:");
		    scanf("%d",&p->num);
		    printf("\t\t要修改的姓名:");
		    scanf("%s",&p->name);
		    printf("\n");
		}
        p=p->next;
    }
}
 
//删除学生信息
Student *del(Stu *head)
{
	int x,y; 
	printf("\n\t\t\t1.删除某个学生信息");
	printf("\n\t\t\t2.删除全部学生信息\n");
	printf("\n\t\t\t选择1或2：");
    scanf("%d",&x);
    if(x==1)
    {
    	printf("\n\t\t\t请输入将要删除学生的位置：");
    	scanf("%d",&y);
    	Stu *p,*q;
	    int i;
	    if(y-1==0)
	    {
			head=head->next;
		}
		else
		{
	    	p=head;
	    	for(i=1;i<y&&p->next!=NULL;i++)
			{
				p=p->next;
			}
			q=p->next;
			p->next=q->next;
		}
		printf("\n\t\t\t删除成功！\n");
		return head;
	}
	else if(x==2)
	{
		head=NULL;
		printf("\n\t\t\t删除成功！\n");
		return head;
	}
	else
	{
		printf("输入错误，返回主菜单！\n");
		return head;
	}
}
 
//写入文件 
void write_file(Stu *head)
{
	FILE *fp;
	if((fp=fopen(F,"at+"))==NULL) //指定的方式打开文件 
	{
		printf("文件打开失败！\n");
	}
	Stu *p;
	p=head;
	while(p!=NULL)
	{
		fprintf(fp,"%d\t",p->lh);
		fprintf(fp,"%d\t",p->roomnum);
		fprintf(fp,"%d\t",p->bednum);
		fprintf(fp,"%d\t",p->num);
		fprintf(fp,"%s\t",p->name);
		p=p->next;
	}
	 
    fflush(fp); //清除文件缓冲区，当文件以写方式打开时，将缓冲区内容写入文件 
    fclose(fp); /*fclose()用来关闭先前fopen()打开的文件。
	            此动作会让缓冲区内的数据写入文件中, 并释放系统所提供的文件资源。必要时刷新缓冲区 */ 
}
 
//读取文件 
void read_file()
{
	int lh;			//宿舍楼号 
    int roomnum;	//宿舍号 
    int bednum;		//床位号 
    int num;		//学号 
    char name[20];	//姓名 
 
	FILE *fp;
	fp=fopen(F,"rt");
	while(fscanf(fp,"%d\t%d\t%d\t%d\t%s\t",&lh,&roomnum,&bednum,&num,&name)!=EOF)
	{
		printf("\t\t楼号为：%5d   宿舍号：%5d   床号：%5d   学号：%5d   姓名：%5s\n",lh,roomnum,bednum,num,name);
	}
}
 



int main()          
{
	
	int n,m,x,y;
	Stu *head = NULL;
	Stu *pnew;
	for(;;)
	{
        switch(menu_select())
        {
            case 1:
            	system("cls");
            	printf("\n\n\t\t------------------------------------------------------------\n\n");
				printf("\t\t\t输入学生的个数：");
				scanf("%d",&n);
				if(n <= 0)
				{
					printf("\n\t\t\t请输入正确的人数!");
					break;
				}
				else
				{
					printf("\n\t\t\t输入学生数据\n\n");
	            	head=input(n);
	            	break;
				}
            case 2:
            	system("cls");
	            printf("\n\t\t\t显示学生数据\n");
	            output(head);
	            system("pause");
	            break; 
            case 3:
				do
				{
					x=sort_select(head,sort_menu());
				}while(x!=0);
                break;
            case 4:
                system("cls");
                printf("\n\n\t\t------------------------------------------------------------\n\n");
                printf("\t\t\t输入要插入的学生的信息\n");
				insert(head);
				printf("\n\t\t插入成功！\n");
				system("pause");
				break;               
            case 5:
            	system("cls");
				do
				{
					y=find_select(head,find_menu());
				}while(y!=0);
                break;
            case 6:
            	system("cls");
                printf("\n\n\t\t------------------------------------------------------------\n\n");
				correct(head);
				printf("\n\t\t\t修改成功！\n");
                system("pause");
                break;
			case 7:
				system("cls");
                printf("\n\n\t\t------------------------------------------------------------\n\n");
                head=del(head);
                system("pause");
                break;
			case 8:
				write_file(head);
				printf("\n\t\t\t写入成功！\n");
				system("pause");
				break;
			case 9:
				printf("\n\t\t\t读取成功！\n");
				read_file();
				system("pause");
				break;
            case 0:
                printf("\n\t\t\t谢谢使用\n");
                exit(0);
        }
	}
}
















 
