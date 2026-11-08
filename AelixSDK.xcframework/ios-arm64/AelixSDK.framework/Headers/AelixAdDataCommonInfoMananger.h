//
//  AelixAdDataCommonInfoMananger.h
//  Aelix
//
//  Created by xiefei10 on 8/6/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AelixAdDataCommonInfoMananger : NSObject

@property (nonatomic, copy) NSString *idfa;
@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSString *appVersion;
@property (nonatomic, copy) NSString *bundle;
@property (nonatomic, copy) NSString *systemVersion;
@property (nonatomic, copy) NSString *screenSize;
@property (nonatomic, copy) NSString *model;
/*!
 @property sessionId
 @abstract session Id 日志用
 */
@property (nonatomic, assign) long long sessionId;
@property (nonatomic, assign) long long enterBackgroundTime;

+ (instancetype)shared;


@end

NS_ASSUME_NONNULL_END
