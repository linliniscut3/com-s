#define IR_IN 2

int lastStatusIrIn = HIGH;  // Initialize to HIGH to indicate no object detected
int userCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IR_IN, INPUT);
}

void loop() {
  int currentStatusIrIn = digitalRead(IR_IN);

  if (currentStatusIrIn == LOW && lastStatusIrIn == HIGH) {
    userCount++;
    Serial.print("New user entered. Total users: ");
    Serial.println(userCount);
  }

  lastStatusIrIn = currentStatusIrIn;  // Update last status
}
