//
//  GenerateToken.h
//  asr-iOS-sdk
//  Example of token application
//
//  Created by sogou on 2018/12/10.
//  Copyright 2018 Sogou Inc. All rights reserved.
//  Use of this source code is governed by the Apache 2.0
//  license that can be found in the LICENSE file.
//

#import <Foundation/Foundation.h>


typedef void (^TokenResponseHandler) (NSString *token, NSError *error, BOOL success);

@interface GenerateToken : NSObject

+ (void)requestTokenWithAppid:(NSString *)appid
                       appkey:(NSString *)appkey
                         uuid:(NSString *)uuid
                durationHours:(NSInteger)duration
                      handler:(TokenResponseHandler)handler;

@end

