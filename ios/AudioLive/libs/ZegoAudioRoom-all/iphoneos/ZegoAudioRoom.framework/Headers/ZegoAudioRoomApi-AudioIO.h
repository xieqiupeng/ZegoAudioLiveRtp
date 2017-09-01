//
//  ZegoAudioRoomApi-AudioIO.h
//  ZegoAudioRoom
//
//  Created by Strong on 2017/3/16.
//  Copyright © 2017年 Zego. All rights reserved.
//

#import "ZegoAudioRoomApi.h"
#import "ZegoAudioCapture.h"

@interface ZegoAudioRoomApi (AudioIO)

+ (void)enableExternalAudioDevice:(bool)enable;
- (AVE::IAudioDataInOutput* )getIAudioDataInOutput;

/**
 设置音频前处理函数
 
 @warning Deprecated，请使用 [ZegoAudioRoomApi (AudioIO) setAudioPrep2:dataCallback:]
 */
+ (void)setAudioPrep:(void(*)(const short* inData, int inSamples, int sampleRate, short *outData))prep;


/**
 设置音频前处理函数
 
 @param prepSet 预处理的采样率等参数设置
 @param callback 采样数据回调
 @discussion 调用者调用此 API 设置音频前处理函数。SDK 会在音频编码前调用，inFrame 为采集的音频数据，outFrame 为处理后返回给SDK的数据
 */
+ (void)setAudioPrep2:(AVE::ExtPrepSet)prepSet dataCallback:(void(*)(const AVE::AudioFrame& inFrame, AVE::AudioFrame& outFrame))callback;

@end
