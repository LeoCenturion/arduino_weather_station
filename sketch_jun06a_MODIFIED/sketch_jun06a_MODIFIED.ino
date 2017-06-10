#include <SD.h>

  /*
Pin Configuration
Rain Drop      A0
Soil Humidity  A1
SDA            A4
SCL            A5
DHT11 Data     D2
*/

float result [3];           //Sensor result array
#include <Wire.h>         //Including wire library
#include <SFE_BMP180.h>   //Including BMP180 library
#define ALTITUDE 10       //Estimamos un promedio de 10 metros de altura sobre el nivel del mar - CABA
SFE_BMP180 pressure;      //Creating an object
#include <DHT.h>          //Including DHT11 library
#define DHTPIN 2          //Define DHT11 digital pin
#define DHTTYPE DHT11     //Define DHT TYPE which is DHT11
DHT dht(DHTPIN, DHTTYPE); //Execute DHT11 library

void setup() {
  Serial.begin(9600);       //Starting serial communication
  Serial.println("Programa iniciado");
  Serial.println("Inicializando tarjeta SD");
  if (!SD.begin(4)) {
    Serial.println("La tarjeta SD falló");
    return;
  }
  File dataFile = SD.open("mediciones.txt", FILE_WRITE);
  if (!dataFile) {
    Serial.println("Marcelo, esto falló");
  }
  else {
    Serial.println("La tarjeta SD creó el archivo y llegué hasta acá. vamo manaos"); 
    dataFile.println("Datalogger laboratorio:");
  }
/*
  if (pressure.begin()) {
     dataFile.print("Presión (mBar),");                 // posicion 0 del array result
     dataFile.print("Temperatura-BMP (°C),");
     dataFile.print("Humedad (),");
     dataFile.println("Temperatura-DHT (°C)\n");        // posicion 3 del array result
  }   
  else {
      dataFile.println("BMP180 init fail");
      while (1);
    }
*/
  dataFile.close();
  if(!SD.exists("mediciones.txt")){
    Serial.println("No. Este archivo no existe");
  }

/*  
  if (pressure.begin())     //If initialization was successful, continue
   {Serial.println("BMP180 init success");
   Serial.print("Datalogger laboratorio:");
   Serial.print("\n");
   Serial.print("Presión (mBar),");                 // posicion 0 del array result
   Serial.print("Temperatura-BMP (°C),");
   Serial.print("Humedad (),");
   Serial.println("Temperatura-DHT (°C)\n");}   // posicion 3 del array result
  else                       //Else, stop code forever
    {
      Serial.println("BMP180 init fail");
      while (1);
    }
    */

  //DHT11 setup
  dht.begin(); 
}

void loop() {
  
//  char status;
//  double T, P, p0;  // T -> temperatura, P-> presion a la altura actual, p0-> p al nivel del mar 
//  status = pressure.startTemperature();
//  if (status != 0) {
//      delay(status);
//      status = pressure.getTemperature(T);  //todo:escribir tambien la t de bmp180
//      result[2] = T;
//      if (status != 0) {        
//      status = pressure.startPressure(3); //por que 3?-> número magico
//        if (status != 0) {
//          delay(status);
//          status = pressure.getPressure(P, T);
//          if (status != 0) {
//            p0 = pressure.sealevel(P, ALTITUDE);
//            result[0]=p0;
//          }}}}

//  result[1] = dht.readHumidity();           // no estaria reconociendo la funcion. ampliaremos
//  result[3] = dht.readTemperature();        // esta y la de arriba reciben un bool por parametro que no estaria pasadod<

 File dataFile = SD.open("mediciones.csv");
 dataFile.print(result[0]);
 dataFile.print(",");
 dataFile.print(result[1]);
 dataFile.print(",");
 dataFile.print(result[2]);
 dataFile.print(",");
 dataFile.println(result[3]);
}


/*
 void loop() {
  
  //bmp180 setup
//  char status;
//  double T, P, p0;  // T -> temperatura, P-> presion a la altura actual, p0-> p al nivel del mar 
//  status = pressure.startTemperature();
//  if (status != 0) {
//      delay(status);
//      status = pressure.getTemperature(T);  //todo:escribir tambien la t de bmp180
//      result[2] = T;
//      if (status != 0) {        
//      status = pressure.startPressure(3); //por que 3?-> número magico
//        if (status != 0) {
//          delay(status);
//          status = pressure.getPressure(P, T);
//          if (status != 0) {
//            p0 = pressure.sealevel(P, ALTITUDE);
//            result[0]=p0;
//          }}}}

  result[1] = dht.readHumidity();           // no estaria reconociendo la funcion. ampliaremos
  result[3] = dht.readTemperature();        // esta y la de arriba reciben un bool por parametro que no estaria pasadod<
//  Serial.print("Datalogger: ");
//  Serial.print(" \t");
//  Serial.print(result[0]);
//  Serial.print(",");
  Serial.print(result[1]);
  Serial.print(",");
//  Serial.print(result[2]);
//  Serial.print(",");
  Serial.print(result[3]);
  Serial.print("\n");
}
 */



