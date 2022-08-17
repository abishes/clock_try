#include <iostream>
#include <graphics.h>
#include <cmath>
#include <ctime>
#define PI 3.14159265
#define Wheight 750
#define radius 300
enum clockHand{H=15,M=10, S=3};
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
        circle(Wheight/2,Wheight/2,200);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(Wheight/2,Wheight/2,LIGHTRED);
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
    ~hand(){
        setcolor(BLACK);
        setlinestyle(SOLID_LINE,0,thickness);
        line(Wheight/2, Wheight/2, Wheight/2+int(cos(angle)*length), Wheight/2+int(sin(angle)*length));
    }
};
void drawArms(){
    hand hour(H), minute(M), second(S);
    hour.drawHand(0.3f);
    minute.drawHand(1.2f);
    second.drawHand(2.0f);
    setcolor(LIGHTGRAY);
    circle(Wheight/2,Wheight/2,12);
    setfillstyle(1,LIGHTGRAY);
    floodfill(Wheight/2,Wheight/2,LIGHTGRAY);
    delay(2000);
    //to clear the screen
    setcolor(LIGHTRED);
    setlinestyle(SOLID_LINE,0,2);
    circle(Wheight/2,Wheight/2,200);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(Wheight/2,Wheight/2,LIGHTRED);
}
int main(){
    initwindow(Wheight, Wheight,"Clock");
    Proto ClockProto;
    drawArms();
    getch();
    closegraph();

}
