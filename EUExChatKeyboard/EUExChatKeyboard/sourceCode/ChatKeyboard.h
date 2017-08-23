//
//  ChatKeyboard.h
//  EUExChatKeyboard
//
//  Created by xurigan on 14/12/12.
//  Copyright (c) 2014年 com.zywx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EUExChatKeyboard.h"
#import "ZBMessageInputView.h"
#import "ZBMessageShareMenuView.h"
#import "ZBMessageManagerFaceView.h"
#import "EBrowserView.h"
#import "ChatKeyboardUtility.h"
#import "JSON.h"
#import "ACPVoiceActionView.h"

#define UEXChatKeyboard_LOCALIZEDSTRING(...) [EUtility uexPlugin:@"uexChatKeyboard" localizedString:__VA_ARGS__,nil]

typedef NS_ENUM(NSInteger,ZBMessageViewState) {
    ZBMessageViewStateShowFace,
    ZBMessageViewStateShowShare,
    ZBMessageViewStateShowNone,
};

@interface ChatKeyboard : NSObject<ZBMessageInputViewDelegate,ZBMessageShareMenuViewDelegate,ZBMessageManagerFaceViewDelegate,ACPVoiceActionViewDelegate>



@property (nonatomic, weak) EUExChatKeyboard *uexObj;

@property (nonatomic,strong) ZBMessageInputView *messageToolView;

@property (nonatomic,strong) ZBMessageManagerFaceView *faceView;

@property (nonatomic,strong) UIButton *sendButton;

@property (nonatomic,strong) ZBMessageShareMenuView *shareMenuView;

@property (nonatomic,assign) CGFloat previousTextViewContentHeight;

@property (nonatomic,assign) double animationDuration;

@property (nonatomic,assign) CGRect keyboardRect;

@property (nonatomic,strong) NSTimer *timerRecordUpdate;

@property (nonatomic,strong) ACPVoiceActionView *v;

@property (nonatomic,assign) CGFloat inputViewHeight;

@property (nonatomic,assign) BOOL isInit;

@property (nonatomic,strong) NSString *facePath;

@property (nonatomic,assign)CGFloat bottomOffset;
@property (nonatomic,strong)NSArray<NSString *> *keywords;

- (instancetype)initWithUexobj:(EUExChatKeyboard *)uexObj;

- (void)open;

- (void)close;

- (void)hideKeyboard;

- (void)changeWebView:(float)height;

- (void)insertAfterAt:(NSString *)str;

//通过关键字插入内容
- (void)insertString:(NSString *)str afterKeyword:(NSString *)keyword isReplacingKeyword:(BOOL)isReplacingKeyword;

@end
