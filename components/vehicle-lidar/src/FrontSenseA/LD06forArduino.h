#ifndef LD06_FOR_ARDUINO
#define LD06_FOR_ARDUINO
#include <vector>

class LD06forArduino
{
  private:
    // note: 12 data *3 Byte
    const int DATA_BYTE = 36;
    // note: 1(Start)+2(Datalen)+2(Speed)+2(SAngle)+36(DataByte)+2(EAngle)+2(TimeStamp)+1(CRC)
    const int TOTAL_DATA_BYTE = 48;

    void calc_lidar_data(std::vector<char> &values);
  public:
    std::vector<float> angles;
    std::vector<float> distances;
    std::vector<int> confidences;

    char start_byte;
    char data_length;
    float Speed;
    float FSA;
    float LSA;
    int time_stamp;
    int CS;
    float angle_step;

    void Init(const int pin);
    void read_lidar_data();
    void print();
};

#endif
