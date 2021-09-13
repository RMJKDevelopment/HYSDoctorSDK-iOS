//
//  HYSDoctorSDK.h
//  HYSDoctor
//
//  Created by rmjk on 2021/9/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HYSDoctorSDK : NSObject

+ (instancetype)shared;

- (void)start;

@end

NS_ASSUME_NONNULL_END
