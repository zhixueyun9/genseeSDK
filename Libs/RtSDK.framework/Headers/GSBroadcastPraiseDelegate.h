//
//  GSBroadcastPraiseDelegate.h
//  RtSDK
//
//  Created by Gaojin Hsu on 5/24/18.
//  Copyright © 2018 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GSPraiseUserInfo.h"




@protocol GSBroadcastPraiseDelegate <NSObject>


/**
 点赞勋章 返回信息

 @param nResult 调用结果 1为成功
 @param strPraiseType 枚举类型
 @param userinfo 类实例
 */
- (void) OnPraiseInfo:(int)nResult strPraiseType:(GSPraiseType)strPraiseType userinfo:(GSPraiseUserInfo*)userinfo;

/**
 点赞勋章 总数信息

 @param nResult 调用结果 1为成功
 @param strPraiseType 枚举类型
 @param dwTotal 总数
 */
- (void) OnGetPraiseTotal:(int)nResult strPraiseType:(GSPraiseType)strPraiseType dwTotal:(unsigned int)dwTotal;

/**
 点赞勋章 排名

 @param nResult 调用结果 1为成功
 @param strPraiseType 枚举类型
 @param dwTotal 排名数组
 */
- (void) OnGetPraiseRecvList:(int)nResult strPraiseType:(GSPraiseType)strPraiseType praises:(NSArray<GSPraiseInfo*>*) dwTotal;

/**
 点赞勋章 发送回调

 @param strPraiseType 枚举类型
 @param userID 发送者id
 @param toUserID 接收者id
 @param time 时间
 @param src 发送者信息实例
 @param dst 接收者信息实例
 */
- (void) OnSendPraiseNotify:(GSPraiseType)strPraiseType userID:(long long)userID toUser:(long long)toUserID time:(unsigned int)time srcUserinfo:(GSPraiseUserInfo*)src dstUserinfo:(GSPraiseUserInfo*)dst;

@end
