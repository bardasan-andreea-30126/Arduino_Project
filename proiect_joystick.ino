// Variabilele joystick-ului

int sX = A0;     //Axa x a joystick-ului, intrare analogica
int sY = A1;     //Axa y a joystick-ului, intrare analogica
int sSX;         //starea lui x, citita de pe sX
int sSY;         //starea lui y, citita de pe sY
int sS;          
// vom introduce variabile de joc
int rNum;        //un intreg ce reprezinta led-ul care se aprinde
int wins=0;      //numara rundele castigate
int highScore=0; //stocheaza cel mai mare numar de runde castigate

// Variabile constante ce dau timpul de reactie
const int easy=1000;
const int medium=500;
const int hard=325;
const int extreme=250;


int ledPins[]={5,2,4,3,6,7,8}; //initializare led-uri
int pinCount=7;                //numarul de pini pt led-uri

void setup() {

Serial.begin(9600);
pinMode(sX, INPUT);
pinMode(sY, INPUT);

for (int thisPin = 0; thisPin < pinCount; thisPin++) { //atribuie toti pinii ca iesiri intr-o bucla for
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() {

  rNum=random(4); // generam random ce led sa se aprinda
  delay(1000);
  digitalWrite(ledPins[rNum], HIGH); //se aprinde led-ul respectiv
  delay(extreme); 
  
 
  sSX = analogRead(sX); //se citesc intrarile de pe axa x
  delay(100);
  sSY = analogRead(sY); //se citesc intrarile de pe axa y

  //se convertesc intrarile de pe axele x si y la 4 variante. 0 si 1023 sunt valorile maxime de pe axele x si y ale joystick-ului.
  sS=0;
  switch (sSX) {
  case 0:
  sS=1;      // Stanga
  break;
  case 1023:
  sS=2;      // Dreapta
  break;
}
switch (sSY) {
  case 0:
  sS=3;      // Sus
  break;
  case 1023:
  sS=4;      // Jos
  break;
}

  digitalWrite(ledPins[rNum], LOW); //se stinge led-ul ales random, dupa ce s-a ales de la joystick.
  if (sS-1==rNum) //se verifica daca aleagerea jucatorului este corecta.
  {
    wins=wins+1;
    for (int k=0; k<=3; k++) {     //se aprinde led-ul verde daca alegerea este corecta
    digitalWrite(ledPins[4], HIGH);
    delay(50);
    digitalWrite(ledPins[4], LOW);
    delay(50);
    }
  }
  else
  {
    if (wins>highScore) {
        highScore=wins;
    }
    wins=0;
    for (int i=0; i<=3; i++) {       //se aprinde led-ul rosu daca optiunea aleasa este gresita
      digitalWrite(ledPins[5], HIGH);
      delay(50);
      digitalWrite(ledPins[5], LOW);
      delay(50);
    }
    for (int w=0; w<highScore; w++) { //se afiseza scorul prin aprinderea led-ului alb de atatea ori cate runde au fost castigate
        digitalWrite(ledPins[6], HIGH);
        delay(200);
        digitalWrite(ledPins[6], LOW);
        delay(200);
    }  
  }  
  }
