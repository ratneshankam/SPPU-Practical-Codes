//          --> Assingment no 5        piezo +ve = with register GND, LED 2nd = with register GND || piezo -ve = 12,  LED 4th = 13
//                                     (proximity sensor) signal = D2;   power = 5V;    ground = GND
// int pirsensor;
// void setup() {
//     pinMode(2,INPUT);
//     pinMode(12,OUTPUT);
//     pinMode(13,OUTPUT);
// }
// void loop() {
//     pirsensor = digitalRead(2);
//     if(pirsensor == HIGH) {
//         digitalWrite(13, HIGH);
//         tone(12, 500, 500);
//     }
//     digitalWrite(13, LOW);
// }


//          --> Assingment no 6        piezo +ve = with register GND, LED 2nd = with register GND || piezo -ve = 12,  LED 4th = 13
//                                      (temperature sensor)    power = 5V;     vout = A2;      ground = GND;
// int tempsensor;
// void setup() {
//     pinMode(A2,INPUT);
//     pinMode(12,OUTPUT);
//     pinMode(13,OUTPUT);
// }
// void loop() {
//     tempsensor = analogRead(A2);
//     if(tempsensor >= 200) {
//         digitalWrite(13, HIGH);
//         tone(12, 500, 500);
//     }
//     digitalWrite(13, LOW);
// }