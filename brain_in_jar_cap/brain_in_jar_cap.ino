
/**Must include the Adafruit_CircuitPlayground.h**/
#include <Adafruit_CircuitPlayground.h>
    
int soil_reading;  
int dry_value = 20; //similar to threshold, change the value to work with different type of soil
void setup() {
  Serial.begin(9600); // Starting the serial monitor
  CircuitPlayground.begin(); // Initializing the Circuit Playground
  
} 
void loop (){
   soil_reading = CircuitPlayground.readCap(12); // Read the Soil Sensor
   Serial.println(soil_reading); // print out these values
  if (soil_reading <= dry_value){
    for (int i=0; i<10; i++){
      CircuitPlayground.setPixelColor(i, 255, 255, 255); // turn on all neon pixels and set them to white
      
    }
  }
    else{
      for (int i = 10; i >= 0 ; i--) { 
      CircuitPlayground.setPixelColor(i, 255, 0, 0);
     
    }
  }
}
