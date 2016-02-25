const int btn = 8; //pulsante
const int led = 9; //led
unsigned int contatore = 30; //var. utilizzata per diminuire ritardo (da 30)

void setup()
{
  //impostazione pulsanti
  pinMode(btn,INPUT); 
  pinMode(led,OUTPUT); 
  Serial.begin(9600); //porta seriale per ricevimento dati
}

void loop()
{  
  int btn_s = digitalRead(btn); //leggi il valore del pulsante (se premuto o meno)
  if(btn_s == HIGH) { //se il pulsante è premuto...
    contatore--; //decrementa contatore 
    Serial.print("[i]pulsante: premuto\n"); //scrivi informazione
  }
  
  digitalWrite(led,HIGH); //accendi
  //Moltiplica contatore per 10, per ottenere un ritardo maggiore
  delay(contatore * 10); 
  digitalWrite(led,LOW); //spegni
  delay(contatore * 10);

  //Scrivi informazione sul valore di contatore 
  Serial.print("[!]stato: "); 
  Serial.print(contatore);
  Serial.print(" ; ritardo: ");
  Serial.print(contatore * 10);
  Serial.print('\n');

  //riporta contatore a 30, se arriva a 0
  if(contatore == 0) contatore = 30; 
}

