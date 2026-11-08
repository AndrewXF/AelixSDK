//
//  AelixSupplierDelegate.h
//  Demo
//
//  Created by xiefei on 2020/11/25.
//

#ifndef AelixSupplierDelegate_h
#define AelixSupplierDelegate_h

@class AelixSupplierModel;
@class AelixSDKSupplier;
@protocol AelixSupplierDelegate <NSObject>

@optional

/// 加载策略Model成功
- (void)aelixBaseAdapterLoadSuccess:(nonnull AelixSupplierModel *)model;

/// 加载策略Model失败
- (void)aelixBaseAdapterLoadError:(nullable NSError *)error;

/// 加载的 sortTag
- (void)aelixBaseAdapterLoadSortTag:(NSString *)sortTag;

- (void)aelixBaseAdapterLoadAndShow;


/// 返回下一个渠道的参数
/// @param supplier 被加载的渠道
/// @param error 异常信息
- (id)aelixBaseAdapterLoadSuppluer:(nullable AelixSDKSupplier *)supplier error:(nullable NSError *)error;

@end

#endif /* AelixSupplierDelegate_h */
