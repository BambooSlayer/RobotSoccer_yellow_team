#ifndef _STRATEGY_H_
#define _STRATEGY_H_

void MyGoalie( Environment *env, int robot );

void DefendForbid(Environment *env);
void DefendForbidSmall(Environment *env);
void DefendForbidEdgeAbove(Environment *env);
void DefendForbidEdgeBellow(Environment * env);
void DefendBackAbove(Environment *env);
void DefendBackMiddle(Environment * env);
void DefendBackBellow(Environment *env);
void DefendMiddleAbove(Environment *env);
void DefendMiddleMiddle(Environment * env);
void DefendMiddleBellow(Environment *env);
void AttackForbid(Environment *env);
void AttackForbidAbove(Environment *env);
void AttackForbidBellow(Environment * env);
void AttackForbidSmall(Environment * env);
void AttackForbidEdgeAbove(Environment * env);
void AttackForbidEdgeBellow(Environment * env);
void AttackFrontAbove(Environment *env);
void AttackFrontBellow(Environment * env);
void AttackMiddle(Environment *env);

int *Role(Environment *env, int *role);//��ɫ����
int *OppRole(Environment *env, int *opp);//�Է���Ա���ȼ�




#endif //_STRATEGY_H_