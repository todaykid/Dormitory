#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define F "data.txt" //�ļ�·��

typedef struct Student
{
	int lh;           //¥�� 
	int roomnum;      //����� 
	int bednum;       //����
	int num;          //ѧ��  
	char name[20];    //���� 
	struct Student *next;
}Stu;

 //�˵�����
int menu_select()
{      
 	int a;
    do{
        system("cls");   // ���� 
        printf("\n\n\t\t----------------------ѧ���������ϵͳ----------------------\n\n");
        printf("\t\t1. ���ѧ����Ϣ     \n\n");
        printf("\t\t2. ��ʾѧ����Ϣ     \n\n");
        printf("\t\t3. ����Ϣ������ʾ \n\n");
        printf("\t\t4. ����ѧ����Ϣ     \n\n");
        printf("\t\t5. ����ѧ����Ϣ     \n\n");
        printf("\t\t6. �޸�ѧ����Ϣ     \n\n");
        printf("\t\t7. ɾ��ѧ����Ϣ     \n\n");
        printf("\t\t8. ����Ϣд���ļ�   \n\n");
        printf("\t\t9. ��ȡ�ļ��е���Ϣ \n\n");
		printf("\t\t0. �˳�ϵͳ         \n\n");
        printf("\t------------------------------------------------------------\n");
        printf("\t��ѡ����Ҫ���е�ѡ�(0-9):");
        scanf("%d",&a);
    }while(a < 0 || a > 9);
    return a;
}

// ���ѧ����Ϣ
Student *input(int n)
{
	int i;
	Stu *head,*l,*r;
	
	if(n <= 0)
		return NULL;
		
	l = (Stu *)malloc(sizeof(Stu));
	
	
	printf("\t\t����¥��");
	scanf("%d",&l->lh); 
	printf("\t\t���������");
	scanf("%d",&l->roomnum);
	printf("\t\t���봲��");
	scanf("%d",&l->bednum); 
	printf("\t\t����ѧ��");
	scanf("%d",&l->num); 
	printf("\t\t��������");
	scanf("%s",&l->name) ;
	printf("\n");
	head = l;
	
	for(i = 1;i < n;i++)
	{
		r = (Stu *)malloc(sizeof(Stu));
		
		printf("\t\t����¥��");
		scanf("%d",&l->lh); 
		printf("\t\t���������");
		scanf("%d",&l->roomnum);
		printf("\t\t���봲��");
		scanf("%d",&l->bednum); 
		printf("\t\t����ѧ��");
		scanf("%d",&l->num); 
		printf("\t\t��������");
		scanf("%s",&l->name) ;
		printf("\n");
		l->next = r;
		l = r;
		
		if(i==n-1)
			l->next = NULL;				 
	}
	return head;
 }
 //��� 
void output(Stu *head)
{
	Stu *p;
	p=head;
	if(head==NULL)
	{
		printf("\n\t\t\tѧ����ϢΪ�գ�\n");
	}
	else
	{
		do
		{
			printf("\t\t¥��Ϊ��%5d   ����ţ�%5d   ���ţ�%5d   ѧ�ţ�%5d   ������%5s\n",p->lh,p->roomnum,p->bednum,p->num,p->name);
			p=p->next;
		}while(p!=NULL);
	}  
} 
//����˵� 
int sort_menu()
{
	int a;
    do{
    	system("cls");
		printf("\n\n\t\t------------------------------------------------------------\n\n"); 
        printf("\t\t\t1. ������������\n\n");
        printf("\t\t\t2. ����ѧ������\n\n");
        printf("\t\t\t3. �������������\n\n");
        printf("\t\t\t0. ���ص����˵�\n\n");
        printf("\t\t------------------------------------------------------------\n");
        printf("\t\t��ѡ����Ҫ���е�ѡ�(0-3):");
        scanf("%d",&a);
    }while(a<0||a>3);
    return a;
}
//����ѡ��˵�
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
		case 1://���� 
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
	    case 2://ѧ�� 
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
	    case 3://����� 
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

//����ѧ����Ϣ
void insert(Stu *head)
{
    Stu *p,*pnew;
    int m;
	pnew=(Stu *)malloc(sizeof(Stu));
    printf("\t\t����¥��:");
	scanf("%d",&pnew->lh);
	printf("\t\t�����:");                
	scanf("%d",&pnew->roomnum);
	printf("\t\t��λ��:");
	scanf("%d",&pnew->bednum);
	printf("\t\tѧ��:");
	scanf("%d",&pnew->num);
	printf("\t\t����:");
	scanf("%s",&pnew->name);
	printf("\n");
    printf("\t\t\t��������Ҫ�嵽��λ�ã�");
	scanf("%d",&m);
	p=head;
	for(int j=1;j<m&&p!=NULL;j++)
	{
	    p=p->next;
	}
	pnew->next=p->next;
	p->next=pnew;
}
//���Ҳ˵� 
int find_menu()
{
	int a;
    do{
    	system("cls");
		printf("\n\n\t\t------------------------------------------------------------\n\n"); 
        printf("\t\t\t1. ������������\n\n");
        printf("\t\t\t2. ����ѧ�Ų���\n\n");
        printf("\t\t\t3. ��������Ų���\n\n");
        printf("\t\t\t0. ���ص����˵�\n\n");
        printf("\t\t------------------------------------------------------------\n");
        printf("\t\t��ѡ����Ҫ���е�ѡ�(0-3):");
        scanf("%d",&a);
    }while(a<0||a>8);
    return a;
}
//����ѡ��˵� 
int find_select(Stu *head,int n)
{
	Stu *p;
    switch(n)
	{
		case 1:
			system("cls");
			p=head;
			char g[20];
			printf("\n\t\t\tҪ���ҵ�����Ϊ��");
			scanf("%s",&g);
			while(p!=NULL)
			{
				if(strcmp(p->name,g)==0)
					printf("\t\t¥��Ϊ��%5d   ����ţ�%5d   ���ţ�%5d   ѧ�ţ�%5d   ������%5s\n",p->lh,p->roomnum,p->bednum,p->num,p->name);			
				p=p->next;
			}
			system("pause");
			return 1;
		case 2:
			system("cls");
			p=head;
			int f;
			printf("\n\t\t\tҪ���ҵ�ѧ��Ϊ��");
			scanf("%d",&f);
			while(p!=NULL)
			{
				if(p->num==f)
					printf("\t\t¥��Ϊ��%5d   ����ţ�%5d   ���ţ�%5d   ѧ�ţ�%5d   ������%5s\n",p->lh,p->roomnum,p->bednum,p->num,p->name);			
				p=p->next;
			}
			system("pause");
			return 1; 
		case 3:
 			system("cls");
			p=head;
			int b;
			printf("\n\t\t\tҪ���ҵ������Ϊ��");
			scanf("%d",&b);
			while(p!=NULL)
			{
				if(p->roomnum==b)
					printf("\t\t¥��Ϊ��%5d   ����ţ�%5d   ���ţ�%5d   ѧ�ţ�%5d   ������%5s\n",p->lh,p->roomnum,p->bednum,p->num,p->name);			
				p=p->next;
			}
	        system("pause");
	        return 1;
	    case 0:
	    	system("pause");
	    	return 0;
	}
}
//�޸�ѧ����Ϣ 
void correct(Stu *head)
{
	int a;
	printf("\n\t\t\t�����뽫Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%d",&a);
	Stu *p;
    p = head;
	while(p!=NULL)
    {
    	if(a==p->num)
    	{
			printf("\t\tҪ�޸ĵ�����¥��:");
		    scanf("%d",&p->lh);
		    printf("\t\tҪ�޸ĵ������:");                
		    scanf("%d",&p->roomnum);
		    printf("\t\tҪ�޸ĵĴ�λ��:");
		    scanf("%d",&p->bednum);
		    printf("\t\tҪ�޸ĵ�ѧ��:");
		    scanf("%d",&p->num);
		    printf("\t\tҪ�޸ĵ�����:");
		    scanf("%s",&p->name);
		    printf("\n");
		}
        p=p->next;
    }
}
 
//ɾ��ѧ����Ϣ
Student *del(Stu *head)
{
	int x,y; 
	printf("\n\t\t\t1.ɾ��ĳ��ѧ����Ϣ");
	printf("\n\t\t\t2.ɾ��ȫ��ѧ����Ϣ\n");
	printf("\n\t\t\tѡ��1��2��");
    scanf("%d",&x);
    if(x==1)
    {
    	printf("\n\t\t\t�����뽫Ҫɾ��ѧ����λ�ã�");
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
		printf("\n\t\t\tɾ���ɹ���\n");
		return head;
	}
	else if(x==2)
	{
		head=NULL;
		printf("\n\t\t\tɾ���ɹ���\n");
		return head;
	}
	else
	{
		printf("������󣬷������˵���\n");
		return head;
	}
}
 
//д���ļ� 
void write_file(Stu *head)
{
	FILE *fp;
	if((fp=fopen(F,"at+"))==NULL) //ָ���ķ�ʽ���ļ� 
	{
		printf("�ļ���ʧ�ܣ�\n");
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
	 
    fflush(fp); //����ļ������������ļ���д��ʽ��ʱ��������������д���ļ� 
    fclose(fp); /*fclose()�����ر���ǰfopen()�򿪵��ļ���
	            �˶������û������ڵ�����д���ļ���, ���ͷ�ϵͳ���ṩ���ļ���Դ����Ҫʱˢ�»����� */ 
}
 
//��ȡ�ļ� 
void read_file()
{
	int lh;			//����¥�� 
    int roomnum;	//����� 
    int bednum;		//��λ�� 
    int num;		//ѧ�� 
    char name[20];	//���� 
 
	FILE *fp;
	fp=fopen(F,"rt");
	while(fscanf(fp,"%d\t%d\t%d\t%d\t%s\t",&lh,&roomnum,&bednum,&num,&name)!=EOF)
	{
		printf("\t\t¥��Ϊ��%5d   ����ţ�%5d   ���ţ�%5d   ѧ�ţ�%5d   ������%5s\n",lh,roomnum,bednum,num,name);
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
				printf("\t\t\t����ѧ���ĸ�����");
				scanf("%d",&n);
				if(n <= 0)
				{
					printf("\n\t\t\t��������ȷ������!");
					break;
				}
				else
				{
					printf("\n\t\t\t����ѧ������\n\n");
	            	head=input(n);
	            	break;
				}
            case 2:
            	system("cls");
	            printf("\n\t\t\t��ʾѧ������\n");
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
                printf("\t\t\t����Ҫ�����ѧ������Ϣ\n");
				insert(head);
				printf("\n\t\t����ɹ���\n");
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
				printf("\n\t\t\t�޸ĳɹ���\n");
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
				printf("\n\t\t\tд��ɹ���\n");
				system("pause");
				break;
			case 9:
				printf("\n\t\t\t��ȡ�ɹ���\n");
				read_file();
				system("pause");
				break;
            case 0:
                printf("\n\t\t\tллʹ��\n");
                exit(0);
        }
	}
}
















 
