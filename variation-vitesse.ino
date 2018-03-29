  #define LEDC_TIMER_13_BIT  13         
  #define LEDC_BASE_FREQ     50000
  #define LEDC_CHANNEL_0     0
  int dutyCycle = 0;
  int vitesse = 0;
  int fadeAmount = 5;
  void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 255) {
       uint32_t duty = (8191 / valueMax) * min(value, valueMax);
       ledcWrite(channel, duty);
  //#define MOTOR_PWM_CHANNEL_LEDC_CHANNEL_1
  }
void setup() { //http://lacavernedelucan.com/laop-lm324/
  // put your setup code here, to run once:
  pinMode(25,INPUT_PULLUP);
  pinMode(26,INPUT_PULLUP);
  pinMode(17,OUTPUT);
  pinMode(16,OUTPUT);
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(4, LEDC_CHANNEL_0);
  
}

void loop() {
  ledcAnalogWrite(LEDC_CHANNEL_0, vitesse);      
  vitesse = 180; 
  int valeur_recup = 0;
      valeur_recup = analogRead(A5);
  if ((valeur_recup >= 0) && (digitalRead(26)== 0) && (valeur_recup <= 4095))
      {
      digitalWrite(17,HIGH);
      }
  else if((valeur_recup <= 4095) && (digitalRead(25)==0) && (valeur_recup >= 0))
      {
      digitalWrite(16,HIGH);
      }
  else {
        digitalWrite(16,LOW);
        digitalWrite(17,LOW);
        }

}
