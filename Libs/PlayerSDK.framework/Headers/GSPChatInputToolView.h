//
//  GSPChatInputToolView.h
//  GHEmojiKeyboard
//
//  Created by Gaojin Hsu on 4/25/15.
//  Copyright (c) 2015 gensee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GSPChatView.h"
#import "GSPQaView.h"


@class GSPChatView;
@class GSPQaView;

@protocol GSPChatInputToolViewDelegate <NSObject>
@optional
- (void)sendMsg:(NSString*)msg isChat:(BOOL)isChat;

//textView代理 - 用于用户自定义额外事件

- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

- (void)textViewDidChange:(UITextView *)textView;

@end

/**
 聊天和问答的输入栏
 */
@interface GSPChatInputToolView : UIView

/**
 *  初始化输入栏
 *
 *  @param viewController  当前的viewController
 *  @param chatView        输入栏所工作的目标ChatView对象
 *  @param qaView          输入栏所工作的目标QaView对象
 *  @param flag            表示是作用于ChatView还是QaView，YES表示作用于ChatView
 *
 *  @return GSPChatInputToolView
 */
- (id)initWithViewController:(UIViewController*)viewController combinedChatView:(GSPChatView *)chatView combinedQaView:(GSPQaView*)qaView isChatMode:(BOOL)flag;

/**
 *  输入栏中的textView
 */
@property (nonatomic, strong) UITextView *inputTextView;

@property (nonatomic, weak) id <GSPChatInputToolViewDelegate> delegate;


/**
 *  设置聊天用户列表
 *
 *  @param array 用户对象数字，内容为GSPUserInfo实例
 */
- (void)setUserList:(NSMutableArray*)array;

/**
 *  隐藏用户列表
 */
- (void)hideUserListView;

@end
