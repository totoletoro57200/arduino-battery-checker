//Script by github.com/totoletoro57200
//9 volts version
//WARNING THIS IS A PROTOTYPE, DO NOT USE IN PRODUCTION FOR NOW



#define RLed 1; //Red led pin
#define OLed 2; //Orange led pin
#define GLed 3; //Green led pin
#define VoltSensor 0; //Voltage sensor pin (in analog)

float vPow = 4.7; //AtMega 2560 voltage (Arduino Mega), TBT on Uno
float r1 = 0; //R1 value (5 = 9*(R2/(R1+R2)))
float r2 = 0; //R2 value

void setup() {
    Serial.begin(9600);
    Serial.println("Maximum Voltage: " + (int)(vPow / (r2 / (r1 + r2))) + " V");
}

void loop() {
    float v = (analogRead(VoltSensor) * vPow) / 1024.0;
    float v2 = v / (r2 / (r1 + r2)); //Voltage calculation

    if(v2 > 7) {
        clearLights(GLed);
        digitalWrite(GLed, HIGH);
    }else if(v2 > 6) {
        clearLights(OLed);
        digitalWrite(OLed, HIGH);
    }else{
        clearLights(RLed);
        digitalWrite(RLed, HIGH);
    }
}

void clearLights(int ignored) {
    int[] leds = RLed, OLed, GLed;
    for(int i = 0; i <= 2; i++){
        if(leds[i] != ignored){
            digitalWrite(leds[i], LOW);
        }
    }
}
