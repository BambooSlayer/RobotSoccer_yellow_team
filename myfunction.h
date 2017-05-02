#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

bool Shoot1(Environment *env,int robot);
void WeightestKick(Environment * env,int robot,Vector3D pos);///ѡ��Ȩֵ����ȥ����

void Kick2(Environment *env,int robot,Vector3D pos);//�����з��ߵ���λ������ֻ���ǵĻ����������ߵ����
void Kick0(Environment * env, int robot, Vector3D Topos=CONSTGATE);////����ı��������Kick

int GetValueDistance(double dis);
int GetValueAngle(double dis);
int GetValuePosition(double x,double ball);
int WhoKick(Environment *env);

void Position1(Environment *env,int robot,Vector3D pos,double limit);
void NewtonPosition(Environment *env,int robot,Vector3D pos[],int n,double limit,bool frontad);///����newton��ֵ����λ����
void Position3(Environment *env,int robot,Vector3D pos,double limit);///�����˹��Ƴ�����λ���������Դﵽ���ϵ�Ч�������Ǻܲ�����

void PositionAndAngle(Environment *env,int robot);
void PositionAndAngle1(Environment *env,int robot);
void PositionAndAngle2(Environment *env,int robot);
void PositionAndAngle3(Environment *env,int robot);

Vector3D MeetBall(Environment *env,int robot);////���׷��������λ��

void PushOpp(Environment *env ,int robot, Vector3D OppPos ,Vector3D ToPosition);
void PushRobot(Environment *env ,int robot, Vector3D RobotPos ,Vector3D ToPosition);

bool PositionAndHeadoff(Environment *env,int robot,double X);///robot���ں�����X����λ׼��������

bool PositionAndHeadoff1(Environment *env,int robot,Vector3D pos1,Vector3D pos2);
int CheckNearestOpp(Environment *env,Vector3D go);//ѡ�������go������ĶԷ�������

int CheckMySmallForbidOpp(Environment *env);//�ҷ�С������Է������˵���Ŀ
int CheckMySmallForbidRobot(Environment *env);//�ҷ�С�������ҷ������˵���Ŀ
int CheckMyForbidOpp(Environment *env);//�ҷ��������Է������˵���Ŀ
int CheckMyForbidRobot(Environment *env);//�ҷ���������ҷ������˵���Ŀ

void SortMax(int *robot,double *weight,int n);//����Ȩֵweight��С�����˳������robot
void SortMin(int *robot,double *weight,int n);//����Ȩֵweight�Ӵ�С��˳������robot
int SortDangerousOpp(Environment * env, int * dangerousopp);//����Σ�������ڡ��Է������˵���Ŀ�����Ұ��������ľ����С��������
int SortDangerousOpp2(Environment * env, int * dangerousopp,int robot);
void SortRobotX(Environment *env,int *role,int n);//��n�������˰���X���������˳������
void SortRobotY(Environment *env,int *role,int n);//��n�������˰���X���������˳������

bool IsDangerousOpp(Environment *env, int opp);//�ж϶Է�opp�ǲ���Σ����Ա
bool PushDangerousOpp(Environment *env,int robot);

void AngOppToBall(Environment * env, int * opp);//�Է��������������߼н������С����
void AngRobotToBall(Environment * env, int * robot);//�ҷ��������߼н������С����
void DisRobotToOpp(Environment * env, int * robot, int opp);//�ҷ������˵�opp�����С����
void DisOppToRobot(Environment * env, int *opp, int robot);//�Է������˾�robot�����С��������
void DisOppToBall(Environment * env, int * opp);//�Է������˾�������С����
void DisRobotToBall(Environment * env, int * robot);//�ҷ������˾�������С����

bool IsInSmallForbidRobot(Environment *env, int robot);//�ж�robot�Ƿ����ҷ�С����
bool IsInSmallForbidOpp(Environment * env, int opp);//�ж�opp�Ƿ����ҷ�С������
bool IsInForbidRobot(Environment *env, int robot);

void GoAndBack1(Environment *env,int robot,Vector3D pos1,Vector3D pos2,double limit1=3,double limit2=3);
void GoAndBackAbove2(Environment *env,int robot1,int robot2,Vector3D pos1,Vector3D pos2,double limit1=3,double limit2=3);
void GoAndBackBelow2(Environment *env,int robot1,int robot2,Vector3D pos1,Vector3D pos2,double limit1,double limit2);
void GoAndBack3(Environment *env,int robot1,int robot2,int robot3,Vector3D pos1,Vector3D pos2,double limit1,double limit2);
//����������������֮�������˶�

bool AssistantGoalie(Environment *env,int robot,double radius=13);//��Բ��������

void GoByPos(Environment *env,int robot,Vector3D pos,Vector3D des,double precision);

///////////////////////////////////////////////////////////////////
bool PushTopRobot(Environment *env,int robot);///һЩ��·����ĺ���
bool PushBotRobot(Environment *env,int robot);
bool PushRightAbove(Environment *env,int robot);
bool PushRightBelow(Environment *env,int robot);
void PushLeftAbove(Environment *env,int robot);
void PushLeftBelow(Environment *env,int robot);
bool PushRightBelowCorner(Environment *env,int robot);
bool PushRightAboveCorner(Environment *env,int robot);
bool PushLeftBelowCorner(Environment *env,int robot);
bool PushLeftAboveCorner(Environment *env,int robot);
//////////////////////////////////////////////////////////
int CheckOppGoalkeeper(Environment *env);//�ж϶Է�����Ա
/*bool IsInArea(Environment *env,int robot,Area area);///�����ǲ���area������

int SortAreaRobotX(Environment *env,int *robot,Area area,int *role);//������area��Ļ����˰���X��������ķ�ʽ������,���������role�з������������Ļ�������Ŀ
int SortAreaRobotY(Environment *env,int *robot,Area area,int *role);//������area��Ļ����˰���X��������ķ�ʽ������,���������role�з������������Ļ�������Ŀ
*/
void PositionAndX(Environment *env,int  robot) ;
bool IsTouchOppGoalkeeper(Environment *env);

void RollWhenStuck(Environment *env);
void Kick11(Environment *env,int robot,Vector3D ToPos);
void GoBack(Environment *env,int robot);
#endif

void JG(Environment *env,int m);