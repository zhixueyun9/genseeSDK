//
//  GSBroadcastQaDelegate.h
//  RtSDK
//
//  Created by Gaojin Hsu on 6/29/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GSBroadcastValues.h"
#import "GSQuestion.h"

@class GSBroadcastManager;
/**
 *  直播问答代理，接收问答信息回调
 */
@protocol GSBroadcastQaDelegate <NSObject>

@required


/**
 *  问答模块初始化结果反馈代理
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param result           布尔值表示初始化结果，YES表示成功
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didReceiveQaModuleInitResult:(BOOL)result;


@optional


/**
 *  问答设置状态改变代理
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param enabled          布尔值表示是否可以提问， YES表示可以
 *  @param autoDispatch     布尔值表示问题是否自动派发给嘉宾
 *  @param autoPublish      布尔值表示问题是否自动发布，YES表示自动发布
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didSetQaEnabled:(BOOL)enabled QuestionAutoDispatch:(BOOL)autoDispatch QuestionAutoPublish:(BOOL)autoPublish;


/**
 *  问题的状态改变代理
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param question         问题对象
 *  @param status           枚举值表示发生了何种类型的状态改变
 *  @see  GSBroadcastManager
 *  @see  GSQuestion
 *  @see  GSQaStatus
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager question:(GSQuestion*)question updatesOnStatus:(GSQaStatus)status;

@end