//Hector Gutierrez
//Mayra Ruvalcaba
//Valeria Navarro
//Ximena Dojaquez 

#include<Servo.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 11, 5, 6, 7, 8);


//declarar variables 

const int pinPIR = 2;
Servo myServo;

int led_rojo = 9;
int led_azul = 10;
int statePIR = 0;
int valorAngulo = 0;
int pinButton = 4;
int pinBuzzer = 3;
int stateButton;
void setup()
{

    //declarar ENTRADAS Y SALIDAS

    pinMode(pinButton, INPUT);
    pinMode(pinBuzzer, OUTPUT);
    pinMode(led_rojo, OUTPUT);
    pinMode(led_azul, OUTPUT);
    pinMode(pinPIR, INPUT);  //declarar pin 2 como ENTRADA 
    myServo.attach(12);      // pin donde conecto el servomotor #12
    myServo.write(0);        //anuglo Inicial del servomotor 


    //Encender el Monitor Serial
    Serial.begin(9600);

    // imprime el número de segundos desde el reinicio:
    //lcd.print(millis() / 1000);
    lcd.begin(16, 2);
    lcd.setCursor(3, 0);
    lcd.print("BIENVENIDO");
    lcd.setCursor(2, 1);
    lcd.print("FEMALE-HACK!");
    delay(2000);

    Serial.println("Para solicitar ayuda en caso de emergencia");
    Serial.println("Presione el boton");
    delay(3000);
    lcd.clear();

}

void loop()
{

    stateButton = digitalRead(pinButton);

    if (stateButton == LOW)
    {
        //encender alarma al presionar el boton
        tone(pinBuzzer, 400, 100);
        digitalWrite(led_rojo, HIGH);
        digitalWrite(led_azul, LOW);
        delay(500);
        digitalWrite(led_rojo, LOW);
        digitalWrite(led_azul, HIGH);
        delay(500);
        digitalWrite(led_rojo, HIGH);
        digitalWrite(led_azul, LOW);
        delay(500);
        digitalWrite(led_rojo, HIGH);
        digitalWrite(led_azul, LOW);
        delay(500);


        // imprime el número de segundos desde el reinicio:
        //lcd.print(millis() / 1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Llamando al 911 ");
        lcd.setCursor(3, 1);
        lcd.print("La policia ");

        Serial.println("ALERTA!!!");
        Serial.print("Llamando a la policia");
        delay(1000);
        Serial.print(".");
        delay(1000);
        Serial.print(".");
        delay(1000);
        Serial.println(".");
        Serial.println(" ");
        Serial.println("CONSERVE LA CALMA");
        Serial.println("LA POLICIA YA VIENE EN CAMINO");

        delay(10);
    }

    statePIR = digitalRead(pinPIR);  //leer el estado del sensor PIR (HIGH o LOW)
    if (statePIR == HIGH) {          //si el sensor se activa entonces gira el servomor a 90 grados 
        myServo.write(180);             //entonces gira el servomotor a 180 grados
        delay(3000);
        valorAngulo = myServo.read();
        Serial.println("Entregando producto");
        delay(2000);
        Serial.println("Producto Entregado!");

    }
    else {
        myServo.write(0);           //regresa a su posicion original 

    }



}
