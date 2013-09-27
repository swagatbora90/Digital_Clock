#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
using namespace std;



//user code for clrscrn command

void clrscr()  
 {  
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // gets the window handle  
  COORD coord = {0, 0};                              // sets coordinates to 0,0  
  DWORD count;  
  CONSOLE_SCREEN_BUFFER_INFO csbi;  
  GetConsoleScreenBufferInfo(hStdOut, &csbi);       // gets the buffer info (screen)  

 // fill all characters as ' ' (empty the screen)  
 FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);  

 // resets the cursor position  
SetConsoleCursorPosition(hStdOut, coord);  
 }  


 void gotoxy (int x, int y)  
 {  
    COORD coord; // coordinates  
    coord.X = x; coord.Y = y; // X and Y coordinates  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
  } 



 int main()
 {
 int hh,mm,ss;
 hh=mm=ss=0;
 gotoxy(5,5);
 printf("YOUR TIME STARTS NOW: ");
 gotoxy(5,10);
 printf("HH : MM : SS");
 //_setcursortype(_NOCURSOR);
 for(;;ss++) //An infinite loop
 {
  if(ss==60)
  {
    mm++;
    ss=0;
  }

  if(mm==60)
  {
    hh++;
    mm=0;
  }

  gotoxy(5,12);
  Sleep(1000);
  printf("%02d : %02d : %02d",hh,mm,ss);
  if(kbhit())
	  break;

 }  
 return 0;
}
