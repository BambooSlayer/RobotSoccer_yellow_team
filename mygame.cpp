#include <string.h>
#include <stdio.h>
#include<math.h>
#include <windows.h>

#include "offical.h"
#include "function.h"
#include "action.h"
#include "strategy.h"
#include "mygame.h"
#include "myfunction.h"

//����ʦд�Ĵ���
void NormalGame ( Environment *env )
{
	Mydata * p;
	p=(Mydata *)env->userData;
/*    switch(CheckBall(env))
	{
	case 1:
		break;
	default:
		break;
	}
 */
	 MyGoalie(env,0);//����Ա���ԣ����鲻Ҫ�޸�
	
	 Vector3D go;
	go.x=90;
	go.y=43;
	Vector3D goB;
	goB.x=10;
	goB.y=43;
	Vector3D go2;
		Vector3D zs;zs.x=10;zs.y=71;
			Vector3D zx;zx.x=10;zs.y=12;
				Vector3D ys;ys.x=90;ys.y=71;
					Vector3D yx;yx.x=90;yx.y=12;
   
	 //RollWhenStuck(env);  
	if(p->mygrand){//�ǻƶ�
		if (p->curball.x<55&&p->curball.x>45&&p->curball.y>20&&p->curball.y<60)//�칥��
		{PositionAndThrough(env,1,p->curball,180);
			 go2.x=30;
	        go2.y=p->curball.y;
            PositionAndStop(env,2,go2);
		PositionAndThrough(env,3,p->curball,180);
		PositionAndThrough(env,4,p->curball,180);
		PositionAndThrough(env,5,p->curball,180);}
	    else if (p->curball.x>72&&p->curball.y>20&&p->curball.y<60)//������
		{JG(env,3);Kick(env,1,go);Kick(env,4,go);
			go2.x=30;
	        go2.y=p->curball.y;
            PositionAndStop(env,2,go2);}
		else if(p->curball.x<30&&p->curball.y>20&&p->curball.y<60)//������
		{ PositionAndThrough(env,2,p->preball,180);//XY

	//	PushRobot(env,2,p->opp[1],go);//����
      // Pushbot(env,3,p->opp[4],go);
	   	Kick(env,1,go);	Kick(env,4,go);Kick(env,3,go);
        		}
		else if(p->curball.y<12){Kick(env,1,yx);Kick(env,2,yx);Kick(env,3,yx);Kick(env,4,yx);}
		else if(p->curball.y>71){Kick(env,1,ys);Kick(env,2,ys);Kick(env,3,ys);Kick(env,4,ys);}//�߷���
	//	
	//	//////////////////////////////////////////
	//	}
		else  {	for(int i=1;i<5;i++)Kick(env,i,go);}	//������kick

	}
  else//BLUE
	{
			if (p->curball.x<55&&p->curball.x>45&&p->curball.y>20&&p->curball.y<60)//�칥��
		{PositionAndThrough(env,1,p->curball,180);
		   	go2.x=60;
	        go2.y=p->curball.y;
            PositionAndStop(env,2,go2);
		PositionAndThrough(env,3,p->curball,180);
		PositionAndThrough(env,4,p->curball,180);
		PositionAndThrough(env,5,p->curball,180);}
	    else if (p->curball.x>72&&p->curball.y>20&&p->curball.y<60)//������
		{JG(env,3);Kick(env,1,goB);Kick(env,4,goB);
			go2.x=60;
	        go2.y=p->curball.y;
            PositionAndStop(env,2,go2);}
		else if(p->curball.x<30&&p->curball.y>20&&p->curball.y<60)//������
		{ PositionAndThrough(env,2,p->preball,180);//XY

	//	PushRobot(env,2,p->opp[1],go);//����?
       // PushRobot(env,3,p->opp[4],go);
		Kick(env,1,goB);	Kick(env,4,goB);Kick(env,3,goB);	
        		}
	//		else if(p->curball.y<12||p->curball.y>71){//�߷���
       else if(p->curball.y<12){Kick(env,1,zx);Kick(env,2,zx);Kick(env,3,zx);Kick(env,4,zx);}
		else if(p->curball.y>71){Kick(env,1,zs);Kick(env,2,zs);Kick(env,3,zs);Kick(env,4,zs);}//�߷���

	//	Kick(env,1,goB);Kick(env,2,goB)	;Kick(env,4,goB);Kick(env,3,goB);
	//}
		else  {	for(int i=1;i<5;i++)Kick(env,i,goB);}	//������kick
	}

}
	
	//���޷���ʱʹ�� ������ĵ��á�������ʱ�ӣ������� 
	//����ʱ������kick �����ױ���

//	Velocity(env,1,125,125);
  
//����ʦд����




void FreeBallGame(Environment *env)
{	Mydata * p;
	p=(Mydata *)env->userData;
 /////
	NormalGame(env);

}

void PlaceBallGame(Environment *env)
{
	NormalGame(env);
}

void PenaltyBallGame(Environment *env)
{  /* Vector3D goo;
    Vector3D goo1;
	////////////////////////////////////////////////������ �ٴ�������
 	//Angle(env,1,-20);
	goo.x=93;goo.y=48;
	goo1.x=93;goo.y=28;
	PositionAndThrough(env,1,goo,150);
	*/
	NormalGame(env);
}

void FreeKickGame(Environment *env)
{
	NormalGame(env);
}

void GoalKickGame(Environment *env)
{
	NormalGame(env);
}


//////
/*MyGame  �Բ�ͬ��GameState���ò�ͬ�Ĳ���
�����ڸ���״̬֮���л���ʱ�����˼���������Ϊ������״̬�ı䵽����״̬���жϱ�־
ÿ������״̬���м�����

*/
//

void MyGame ( Environment *env )
{
	Mydata * p;
	p=(Mydata *)env->userData;
	switch(p->gameState)
	{
	case FREE_BALL:	//1:
		 FreeBallGame(env);
		 break;
	case PLACE_KICK:	//2:
   		 PlaceBallGame(env);	 
		 break;
	case PENALTY_KICK:	//3:
		 PenaltyBallGame(env);	
		 break;
	case FREE_KICK:	//4:
	     FreeKickGame(env);
		 break;
	case GOAL_KICK:	//5:
		 GoalKickGame(env);
		 break;
	default :
		 NormalGame(env);
		 break;
	}
	
}
