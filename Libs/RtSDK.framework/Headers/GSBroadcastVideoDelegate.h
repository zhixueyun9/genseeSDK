//
//  GSBroadcastVideoDelegate.h
//  RtSDK
//
//  Created by Gaojin Hsu on 6/29/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  直播视频代理，接受直播视频信息回调
 */
@protocol GSBroadcastVideoDelegate <NSObject>

@required

/**
 *  视频模块初始化反馈代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param result  布尔值表示初始化结果，YES表示成功
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveVideoModuleInitResult:(BOOL)result;


/**
 *  摄像头或插播视频每一帧的数据代理
 *
 *  @param manager  触发此代理的GSBroadcastManager对象
 *  @param userID   表示这一帧视频数据是从该用户哪里发送过来的
 *  @param videoFrame 一帧视频数据
 *  @see  GSBroadcastManager
 *  @see  GSVideoFrame
 */
- (void)broadcastManager:(GSBroadcastManager*)manager userID:(long long)userID renderVideoFrame:(GSVideoFrame*)videoFrame;


- (void)OnVideoData4Render:(long long) userId width: (int) nWidth nHeight:(int) nHeight frameFormat:( unsigned int) dwFrameFormat  displayRatio: (float) fDisplayRatio data:( void*) pData len:(int) iLen;


/**
 *  某个用户加入视频
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param userInfo 用户信息
 *  @see GSBroadcastManager
 *  @see GSUserInfo
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didUserJoinVideo:(GSUserInfo*)userInfo;


/**
 *  某个用户退出视频
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param userID  退出用户的ID
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didUserQuitVideo:(long long)userID;



/**
 *  摄像头是否可用代理
 *
 *  @param manager     触发此代理的GSBroadcastManager对象
 *  @param isAvailable 布尔值表示摄像头是否可用，YES表示可用
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager isCameraAvailable:(BOOL)isAvailable;


/**
 *  摄像头打开代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @see GSBroadcastManager
 */
- (void)broadcastManagerDidActivateCamera:(GSBroadcastManager*)manager;


/**
 *  摄像头关闭代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @see  GSBroadcastManager
 */
- (void)broadcastManagerDidInactivateCamera:(GSBroadcastManager*)manager;


/**
 *  摄像头或插播视频播放代理
 *
 *  @param manager  触发此代理的GSBroadcastManager对象
 *  @param userInfo 视频所属用户的用户信息
 *  @see  GSBroadcastManager
 *  @see  GSUserInfo
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didDisplayVideo:(GSUserInfo*)userInfo;


/**
 *  摄像头或插播视频关闭播放代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param userID  视频所属用户的ID
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didUndisplayVideo:(long long)userID;


/**
 *  设置某一路摄像头或插播视频的激活状态代理
 *
 *  @param manager  触发此代理的GSBroadcastManager对象
 *  @param userInfo 激活视频所属用户的用户信息
 *  @param active   布尔值表示是否激活，YES表示激活
 *  @see  GSBroadcastManager
 *  @see  GSUserInfo
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didSetVideo:(GSUserInfo*)userInfo active:(BOOL)active;


/**
 *  手机摄像头开始采集数据
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 */
- (BOOL)broadcastManagerDidStartCaptureVideo:(GSBroadcastManager*)manager;



/**
 手机摄像头停止采集数据

 @param manager  触发此代理的GSBroadcastManager对象
 */
- (void)broadcastManagerDidStopCaptureVideo:(GSBroadcastManager*)manager;

@end

