//
//  AudioRoomCallback-Publisher.h
//  zegoaudioroom
//
//  Copyright © 2017年 ZEGO. All rights reserved.
//

#ifndef AudioRoomCallback_Publisher_h
#define AudioRoomCallback_Publisher_h

#include "./AudioRoomDefines.h"

namespace ZEGO
{
    namespace AUDIOROOM
    {
        class IAudioLivePublisherCallback
        {
        public:
            /**
             推流状态更新
             
             @param stateCode 状态码
             @param pszStreamID 流 ID
             @param oStreamInfo 推流信息
             */
            virtual void OnPublishStateUpdate(int stateCode, const char *pszStreamID, const ZegoPublishingStreamInfo& oStreamInfo) = 0;
            
            virtual void OnAuxCallback(unsigned char *pData, int *pDataLen, int *pSampleRate, int *pNumChannels) {}
            
            virtual ~IAudioLivePublisherCallback() {}
        };
    }
}

#endif /* AudioRoomCallback_Publisher_h */
