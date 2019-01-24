//
//  GSBroadcastHongbaoDelegate.h
//  RtSDK
//
//  Created by Gaojin Hsu on 6/29/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GSGrabInfo.h"
#import "GSTipInfo.h"

/**
 *  红包代理，接受直播中红包的回调
 */
@protocol GSBroadcastHongbaoDelegate <NSObject>

@optional

/**
 *  创建红包结果回调
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param result           创建结果
 *  @param strid            红包ID
 */
- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onHongbaoCreate:(GSHongbaoCreateResult)result strId:(NSString*)strid;

/**
 *  抢红包结果回调
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param result           抢红包结果
 *  @param strid            红包ID
 *  @param money            抢到的金额
 */
- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onHongbaoGrabHongbao:(GSHongbaoGrabResult)result strId:(NSString*)strid money:(unsigned)money;

/**
 *  查询会议里所有的红包列表
 *
 *  @param broadcastManager  触发此代理的GSBroadcastManager对象
 *  @param hongbaoArray     红包列表
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager onHongbaoQueryHongbaoList:(NSArray*)hongbaoArray;

/**
 *  查询抢了这个红包的所有人
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param grabs            抢了这个红包的所有人的信息
 *  @param strid            红包ID
 */
- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onHongbaoQueryHongbaoGrabList:(NSArray*)grabs strId:(NSString*)strid;

/**
 *  查询自己抢的所有红包
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param grabs            自己抢的红包列表
 */
- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onHongbaoQuerySelfGrabList:(NSArray*)grabs;

/**
 *  查询余额
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param balance          余额
 *  @param ok
 */
- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onHongbaoQueryBalance:(unsigned)balance ok:(BOOL)ok;

/**
 *  出现红包回调
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param hongbaoInfo      红包信息
 */
- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onHongbaoComingNotify:(GSHongbaoInfo*)hongbaoInfo;

/**
 *  红包被抢回调
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param strid            红包ID
 *  @param grabInfo         抢红包信息
 *  @param hongbaoType      红包类型：//0:随机红包，1：固定红包，2：定向红包
 */
- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onHongbaoGrabbedNotify:(NSString*)strid grabInfo:(GSGrabInfo*)grabInfo type:(int)hongbaoType;


- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onTipQueryTotalAmount:(unsigned int)dwAmount result:(int)result;


- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onTipQueryTopList:(NSArray*)TipInfo result:(int)result;

//打赏回调接口 返回打赏类 GSTipInfo or GSTipInfoEx
- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onTipComingNotify:(GSTipInfo*) tip totalAmount:(int)totalAmount;

- (void)broadcastManager:(GSBroadcastManager*) broadcastManager onTipComingNotifyEx:(GSTipInfoEx*) tip totalAmount:(int)totalAmount;


@end

