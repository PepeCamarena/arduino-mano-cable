// Define sensores y servos

#include <Servo.h> //Incluir la libreria de servos

Servo dedo1, dedo2, dedo3, dedo4, dedo5;

int servoPin1 = 5;
int servoPin2 = 6;
int servoPin3 = 9;
int servoPin4 = 10;
int servoPin5 = 3;

int flexPin1 = A0;
int flexPin2 = A1;
int flexPin3 = A2;
int flexPin4 = A3;
int flexPin5 = A4;

void setup()
{
    // Conectando los objetos servo a sus respectivos pines
    dedo1.attach(servoPin1);
    dedo2.attach(servoPin2);
    dedo3.attach(servoPin3);
    dedo4.attach(servoPin4);
    dedo5.attach(servoPin5);
    
    /* Configurar cada pin del servo en salida 
     ** No estoy seguro que sea necesario, pero lo hice por si acaso*/
    pinMode(servoPin1, OUTPUT);
    pinMode(servoPin2, OUTPUT);
    pinMode(servoPin3, OUTPUT);
    pinMode(servoPin4, OUTPUT);
    pinMode(servoPin5, OUTPUT);
    
    // Se asocia cada flex sensor a su pin de entrada
    pinMode(flexPin1, INPUT);
    pinMode(flexPin2, INPUT);
    pinMode(flexPin3, INPUT);
    pinMode(flexPin4, INPUT);
    pinMode(flexPin5, INPUT);
    
    
}

void loop()
{
    // Define las entrada analogas variables
    int flex1 = analogRead(flexPin1);
    int flex2 = analogRead(flexPin2);
    int flex3 = analogRead(flexPin3);
    int flex4 = analogRead(flexPin4);
    int flex5 = analogRead(flexPin5);
    
    /* Define las variable "pos" como proporcionales a las entradas flexibles
       El rango de valores de 400 a 700 son tentativos dependiendo de los flex 
       que se compren y de los valores que arrojen sus lecturas */
    int pos1 = map(flex1, 400, 700, 0, 180);
    pos1 = constrain(pos1, 0, 180);
    int pos2 = map(flex2, 400, 700, 0, 180);
    pos2 = constrain(pos2, 0, 180);
    int pos3 = map(flex3, 400, 700, 0, 180);
    pos3 = constrain(pos3, 0, 180);
    int pos4 = map(flex4, 480, 640, 0, 180);
    pos4 = constrain(pos4, 0, 180);
    int pos5 = map(flex5, 400, 700, 0, 180);
    pos5 = constrain(pos5, 0, 180);
    
    // Le ordena a los servos que se muevan según la cantidad especificada en las variables "pos"
    dedo1.write(pos1);
    dedo2.write(pos2);
    dedo3.write(pos3);
    dedo4.write(pos4);
    dedo5.write(pos5);
}
