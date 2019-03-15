#define enA 9
#define in1 6
#define in2 7
#define enB 8
#define in3 4
#define in4 5
#define fanpin 10
#define ldrupin A0
#define ldrdpin A1
int ldru=0,ldrd=0,curr=0;
boolean clothes = true;
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(fanpin,OUTPUT);
  digitalWrite(fanpin,LOW);
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.begin(9600);
}
void clockw(){
  digitalWrite(enA,HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
void anticlw(){
  digitalWrite(enA,HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
void dow(){
  digitalWrite(enB,HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
    delay(500);
  digitalWrite(enB,LOW);
}
void up(){
  digitalWrite(enB,HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
    delay(450);
   digitalWrite(enB,LOW);
}
boolean israin(String s){
  for(int i=0;i<s.length()-3;++i){
    if(s[i]=='R'&&s[i+1]=='a'&&s[i+2]=='i'&&s[i+3]=='n')
      return false;
  }  
  return true;
}
void light(){
 /*if(ldru>ldrd && curr==1  && ldrd<=15){
  dow();
 //anticlw();
  curr=0;
  //delay(250);
  digitalWrite(enB,LOW);
 }
 else if(ldru<ldrd && curr==0 && ldrd-ldru>=100){
  up();
  //clockw();
  curr=1;
  //delay(250);
  digitalWrite(enB,LOW);
 }*/
 if(ldrd>100){
  up();
 }
 else if(ldrd<=15){
  dow();
 }
}
void loop() {
  String s="{cod:200,message:0.0059,cnt:40,list:[{dt:1551711600,main:{temp:290.05,temp_min:289.647,temp_max:290.05,pressure:1009.31,sea_level:1009.31,grnd_level:984.39,humidity:79,temp_kf:0.41},weather:[{id:500,main:Rain,description:light rain,icon:10n}],clouds:{all:36},wind:{speed:4,deg:337.501},rain:{3h:0.27},sys:{pod:n},dt_txt:2019-03-04 15:00:00},{dt:1551722400,main:";
  String s1="{cod:200,message:0.0059,cnt:40,list:[{dt:1551711600,main:{temp:290.05,temp_min:289.647,temp_max:290.05,pressure:1009.31,sea_level:1009.31,grnd_level:984.39,humidity:79,temp_kf:0.41},weather:[{id:500,main:ain,description:light rain,icon:10n}],clouds:{all:36},wind:{speed:4,deg:337.501},rain:{3h:0.27},sys:{pod:n},dt_txt:2019-03-04 15:00:00},{dt:1551722400,main:" ;
 //Serial.println("Curr: "+curr);
 if(israin(s)){
  clockw();
  digitalWrite(fanpin,HIGH);
  delay(3000);
 // digitalWrite(enA,LOW);
  delay(10000);
  digitalWrite(enA,LOW);
  digitalWrite(fanpin,LOW);
  delay(3000);
  digitalWrite(enA,LOW);
  delay(10000);
 }
 ldru = analogRead(ldrupin);
 ldrd = analogRead(ldrdpin);
 Serial.println(ldrd);
 light();
 
}
