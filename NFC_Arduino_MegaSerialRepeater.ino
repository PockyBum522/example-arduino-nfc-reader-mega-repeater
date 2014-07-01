void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int inByte = Serial1.read();

  if (inByte > 0) { //If we see data (inByte > 0) and that data isn't a carriage return
    delay(50); //Allow serial data time to collect (I think. All I know is it doesn't work without this.)

    while (Serial1.available() > 0){ // As long as EOL not found and there's more to read, keep reading
      inByte = Serial1.read(); // Read next byte
      Serial.println(inByte);
    }
  }
}

