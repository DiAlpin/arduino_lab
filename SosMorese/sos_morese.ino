
// variables
int pin_no=9;

int ref_time=500;
int dyh;
int dyl;
int stp = 0;
int myList[] = {1, 2, 3, 5, 6, 7, 9, 10, 11};
int listLength = sizeof(myList) / sizeof(myList[0]);

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_no, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    // Wait for serial port to connect
  }
}

void loop() {
if (stp == 0 || stp == 8) {
  dyh = ref_time*1;
  dyl = dyh;
  stp = stp + 1;
}
if (stp == 4) {
  dyh = ref_time*3;
  dyl = ref_time*1;
  stp = stp + 1;
}
if (stp == 12) {
  dyh = 0;
  dyl = ref_time*10;
  stp = 0;
}

for (int i = 0; i < listLength; i++) {
  if (myList[i] == stp) {
    stp = stp + 1;
    break; // Exit the loop early if variable is found
  }
}


Serial.print("stp value: ");
Serial.println(stp);

digitalWrite(pin_no, HIGH);
delay(dyh);
digitalWrite(pin_no, LOW);
delay(dyl);
}
