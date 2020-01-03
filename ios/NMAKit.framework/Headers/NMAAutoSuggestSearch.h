/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAAutoSuggest.h"


@class NMACategory;
@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;
@class NMADiscoveryRequest;

/**
 * Represents a suggested search.
 *
 * See also `NMAAutoSuggestPlace`
 */
@interface NMAAutoSuggestSearch : NMAAutoSuggest

/**
 * The `NMAGeoCoordinates` representing the geographical position of the `NMAPlace`.
 *
 * @note position for a place is optional. Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly, strong) NMAGeoCoordinates *position;

/**
 * The NSString representation of the category for the NMAPlace.
 *
 * @note category for a place is optional. Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly, strong) NSString *category;

/**
 * The enclosing `NMAGeoBoundingBox` describing a range of coordinates
 * that correspond to the NMAPlace. Typically, bounding boxes are
 * associated with places such as cities and countries.
 *
 * @note Bounding box information for a place is optional. Attempts to read
 * this property could return nil.
 */
@property (nullable, nonatomic, readonly, strong) NMAGeoBoundingBox *boundingBox;

/**
 * Gets the `NMADiscoveryRequest` to perform a suggested search e.g. category search.
 */
- (nullable NMADiscoveryRequest *)suggestedSearchRequest;

@end

