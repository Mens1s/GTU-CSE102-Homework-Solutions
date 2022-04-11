#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w);

char dt1a(float pl,float pw, float sl, float sw);
char dt1b(float pl,float pw, float sl, float sw);

double dt2a(float x1, float x2, float x3, int x4, int x5);
double dt2b(float x1, float x2, float x3, int x4, int x5);

int dt3a(float rate, float pRate, float demand, int fearChoice, int buyerChoice);
int dt3b(float rate, float pRate, float demand, int fearChoice, int buyerChoice);


#endif /* _UTIL_H_ */
