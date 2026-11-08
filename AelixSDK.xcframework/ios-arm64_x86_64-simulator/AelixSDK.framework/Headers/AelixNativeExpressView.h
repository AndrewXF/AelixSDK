//
//  AelixNativeExpressView.h
//  AelixSDK
//
//  Created by MS on 2021/8/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AelixMedationFeedAdModel.h"

@class  AelixNativeExpress;
@interface AelixNativeExpressView : NSObject
- (instancetype)initWithViewController:(UIViewController *)controller;
// 信息流view
@property (nonatomic, strong) UIView *expressView;

// 信息流原始数据
@property (nonatomic, strong) AelixMedationFeedAdModel *adData;

// 媒体view
@property (nonatomic, strong) UIView *mediaView;
// 渠道标识
@property (nonatomic, copy) NSString *identifier;

// 媒体view
@property (nonatomic, weak) AelixNativeExpress *express;

- (void)render;

@end
