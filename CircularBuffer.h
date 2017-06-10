struct sCircularBuffer{
    tElement *buf;
    uint16_t size;
    uint16_t read;
    uint16_t write;
};

uint16_t CBlengthData(struct sCircularBuffer *cb);
enum eError CBWirte(struct sCircularBuffer *cb, tElement data);
enum eError CBRead(struct sCircularBuffer *cb, tElement *data);