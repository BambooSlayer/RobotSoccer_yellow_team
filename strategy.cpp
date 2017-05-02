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
//ϵͳͨ��Environment* env���ָ�������Ǵ��ݵ�ǰ����ϵͳ�ṩ��Ϣ
{//��ɫ����
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
			if(RoleGrade[role[i]] < RoleGrade[role[j]]){     //�Ӵ�С��  ����� role ����С
				exchange = role[i];
				role[i] = role[j];
				role[j] = exchange;
			}				
		}
	}

	return role;
}

int *OppRole(Environment * env, int *opp)//���ǹ��ƶԷ�  
{
	return opp;
}


void DefendForbid(Environment * env)
{//�ҷ�����
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);


}

void DefendForbidSmall(Environment *env)
{//�ҷ�С����
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendForbidEdgeAbove(Environment *env)
{//�ҷ�������Ե��
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendForbidEdgeBellow(Environment * env)
{//�ҷ�������Ե��
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendBackAbove(Environment *env)
{//�ҷ�����
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendBackMiddle(Environment * env)
{//�ҷ�����
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendBackBellow(Environment *env)
{//�ҷ�����
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendMiddleAbove(Environment *env)
{//�ҷ��г���
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendMiddleMiddle(Environment * env)
{//�ҷ��г���
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void DefendMiddleBellow(Environment *env)
{//�ҷ��г���
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbid(Environment *env)
{//�Է�����
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbidAbove(Environment *env)
{//�Է�������
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbidBellow(Environment * env)
{//�Է�������
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbidSmall(Environment * env)
{//�Է�С����
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbidEdgeAbove(Environment * env)
{//�Է�������Ե��
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackForbidEdgeBellow(Environment * env)
{//�Է�������Ե��
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackFrontAbove(Environment *env)
{//�Է�ǰ����
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackFrontBellow(Environment * env)
{//�Է�ǰ����
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

void AttackMiddle(Environment *env)
{//�Է��г�
	Mydata * p;
	p=(Mydata *)env->userData;
	PredictBall(env,2);
}

//
/*MyGoalie ��robot����

*/
//
void MyGoalie ( Environment *env, int robot )
{//��У����̬����ȥ����
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

	double OX=	FLEFT - (GTOP - GBOT);	// �õ�Ϊ�������� ����ƶ��������
	double OY=	(FTOP + FBOT)/2;			//��������	
	double ballx=p->curball.x	;
	double bally=p->curball.y	;
	double gx = p->robot[robot].pos.x ;	
	double gx_outline = FLEFT + 2.2;		//��x������޶�����ֹ��������̫Զ��
	double gx_inline = FLEFT + 1.8;
	double gy = p->robot[robot].pos.y;		//��λ��,��ֵΪ��ǰλ��
	double goalline = FLEFT + 3;
	bool   notout= true;	//������
	bool   standby = true;	//����x ����
	bool   XX=false;	//�Ƿ���ת



	if( XX && ballx < gx + 0.5 )
	{//��ת
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
///////////////////////////////////////////////////////////////////////���ݲ�ͬ����״̬���ò�ͬ�Ĳ���
//void main(Environment *env)
//{ 
//switch(env->gameState){
 //         case 0 :          
//		//	  strategyForD(env);
//			  break;             //Ĭ��
//          case FREE_BALL :  
//		//	  strategyForD(env); 
//			  break;           //����
//        case PLACE_KICK :   //��λ�� 
//		//               MoonAttack ( &env->home [3],3, env );
//		//               strategyForD(env); 
//			  break;
//         case PENALTY_KICK :
//		//	 strategyForPeK(env); 
//			 break;   //����
//         case FREE_KICK :
//		//	 strategyForD(env);
//			 break;              //������
//         case GOAL_KICK :                                //����
//         //         MoonAttack ( &env->home [3],3, env );
//	     //        strategyForD(env);
//			 break;
//     }
//}
//////////////////�������������򣬲��ò�ͬ���Σ�attack()�������ֽ������Σ�defend()�������ַ��ض���
void mm(Environment *env,int n,int w)
{Vector3D po;
int l;
int r;
po.z=90;
//����Ҫ��д�жϻƷ���������if
po.x=82; //21 for blue 

if(w)//�ж��Ϸ����������·� �Ϸ���w=1���·�0
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
            WIB=whereIsBall(); 	//�ж�����������WIB
             switch(WIB){                
                 case 1 : attack(4,env); break;        //����һ���������ý�������4
                case 2 : attack(5,env); break;        //���ڶ����������ý�������5
                case 3 : attack(6,env); break;	      //���������������ý�������6
                case 4 : attack(7,env); break;        //�����ĺ��������ý�������7
                case 5 : attack(8,env); break;        //��������������ý�������8
                case 6 : attack(9,env); break;        //���������������ý�������9
                case 7 : defend1(1,env); break;       //�����ߺ��������÷��ض���1
                case 8 : defend1(2,env); break;       //���ڰ˺��������÷��ض���2
                case 9 : defend1(3,env); break;       //���ھź��������÷��ض���3
         }
    }*/
////////////////////���ݲ�ͬ���Σ����ĸ������˷��䲻ͬ��ɫwaiter(), attacker()��.

//void attack(int wib,Environment *env)
//{
//      if(wib == 4){                                                       //  �ĺŽ������� 
//	           waiter(&env->home[1], 1, 85, 21);  
 //                                            //һ���������·��������򿿽�������
//	            waiter(&env->home[2], 2, 80, 64);   
//                                             //�����������Ϸ��������򿿽�������
//	            attacker(&env->home[4],4);    
 //                                           //�ĺŶ�Ա��ɫΪ����		
//				negativeDefender(&env->home[3], 3, 0, 43);       //����Э��
  //     }
 //     else if(wib == 5) {        //��Ž�������	}
 //     else if(wib == 6){        //��Ž�������  }
    //  ����
//}
//////////    4) ��ɫ�������ö��������������
        
//        waiter()-> go() -> rotateto() -> run();
//        attacker()->go()->rotateto()->run();
//       negativedefender()->go()->rotateto()
//     activedefender()->go()->rotateto()

	  ///////////////////////////////////
//	  int whereIsBall(); 

