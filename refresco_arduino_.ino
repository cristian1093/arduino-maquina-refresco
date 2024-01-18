#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo servo_coca;
Servo servo_pepsi;
Servo servo_fanta;

const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FILAS] = {13,12,11,10};
byte pinesColumnas[COLUMNAS] = {9,8,7,6};
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);


LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 


char TECLA;
char CLAVE[4];
char CLAVE_COCA[4] = "C23";
char CLAVE_PEPSI[4] = "B34";
char CLAVE_FANTA[4] = "A93";
byte INDICE = 0;

byte LCDcol = 0;
void setup() {
  servo_coca.attach(2);
  servo_pepsi.attach(3);
  servo_fanta.attach(4);
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(">Ingresa Codigo<"); 
  lcd.setCursor(0,1);
  lcd.print(""); 
}

void loop() {
  TECLA = teclado.getKey();
  if (TECLA){
    CLAVE[INDICE] = TECLA;
    INDICE ++;
     LCDcol++;
    Serial.print(TECLA);
    lcd.print(TECLA);
    lcd.setCursor(LCDcol,1);
   
  }

  if(INDICE == 3){
    if(!strcmp(CLAVE, CLAVE_COCA)){
      lcd.setCursor(0,0);
      lcd.setCursor(0,1);
      delay(1000);
      lcd.print("Entregando COCA");
      Serial.println(" Correcta COCA");
      servo_coca.write(0);
      delay(5000);
      servo_coca.write(180);
      lcd.clear();
      delay(5000);
      lcd.setCursor(0,0);
      lcd.print(">Ingresa Codigo<"); 
      lcd.setCursor(0,1);
      lcd.print(""); 
      LCDcol = 0;
      INDICE = 0;
    }else if(!strcmp(CLAVE, CLAVE_PEPSI)){
      lcd.setCursor(0,0);
      lcd.setCursor(0,1);
      delay(1000);
      lcd.print("Entregando PEPSI");
      Serial.println(" Correcta PEPSI");
      servo_pepsi.write(0);
      delay(5000);
      servo_pepsi.write(180);
      lcd.clear();
      delay(5000);
      lcd.setCursor(0,0);
      lcd.print(">Ingresa Codigo<"); 
      lcd.setCursor(0,1);
      lcd.print(""); 
      LCDcol = 0;
      INDICE = 0;
    }else if(!strcmp(CLAVE, CLAVE_FANTA)){
      lcd.setCursor(0,0);
      lcd.setCursor(0,1);
      delay(1000);
      lcd.print("Entregando FANTA");
      Serial.println(" Correcta FANTA");
      servo_fanta.write(0);
      delay(5000);
      servo_fanta.write(180);
      lcd.clear();
      delay(5000);
      lcd.setCursor(0,0);
      lcd.print(">Ingresa Codigo<"); 
      lcd.setCursor(0,1);
      lcd.print(""); 
      LCDcol = 0;
      INDICE = 0;
    }else{
      lcd.setCursor(0,0);
      lcd.setCursor(0,1);
      delay(1000);
      lcd.print("Codigo no Valido");
      Serial.println(" Codigo Incorrecto");
      delay(5000);
      lcd.clear();
      delay(2000);
      lcd.setCursor(0,0);
      lcd.print(">Ingresa Codigo<"); 
      lcd.setCursor(0,1);
      lcd.print(""); 
      LCDcol = 0;
      INDICE = 0;
    }
    
  }

}
