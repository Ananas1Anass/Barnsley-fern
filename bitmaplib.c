#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bitmaplib.h"

#define PI 3.14159

int i;
picture new_pic(int height,int width){
    int *pixels=malloc(3*height*width*4);
    picture image;
    image.height=height;
    image.width=width;
    for(int i=0;i<3*height*width;i++){
        *(pixels+i)=255;
    }
    image.pixels=pixels;
    return image;
}

void set_pixel(picture pic,int x, int y, color couleur){
*(pic.pixels+3*(y)*pic.width+3*x)=couleur.red;
*(pic.pixels+3*(y)*pic.width+3*x+1)=couleur.green;
*(pic.pixels+3*(y)*pic.width+3*x+2)=couleur.blue;
}
void save_pic(picture pic,char* nom_fichier){

FILE* f=fopen(nom_fichier,"w");
int n=3*pic.height*pic.width;
int buffer[100];
fputs("P3\n1600 900\n255\n",f);
for(i=0;i<n-3;i+=3){
   sprintf(buffer,"%d %d %d\n",*(pic.pixels+i),*(pic.pixels+i+1),*(pic.pixels+i+2));
   fputs(buffer,f);
 }
	fclose(f);
}
void draw_line(picture pic, int x1, int y1, int x2, int y2, color couleur){
    int n;
    if (abs(x2-x1)>abs(y2-y1)){
        n=abs(x2-x1);
    } else{
        n=abs(y2-y1);
    }
    int x;
    int y;
    if (n!=0){
        for (int k=0;k<n+1;k++){
            x=(x2-x1)*k/n+x1;
            y=(y2-y1)*k/n+y1;
            set_pixel(pic,x,y,couleur);
        }
    }
}


void fougere(picture fig,double x,double y,double OH,double theta,int n,color couleur,double condition){
 if(OH<condition){

 }
else{
  if(n==1){
draw_line(fig,x,y,OH*0.16*cos(theta)+x,-OH*0.16*sin(theta)+y,couleur);
}
else{
draw_line(fig,x,y,OH*0.16*cos(theta)+x,-OH*0.16*sin(theta)+y,couleur);
}

fougere(fig,OH*0.16*cos(theta)+x,-OH*0.16*sin(theta)+y,OH*0.86,theta-n*0.05,n,couleur,condition);
fougere(fig,OH*0.12*cos(theta)+x,-OH*0.12*sin(theta)+y,OH*0.27,theta+n*PI*0.5,n,couleur,condition);
fougere(fig,OH*0.08*cos(theta)+x,-OH*0.08*sin(theta)+y,OH*0.3,theta-n*PI*0.5,-n,couleur,condition);

}
}
