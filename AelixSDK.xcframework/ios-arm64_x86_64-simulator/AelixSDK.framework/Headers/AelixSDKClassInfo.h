
#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type encoding's type.
 */
typedef NS_OPTIONS(NSUInteger, AelixSDKEncodingType) {
    AelixSDKEncodingTypeMask       = 0xFF, ///< mask of type value
    AelixSDKEncodingTypeUnknown    = 0, ///< unknown
    AelixSDKEncodingTypeVoid       = 1, ///< void
    AelixSDKEncodingTypeBool       = 2, ///< bool
    AelixSDKEncodingTypeInt8       = 3, ///< char / BOOL
    AelixSDKEncodingTypeUInt8      = 4, ///< unsigned char
    AelixSDKEncodingTypeInt16      = 5, ///< short
    AelixSDKEncodingTypeUInt16     = 6, ///< unsigned short
    AelixSDKEncodingTypeInt32      = 7, ///< int
    AelixSDKEncodingTypeUInt32     = 8, ///< unsigned int
    AelixSDKEncodingTypeInt64      = 9, ///< long long
    AelixSDKEncodingTypeUInt64     = 10, ///< unsigned long long
    AelixSDKEncodingTypeFloat      = 11, ///< float
    AelixSDKEncodingTypeDouble     = 12, ///< double
    AelixSDKEncodingTypeLongDouble = 13, ///< long double
    AelixSDKEncodingTypeObject     = 14, ///< id
    AelixSDKEncodingTypeClass      = 15, ///< Class
    AelixSDKEncodingTypeSEL        = 16, ///< SEL
    AelixSDKEncodingTypeBlock      = 17, ///< block
    AelixSDKEncodingTypePointer    = 18, ///< void*
    AelixSDKEncodingTypeStruct     = 19, ///< struct
    AelixSDKEncodingTypeUnion      = 20, ///< union
    AelixSDKEncodingTypeCString    = 21, ///< char*
    AelixSDKEncodingTypeCArray     = 22, ///< char[10] (for example)
    
    AelixSDKEncodingTypeQualifierMask   = 0xFF00,   ///< mask of qualifier
    AelixSDKEncodingTypeQualifierConst  = 1 << 8,  ///< const
    AelixSDKEncodingTypeQualifierIn     = 1 << 9,  ///< in
    AelixSDKEncodingTypeQualifierInout  = 1 << 10, ///< inout
    AelixSDKEncodingTypeQualifierOut    = 1 << 11, ///< out
    AelixSDKEncodingTypeQualifierBycopy = 1 << 12, ///< bycopy
    AelixSDKEncodingTypeQualifierByref  = 1 << 13, ///< byref
    AelixSDKEncodingTypeQualifierOneway = 1 << 14, ///< oneway
    
    AelixSDKEncodingTypePropertyMask         = 0xFF0000, ///< mask of property
    AelixSDKEncodingTypePropertyReadonly     = 1 << 16, ///< readonly
    AelixSDKEncodingTypePropertyCopy         = 1 << 17, ///< copy
    AelixSDKEncodingTypePropertyRetain       = 1 << 18, ///< retain
    AelixSDKEncodingTypePropertyNonatomic    = 1 << 19, ///< nonatomic
    AelixSDKEncodingTypePropertyWeak         = 1 << 20, ///< weak
    AelixSDKEncodingTypePropertyCustomGetter = 1 << 21, ///< getter=
    AelixSDKEncodingTypePropertyCustomSetter = 1 << 22, ///< setter=
    AelixSDKEncodingTypePropertyDynamic      = 1 << 23, ///< @dynamic
};

AelixSDKEncodingType AelixSDKEncodingGetType(const char *typeEncoding);

@interface AelixSDKClassIvarInfo : NSObject
@property (nonatomic, assign, readonly) Ivar ivar;              ///< ivar opaque struct
@property (nonatomic, strong, readonly) NSString *name;         ///< Ivar's name
@property (nonatomic, assign, readonly) ptrdiff_t offset;       ///< Ivar's offset
@property (nonatomic, strong, readonly) NSString *typeEncoding; ///< Ivar's type encoding
@property (nonatomic, assign, readonly) AelixSDKEncodingType type;    ///< Ivar's type

- (instancetype)initWithIvar:(Ivar)ivar;
@end


/**
 Method information.
 */
@interface AelixSDKClassMethodInfo : NSObject
@property (nonatomic, assign, readonly) Method method;                  ///< method opaque struct
@property (nonatomic, strong, readonly) NSString *name;                 ///< method name
@property (nonatomic, assign, readonly) SEL sel;                        ///< method's selector
@property (nonatomic, assign, readonly) IMP imp;                        ///< method's implementation
@property (nonatomic, strong, readonly) NSString *typeEncoding;         ///< method's parameter and return types
@property (nonatomic, strong, readonly) NSString *returnTypeEncoding;   ///< return value's type
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *argumentTypeEncodings; ///< array of arguments' type
- (instancetype)initWithMethod:(Method)method;
@end


/**
 Property information.
 */
@interface AelixSDKClassPropertyInfo : NSObject
@property (nonatomic, assign, readonly) objc_property_t property; ///< property's opaque struct
@property (nonatomic, strong, readonly) NSString *name;           ///< property's name
@property (nonatomic, assign, readonly) AelixSDKEncodingType type;      ///< property's type
@property (nonatomic, strong, readonly) NSString *typeEncoding;   ///< property's encoding value
@property (nonatomic, strong, readonly) NSString *ivarName;       ///< property's ivar name
@property (nullable, nonatomic, assign, readonly) Class cls;      ///< may be nil
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *protocols; ///< may nil
@property (nonatomic, assign, readonly) SEL getter;               ///< getter (nonnull)
@property (nonatomic, assign, readonly) SEL setter;               ///< setter (nonnull)

- (instancetype)initWithProperty:(objc_property_t)property;
@end


/**
 Class information for a class.
 */
@interface AelixSDKClassInfo : NSObject
@property (nonatomic, assign, readonly) Class cls; ///< class object
@property (nullable, nonatomic, assign, readonly) Class superCls; ///< super class object
@property (nullable, nonatomic, assign, readonly) Class metaCls;  ///< class's meta class object
@property (nonatomic, readonly) BOOL isMeta; ///< whether this class is meta class
@property (nonatomic, strong, readonly) NSString *name; ///< class name
@property (nullable, nonatomic, strong, readonly) AelixSDKClassInfo *superClassInfo; ///< super class's class info
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, AelixSDKClassIvarInfo *> *ivarInfos; ///< ivars
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, AelixSDKClassMethodInfo *> *methodInfos; ///< methods
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, AelixSDKClassPropertyInfo *> *propertyInfos; ///< properties
- (void)setNeedUpdate;

- (BOOL)needUpdate;

+ (nullable instancetype)classInfoWithClass:(Class)cls;

+ (nullable instancetype)classInfoWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
