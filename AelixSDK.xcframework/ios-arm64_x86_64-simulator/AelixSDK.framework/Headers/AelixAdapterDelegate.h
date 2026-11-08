//
//  AelixAdapterDelegate.h
//  Aelix
//
//  Created by xiefei10 on 7/15/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AelixBaseAdPosition;

@protocol AelixAdapterDelegate <NSObject>

- (void)adLoadSuccessForPriceCompare:(AelixBaseAdPosition *)adpater;

- (void)adAdapterLoadFailed:(AelixBaseAdPosition *)adpater;

@end

NS_ASSUME_NONNULL_END
