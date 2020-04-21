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
  int lightLevel = analogRead(analogPin); // Read the light level
  int MAX_RES = 255; // this variable will hold our resolution.
  Serial.println(lightLevel); // Print the analog value to Serial (used to test sensor)

  // default mode is off, unless triggered by moving person
   int greenVal = MAX_RES; // max voltage will give us no color
   int blueVal = MAX_RES;
   int redVal = MAX_RES;
   analogWrite( RED, redVal );
   analogWrite( GREEN, greenVal );
   analogWrite( BLUE, blueVal ); 

     // the darker the environment, the greater the reading
    if (lightLevel > 570) {


      // Turns on the rainbow LED
      for (int i; i < 2; i += 1){
    
         // begins as full red
         int redVal = 0; 
         int greenVal = MAX_RES;
         int blueVal = MAX_RES; 
         analogWrite( RED, redVal );
         analogWrite( GREEN, greenVal );
         analogWrite( BLUE, blueVal );
        
         // Changes from red to green
         for( int i = 0 ; i < MAX_RES ; i += 1 ){
           greenVal -= 1;
           redVal += 1;
           analogWrite( RED, redVal ); // sets to redVal
           analogWrite( GREEN, greenVal ); // sets to greenVal
          
           delay( delayTime ); // wait for how long delay time is
         }
        
         // changes to full green
         redVal = MAX_RES; 
         greenVal = 0; 
         blueVal = MAX_RES; 
         analogWrite( RED, redVal );
         analogWrite( GREEN, greenVal );
         analogWrite( BLUE, blueVal );
      
         // Change from green to blue 
         for( int i = 0 ; i < MAX_RES ; i += 1 ){
           blueVal -= 1;
           greenVal += 1;
           analogWrite( BLUE, blueVal ); // sets blueVal
           analogWrite( GREEN, greenVal ); // sets greenVal
          
           delay( delayTime ); // wait for how long delay time is
         }
        
         // changes to full blue.
         redVal = MAX_RES; 
         greenVal = MAX_RES; 
         blueVal = 0; 
         analogWrite( RED, redVal );
         analogWrite( GREEN, greenVal );
         analogWrite( BLUE, blueVal );
      
         // fade from blue to red 
         for( int i = 0 ; i < MAX_RES ; i += 1 ){
           redVal -= 1;
           blueVal += 1;
           analogWrite( RED, redVal ); // sets redVal
           analogWrite( BLUE, blueVal ); // sets blueVal
          
           delay( delayTime ); // wait for how long delay time is
      }
    }
  }
  delay(100); // delay for 0.1 seconds
 }
