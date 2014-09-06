/*基本：键盘弹奏   鼠标设定音调音色节奏等==  可自动播放曲子,输入歌曲简谱，自动播放*/
#include "stdio.h"
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <graphics.h>
#include <bios.h>
#define stage=8100
/*设置偏移量*/
#define OFFSET 20
#define OFFSET_x 4
#define OFFSET_y 3
#define N 16
int frq[3][7]={262,294,330,349,392,440,494,524,587,659,698,784,880,988,1024,1174,1318,1396,1568,1760,1976};
int mx,my,x,y,step=16;
int i=0,j=0;
char key=0;
int yun,preyun;
/*定义全局变量*/
int status[N][N]; /*定义的数组，保存状态*/
int step_x,step_y;/*行走的坐标*/
int wzq;
int   MouseX; 
int   MouseY; /*全局变量（MouseX,MouseY）为鼠标顶尖点坐标*/
/*up[16][16]与down[16][16]两数组为中间变量。mouse_draw[16][16]描述鼠标的各点像素。pixel_save[16][16]为记录下被鼠标遮挡部分的像素*/

FILE *hzk;
void open_hzk(void);
void get_hz(char incode[],char bytes[]);
void dishz(int x,int y,char cade[],int color);
void draw_button(void);

void beginning()
{ 
   int driver=DETECT,mode;
   initgraph(&driver,&mode,"");
   setcolor(6);
   settextstyle(1,0,2); 
   outtextxy(x+100,y+40,"Welcome to my");
   setcolor(4);
   settextstyle(1,0,0);
   outtextxy(x+100,y+100,"COMPUTER PIANO");
   setcolor(3);
   settextstyle(1,0,3);
   outtextxy(x+100,y+130,"Press anykey to continue...");
   getch();
   cleardevice();
   }

void disp_piano()
{ 
   
   int i,j;
   
   x=mx-(21*step)/2;
   y=my-20;
   setcolor(3);
   rectangle(x,y,x+21*step+1,y+100);
   rectangle(x-1,y-1,x+21*step+2,y+101);
   setcolor(15);
   rectangle(x+2,y+50,x+21*step-1,y+98);
   setfillstyle(1,15);
   floodfill(x+10,y+60,15);
   setcolor(0);
   for(i=x+step;i<x+21*step;i+=step)
      line(i,y+50,i,y+99);
   setcolor(3);
   rectangle(x-40,y-20,x+21*step+40,y+130);
   rectangle(x-41,y-21,x+21*step+41,y+131);
   rectangle(x-41,y-25,x+21*step+41,y-24);
   rectangle(x-41,y-22,x-40,y-53);
   rectangle(x+21*step+40,y-22,x+21*step+41,y-53);
   rectangle(x-1,y-93,x+21*step+1,y-92);
   arc(x-1,y-53,90,180,40);
   arc(x-1,y-53,90,180,39);
   arc(x+21*step+1,y-53,0,90,40);
   arc(x+21*step+1,y-53,0,90,39);
   rectangle(x+43,y-80,x+21*step-43,y-35);
   for(i=x+49;i<x+21*step-48;i+=12)
   { 
      setfillstyle(1,3);
      bar(i,y-75,i+9,y-40);
      j=random(24);
      setfillstyle(2,11);
      bar(i,y-75+j,i+9,y-65+j);
   }
   rectangle(x-32,y-50,x+33,y-40);
   setfillstyle(1,1);
   floodfill(x-30,y-10,3);
   setfillstyle(10,3);
   floodfill(x-39,y-27,3);
   setcolor(11);
   circle(x+21*step-5,y-70,6);
   circle(x+21*step-5,y-45,6);
   setfillstyle(1,4);
   floodfill(x+21*step-5,y-70,11);
   floodfill(x+21*step-5,y-45,11);
   outtextxy(x-30,y-65,"VOLUME");
   setcolor(3);
   outtextxy(x+110,y+112,"COMPUTER PIANO");
   setcolor(10);
   settextstyle(2,0,5);
   outtextxy(x-15,y+140,"Help:Esc to quit.");
   }

void press_line(int i,int j,int color1,int color2)
{ 
   int dt;
   dt=(i*7+j)*step;
   setcolor(color1);
   if((i!=0)||(j!=0))
      line(x+1+dt,y+50,x+1+dt,y+98);
   line(x+2+dt,y+50,x+2+dt,y+98);
   line(x+dt+step-1,y+50,x+dt+step-1,y+98);
   line(x+dt+step-2,y+50,x+dt+step-2,y+98);
   setcolor(color2);
   line(x+3+dt,y+18,x+3+dt,y+49);
   line(x+4+dt,y+18,x+4+dt,y+49);
}
void   MouseMath()/*为mouse_draw[16][16]赋值，储存鼠标样子*/ 
{int  i,j,jj,k; 
long  UpNum[16]={ 
              0x3fff,0x1fff,0x0fff,0x07ff, 
              0x03ff,0x01ff,0x00ff,0x007f, 
              0x003f,0x00ff,0x01ff,0x10ff, 
              0x30ff,0xf87f,0xf87f,0xfc3f 
              }; 
long  DownNum[16]={ 
              0x0000,0x7c00,0x6000,0x7000, 
              0x7800,0x7c00,0x7e00,0x7f00, 
              0x7f80,0x7e00,0x7c00,0x4600, 
              0x0600,0x0300,0x0300,0x0180 
            }; 
for(i=0;i<16;i++) 
      { 
      j=jj=15; 
        while(UpNum[i]!=0) 
        { 
        up[i][j]=UpNum[i]%2; 
        j--; 
        UpNum[i]/=2; 
        } 
         while(DownNum[i]!=0) 
        { 
        down[i][jj--]=DownNum[i]%2; 
        DownNum[i]/=2; 
        } 
for(k=j;k>=0;k--) 
      up[i][k]=0; 
for(k=jj;k>=0;k--) 
      down[i][k]=0; 
for(k=0;k <16;k++)/*四种组合方式*/ 
      { 
      if(up[i][k]==0&&down[i][k]==0) 
        mouse_draw[i][k]=0; 
      else   if(up[i][k]==0&&down[i][k]==1) 
        mouse_draw[i][k]=15; 
      else   if(up[i][k]==1&&down[i][k]==0) 
        mouse_draw[i][k]=3; 
      else 
        mouse_draw[i][k]=3; 
    } 
  } 
mouse_draw[1][2]=4;/*特殊点*/ 
} 
/*鼠标光标显示。其作用有两个。1.记录被以（x，y）为顶点的鼠标遮挡下的像素；2.以（x，y）为顶点画鼠标*/ 
void   MouseOn(int   x,int   y) 
{ 
int   i,j; 
int   color; 
for(i=0;i<16;i++)/*画鼠标*/ 
    { 
      for(j=0;j<16;j++) 
        { 
        pixel_save[i][j]=getpixel(x+j,y+i);/*保存原来的颜色*/ 
         if(mouse_draw[i][j]==0||mouse_draw[i][j]==15) 
        putpixel(x+j,y+i,mouse_draw[i][j]); 
 
        } 
    } 
} 
/*将鼠标用原像素遮盖达到隐藏鼠标且不改变背景目的*/ 
void MouseOff() 
{ 
int i,j,x,y,color; 
  x=MouseX; 
  y=MouseY; 
  for(i=0;i <16;i++)/*原位置异或消去*/ 
    for(j=0;j <16;j++) 
      { 
        if(mouse_draw[i][j]==0||mouse_draw[i][j]==15) /*如果是鼠标边界点或内部点即黑色或白色*/
         {
        color=getpixel(x+j,y+i); 
        putpixel(x+j,y+i,color^color); 
        putpixel(x+j,y+i,pixel_save[i][j]); 
         } 
      }
} 
void   MouseSetXY(int   x,int   y) /**_AX_CX_DX为入口参数m1,m2,m3，m1取4，m3，m4取横纵坐标时，设置光标位置*/
    { 
      _CX=x; 
      _DX=y; 
      _AX=0x04;
      geninterrupt(0x33); /*采用 int 33H中断*/
    } 

/*判断是否左击，左击返回非0，不左击返回0*/
int   LeftPress() /*_AX为入口参数m1，m1取3时，获取按钮状态和鼠标位置出口参数_BX为鼠标状态*/
    { 
      _AX=0x03; /*_AX为入口参数m1，m1取3时，获取按钮状态和鼠标位置*/
      geninterrupt(0x33);
      return(_BX&1); /*掩码位为1时获取*/

    } 

/*获取鼠标当前位置*/ 
void   MouseGetXY() 
    { 
      _AX=0x03; /**_AX为入口参数m1，m1取3时获取按钮状态和鼠标位置*/
      geninterrupt(0x33); 
      MouseX=_CX; 
      MouseY=_DX; 
    } 

int   MouseStatus()/*鼠标按键情况*/ 
{ 
  int   x,y; 
  int   status; 
  int   press=0; 
  int   i,j,color; 
  status=0;/*默认鼠标没又移动*/ 

  x=MouseX; 
  y=MouseY; 

  while(x==MouseX&&y==MouseY&&status==0&&press==0) 
  { 
  
if(LeftPress()) 
    press=1; 
  MouseGetXY(); 
  if(MouseX!=x||MouseY!=y) 
    status=1; 
  } 
  if(status)/*移动情况才重新显示鼠标*/ 
  { 
for(i=0;i <16;i++)/*原位置异或消去*/ 
    for(j=0;j <16;j++) 
      { 
        if(mouse_draw[i][j]==0||mouse_draw[i][j]==15) /*如果是鼠标边界点或内部点即黑色或白色*/
         {
        color=getpixel(x+j,y+i); 
        putpixel(x+j,y+i,color^color); 
        putpixel(x+j,y+i,pixel_save[i][j]); 
         } 
      }
  MouseOn(MouseX,MouseY);/*新位置显示*/ 
  } 
  if(press!=0)/*有按键得情况*/ 
    return   press; 
  return   0;/*只移动得情况*/ 
} 

void set_volume(int i,int j,int color)
{ 
   int t,s;
   s=i*7+j+1;
   setcolor(color);
   for(t=0;t<s;t++)
      rectangle(x-32+t*3,y-48,x-29+t*3,y-42);
}

void main()
{ 
   int x[10];
   int y[10];
   int i;
int   driver,mode,i,j,t,k,HA
   char *s[10];
   int driver=VGA;
   int mode=VGAHI;
    nosound();
   mx=320;
   my=240;
driver=VGA;mode=VGAHI;
initgraph(&driver,&mode, "e:\\tc");
MouseMath();/*计算鼠标位置给全局变量mouse_draw[16][16]赋值*/
MouseSetXY(100,100);/*将（100，100）赋值给鼠标的横纵坐标*/
HA=1;
MouseOn(MouseX,MouseY);/*第一次显示鼠标*/

   beginning();

   initgraph(&driver,&mode,"");
   disp_piano();


   s[1]="趣味键盘琴";
   s[2]="退出";
   s[3]="播放内置歌曲"
   s[4]="歌曲一";
   s[5]="歌曲二";
   s[6]="歌曲三";
   x[1]=280;y[1]=40;
   x[2]=550;y[2]=440;
   x[3]=50;y[3]=440;
   x[4]=190;y[4]=440;
   x[5]=270;y[5]=440;
   x[6]=350;y[6]=440;
   
   draw_button();
   open_hzk();
   for(i=1;i<=6;i++)
   {
      while(*s[i]!=NULL)
      {
	 dishz(x[i],y[i],s[i],RED);
	 x[i]+=20;
         s[i]+=2;
      }
   }
   getch();
   fclose(hzk);


   while(key!=27)
   { 
      yun=0;
      key=getch(); 
      if(i<3&&j<7)
      { 
         nosound();
         press_line(i,j,15,0);
         set_volume(i,j,0);
      }
      switch(key)
      { 
         case 122:i=0;j=0;break;
         case 120:i=0;j=1;break;
         case 99:i=0;j=2;break;   
         case 118:i=0;j=3;break;
         case 98:i=0;j=4;break;
         case 110:i=0;j=5;break;
         case 109:i=0;j=6;break;
         case 97:i=1;j=0;break;
      
case 115:
	i=1;
	j=1;
	break;
     
case 100:
	i=1;
	j=2;
	break;
      
case 102:
	i=1;
	j=3;
	break;
      
case 103:
	i=1;
	j=4;
	break;
     
case 104:
	i=1;
	j=5;
	break;
      
case 106:
	i=1;
	j=6;
	break;
      
case 113:
	i=2;
	j=0;
	break;
      
case 119:
	i=2;
	j=1;
	break;
      
case 101:
	i=2;
	j=2;
	break;
      
case 114:
	i=2;
	j=3;
	break;
      
case 116:
	i=2;
	j=4;
	break;
      
case 121:
	i=2;
	j=5;
	break;
      
case 117:
	i=2;
	j=6;
	break;
      }

if(i<3&&j<7)

{
   sound(frq[i][j]);
   delay(100000000);
   nosound();
}
if(key<97||key>122) nosound();

if((yun||key!='0')&&(yun!=-1)&&(i<3&&j<7))

{press_line(i,j,0,15);
	 set_volume(i,j,10);}
  }

}

void open_hzk()
{
   hzk=fopen("hzk16","rb");
   if(!hzk)
   {
      printf("the file HZK16 not eist!\n");
      getch();
      closegraph();
      exit(1);
   }
}

void get_hz(char incode[],char bytes[])
{
   unsigned char qh,wh;
   unsigned long offset;
   qh=incode[0]-0xa0;
   wh=incode[1]-0xa0;
   offset=(94*(qh-1)+(wh-1))*32L;
   fseek(hzk,offset,SEEK_SET);
   fread(bytes,32,1,hzk);
}

void dishz(int x0,int y0,char code[],int color)
{
   unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

   int i,j,x,y,pos;
   char mat[32];
   get_hz(code,mat);
   y=y0;
   for(i=0;i<16;i++)
   {
      x=x0;
      pos=2*i;
      for(j=0;j<16;j++)
      {
	 if((mask[j%8]&mat[pos+j/8])!=NULL)
	    putpixel(x,y,color);
	 ++x;
      }
      ++y;
   }
}

void draw_button(void)
{
   int i;
   int x0;
   setcolor(YELLOW);
   setfillstyle(1,YELLOW);
   x0=287;
   for(i=0;i<5;i++)
   {
      fillellipse(x0+i*20,47,10,12);
      floodfill(x0+i*20,47,YELLOW);
   }

   setcolor(BROWN);
   setfillstyle(1,BROWN);
   rectangle(540,430,595,465);/*退出键范围*/
   floodfill(541,431,BROWN);
   rectangle(40,430,175,465);
   floodfill(41,431,BROWN);

   setcolor(YELLOW);
   setfillstyle(1,YELLOW);
   x0=180;
   for(i=0;i<3;i++)
   {
      rectangle(x0+i*75,430,x0+(i+1)*75,465);
/*歌曲一~三
(180,430,255,465)
(260,430,335,465)
(340,430,415,465)*/
      floodfill(x0+i*75+1,431,YELLOW);
      x0+=5;
   }
}
void nosound(); 
void far closegraph();