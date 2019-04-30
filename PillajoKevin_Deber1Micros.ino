/*                                 UNIVERSIDAD TÉCNICA DEL NORTE
 *                                       FICA / CIERCOM
 *                                  SISTEMAS MICROPROCESADOS
 *   
 *    NOMBRE: Kevin Pillajo
 *    FECHA:24-04-2019                          
 */ 
int leds[8]={1,2,3,4,5,6,7,8};
int j=0;
int led[6]={1,2,3,4,5,6};
int ledi[3]={1,3,5};
int ledp[3]={2,4,6};
int l=0;
int i=0;
int p=0;
long randNumber;
int r=0;
void setup() {
  // put your setup code here, to run once:
  for (;l<6;l++){
  pinMode(led[l],OUTPUT);
  }
  l=0;
  for (;i<3;i++){
  pinMode(ledi[i],OUTPUT);
  }
  i=0;
  for (;p<3;p++){
  pinMode(ledp[p],OUTPUT);
  }
  p=0;

  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  
// EJERCICIO 1: Realizar un juego de lueces que se prendan secuencialmente los leds impartes (1,3,5).
   for (;i<3;i++){
   digitalWrite(ledi[i],HIGH);//pines impares 1,3,5 en alto
   delay(200);//tiempo de espera de 200ms.
   }
   i=0;
   for (;i<3;i++){
   digitalWrite(ledi[i],LOW);//pines impares 1,3,5 en bajo
   delay(200);//tiempo de espera de 200ms.
   }
// EJERCICIO 2: Realizar un programa que se enciendan uno por uno los leds pares (0,2,4). 
   for (;p<3;p++){
   digitalWrite(ledp[p],HIGH);//pin pares 2,4,6 en alto
   delay(200);//tiempo de espera de 200ms.
   }
   p=0;
   for (;p<3;p++){
   digitalWrite(ledp[p],LOW);//pines pares 2,4,6 en bajo
   delay(200);//tiempo de espera de 200ms.
   }
// EJERCICIO 3.- Las luces se encienden y apagan de forma aleatoria. (Consultar random)
   r=random(1,7);
   for(l=0;l<r; l++){
   digitalWrite(led[l],HIGH); //pines 1,2,3,4,5,6 en ramdom  en alto.
   delay(200);//tiempo de espera de 200ms.
   }
// EJERCICIO 4.- Las luces se encnderán de abajo hacia arriba 
for(i=j;i<contador;i++){
  digitalWrite(leds[i],HIGH);
  delay(100);
  digitalWrite(leds[i],LOW);  
  delay(100);
// EJERCICIO 5.- Las luces se encenderán de abajo hacia arriba 
  for(int w=0;w<contador;w++){
  digitalWrite(leds[w],HIGH);
  delay(50);
  digitalWrite(leds[w],LOW);   
}
for(int w=contador-1;w>=0;w--){
  digitalWrite(leds[w],HIGH);
  delay(50);
  digitalWrite(leds[w],LOW);   
}
  i=0;
}
