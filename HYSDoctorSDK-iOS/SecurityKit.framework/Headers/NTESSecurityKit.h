//
//  NTESSecurityKit.h
//  NTESSecurityKit
//
//  Created by NetEase on 17/5/30.
//  Copyright © 2017年 NetEase. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NSSKSecurityError){
    NSSKSecurityInvalidParameterError = 1,   // 输入无效参数
    NSSKSecurityBundleIDMismatchError    ,   // Bundle Identifier不匹配
    NSSKSecurityProtocolError            ,   // 数据格式错误
    NSSKSecurityInvalidSeverDataError    ,   // 服务器的数据被篡改
    NSSKSecurityUnkownError              ,
    NSSKSecurityKeyExistError            ,   // 本地数据索引已存在
    NSSKSecurityKeyDoesNotExistError     ,   // 本地数据索引不存在
    NSSKSecurityFileOperationError       ,   // 本地数据文件操作失败
    NSSKSecurityDataEncryptDecryptError  ,   // 数据加解密失败
    NSSKSecurityKeyError                 ,   // 密钥错误
    NSSKSecurityOutofValidPeriodError    ,   // 超出使用期错误
    NSSKSecurityWhiteBoxEncryptError     ,   // 白盒加密错误
    NSSKSecurityWhiteBoxDecryptError     ,   // 白盒解密错误
};

@interface NTESSecurityKit : NSObject

/**
 *  单例
 *
 *  @return         NTESSecurityKit对象
 */
+ (NTESSecurityKit *)sharedInstance;

/**
 *  客户端对输入的明文数据进行加密，然后返回密文，这个密文是发送到服务器的
 *
 *  @param input    需要加密保护的字符串数据
 *  @param error    如果加密出现错误，error会被设置, error的code对应 NSSKSecurityError;接口返回值为nil。
 *
 *  @return         加密的结果,UTF-8编码
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance
 */
- (NSString *)encryptStringToServer:(NSString *)input error:(NSError **)error;

/**
 *  客户端对输入的密文数据(密文来自服务器)进行解密，然后返回明文
 *
 *  @param input    需要解密还原的字符串数据
 *  @param error    如果解密出现错误，error会被设置, error的code对应 NSSKSecurityError;接口返回值为nil。
 *
 *  @return         解密的结果，UTF-8编码
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance; (2)输入参数input是来自服务器返回的加密结果
 */
- (NSString *)decryptStringFromServer:(NSString *)input error:(NSError **)error;

/**
 *  客户端对输入的Binary数据进行加密，然后返回密文，该密文用于发送至服务端
 *  
 *  @param input     需要加密保护的Binary数据
 *  @param error     如果加密出现错误，error会被设置, error的code对应 NSSKSecurityError;接口返回值为nil。
 
 *  @return          加密的结果，UTF-8编码
 *  @说明             (1)在调用该接口前，确定已调用 sharedInstance
 */
- (NSString *)encryptBinaryToServer:(NSData *)input error:(NSError **)error;

/**
 *  客户端对输入的密文数据(密文来自服务器)进行解密，然后返回解密后的Binary
 *
 *  @param input    需要解密还原的字符串数据
 *  @param error    如果解密出现错误，error会被设置, error的code对应 NSSKSecurityError;接口返回值为nil。
 *
 *  @return         解密的结果，Binary数据
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance; (2)输入参数input是来自服务器返回的加密结果
 */
- (NSData *)decryptBinaryFromServer:(NSString *)input error:(NSError **)error;

/**
 *  SDK将需要加密存储的字符串进行加密，并存储在本地
 *  
 *  @param input    需要加密存储的字符串
 *  @param key      用户自定义的key，用于索引本地数据
 *  @param error    如果加密或存储出现错误，error将会被设置，error的code对应 NSSKSecurityError；接口返回NO
 *
 *  @return         加密存储是否成功，成功返回YES，失败返回NO
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance;
 */
- (BOOL)putString:(NSString *)input key:(NSString *)key error:(NSError **)error;

/**
 *  取出存储在本地的字符串，返回解密后的明文
 *
 *  @param key      用户自定义的key，用于索引本地数据
 *  @param error    如果取出本地存储的数据出现错误，error将会被设置，error的code对应 NSSKSecurityError；接口返回nil
 *
 *  @return         本地存储的对应于key的数据，数据将被解密，返回解密后的明文
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance;
 */
- (NSString *)getString:(NSString *)key error:(NSError **)error;

/**
 *  更新本地存储的字符串数据
 *
 *  @param input    更新的字符串
 *  @param key      用户自定义的key，用于索引本地数据
 *  @param error    如果加密或存储出现错误，error将会被设置，error的code对应 NSSKSecurityError；接口返回NO
 *
 *  @return         加密存储是否成功，成功返回YES，失败返回NO
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance;
 */
- (BOOL)updateString:(NSString *)input key:(NSString *)key error:(NSError **)error;
/**
 *  删除存储在本地的字符串
 *
 *  @param key      用户自定义的key，用于索引本地数据
 *  @param error    如果删除本地存储的数据出现错误，error将会被设置，error的code对应 NSSKSecurityError；接口返回NO
 *
 *  @return         删除本地存储的数据是否成功，成功返回YES，失败返回NO
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance;
 */
- (BOOL)removeString:(NSString *)key error:(NSError **)error;

/**
 *  SDK将需要加密存储的Binary进行加密，并存储在本地
 *
 *  @param input    需要加密存储的Binary
 *  @param key      用户自定义的key，用于索引本地数据
 *  @param error    如果加密或存储出现错误，error将会被设置，error的code对应 NSSKSecurityError；接口返回NO
 *
 *  @return         加密存储是否成功，成功返回YES，失败返回NO
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance;
 */
- (BOOL)putBinary:(NSData *)input key:(NSString *)key error:(NSError **)error;

/**
 *  取出存储在本地的Binary数据，返回解密后的明文
 *
 *  @param key      用户自定义的key，用于索引本地数据
 *  @param error    如果取出本地存储的数据出现错误，error将会被设置，error的code对应 NSSKSecurityError；接口返回nil
 *
 *  @return         本地存储的对应于key的数据，数据将被解密，返回解密后的明文
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance;
 */
- (NSData *)getBinary:(NSString *)key error:(NSError **)error;

/**
 *  更新本地存储的Binary数据
 *
 *  @param input    更新的Binary
 *  @param key      用户自定义的key，用于索引本地数据
 *  @param error    如果加密或存储出现错误，error将会被设置，error的code对应 NSSKSecurityError；接口返回NO
 *
 *  @return         加密存储是否成功，成功返回YES，失败返回NO
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance;
 */
- (BOOL)updateBinary:(NSData *)input key:(NSString *)key error:(NSError **)error;
/**
 *  删除存储在本地的Binary数据
 *
 *  @param key      用户自定义的key，用于索引本地数据
 *  @param error    如果删除本地存储的数据出现错误，error将会被设置，error的code对应 NSSKSecurityError；接口返回NO
 *
 *  @return         删除本地存储的数据是否成功，成功返回YES，失败返回NO
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance;
 */
- (BOOL)removeBinary:(NSString *)key error:(NSError **)error;

/**
 *  SDK将明文白盒加密，返回密文
 *  @param input    需要加密保护的字符串数据
 *  @param error    如果加密出现错误，error会被设置, error的code对应 NSSKSecurityError;接口返回值为nil
 *
 *  @return         加密的结果
*  @说明            (1)在调用该接口前，确定已调用 sharedInstance
 */
- (NSString *)getWBEncryptString:(NSString *)input error:(NSError **)error;

/**
 *  SDK将白盒加密的密文，通过白盒解密，返回解密后的明文
 *
 *  @param input    需要解密还原的字符串数据
 *  @param error    如果解密出现错误，error会被设置, error的code对应 NSSKSecurityError;接口返回值为nil。
 *
 *  @return         解密的结果
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance;
 */
- (NSString *)getWBDecryptString:(NSString *)input error:(NSError **)error;

/**
 *  客户端对输入的Binary数据进行白盒加密，返回白盒密文
 *
 *  @param input     需要加密保护的Binary数据
 *  @param error     如果加密出现错误，error会被设置, error的code对应 NSSKSecurityError;接口返回值为nil。
 
 *  @return          加密的结果
 *  @说明             (1)在调用该接口前，确定已调用 sharedInstance
 */
- (NSString *)getWBEncryptBinary:(NSData *)input error:(NSError **)error;

/**
 *  客户端对输入的白盒密文进行解密，然后返回解密后的Binary
 *
 *  @param input    需要解密还原的字符串数据
 *  @param error    如果解密出现错误，error会被设置, error的code对应 NSSKSecurityError;接口返回值为nil。
 *
 *  @return         解密的结果，Binary数据
 *  @说明            (1)在调用该接口前，确定已调用 sharedInstance; (2)输入参数input是来自服务器返回的加密结果
 */
- (NSData *)getWBDecryptBinary:(NSString *)input error:(NSError **)error;

/* 查看SDK的版本号
 *
 * @return          SDK的版本信息
 */
- (NSString *)sdkVersion;

/* 判断设备是否越狱
 *
 * @return, BOOL YES:越狱;NO:非越狱
 */
- (BOOL)isJailbreak;

@end
