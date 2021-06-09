/* ------------ REGA AUTONOMA ------------ */
//Programa desenvolvido para a disciplina de Intrododução a engenharia de computação

#define SensorUmipinoA A0 //Definindo pino analogico do sensor de umidade
#define SensorUmipinoD 2 //Definindo pino digital do sensor de umidade
#define Buzzer 4 //Defininfo pino digital buzzer
int tempoChec = 3600*1000;

void setup() 
{ 
  pinMode(SensorUmipinoD, INPUT); //Definindo o pino 2 como pino de entrada
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600); //Porta serial, taxa de dados 9600 bps(bits por segundo)  
}

void loop() 
{
  
  tempoChec = 3600*1000;
  Serial.print("Digital : ");
  if(digitalRead(SensorUmipinoD))
   {
      Serial.print("Sem Umidade\n");
    }
  else{
      Serial.print("Com Umidade\n");
    }
    
  Serial.print("Analogico :");
  Serial.print(analogRead(SensorUmipinoA));
  Serial.print("\n");
  if (analogRead(SensorUmipinoA) < 370 && analogRead(SensorUmipinoA) >250)
  {
    //Nivel de umidade perfeito
    noTone(Buzzer);
    Serial.print("Nivel de umidade perfeita \n");
    }
  else if (analogRead(SensorUmipinoA)< 249)
  {
    //Muita umidade
    Serial.print("Muita umidade\n");
    }
  else
  {
    //Pouca umidade
    tone(Buzzer,392);//Alerta sonoro para indicar que a planta precisa de agua
    tempoChec = 1000;
    Serial.print("Pouca Umidade\n");
    }
    
  delay(tempoChec);
}
