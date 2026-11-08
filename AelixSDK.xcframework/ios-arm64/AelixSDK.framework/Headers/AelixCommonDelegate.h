//
//  AelixCommonDelegate.h
//  Pods
//
//  Created by MS on 2021/1/16.
//

#ifndef AelixCommonDelegate_h
#define AelixCommonDelegate_h

@class AelixError;
// 策略相关的代理
@protocol AelixCommonDelegate <NSObject>

@optional

/// 成功加载 并返回 加载的队列的标识
- (void)aelixSuccessSortTag:(NSString *)sortTag;

/// 失败
/// @param error 聚合SDK的错误
/// @param description 每个渠道的错误详情, 部分情况下为nil  key的命名规则: 渠道名-index
- (void)aelixFailedWithError:(AelixError *)error description:(NSDictionary *)description;

/// 内部渠道开始加载时调用
- (void)aelixSupplierWillLoad:(NSString *)supplierId;
@end

#endif /* AelixBaseDelegate_h */
