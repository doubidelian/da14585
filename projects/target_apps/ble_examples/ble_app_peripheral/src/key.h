#ifndef KEY_H
#define KEY_H

#include "types.h"

//���� "�������� ��������Ӳ���Զ�����
//��ס�����3�룬��ʾ������ַ
//��������� �������� ˫������� ����ۼ�
//����������3��,�ػ�.

typedef enum{
	KEY_ZERO=0,
	KEY_PWR,
	KEY_ALL
}key_code_t;
#define KEY_PRESSED 1
#define KEY_LONG_PRESSED 2
#define KEY_RELEASE 0

typedef struct key_msg{
	uint8 key;
	uint8 event;
	uint8 invalid;
}key_msg_t;

typedef void(*key_event_func_t)(key_msg_t* event);

//�ػ�.
void  key_power_off(void);
//���ؼ��Ƿ��������סn��
void  is_pwr_key_pressed(uint8 s);
//������Ƿ��������סn��
void  is_zero_key_pressed(uint8 s);

void  is_zero_key_clicked(uint8 s);

void  is_zero_key_double_clicked(uint8 s);

void  key_isr(void);
void  key_register(key_event_func_t cb);

uint8  key_get_msg(key_msg_t* msg);
#endif
