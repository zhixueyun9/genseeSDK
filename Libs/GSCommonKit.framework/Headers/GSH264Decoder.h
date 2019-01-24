//
//  GSH264Decoder.h
//  GSCommonKit
//
//  Created by Gaojin Hsu on 7/10/17.
//  Copyright © 2017 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>
#import <CoreVideo/CoreVideo.h>
#import <UIKit/UIKit.h>
//#import "GSVideoView.h"

//typedef void (^VideoDecodeCompletionBlock)(CMSampleBufferRef _Nullable sampleBufferRef, unsigned long videoWidth, unsigned long videoHeight);
@class GSH264Decoder;
@protocol GSH264DataDelegate <NSObject>
@optional
- (void)h264Decoder:(GSH264Decoder* _Nullable)decoder onAVSampleBuffer:(CMSampleBufferRef _Nullable)mbuffer;

- (void)h264Decoder:(GSH264Decoder* _Nullable)decoder onCVImageBufferRef:(CVImageBufferRef)mbuffer width:(unsigned long)mwidth height:(unsigned long)mheight;

@end



//typedef enum : NSUInteger {
//    //硬解
//    GSH264DecodeVTD, //使用videoToolBox
//    GSH264DecodeAVSample, //使用AVSampleBuffer
//    //软解
//    GSH264DecodeFFMPEG, //使用ffmpeg
//} GSH264DecodeType;

//H264(baseline)格式视频解码器
@interface GSH264Decoder : NSObject
- (void)decodeRawVideoFrame:(uint8_t *_Nonnull)frame withSize:(uint32_t)frameSize;//接受h264数据进行解码
//@property (nonatomic, copy) VideoDecodeCompletionBlock  _Nullable completion;//每一帧解码完成回调
//@property (nonatomic, assign) BOOL moreInfo; //开启返回视频宽高信息，CPU消耗增加%3（iPhone7Plus）,默认关闭
@property (nonatomic, assign) BOOL isVideoToolBox; //使用videoToolBox
@property (nonatomic, weak) id<GSH264DataDelegate> _Nullable  delegate;
@end
