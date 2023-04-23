
// DRONE PROTON RC TANK CODES

const int sol_enable = 11;  // ENABLE A
const int sag_ileri = 10;   // INPUT 1
const int sag_geri = 9;     // INPUT 2
const int sol_ileri = 8;    // INPUT 3
const int sol_geri = 7;     // INPUT 4
const int sag_enable = 6;   // ENABLE B

void setup(){
pinMode(sag_ileri, OUTPUT);
pinMode(sag_geri, OUTPUT);
pinMode(sol_ileri, OUTPUT);
pinMode(sol_geri, OUTPUT);
pinMode(sag_enable, OUTPUT);
pinMode(sol_enable, OUTPUT);
Serial.begin(9600);
}

void loop() {
if (Serial.available() > 0) {
char gelen_veri = Serial.read();
Serial.println(gelen_veri);

if( gelen_veri == 'R' ) { // gelen_veri 'R' ise / if incoming_data is 'R'
/* araç geri gitsin / get the car back */
digitalWrite(sag_ileri, 1);
digitalWrite(sag_geri, 0);
digitalWrite(sol_ileri, 1);
digitalWrite(sol_geri, 0);
analogWrite(sag_enable, 255); // motor hızı / engine speed
analogWrite(sol_enable, 255);
}

if( gelen_veri == 'F' ) { // gelen_veri 'F' ise / if incoming_data is 'F'
/* araç sola dönsün / get the car left*/
digitalWrite(sag_ileri, 0);
digitalWrite(sag_geri, 1);
digitalWrite(sol_ileri, 1);
digitalWrite(sol_geri, 0);
analogWrite(sag_enable, 255); // motor hızı / engine speed
analogWrite(sol_enable, 255);
}

if( gelen_veri == 'B' ) { // gelen_veri 'B' ise / if incoming_data is 'B'
/* araç sağa dönsün / get the car Right  */
digitalWrite(sag_ileri, 1);
digitalWrite(sag_geri, 0);
digitalWrite(sol_ileri, 0);
digitalWrite(sol_geri, 1);
analogWrite(sag_enable, 255); // motor hızı / engine speed
analogWrite(sol_enable, 255);
}

if( gelen_veri == 'L' ) { // gelen_veri 'L' ise / if incoming_data is 'L'
/* araç ileri gitsin / get the car forward */
digitalWrite(sag_ileri, 0);
digitalWrite(sag_geri, 1);
digitalWrite(sol_ileri, 0);
digitalWrite(sol_geri, 1);
analogWrite(sag_enable, 255); // motor hızı / engine speed
analogWrite(sol_enable, 255);
}


if( gelen_veri == 'S' ) { // gelen_veri 'S' ise / if incoming_data is 'S'
/* araç dursun / get the car stop */
digitalWrite(sag_ileri, 0);
digitalWrite(sag_geri, 0);
digitalWrite(sol_ileri, 0);
digitalWrite(sol_geri, 0);
}
}
}
