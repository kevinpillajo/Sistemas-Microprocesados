/*                       UNIVERSIDAD TÉCNICA DEL NORTE 
 *                              FICA / CIERCOM
 *                         SISTEMAS MICROPROCESADOS 
 *  Nombre: Kevin Pillajo
 *  Fecha: 26-06-2019
 *  DEBER : Igreso de contraseña mediante teclado matricial
*/

#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd (12,11,5,4,3,2);
const byte filas=4;
const byte columnas=4;
byte pinsFilas[filas]={A0, A1, A2, A3};
byte pinsColumnas[columnas]={10, 9, 8};
char teclas[filas][columnas]={
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'#','0','*'}
};
Keypad teclado= Keypad (makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas);
char tecla;
int numero;
char clave1 [4]={'1', '2', '3', '4'};
char clave2 [4];
int i=0, j=0, k=0,w=0;
int c;
  
void setup() {
lcd.begin(16,2);
}

void loop() {
char tecla=teclado.getKey();

if (tecla!=NO_KEY)
{
  numero=tecla-48;
}
if(numero==17)
{
  c=1;
  numero=3;
}
  if(c==1)
  {
    delay(50);
    lcd.println();
    lcd.println("Ingrese Clave");
    for(j=0; j<=3; j++)
    {
      clave2[j]=teclado.waitForKey();
      lcd.print("*");
    }
      delay(50);
      w=0;
for(k=0; k<=3; k++)
{
  if (clave1[k]==clave2[k])
  {
    w++;
  }
}
 
if (w==4)
{
lcd.println();
lcd.println("Clave Correcta");
lcd.println();
lcd.println("Bienvenidos");
c=2;
}
else
{
 lcd.println();
lcd.println("Clave Incorrecta");
delay(600); 
}
}
}
