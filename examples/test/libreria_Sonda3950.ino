// En este ejemplo asumimos que el ADC es de 10 bits y el termistor es de 100K a 25 grados con una resistencia PULLUP de 100K
// Si no fuese así, se puede modificar esos datos al crear el objeto:
// sonda3950 termistor(pinTermistor, valorMaximoADC, valorResistenciaPullUp, valorResistenciaTermistor);


#include "sonda3950.h"


const uint8_t pinTermistor = A0;      // Pin de la sonda
float sensor;                         // Guardamos el valor del sensor


uint32_t tiempoActual, tiempoAnterior;
const uint32_t intervalo = 1000;


sonda3950 termistor(pinTermistor);    // Creamos objeto


void setup() {
  Serial.begin(115200);
  Serial.println("INICIO DEL SISTEMA");
  
  termistor.begin();
}


void loop() {
  tiempoActual = millis();
  
  termistor.actualizar();
  
  sensor = termistor.temperaturaLeida();

  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;
    Serial.println(sensor, 2);
  }
}