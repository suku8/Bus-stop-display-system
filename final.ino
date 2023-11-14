#include <TinyGPS++.h>
#include <Wire.h> 
#include <math.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2); 
TinyGPSPlus gps;
void getgps(TinyGPSPlus &gps);
float la,lo,t1,t2;
long int lt,lg;
int i;
#define button1 7
bool button_State;
char p[12][50]={"KARUMATHAMPATTI","KANIYUR","NEELAMBUR","CHINNAYAMPALAYAM","KMCH","SITRA","ARAVIND","CIT","HOPES","PSG HOSPITAL","PEELAMEDU"};

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}

void getgps(TinyGPSPlus &gps)
{
  if (gps.location.isValid() and gps.date.isValid() and gps.time.isValid())
  {
    la=gps.location.lat();
    lo=gps.location.lng();
    Serial.print("Latitude: ");
    Serial.println(la,20);
    Serial.print("Longitude: ");
    Serial.println(lo);    
    t1=round(la*1000);
    lt=(long int) t1; 
    t2=round(lo*1000);
    lg=(long int) t2;       
    if(lt==11107 and lg==77177)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("TRIP STARTS");
      delay(5000);      
      lcd.clear();     
      lcd.setCursor(0,0);
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print("KANIYUR");      
      delay(2000);           
    }
    else if(lt==11095 and lg==77152)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print(p[i+2]);
      delay(2000);      
    }                
    else if(lt==11061 and lg==77086)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print(p[i+3]);
      delay(2000);      
    }                
    else if(lt==11055 and lg==77065)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print(p[i+4]);
      delay(2000);      
    }                
    else if(lt==11040 and lg==77041)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print(p[i+5]);
      delay(2000);      
    }                
    else if(lt==11039 and lg==77038)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print(p[i+6]);
      delay(2000);      
    }                
    else if(lt==11035 and lg==77034)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print(p[i+7]);
      delay(2000);      
    }                
    else if(lt==11028 and lg==77025)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print(p[i+8]);
      delay(2000);      
    }                    
    else if(lt==11026 and lg==77019)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print(p[i+9]);
      delay(2000);      
    }                
    else if(lt==11025 and lg==77008)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print(p[i+10]);
      delay(2000);      
    }
    else if(lt==11023 and lg==77001)
    {
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("RETURN TRIP");
      delay(5000);            
      lcd.clear(); 
      lcd.setCursor(0,0); 
      lcd.print("NEXT STOP:");
      lcd.setCursor(0,1);
      lcd.print("PSG HOSPITAL");
      delay(2000);      
    }    
    else
    {
      lcd.clear(); 
      lcd.setCursor(0,0);
      lcd.print(lt);
      lcd.setCursor(0,1);
      lcd.print(lg);                    
      
    }                     
  }
}    
    

void loop() {
  // put your main code here, to run repeatedly:
  button_State = digitalRead(button1);   //We are constantly reading the button State
 
  i=0;
  byte a;
  if (Serial.available() > 0 )
  {
    a = Serial.read();
    if (gps.encode(a))
    {
      if (button_State == LOW)          //PRESSED
      {            
        Serial.println("TRIP STARTS");
        i=0;   
        delay(200);
      }
      else
      {
        Serial.println("RETURN TRIP");
        i=-2;   
        delay(200);  
      }       
      getgps(gps);
    }
  }
}