#include <string.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

#include "offical.h"
#include "function.h"
#include "action.h"
#include "strategy.h"
#include "myfunction.h"
//the coordinate
double x1 = 10;
double x2 = 17;
double x3 = 20;
double x4 = 25;
double x5 = 45;
double x7 = 76.3;
double x10 = 62.0;
double x6 = 61.8;
double x8 = 89.7;
double x9 = 84;

double Y1 = 9.5;
double y2 = 26;
double y3 = 31;
double y4 = 51;
double y5 = 56;
double y6 = 73;
int WIB=0;
int *Role(Environment * env, int *role)
//系统通过Environment* env这个指针向我们传递当前周期系统提供信息
{//角色分配
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
	

	double RoleGrade[5];
	int i,j;
	int exchange;

	for(i = 1; i < 5; i ++){
		role[i] = i;
	}
	
	for(i = i; i < 5; i++){
		RoleGrade[i] = 0.0;//	double RoleGrade[5];
	}
	
	for(i = 1; i < 5; i++){

		if(p->RobotDisToBall[i] <= 20) {
			RoleGrade[i] += 10 - p->RobotDisToBall[i] / 10 ;
		}
		else if(p->RobotDisToBall[i] > 20 && p->RobotDisToBall[i] <= 60){
			RoleGrade[i] += 8 - (p->RobotDisToBall[i] - 20) / 20 ;
		}
		else if(p->RobotDisToBall[i] > 60 && p->RobotDisToBall[i] <= 100){
			RoleGrade[i] += 6 - (p->RobotDisToBall[i] - 60) / 10 ;
		}
		else if(p->RobotDisToBall[i] > 100){
			RoleGrade[i] += 2 - (p->RobotDisToBall[i] - 100) / 40;
		}

		RoleGrade[i] += 6 * (1 - p->RobotAngleToBall[i] / 90);
			
	}

	for(i = 1; i < 5; i++){
		for(j = i + 1; j < 5; j++){
			if(RoleGrade[role[i]] < RoleGrade[role[j]]){     //从大到小排  离球进 role 数字小
				exchange = role[i];
				role[i] = role[j];
				role[j] = exchange;
			}				
		}
	}

	return role;
}

int *OppRole(Environment * env, int *opp)//这是估计对方  
{
	return opp;
}


void DefendForbid(Environment * env)
{//我方禁区
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);


}

void DefendForbidSmall(Environment *env)
{//我方小禁区
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendForbidEdgeAbove(Environment *env)
{//我方禁区边缘上
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendForbidEdgeBellow(Environment * env)
{//我方禁区边缘下
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendBackAbove(Environment *env)
{//我方后场上
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendBackMiddle(Environment * env)
{//我方后场中
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendBackBellow(Environment *env)
{//我方后场下
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendMiddleAbove(Environment *env)
{//我方中场上
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendMiddleMiddle(Environment * env)
{//我方中场中
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendMiddleBellow(Environment *env)
{//我方中场下
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbid(Environment *env)
{//对方禁区
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbidAbove(Environment *env)
{//对方禁区上
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbidBellow(Environment * env)
{//对方禁区下
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbidSmall(Environment * env)
{//对方小禁区
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbidEdgeAbove(Environment * env)
{//对方禁区边缘上
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbidEdgeBellow(Environment * env)
{//对方禁区边缘下
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackFrontAbove(Environment *env)
{//对方前场上
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackFrontBellow(Environment * env)
{//对方前场下
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackMiddle(Environment *env)
{//对方中场
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

//
/*MyGoalie 让robot守门

*/
//
void MyGoalie ( Environment *env, int robot )
{//先校正姿态，再去拦球
	Mydata * p;
	p=(Mydata *)env->userData;
	
	Vector3D go;

	double x1=10;
	double x2=17;
	double x3=20;
	double x4=25;
	double x5=45;
    double x7=76.3;
	double x10=62.0;
	double x6=61.8;
	double x8=89.7;
	double x9=84;
	
	double y1=9.5;
	double y2=26;
	double y3=31;
	double y4=51;
	double y5=56;
	double y6=73;

	double OX=	FLEFT - (GTOP - GBOT);	// 该点为球门中心 向后移动半个球门
	double OY=	(FTOP + FBOT)/2;			//球门中心	
	double ballx=p->curball.x	;
	double bally=p->curball.y	;
	double gx = p->robot[robot].pos.x ;	
	double gx_outline = FLEFT + 2.2;		//对x坐标的限定，防止离球门线太远了
	double gx_inline = FLEFT + 1.8;
	double gy = p->robot[robot].pos.y;		//跑位点,初值为当前位置
	double goalline = FLEFT + 3;
	bool   notout= true;	//不出击
	bool   standby = true;	//限制x 坐标
	bool   XX=false;	//是否旋转



	if( XX && ballx < gx + 0.5 )
	{//旋转
		if(bally < gy && bally > gy-4 )
		{
			Velocity(env,robot,-125,125);
			return ;
		}
		else if(bally > gy && bally < gy+4)
		{
			Velocity(env,robot,125,-125);
			return ;
		}
	}


	gy = OY + ( goalline - OX ) * (bally - OY)/(ballx - OX);
	
	if(notout)
	{
		if(gy > GTOP+3)
			gy = GTOP+3;
		else if(gy < GBOT-3)
			gy = GBOT-3;
	}
	go.y = gy ;

	if(standby)
	{
		if(gx > gx_outline )
			gx = gx_outline;
		else if(gx < gx_inline)
			gx = gx_inline;
	}

	go.x = gx ;
	GoaliePosition(env,robot,go,90,1.5);

	if(p->curball.x <= x1 && p->curball.y >= y2 && p->curball.y <=y3 
		&& p->ballspeed.x <= 2 && p->ballspeed.y <= 2)
	{
		go.x = p->robot[0].pos.x;
		go.y = 29;
		
		PositionAndThrough(env, robot, go);
		
		//Goalie(env, robot);
	}
	else if(p->curball.x <= x1 && p->curball.y >= y4 && p->curball.y <= y5 
			&& p->ballspeed.x <= 2 && p->ballspeed.y <= 2)
	{
		go.x = p->robot[0].pos.x;
		go.y = 54;
		
		PositionAndThrough(env, robot, go);

		//Goalie(env, robot);
	}

}
///////////////////////////////////////////////////////////////////////根据不同比赛状态采用不同的策略
//void main(Environment *env)
//{ 
//switch(env->gameState){
 //         case 0 :          
//		//	  strategyForD(env);
//			  break;             //默认
//          case FREE_BALL :  
//		//	  strategyForD(env); 
//			  break;           //争球
//        case PLACE_KICK :   //定位球 
//		//               MoonAttack ( &env->home [3],3, env );
//		//               strategyForD(env); 
//			  break;
//         case PENALTY_KICK :
//		//	 strategyForPeK(env); 
//			 break;   //点球
//         case FREE_KICK :
//		//	 strategyForD(env);
//			 break;              //任意球
//         case GOAL_KICK :                                //门球
//         //         MoonAttack ( &env->home [3],3, env );
//	     //        strategyForD(env);
//			 break;
//     }
//}
//////////////////根据球所在区域，采用不同队形，attack()定义四种进攻队形，defend()定义四种防守队形
void mm(Environment *env,int n,int w)
{Vector3D po;
int l;
int r;
po.z=90;
//这里要加写判断黄方还是蓝方if
po.x=82; //21 for blue 

if(w)//判断上方攻击还是下方 上方则w=1，下方0
{   
po.y=23;//58
l=125;
r=0;}
else
{
po.y=58;
l=0;
r=125;
}

PositionAndStopX(env,n,po,90,5);
Velocity(env,n,l,r);
}




     /* void strategyForD(Environment *env)
      {
            WIB=whereIsBall(); 	//判断球所在区域WIB
             switch(WIB){                
                 case 1 : attack(4,env); break;        //球在一号区，采用进攻队形4
                case 2 : attack(5,env); break;        //球在二号区，采用进攻队形5
                case 3 : attack(6,env); break;	      //球在三号区，采用进攻队形6
                case 4 : attack(7,env); break;        //球在四号区，采用进攻队形7
                case 5 : attack(8,env); break;        //球在五号区，采用进攻队形8
                case 6 : attack(9,env); break;        //球在六号区，采用进攻队形9
                case 7 : defend1(1,env); break;       //球在七号区，采用防守队形1
                case 8 : defend1(2,env); break;       //球在八号区，采用防守队形2
                case 9 : defend1(3,env); break;       //球在九号区，采用防守队形3
         }
    }*/
////////////////////根据不同队形，给四个机器人分配不同角色waiter(), attacker()….

//void attack(int wib,Environment *env)
//{
//      if(wib == 4){                                                       //  四号进攻队形 
//	           waiter(&env->home[1], 1, 85, 21);  
 //                                            //一号在球场右下方待命，球靠近则踢球
//	            waiter(&env->home[2], 2, 80, 64);   
//                                             //二号在球场右上方待命，球靠近则踢球
//	            attacker(&env->home[4],4);    
 //                                           //四号队员角色为进攻		
//				negativeDefender(&env->home[3], 3, 0, 43);       //三号协防
  //     }
 //     else if(wib == 5) {        //五号进攻队形	}
 //     else if(wib == 6){        //五号进攻队形  }
    //  ……
//}
//////////    4) 角色函数调用动作函数完成任务
        
//        waiter()-> go() -> rotateto() -> run();
//        attacker()->go()->rotateto()->run();
//       negativedefender()->go()->rotateto()
//     activedefender()->go()->rotateto()

	  ///////////////////////////////////
//	  int whereIsBall(); 

