/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * Represents a HERE Places resource link which requires another request to be made
 * in order to retrieve the full details of the resource. The link contains basic metadata
 * about the linked resource.
 *
 * The interface is typically subclassed to provide methods to make the appropriate resource
 * request.
 */
@interface NMALink : NSObject

/**
 * Gets the unique identifier for the resource to which the `NMALink` refers.
 *
 * @note An identifier for a linked object is optional, so this property could be nil.
 */
@property (nullable, nonatomic, readonly) NSString *uniqueId;

/**
 * Gets the `NSString` representation of the link URL.
 *
 * This URL may be used to perform an HTTP GET request to the HERE Places REST service
 * to retrieve the full metadata of the linked resources.
 *
 * The request may return a HTML or JSON response. If url contains "places.hybrid.api.here.com",
 * it will return a JSON response as specified at http://developer.here.com/places
 * If URL contains other domains, it will most likely return a HTML response.
 *
 * @note For convenience it is recommended to use request methods in dervied classes when
 * available.
 */
@property (nonnull, nonatomic, readonly) NSString *url;

/**
 * Gets the localized name for the resource to which the `NMALink` refers.
 *
 * Client applications can safely display this name to the user.
 *
 * @note A title for a linked object is optional, so this property could be nil.
 */
@property (nullable, nonatomic, readonly) NSString *name;

/**
 * Gets an URL of the icon for the resource to which assiciated with this NMALink.
 *
 * @note An icon URL for a NMALink object is optional, so this property could be nil.
 * Application can download the icon online with this URL, but it needs to use
 * its own icon for offline.
 */
@property (nullable, nonatomic, readonly) NSString *iconUrl;

@end
