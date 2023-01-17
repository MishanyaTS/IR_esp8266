#include <IRremoteESP8266.h>
#include <IRutils.h>

const uint16_t kRecvPin = 2; // D4, ПИН ИК приемника
IRrecv irrecv(kRecvPin);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();  // Инициализируем ИК приемник
}

void loop() {
  if (irrecv.decode(&results)) { // Если данные пришли, то выполняем код ниже
    serialPrintUint64(results.value, HEX); // Вывод в консоль
    Serial.println("");
    irrecv.resume(); // Принимаем следующий сигнал от приемника
  }
  delay(50);
}
