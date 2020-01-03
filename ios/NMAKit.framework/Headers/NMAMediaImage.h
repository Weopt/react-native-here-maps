/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMedia.h"

/**
 * Represents an image associated with an `NMAPlace`. Images are uploaded by
 * the HERE user community.
 *
 * See also `NMAMediaEditorial`
 * See also `NMAMediaReview`
 * See also `NMAMediaRating`
 */
@interface NMAMediaImage : NMAMedia

/**
 * The external URL of the image source.
 *
 * @return The `NSString`
 */
@property (nonnull, nonatomic, readonly) NSString *imageSource;

/**
 * The unique identifier of the image.
 *
 * @note An ID for an image is optional. Attempts to read this property
 * could return empty string.
 *
 * @return The ID (could be empty string)
 */
@property (nonnull, nonatomic, readonly) NSString *uniqueId;

/**
 * The details of the user who contributed the image.
 *
 * @note A user-contributor for an image is optional. Attempts to read
 * this property could return nil.
 *
 * @return `NMALink` (could be nil)
 */
@property (nullable, nonatomic, readonly) NMALink *user;

/**
 * Gets a URL for an image with specific width-height dimensions.
 *
 * The provided width-height are used as upper boundaries
 * for the dimensions of the returned images. The solution will
 * never scale up small images and will maintain the aspect ratio
 * of the original image.
 *
 * 
 * A URL of image with specific width-height dimensions will not
 * be returned if it has not been queried with `-[NMARequest addImageSizeWithWidth:height:]`
 * 
 * 
 * For example:
 * 
 * \code
 * image_dimensions=w32-h32,w64-h64
 * image_dimensions=w32-h32,w300
 * image_dimensions=h200
 * \endcode
 *
 * @param width The image width.
 * @param height The image height.
 *
 * @return The URL to retrieve the image with the specified width-height
 *         dimensions. Can be nil if an image with the specified
 *         dimensions is unavailable.
 */
- (nullable NSString*)URLForImageWithWidth:(NSInteger)width
                           height:(NSInteger)height
NS_SWIFT_NAME(imageURL(width:height:));

@end
