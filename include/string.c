#include "string.h"
#include "stddef.h"
uint8_t Strlen(char* ch){
    uint8_t i = 0;
	while(ch[i++]);
	return --i;
}
uint8_t strEql(char* ch1, char* ch2){
    uint8_t result = 0;
    uint8_t size = Strlen(ch1);
    if(size != Strlen(ch2)) return 1;
    else {
        uint8_t i = 0;
        for(i;i<=size;i++){
            if(ch1[i] != ch2[i]) result = 1;
        }
    }
    return result;
}
char* strSlice(char* source, uint16_t start, uint16_t end) {
    static char buffer[256]; 
    uint16_t sourceLen = Strlen(source);
    if (start >= sourceLen || end > sourceLen || start >= end) {
        buffer[0] = '\0';  
        return buffer;
    }
    uint16_t sliceLen = end - start;
    if (sliceLen >= sizeof(buffer)) {
        buffer[0] = '\0';  
        return buffer;
    }
    for (uint16_t i = 0; i < sliceLen; i++) {
        buffer[i] = source[start + i];
    }
    buffer[sliceLen] = '\0';  
    return buffer;
}