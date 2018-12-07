//
//  GenerateToken.m
//  Example
//
//  Created by Marx Ma on 2018/10/20.
//  Copyright © 2018年 sogou. All rights reserved.
//

#import "GenerateToken.h"

#define TOKEN_HOST @"https://canary.speech.sogou.com/apis/auth/v1/create_token"

@implementation GenerateToken

+(void)requestTokenWithAppid:(NSString *)appid appkey:(NSString *)appkey uuid:(NSString *)uuid durationHours:(NSInteger)duration handler:(TokenResponseHandler)handler{
    NSURL *url = [NSURL URLWithString:TOKEN_HOST];
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc]initWithURL:url];
    [request setHTTPMethod:@"POST"];
    NSMutableDictionary *paramDict = [NSMutableDictionary new];
    [paramDict setObject:appid forKey:@"appid"];
    [paramDict setObject:appkey forKey:@"appkey"];
    NSString* timeStr = [NSString stringWithFormat:@"%zds",duration*60*60];
    [paramDict setObject:timeStr forKey:@"exp"];
    [paramDict setObject:uuid forKey:@"uuid"];

    NSError *jsonError;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:paramDict options:NSJSONWritingPrettyPrinted error:&jsonError];
    [request setHTTPBody:jsonData];
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *task = [session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        if (error) {
            handler(nil, error, NO);
            NSLog(@"CreateToken_Error:%@",[error localizedDescription]);
        }
        else{
            if (data) {
                NSString *dataStr = [[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
                NSMutableDictionary *jsonDict = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:&error];
                if(!error){
                    if(![[jsonDict allKeys]containsObject:@"token"]){
                        NSDictionary *errorUserInfo = @{
                                                        NSLocalizedDescriptionKey : @"token is nil.",
                                                        NSLocalizedFailureReasonErrorKey : @"get token failed"
                                                        };
                        handler(nil, [NSError errorWithDomain:@"com.sogou.token" code:10000 userInfo:errorUserInfo], NO);
                        return;
                    }
                    NSString *token = [jsonDict objectForKey:@"token"];
                    handler(token, nil, YES);
                    NSLog(@"ZY_Token 更新成功 JsonDict %@",jsonDict);
                }else{
                    NSLog(@"CreateToken_Error:%@ ResponseStr: %@",[error localizedDescription],dataStr);
                    handler(nil, error, YES);
                }

            }
            else{
                NSDictionary *errorUserInfo = @{
                                                NSLocalizedDescriptionKey : @"ASR authentication failed.",
                                                NSLocalizedFailureReasonErrorKey : @"get token failed"
                                                };
                handler(nil, [NSError errorWithDomain:@"com.sogou.token" code:10001 userInfo:errorUserInfo], NO);
                NSLog(@"CreateToken_Error:%@",[error localizedDescription]);
            }
        }
    }];
    [task resume];
}

@end
