
#include <stdio.h>
#include <windows.h>
#include <math.h>

#include "offical.h"
#include "function.h"
#include "action.h"
//***********��д�ĺ���********************************************//
//���ҷ��볡1ʱ��Ӧ��kick
//Ӧ���ټ��������жϣ������±���vs˳ʱ�����ʱ�룬���ҷ��볡����Ҫ��ת���أ�������
#define MYDISTANCE 0.03
int judgeballmove( Mydata * p )//�ж����Ƿ��ƶ�,1Ϊû���ƶ���Ҫ��ת��0Ϊ�����ƶ�����ת
{
	
	Vector3D stop=p->curball,old=p->oldball;
	double a,b;
	a=stop.x-old.x;
	b=stop.y-old.y;

	if( sqrt(a*a+b*b) < MYDISTANCE )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void RollWhenStuck( Environment *env)
{
	Mydata * p;
	p=(Mydata *)env->userData;


	if(judgeballmove(p))
	{
			int i=1;
		int j=1;
	    int n=1;
	for(i = 1; i < 5; i++)
		{
		for(j = i + 1; j < 5; j++)
		  {
			if(p->RobotAngleToBall[i] < p->RobotAngleToBall[j])
			{    
				n=i;
			}		
            else n=j;
          }			
		}
	
			PositionAndStopX(env,i,p->robot[i].pos,-125,0);//�������ڵ�ǰλ����ת/////���������ת�ͺ��ˡ���bamboo
		
	}
}
void JG(Environment *env,int m){
	Mydata * p;
	p=(Mydata *)env->userData;
	Vector3D go;
	go.y=43;
	Vector3D mm;
	mm.y=38;	
	if(p->mygrand)
	{
	go.x=90;//10
	mm.x=75;//������25

   //������
			{PositionAndThrough(env,m,mm,180);}
		if(p->curball.x>75){PositionAndThrough(env,m,p->preball,180);}
    
	}
	else{
	go.x=10;//10
	mm.x=25;//������25
	
			{PositionAndThrough(env,m,mm,180);}
		if(p->curball.x<25){PositionAndThrough(env,m,p->preball,180);}
}}

/*		
void JG(Environment *env,int m2,int m3){
	Mydata * p;
	p=(Mydata *)env->userData;
	Vector3D go;
	go.x=90;
	go.y=43;
	Vector3D mm1,mm2;
	int q;
	mm1.x=79;mm2.x=79;//������21
	mm1.y=36;
	mm2.y=47;
   //������
			if(p->curball.y>42)//�Ϸ� �·�׼��
			{PositionAndThrough(env,m2,mm1,120);q=1;}
			if(p->curball.y<42&&q==1){PositionAndThrough(env,m2,p->curball,140);q=0;}//��ת��
    //2�����·�����  3�����·�����
			if(p->curball.y<42)//�·� �Ϸ�׼��
			{PositionAndThrough(env,m3,mm2,120);q=0;}
			if(p->curball.y>42&&q==0){PositionAndThrough(env,m3,p->curball,140);q=1;}//ת��
			
}	*/