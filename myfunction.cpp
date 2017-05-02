
#include <stdio.h>
#include <windows.h>
#include <math.h>

#include "offical.h"
#include "function.h"
#include "action.h"
//***********编写的函数********************************************//
//在我方半场1时不应有kick
//应该再加两个个判断！！上下边沿vs顺时针和逆时针，在我方半场才需要旋转防守！！！！
#define MYDISTANCE 0.03
int judgeballmove( Mydata * p )//判断球是否移动,1为没有移动需要旋转，0为有球移动不用转
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
	
			PositionAndStopX(env,i,p->robot[i].pos,-125,0);//所有人在当前位置旋转/////离球最近的转就好了——bamboo
		
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
	mm.x=75;//蓝方则25

   //进攻区
			{PositionAndThrough(env,m,mm,180);}
		if(p->curball.x>75){PositionAndThrough(env,m,p->preball,180);}
    
	}
	else{
	go.x=10;//10
	mm.x=25;//蓝方则25
	
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
	mm1.x=79;mm2.x=79;//蓝方则21
	mm1.y=36;
	mm2.y=47;
   //进攻区
			if(p->curball.y>42)//上方 下方准备
			{PositionAndThrough(env,m2,mm1,120);q=1;}
			if(p->curball.y<42&&q==1){PositionAndThrough(env,m2,p->curball,140);q=0;}//上转下
    //2负责下方卖萌  3负责下方卖萌
			if(p->curball.y<42)//下方 上方准备
			{PositionAndThrough(env,m3,mm2,120);q=0;}
			if(p->curball.y>42&&q==0){PositionAndThrough(env,m3,p->curball,140);q=1;}//转上
			
}	*/