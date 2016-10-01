#include "juego.h"
#define n 100// define el numero de carros 
volatile  int i,k=2,l=0,state=0,con=99,ax,aux=0,tie=500;
volatile  int columna[n],fila[n],id[5];
long int melody[]={e2,b,c2,D2,c2,b,a,a,c2,e2,D2,c2,b,c2,D2,e2,c2,a,a,a,b,c2,D2,f2,a2,
                   g2,f2,e2,c2,e2,D2,c2,b,b,c2,D2,e2,c2,a,a,S,e2,c2,D2,b,c2,a,gs,b,S,
                   e2,c2,D2,b,c2,e2,a2,g2s,S};
long int duracion[]={t_n,t_c,t_c,t_n,t_c,t_c,t_n,t_c,t_c,t_n,t_c,t_c,t_c+t_n,t_c,t_n,t_n,
                     t_n,t_n,t_c,t_c,t_c,t_c,t_n+t_c,t_c,t_n,t_c,t_c,t_n+t_c,t_c,t_n,t_c,
                     t_c,t_n,t_c,t_c,t_n,t_n,t_n,t_n,t_n,t_n,t_b,t_b,t_b,t_b,t_b,t_b,t_b,
                     t_n,t_n,t_b,t_b,t_b,t_b,t_n,t_n,t_b,t_b,t_b};
unsigned long currentmillis;
unsigned long previousmillis=0;
int note=0;
int speakerOut=9;
byte led_on={0b0000001};
Timer t;
LiquidCrystal lcd(12,11,7,6,5,4);
byte numero[10]=
            {
              B00001001,
              B10011111,
              B00101010,
              B00001110,
              B10011100,
              B01001100,
              B01001000,
              B00011111,
              B00001000,
              B00001100
            };
byte car[8]={0b11011,
             0b11011,
             0b01010,
             0b11111,
             0b11111,
             0b01010,
             0b11011,
             0b11011};
byte cerveza[8]={0b00100,
             0b01110,
             0b11111,
             0b11101,
             0b01101,
             0b01111,
             0b01110,
             0b01110};
byte choque[8]={0b11011,
             0b10010,
             0b01000,
             0b10110,
             0b10111,
             0b01110,
             0b10001,
             0b11011};
byte enemigo[8]={0b11011,
             0b00100,
             0b01101,
             0b11111,
             0b11111,
             0b01101,
             0b00100,
             0b11011};
      
void initGame()
{
          
          lcd.begin(16,2);
          lcd.clear();  
          lcd.createChar(0,car);
          lcd.createChar(1,choque);
          lcd.createChar(2,enemigo);
          lcd.createChar(3,cerveza);
          lcd.setCursor(0,0);
          lcd.write("   WELCOME TO   ");
          lcd.setCursor(0,1);
          lcd.write("  ROAD FIGTHER ");
          pinMode(2,INPUT_PULLUP);//INTERRUPCIONES
          pinMode(3,INPUT_PULLUP);//INTERRUPCIONES
          pinMode(10,OUTPUT);//LEDS SH_CP
          pinMode(15,OUTPUT);//LEDS DS
          pinMode(8,OUTPUT);//LEDS ST_CP
          pinMode(1,OUTPUT);//DISPLAY
          pinMode(0,OUTPUT);//DISPLAY
          pinMode(14,OUTPUT);//DISPLAY
          pinMode(speakerOut,OUTPUT);//SPEAKER
          delay(1000);
          columna[0]=15;
          llenar_fila();
          llenar_columna();
          id[0]=t.every(tie,escribir);
          id[1]=t.every(tie+5,estado);
          id[2]=t.every(tie,led);
          id[3]=t.every(tie,disp);
          id[4]=t.every(1,musica);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.write(byte(0));   
          attachInterrupt(digitalPinToInterrupt(2),left,FALLING);
          attachInterrupt(digitalPinToInterrupt(3),right,FALLING);
}  
                
void left()
{
          lcd.setCursor(0,1);
          lcd.write(" ");
          lcd.setCursor(0,0);
          lcd.write(byte(0));
          state=0;
          verifica2();
          return;  
}
void right()
{
          lcd.setCursor(0,0);
          lcd.write(" ");
          lcd.setCursor(0,1);
          lcd.write(byte(0));
          state=1;
          verifica2();
          return;
} 
void verifica()
{
      if((fila[i]==state) && (columna[i]==0) && (ax==1))
     {
      lcd.setCursor(0,fila[i]);
      lcd.write(byte(0));
      columna[i]=-2;
      con+=5;         
      }    
     else if((fila[i]==state) && (columna[i]==0))
     {
      lcd.setCursor(0,fila[i]);
      lcd.write(byte(1));
      columna[i]=-2;
      con-=10;         
      }
        
}
void verifica2()
{
       if( (fila[i]==state) && (columna[i]==-1) && (ax==1))
     {
      lcd.setCursor(0,fila[i]);
      lcd.write(byte(0));
      columna[i]=-2;
      con+=5;         
      }
     else if((fila[i]==state) && (columna[i]==-1))
     {
      lcd.setCursor(0,fila[i]);
      lcd.write(byte(1));
      columna[i]=-2;
      con-=10;         
      }
        
}
void llenar_fila()
{
        for(i=0;i<n;i++)
        {
        fila[i]=random(0,2);
        }
        return;
}
void llenar_columna()
{
          for(i=1;i<n;i++)
        {
          columna[i]=16;
        
        }
        return;
}
void escribir()
{
       
           for(i=0;i<n&&k==2;i++)
         {
          ax=0;
          if(columna[i]>-2)
          {
            if(i==0)
            {
          lcd.setCursor(columna[i],fila[i]);
          lcd.write(byte(2));                    
          lcd.setCursor(columna[i]+1,fila[i]);
          lcd.write(" ");
          verifica();
          verifica2();
          columna[i]--;               
            }
           else if (columna[i-1]<=12)
           {
          if(i%6==0)
          {
          lcd.setCursor(columna[i],fila[i]);
          lcd.write(byte(3));
          ax=1;                    
          }
          else
          {
          lcd.setCursor(columna[i],fila[i]);
          lcd.write(byte(2));   
          }                   
          lcd.setCursor(columna[i]+1,fila[i]);
          lcd.write(" ");
          verifica();
          verifica2();
          columna[i]--;            
           }
          }
         }
          return; 
}
void led()
{
 
          if(l%14==0)
          {
          digitalWrite(8,LOW);
          shiftOut(15,10,LSBFIRST,led_on);
          digitalWrite(8,HIGH);
          aux++;  
          led_on<<=1;        
          }
          l++;
          if(aux==8)
          {
            k=1;
          }
          
          return;  
}
void disp()
{
  if((con>0) && (con<100))
  {
          byte dis1 = con/10;
          byte dis2 = con-(dis1 * 10);
          digitalWrite(1,LOW);
          shiftOut(0,14,LSBFIRST,numero[dis1]);
          shiftOut(0,14,LSBFIRST,numero[dis2]);
          digitalWrite(1,HIGH);
          con--;
  }
  else if(con>100)
  {
          con=99;
          byte dis1 = con/10;
          byte dis2 = con-(dis1 * 10);
          digitalWrite(1,LOW);
          shiftOut(0,14,LSBFIRST,numero[dis1]);
          shiftOut(0,14,LSBFIRST,numero[dis2]);
          digitalWrite(1,HIGH);
  }
  else
  {
              con=0;
          byte dis1 = con/10;
          byte dis2 = con-(dis1 * 10);
          digitalWrite(1,LOW);
          shiftOut(0,14,LSBFIRST,numero[dis1]);
          shiftOut(0,14,LSBFIRST,numero[dis2]);
          digitalWrite(1,HIGH);      
  }
          if(con<=0)
          {
            k=0;
          }
}
void musica()
{
  currentmillis=millis();
  if(melody[note]!=0)
  tone(speakerOut,melody[note]);
  if(currentmillis-previousmillis>duracion[note]){
  previousmillis=currentmillis; 
  noTone(speakerOut);
  previousmillis=currentmillis;
note++;}
if(note==59)note=0;
}
void estado()
{
  if(k==0)
  {
    detachInterrupt(digitalPinToInterrupt(2));
    detachInterrupt(digitalPinToInterrupt(3)); 
    t.stop(id[0]);
    t.stop(id[1]);
    t.stop(id[2]);
    t.stop(id[4]);
    noTone(speakerOut);
    lcd.clear();
    lcd.write("     PERDIO  ");
  }
  else if(k==1)
  {
    detachInterrupt(digitalPinToInterrupt(2));
    detachInterrupt(digitalPinToInterrupt(3));
    t.stop(id[0]);
    t.stop(id[1]);
    t.stop(id[3]);
    t.stop(id[2]);
    t.stop(id[4]);
    noTone(speakerOut);
    lcd.clear();
    lcd.write("      GANO  ");   
  }
  
}
void actualizar()
{
   t.update();
}

