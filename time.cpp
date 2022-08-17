#include <iostream>
#include <graphics.h>
#include <cmath>
#include <ctime>
#define PI 3.14159265
#define Wheight 750
#define radius 300
enum clockHand{H=15,M=10, S=3};
static float counting=0;
class Proto{
public:
    Proto(){
        int length=260;
        float angle=PI/6;
        char numbers[13][3]={"3","4","5","6","7","8","9","10","11","12","1","2"};
        setcolor(LIGHTRED);
        setlinestyle(SOLID_LINE,0,10);//The linestyle parameter does not affect circles. Only the thickness parameter is used.
        circle(Wheight/2,Wheight/2,radius);
        settextstyle(SANS_SERIF_FONT,0,3);
        for(int i=0;i<13;i++){
        outtextxy(Wheight/2+int(cos(i*angle)*length), Wheight/2+int(sin(i*angle)*length),numbers[i]);
        plt(Wheight/2+int(cos(i*angle)*length), Wheight/2+int(sin(i*angle)*length));
        }
        setcolor(LIGHTRED);
        setlinestyle(SOLID_LINE,0,2);
        circle(Wheight/2,Wheight/2,210);
    }

    void plt(int x,int y){
        /*  for diamond shape
              X
             XXX
            XXXXX
             XXX
              X
        */
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
int thickness, length;
float angle;
public:
    hand(int x){
        if(x==S){
            length=200;
            thickness=S;
        }
        else if(x==M){
            length=180;
            thickness=M;
        }
        else{
            length=100;
            thickness=H;
        }
        setcolor(15);
    }
    void drawHand(float angle){
        this->angle=angle;
        setlinestyle(SOLID_LINE,0,thickness);
        line(Wheight/2, Wheight/2, Wheight/2+int(cos(angle)*length), Wheight/2+int(sin(angle)*length));
    }
};
void drawArms10times(int angle_second){//for smooth sense, time interval is 0.1 sec

}
void drawArms(float& angle_second){
    hand  second(S);
    second.drawHand(angle_second);
    setcolor(LIGHTGRAY);
    circle(Wheight/2,Wheight/2,12);
    setfillstyle(1,LIGHTGRAY);
    floodfill(Wheight/2,Wheight/2,LIGHTGRAY);
    delay(100);
    //to clear the screen
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(Wheight/2,Wheight/2,LIGHTRED);
    angle_second+=.115*(PI/30);//.1 +.015 //.1 is 10* .1 is 1 sec, but it is slowed down by 15% giving 0.015

}
int main(){
    time_t now;
    struct tm *mytime;
    initwindow(Wheight, Wheight,"Clock");
    Proto ClockProto;
    mytime = localtime(&now);
    float angle_hour=mytime->tm_hour;
    float angle_minute=mytime->tm_min;
    float angle_second= (mytime->tm_sec)*(PI/30);
    while(1){
        drawArms(angle_second);
    }
    closegraph();

}
