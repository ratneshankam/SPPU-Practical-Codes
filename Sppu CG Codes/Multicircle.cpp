#include<graphics.h>
int main()
{initwindow(600,600,"Circle Pattern",150,50);
for(int i=0,r=0;i<30;i++,r+=4)
{
int color;
if(i<=15)
color=i;
if(i>15)
color--;
setcolor(color);
circle(300,250-r,50+r);
// upper circle
circle(300,350+r,50+r);
// lower circle
circle(250-r,300,50+r);
// left circle
circle(350+r,300,50+r);
// right circle
delay(200);
}
getch();
closegraph();
}
