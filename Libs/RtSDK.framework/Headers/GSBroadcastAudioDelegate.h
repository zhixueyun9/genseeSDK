//
//  GSBroadcastAudioDelegate.h
//  RtSDK
//
//  Created by Gaojin Hsu on 6/29/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>


#pragma mark -
#pragma mark Audio

/**
 *  直播音频代理，接受音频相关的信息回调
 */
@protocol GSBroadcastAudioDelegate <NSObject>

@required

/**
 *  音频模块初始化反馈代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param result  布尔值表示音频模块是否加载成功，YES表示成功
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveAudioModuleInitResult:(BOOL)result;


@optional

/**
 *  麦克风是否可用代理
 *
 *  @param manager     触发此代理的GSBroadcastManager对象
 *  @param isAvailabel 布尔值表示麦克风是否可用，YES表示可用
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager isMicrophoneAvailable:(BOOL)isAvailabel;


/**
 *  麦克风打开代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @see  GSBroadcastManager
 */
- (void)broadcastManagerDidActivateMicrophone:(GSBroadcastManager*)manager;


/**
 *  麦克风关闭代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @see  GSBroadcastManager
 */
- (void)broadcastManagerDidInactivateMicrophone:(GSBroadcastManager*)manager;


/**
 *  麦克风设置音量代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param volume  音量值
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didSetMicrophoneVolume:(long long)volume;


/**
 *  麦克风音量波值代理（在音量固定的情况下，声音的强弱是不固定的）
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param value   音量波值
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager microphoneAudioWaveValue:(long long)value;


/**
 *  喇叭是否可用代理
 *
 *  @param manager     触发此代理的GSBroadcastManager对象
 *  @param isAvailable 布尔值表示喇叭是否可用，YES表示可用
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager isSpeakerAvailable:(BOOL)isAvailable;


/**
 *  喇叭打开代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @see  GSBroadcastManager
 */
- (void)broadcastManagerDidActivateSpeaker:(GSBroadcastManager*)manager;


/**
 *  喇叭关闭代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @see  GSBroadcastManager
 */
- (void)broadcastManagerDidInactivateSpeaker:(GSBroadcastManager*)manager;


/**
 *  喇叭设置音量代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param volume  喇叭音量值
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didSetSpeakerVolume:(long long)volume;


/**
 *  喇叭音量波值代理（在音量固定的情况下，声音的强弱是不固定的）
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param value   音量波值
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager speakerAudioWaveValue:(long long)value;


/**
 *  指定用户喇叭音量波值代理（在音量固定的情况下，声音的强弱是不固定的）
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param value   音量波值
 *  @param userID  用户ID
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager speakerAudioWaveValue:(long long)value userID:(long long)userID;

@end
