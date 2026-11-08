//
//  AelixSDK.h
//  Aelix
//
//  Created by xiefei10 on 7/8/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 聚合SDK 配置项
@interface AelixMediationSDK: NSObject

/// 初始化appid，平台获取
@property (nonatomic, strong) NSString *appid;

@end

@interface AelixSDK : NSObject

/**
 初始化方法
 @param config 聚合配置信息
 */
+ (void)initializeWithConfig:(AelixMediationSDK *)config;


@end

NS_ASSUME_NONNULL_END
