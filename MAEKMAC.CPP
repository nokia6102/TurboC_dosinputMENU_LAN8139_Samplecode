#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <process.h>

#define template 8139.cfg
#define writefile 38D8100.cfg

char all_1[12];
char all_eeprom[5000];
main()
{
 int i,j,x,y,loop=0,loop1,string_number;
 char ch;
 FILE *fp,*fp1;

 window(1,7,80,10);
 for(i=0;i<78;i++)
 {  gotoxy(i+1,1); printf("ÍÍ"); gotoxy(i+1,4); printf("ÍÍ");  }
 for(i=0;i<4;i++)
 {  gotoxy(1,i+1); printf("º"); gotoxy(80,i+1);  printf("º");  }

 gotoxy(1,1);  printf("ÉÍ");  gotoxy(79,1);  printf("Í»");
 gotoxy(1,4); printf("ÈÍ");  gotoxy(79,4); printf("Í¼");
 window(3,8,78,9); textbackground(01); textcolor(12);  clrscr();

   gotoxy(4,1); textcolor(YELLOW); cprintf("RTL LAN for WRITE MAC");
   gotoxy(4,2); cprintf("LAN_ID=");
   scanf("%s",&all_1);
   string_number=strlen(all_1);
   if(string_number!=12)
   { gotoxy(35,2); cprintf("Above 12bit,Please try again!");
     delay(3000); spawnl(P_WAIT,"makemac.exe",NULL); exit(1); }

   fp=fopen(template,"r");
   loop1=0;
   while( (ch=getc(fp)) != EOF )
   {
    all_eeprom[loop1]=ch;
       loop1++;
   }
   fclose(fp);


   /*==========*/
   /*= LAN ID =*/
   /*==========*/
   all_eeprom[9]=all_1[0];
   all_eeprom[10]=all_1[1];

   all_eeprom[12]=all_1[2];
   all_eeprom[13]=all_1[3];

   all_eeprom[15]=all_1[4];
   all_eeprom[16]=all_1[5];

   all_eeprom[18]=all_1[6];
   all_eeprom[19]=all_1[7];

   all_eeprom[21]=all_1[8];
   all_eeprom[22]=all_1[9];

   all_eeprom[24]=all_1[10];
   all_eeprom[25]=all_1[11];




   fp=fopen(writefile,"w");
   for(i=0;i<loop1;i++)
   {
    fprintf(fp,"%c",all_eeprom[i]);

   }

   fclose(fp);

   spawnl(P_WAIT,"8100.exe",NULL);
   spawnl(P_WAIT,"echo PASS! PASS! PASS!",NULL);




 /*  gotoxy(4,16); cprintf("Press anykey to contium..."); */


}

