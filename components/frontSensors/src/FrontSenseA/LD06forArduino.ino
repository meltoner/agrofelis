#include "LD06forArduino.h"

void LD06forArduino::Init(const int pin) {
  Serial2.begin(230400, SERIAL_8N1, pin);
}

void LD06forArduino::calc_lidar_data(std::vector<char> &values) {

  start_byte = values[0];
  data_length = 0x1F & values[1];
  Speed = float(values[3] << 8 | values[2]) / 100;
  FSA = float(values[5] << 8 | values[4]) / 100;
  LSA = float(values[values.size() - 4] << 8 | values[values.size() - 5]) / 100;
  time_stamp = int(values[values.size() - 2] << 8 | values[values.size() - 3]);
  CS = int(values[values.size() - 1]);

  if (LSA - FSA > 0) {
    angle_step = (LSA - FSA) / (data_length - 1);
  } else {
    angle_step = (LSA + (360 - FSA)) / (data_length - 1);
  }

  // note: 刻み幅の異常を検知
  if (angle_step > 20) {
    return;
  }

  // note: 過去のデータを初期化
  angles.clear();
  confidences.clear();
  distances.clear();

  for (int i = 0; i < data_length; i++) {
    float raw_deg = FSA + i * angle_step;
    angles.push_back(raw_deg <= 360 ? raw_deg : raw_deg - 360);
    confidences.push_back(values[8 + i * 3]);
    distances.push_back(int(values[8 + i * 3 - 1] << 8 | values[8 + i * 3 - 2]));

  }
}

std::vector<char> tmpChars;

void LD06forArduino::read_lidar_data() {

  // note: Serial２が機能していない場合はスキップ
  if (!Serial2.available()) {
    return;
  }

  bool loopFlag = true;
  char tmpInt;

  while (loopFlag) {
    tmpInt = Serial2.read();

    if (tmpInt == 0x54 && tmpChars.empty()) {
      tmpChars.push_back(tmpInt);
      continue;
    } else if (tmpChars.size() == TOTAL_DATA_BYTE - 1 ) {

      loopFlag = false;
      calc_lidar_data(tmpChars);
      tmpChars.clear();
      continue;

    } else if (tmpChars.size() > 0) {
      if (tmpChars[0] == 0x54) {
        tmpChars.push_back(tmpInt);
      }
      if (tmpChars.size() > 1) {
        if (tmpChars[1] != 0x2C) {
          tmpChars.clear();
        }
      }
    }
  }
}

void LD06forArduino::print(){
  Serial.print("[");
  for (int i = 0; i < ld06.data_length; i++) {
    Serial.printf("%.2f,%.0f", ld06.angles[i],  ld06.distances[i]);
    if(i!= ld06.data_length -1)
      Serial.print("|");
  }
  Serial.print("]");
  Serial.println();
}
 