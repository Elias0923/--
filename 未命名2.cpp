#include<stdio.h>
int Arr[30][30];//����Թ�Ϊ30*30
int Rownum=0,Colnum=0;//������
int Beginrow,Begincol,Endrow,Endcol;//�յ�����
int state=0;//�Թ���ͨ���״̬
int canplace(int row,int col)//�жϵ�ǰ���ܷ���ͨ
{
    if(row>=0 &&col>=0 &&row<Rownum &&col<Colnum &&Arr[row][col]==0)//ΪԽ���ҿ���ͨ
        return 1;
    return 0;
}
void search(int row,int col)
{
    if(row==Endrow && col==Endcol)//��Ŀ���յ�    
    {    state=1;  return ;   }

    int r,c,num;
        num=Arr[row][col];
        //Arr[row][col]=1;//�Կ���ͨ�ĵ���б��
        r=row-1; c=col; //��
    if(canplace(r,c))  { Arr[r][c]=num+1; search(r,c); }
    r=row; c=col+1;//�� 
    if(canplace(r,c))  { Arr[r][c]=num+1; search(r,c); }
    r=row+1;  c=col;//��
    if(canplace(r,c))  { Arr[r][c]=num+1; search(r,c); }
    r=row;    c=col-1;//��
    if(canplace(r,c))  { Arr[r][c]=num+1; search(r,c); }
}
int main()
{ 
    int i,j;
    scanf("%d%d",&Rownum,&Colnum);//�����Թ�������  
    scanf("%d%d%d%d",&Beginrow,&Begincol,&Endrow,&Endcol);//��ʼ�㣬�յ�����
    for(i=0;i<Rownum;i++)
        for(j=0;j<Colnum;j++)
           scanf("%d",&Arr[i][j]);       //һ��һ�е������Թ�����

    Arr[Beginrow][Begincol]=1;
    search(Beginrow,Begincol);
    //һ���Թ�����·���������״̬����ʼ���ͨ���
    int step_num=step_num=Arr[Endrow][Endcol]-1;
    if(state==1)
        printf("%d\n",step_num);
    else
        printf("No\n");    
    return 0;
}

