//
//  GSBroadcastFtDelegate.h
//  RtSDK
//
//  Created by jiangcj on 17/7/5.
//  Copyright © 2017年 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GSBroadcastManager;



@protocol  GSBroadcastFtDelegate <NSObject>

@optional

/**
 *
 *
 *  @param manager    触发此代理的GSBroadcastManager对象
 *  @param ok 
 *  @see
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveBroadcastFtJoinConfirm:(BOOL)ok;


/**
 *  文件上传的配置
 *  @param manager    触发此代理的GSBroadcastManager对象
 *  @param maxUploadCount 最大上传数
 *  @param maxSingleSize 最大单个文件尺寸
 *  @see
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveBroadcastFtSettingUpdate:(unsigned short)maxUploadCount maxSingleSize:(unsigned int)maxSingleSize;

/**
 *
 *  @param manager    触发此代理的GSBroadcastManager对象
 *  @param fileId 文件id
 *  @param fileName 文件名字
 *  @param fileSize 文件尺寸
 *  @param fileOwner 上传当前文件的用户
 *
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveBroadcastFtFtNewFile:(unsigned int)fileId fileName:(NSString*)fileName fileSize:(long long)fileSize fileOwner:(long long)fileOwner;

/**
 *
 *
 *  @param manager    触发此代理的GSBroadcastManager对象
 *  @param fileId     文件id
 *  @see
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveBroadcastFtRemoveFile:(unsigned int)fileId;

/**
 *
 *
 *  @param manager    触发此代理的GSBroadcastManager对象
 *  @param fileId     文件id
 *  @param percent     上传文件的百分比
 *  @see
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveBroadcastFtUploadProgress:(unsigned int)fileId percent:(float)percent;

/**
 *  @param manager    触发此代理的GSBroadcastManager对象
 *  @param fileId 文件id
 *   *  @param percent     下载文件的百分比
 */
- (void)broadcastManager:(GSBroadcastManager*)manager didReceiveBroadcastFtDownloadProgress:(unsigned int)fileId percent:(float)percent;



@end
