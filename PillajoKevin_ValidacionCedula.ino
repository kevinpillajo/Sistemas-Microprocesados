/*                                 UNIVERSIDAD TÉCNICA DEL NORTE
 *                                       FICA / CIERCOM
 *                                  SISTEMAS MICROPROCESADOS
 *   
 *    NOMBRE: Kevin Pillajo
 *    FECHA:19-05-2019
 *    TEMA: Comunicación Serial                           
 *    EJERCICIO: Valide la cédula ecuatoriana que se ingresa por comunicación serial con el Formato. 100124578-9 
 */ 


char cedula[11];             
char validacion[11];

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
  Serial.println("BIENVENIDO");                            
  Serial.println("Ingrese los dígitos su cedula");  
  for(int i;i<11;i){                            
    if(Serial.available()>0){                   
      cedula[i]=Serial.read();                  
      i++;                 
      }
    }
Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println("Validacion de la cedula ingresada");      
  for(int i;i<11;i){                            
    if(Serial.available()>0){                   
      validacion[i]=Serial.read();             
      i++;                                      
      }
      }
  Serial.println("");
  if(cedula[0]==validacion[0]&&cedula[1]==validacion[1]&&cedula[2]
  ==validacion[2]&&cedula[3]==validacion[3]&&cedula[4]==validacion[4]
  &&cedula[5]==validacion[5]&&cedula[6]==validacion[6]&&cedula[7]        
  ==validacion[7]&&cedula[8]==validacion[8]&&cedula[9]==validacion[9]
  &&cedula[10]==validacion[10])
  {
    Serial.println("La cedula ingresada es correcta correcta");                                   
    Serial.println("");
    }else{
       Serial.println("La cedula ingresada es incorrecta");                             
       Serial.println("");
      }      
}
