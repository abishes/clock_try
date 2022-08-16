#include <iostream>
#include <graphics.h>
#include <cmath>
#include <ctime>
#define PI 3.14159265
#define Wheight 750
#define radius 300
enum clockHand{H=15,M=10, S=5};
class Proto{
public:
    Proto(){
        int length=260;
        float angle=PI/6;
        char numbers[13][3]={"3","4","5","6","7","8","9","10","11","12","1","2"};
        setcolor(12);
        setlinestyle(SOLID_LINE,0,10);//The linestyle parameter does not affect circles. Only the thickness parameter is used.
        circle(Wheight/2,Wheight/2,radius);
        settextstyle(SANS_SERIF_FONT,0,3);
        for(int i=0;i<13;i++){
        outtextxy(Wheight/2+int(cos(i*angle)*length), Wheight/2+int(sin(i*angle)*length),numbers[i]);
        plt(Wheight/2+int(cos(i*angle)*length), Wheight/2+int(sin(i*angle)*length));
        }
    }
    void plt(int x,int y){
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
               putpixel(x+i,y+j,15);
            }
        }
        putpixel(x,y-2,15);
        putpixel(x,y+2,15);
        putpixel(x-2,y,15);
        putpixel(x+2,y,15);

    }
};
class hand{
float thickness, length;
public:
    hand(){
        length=200;
        setcolor(15);
        setlinestyle(SOLID_LINE,0,S);
        line(Wheight/2,Wheight/2,Wheight/2+150,Wheight/2+150);
    }
};
int main(){
    initwindow(Wheight, Wheight,(char*)"Clock");
    Proto ClockProto;
    hand hrs;
    getch();
    closegraph();

}
