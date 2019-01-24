//
//  GSBroadcastRoomDelegate.h
//  RtSDK
//
//  Created by Gaojin Hsu on 6/29/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>
#import "GSBroadcastValues.h"
#import <GSCommonKit/GSWebAccess.h>


@class GSBroadcastManager;

/**
 *  直播代理，回调直播信息数据
 */
@protocol GSBroadcastRoomDelegate <NSObject>

@required

/**
 * 直播连接代理
 *
 * @param manager 触发此代理的GSBroadcastManager对象
 *
 * @param connectResult 枚举值，表示直播连接结果
 *
 * @see GSBroadcastManager
 *
 * @see GSBroadcastConnectResult
 *
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveBroadcastConnectResult:(GSBroadcastConnectResult)connectResult;


@optional

/**
 * 加入直播代理
 *
 * @param manager 触发此代理的GSBroadcastManager对象
 *
 * @param joinResult 枚举值，表示加入直播结果
 *
 * @param selfUserID 自己的用户ID
 *
 * @param rebooted rebooted为YES，表示这次连接行为的产生是由于根服务器重启而导致的重连
 *
 * @see GSBroadcastManager
 *
 * @see GSBroadcastConnectResult
 *
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveBroadcastJoinResult:(GSBroadcastJoinResult)joinResult selfUserID:(long long)userID rootSeverRebooted:(BOOL)rebooted;


/**
 * 自己离开直播代理
 *
 * @param manager 触发此代理的GSBroadcastManager对象
 *
 * @param leaveReason 枚举值，表示离开直播的原因
 *
 * @see GSBroadcastManager
 *
 * @see GSBroadcastLeaveReason
 *
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didSelfLeaveBroadcastFor:(GSBroadcastLeaveReason)leaveReason;


/**
 * 直播重连代理
 *
 * @param manager 触发此代理的GSBroadcastManager对象
 *
 * @see GSBroadcastManager
 *
 */
- (void)broadcastManagerWillStartReconnect:(GSBroadcastManager*)manager;


/**
 * 锁住/解锁 房间代理
 *
 * @param manager 触发此代理的GSBroadcastManager对象
 *
 * @param locked 若值为YES，则房间被锁住，若值为NO，房间被解锁
 *
 * @see GSBroadcastManager
 *
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didSetLocked:(BOOL)locked;


/**
 * 直播状态改变代理，比如暂停或者恢复；如果是直播结束，将从 -(void)broadcastManager:didSelfLeaveBroadcastFor:回来， 因为直播结束，默认都会被踢出
 *
 * @param manager 触发此代理的GSBroadcastManager对象
 *
 * @param status 枚举值表示状态
 *
 * @see GSBroadcastManager
 *
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didSetStatus:(GSBroadcastStatus)status;


/**
 *  房间开启录制代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param status  枚举值表示状态
 *  @see GSBroadcastManager
 *  @see GSBroadcastStatus
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didSetRecordingStatus:(GSBroadcastStatus)status;


/**
 *  获取房间信息代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param key     键
 *  @param value   值
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveBroadcastInfoKey:(NSString*)key value:(long long)value;


/**
 *  其他用户加入房间代理
 *
 *  @param manager  触发此代理的GSBroadcastManager对象
 *  @param userInfo 用户信息
 *  @see GSBroadcastManager
 *  @see GSUserInfo
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveOtherUser:(GSUserInfo*)userInfo;


/**
 *  其他用户离开房间
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param userID  离开直播的用户ID
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didLoseOtherUser:(long long)userID;


/**
 *  用户信息更新代理
 *
 *  @param manager  触发此代理的GSBroadcastManager对象
 *  @param userInfo 更新后的用户信息
 *  @param flag     枚举值表示用户更新的字段
 *  @see GSBroadcastManager
 *  @see GSUserInfo
 *  @see GSUserInfoUpdate
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didUpdateUserInfo:(GSUserInfo*)userInfo updateFlag:(GSUserInfoUpdate)flag;


/**
 *  广播消息代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param message 广播的内容
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager broadcastMessage:(NSString *)message;


/**
 *  点名倒计时代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param number  倒计时开始的数字
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager checkinRequestCountingDownFrom:(NSInteger)number;


/**
 *  收到用户回应点名代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param userID  回应点名的用户的UserID
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager checkinRequestResponsedUser:(long long)userID;


/**
 *  举手代理(场景类似于课堂中的举手）
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param userID  举手的用户的UserID
 *  @param data    额外字段
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager handUpUser:(long long)userID extraData:(NSString*)data;


/**
 *  手放下代理（对应于举手）
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param userID  手放下的用户的UserID
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager handDownUser:(long long)userID;


/**
 *  索取直播设置信息代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param key     键
 *  @param value   值
 *  @see  GSBroadcastManager
 */
- (BOOL)broadcastManager:(GSBroadcastManager*)manager querySettingsInfoKey:(NSString*)key strValue:(NSString**)value;

/**
 *  索取直播设置信息代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param key     键
 *  @param value   值
 *  @see  GSBroadcastManager
 */
- (BOOL)broadcastManager:(GSBroadcastManager*)manager querySettingsInfoKey:(NSString*)key numberValue:(int*)value;



///**
// *  保存网页登录的 直播简介 信息代理
// *
// *  @param manager 触发此代理的GSBroadcastManager对象
// *  @param liveIntroduceInfo     简介信息
// *  @see  GSBroadcastManager
// */
//- (BOOL)broadcastManager:(GSBroadcastManager*)manager saveLiveIntroduceInfo:(NSString*)liveIntroduceInfo;



/**
 *  保存正常登录 的直播简介 信息代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param liveIntroduceInfoDic     简介信息
 *  @see  GSBroadcastManager
 */
-(BOOL)broadcastManager:(GSBroadcastManager*)manager saveLiveIntroduceInfoDic:(NSDictionary*)liveIntroduceInfoDic;




/**
 *  保存直播设置信息代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param key     键
 *  @param value   值
 *  @see  GSBroadcastManager
 */
- (BOOL)broadcastManager:(GSBroadcastManager*)manager saveSettingsInfoKey:(NSString*)key strValue:(NSString*)value;

/**
 *  保存直播设置信息代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param key     键
 *  @param value   值
 *  @see  GSBroadcastManager
 */
- (BOOL)broadcastManager:(GSBroadcastManager*)manager saveSettingsInfoKey:(NSString*)key numberValue:(int)value;


/**
 *  程序升级提示代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param urlStr  下载的url
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager upgradedAppDownLoadUrl:(NSString*)urlStr;


/**
 *  网络状态报告代理, 最好的状态为100, 最差的状态为0（接近断网）, 小于50都为较差;
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param level   网络状态值
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager networkStatus:(Byte)level;

/**
 *  中奖代理
 *
 *  @param manager   触发此代理的GSBroadcastManager对象
 *  @param type      抽奖动作类型
 *  @param usernames 中奖名单，多人之间有"\n"间隔
 *  @see GSBroadcastManager
 *  @see GSLotteryType
 */
- (void)broadcastManager:(GSBroadcastManager*)manager lotteryActionType:(GSLotteryActionType)type userNames:(NSString*)usernames;


/**
 *  设置采集比特率
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param session session
 */
- (void)broadcastManager:(GSBroadcastManager *)manager didSetupCustomBitRate:(VTCompressionSessionRef)session;


/**
 *  编码失败
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 */
- (void)broadcastManagerEncodeError:(GSBroadcastManager *)manager;

/**
 直播间是否有接入电话的功能

 @param manager 触发此代理的GSBroadcastManager对象
 @param enabled 是否支持电话接入
 */
- (void)broadcastManager:(GSBroadcastManager*)manager phoneServiceStatus:(BOOL)enabled;


/**
 拨打电话结果

 @param manager  触发此代理的GSBroadcastManager对象
 @param phoneNumber 呼叫的号码
 @param reason reason的值为3 表示呼叫成功
 @param status 在reason的值不等于3的情况下，status表示呼叫失败的具体原因： 0-其他原因；1-被主持人挂断；2-参会人主动挂断； 3-电话未接通；
                4-占线； 7-会议人数已满；8-会议室已上锁；9-不允许外呼
 */
- (void)broadcastManager:(GSBroadcastManager*)manager phoneNumber:(NSString*)phoneNumber reason: (int) reason  status:(int)status;


@end
