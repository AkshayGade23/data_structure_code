
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 // attach pin D3 Arduino to pin Trig of HC-SR04                                          \
 
 
long duration; 
int distance; 
void setup()
{
    pinMode(trigPin,
            OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
 
    // Serial Communication is starting with 9600 of
    // baudrate speed
    Serial.begin(9600);

    Serial.println(
        "Distance measurement using Arduino Uno.");
    delay(500);
}
 
void loop()
{

   digitalWrite(trigPin,LOW); // turn on the Trigger to generate pulse
    delayMicroseconds(10);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(2); 
 
    digitalWrite(trigPin,LOW); 

    duration = pulseIn(echoPin,HIGH);
    distance = duration * 0.0344 / 2; 
 
    Serial.print("Distance: ");
    Serial.print(distance); 
    Serial.println(" cm");
    delay(100);
}