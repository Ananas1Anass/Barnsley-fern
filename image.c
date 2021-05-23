#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bitmaplib.h"



int main (){
color black;
black.green = 0;
black.red =  0;
black.blue = 0;
picture fig1=new_pic(900,1600);
double condition1=1;
fougere(fig1,10,424,1500,0,1,black,condition1);
save_pic(fig1,"fern1.ppm");
picture fig2=new_pic(900,1600);
double condition2=2;
fougere(fig2,10,424,1500,0,1,black,condition2);
save_pic(fig2,"fern2.ppm");
picture fig3=new_pic(900,1600);
double condition3=3;
fougere(fig3,10,424,1500,0,1,black,condition3);
save_pic(fig3,"fern3.ppm");
picture fig4=new_pic(900,1600);
double condition4=4;
fougere(fig4,10,424,1500,0,1,black,condition4);
save_pic(fig4,"fern4.ppm");
}