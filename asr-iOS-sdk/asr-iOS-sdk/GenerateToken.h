//
//  GenerateToken.h
//  Example
//
//  Created by Marx Ma on 2018/10/20.
//  Copyright © 2018年 sogou. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef void (^TokenResponseHandler) (NSString* token, NSError *error, BOOL success);


@interface GenerateToken : NSObject

+ (void)requestTokenWithAppid:(NSString *)appid appkey:(NSString *)appkey uuid:(NSString *)uuid durationHours:(NSInteger)duration handler:(TokenResponseHandler)handler;

@end

