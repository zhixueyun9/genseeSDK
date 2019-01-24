//
//  GSBroadcastLodDelegate.h
//  RtSDK
//
//  Created by Gaojin Hsu on 6/29/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GSLodItem.h"

@protocol GSBroadcastLodDelegate <NSObject>
- (void) OnLodJoinConfirm:(BOOL) bRet;
- (void) OnLodFailed:(NSString*)strid;
- (void) OnLodStart:(GSLodItem*) pLiveodItem;
- (void) OnLodSkip:(GSLodItem*) pLiveodItem;
- (void) OnLodPause:(GSLodItem*) pLiveodItem;
- (void) OnLodStop:(GSLodItem*) pLiveodItem;
- (void) OnLodPlaying:(GSLodItem*) pLiveodItem;
- (void) OnLodResourceAdd:(GSLodItem*) lodData;
- (void) OnLodResourceRemove:( NSString* ) strid;
@end