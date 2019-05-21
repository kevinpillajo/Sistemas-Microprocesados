/*                                 UNIVERSIDAD TÉCNICA DEL NORTE
 *                                       FICA / CIERCOM
 *                                  SISTEMAS MICROPROCESADOS
 *   
 *    NOMBRE: Kevin Pillajo
 *    FECHA:19-05-2019
 *    TEMA: Comunicación Serial                           
 *    EJERCICIO:  Realizar una validación de placa de vehículo donde indique: 
 *    *La provincia 
 *    *Si ha registrado los 4 dígitos necesarios. 
 *    *Si no tiene números en la parte de las letras
 */ 
char placa[8], numeros[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-'};
int errorl = 0, errorn = 0;

void setup() {
  Serial.begin(9600);


}

void loop() {
  Serial.println("Ingrese la placa a validar(***-0000)");
  Serial.println("En caso de contar con tres numeros agregar 0");
  for (int i = 0; i < 8; i) {
    if (Serial.available() > 0) {
      placa[i] = Serial.read();
      Serial.print(placa[i]);
      i++;
    }
  }
  Serial.println(" ");

  if (placa[3] != numeros[10]) {
    Serial.println("El cuarto dígito debe ser un guion'-'");
  }

  validar_placa();

  provincia(placa[0]);
}

void validar_placa() {
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 9; j++) {
      if (placa[i] == numeros[j]) {
        errorl++;
      }
    }
  }
  if (errorl != 0) {
    Serial.println("Error letras");
    errorl = 0;
  }

  for (int i = 4; i < 8; i++) {
    for (int j = 0; j <= 9; j++) {
      if (placa[i] == numeros[j]) {
        errorn++;
      }
    }
  }
  if (errorn != 4) {
    Serial.println("Error numeros");
    errorn = 0;
  }
}

void provincia(char a) {
  switch (a) {
    case 'A':
      Serial.println("Placa de la provincia Azuay");
      break;
    case 'B':
      Serial.println("Placa de la provincia Bolivar");
      break;
    case 'C':
      Serial.println("Placa de la provincia Carchi");
      break;
    case 'E':
      Serial.println("Placa de la provincia Esmeraldas");
      break;
    case 'G':
      Serial.println("Placa de la provincia Guayas");
      break;
    case 'I':
      Serial.println("Placa de la provincia Imbabura");
      break;
    case 'J':
      Serial.println("Placa de la provincia Santo Domingo de los Tsachilas");
      break;
    case 'K':
      Serial.println("Placa de la provincia Sucumbios");
      break;
    case 'L':
      Serial.println("Placa de la provincia Loja");
      break;   
    case 'M':
      Serial.println("Placa de la provincia Manabi");
    case 'N':
      Serial.println("Placa de la provincia Napo");
    case 'O':
      Serial.println("Placa de la provincia El Oror");
    case 'P':
      Serial.println("Placa de la provincia Pichincha");
    case 'Q':
      Serial.println("Placa de la provincia Orellana");
    case 'R':
      Serial.println("Placa de la provincia Los Rios");
      break;
    case 'S':
      Serial.println("Placa de la provincia Pastaza");
      break;
    case 'T':
      Serial.println("Placa de la provincia Tungurahua");
      break;
    case 'V':
      Serial.println("Placa de la provincia Morona Santiago");
      break;
    case 'W':
      Serial.println("Placa de la provincia Galápagos");
      break;
    case 'X':
      Serial.println("Placa de la provincia Cotopaxi");
      break;
    case 'Y':
      Serial.println("Placa de la provincia Santa Elena");
      break;
    case 'Z':
      Serial.println("Placa de la provincia Zamora Chinchipe");
      break;
    default:
      Serial.println("Ingrese LETRAS en mayusculas");
      break;
  }
}
