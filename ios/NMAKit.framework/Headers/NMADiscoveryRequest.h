/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARequest.h"
@class NMAGeoCoordinates;

/**
 * Represents a request to retrieve an `NMADiscoveryPage` object.
 */
@interface NMADiscoveryRequest : NMARequest

/**
 * The text format of the request results.
 *
 * @note The default value is `NMATextFormatHTML`.
 */
@property (nonatomic) NMATextFormat textFormat;

/**
 * Sets the search area using a center location and radius.
 *
 * @param center
 *          The `NMAGeoCoordinates` represents the search area center location.
 * @param radius
 *          The search area radius, clamped to the range 0 to 100,000 meters (100 km).
 *
 * @note Search radius is not supported for "What's here?" requests, see
 * `[NMAPlaces createHereRequestWithLocation:filters:]`.
 */
- (void)setSearchAreaWithCenter:(nonnull NMAGeoCoordinates *)center
                         radius:(NSUInteger)radius
NS_SWIFT_NAME(setSearchArea(center:radius:));

@end
