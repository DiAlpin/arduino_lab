
// variables
int nr;
int ledList[] = {3, 5, 6, 9};
int ledListLen = sizeof(ledList) / sizeof(ledList[0]);


void setup() {
  // put your setup code here, to run once:
  pinMode(ledList[0], OUTPUT);
  pinMode(ledList[1], OUTPUT);
  pinMode(ledList[2], OUTPUT);
  pinMode(ledList[3], OUTPUT);

  Serial.begin(9600);
  while (!Serial) {
    // Wait for serial port to connect
  }
}

void loop() {

int binaryList[4];
convertToBinary(nr, binaryList);

for (int i = 0; i < ledListLen; i++) {
  analogWrite(ledList[i], binaryList[i] * 255);
}
delay(100);
for (int i = 0; i < ledListLen; i++) {
  analogWrite(ledList[i], binaryList[i] * 0);
}
delay(60);

Serial.print("Binary: ");
// Serial.print(nr);
Serial.print(" [");
Serial.print(binaryList[0]);
Serial.print("|");
Serial.print(binaryList[1]);
Serial.print("|");
Serial.print(binaryList[2]);
Serial.print("|");
Serial.print(binaryList[3]);
Serial.println("]");

nr ++;

if (nr == 16) {
  delay(3000);
  nr = 0;
}


}

void convertToBinary(int number, int binaryList[]) {
  for (int i = 3; i >= 0; i--) {
    binaryList[i] = number % 2;
    number = number / 2;
  }
}




