//
//  GSVodVideoView.h
//  GSCommonKit
//
//  Created by Sheng on 2018/7/30.
//  Copyright © 2018年 gensee. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import <GPUImage/GPUImage.h>
//#import <GLKit/GLKView.h>

@interface GSVodVideoView : UIView

@property (nonatomic, strong) UIImageView *renderView;
//
//@property (nonatomic) NSInteger preferredFramesPerSecond;
//
//@property (nonatomic, getter=isPaused) BOOL paused;

- (void)renderData:(const uint8_t *)frame width:(unsigned)width height:(unsigned)height size:(unsigned)size;

@end
