//
//  ZegoAudioRoomApiDefines.h
//  ZegoAudioRoom
//
//  Created by Strong on 2017/3/15.
//  Copyright © 2017年 Zego. All rights reserved.
//

#ifndef ZegoAudioRoomApiDefines_h
#define ZegoAudioRoomApiDefines_h

#ifndef ZEGO_EXTERN
#ifdef __cplusplus
#define ZEGO_EXTERN     extern "C"
#else
#define ZEGO_EXTERN     extern
#endif
#endif

/** 音频流类型 */
typedef enum : NSUInteger {
    /** 音频流新增 */
    ZEGO_AUDIO_STREAM_ADD,
    /** 音频流删除 */
    ZEGO_AUDIO_STREAM_DELETE,
} ZegoAudioStreamType;

/** 音频直播事件 */
typedef enum : NSUInteger {
    /** 音频拉流开始重试 */
    Audio_Play_BeginRetry = 1,
    /** 音频拉流重试成功 */
    Audio_Play_RetrySuccess = 2,
    
    /** 音频推流开始重试 */
    Audio_Publish_BeginRetry = 3,
    /** 音频推流重试成功 */
    Audio_Publish_RetrySuccess = 4,
    
    /** 拉流临时中断 */
    Audio_Play_TempDisconnected = 5,
    /** 推流临时中断 */
    Audio_Publish_TempDisconnected = 6,
} ZegoAudioLiveEvent;

/** 音频流 */
@interface ZegoAudioStream : NSObject

/** 用户 ID */
@property (nonatomic, copy) NSString *userID;
/** 用户名 */
@property (nonatomic, copy) NSString *userName;
/** 流 ID */
@property (nonatomic, copy) NSString *streamID;

@end

/** AudioSession相关配置信息的key, 值为 NSString */
ZEGO_EXTERN NSString *const kZegoAudioRoomConfigKeepAudioSesionActive;

#ifndef ZegoLiveRoomApiDefines_h

enum ZegoAPIAudioRecordMask
{
    /** 关闭音频录制 */
    ZEGOAPI_AUDIO_RECORD_NONE      = 0x0,
    /** 打开采集录制 */
    ZEGOAPI_AUDIO_RECORD_CAP       = 0x01,
    /** 打开渲染录制 */
    ZEGOAPI_AUDIO_RECORD_RENDER    = 0x02,
    /** 打开采集和渲染混音结果录制 */
    ZEGOAPI_AUDIO_RECORD_MIX       = 0x04
};

/** 音频录制配置信息 */
typedef struct
{
    /** 启用音频源选择，参考 ZegoAVAPIAudioRecordMask */
    unsigned int mask;
    
    /** 采样率 8000, 16000, 22050, 24000, 32000, 44100, 48000 */
    int sampleRate;
    
    /** 声道数 1(单声道) 或 2(双声道) */
    int channels;
    
} ZegoAPIAudioRecordConfig;

#endif

#ifndef ZegoLiveRoomApiDefines_Publisher_h

typedef enum : NSUInteger {
    /** 普通延迟模式 */
    ZEGOAPI_LATENCY_MODE_NORMAL = 0,
    /** 低延迟模式，无法用于 RTMP 流 */
    ZEGOAPI_LATENCY_MODE_LOW,
    /** 普通延迟模式，最高码率可达192K */
    ZEGOAPI_LATENCY_MODE_NORMAL2,
    /** 低延迟模式，无法用于 RTMP 流。相对于 ZEGO_LATENCY_MODE_LOW 而言，CPU 开销稍低 */
    ZEGOAPI_LATENCY_MODE_LOW2,
} ZegoAPILatencyMode;

#endif

#ifndef ZegoLiveRoomApiDefines_IM_h

typedef enum
{
    /** 全量更新 */
    ZEGO_UPDATE_TOTAL = 1,
    /** 增量更新 */
    ZEGO_UPDATE_INCREASE,
}ZegoUserUpdateType;

typedef enum
{
    /** 新增 */
    ZEGO_USER_ADD  = 1,
    /** 删除 */
    ZEGO_USER_DELETE,
}ZegoUserUpdateFlag;

/** 用户状态 */
@interface ZegoUserState : NSObject

/** 用户 ID */
@property (nonatomic, copy) NSString *userID;
/** 用户名 */
@property (nonatomic, copy) NSString *userName;
/** 用户更新属性 */
@property (nonatomic, assign) ZegoUserUpdateFlag updateFlag;
/** 角色 */
@property (nonatomic, assign) int role;

@end

#endif

#endif /* ZegoAudioRoomApiDefines_h */
