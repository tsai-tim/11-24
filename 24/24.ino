const boolean data[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
};
byte seg[7] = {2,3,4,5,6,7,8};
byte scan[4] = {12,11,10,9};
byte number[4];
void setup() {
    pinMode(A1,INPUT);
  for(int i=0;i<7;i++)
    pinMode(seg[i],OUTPUT);  
  for(int i=0;i<4;i++)
    pinMode(scan[i],OUTPUT);  
}

unsigned long oldtime=millis();
int i=0;
void loop() {
  i=analogRead(A1);
  number[3]= i /1000;
  number[2]= (i - number[3] * 1000) / 100;
  number[1]= (i - number[3] * 1000-number[2]*100) / 10;
  number[0]= i % 10;
  for(int j= 3;j>0;j--)
    Serial.print(number[j]);
  Serial.println('.');    
  for(int j=0;j<4;j++)
    { 
      disp(number[j]); //查7段顯示器的顯示碼               
      digitalWrite(scan[j],HIGH);
      delay(5);
      digitalWrite(scan[j],LOW);          
     } 
}

void disp(int num)
{
  for(int i=0;i<7;i++)
    digitalWrite(seg[i],data[num][i]);
}
