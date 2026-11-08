//
//  AelixConfig.h
//  aelixlib
//
//  Created by allen on 2024/9/12.
//  Copyright © 2019 Bayescom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AelixMediationSDK.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,AelixSDKLogLevel) {
    AelixSDKLogLevel_None  = 0, // 不打印
    AelixSDKLogLevel_Fatal,
    AelixSDKLogLevel_Error,
    AelixSDKLogLevel_Warning,
    AelixSDKLogLevel_Info,
    AelixSDKLogLevel_Debug,
};


// MARK: ======================= SDK =======================
extern NSString *const AelixSDKVersion;

extern NSString *const AELIX_SDK_TAG_GDT;
extern NSString *const AELIX_SDK_TAG_CSJ;
extern NSString *const AELIX_SDK_TAG_KS;
extern NSString *const AELIX_SDK_TAG_BAIDU;
extern NSString *const AELIX_SDK_TAG_UBIX;
extern NSString *const AELIX_SDK_TAG_MS;
extern NSString *const AELIX_SDK_TAG_QM;
extern NSString *const AELIX_SDK_TAG_DM;

extern NSString *const AelixSDKSdkTypeAdName;
extern NSString *const AelixSDKSdkTypeAdNameSplash;
extern NSString *const AelixSDKSdkTypeAdNameBanner;
extern NSString *const AelixSDKSdkTypeAdNameInterstitial;
extern NSString *const AelixSDKSdkTypeAdNameFullScreenVideo;
extern NSString *const AelixSDKSdkTypeAdNameNativeExpress;
extern NSString *const AelixSDKSdkTypeAdNameRewardVideo;

@interface AelixConfig : NSObject

/// SDK版本
+ (NSString *)sdkVersion;

+ (instancetype)shareInstance;

/// 控制台log级别
/// 0 不打印
/// 1 打印fatal
/// 2 fatal + error
/// 3 fatal + error + warning
/// 4 fatal + error + warning + info
/// 5 全部打印
@property (nonatomic, assign) AelixSDKLogLevel level;

///初始配置
@property (nonatomic, strong) AelixMediationSDK *configModel;

@end

NS_ASSUME_NONNULL_END
