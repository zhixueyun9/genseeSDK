//
//  GSBroadcastChatDelegate.h
//  RtSDK
//
//  Created by Gaojin Hsu on 6/29/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  直播文本聊天代理，接收直播聊天信息回调
 */
@protocol GSBroadcastChatDelegate <NSObject>

@required


/**
 *  聊天模块连接代理
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param result           布尔值表示初始化是否成功，YES表示成功
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didReceiveChatModuleInitResult:(BOOL)result;


@optional


/**
 *  收到私人聊天代理
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param msg              聊天消息数据
 *  @param user             发送者用户信息
 *  @see  GSBroadcastManager
 *  @see  GSChatMessage
 *  @see  GSUserInfo
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didReceivePrivateMessage:(GSChatMessage*)msg fromUser:(GSUserInfo*)user;


/**
 *  收到公共聊天代理
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param msg              聊天消息数据
 *  @param user             发送者用户信息
 *  @see  GSBroadcastManager
 *  @see  GSChatMessage
 *  @see  GSUserInfo
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didReceivePublicMessage:(GSChatMessage*)msg fromUser:(GSUserInfo*)user;


/**
 *  收到嘉宾聊天代理
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param msg              聊天消息数据
 *  @param user             发送者用户信息
 *  @see   GSBroadcastManager
 *  @see   GSChatMessage
 *  @see   GSUserInfo
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didReceivePanelistMessage:(GSChatMessage*)msg fromUser:(GSUserInfo*)user;


/**
 *  禁止或允许聊天/问答 状态改变代理
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param enabled          布尔值表示是否允许聊天和问答，YES表示允许
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didSetChattingEnabled:(BOOL)enabled;




/**
 *  聊天审核以后，根据用户id删除聊天消息
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param userId          用户id
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didChatCensorByUserID:(long long)userId;




/**
 *  聊天审核以后，根据聊天的消息id删除聊天消息
 *
 *  @param broadcastManager 触发此代理的GSBroadcastManager对象
 *  @param msgID          聊天消息id
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)broadcastManager didChatCensorByMsgID:(NSString*)msgID;







@end
