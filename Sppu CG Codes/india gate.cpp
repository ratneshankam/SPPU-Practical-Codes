// C program for the above approach
  
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
  
// Used Function Declaration
void left();
void right();
void mid();
void up();
  
void up()
{
    int u = 520;
    rectangle(500, 370, 1400, 400);
  
    // Defining A loop To Draw
    // Many Lines
    while (u <= 1400) {
        line(u, 370, u, 400);
        u = u + 20;
    }
  
    rectangle(480, 355, 1420, 370);
    line(500, 400, 480, 370);
    line(1400, 400, 1420, 370);
    rectangle(500, 355, 1400, 295);
    rectangle(520, 265, 1380, 295);
  
    // Main Rectangle To Write
    // India
    rectangle(700, 135, 1200, 265);
    circle(780, 220, 30);
    circle(1120, 220, 30);
    line(830, 190, 1070, 190);
    line(830, 190, 830, 240);
    line(830, 240, 900, 240);
    line(1070, 190, 1070, 240);
    line(1070, 240, 1000, 240);
    line(1000, 240, 1000, 250);
    line(900, 240, 900, 250);
    line(900, 250, 1000, 250);
  
    // Writing India
    settextstyle(8, 0, 4);
    outtextxy(900, 200, "INDIA");
    rectangle(800, 125, 1100, 135);
    rectangle(880, 70, 1020, 90);
    arc(880, 125, 90, 180, 35);
    arc(1020, 125, 0, 90, 35);
}
  
// Function to draw the middle part
// of the India Gate
void mid()
{
    line(700, 400, 1200, 400);
    line(700, 430, 935, 430);
    line(965, 430, 1200, 430);
    line(935, 480, 935, 430);
    line(965, 480, 965, 430);
    line(935, 480, 965, 480);
  
    // Left side arcs
    ellipse(935, 580, 90,
            180, 165, 105);
    ellipse(935, 580, 90,
            180, 185, 125);
  
    // Right Side Arcs
    ellipse(965, 580, 0,
            90, 165, 105);
    ellipse(965, 580, 0,
            90, 185, 125);
  
    // Left Side Vertical Line
    line(770, 1000, 770, 580);
  
    // Right Side Vertical Line
    line(1130, 1000, 1130, 580);
}
  
// Function to draw the left part
// of the India Gate
void left()
{
    // Left Base Rectangle
    rectangle(500, 700,
              700, 1000);
  
    // Lower Inner Rectangle
    rectangle(530, 700,
              670, 1000);
    rectangle(560, 920,
              640, 1000);
    line(500, 920, 700, 920);
    line(500, 700, 700, 700);
    line(480, 680, 770, 680);
    line(500, 700, 480, 680);
    line(700, 700, 720, 680);
  
    // Left Upper Rectangle
    rectangle(500, 400,
              700, 680);
  
    // Upper Inner Rectangle
    rectangle(530, 500,
              670, 680);
    line(530, 550, 670, 550);
    line(576, 500, 576, 550);
    line(622, 500, 622, 550);
    line(500, 580, 770, 580);
    line(530, 600, 670, 600);
    rectangle(560, 600,
              640, 630);
    circle(600, 460, 40);
    circle(600, 460, 30);
}
  
// Function to draw the right part
// of the India Gate
void right()
{
    // Right Base Rectangle
    rectangle(1200, 700,
              1400, 1000);
  
    // Lower Inner Rectangle
    rectangle(1230, 700,
              1370, 1000);
    rectangle(1260, 920,
              1340, 1000);
    line(1200, 920, 1400, 920);
    line(1200, 700, 1400, 700);
    line(1130, 680, 1420, 680);
    line(1200, 700, 1180, 680);
    line(1400, 700, 1420, 680);
  
    // Right Upper Ractangle
    rectangle(1200, 400,
              1400, 680);
  
    // Upper Inner Rectangle
    rectangle(1230, 500,
              1370, 680);
    line(1230, 550, 1370, 550);
    line(1276, 500, 1276, 550);
    line(1322, 500, 1322, 550);
    line(1130, 580, 1400, 580);
    line(1230, 600, 1370, 600);
    rectangle(1260, 600,
              1340, 630);
    circle(1300, 460, 40);
    circle(1300, 460, 30);
}
  
// Driver Code
int main()
{
    int height = GetSystemMetrics(SM_CYSCREEN);
	int width = GetSystemMetrics(SM_CXSCREEN);
		
		initwindow(width, height, "");
  
    // Base Line
    line(200, 1000, 2000, 1000);
  
    // Function Call
    left();
  
    // Function Call
    right();
  
    // Function Call
    mid();
  
    // Function Call
    up();
  
    // Holding The Screen For A While
    getch();
  
    // Close the initialized gdriver
    closegraph();
}
