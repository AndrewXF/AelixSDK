//
//  AelixError.h
//  Demo
//
//  Created by xiefei on 2020/11/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 策略相关
typedef NS_ENUM(NSUInteger, AelixErrorCode) {
    AelixErrorCode_101    =    101,
    AelixErrorCode_102    =    102,
    AelixErrorCode_103    =    103,
    AelixErrorCode_104    =    104,
    AelixErrorCode_105    =    105,
    AelixErrorCode_110    =    110,
    AelixErrorCode_111    =    111,
    AelixErrorCode_112    =    112,
    AelixErrorCode_113    =    113,
    AelixErrorCode_114    =    114, //广告填充失败
    AelixErrorCode_115    =    115,
    AelixErrorCode_116    =    116
};

@interface AelixError : NSObject

@property (nonatomic, assign) AelixErrorCode errorCode;

+ (instancetype)errorWithCode:(AelixErrorCode)code;

+ (instancetype)errorWithCode:(AelixErrorCode)code obj:(id)obj;

- (NSError *)toNSError;

@end

NS_ASSUME_NONNULL_END
