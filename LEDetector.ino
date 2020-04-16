// maps analogPin to PE3
int analogPin = 29;

// mapping Red to PD6, Green to PD7, blue to PF4
int RED = 33, GREEN = 32, BLUE = 31;

// initializing values for LED
int redVal;
int greenVal;
int blueVal;
int delayTime = 5;

void setup()
{
  // sets up pin mode for photoresistor.
  Serial.begin(9600); // initialize serial communication for photoresistor
  pinMode(analogPin, OUTPUT);

  // sets up pinMode for LED
   pinMode(RED, OUTPUT);
   pinMode(GREEN, OUTPUT);
   pinMode(BLUE, OUTPUT);
}


void loop()
{
  int lightLevel = analogRead(analogPin); // Read the light level from analog pin 2
  int PWM_RESOLUTION = 255; // this variable will hold our resolution.
  Serial.println(lightLevel); // Print the analog value to Serial

  // default mode is off, unless triggered by moving person
   int greenVal = PWM_RESOLUTION; // max voltage will give us no color
   int blueVal = PWM_RESOLUTION;
   int redVal = PWM_RESOLUTION;
   analogWrite( RED, redVal );
   analogWrite( GREEN, greenVal );
   analogWrite( BLUE, blueVal ); 

     // the darker the environment, the greater the reading of resistance in ohms
    if (lightLevel > 570) {


      // Turns on the rainbow LED
      for (int i; i < 2; i += 1){
    
         // full red
         int redVal = 0; // zero voltage will give us full color
         int greenVal = PWM_RESOLUTION; // max voltage will give us no color
         int blueVal = PWM_RESOLUTION; // max voltage will give us no color
         analogWrite( RED, redVal );
         analogWrite( GREEN, greenVal );
         analogWrite( BLUE, blueVal );
        
         // Fade from red to green
         for( int i = 0 ; i < PWM_RESOLUTION ; i += 1 ){
           greenVal -= 1;
           redVal += 1;
           analogWrite( RED, redVal ); // set the new red value
           analogWrite( GREEN, greenVal ); // set the new green value
          
           delay( delayTime ); // wait for how long delay time is
         }
        
         // full green
         redVal = PWM_RESOLUTION; // max voltage will give us no color
         greenVal = 0; // zero voltage will give us full color
         blueVal = PWM_RESOLUTION; // max voltage will give us no color
         analogWrite( RED, redVal );
         analogWrite( GREEN, greenVal );
         analogWrite( BLUE, blueVal );
      
         // Fade from green to blue 
         for( int i = 0 ; i < PWM_RESOLUTION ; i += 1 ){
           blueVal -= 1;
           greenVal += 1;
           analogWrite( BLUE, blueVal ); // set the new blue value
           analogWrite( GREEN, greenVal ); // set the new green value
          
           delay( delayTime ); // wait for how long delay time is
         }
        
         // full blue
         redVal = PWM_RESOLUTION; // max voltage will give us no color
         greenVal = PWM_RESOLUTION; // max voltage will give us no color
         blueVal = 0; // zero voltage will give us full color
         analogWrite( RED, redVal );
         analogWrite( GREEN, greenVal );
         analogWrite( BLUE, blueVal );
      
         // fade from blue to red 
         for( int i = 0 ; i < PWM_RESOLUTION ; i += 1 ){
           redVal -= 1;
           blueVal += 1;
           analogWrite( RED, redVal ); // set the new red value
           analogWrite( BLUE, blueVal ); // set the new blue value
          
           delay( delayTime ); // wait for how long delay time is
      }
    }
  }
  delay(100); // delay for 1 second
 }
