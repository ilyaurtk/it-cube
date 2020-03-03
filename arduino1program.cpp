int firstPin = 3;   // Пин, который отправляет сигнал
int secondPin = 2;  // Пин, который принимает сигнал
int ledPin = 13;    // Светодиод
 
void setup() 
{
  pinMode(secondPin, OUTPUT);
  pinMode(firstPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  int ms = getDeltaTime();
  if(ms > 100){
    digitalWrite(ledPin,HIGH);
  }else{
    digitalWrite(ledPin,LOW);
  }
  delay(10);
}
 
int getDeltaTime()
{
  int time_start=0; 
  int time_finish = 0;
  int time_delta = 0;
   
  time_start = micros(); // Количество микросекунд со старта программы
  digitalWrite(secondPin, HIGH); // Отправляем сигнал 
  while(digitalRead(firstPin) == LOW); // Джем пока дойдет сигнал от одного пина к другому
  time_finish = micros(); // Еще раз смотрим сколько прошло микросекунд со старта программы                 
  time_delta = time_finish - time_start; // Высчитываем сколько микросекунд ушло на передачу сигнала между пинами
  digitalWrite(secondPin, LOW); // Останавливаем передачу сигнала
   
  Serial.println(time_delta);
  return time_delta;    
}