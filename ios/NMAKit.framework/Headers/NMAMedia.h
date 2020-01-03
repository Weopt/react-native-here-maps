/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMALink;
/**
 * Represents available NMAMedia derived objects.
 */
typedef NS_ENUM(NSUInteger, NMAMediaType) {
    /** NMAMedia object unknown */
    NMAMediaTypeUnknown = 0,
    /** NMAMediaEditorial */
    NMAMediaTypeEditorial,
    /** NMAMediaImage */
    NMAMediaTypeImage,
    /** NMAMediaReview */
    NMAMediaTypeReview,
    /** NMAMediaRating */
    NMAMediaTypeRating
};

/**
 * Represents the base interface for additional rich content about
 * a `NMAPlace`.
 *
 * The following specialized content might be available:
 *
 * - images
 *
 * - editorials
 *
 * - reviews
 */
@interface NMAMedia : NSObject

/**
 * The `NSString` representation of the attribution text for the
 * `NMAMedia`, according to the terms and conditions of the originating source.
 */
@property (nullable, nonatomic, readonly) NSString *attributionText;

/**
 * The `NMALink` to the resource representing the supplier of
 * the content (the object provides details on the origin of the information).
 */
@property (nullable, nonatomic, readonly) NMALink *supplierLink;

/**
 * The `NMALink` to the origin of the information,
 * usually a website of the supplier. The type attribute of the link
 * might need to be checked to see if there is a better user agent than a web
 * browser for handling the media type of the linked-to resource.
 */
@property (nullable, nonatomic, readonly) NMALink *viaLink;

/**
 * The specialized content type.
 */
@property (nonatomic, readonly) NMAMediaType type;

@end
