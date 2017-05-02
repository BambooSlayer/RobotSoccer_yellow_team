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

//黄老师写的代码
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
	 MyGoalie(env,0);//守门员策略，建议不要修改
	
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
	if(p->mygrand){//是黄队
		if (p->curball.x<55&&p->curball.x>45&&p->curball.y>20&&p->curball.y<60)//快攻区
		{PositionAndThrough(env,1,p->curball,180);
			 go2.x=30;
	        go2.y=p->curball.y;
            PositionAndStop(env,2,go2);
		PositionAndThrough(env,3,p->curball,180);
		PositionAndThrough(env,4,p->curball,180);
		PositionAndThrough(env,5,p->curball,180);}
	    else if (p->curball.x>72&&p->curball.y>20&&p->curball.y<60)//助攻区
		{JG(env,3);Kick(env,1,go);Kick(env,4,go);
			go2.x=30;
	        go2.y=p->curball.y;
            PositionAndStop(env,2,go2);}
		else if(p->curball.x<30&&p->curball.y>20&&p->curball.y<60)//防守区
		{ PositionAndThrough(env,2,p->preball,180);//XY

	//	PushRobot(env,2,p->opp[1],go);//试试
      // Pushbot(env,3,p->opp[4],go);
	   	Kick(env,1,go);	Kick(env,4,go);Kick(env,3,go);
        		}
		else if(p->curball.y<12){Kick(env,1,yx);Kick(env,2,yx);Kick(env,3,yx);Kick(env,4,yx);}
		else if(p->curball.y>71){Kick(env,1,ys);Kick(env,2,ys);Kick(env,3,ys);Kick(env,4,ys);}//边防区
	//	
	//	//////////////////////////////////////////
	//	}
		else  {	for(int i=1;i<5;i++)Kick(env,i,go);}	//其他区kick

	}
  else//BLUE
	{
			if (p->curball.x<55&&p->curball.x>45&&p->curball.y>20&&p->curball.y<60)//快攻区
		{PositionAndThrough(env,1,p->curball,180);
		   	go2.x=60;
	        go2.y=p->curball.y;
            PositionAndStop(env,2,go2);
		PositionAndThrough(env,3,p->curball,180);
		PositionAndThrough(env,4,p->curball,180);
		PositionAndThrough(env,5,p->curball,180);}
	    else if (p->curball.x>72&&p->curball.y>20&&p->curball.y<60)//助攻区
		{JG(env,3);Kick(env,1,goB);Kick(env,4,goB);
			go2.x=60;
	        go2.y=p->curball.y;
            PositionAndStop(env,2,go2);}
		else if(p->curball.x<30&&p->curball.y>20&&p->curball.y<60)//防守区
		{ PositionAndThrough(env,2,p->preball,180);//XY

	//	PushRobot(env,2,p->opp[1],go);//试试?
       // PushRobot(env,3,p->opp[4],go);
		Kick(env,1,goB);	Kick(env,4,goB);Kick(env,3,goB);	
        		}
	//		else if(p->curball.y<12||p->curball.y>71){//边防区
       else if(p->curball.y<12){Kick(env,1,zx);Kick(env,2,zx);Kick(env,3,zx);Kick(env,4,zx);}
		else if(p->curball.y>71){Kick(env,1,zs);Kick(env,2,zs);Kick(env,3,zs);Kick(env,4,zs);}//边防区

	//	Kick(env,1,goB);Kick(env,2,goB)	;Kick(env,4,goB);Kick(env,3,goB);
	//}
		else  {	for(int i=1;i<5;i++)Kick(env,i,goB);}	//其他区kick
	}

}
	
	//仅限发球时使用 最理想的调用——》用时延？！！！ 
	//发球时不能用kick 很容易被动

//	Velocity(env,1,125,125);
  
//黄老师写完了




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
	////////////////////////////////////////////////先推上 再打下试试
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
/*MyGame  对不同的GameState采用不同的策略
并且在各种状态之间切换的时候还用了计数器，作为从特殊状态改变到正常状态的判断标志
每种特殊状态都有计数器

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
