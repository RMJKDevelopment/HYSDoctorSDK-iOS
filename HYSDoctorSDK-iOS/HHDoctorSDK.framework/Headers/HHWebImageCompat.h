/*
 * This file is part of the HHWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Jamie Pinkham
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <TargetConditionals.h>

#ifdef __OBJC_GC__
    #error HHWebImage does not support Objective-C Garbage Collection
#endif

// Apple's defines from TargetConditionals.h are a bit weird.
// Seems like TARGET_OS_MAC is always defined (on all platforms).
// To determine if we are running on OSX, we can only rely on TARGET_OS_IPHONE=0 and all the other platforms
#if !TARGET_OS_IPHONE && !TARGET_OS_IOS && !TARGET_OS_TV && !TARGET_OS_WATCH
    #define HH_MAC 1
#else
    #define HH_MAC 0
#endif

// iOS and tvOS are very similar, UIKit exists on both platforms
// Note: watchOS also has UIKit, but it's very limited
#if TARGET_OS_IOS || TARGET_OS_TV
    #define HH_UIKIT 1
#else
    #define HH_UIKIT 0
#endif

#if TARGET_OS_IOS
    #define HH_IOS 1
#else
    #define HH_IOS 0
#endif

#if TARGET_OS_TV
    #define HH_TV 1
#else
    #define HH_TV 0
#endif

#if TARGET_OS_WATCH
    #define HH_WATCH 1
#else
    #define HH_WATCH 0
#endif


#if HH_MAC
    #import <AppKit/AppKit.h>
    #ifndef UIImage
        #define UIImage NSImage
    #endif
    #ifndef UIImageView
        #define UIImageView NSImageView
    #endif
    #ifndef UIView
        #define UIView NSView
    #endif
#else
    #if __IPHONE_OS_VERSION_MIN_REQUIRED != 20000 && __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
        #error HHWebImage doesn't support Deployment Target version < 5.0
    #endif

    #if HH_UIKIT
        #import <UIKit/UIKit.h>
    #endif
    #if HH_WATCH
        #import <WatchKit/WatchKit.h>
    #endif
#endif

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

#ifndef NS_OPTIONS
#define NS_OPTIONS(_type, _name) enum _name : _type _name; enum _name : _type
#endif

FOUNDATION_EXPORT UIImage *HHScaledImageForKey(NSString *key, UIImage *image);

typedef void(^HHWebImageNoParamsBlock)(void);

FOUNDATION_EXPORT NSString *const HHWebImageErrorDomain;

#ifndef dispatch_queue_async_safe
#define dispatch_queue_async_safe(queue, block)\
    if (strcmp(dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL), dispatch_queue_get_label(queue)) == 0) {\
        block();\
    } else {\
        dispatch_async(queue, block);\
    }
#endif

#ifndef dispatch_main_async_safe
#define dispatch_main_async_safe(block) dispatch_queue_async_safe(dispatch_get_main_queue(), block)
#endif
