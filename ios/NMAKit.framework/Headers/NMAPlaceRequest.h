/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARequest.h"

/**
 * Represents a request to retrieve an NMAPlace object.
 */
@interface NMAPlaceRequest : NMARequest

/**
 * To request an image media with specific width-height
 * dimensions. At least one of the sizes (width or height) needs to be valid
 * (greater than 0).
 *
 * Note taht the provided width-height are used as upper boundaries
 * for the dimensions of the returned images.
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
 */
- (void)addImageSizeWithWidth:(NSInteger)width
                       height:(NSInteger)height
NS_SWIFT_NAME(addImageSize(width:height:));

/**
 * To request additional content. Result will be provided in editorials property of NMAPlace object
 *
 * @param content The content name. Currently only NMAPlacesContentWikipedia is supported.
 * Unsupported values are ignored.
 */
- (void)addContent:(nonnull NSString *)content;

/**
 * The text format of the request results.
 *
 * @note The default value is NMATextFormatHTML.
 */
@property (nonatomic) NMATextFormat textFormat;

@end

