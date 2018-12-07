//
//  SogouSpeechErrorCode.h
//  SogouSpeech
//
//  Created by Marx Ma on 2018/9/27.
//  Copyright © 2018年 sogou. All rights reserved.
//

#import <Foundation/Foundation.h>

/******************************************
 定义搜狗语音识别error domain
 ******************************************/
#define SGSPEECH_RECOGNIZE_ERRORDOMAIN_AUTH             @"com.sogou.speech.errordomain.auth"
#define SGSPEECH_RECOGNIZE_ERRORDOMAIN_NETWORK          @"com.sogou.speech.errordomain.asr.network"
#define SGSPEECH_RECOGNIZE_ERRORDOMAIN_AUDIO            @"com.sogou.speech.errordomain.asr.audio"
#define SGSPEECH_RECOGNIZE_ERRORDOMAIN_PREPROCESS       @"com.sogou.speech.errordomain.asr.preprocess"
#define SGSPEECH_RECOGNIZE_ERRORDOMAIN_OFFLINE          @"com.sogou.speech.errordomain.asr.offline"
#define SGSPEECH_RECOGNIZE_ERRORDOMAIN_SERVICE          @"com.sogou.speech.errordomain.asr.service"
#define SGSPEECH_RECOGNIZE_ERRORDOMAIN_UNKNOWN          @"com.sogou.speech.errordomain.asr.unknown"
#define SGSPEECH_RECOGNIZE_ERRORDOMAIN_OTHER            @"com.sogou.speech.errordomain.asr.other"
#define SGSPEECH_RECOGNIZE_ERRORDOMAIN_GRPC             @"com.sogou.speech.errordomain.asr.grpc"


typedef NS_ENUM(NSInteger, SogouSpeechErrorCode) {
    //1：网络相关
    //网络连接不可用
    ERROR_NETWORK_UNAVAILABLE = 1000,
    //网络连接超时
    ERROR_NETWORK_TIMEOUT = 1001,
    //网络IO异常
    ERROR_NETWORK_IO = 1002,
    //网络连接异常
    ERROR_NETWORK_CONN = 1003,
    //网络协议异常
    ERROR_NETWORK_PROTOCOL = 1004,
    //网络异常且超过重传次数
    ERROR_NETWORK_EXCEED_RETRY_TIMES = 1005,
    //URL异常
    ERROR_NETWORK_MALFORMED_URL = 1006,
    //解码异常
    ERROR_NETWORK_UNSUPPORTED_ENCODING = 1007,
    //域名解析出错时，报出java.lang.SecurityException
    ERROR_NETWORK_SECURITY_EXCEPTION = 1008,
    //其他网络错误
    ERROR_NETWORK_OTHER = 1009,
    
    //1100：GRPC层错误
    ERROR_GRPC_ERROR = 1100,
    ERROR_GRPC_CANCELLED = 1101,
    ERROR_GRPC_UNKNOWN = 1102,
    ERROR_GRPC_INVALID_ARGUMENT = 1103,
    ERROR_GRPC_DEADLINE_EXCEEDED = 1104,
    ERROR_GRPC_NOT_FOUND = 1105,
    ERROR_GRPC_ALREADY_EXISTS = 1106,
    ERROR_GRPC_PERMISSION_DENIED = 1107,
    ERROR_GRPC_RESOURCE_EXHAUSTED = 1108,
    ERROR_GRPC_FAILED_PRECONDITION = 1109,
    ERROR_GRPC_ABORTED = 1110,
    ERROR_GRPC_OUT_OF_RANGE = 1111,
    ERROR_GRPC_UNIMPLEMENTED = 1112,
    ERROR_GRPC_INTERNAL = 1113,
    ERROR_GRPC_UNAVAILABLE = 1114,
    ERROR_GRPC_DATA_LOSS = 1115,
    ERROR_GRPC_UNAUTHENTICATED = 1116,
    
    //1200：处理grpc错误
    //token请求失败
    ERROR_GRPC_TOKEN_REQUEST_FAILED = 1201,
    //token无效
    ERROR_GRPC_INVALID_TOKEN = 1202,
    //response错误
    ERROR_GRPC_BAD_RESPONSE = 1203,

    //2：录音相关
    //录音权限被禁用
     ERROR_AUDIO_FORBIDDEN = 2000,
    //AudioRecord为null
     ERROR_AUDIO_IS_NULL = 2001,
    //采样率传入错误
     ERROR_AUDIO_ILLEGAL_SAMPLE_RATE = 2002,
    //BUFFER_SIZE获取失败
     ERROR_AUDIO_ILLEGAL_BUFFER_SIZE = 2003,
    //构建AudioRecord时抛出IllegalArgumentException
     ERROR_AUDIO_ILLEGAL_ARGUMENT = 2004,
    //AudioRecord.read()报错
     ERROR_AUDIO_READ_FAILED = 2005,
    ///录音后立即停止录音(未读到数据)
     ERROR_AUDIO_END_WHEN_START_AUDIO = 2006,
    //录音初始化失败，AudioRecord初始化错误，audioRecord.getState() != AudioRecord.STATE_INITIALIZED
     ERROR_AUDIO_INITIALIZE_FAILED = 2007,
    //录音启动失败
     ERROR_AUDIO_START_FAILED = 2008,
    //录音停止失败
     ERROR_AUDIO_STOP_FAILED = 2009,
    //audioRecord释放失败
     ERROR_AUDIO_RELEASE_FAILED = 2010,
    //重复开启录音
    ERROR_AUDIO_DUPLICATED_STARTUP_OPTION = 2011,
    //录音太长
    ERROR_AUDIO_TOO_LONG = 2012,
    



    //3:预处理相关，AGC&&AEC&&VAD&&speex
    // AGC处理出错
     ERROR_AGC_PROCESS = 3000,
    //AGC初始化失败
     ERROR_AGC_INIT_FAILED = 3001,
    //AEC处理出错
     ERROR_AEC_PROCESS = 3100,
    //AEC初始化失败,init方法返回了非0值
     ERROR_AEC_INIT_FAILED = 3101,
    //VAD出错
     ERROR_VAD_UNKNOWN = 3200,
    //未检测到有效语音
     ERROR_VAD_SPEECH_TIMEOUT = 3201,
    //语音超出最大规定时长
     ERROR_VAD_SPEECH_TOO_LONG = 3202,
    //音频长度太短，且未检测到有效声音
     ERROR_VAD_AUDIO_TOO_SHORT = 3203,
    //传入的音频长度超过规定长度
     ERROR_VAD_AUDIO_INPUT_TOO_LONG = 3204,
    //VAD运行过程中缓存不够用，内存溢出，抛出BufferOverrunException异常
     ERROR_VAD_AUDIO_BUFFER_OVERRUN = 3205,
    //Speex编码错误，Speex编码后返回的数据是null
     ERROR_SPEEX_ENCODE = 3300,

    //4:离线引擎相关
    //解码器初始化失败
     ERROR_BF_DECODER_INIT_FAILED = 4000,
    //启动解码失败
     ERROR_BF_DECODER_START_FAILED = 4001,
    //解码失败
     ERROR_BF_DECODER_DECODE_FAILED = 4002,
    //模型文件不可用(模型文件路径传入错误)
     ERROR_BF_DECODER_MODEL_PATH_ERROR = 4003,
    //停止解码器工作失败，BFASRJNIInterface.stopDecode()返回值小于0
     ERROR_BF_DECODER_STOP_FAILED = 4005,
    //离线解码器最终识别结果为空（即解码器没有返回任何中间结果、最终结果)
     ERROR_BF_RECOGNITION_NO_MATCH = 4006,
    //语音处理器错误
     ERROR_BF_DECODER_ERROR = 4007,
    //离线鉴权失败（公司内app无鉴权）
     ERROR_BF_DECODER_AUTH_ILLEGAL = 4008,


    //5:识别服务相关
    //修改文字失败
     ERROR_CORRECTING_FAILED = 5101,

    //6:唤醒相关
    //建网失败
     ERROR_WAKE_UP_BUILD_NET_FAIL = 6000,
    //无效的垃圾词得分
     ERROR_WAKE_UP_INVALID_PARAM = 6001,
    //无效的配置文件或者复制文件失败
     ERROR_WAKE_UP_COPY_CONFIG = 6002,
    //设置配置文件路径失败
     ERROR_WAKE_UP_SET_DATA_PATH = 6003,
    //配置模型文件失败
     ERROR_WAKE_UP_SET_MODEL_PATH = 6004,
    //模型建网失败
     ERROR_WAKE_UP_BUILD_NET = 6005,
    //关键词文件不存在
     ERROR_WAKE_UP_INVALID_KEYWORD_PATH = 6006,
    //拷贝关键词文件失败
     ERROR_WAKE_UP_COPY_KEYWORD = 6007,
    //唤醒未初始化
     ERROR_WAKE_UP_KWS_UNPREPARED = 6008,
    //唤醒启动失败
     ERROR_WAKE_UP_KWS_INVALID_HANDLE = 6009,



    //7:鉴权相关
    //(鉴权包含离线鉴权和在线鉴权，在线鉴权错误码采用7100~7199；离线鉴权错误码采用7200~7299;离线和在线公有错误采用7000~7099)
    
    //鉴权应用包名错误，请检查是否与申请时一致
     ERROR_AUTH_PACKAGE_NAME = -7001,
    //鉴权appid/appkey错误，请检查是否与申请时一致
     ERROR_AUTH_APPID_KEY = -7002,
    
    //token 不可用
     ERROR_AUTH_TOKEN_UNAVAILABLE = 7100,
    
    
    
    //离线云端鉴权失败（云端判断appid错误，status=3）
     ERR_CLOUD_AUTENTICATION_FAIL = -100003,
    //离线云端鉴权响应异常（400，appid、包名、标识符三个参数有缺失）
     ERR_ILLEGAL_HTTP_RESPONSE_STATUS = -100004,
    //离线鉴权云端请求异常
     ERR_EXCEPTION_WITHIN_AUTHENTICATION_HTTP_REQEUST = -100005,
    //离线鉴权线程处理失败
     ERR_EXECUTOR_SHUTDOWN_WHEN_PERFORM_HTTP_REQUEST = -100006,
    //离线鉴权解析响应错误
     ERR_SDK_PARSE_HTTP_RESPONSE = -100007,
    //本地获取appid失败
     ERR_OBTAIN_APPID = -100008,
    //本地获取包名失败
     ERR_OBTAIN_PACKAGE_NAME = -100009,
    //本地获取的appid与license中的不一致
     ERR_INVALID_APPID = -100010,
    //本地获得的包名与license中的不一致
     ERR_INVALID_PACKAGE_NAME = -100011,
    //访问授权配置文件失败，status=1
     ERR_SERVER_GET_APPID_FAILED = -100012,
    //配置与约定不匹配，status=2
     ERR_SERVER_APPID_INFO_WRONG_FORMAT = -100013,
    //转发服务无法访问鉴权服务，status= 4
     ERR_SERVER_AUTHENTICATE_SPEECH_SERVER_INAVAILABLE = -100014,
    //超出次数限制， status =5
     ERR_SERVER_AUTHENTICATE_EXCEEDS_MAX_LIMIT = -100015,
    //上传包名错误，与注册信息不匹配，status=6
     ERR_SERVER_AUTHENTICATE_WRONG_PACKAGE_NAME = -100016,
    //时间过期，status=7
     ERR_SERVER_AUTHENTICATE_DATE_EXPIRE = -100017,

    //8：后端返回状态码
    //    there_is_no_decoded_result
     ERROR_SERVER_NO_DECODED_RESULT = 8000,
    //decode_failed
     ERROR_SERVER_DECODE_FAILED = 8001,
    //    server_is_busy
     ERROR_SERVER_IS_BUSY = 8048,
    //voice_content_is_empty
     ERROR_SERVER_VOICE_CONTENT_EMPTY = 8056,
    //socket_connection_failed
     ERROR_SERVER_SOCKET_CONNECTION_FAILED = 8060,
    //    parsing_request_body_failed
     ERROR_SERVER_PARSE_REQUEST_BODY_FAILED = 8062,
    //    request_body_is_empty
     ERROR_SERVER_REQUEST_BODY_EMPTY = 8063,
    //request_method_is_illegal
     ERROR_SERVER_REQUEST_METHOD_ILLEGAL = 8064,
    //服务端返回的response状态码不是200
     ERROR_SERVER_RESPONSE_NOT_200 = 8200,

    //9:其他
    //json解析异常
     ERROR_ANALYZE_JSON = 9000,
    //数字格式化错误
     ERROR_NUMBER_FORMAT = 9001,
    //其他错误
     ERROR_OTHER = 9010,
};

