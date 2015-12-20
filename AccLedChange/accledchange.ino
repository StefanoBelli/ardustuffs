/*Accellerometer*/
const int x_axis_pin = A2;
const int y_axis_pin = A1;
const int z_axis_pin = A0;
/*Led ~PWM*/
const int red_led_x = 11;
const int yellow_led_y = 10;
const int green_led_z = 9;
/*Initial values*/
static int x_get_initial_value,y_get_initial_value,z_get_initial_value;

void setup()
{
 Serial.begin(9600);
 Serial.print("Initializing output...");
 Serial.println();
 pinMode(red_led_x, OUTPUT);
 pinMode(yellow_led_y,OUTPUT);
 pinMode(green_led_z,OUTPUT);
 x_get_initial_value = analogRead(x_axis_pin);
 y_get_initial_value = analogRead(y_axis_pin);
 z_get_initial_value = analogRead(z_axis_pin);
 Serial.print("Initial value (x):\t ");
 Serial.print(x_get_initial_value);
 Serial.println();
 Serial.print("Initial value (y):\t ");
 Serial.print(y_get_initial_value);
 Serial.println();
 Serial.print("Initial value (z):\t ");
 Serial.print(z_get_initial_value);
 Serial.println();
 delay(1500);
}

void loop()
{
 int x_axis, y_axis, z_axis;
 /*X*/
 x_axis=analogRead(x_axis_pin);
 if(x_axis > x_get_initial_value)
 {
  digitalWrite(red_led_x,HIGH);
  analogWrite(red_led_x,100);
  delay(100);
  analogWrite(red_led_x,x_axis);
  delay(100);
 }
 else if(x_axis < x_get_initial_value)
  digitalWrite(red_led_x,LOW);
  
 /*Y*/
 y_axis=analogRead(y_axis_pin);
 if(y_axis > y_get_initial_value)
 {
  digitalWrite(yellow_led_y,HIGH);
  analogWrite(yellow_led_y,100);
  delay(100);
  analogWrite(yellow_led_y,y_axis);
  delay(100);
 }
 else if(y_axis < y_get_initial_value)
  digitalWrite(yellow_led_y,LOW);

 /*Z*/
 z_axis=analogRead(z_axis_pin);
 if(z_axis > z_get_initial_value)
 {
  digitalWrite(green_led_z,HIGH);
  analogWrite(green_led_z,100);
  delay(100);
  analogWrite(green_led_z,z_axis);
  delay(100);
 }
 else if(z_axis < z_get_initial_value)
  digitalWrite(green_led_z,LOW);

 /*Printing values*/
 Serial.print("x: ");
 Serial.print(x_axis);
 Serial.print("\ty: ");
 Serial.print(y_axis);
 Serial.print("\tz: ");
 Serial.print(z_axis);
 Serial.println();

 /*200 ms refresh rate*/
 delay(200);
}
