#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <ctype.h>
#include <string.h>
void derecha(void);
void izquier(void);
void bajada(void);
void subida(void);
void ver_sopa(void);
void verificar_posicion(void);
void administrador(void);
void jugador(void);
void verificar_palabra(void);
// DECLARACION DE LA MATRIZ PARA LA SOPA DE LETRAS
char sop[15][15]={'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'};

char palabras[15][15]={"INFORMATICA","PROGRAMACION","COMPUTADOR","LENGUAJE","SISTEMAS",
     "WINDOWS","INTERNET","MONITOR","CPU","WIFI",
     "REDES","MEMORIA","RATON","TECNOLOGIA","LAPTO"};
int a=0,b=0,suma=0,tot=0,acum=0,bsuma=0, pf=0, pc=0, pal=0, d=0, paso=0, filtro=0;
char can[20],vol[20],op[1], pcc, dir[2],pausa[1];
////////////////////////////////////////////////////////////////

void main(){
  do{
    clrscr();
    textcolor(YELLOW);
    gotoxy(15,2);cprintf("J U E G O   D E   S O P A   D E   L E T R A S");
    textcolor(WHITE);
    gotoxy(15,3);cprintf("_____________________________________________");
    textcolor(GREEN);
    gotoxy(30,5);cprintf("MENU PRINCIPAL");
    gotoxy(15,8);cprintf("1.- Administrador");
    gotoxy(15,9);cprintf("2.- Jugador");
    gotoxy(15,10);cprintf("0.- Salir");
    textcolor(WHITE);
    gotoxy(15,12);cprintf("Indique una opcion del 0-2 ( )");
    gotoxy(43,12);scanf("%c",&op[0]);
    fflush;
    if(op[0]=='1'){
      administrador();
      filtro =1;
      fflush;
      scanf("%c",&pausa[0]);
    }
    if(op[0]=='2'){
      if(filtro!=0){
	jugador();
	fflush;
	scanf("%c",&pausa[0]);
      }else{
       fflush;
       gotoxy(30,24);cprintf("Ingrese primero como administrador");
       cscanf("%c",&pausa[0]);
      }
    }
  }while(op[0]!='0');
}

void administrador(void)
   {
       int f,c,i;
       clrscr();
       textbackground(BLACK);
       textcolor(WHITE);//imprime mi sopa de letras
       //IMPRIME LA REFERENCIA DE FILAS Y COLUMNAS (ABC123)
       textcolor(WHITE);
       gotoxy(6,2);cprintf("A D M I N I S T R A D O R");
       textcolor(RED);
       gotoxy(4,4);cprintf("A B C D E F G H I J K L M N O");
       textcolor(YELLOW);
       for(i=5; i<20; i++){
	  gotoxy(1,i);cprintf("%d",i-4);
       }
       ver_sopa();
       textcolor(GREEN);
       gotoxy(35,2);cprintf("FIL(1-15) COL(A-O) DIR: HD, HI, VS, VB");
       gotoxy(35,3);cprintf("PALABRAS/Caract  FILA  COLUMNA   DIRECCION");
       textcolor(WHITE);
       gotoxy(60,4);printf(" ");  //54  62  71
       gotoxy(35,5 );cprintf("INFORMATICA (11)  (  )    ( )      (  )");
       gotoxy(35,6 );cprintf("PROGRAMACION (12) (  )    ( )      (  )");
       gotoxy(35,7 );cprintf("COMPUTADOR   (10) (  )    ( )      (  )");
       gotoxy(35,8);cprintf("LENGUAJE (8)      (  )    ( )      (  )");
       gotoxy(35,9);cprintf("SISTEMAS (8)      (  )    ( )      (  )");
       gotoxy(35,10);cprintf("WINDOWS (7)       (  )    ( )      (  )");
       gotoxy(35,11);cprintf("INTERNET (8)      (  )    ( )      (  )");
       gotoxy(35,12);cprintf("MONITOR (7)       (  )    ( )      (  )");
       gotoxy(35,13);cprintf("CPU (3)           (  )    ( )      (  )");
       gotoxy(35,14);cprintf("WIFI (4)          (  )    ( )      (  )");
       gotoxy(35,15);cprintf("REDES (5)         (  )    ( )      (  )");
       gotoxy(35,16);cprintf("MEMORIA (7)       (  )    ( )      (  )");
       gotoxy(35,17);cprintf("RATON (5)         (  )    ( )      (  )");
       gotoxy(35,18);cprintf("TECNOLOGIA (10)   (  )    ( )      (  )");
       gotoxy(35,19);cprintf("LAPTO (5)         (  )    ( )      (  )");
       int j=0;
       do{
	 for(j=5; j<20; j++) {   //CICLO
	    do{
	      fflush;
	      gotoxy(54,j);printf("  ");
	      gotoxy(54,j);cscanf("%d",&pf);
	    }while(pf==0 || pf>15);
	    pc=0;
	    do{
	      fflush;
	      gotoxy(62,j);printf(" ");
	      gotoxy(62,j);cscanf("%c",&pcc);
	      if(pcc=='A' || pcc=='a'){
		pc=1;
	      }
	      if(pcc=='B' || pcc=='b'){
		pc=2;
	      }
	      if(pcc=='C' || pcc=='c'){
		pc=3;
	      }
	      if(pcc=='D' || pcc=='d'){
		pc=4;
	      }
	      if(pcc=='E' || pcc=='e'){
		pc=5;
	      }
	      if(pcc=='F' || pcc=='f'){
		pc=6;
	      }
	      if(pcc=='G' || pcc=='g'){
		pc=7;
	      }
	      if(pcc=='H' || pcc=='h'){
		pc=8;
	      }
	      if(pcc=='I' || pcc=='i'){
		pc=9;
	      }
	      if(pcc=='J' || pcc=='j'){
		pc=10;
	      }
	      if(pcc=='K' || pcc=='k'){
		pc=11;
	      }
	      if(pcc=='L' || pcc=='l'){
		pc=12;
	      }
	      if(pcc=='M' || pcc=='m'){
		pc=13;
	      }
	      if(pcc=='N' || pcc=='n'){
		pc=14;
	      }
	      if(pcc=='O' || pcc=='o'){
		pc=15;
	      }
	    }while(pc==0);
	    d=0;
	    do{
	      gotoxy(71,j);cprintf("  ");
	      gotoxy(71,j);cscanf("%s",&dir);
	      if(dir[0]=='H' && dir[1]=='D' || dir[0]=='h' && dir[1]=='d'){
		d=1;
	      }
	      if(dir[0]=='H' && dir[1]=='I' || dir[0]=='h' && dir[1]=='i'){
		d=2;
	      }
	      if(dir[0]=='V' && dir[1]=='S' || dir[0]=='v' && dir[1]=='s'){
		d=3;
	      }
	      if(dir[0]=='V' && dir[1]=='B' || dir[0]=='v' && dir[1]=='b'){
		d=4;
	      }
	    }while(d==0);
	    verificar_posicion();
	    pal++;
	    if(paso==0){
	      j--;
	      pal--;
	    }
	 }
	 //RELLENAR ESPACIOS VACIOS CON LETRAS ALEATORIAS
	 char letra;
	 int cascii=0;
	 for (i=0; i<15; i++)
	 {
	   for (j=0; j<15; j++)
	   {
	     if (sop[i][j] =='_'){
	       cascii=0;
	       do {
		 randomize();
		 cascii=random(91);
	       }while(cascii<65);
	       if (cascii==65){
		 letra='A';
	       }
	       if (cascii==66){
		 letra='B';
	       }
	       if (cascii==67){
		 letra='C';
	       }
	       if (cascii==68){
		 letra='D';
	       }
	       if (cascii==69){
		 letra='E';
	       }
	       if (cascii==70){
		 letra='F';
	       }
	       if (cascii==71){
		 letra='G';
	       }
	       if (cascii==72){
		 letra='H';
	       }
	       if (cascii==73){
		 letra='I';
	       }
	       if (cascii==74){
		 letra='J';
	       }
	       if (cascii==75){
		 letra='K';
	       }
	       if (cascii==76){
		 letra='L';
	       }
	       if (cascii==77){
		 letra='M';
	       }
	       if (cascii==78){
		 letra='N';
	       }
	       if (cascii==79){
		 letra='O';
	       }
	       if (cascii==80){
		 letra='P';
	       }
	       if (cascii==81){
		 letra='Q';
	       }
	       if (cascii==82){
		 letra='R';
	       }
	       if (cascii==83){
		 letra='S';
	       }
	       if (cascii==84){
		 letra='T';
	       }
	       if (cascii==85){
		 letra='U';
	       }
	       if (cascii==86){
		 letra='V';
	       }
	       if (cascii==87){
		 letra='W';
	       }
	       if (cascii==88){
		 letra='X';
	       }
	       if (cascii==89){
		 letra='Y';
	       }
	       if (cascii==90){
		 letra='Z';
	       }
	       sop[i][j]=letra;
	     }
	   }
	 }

       }while(paso==0);
       ver_sopa();
       fflush;
       gotoxy(30,24);cprintf("Pulse una letra para regresar al menu principal ");
       gotoxy(80,24);cscanf("%c",&pausa);
       textcolor(WHITE);

   }

   //FUNCION PARA VER SOPA EN PANTALLA
    void ver_sopa(void){
       int fila,columna,f,c;
       fila = 0;
       columna = 0;
       textcolor(BLUE);
       for(f=0;f<=14;f++)
       {
	 for(c=0;c<=14;c++)
	 {
	    gotoxy((c+2)*2,(f+5));cprintf("%c",sop[fila][columna]);
	    columna++;
	 }
	 columna = 0;
	 fila++;
       }
    }


   //FUNCION PARA VERIFICAR LA POSICION
    void verificar_posicion(void){
       paso=0;
       int letras=0;
       letras = strlen(palabras[pal]);
       int disponibles=0;
       if(d==1){
	  disponibles = 15-pc;
       }
       if(d==2){
	  disponibles = pc;
       }
       if(d==3){
	  disponibles = pf;
       }
       if(d==4){
	  disponibles = 15-pf;
       }
       if(disponibles>=letras){
	 //VERIFICAR SI NO CHOCA CON OTRAS PALABRAS
	 //DIRECCION HORIZONTAL A LA DERECHA
	 if(d==1){
	    int c,f,i,j;
	    c= pc-1;
	    f= pf-1;
	    for(i=0; i<=letras-1; i++){
	      if(sop[f][c+i]==palabras[pal][i] || sop[f][c+i]== '_'){
		 paso=1;
	      }else{
		 paso=0;
		 i=letras;
	      }
	    }
	    if(paso==1){
	      for(j=c; j<=c+letras-1; j++){
		 sop[f][j]=palabras[pal][j-c];
	      }
	      ver_sopa();
	    }
	 }

	 //DIRECCION HORIZONTAL A LA IZQUIERDA
	 if(d==2){
	    int c,f,i,j;
	    c= pc-1;
	    f= pf-1;
	    for(i=0; i<=letras+1; i++){
	      if(sop[f][c]==palabras[pal][i] || sop[f][c]== '_'){
		 paso=1;
	      }else{
		 paso=0;
		 i=0;
	      }
	      c--;
	    }
	    c=pc-1;
	    if(paso==1){
	      int k=0;
	      for(j=c; j>=c-letras+1; j--){
		 sop[f][j]=palabras[pal][k];
		 k++;
	      }
	      ver_sopa();
	    }
	 }

	 //DIRECCION VERTICAL HACIA ARRIBA
	 if(d==3){
	    int c,f,i,j;
	    c= pc-1;
	    f= pf-1;
	    for(i=0; i<=letras+1; i++){
	      if(sop[f][c]==palabras[pal][i] || sop[f][c]== '_'){
		 paso=1;
	      }else{
		 paso=0;
		 i=0;
	      }
	      f--;
	    }
	    f=pf-1;
	    if(paso==1){
	      int k=0;
	      for(j=f; j>=f-letras+1; j--){
		 sop[j][c]=palabras[pal][k];
		 k++;
	      }
	      ver_sopa();
	    }
	 }

	 //DIRECCION VERTICAL HACIA ABAJO
	 if(d==4){
	    int c,f,i,j;
	    c= pc-1;
	    f= pf-1;
	    for(i=0; i<=letras-1; i++){
	      if(sop[f+i][c]==palabras[pal][i] || sop[f+i][c]== '_'){
		 paso=1;
	      }else{
		 paso=0;
		 i=letras;
	      }
	    }
	    if(paso==1){
	      for(j=f; j<=f+letras-1; j++){
		 sop[j][c]=palabras[pal][j-f];
	      }
	      ver_sopa();
	    }
	 }

       }
    }


    void jugador(void)
   {
     int f,c,i;
     pal=0;
     clrscr();
     do
     {
       textbackground(BLACK);
       textcolor(WHITE);
       //IMPRIME LA REFERENCIA DE FILAS Y COLUMNAS (ABC123)
       textcolor(WHITE);
       gotoxy(14,2);cprintf("J U G A D O R");
       textcolor(RED);
       gotoxy(4,4);cprintf("A B C D E F G H I J K L M N O");
       textcolor(YELLOW);
       for(i=5; i<20; i++){
	  gotoxy(1,i);cprintf("%d",i-4);
       }
       ver_sopa();
       textcolor(GREEN);
       gotoxy(35,2);cprintf("FIL(1-15) COL(A-O) DIR: HD, HI, VS, VB");
       gotoxy(35,3);cprintf("PALABRAS/Caract  FILA  COLUMNA   DIRECCION");
       textcolor(WHITE);
       gotoxy(60,4);printf(" ");
       gotoxy(35,5 );cprintf("INFORMATICA (11)  (  )    ( )      (  )");
       gotoxy(35,6 );cprintf("PROGRAMACION (12) (  )    ( )      (  )");
       gotoxy(35,7 );cprintf("COMPUTADOR   (10) (  )    ( )      (  )");
       gotoxy(35,8);cprintf("LENGUAJE (8)      (  )    ( )      (  )");
       gotoxy(35,9);cprintf("SISTEMAS (8)      (  )    ( )      (  )");
       gotoxy(35,10);cprintf("WINDOWS (7)       (  )    ( )      (  )");
       gotoxy(35,11);cprintf("INTERNET (8)      (  )    ( )      (  )");
       gotoxy(35,12);cprintf("MONITOR (7)       (  )    ( )      (  )");
       gotoxy(35,13);cprintf("CPU (3)           (  )    ( )      (  )");
       gotoxy(35,14);cprintf("WIFI (4)          (  )    ( )      (  )");
       gotoxy(35,15);cprintf("REDES (5)         (  )    ( )      (  )");
       gotoxy(35,16);cprintf("MEMORIA (7)       (  )    ( )      (  )");
       gotoxy(35,17);cprintf("RATON (5)         (  )    ( )      (  )");
       gotoxy(35,18);cprintf("TECNOLOGIA (10)   (  )    ( )      (  )");
       gotoxy(35,19);cprintf("LAPTO (5)         (  )    ( )      (  )");
       int j=0;
       do{
	 for(j=5; j<20; j++) {   //CICLO
	    do{
	      gotoxy(54,j);printf("  ");
	      gotoxy(54,j);cscanf("%d",&pf);
	    }while(pf==0 || pf>15);
	    pc=0;
	    do{
	      gotoxy(62,j);printf(" ");
	      gotoxy(62,j);cscanf("%c",&pcc);
	      if(pcc=='A' || pcc=='a'){
		pc=1;
	      }
	      if(pcc=='B' || pcc=='b'){
		pc=2;
	      }
	      if(pcc=='C' || pcc=='c'){
		pc=3;
	      }
	      if(pcc=='D' || pcc=='d'){
		pc=4;
	      }
	      if(pcc=='E' || pcc=='e'){
		pc=5;
	      }
	      if(pcc=='F' || pcc=='f'){
		pc=6;
	      }
	      if(pcc=='G' || pcc=='g'){
		pc=7;
	      }
	      if(pcc=='H' || pcc=='h'){
		pc=8;
	      }
	      if(pcc=='I' || pcc=='i'){
		pc=9;
	      }
	      if(pcc=='J' || pcc=='j'){
		pc=10;
	      }
	      if(pcc=='K' || pcc=='k'){
		pc=11;
	      }
	      if(pcc=='L' || pcc=='l'){
		pc=12;
	      }
	      if(pcc=='M' || pcc=='m'){
		pc=13;
	      }
	      if(pcc=='N' || pcc=='n'){
		pc=14;
	      }
	      if(pcc=='O' || pcc=='o'){
		pc=15;
	      }
	    }while(pc==0);
	    d=0;
	    do{
	      gotoxy(71,j);cprintf("  ");
	      gotoxy(71,j);cscanf("%s",&dir);
	      if(dir[0]=='H' && dir[1]=='D' || dir[0]=='h' && dir[1]=='d'){
		d=1;
	      }
	      if(dir[0]=='H' && dir[1]=='I' || dir[0]=='h' && dir[1]=='i'){
		d=2;
	      }
	      if(dir[0]=='V' && dir[1]=='S' || dir[0]=='v' && dir[1]=='s'){
		d=3;
	      }
	      if(dir[0]=='V' && dir[1]=='B' || dir[0]=='v' && dir[1]=='b'){
		d=4;
	      }
	    }while(d==0);
	    verificar_palabra();
	    pal++;
	    if(paso==0){
	      j--;
	      pal--;
	    }
	 }
       }while(paso==0);
       gotoxy(30,24);cprintf("Pulse enter para regresar al menu principal ");
       fflush;
       gotoxy(80,24);scanf("%c",&pausa);
       textcolor(WHITE);
     }while(op[0]=='0');
   }

   //FUNCION PARA VERIFICAR SI LA POSICION ES CORRECTA
    void verificar_palabra(void){
       char palabra[1][15];
       paso=0;
       int letras=0,j=0,c,f;
       letras = strlen(palabras[pal]);
       if(d==1){
	 int c,f,i,j;
	    c= pc-1;
	    f= pf-1;
	    for(i=0; i<=letras-1; i++){
	      if(sop[f][c+i]==palabras[pal][i]){
		 paso=1;
	      }else{
		 paso=0;
		 i=letras;
	      }
	    }
	    c=pc;
	    f=pf;
	    if(pc==1)c=4;
	    if(pc==2)c=6;
	    if(pc==3)c=8;
	    if(pc==4)c=10;
	    if(pc==5)c=12;
	    if(pc==6)c=14;
	    if(pc==7)c=16;
	    if(pc==8)c=18;
	    if(pc==9)c=20;
	    if(pc==10)c=22;
	    if(pc==11)c=24;
	    if(pc==12)c=26;
	    if(pc==13)c=28;
	    if(pc==14)c=30;
	    if(pc==15)c=32;
	    if(paso==1){
	      for(j=0; j<=letras-1; j++){
		 textcolor(YELLOW);
		 gotoxy(c,pf+4);cprintf("%c",palabras[pal][j]);
		 c=c+2;
	      }
	    }
       }

       if(d==2){
	 int c,f,i,j;
	    c= pc-1;
	    f= pf-1;
	    for(i=0; i<=letras-1; i++){
	      if(sop[f][c]==palabras[pal][i]){
		 paso=1;
	      }else{
		 paso=0;
		 i=letras+1;
	      }
	      c--;
	    }
	    c=pc;
	    f=pf;
	    if(pc==1)c=4;
	    if(pc==2)c=6;
	    if(pc==3)c=8;
	    if(pc==4)c=10;
	    if(pc==5)c=12;
	    if(pc==6)c=14;
	    if(pc==7)c=16;
	    if(pc==8)c=18;
	    if(pc==9)c=20;
	    if(pc==10)c=22;
	    if(pc==11)c=24;
	    if(pc==12)c=26;
	    if(pc==13)c=28;
	    if(pc==14)c=30;
	    if(pc==15)c=32;
	    if(paso==1){
	      for(j=0; j<=letras-1; j++){
		 textcolor(YELLOW);
		 gotoxy(c,pf+4);cprintf("%c",palabras[pal][j]);
		 c=c-2;
	      }
	    }
       }

       if(d==3){
	 int c,f,i,j;
	    c= pc-1;
	    f= pf-1;
	    for(i=0; i<=letras-1; i++){
	      if(sop[f][c]==palabras[pal][i]){
		 paso=1;
	      }else{
		 paso=0;
		 i=letras+1;
	      }
	      f--;
	    }
	    c=pc;
	    f=pf+4;
	    if(pc==1)c=4;
	    if(pc==2)c=6;
	    if(pc==3)c=8;
	    if(pc==4)c=10;
	    if(pc==5)c=12;
	    if(pc==6)c=14;
	    if(pc==7)c=16;
	    if(pc==8)c=18;
	    if(pc==9)c=20;
	    if(pc==10)c=22;
	    if(pc==11)c=24;
	    if(pc==12)c=26;
	    if(pc==13)c=28;
	    if(pc==14)c=30;
	    if(pc==15)c=32;

	    if(paso==1){
	      for(j=0; j<=letras-1; j++){
		 textcolor(YELLOW);
		 gotoxy(c,f);cprintf("%c",palabras[pal][j]);
		 f=f--;
	      }
	    }
       }

       if(d==4){
	 int c,f,i,j;
	    c= pc-1;
	    f= pf-1;
	    for(i=0; i<=letras-1; i++){
	      if(sop[f+i][c]==palabras[pal][i]){
		 paso=1;
	      }else{
		 paso=0;
		 i=letras;
	      }
	    }
	    c=pc;
	    f=pf+4;
	    if(pc==1)c=4;
	    if(pc==2)c=6;
	    if(pc==3)c=8;
	    if(pc==4)c=10;
	    if(pc==5)c=12;
	    if(pc==6)c=14;
	    if(pc==7)c=16;
	    if(pc==8)c=18;
	    if(pc==9)c=20;
	    if(pc==10)c=22;
	    if(pc==11)c=24;
	    if(pc==12)c=26;
	    if(pc==13)c=28;
	    if(pc==14)c=30;
	    if(pc==15)c=32;
	    if(paso==1){
	      for(j=0; j<=letras-1; j++){
		 textcolor(YELLOW);
		 gotoxy(c,f);cprintf("%c",palabras[pal][j]);
		 f=f++;
	      }
	    }
       }
    }




