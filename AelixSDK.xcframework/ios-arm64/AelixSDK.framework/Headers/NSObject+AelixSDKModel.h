
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (AelixSDKModel)

+ (nullable instancetype)aelixSDK_modelWithJSON:(id)json;

+ (nullable instancetype)aelixSDK_modelWithDictionary:(NSDictionary *)dictionary;

- (BOOL)aelixSDK_modelSetWithJSON:(id)json;

- (BOOL)aelixSDK_modelSetWithDictionary:(NSDictionary *)dic;

- (nullable id)aelixSDK_modelToJSONObject;

- (nullable NSData *)aelixSDK_modelToJSONData;

- (nullable NSString *)aelixSDK_modelToJSONString;

- (nullable id)aelixSDK_modelCopy;

- (void)aelixSDK_modelEncodeWithCoder:(NSCoder *)aCoder;

- (id)aelixSDK_modelInitWithCoder:(NSCoder *)aDecoder;

- (NSUInteger)aelixSDK_modelHash;

- (BOOL)aelixSDK_modelIsEqual:(id)model;

- (NSString *)aelixSDK_modelDescription;

@end

@interface NSArray (AelixSDKModel)

+ (nullable NSArray *)aelixSDK_modelArrayWithClass:(Class)cls json:(id)json;

@end

@interface NSDictionary (AelixSDKModel)

+ (nullable NSDictionary *)aelixSDK_modelDictionaryWithClass:(Class)cls json:(id)json;
@end

@protocol AelixSDKModel <NSObject>
@optional

+ (nullable NSDictionary<NSString *, id> *)modelCustomPropertyMapper;

+ (nullable NSDictionary<NSString *, id> *)modelContainerPropertyGenericClass;

+ (nullable Class)modelCustomClassForDictionary:(NSDictionary *)dictionary;

+ (nullable NSArray<NSString *> *)modelPropertyBlacklist;

+ (nullable NSArray<NSString *> *)modelPropertyWhitelist;

- (NSDictionary *)modelCustomWillTransformFromDictionary:(NSDictionary *)dic;

- (BOOL)modelCustomTransformFromDictionary:(NSDictionary *)dic;

- (BOOL)modelCustomTransformToDictionary:(NSMutableDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
