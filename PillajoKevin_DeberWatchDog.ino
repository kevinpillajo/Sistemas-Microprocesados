/*                       UNIVERSIDAD TÉCNICA DEL NORTE 
 *                              FICA / CIERCOM
 *                         SISTEMAS MICROPROCESADOS 
 *  Nombre: Kevin Pillajo             
 *  Fecha: 28-07-2019
 *  DEBER WATCHDOG: Realizar un programa que reinicie el sistema al tener la hora 00:10:50. Cuando vuelva a funcionar, deberá empezar con la hora 00:11:10. 
 *  Es proceso se observa en una LCD                                    
*/
#include <EEPROM.h>
#include <MsTimer2.h>
#include <LiquidCrystal.h> 
#include <avr/wdt.h>
  
 LiquidCrystal lcd(13,12,11,10,9,8);
 int s = 0;
 int m = 0;
 int h = 0;
 
void setup() {
  Serial.begin(9600);
  MsTimer2::set(1000,timer);
  MsTimer2::start();
  /*int tam = EEPROM.length();
  for (int i = 0; i<tam;i++){
    EEPROM.write(i,255);
  }
  EEPROM.write(0,0);
  EEPROM.write(1,10);
  EEPROM.write(2,30);*/
  h = EEPROM.read(0);
  m = EEPROM.read(1);
  s = EEPROM.read(2);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void timer(){
  s++;
  if(s==60){
    m++;
    s=0;
  }
  if(m==60){
    h++;
    m=0;
  }
  if(h==24){
    h = 0;
  }
  String sh = String(h);
  String sm = String(m);
  String ss = String(s);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Reloj");
  lcd.setCursor(0,1);
  lcd.print(sh+":"+sm+":"+ss);
  EEPROM.write(0,h);
  EEPROM.write(1,m);
  EEPROM.write(2,s);
  if(h==0&&m==10&&s==49){
    EEPROM.write(1,11);
    EEPROM.write(2,10);
    wdt_enable(WDTO_8S);
    MsTimer2::stop();
  }
}
