//
//  ViewController.m
//  asr-iOS-sdk
//  SDK function demo
//
//  Created by sogou on 2018/12/10.
//  Copyright 2018 Sogou Inc. All rights reserved.
//  Use of this source code is governed by the Apache 2.0
//  license that can be found in the LICENSE file.
//

#import "ViewController.h"
#import "GenerateToken.h"
#import "SogoSpeechSDK.h"


#error 填写申请到的appid和appkey
NSString* __appid = @"your app id";
NSString* __appkey = @"your app key";


@interface ViewController () <SogouSpeechDelegate>

@property (nonatomic, strong) SogouSpeechManager *speechManager;

@property (nonatomic, strong) UINavigationController *settingViewController;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [SogoSpeechSDK sdkVersion];
    
    NSString *filepathSpeex = [NSTemporaryDirectory() stringByAppendingPathComponent:@"speex.data"];
    [SogouSpeechPropertySetting setProperty:filepathSpeex forKey:ASR_ONLINE_DEBUG_SAVE_SPEEX_PATH];
    NSString *filepathVad = [NSTemporaryDirectory() stringByAppendingPathComponent:@"vad.pcm"];
    [SogouSpeechPropertySetting setProperty:filepathVad forKey:ASR_ONLINE_DEBUG_SAVE_VAD_PATH];
    [SogouSpeechPropertySetting setProperty:@NO forKey:ASR_ONLINE_ENABLE_DEBUG_LOG_BOOL];
    NSString *filepathWav = [NSTemporaryDirectory() stringByAppendingPathComponent:@"audio.wav"];
    [SogouSpeechPropertySetting setProperty:filepathWav forKey:ASR_ONLINE_DEBUG_SAVE_WAV_PATH];
    
    [SogouSpeechPropertySetting setProperty:@"default" forKey:ASR_ONLINE_MODEL];
    
#error 填写将要使用的服务域名
    [SogouSpeechPropertySetting setProperty:@"canary.speech.sogou.com:443" forKey:ASR_ONLINE_HOST_ADDRESS];
    
    self.speechManager = [[SogouSpeechManager alloc] init];
    self.speechManager.delegate = self;
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (IBAction)startRec:(id)sender {
    self.textView.text = @"";
    [self.speechManager sendCommand:ASR_ONLINE_START withData:nil];
}

- (IBAction)stopRec:(id)sender {
    [self.speechManager sendCommand:ASR_ONLINE_STOP withData:nil];
}

- (IBAction)requestToken:(id)sender {
    [self getNewToken];
}

- (void)onError:(NSError *)error {
    [self.textView setText:[NSString stringWithFormat:@"%@",error]];
}

- (void)onEvent:(NSString *)eventName param:(NSObject *)param{
    if ([eventName isEqualToString:MSG_ASR_ONLINE_RESULT]) {
        if ([param isKindOfClass:[NSString class]] && ((NSString*)param).length > 0) {
            [self.textView setText:(NSString*)param];
        }
    }
    else if([eventName isEqualToString:MSG_ASR_ONLINE_GET_TOKEN_SUCCESS]) {
        NSString * textStr = [self.textViewStauts.text stringByAppendingFormat:@"%@\n",@"token获取成功"];
        [self.textViewStauts setText:textStr];
    }
    else if([eventName isEqualToString:MSG_ASR_ONLINE_READY]) {
        NSString * textStr = [self.textViewStauts.text stringByAppendingFormat:@"%@\n",(NSString*)param];
        [self.textViewStauts setText:textStr];
    }
    else if([eventName isEqualToString:MSG_ASR_ONLINE_WORKING]) {
        NSString * textStr = [self.textViewStauts.text stringByAppendingFormat:@"%@\n",(NSString*)param];
        [self.textViewStauts setText:textStr];
    }
    else if([eventName isEqualToString:MSG_ASR_ONLINE_SPEECH_START]) {
        NSString * textStr = [self.textViewStauts.text stringByAppendingFormat:@"%@\n",(NSString*)param];
        [self.textViewStauts setText:textStr];
    }
    else if([eventName isEqualToString:MSG_ASR_ONLINE_SPEECH_END]) {
        NSString * textStr = [self.textViewStauts.text stringByAppendingFormat:@"%@\n",(NSString*)param];
        [self.textViewStauts setText:textStr];
    }
    else if([eventName isEqualToString:MSG_AUDIO_RECORDER_START]) {
        NSString * textStr = [self.textViewStauts.text stringByAppendingFormat:@"%@\n",(NSString*)param];
        [self.textViewStauts setText:textStr];
    }
    else if([eventName isEqualToString:MSG_AUDIO_RECORDER_STOP]) {
        NSString * textStr = [self.textViewStauts.text stringByAppendingFormat:@"%@\n",(NSString*)param];
        [self.textViewStauts setText:textStr];
    }
    else if([eventName isEqualToString:MSG_ASR_ONLINE_COMPLETED]) {
        NSString * textStr = [self.textViewStauts.text stringByAppendingFormat:@"%@\n",(NSString*)param];
        [self.textViewStauts setText:textStr];
    }
    else if([eventName isEqualToString:MSG_ASR_ONLINE_TERMINATION]) {
        NSString * textStr = [self.textViewStauts.text stringByAppendingFormat:@"%@\n",(NSString*)param];
        [self.textViewStauts setText:textStr];
    }
    else if([eventName isEqualToString:MSG_ASR_ONLINE_AUDIO_DATA]) {
        
    }
    else if([eventName isEqualToString:MSG_AUDIO_RECORDER_VOLUME]) {
        [self.labelVolume setText: [NSString stringWithFormat:@"%@",(NSNumber*)param]];
    }
    else if([eventName isEqualToString:MSG_ASR_ONLINE_SPEECH_NOT_FOUND]) {
        NSString * textStr = [self.textViewStauts.text stringByAppendingFormat:@"%@\n",(NSString*)param];
        [self.textViewStauts setText:textStr];
    }
    else if([eventName isEqualToString:MSG_ASR_ONLINE_WEBHOOK]){
        NSDictionary * dic = (NSDictionary*)param;
        NSString* str = [dic objectForKey:@"semantic"];
        NSLog(@"%@",str);
        [self.textView setText:str];
    }
    
    [self.textView scrollRangeToVisible:NSMakeRange(self.textView.text.length - 1, 1)];
    [self.textViewStauts scrollRangeToVisible:NSMakeRange(self.textViewStauts.text.length - 1, 1)];
}

- (void)getNewToken{
    NSString * uuid = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
    [GenerateToken requestTokenWithAppid:__appid appkey:__appkey uuid:uuid durationHours:10 handler:^(NSString *token, NSError *error, BOOL success) {
        [SogouSpeechPropertySetting setProperty:token forKey:SOGOU_SPEECH_TOKEN];
        [SogouSpeechPropertySetting setProperty:__appid forKey:SOGOU_SPEECH_APPID];
        [SogouSpeechPropertySetting setProperty:uuid forKey:SOGOU_SPEECH_UUID];
        NSLog(@"token : %@", token);
        NSLog(@"error : %@", error);
    }];
}

@end

