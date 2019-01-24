//
//  GSH264Encoder.h
//  GSCommonKit
//
//  Created by Gaojin Hsu on 7/17/17.
//  Copyright © 2017 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
@protocol GSH264EncoderDelegate <NSObject>
- (void)gotSpsPps:(NSData*)sps pps:(NSData*)pps spslen:(int)spslen ppslen:(int)ppslen;
- (void)gotEncodedData:(NSData*)data isKeyFrame:(BOOL)isKeyFrame len:(int)len;
@end

@interface GSH264Encoder : NSObject
@property (nonatomic, assign) unsigned int videoWidth;
@property (nonatomic, assign) unsigned int videoHeight;
@property (nonatomic, assign) BOOL AVCSent;
@property (nonatomic, weak) id<GSH264EncoderDelegate> delegate;
@property (nonatomic, copy)void (^SpsPpsBlock)(NSData* sps, NSData* pps, int spslen, int ppslen);
@property (nonatomic, copy) void (^EncodedDataBlock)(NSData* data, BOOL isKeyFrame, int len);
- (instancetype)initWithVideoWidth:(unsigned int)width videoHeight:(unsigned int)height;
- (void)encodeImageBuffer:(CVImageBufferRef) imageBuffer;


@end
