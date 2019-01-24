//
//  GSNotificationManager.h
//  FASTSDK
//
//  Created by Sheng on 2018/6/6.
//  Copyright © 2018年 Gensee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GSNotificationManager : NSObject

- (nullable instancetype)init;

- (void)addObserver:(nonnull id)observer
           selector:(nonnull SEL)aSelector
               name:(nullable NSString *)aName
             object:(nullable id)anObject;

- (void)removeAllObservers:(nonnull id)observer;

@end
