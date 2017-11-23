#pragma once
#ifdef __cplusplus
extern "C"{
#endif
#include <stdint.h>

typedef void* voidstar;

char* createrawtransaction(voidstar f,const char* reqjson);
#ifdef __cplusplus
}
#endif
