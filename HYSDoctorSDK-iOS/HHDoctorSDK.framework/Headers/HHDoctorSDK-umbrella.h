#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "UITextView+Placeholder.h"
#import "HHMBProgressHUD.h"
#import "ObjectMapper.h"
#import "HHPhotoPicker.h"
#import "CGGeometry+RSKImageCropper.h"
#import "RSKImageCropVC.h"
#import "RSKImageCropViewController+Protected.h"
#import "SDKImageCropper.h"
#import "SDKImageScrollView.h"
#import "SDKTouchView.h"
#import "UIApplication+RSKImageCropper.h"
#import "UIImage+RSKImageCropper.h"
#import "SDKCameraImageModel.h"
#import "SDKCameraUtil.h"
#import "SDKPHAssetManager.h"
#import "HHAnimatedImageRep.h"
#import "HHImageCache.h"
#import "HHImageCacheConfig.h"
#import "HHWebImageCoder.h"
#import "HHWebImageCoderHelper.h"
#import "HHWebImageCodersManager.h"
#import "HHWebImageCompat.h"
#import "HHWebImageDownloader.h"
#import "HHWebImageDownloaderOperation.h"
#import "HHWebImageFrame.h"
#import "HHWebImageGIFCoder.h"
#import "HHWebImageImageIOCoder.h"
#import "HHWebImageManager.h"
#import "HHWebImageOperation.h"
#import "HHWebImagePrefetcher.h"
#import "HHWebImageTransition.h"
#import "NSData+hhImageContentType.h"
#import "NSImage+hhWebCache.h"
#import "UIButton+hhWebCache.h"
#import "UIImage+hhForceDecode.h"
#import "UIImage+hhGIF.h"
#import "UIImage+hhMultiFormat.h"
#import "UIImageView+hhHighlightedWebCache.h"
#import "UIImageView+hhWebCache.h"
#import "UIView+hhWebCache.h"
#import "UIView+hhWebCacheOperation.h"

FOUNDATION_EXPORT double HHDoctorSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char HHDoctorSDKVersionString[];

