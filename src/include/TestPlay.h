#ifndef TESTPLAY_H
#define TESTPLAY_H
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavutil/avutil.h>
    #include <libswresample/swresample.h>
    #include <libswscale/swscale.h>
}

class TestPlay
{
public:
    TestPlay();




public:
    bool OpenFile(const char* pFileName);
};

#endif // TESTPLAY_H
