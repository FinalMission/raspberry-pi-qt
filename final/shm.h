#ifndef SHM_H
#define SHM_H

#define KEY_SHM 0x2222
#define STATUS_INVALID 0
#define STATUS_VALID 0xbeafbeaf
#define TIMEOUT 30
#define MAX_BUF 64
#define ERROR -1
#define SEG1 0xffeeddcc
#define SEG2 0xbbaa9988
#define SEG3 0x77665544
#define PI0W1 "B8:27:EB:0C:CF:BD"
#define PI0W2 "B8:27:EB:4F:CF:45"
#define PI1 "00:1A:7D:DA:71:13"
typedef struct
{
  char addr[18];
  char rssi;
}Packet;



#define P_OFFSET sizeof(Packet)


#endif // SHM_H