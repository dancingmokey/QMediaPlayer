#include "include/TestPlay.h"

TestPlay::TestPlay()
{
    av_register_all();

    this->OpenFile("/home/liulei/Workspace/QMediaPlayer/src/temp.f4v");
}



bool TestPlay::OpenFile(const char* pFileName)
{
    int nRetVal = 0;
    bool bIsCodecInit = false;
    int nVideoStreamIdx = -1;
    AVCodecContext* pCodecCtx = NULL;
    AVFormatContext *pFormatCtx = NULL;

    if ((nRetVal = avformat_open_input(&pFormatCtx, pFileName, NULL, NULL)) < 0)
    {
        av_log(NULL, AV_LOG_ERROR, "Cannot open input file\n");
        return nRetVal;
    }


    if ((nRetVal = avformat_find_stream_info(pFormatCtx, NULL)) < 0)
    {
        av_log(NULL, AV_LOG_ERROR, "Cannot find stream information\n");
        avformat_close_input(&pFormatCtx);
        return nRetVal;
    }

    for (int i = 0; i < pFormatCtx->nb_streams; i++)
    {
        // 找到视频码流
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            nVideoStreamIdx = i;
            // 初始化解码器信息
            if (bIsCodecInit == false)
            {
                pCodecCtx = pFormatCtx->streams[i]->codec;
                AVCodec* pCodec = avcodec_find_decoder(pCodecCtx->codec_id);

                if (NULL == pCodec)
                {
                    printf("cannot find decoder");
                    avformat_close_input(&pFormatCtx);
                    return 1;
                }

                if(0 != avcodec_open2(pCodecCtx, pCodec, NULL))
                {
                    printf("open codecer failed");
                    avformat_close_input(&pFormatCtx);
                    return 1;
                }

                bIsCodecInit = true;

                printf("Codec = %s\n", pCodec->long_name);
            }

        }
    }

    // 解码视频
    if ((bIsCodecInit == true) &&
        (pCodecCtx != NULL))
    {
        //decode_video_packet(pFormatCtx, pCodecCtx, nVideoStreamIdx);
    }

    // 关闭文件
    avformat_close_input(&pFormatCtx);

    return 0;
}
