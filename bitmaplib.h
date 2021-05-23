#ifndef BITMAPLIB_H
#define BITMAPLIB_H

typedef struct picture{
    int height,width;
    int* pixels;
}picture;

typedef struct{
  char red;
  char green;
  char blue;
}color;

picture new_pic(int height,int width);
void set_pixel(picture pic,int x, int y, color couleur);
void save_pic(picture pic,char* nom_fichier);
void draw_line(picture pic, int x1, int y1, int x2, int y2, color couleur);
void fougere(picture fig,double x,double y,double OH,double theta,int n,color couleur,double condition);
#endif
