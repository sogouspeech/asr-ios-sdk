//
//  SogouSpeechDelegate.h
//  SogouSpeech
//
//  Created by sogou on 2018/6/25.
//  Copyright © 2018年 sogou. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 在线语音识别
 * MSG_ASR_ONLINE_GET_TOKEN_SUCCESS : 获取token成功(鉴权成功)
 * MSG_ASR_ONLINE_RESULT: 语音识别结果
 * MSG_ASR_ONLINE_SPEECH_START: 检测到语音开始(说话声)
 * MSG_ASR_ONLINE_SPEECH_END: 检测到语音结束(说话声)
 * MSG_ASR_ONLINE_SPEECH_NOT_FOUND: 未检测到有效语音，提示用户说话(说话声)
 * MSG_ASR_ONLINE_READ: 本次识别服务就绪,等待传入数据
 * MSG_ASR_ONLINE_READ: 识别中
 * MSG_ASR_ONLINE_COMPLETED: 本次语音识别结束
 * MSG_ASR_ONLINE_TERMINATION: 语音识别终止
 * MSG_ASR_ONLINE_AUDIO_DATA: 识别的音频数据回调
 * MSG_ASR_ONLINE_AUDIO_DATA: 无法同时开启两个语音识别
 * MSG_ASR_ONLINE_WEBHOOK:webhook中转响应结果。
 */
extern NSString* MSG_ASR_ONLINE_GET_TOKEN_SUCCESS;
extern NSString* MSG_ASR_ONLINE_RESULT ;
extern NSString* MSG_ASR_ONLINE_SPEECH_END ;//(说话声)
extern NSString* MSG_ASR_ONLINE_SPEECH_START ;//(说话声)
extern NSString* MSG_ASR_ONLINE_SPEECH_NOT_FOUND;//(说话声)
extern NSString* MSG_ASR_ONLINE_WORKING ;
extern NSString* MSG_ASR_ONLINE_READY ;
extern NSString* MSG_ASR_ONLINE_COMPLETED ;
extern NSString* MSG_ASR_ONLINE_TERMINATION ;
extern NSString* MSG_ASR_ONLINE_AUDIO_DATA ;
extern NSString* MSG_ASR_ONLINE_DUPLICATE;
extern NSString* MSG_ASR_ONLINE_WEBHOOK;

/**
 * 录音功能回调相关参数
 */
extern NSString* MSG_AUDIO_RECORDER_START ;
extern NSString* MSG_AUDIO_RECORDER_STOP ;
extern NSString* MSG_AUDIO_RECORDER_VOLUME ;

/**
 * 唤醒功能回调相关参数
 */
extern NSString* MSG_WAKEUP_INIT_SUCC ;
extern NSString* MSG_WAKEUP_SUCC ;

/**
 * 其他功能
 * ...
 */

@protocol SogouSpeechDelegate <NSObject>

@optional

/**
 消息回调(主线程)

 @param eventName 消息名称
 @param param 消息内容
 */
- (void) onEvent: (NSString*) eventName param: (NSObject*) param;

/**
 错误回调(主线程)

 @param error 具体错误
 */
- (void) onError: (NSError*) error;
                                
@end
