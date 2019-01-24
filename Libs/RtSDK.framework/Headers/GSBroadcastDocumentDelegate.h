//
//  GSBroadcastDocumentDelegate.h
//  RtSDK
//
//  Created by Gaojin Hsu on 6/29/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  直播文档代理，接收直播文档信息回调
 */
@protocol GSBroadcastDocumentDelegate <NSObject>

@required


/**
 *  文档模块初始化反馈代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param result  布尔值表示初始化是否成功，YES表示成功
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveDocModuleInitResult:(BOOL)result;


@optional


/**
 *  文档打开代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager *)manager didOpenDocument:(GSDocument*)doc;


/**
 *  文档关闭代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager *)manager didCloseDocument:(unsigned)docID;


/**
 *  文档切换代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @see  GSBroadcastManager
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didSlideToPage:(unsigned)pageID ofDoc:(unsigned)docID step:(int)step;

/**
 *  文档收到标注代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param anno    标注对象
 *  @param pageID  标注所属Page的pageID
 *  @param docID   标注所属的Doc的docID
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveAnno:(GSAnnoBase*)anno onPage:(unsigned int)pageID ofDoc:(unsigned int)docID ;


/**
 *  文档删除标注代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param annoID  删除标注的ID
 *  @param pageID  删除标注所属的Page的pageID
 *  @param docID   删除标注所属的Doc的docID
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didRemoveAnno:(long long)annoID onPage:(unsigned int)pageID ofDoc:(unsigned int)docID;

/**
 *  文档页加载完成代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param page    加载完的文档页对象
 *  @param docID   文档页所属的Doc的docID
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didFinishLoadingPage:(GSDocPage*)page ofDoc:(unsigned int)docID;

/**
 *  文档是否保存到服务器代理
 *
 *  @param manager 触发此代理的GSBroadcastManager对象
 *  @param docID   文档的docID
 *  @param bSaved  是否保存到服务器
 *  @param isBySelf 是否是自己保存的，YES表示是
 */
- (void)broadcastManager:(GSBroadcastManager*)manager doc:(unsigned int)docID savedOnServer:(BOOL)bSaved bySelf:(BOOL)isBySelf;

@end

