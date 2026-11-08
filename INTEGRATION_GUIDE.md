# AelixSDK iOS 接入指南

AelixSDK 是一款 iOS 广告聚合 SDK，通过服务端下发策略，按优先级调度各广告渠道，帮助 App 快速接入广告变现能力。

- 当前版本：**1.0.0**
- 最低系统：**iOS 12.0**
- 交付形态：二进制 `xcframework`（静态框架，真机 arm64 + 模拟器 arm64/x86_64）
- 内置渠道：UBiX 聚合（UBiXMediationSDK 2.12.2.11.1001 + UBiXMUBiXAdapter 2.9.0.11.0）

---

## 一、CocoaPods 集成

在 `Podfile` 中添加：

```ruby
source 'https://cdn.cocoapods.org/'

platform :ios, '12.0'

target 'YourApp' do
  pod 'AelixSDK', :git => 'https://github.com/AndrewXF/AelixSDK.git', :tag => '1.0.0'
end
```

然后执行：

```bash
pod install
```

说明：

- UBiX 渠道相关依赖（`UBiXMediationSDK`、`UBiXMUBiXAdapter` 及其子依赖 UBiXMerakSDK、UBiXDaq 等）会由 podspec 依赖自动带入，无需单独声明。
- podspec 已自动为宿主工程配置 `-ObjC` 链接参数，无需手动添加。
- SDK 为静态框架，不要与旧版本 SDK（MobPulseSDK）同时集成。

## 二、工程配置

### 1. ATS 配置

广告渠道存在 HTTP 资源请求，在 `Info.plist` 中开启：

```xml
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```

### 2. IDFA（建议）

为提升广告填充率和收益，建议申请 ATT 授权。`Info.plist` 添加：

```xml
<key>NSUserTrackingUsageDescription</key>
<string>我们需要获取您的设备标识，用于向您提供更相关的广告内容</string>
```

并在 App 启动后合适时机请求授权：

```objc
#import <AppTrackingTransparency/AppTrackingTransparency.h>

if (@available(iOS 14, *)) {
    [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
        // 授权结果不影响 SDK 初始化
    }];
}
```

## 三、初始化

在 `AppDelegate` 中初始化，appid 由平台分配：

```objc
#import <AelixSDK/AelixMediationSDK.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    AelixMediationSDK *config = [[AelixMediationSDK alloc] init];
    config.appid = @"YOUR_APP_ID";
    [AelixSDK initializeWithConfig:config];
    return YES;
}
```

注意：

- 只需初始化一次，SDK 内部会拉取并缓存服务端的广告位策略配置。
- 广告位 ID（placementId）在平台后台创建，Demo 中的测试位仅供联调。

## 四、广告位接入

所有广告对象都遵循同一模式：**初始化 → 设置 delegate → loadAd → （成功后）showAd**。通用回调见「五、代理回调」。

> 建议：广告实例不要复用，每次加载都创建新实例，且一次广告流程中不要更换 delegate。

### 4.1 开屏 AelixSplash

```objc
#import <AelixSDK/AelixSplash.h>

@interface ViewController () <AelixSplashDelegate>
@property (nonatomic, strong) AelixSplash *splash;
@end

- (void)loadSplash {
    self.splash = [[AelixSplash alloc] initWithPlaceMentId:@"开屏广告位ID" viewController:self];
    self.splash.delegate = self;
    [self.splash loadAd];   // 加载成功后自动展示
}
```

可选属性：`showLogoRequire`（是否强制展示 Logo）、`logoImage`、`logoHeight`（≤ 屏幕高度 25%）、`backgroundImage`（加载占位图）、`timeout`（总超时时间）。

专属回调：

```objc
- (void)aelixSplashOnAdSkipClicked;      // 点击跳过
- (void)aelixSplashOnAdCountdownToZero;  // 倒计时结束
```

### 4.2 插屏 AelixInterstitial

```objc
#import <AelixSDK/AelixInterstitial.h>

self.interstitial = [[AelixInterstitial alloc] initWithPlaceMentId:@"插屏广告位ID" viewController:self];
self.interstitial.delegate = self;
[self.interstitial loadAd];

// 在 aelixUnifiedViewDidLoad 成功回调后展示：
[self.interstitial showAd];
```

### 4.3 激励视频 AelixRewardVideo

```objc
#import <AelixSDK/AelixRewardVideo.h>

self.rewardVideo = [[AelixRewardVideo alloc] initWithPlaceMentId:@"激励视频广告位ID" viewController:self];
self.rewardVideo.delegate = self;
[self.rewardVideo loadAd];

// 加载成功后：
[self.rewardVideo showAd];
```

专属回调：

```objc
- (void)aelixRewardVideoAdDidPlayFinish;       // 播放完成
- (void)aelixRewardVideoAdDidRewardEffective;  // 激励达成（发奖励时机）
```

### 4.4 全屏视频 AelixFullScreenVideo

```objc
#import <AelixSDK/AelixFullScreenVideo.h>

self.fullScreenVideo = [[AelixFullScreenVideo alloc] initWithPlaceMentId:@"全屏视频广告位ID"];
self.fullScreenVideo.viewController = self;   // 基类 AelixBaseAdapter 的公开属性，展示时依赖它
self.fullScreenVideo.delegate = self;
[self.fullScreenVideo loadAd];

// 加载成功后：
[self.fullScreenVideo showAd];
```

专属回调：`- (void)aelixFullScreenVideoOnAdPlayFinish;`

> 头文件中另有 `initWithJsonDic:viewController:` 初始化方式，用于直接传入本地策略 JSON（离线联调场景），日常接入用上方的 `initWithPlaceMentId:` 即可。

### 4.5 Banner AelixBanner

```objc
#import <AelixSDK/AelixBanner.h>

UIView *container = [[UIView alloc] initWithFrame:CGRectMake(0, 100, self.view.bounds.size.width, self.view.bounds.size.width * 5 / 32)];
[self.view addSubview:container];

self.banner = [[AelixBanner alloc] initWithPlaceMentId:@"Banner广告位ID"];
self.banner.adContainer = container;   // Banner 渲染到该容器视图
self.banner.delegate = self;
// self.banner.refreshInterval = 30;   // 自动刷新间隔（秒），默认 30
[self.banner loadAd];
```

> Banner 必须设置 `adContainer`。头文件中的 `initWithJsonDic:adContainer:viewController:` 为本地策略 JSON 的初始化方式。

### 4.6 模板信息流 AelixNativeExpress

```objc
#import <AelixSDK/AelixNativeExpress.h>

self.nativeExpress = [[AelixNativeExpress alloc] initWithPlaceMentId:@"信息流广告位ID"
                                                      viewController:self
                                                              adSize:CGSizeMake(self.view.bounds.size.width, 0)];
self.nativeExpress.delegate = self;
[self.nativeExpress loadAd];   // 成功后在 aelixNativeExpressOnAdLoadSuccess: 返回视图数组
```

专属回调（`AelixNativeExpressDelegate`）：

```objc
- (void)aelixNativeExpressOnAdLoadSuccess:(NSArray<AelixNativeExpressView *> *)views;
- (void)aelixNativeExpressOnAdRenderSuccess:(AelixNativeExpressView *)adView;
- (void)aelixNativeExpressOnAdRenderFail:(AelixNativeExpressView *)adView;
- (void)aelixNativeExpressOnAdShow:(AelixNativeExpressView *)adView;
- (void)aelixNativeExpressOnAdClicked:(AelixNativeExpressView *)adView;
- (void)aelixNativeExpressOnAdClosed:(AelixNativeExpressView *)adView;
```

使用要点：收到 `views` 后把 `AelixNativeExpressView` 加入列表/容器；关闭回调中将该视图从数据源移除并刷新列表。

### 4.7 自定义信息流 AelixNativeCustomExpress

自渲染场景（自己拼 UI，SDK 只返回素材）：

```objc
#import <AelixSDK/AelixNativeCustomExpress.h>

self.customFeed = [[AelixNativeCustomExpress alloc] initWithPlaceMentId:@"自定义信息流广告位ID"
                                                         viewController:self
                                                                 adSize:CGSizeMake(self.view.bounds.size.width, 0)];
self.customFeed.delegate = self;
[self.customFeed loadAd];
```

素材数据模型为 `AelixMediationMaterialData`（标题、描述、图片、视频等），回调与模板信息流一致。

## 五、代理回调

所有广告类型的 delegate 都继承自 `AelixBaseDelegate`（`AelixCommonDelegate`）：

```objc
// 流程状态
- (void)aelixSupplierWillLoad:(NSString *)supplierId;                 // 即将加载某个渠道
- (void)aelixSuccessSortTag:(NSString *)sortTag;                      // 某渠道加载成功
- (void)aelixFailedWithError:(AelixError *)error description:(NSDictionary *)description; // 最终失败

// 渲染与展示
- (void)aelixUnifiedViewDidLoad;        // 广告就绪（可 showAd）
- (void)aelixUnifiedViewDidLoadFailed;  // 渲染失败
- (void)aelixSDKExposured;              // 曝光
- (void)aelixSDKClicked;                // 点击
- (void)aelixSDKDidClose;               // 关闭
```

## 六、错误码

| code | 含义 | 排查建议 |
|---|---|---|
| 101~105 | 参数/初始化类错误 | 检查 appid、placementId、delegate 设置 |
| 110~113 | 配置/策略拉取失败 | 检查网络；确认后台已配置该 bundleId + appid |
| **114** | **所有本地策略执行失败（无填充）** | 最常见。表示所有渠道都没返回广告：确认平台后台该广告位已挂渠道、渠道侧有预算/需求、测试设备已加白 |
| 115~116 | 展示/渲染失败 | 检查 viewController 生命周期、容器视图 |

调试技巧：`aelixFailedWithError:description:` 的 `description` 字典里带各渠道的失败明细；`aelixSupplierWillLoad:` / `aelixSuccessSortTag:` 可以看到每条渠道策略的执行顺序。

## 七、常见问题

**1. 集成后一直报 114？**
SDK 按服务端下发的策略顺序逐个尝试渠道，114 表示全部失败。先确认：(a) 后台该广告位配置了渠道；(b) 渠道 SDK 版本与本 SDK 声明的依赖一致；(c) 渠道后台有可用需求（可用渠道提供的测试位验证）。

**2. 模拟器可以用吗？**
可以，xcframework 同时包含模拟器 arm64/x86_64 slice，无需配置 `EXCLUDED_ARCHS`。

**3. 和旧 SDK（MobPulseSDK）能共存吗？**
不建议。两者本地缓存 key 已隔离（`aelix_mediation_config_key`），但渠道 SDK 重复链接会导致符号冲突。

**4. 如何升级版本？**
修改 Podfile 中的 `:tag` 为新版本号，执行 `pod update AelixSDK`。

---

完整可运行示例见 Demo 工程；接入问题请联系平台方并提供 `aelixFailedWithError` 的完整日志。
