#include<stdio.h>
#include<math.h>
int main(){
    printf("Rathod Pavan Kumar Naik\n");printf("BT22CSE111\n");
float angle, bforce, dforce, eforce, fab, fbc, fde, fda, fdb, fec, feb, sina, cosa,ra, rc;
printf("TRUSS IS SYMMETRIC!");printf(" d e\n");
printf(" ______\n");
printf(" d    e \n");
printf(" /\\  /\\\n");
printf("/  \\/  \\\n");
printf("--------\n");
printf("a  b   c\n");
printf("Enter force on B in kN:\n");
scanf("%f", &bforce);
printf("Enter force on D in kN:\n");
scanf("%f", &dforce);
printf("Enter force on E in kN:\n");
scanf("%f", &eforce);
printf("Enter angle at A in the trisection DAB:\n");
scanf("%f", &angle);
sina = sin(3.14*angle / 180);
cosa = cos(3.14*angle / 180);
fdb = bforce / sina;
feb = fdb;
fda = (-1)*fdb;
fec = (-1)*feb;
fda -= dforce*(sina);
fdb += dforce*(sina);
feb += eforce*(sina);
fec -= eforce*(sina);
fde = (-1)*fdb*(cosa);
fab = (-1)*fda*(cosa);
fbc = (-1)*fec*(cosa);
rc = (dforce + 2*bforce+3*eforce) / 4;
ra = dforce + eforce + bforce - rc;
printf("force b/w a&b is:%fkN\n", fab);
printf("force b/w b&c is:%fkN\n", fbc);
printf("force b/w a&d is:%fkN\n", fda);
printf("force b/w d&b is:%fkN\n", fdb);
printf("force b/w d&e is:%fkN\n", fde);
printf("force b/w e&b is:%fkN\n", feb);
printf("force b/w e&c is:%fkN\n", fec);
printf("Ra is:%fkN\n", ra);
printf("Rc is:%fkN\n", rc);
return 0;}