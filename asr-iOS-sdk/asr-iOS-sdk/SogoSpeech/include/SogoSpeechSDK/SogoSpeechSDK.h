//
//  SogoSpeechSDK.h
//  SogouSpeech
//  Set of header files needed by the SDK
//
//  Created by sogou on 2018/12/10.
//  Copyright 2018 Sogou Inc. All rights reserved.
//  Use of this source code is governed by the Apache 2.0
//  license that can be found in the LICENSE file.
//

#import <Foundation/Foundation.h>

#import "SogouSpeechErrorCode.h"
#import "SogouSpeechDelegate.h"
#import "SogouSpeechPropertySetting.h"
#import "SogouSpeechManager.h"

#import <SogouSpeech/sogou/speech/asr/v1/Asr.pbobjc.h>

@interface SogoSpeechSDK : NSObject

+ (NSString *)sdkVersion;

@end
