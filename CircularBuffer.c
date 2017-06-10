#include "CircularBuffer.h"

uint16_t CBlengthData(struct sCircularBuffer *cb){
    return ((cb->write - cb->read)&(cb->size - 1));
}

enum eError CBWirte(struct sCircularBuffer *cb, tElement data){
    if(CBlengthData(cb) == (cb->size - 1)){
        return eErrorBufferFull;
    }
    cb->buf[cb->write] = data;
    cb->write = (cb->write + 1)&(cb->size - 1);
}
enum eError CBRead(struct sCircularBuffer *cb, tElement *data){
    if(CBlengthData(cb) == 0){
        return eErrorBufferEmpty;
    }
    *data = (cb->buf)[cb->read];
    cb->read = (cb->read + 1)&(cb->size - 1);
}