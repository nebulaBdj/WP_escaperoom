// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일

#include "pch.h"
bool m_nBedroomItemGet = FALSE;
bool bedRoom_key = FALSE;
int mirror_count = 0;
bool door_step_isMirror = FALSE;
bool bedroom_isMirror = FALSE;
bool library_isMirror = FALSE;
bool secret_room_per = FALSE; 

extern bool mirror1_observer_once = FALSE;
extern bool mirror2_observer_once = FALSE;
extern bool mirror3_observer_once = FALSE;
extern bool bedroom_observer_once = FALSE;
bool secret_room_observer_once = FALSE;
// 미리 컴파일된 헤더를 사용하는 경우 컴파일이 성공하려면 이 소스 파일이 필요합니다.
