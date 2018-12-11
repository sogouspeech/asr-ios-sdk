//
//  SogouSpeechManager.h
//  SogouSpeech
//  Declare the control instructions and methods of the SDK
//
//  Created by sogou on 2018/12/10.
//  Copyright 2018 Sogou Inc. All rights reserved.
//  Use of this source code is governed by the Apache 2.0
//  license that can be found in the LICENSE file.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN



/**
 * 鉴权指令
 */
extern NSString* SOGOU_SPEECH_AUTHENTICATION ;
/**
 * 在线识别控制命令
 * ----------------------------------------------
 * --> 创建ASR引擎；
 * --> ASR引擎开启；
 * --> 识别；
 * --> 停止；
 * --> 取消；
 * --> 销毁ASR资源。
 */
extern NSString* ASR_ONLINE_CREATE ;
extern NSString* ASR_ONLINE_START ;
extern NSString* ASR_ONLINE_RECOGIZE ;
extern NSString* ASR_ONLINE_STOP ;
extern NSString* ASR_ONLINE_CANCEL ;
extern NSString* ASR_ONLINE_DESTROY ;

/**
 * 唤醒控制指令
 */
extern NSString* WAKEUP_START;

/**
 * 其他功能
 * ...
 */

@protocol SogouSpeechDelegate;

@interface SogouSpeechManager : NSObject

/**
 * 操作命令的控制方法，控制启停、执行等操作
 * @param command 操作指令
 * @param dataObj 相关参数
 */
- (void)sendCommand:(NSString *)command withData:(NSObject* _Nullable)dataObj;


/**
 设置委托类，用于获取回调信息
 
 @param delegate 委托类实例
 */
- (void)setDelegate:(id<SogouSpeechDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
