#define button1 A1
#define button2 A0

// Display 7 Segmento 1 
int display1[7]= {A5,A4,2,3,4,5,6};
// Display 7 Segmento 2
int display2[7]= {7,8,9,10,11,12,13};

int counter; // contador
int unit=0; // unidad
int tens=0; // decena
String number;

// definicion de decodificador catodo
int number0[7] = {1,1,1,1,1,1,0};
int number1[7] = {0,1,1,0,0,0,0};
int number2[7] = {1,1,0,1,1,0,1};
int number3[7] = {1,1,1,1,0,0,1};
int number4[7] = {0,1,1,0,0,1,1};
int number5[7] = {1,0,1,1,0,1,1};
int number6[7] = {1,0,1,1,1,1,1};
int number7[7] = {1,1,1,0,0,0,0};
int number8[7] = {1,1,1,1,1,1,1};
int number9[7] = {1,1,1,1,0,1,1};
int letterE[7] = {1,0,0,1,1,1,1};

// Funcion de error E0
void displayE0(){
  for (int i=0; i<7; i++) {
    digitalWrite(display1[i],letterE[i]);
    digitalWrite(display2[i],number0[i]);
  }
}
// Funcion de error E9
void displayE9(){
  for (int i=0; i<7; i++) {
    digitalWrite(display1[i],letterE[i]);
    digitalWrite(display2[i],number9[i]);
  }
}

// Funcion mostrar numeros
void displayNumber(){
// numero de una cifra
  if(counter<10){
    number="";
    number+="0";
    number+= counter;
  }
// numero de dos cifras 
  else{
    number="";
    number+= counter;
  }

  unit= number.substring(1,2).toInt();
  tens=  number.substring(0,1).toInt();
  Serial.print(tens);
  Serial.print(" ");
  Serial.println(unit);

  switch (unit) {

  case(0):
  for(int i=0; i<7; i++){
    digitalWrite(display2[i],number0[i]);
  }
  break;

  case(1):
  for(int i=0; i<7; i++){
    digitalWrite(display2[i],number1[i]);
  }
  break;

  case(2):
  for(int i=0; i<7; i++){
    digitalWrite(display2[i],number2[i]);
  }
  break;

  case(3):
  for(int i=0; i<7; i++){
    digitalWrite(display2[i],number3[i]);    
  }
  break;

  case(4):
  for(int i=0; i<7; i++){
    digitalWrite(display2[i],number4[i]);
  }
  break;

  case(5):
  for(int i=0; i<7; i++){
    digitalWrite(display2[i],number5[i]);
  }
  break;

  case(6):
  for(int i=0; i<7; i++){
    digitalWrite(display2[i],number6[i]);
  }
  break;

  case(7):
  for(int i=0; i<7; i++){
    digitalWrite(display2[i],number7[i]);
  }
  break;

  case(8):
  for(int i=0; i<7; i++){
    digitalWrite(display2[i],number8[i]);
  }
  break;

  case(9):
  for(int i=0; i<7; i++){
    digitalWrite(display2[i],number9[i]);
  }
  break;
  }

  switch(tens){

    case(0):
  for(int i=0; i<7; i++){
    digitalWrite(display1[i],number0[i]);
  }
  break;

  case(1):
  for(int i=0; i<7; i++){
    digitalWrite(display1[i],number1[i]);
  }
  break;

  case(2):
  for(int i=0; i<7; i++){
    digitalWrite(display1[i],number2[i]);
  }
  break;

  case(3):
  for(int i=0; i<7; i++){
    digitalWrite(display1[i],number3[i]);    
  }
  break;

  case(4):
  for(int i=0; i<7; i++){
    digitalWrite(display1[i],number4[i]);
  }
  break;

  case(5):
  for(int i=0; i<7; i++){
    digitalWrite(display1[i],number5[i]);
  }
  break;

  case(6):
  for(int i=0; i<7; i++){
    digitalWrite(display1[i],number6[i]);
  }
  break;

  case(7):
  for(int i=0; i<7; i++){
    digitalWrite(display1[i],number7[i]);
  }
  break;

  case(8):
  for(int i=0; i<7; i++){
    digitalWrite(display1[i],number8[i]);
  }
  break;

  case(9):
  for(int i=0; i<7; i++){
    digitalWrite(display1[i],number9[i]);
  }
  break;

  }
}

void setup(){
  Serial.begin(9600);
  pinMode (button1, INPUT); // definicion del boton 1
  pinMode (button2, INPUT); // definicion del boton 2
  for (int i=0; i<7; i++) {
    pinMode(display1[i], OUTPUT);
    pinMode(display2[i],OUTPUT);
  }
  displayNumber();
}

void loop(){
  //boton decrementar
  if(digitalRead(button1)){
    counter--;
    Serial.println(counter);
    if(counter < 0){
      displayE0(); // muestra el error E0
      counter = -1;
    } else {
      displayNumber();
      delay(300);
    }
  }
  //boton incrementar
  if(digitalRead(button2)){
    counter++;
    Serial.println(counter);
    if(counter > 99){
      displayE9();// muestra el error E9
      counter = 100;
      delay(300);
    } else {
      displayNumber();
      delay(300);
    }
  }
}