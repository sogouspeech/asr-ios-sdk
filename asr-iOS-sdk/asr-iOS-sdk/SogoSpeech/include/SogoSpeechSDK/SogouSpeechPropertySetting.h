//
//  SogouSpeechPropertySetting.h
//  SogouSpeech
//
//  Created by Marx Ma on 2018/9/26.
//  Copyright © 2018年 sogou. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * APPID app在搜狗的唯一标识
 * 
 */
extern NSString* SOGOU_SPEECH_APPID;
extern NSString* SOGOU_SPEECH_UUID;
extern NSString* SOGOU_SPEECH_TOKEN;




/**
 语音功能选择，包括识别、唤醒、语义等
 */
typedef NS_OPTIONS(NSUInteger, SGSpeechModeOption)
{
    /* 在线识别 */
    SGSpeechModeOptionASROnline             = 0x1,
    /* 离线识别 */
    SGSpeechModeOptionASROffline            = 0x2,
    /* 离线固定句式识别 */
    SGSpeechModeOptionLimitedASROffline     = 0x4,
    /* 唤醒*/
    SGSpeechModeOptionWakeUp                = 0x8,
    /* 在线语义识别 ，必须与在线识别同时使用*/
    SGSpeechModeOptionNLUOnline             = 0x11,
//    /* 离线语义识别 ，必须与离线识别同时使用*/
//    SGSpeechModeOptionNLUOffline            = 0x22,
};

/**
 语音功能选择，输入参数为SGSpeechModeOption
 */
extern NSString* SOGOU_SPEECH_MODE_OPTION;

/**
 * 在线识别参数设置
 * ----------------------------------------------
 *
 *
 * ASR_ONLINE_VAD_ENABLE_BOOL：
 *      VAD 开关
 * ASR_ONLINE_VAD_BOS_FLOAT:
 *      语音后端超时检测，如果已经开始说话后，间隔超过 ASR_ONLINE_VAD_BOS_FLOAT 时间不说话，则返回 OUT_OF_INTERVAL_TIME 消息，此后将进入不可再输入状态。
 * ASR_ONLINE_VAD_EOS_FLOAT:
 *      语音后端超时检测，如果已经开始说话后，间隔超过 ASR_VAD_EOS_FLOAT 时间不说话，则返回 MSG_SPEECH_END 消息，此后将进入不可再输入状态。
 * ASR_ONLINE_VAD_MAX_INTERVAL_INT：
 *      VAD检测到有效声音的最大时长，超过该时长，vad将返回 ERROR_VAD_SPEECH_TIMEOUT 消息，此后将进入不可再输入状态。
 * ASR_ONLINE_VAD_MAX_AUDIO_LENGTH_INT：
 *      VAD可检测的最长音频长度，如果音频长度超过该阈值，则返回ERROR_AUDIO_TOO_LONG消息，此后将进入不可再输入状态。
 * ASR_ONLINE_VAD_LONGMODE_BOOL:
 *      VAD长时模式，开启后可以一直进行输入，vad将过滤掉无效声音/静音，返回有效声音。(暂时等效于enable_vad = false)
 *      此模式下，ASR_VAD_BOS_FLOAT，ASR_VAD_EOS_FLOAT，ASR_VAD_MAX_INTERVAL_FLOAT 失效。
 * ASR_ONLINE_VAD_SILENCE_ALERT_FLOAT:
 *      VAD检测出（ASR_ONLINE_VAD_SILENCE_ALERT_FLOAT）秒不说话后，将产生一个回调，可用于提示用户说话。
 *
 * ASR_ONLINE_AUDIO_CODING_INT:
 *      音频编码格式:
 *      value = 1 Uncompressed 16-bit signed little-endian samples (Linear PCM).
 *      value = 2.[`FLAC`](https://xiph.org/flac/documentation.html) (Free Lossless Audio Codec)
 *      value = 100. speex压缩格式
 * ASR_ONLINE_LANGUAGE_STRING:
 *      识别的语种。
 *
 * ASR_ONLINE_AUTH_TOKEN_STRING:
 *      语音识别token，鉴权用。
 *
 * ASR_ONLINE_SEND_PACK_LEN_INT:
 *      发送请求时语音包长，取值范围（3200，8000），单位Short。必须设置200ms的整数倍，200ms的数据长度为3200Short，最长不得超过500ms。
 *
 * ASR_ONLINE_MODEL:
 *      分环境设置：包括通用、地图导航类、搜索(search)等。
 */

extern NSString* ASR_ONLINE_VAD_ENABLE_BOOL;
extern NSString* ASR_ONLINE_VAD_BOS_FLOAT;
extern NSString* ASR_ONLINE_VAD_EOS_FLOAT;
extern NSString* ASR_ONLINE_VAD_MAX_INTERVAL_INT;
extern NSString* ASR_ONLINE_VAD_MAX_AUDIO_LENGTH_INT;
extern NSString* ASR_ONLINE_VAD_LONGMODE_BOOL;
extern NSString* ASR_ONLINE_VAD_SILENCE_ALERT_FLOAT;

extern NSString* ASR_ONLINE_AUDIO_CODING_INT;
extern NSString* ASR_ONLINE_LANGUAGE_STRING;
extern NSString* ASR_ONLINE_AUTH_TOKEN_STRING;
extern NSString* ASR_ONLINE_SEND_PACK_LEN_INT;
extern NSString* ASR_ONLINE_MODEL;


/**
 * WAKEUP_IS_NEEDED:是否需要唤醒功能
 * WAKEUP_ONESHOT_IS_NEEDED：有了唤醒之后，是否需要oneshot功能
 * WAKEUP_NEED_FORCE_INIT:是否强行建模
 * WAKEUP_KEYWORD_PATH：本地唤醒词路径
 */
extern NSString* WAKEUP_IS_NEEDED;
extern NSString* WAKEUP_ONESHOT_IS_NEEDED;
extern NSString* WAKEUP_NEED_FORCE_INIT;
extern NSString* WAKEUP_KEYWORD_PATH;

/**
 * ASR_ONLINE_ENABLE_DEBUG_LOG_BOOL:
 *      是否打印debug日志
 * ASR_ONLINE_DEBUG_SAVE_VAD_PATH:
 *      调试，保存vad数据至传入路径。
 * ASR_ONLINE_DEBUG_SAVE_SPEEX_PATH:
 *      保存speex数据至传入的路径。
 * ASR_ONLINE_DEBUG_SAVE_REQUEST_DATA_PATH:
 *      保存传给语音服务的数据，路径。
 * ASR_ONLINE_DEBUG_SAVE_VAD_PATH:
 *      保存原始录音的wav文件路径。
 */
extern NSString* ASR_ONLINE_ENABLE_DEBUG_LOG_BOOL;
extern NSString* ASR_ONLINE_DEBUG_SAVE_VAD_PATH;
extern NSString* ASR_ONLINE_DEBUG_SAVE_SPEEX_PATH;
extern NSString* ASR_ONLINE_DEBUG_SAVE_REQUEST_DATA_PATH;
extern NSString* ASR_ONLINE_DEBUG_SAVE_WAV_PATH;


/**
 * SGASR_LANGUAGE_CHINESE:
 *      汉语普通话
 * SGASR_LANGUAGE_ENGLISH:
 *      英语
 * SGASR_LANGUAGE_KOREAN:
 *      韩语
 * SGASR_LANGUAGE_JAPANESE:
 *      日语
 */
extern NSString* SGASR_LANGUAGE_CHINESE ;
extern NSString* SGASR_LANGUAGE_ENGLISH ;
extern NSString* SGASR_LANGUAGE_KOREAN  ;
extern NSString* SGASR_LANGUAGE_JAPANESE;

/**
 中转服务设置
 */
extern NSString* ASR_ONLINE_WEBHOOK_NAME;
extern NSString* ASR_ONLINE_WEBHOOK_URI ;
extern NSString* ASR_ONLINE_WEBHOOK_EXTRA;

/**
 服务地址设置，可使用默认值。
 */
extern NSString* ASR_ONLINE_HOST_ADDRESS;

/**
 个性化设置
 */
@interface SogouSpeechPropertySetting : NSObject

/**
 参数设置

 @param property 参数值
 @param key 参数名称
 @return 是否设置成功
 */
+ (BOOL)setProperty:(id)property forKey:(NSString* )key;

/**
 获取参数值

 @param key 参数名称
 @return 参数值
 */
+ (id)getPropertyForKey:(NSString* )key;

@end

