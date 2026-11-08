# AelixSDK

Aelix 广告聚合 SDK，支持 Banner、插屏、开屏、激励视频、全屏视频、信息流等广告形式。

当前版本内置广告渠道：UbiX（通过 CocoaPods 依赖 `UBiXMediationSDK`、`UBiXMUBiXAdapter` 自动引入）。

## 系统要求

- iOS 12.0+
- Xcode 12+

## 安装

在 `Podfile` 中引入：

```ruby
pod 'AelixSDK', :git => 'https://github.com/AndrewXF/AelixSDK.git', :tag => '1.0.0'
```

然后执行：

```bash
pod install
```

## 使用

```objc
#import <AelixSDK/AelixMediationSDK.h>

AelixMediationSDK *config = [[AelixMediationSDK alloc] init];
config.appid = @"YOUR_APP_ID";
[AelixSDK initializeWithConfig:config];
```

## 文档

详细接入说明（工程配置、各广告位示例、代理回调、错误码、FAQ）见 [接入指南](INTEGRATION_GUIDE.md)。

## 目录结构

- `AelixSDK.podspec`：Pod 描述文件
- `AelixSDK.xcframework`：真机 arm64 + 模拟器 arm64/x86_64 二进制
- `LICENSE`：许可证

## 版本

当前版本：1.0.0
