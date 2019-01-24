//  GSDiagnosisInfo.h
//  RtSDK
//  Created by jiangcj on 15/7/8.
//  Copyright (c) 2015年 Geensee. All rights reserved.
#import <Foundation/Foundation.h>
#define IsException @"isException"
typedef NS_ENUM(NSInteger, GSDiagnosisType) {
    /**成功*/
    GSDiagnosisUploadSuccess = 0,
    /**文件打包出错*/
    GSDiagnosisPackError=1,
    /**文件上传发生错误*/
    GSDiagnosisUploadNetError = 2,
    /**提交回执出错*/
    GSDiagnosisSubmitXMLInfoError=3
};
@protocol GSDiagnosisInfoDelegate <NSObject>
@optional
- (void)diagnosis:(id)sender didUploadWithResult:(GSDiagnosisType)type error:(NSString*)errorDescription;
@end
typedef void (^GSUploadWithErrorBlock)(GSDiagnosisType type,NSString* errorDescription);
@interface GSDiagnosisInfo : NSObject<NSURLSessionDelegate>
@property (nonatomic,weak) id<GSDiagnosisInfoDelegate> delegate;
/**
 是否采用https
 */
@property (nonatomic,assign) BOOL useHttps;


/**
 日志上传结果的Block的回调
 */
@property (nonatomic, copy) GSUploadWithErrorBlock upLoadResult;

/**
 单例模式
 */
+ (GSDiagnosisInfo*)shareInstance;

/**
 报告诊断信息
 */
- (void)ReportDiagonse;


/**
 报告诊断信息Ex - 加入直播前可以用这个上传日志,上传到一个固定的地址
 */
- (void)ReportDiagonseEx;


/*
 需要先调用这个方法，将日记重定向到日记文件
 **/
- (void)redirectNSlogToDocumentFolder;
@end
