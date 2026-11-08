//
//  AelixSupplierModel.h
//  Demo
//
//  Created by xiefei on 2020/11/18.
//

#import <Foundation/Foundation.h>

@class AelixSupplierModel;
@class AelixSDKSetting;
@class AelixSDKSupplier;
@class AelixBaseAdPosition;
//typedef NS_ENUM(NSUInteger, AelixEventType) {
    /// 点击
//    AelixSDKSdkSupplierRepoClicked,
//    /// 数据拉取成功
//    AelixSDKSdkSupplierRepoSucceeded,
//    /// 广告物料加载成功
//    AelixEventType_NETWORK_FILL,
//    /// 广告物料加载失败
//    AelixEventType_NETWORK_FILLFailed,
//    /// 曝光成功
//    AelixSDKSdkSupplierRepoImped,
//    /// 曝光失败
//    AelixSDKSdkSupplierRepoFaileded,
//};


NS_ASSUME_NONNULL_BEGIN

#pragma mark - Object interfaces

@interface AelixSupplierModel : NSObject
@property (nonatomic, strong) NSMutableArray<AelixSDKSetting *> *rules;
@property (nonatomic, strong) NSMutableArray<AelixSDKSupplier *> *suppliers;
@property (nonatomic, copy)   NSString *sortTag;

@end

@interface AelixSDKSetting : NSObject
@property (nonatomic, strong) NSMutableArray<NSNumber *> *sort;
@property (nonatomic, assign) NSInteger percent;
@property (nonatomic, copy)   NSString *tag;



@end

@interface AelixSDKSupplier : NSObject
@property (nonatomic, copy)   NSString *appId;
@property (nonatomic, copy)   NSString *adspotId;
@property (nonatomic, copy)   NSString *tag;
@property (nonatomic, strong)   NSNumber *index;
@property (nonatomic, assign)   NSInteger adType;
@property (nonatomic, strong) AelixBaseAdPosition *adPosition;
@end

NS_ASSUME_NONNULL_END
