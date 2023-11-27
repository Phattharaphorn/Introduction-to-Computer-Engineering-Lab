#include <Wire.h>
int slaveAddress2 = 9;
char data[7];

void setup()
{
  Wire.begin(slaveAddress2);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop()
{
  delay(100);
}

// Get data from board 1
void receiveEvent(int bytes)
{
  while (Wire.available() > 0)
  {
    for (int i = 0; i < bytes; i++)
    {
      data[i] = Wire.read();
    }
  }
  data[5]++;
  if (data[5] > '9')
  {
    data[5] = '1';
  }
  Serial.println(data);
}

// Sent data to board 1
void requestEvent()
{
  Wire.write(data);
}