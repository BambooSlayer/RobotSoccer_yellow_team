#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

bool Shoot1(Environment *env,int robot);
void WeightestKick(Environment * env,int robot,Vector3D pos);///选择权值最大的去踢球

void Kick2(Environment *env,int robot,Vector3D pos);//基于中分线的跑位函数，只考虑的机器人在球后边的情况
void Kick0(Environment * env, int robot, Vector3D Topos=CONSTGATE);////处理的边线死球的Kick

int GetValueDistance(double dis);
int GetValueAngle(double dis);
int GetValuePosition(double x,double ball);
int WhoKick(Environment *env);

void Position1(Environment *env,int robot,Vector3D pos,double limit);
void NewtonPosition(Environment *env,int robot,Vector3D pos[],int n,double limit,bool frontad);///基于newton差值的跑位函数
void Position3(Environment *env,int robot,Vector3D pos,double limit);///基于人工势场的跑位函数，可以达到壁障的效果，但是很不理想

void PositionAndAngle(Environment *env,int robot);
void PositionAndAngle1(Environment *env,int robot);
void PositionAndAngle2(Environment *env,int robot);
void PositionAndAngle3(Environment *env,int robot);

Vector3D MeetBall(Environment *env,int robot);////求出追到球的最佳位置

void PushOpp(Environment *env ,int robot, Vector3D OppPos ,Vector3D ToPosition);
void PushRobot(Environment *env ,int robot, Vector3D RobotPos ,Vector3D ToPosition);

bool PositionAndHeadoff(Environment *env,int robot,double X);///robot以在横坐标X上跑位准备拦截球

bool PositionAndHeadoff1(Environment *env,int robot,Vector3D pos1,Vector3D pos2);
int CheckNearestOpp(Environment *env,Vector3D go);//选择距离球go点最近的对方机器人

int CheckMySmallForbidOpp(Environment *env);//我方小禁区里对方机器人的数目
int CheckMySmallForbidRobot(Environment *env);//我方小禁区里我方机器人的数目
int CheckMyForbidOpp(Environment *env);//我方大禁区里对方机器人的数目
int CheckMyForbidRobot(Environment *env);//我方大禁区里我方机器人的数目

void SortMax(int *robot,double *weight,int n);//按照权值weight从小到大的顺序排列robot
void SortMin(int *robot,double *weight,int n);//按照权值weight从大到小的顺序排列robot
int SortDangerousOpp(Environment * env, int * dangerousopp);//返回危险区域内。对方机器人的数目。并且按照其距球的距离从小到达排序
int SortDangerousOpp2(Environment * env, int * dangerousopp,int robot);
void SortRobotX(Environment *env,int *role,int n);//将n个机器人按照X坐标递增的顺序排列
void SortRobotY(Environment *env,int *role,int n);//将n个机器人按照X坐标递增的顺序排列

bool IsDangerousOpp(Environment *env, int opp);//判断对方opp是不是危险球员
bool PushDangerousOpp(Environment *env,int robot);

void AngOppToBall(Environment * env, int * opp);//对方机器人与球连线夹角排序从小到大
void AngRobotToBall(Environment * env, int * robot);//我方与球连线夹角排序从小到大
void DisRobotToOpp(Environment * env, int * robot, int opp);//我方机器人到opp距离从小到大
void DisOppToRobot(Environment * env, int *opp, int robot);//对方机器人距robot距离从小到大排列
void DisOppToBall(Environment * env, int * opp);//对方机器人距球距离从小到大
void DisRobotToBall(Environment * env, int * robot);//我方机器人距球距离从小到大

bool IsInSmallForbidRobot(Environment *env, int robot);//判断robot是否在我方小禁区
bool IsInSmallForbidOpp(Environment * env, int opp);//判断opp是否在我方小禁区内
bool IsInForbidRobot(Environment *env, int robot);

void GoAndBack1(Environment *env,int robot,Vector3D pos1,Vector3D pos2,double limit1=3,double limit2=3);
void GoAndBackAbove2(Environment *env,int robot1,int robot2,Vector3D pos1,Vector3D pos2,double limit1=3,double limit2=3);
void GoAndBackBelow2(Environment *env,int robot1,int robot2,Vector3D pos1,Vector3D pos2,double limit1,double limit2);
void GoAndBack3(Environment *env,int robot1,int robot2,int robot3,Vector3D pos1,Vector3D pos2,double limit1,double limit2);
//三个机器人在两点之间来回运动

bool AssistantGoalie(Environment *env,int robot,double radius=13);//半圆辅助防守

void GoByPos(Environment *env,int robot,Vector3D pos,Vector3D des,double precision);

///////////////////////////////////////////////////////////////////
bool PushTopRobot(Environment *env,int robot);///一些边路挤球的函数
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
int CheckOppGoalkeeper(Environment *env);//判断对方守门员
/*bool IsInArea(Environment *env,int robot,Area area);///机器是不在area区域内

int SortAreaRobotX(Environment *env,int *robot,Area area,int *role);//将区域area里的机器人按照X坐标递增的方式的排序,结果保存在role中返回满足条件的机器人数目
int SortAreaRobotY(Environment *env,int *robot,Area area,int *role);//将区域area里的机器人按照X坐标递增的方式的排序,结果保存在role中返回满足条件的机器人数目
*/
void PositionAndX(Environment *env,int  robot) ;
bool IsTouchOppGoalkeeper(Environment *env);

void RollWhenStuck(Environment *env);
void Kick11(Environment *env,int robot,Vector3D ToPos);
void GoBack(Environment *env,int robot);
#endif

void JG(Environment *env,int m);