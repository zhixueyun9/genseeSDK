//
//  GSVodManager.h
//  VodSDKDemo
//
//  Created by Sheng on 2018/8/3.
//  Copyright © 2018年 Gensee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VodSDK.h"

typedef enum : NSUInteger {
    GSVodDownloadNetworkError,
    GSVodDownloadWriteFailed,
} GSVodDownloadError;

//public static final String RESULT_SUCCESS = "1";      public static final String RESULT_FAIL_TOKEN = "4";      public static final String RESULT_FAIL_LOGIN = "5";      public static final String RESULT_FIAL_NOT_EXIT_LOGIN_OR_PASSWORD = "7";      public static final String RESULT_FAIL = "2";      public static final String RESULT_FAIL_NOT_EXIT_VOD_ID = "6";      public static final String RESULT_FAIL_NOT_EXIT_VOD = "3";//number      public static final String RESULT_FAIL_K = "10";

typedef enum : NSUInteger {
    GSVodWebaccessSuccess = 1,          //成功
    GSVodWebaccessFailed = 2,           //错误 - 内部错误
    GSVodWebaccessNumberError = 3,      //房间号错误 或者 webcast/training设置错误
    GSVodWebaccessWrongPassword = 4,    //观看密码错误
    GSVodWebaccessLoginFailed = 5,      //登录失败
    GSVodWebaccessVodIdError = 6,       //VodID错误
    GSVodWebaccessNoAccountOrPwd = 7,   //账号为空 或 密码为空
    GSVodWebaccessThirdKeyError = 10,   //第三方验证错误
    GSVodWebaccessNetworkError = 14,    //网络请求失败
} GSVodWebaccessError;

typedef enum : NSUInteger {
    GSVodDownloadStateStop,
    GSVodDownloadStateDownloading,
    GSVodDownloadStatePause,
} GSVodDownloadState;

@class GSVodManager;
@protocol GSVodManagerDelegate <NSObject>
@optional
//开始下载
- (void)vodManager:(GSVodManager *)manager downloadBegin:(downItem *)item;
//下载进度
- (void)vodManager:(GSVodManager *)manager downloadProgress:(downItem *)item percent:(float)percent;
//下载暂停
- (void)vodManager:(GSVodManager *)manager downloadPause:(downItem *)item;
//下载停止
- (void)vodManager:(GSVodManager *)manager downloadStop:(downItem *)item;
//下载完成
- (void)vodManager:(GSVodManager *)manager downloadFinished:(downItem *)item;
//下载失败
- (void)vodManager:(GSVodManager *)manager downloadError:(downItem *)item state:(GSVodDownloadError)state;
@end

@interface GSVodManager : NSObject
//play
@property (nonatomic, strong) VodPlayer *player;
@property (nonatomic, assign) BOOL isFlv;

@property (nonatomic, assign) GSVodDownloadState state;

//downlaod
@property (nonatomic, strong) VodDownLoader *downloader;
@property (nonatomic, weak) id<GSVodManagerDelegate> delegate;

/**
 记录上次或正在下载的录制件信息
 */
@property (nonatomic, strong) downItem *downloadingItem;

/**
 下载处理队列
 */
@property (nonatomic, strong) NSMutableArray *downloadQueue;
/**
 下载完成队列
 */
@property (nonatomic, strong) NSMutableArray *downloadProcessed;


+ (instancetype)sharedInstance;

#pragma mark - play

- (void)play:(downItem *)item online:(BOOL)isOnline;

#pragma mark - download

/**
 获取点播件信息,并加入队列

 @param param 需要下载item的param信息
 @param isqueue 是否加入下载队列
 @param block 获取信息回调,异步请求,多次调用并不保证时序性
 */
- (void)requestParam:(VodParam *)param enqueue:(BOOL)isqueue completion:(void(^)(downItem *item,GSVodWebaccessError type))block;
//手动插入item到队列 -1为插入到末尾
- (BOOL)insertQueue:(downItem *)item atIndex:(NSInteger)index;
//开始队列下载
- (BOOL)startQueue;
//取消下载 - 取消当前下载,并暂停队列下载队列
- (void)stopQueue;
//暂停下载 - 暂停当前下载，恢复时继续下载
- (void)pauseQueue;
//删除已下载的项目
- (BOOL)removeOnDisk:(NSString *)vodId;
//清空所有下载相关的队列并停止下载
- (void)cleanQueue;
@end
