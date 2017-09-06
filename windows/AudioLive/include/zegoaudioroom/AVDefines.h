//
//  AVDefine.h
//  zegoliveroom
//
//  Created by Strong on 2017/7/20.
//

#ifndef AVDefine_h
#define AVDefine_h

#ifndef ZegoAVDefines_h

#define ZEGO_MAX_COMMON_LEN         (512)
#define ZEGO_MAX_LONG_LEN           (4*1024)
#define ZEGO_MAX_URL_COUNT          (10)
#define ZEGO_MAX_EVENT_INFO_COUNT   (10)
#define ZEGO_MAX_MIX_INPUT_COUNT    (12)

#if defined(_MSC_VER) || defined(__BORLANDC__)
#    define _I64_                "I64"
#    define _i64_                "i64"
#    define _64u_                "%I64u"
#    define _I64uw_                L"%llu"L
#    define _i64uw_                L"%llu"L
#else
#    define _I64_                "ll"
#    define _i64_                "ll"
#    define _64u_                "%llu"
#    define _I64w_                "ll"
#    define _I64uw_                L"%llu" L
#    define _i64uw_                L"%llu" L
#    define __int64                long long
#endif

namespace ZEGO
{
    namespace AV
    {
        /** SDK 事件通知 */
        enum EventType
        {
            Play_BeginRetry = 1,        /**< 开始重试拉流 */
            Play_RetrySuccess = 2,      /**< 重试拉流成功 */
            
            Publish_BeginRetry = 3,     /**< 开始重试推流 */
            Publish_RetrySuccess = 4,   /**< 重试推流成功 */
        };
        
        struct EventInfo
        {
            unsigned int uiInfoCount;
            char* arrKeys[ZEGO_MAX_EVENT_INFO_COUNT];
            char* arrValues[ZEGO_MAX_EVENT_INFO_COUNT];
        };
        
        /** 视频编码码率控制策略 */
        enum ZegoVideoEncoderRateControlStrategy
        {
            ZEGO_RC_ABR,                /**< 恒定码率 */
            ZEGO_RC_CBR,                /**< 恒定码率 */
            ZEGO_RC_VBR,                /**< 恒定质量 */
            ZEGO_RC_CRF,                /**< 恒定质量 */
        };
        
        /** 音频设备类型 */
        enum AudioDeviceType
        {
            AudioDevice_Input = 0,      /**< 输入设备 */
            AudioDevice_Output,         /**< 输出设备 */
        };
        
        struct DeviceInfo
        {
            char szDeviceId[ZEGO_MAX_COMMON_LEN];
            char szDeviceName[ZEGO_MAX_COMMON_LEN];
        };
        
        /** 设备状态 */
        enum DeviceState
        {
            Device_Added = 0,           /**< 输出设备 */
            Device_Deleted,             /**< 输出设备 */
        };
        
        /** 音量类型 */
        enum VolumeType
        {
            Volume_EndPoint = 0,        /**< 设备音量 */
            Volume_Simple,              /**< App 音量 */
        };
        
        /** 音频录制类型 */
        enum ZegoAVAPIAudioRecordMask
        {
            ZEGO_AUDIO_RECORD_NONE      = 0x0,  /**< 关闭音频录制 */
            ZEGO_AUDIO_RECORD_CAP       = 0x01, /**< 打开采集录制 */
            ZEGO_AUDIO_RECORD_RENDER    = 0x02, /**< 打开渲染录制 */
            ZEGO_AUDIO_RECORD_MIX       = 0x04  /**< 打开采集和渲染混音结果录制 */
        };
        
        /** 音频设备模式 */
        enum ZegoAVAPIAudioDeviceMode
        {
            ZEGO_AUDIO_DEVICE_MODE_COMMUNICATION = 1,    /**< 开启硬件回声消除 */
            ZEGO_AUDIO_DEVICE_MODE_GENERAL = 2,          /**< 关闭硬件回声消除 */
            ZEGO_AUDIO_DEVICE_MODE_AUTO = 3              /**< 根据场景自动选择是否开启硬件回声消除 */
        };
        
        /** 延迟模式 */
        enum ZegoAVAPILatencyMode
        {
            ZEGO_LATENCY_MODE_NORMAL = 0,               /**< 普通延迟模式 */
            ZEGO_LATENCY_MODE_LOW,                      /**< 低延迟模式，无法用于 RTMP 流 */
            ZEGO_LATENCY_MODE_NORMAL2,                  /**< 普通延迟模式，最高码率可达 192K */
            ZEGO_LATENCY_MODE_LOW2,                     /**< 低延迟模式，无法用于 RTMP 流。相对于 ZEGO_LATENCY_MODE_LOW 而言，CPU 开销稍低 */
        };
        
        /** 流量控制属性 */
        enum ZegoTrafficControlProperty
        {
            ZEGO_TRAFFIC_NONE = 0,                      /**< 无 */
            ZEGO_TRAFFIC_FPS = 1,                       /**< 帧率 */
            ZEGO_TRAFFIC_RESOLUTION = 1 << 1,           /**< 分辨率 */
        };
        
        enum PublishChannelIndex
        {
            PUBLISH_CHN_MAIN = 0,  ///< 主推流通道，默认
            PUBLISH_CHN_AUX,       ///< 第二路推流通道，无法推出声音
        };

        struct ZegoStreamInfo
        {
            ZegoStreamInfo()
            {
                uiRtmpURLCount = 0;
                uiHlsURLCount = 0;
                uiFlvURLCount = 0;
                szStreamID[0] = '\0';
                szMixStreamID[0] = '\0';
            }
            
            char szStreamID[ZEGO_MAX_COMMON_LEN];       /**< 流 ID */
            char szMixStreamID[ZEGO_MAX_COMMON_LEN];    /**< 混流 ID */
            
            char* arrRtmpURLs[ZEGO_MAX_URL_COUNT];      /**< RTMP 播放 URL 列表 */
            unsigned int uiRtmpURLCount;                /**< RTMP URL 个数 */
            
            char* arrFlvRULs[ZEGO_MAX_URL_COUNT];
            unsigned int uiFlvURLCount;
            
            char* arrHlsURLs[ZEGO_MAX_URL_COUNT];
            unsigned int uiHlsURLCount;
        };
        
        struct ZegoMixStreamConfig
        {
            char szStreamID[ZEGO_MAX_COMMON_LEN];       /**< 混流 ID */
            struct
            {
                int top;
                int left;
                int bottom;
                int right;
            } layout;
            
            /**
             *  原点在左上角，top/bottom/left/right 定义如下：
             *
             *  (left, top)-----------------------
             *  |                                |
             *  |                                |
             *  |                                |
             *  |                                |
             *  -------------------(right, bottom)
             */
        };
        
        
        /** 完整混流配置 */
        struct ZegoCompleteMixStreamConfig
        {
            char szOutputStream[ZEGO_MAX_COMMON_LEN];   /**< 输出流名或 URL，参见 bOutputIsUrl */
            bool bOutputIsUrl;                          /**< true: szOutputStream 为完整 RTMP URL，false: szOutputStream 为流名 */
            
            int nOutputFps;                             /**< 混流输出帧率 */
            int nOutputBitrate;                         /**< 混流输出码率 */
            
            int nOutputWidth;                           /**< 混流输出视频分辨率宽 */
            int nOutputHeight;                          /**< 混流输出视频分辨率高 */
            
            int nOutputAudioConfig;                     /**< 混流输出音频格式 */
            
            ZegoMixStreamConfig* pInputStreamList;      /**< 混流输入流列表 */
            int nInputStreamCount;                      /**< 混流输入流列表个数 */
            
            const unsigned char * pUserData;            /**< 用户自定义数据 */
            int nLenOfUserData;                         /**< 用户自定义数据的长度 */
            
            ZegoCompleteMixStreamConfig ()
            : bOutputIsUrl(false)
            , nOutputFps(0)
            , nOutputBitrate(0)
            , nOutputWidth(0)
            , nOutputHeight(0)
            , nOutputAudioConfig(0)
            , pInputStreamList(0)
            , nInputStreamCount(0)
            , pUserData(0)
            , nLenOfUserData(0)
            {
                szOutputStream[0] = '\0';
            }
        };
        
        /** 混流失败消息信息 */
        struct ZegoMixStreamResult
        {
            unsigned int uiErrorCode;   /**< 错误码，0 表示成功，此时 oStreamInfo 有效。150 表示输入流不存在，参考 nNonExistsStreamCount 和 ppNonExistsStreamIDList */
            
            int nNonExistsStreamCount;                                      /**< 不存在的输入流个数 */
            const char* ppNonExistsStreamIDList[ZEGO_MAX_MIX_INPUT_COUNT];  /**< 不存在的输入流 ID 列表 */
            
            ZegoStreamInfo oStreamInfo;
            
            ZegoMixStreamResult()
            : uiErrorCode(0)
            , nNonExistsStreamCount(0)
            {}
        };
    }
}

#endif


#ifndef ZegoAVCallback_h
namespace ZEGO
{
    namespace AV
    {
        class IZegoAudioRecordCallback
        {
        public:
            /**
            音频录制结果回调

            @param pData SDK 录制的音频数据
            @param data_len 数据长度
            @param sample_rate 采样率，不固定，以当前值为准
            @param num_channels 通道数量，单通道
            @param bit_depth 位深度，16 bit
            @param type 音频类型，参考 ZegoAVAPIAudioRecordMask
            @attention 开启音频录制并设置成功代理对象后，用户调用此 API 获取 SDK 录制的音频数据。用户可自行对数据进行处理，例如：存储等
            @note SDK 发送音频数据的周期为 20ms
            @note 存储数据时注意取 sampleRate、numOfChannels、bitDepth 参数写包头信息
            */
            virtual void OnAudioRecordCallback(const unsigned char *pData, int data_len, int sample_rate, int num_channels, int bit_depth, unsigned int type) {}

            /**
            音频录制回调

            @warning Deprecated，请使用带 type 参数的 OnAudioRecordCallback 回调
            */
            virtual void OnAudioRecordCallback(const unsigned char *pData, int data_len, int sample_rate, int num_channels, int bit_depth) {}
        };

        class IZegoLiveEventCallback
        {
        public:
            /**
            AVKit 事件通知

            @param event 事件
            @param pInfo 信息
            */
            virtual void OnAVKitEvent(int event, EventInfo* pInfo) = 0;
        };

        class IZegoDeviceStateCallback
        {
        public:
#ifdef WIN32
            /**
            音频设备状态变更

            @param deviceType 设备类型
            @param deviceInfo 设备信息
            @param state 状态
            */
            virtual void OnAudioDeviceStateChanged(AudioDeviceType deviceType, DeviceInfo *deviceInfo, DeviceState state) = 0;

            /**
            视频设备状态变更

            @param deviceInfo 设备信息
            @param state 状态
            */
            virtual void OnVideoDeviceStateChanged(DeviceInfo *deviceInfo, DeviceState state) {}

            /**
            音频设备音量变更

            @param deviceType 设备类型
            @param deviceId 设备 Id
            @param volumeType 音量类型
            @param volume 音量值
            @param bMuted 是否静音
            */
            virtual void OnAudioVolumeChanged(AudioDeviceType deviceType, const char *deviceId, VolumeType volumeType, unsigned int volume, bool bMuted) {}
#endif
            /**
            设备错误

            @param deviceName 设备名称
            @param errorCode 错误码
            */
            virtual void OnDeviceError(const char* deviceName, int errorCode) {}
        };
    }
}

#endif

#endif /* AVDefine_h */
