//
//  GSBroadcastInvestigationDelegate.h
//  RtSDK
//
//  Created by Gaojin Hsu on 6/29/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  直播问卷调查代理，接受直播中问卷调查信息的回调
 */
@protocol GSBroadcastInvestigationDelegate <NSObject>

@required


/**
 *  问卷调查模块初始化结果反馈代理
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param result           布尔值表示初始化是否成功， YES表示成功
 *  @see GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didReceiveInvestigationModuleInitResult:(BOOL)result;

@optional


/**
 *  添加问卷调查代理
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param investigation    添加的问卷调查对象
 *  @see  GSBroadcastManager
 *  @see  GSInvestigation
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didAddNewInvestigation:(GSInvestigation*)investigation;


/**
 *  删除一项问卷调查
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param investigation    删除的问卷调查对象
 *  @see   GSBroadcastManager
 *  @see   GSInvestigation
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didRemoveInvestigation:(GSInvestigation*)investigation;


/**
 *  发布一项问卷调查
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param investigation    发布的问卷调查对象
 *  @see   GSBroadcastManager
 *  @see   GSInvestigation
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didPublishInvestigation:(GSInvestigation*)investigation;


/**
 *  公布一项问卷调查的结果
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param investigation    公布了结果的问卷调查对象
 *  @see   GSBroadcastManager
 *  @see   GSInvestigation
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didPublishInvestigationResult:(GSInvestigation*)investigation;


/**
 *  提交一项问卷调查
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param investigation    提交的问卷调查对象
 *  @see   GSBroadcastManager
 *  @see   GSInvestigation
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didSubmitInvestigation:(GSInvestigation*)investigation;


/**
 *  问卷调查截止
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param investigation    截止了的问卷调查对象
 *  @see   GSBroadcastManager
 *  @see   GSInvestigation
 */
- (void)broadcastManager:(GSBroadcastManager *)broadcastManager didTerminateInvestigation:(GSInvestigation *)investigation;


/**
 *  发送问卷调查链接
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param investigationURL 问卷调查链接地址
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager *)broadcastManager didPostInvestigationURL:(NSString *)investigationURL;



/**
 *  发布答题卡
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param options 答题卡选项
 *  @param type 答题卡类型，单选，多选
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager *)broadcastManager didOnCardPublish:(NSDictionary *)options type:(GSCardQuestionType)questionType;



/**
 *  答题卡结果发布
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param options 所有选项,包括选择此选项的人数,此选项是否为正确答案
 *  @param type 答题卡类型，单选，多选
 *  @param totalSubmitted 总的提交人数
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager *)broadcastManager didOnCardResultPublish:(NSMutableArray *)options type:(GSCardQuestionType)questionType totalSubmitted:(int)totalSubmitted;



/**
 *  答题卡提交
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param itemIds 数组
 *  @param userId 用户id
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager *)broadcastManager didOnCardSubmit:(NSArray *)itemIds userId:(long long)userId;



/**
 *  答题卡结束
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager_didOnCardEnd:(GSBroadcastManager *)broadcastManager ;

/**
 抢答开始
 
 @param nDurationSec 抢答时间 (是包括推迟时间的)
 @param nDelaySec 推迟时间
 */
- (void)broadcastManager:(GSBroadcastManager *)broadcastManager OnVieToAnswerFirstStart:(int)nDurationSec delaySec:(int)nDelaySec;



//抢答结束
- (void)broadcastManagerOnVieToAnswerFirstEnd:(GSBroadcastManager *)broadcastManager;

/**
 抢答结果
 
 @param userID 用户id
 @param strUserName 用户名称
 */
- (void)broadcastManager:(GSBroadcastManager *)broadcastManager  OnVieToAnswerFirstSubmit:(long long)userID userName:(NSString*)strUserName;
@end


