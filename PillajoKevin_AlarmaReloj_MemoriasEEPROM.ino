/*                       UNIVERSIDAD TÉCNICA DEL NORTE 
 *                              FICA / CIERCOM
 *                         SISTEMAS MICROPROCESADOS 
 *  Nombre: Kevin Pillajo             
 *  Fecha: 15-07-2019
 *  Deber: Realice un sistema reloj con alarma almacenada en la EEPROM.                                     
*/

#include <LiquidCrystal.h>
#include <TimerOne.h>
#include<EEPROM.h>
#include <MsTimer2.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
int i = 0;
int d = 0;
int j = 0;
int m = 0;
int h = 0;
int M = 0;
int H = 0;
int k = 0;
String dato;
void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(12, INPUT);
  lcd.begin(16, 2);
  Timer1.initialize(1000000); 
  Timer1.attachInterrupt(contador); 
  MsTimer2::set(1000, talarma); 
  //MsTimer2::start();
  attachInterrupt(0, ho, RISING);
  attachInterrupt(1, mi, RISING);
  m = EEPROM.read(0);
  h = EEPROM.read(1);
}
void loop() {
  minutos();
  horas();    
  confalarma();
  //Serial.println(j);
  delay(500);
  segundos();
  detener();
  alarma();
  if (h > 23) {  
    h = 0;
  }
  // estructura LCD
  lcd.setCursor(2, 0);
  lcd.print(':');
  lcd.setCursor(5, 0);
  lcd.print(':');
  lcd.setCursor(0, 1);
  lcd.print("ALARMA");
  lcd.setCursor(8, 0);
  lcd.print(' ');
}
void contador() {   
  i++;               
  if (i == 10) {      
    EEPROM.write(0, m); 
    EEPROM.write(1, h); 
  }
  if (i > 59) {       
    i = 0;
    m++;         
  }
  if (m > 59) {       
    m = 0;
    h++;
  }
}
void segundos() {   
  if (i < 10) {        
    lcd.setCursor(6, 0);
    lcd.print(0);
    lcd.setCursor(7, 0); 
    lcd.print(i);
  }
  else {
    lcd.setCursor(6, 0); 
    lcd.print(i);
  }
}
void minutos() {      
  if (m < 10) {      
    lcd.setCursor(3, 0);  
    lcd.print(0);
    lcd.setCursor(4, 0);  
    lcd.print(m);
  }
  else {
    lcd.setCursor(3, 0);   
    lcd.print(m);
  }
}
void horas() {          
  if (h < 10) {           
    lcd.setCursor(0, 0);     
    lcd.print(0);
    lcd.setCursor(1, 0);     
    lcd.print(h);
  }
  else {
    lcd.setCursor(0, 0);      
    lcd.print(h);
  }
}
void talarma() {        
  j++;                    
}
void ho() {            
  h++;                     
}
void mi() {            
  m++;                 
}
void confalarma() {       
  if (k == 0) {           
    Serial.println("ingrese la hora para alarma");  
    delay(1000);
    if (Serial.available() > 0) {    
      dato = Serial.readString();   
      H = dato.toInt();            
      EEPROM.write(3, H);           
      delay(1000);
      k = 1;
    }
  }
  if (k == 1) {                   
    Serial.println(' ');
    Serial.println("Ingrese minutos para alarma");    
    delay(1000);
    if (Serial.available() > 0) {         
      dato = Serial.readString();           
      M = dato.toInt();                   
      EEPROM.write(4, M);                  
      delay(1000);
      k = 2;
    }
  }
  if (k == 2) {                       
    Serial.println(' ');
    Serial.println("La alarma ingresada es: ");     
    Serial.print(EEPROM.read(3));                 
    Serial.print(':');
    Serial.print(EEPROM.read(4));               
    k = 3;
  }
}
void alarma() {                            
  if (d == 0) {
    if (m == M && h == H && i == 0 ) {          
      digitalWrite(10, HIGH);  
      delay(1000);// pin 10 encendido
      MsTimer2::start();
      Serial.print("Alamra Activa");
      j = 0;
    }
    if (j == 1) {                           
      digitalWrite(10, LOW);                           
      j = 0;
      M++;
      //Estructura de la Modificacion de Alarma
      Serial.print("La nueva alarma: ");
      Serial.print(H);
      Serial.print(':');
      Serial.print(M);
      MsTimer2::stop();
    }
  }
  else {
    //Serial.print("Alarma Apagada");
    digitalWrite(10, LOW);                         
    d = 1;
    MsTimer2::stop();
    j = 0;
  }
}
void detener() {                         
  if ( digitalRead(12) == LOW)          
    d = 0;
  if ( digitalRead(12) == HIGH)                
    d = 1;
}
