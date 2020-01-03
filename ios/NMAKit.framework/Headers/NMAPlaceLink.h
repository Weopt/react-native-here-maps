/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMALink.h"

@class NMACategory;
@class NMAPlaceRequest;
@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents metadata about a place, this object is usually returned as a response to places search.
 *
 * @note To retrieve the actual NMAPlace object use the `detailsRequest` property.
 */
@interface NMAPlaceLink : NMALink

/**
 * The `NMAGeoCoordinates` representing the geographical position
 * of the NMAPlace.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *position;

/**
 * The distance to the NMAPlace, in meters.
 *
 * @note Distance information for a place is optional. Attempts to read this
 * property could return be zero.
 */
@property (nonatomic, readonly) NSInteger distance;

/**
 * The average rating for the NMAPlace if available, otherwise
 * -1.0 to indicate the value is not available.
 */
@property (nonatomic, readonly) double averageRating;

/**
 * The `NMACategory` to the primary category for the NMAPlace.
 */
@property (nonatomic, readonly) NMACategory *category;

/**
 * The `NSString` description of the vicinity surrounding the
 * `NMAPlaceLink`.
 *
 * Typically, this property is derived from the address, but could also
 * contain any other description that helps an application user understand
 * where the place is located.
 */
@property (nonatomic, readonly) NSString *vicinityDescription;

/**
 * The enclosing `NMAGeoBoundingBox` describing a range of coordinates
 * that correspond to the NMAPlace. Typically, bounding boxes are
 * associated with places such as cities and countries.
 *
 * This bounding box does not necessarily have the location from the position
 * property as its center. For example, if the search was performed with a
 * street name, this bounding box may be one that contains the entire
 * street, while position can be any point along the street.
 *
 * @note Bounding box information for a place is optional. Attempts to read
 * this property could return nil.
 */
@property (nullable, nonatomic, readonly) NMAGeoBoundingBox *boundingBox;

/**
 * Indicates whether this search result is sponsored.
 *
 * Applications should provide some visual differentiation between sponsored
 * search results and regular search results.
 *
 * @note Sponsorship is an optional attribute for a place.
 */
@property (nonatomic, readonly) BOOL isSponsored;

/**
 * Gets the request to retrieve the `NMAPlace` details.
 * Attempts to read this property could return nil.
 */
- (nullable NMAPlaceRequest *)detailsRequest;

/**
 * Get reference identifiers for a specific source. For example, a place
 * can have a reference to an extruded building object in the map. The
 * reference identifiers can be retrieved by calling this method with source
 * `NMAPlacesSourceBuilding`.
 *
 * Index 0 is the primary reference identifier for the place.
 *
 * @note A reference identifier will not be returned if it has not been queried
 * with the `NMARequest::addSource:` function.
 *
 * @param source `NSString` specifying the source
 * @return An `NSArray` of reference identifiers. Return nil if reference
 * identifier does not exist.
 */
- (nullable NSArray<NSString *> *)referenceIdentifiersForSource:(NSString *)source
NS_SWIFT_NAME(referenceIdentifiers(forSource:));

@end

NS_ASSUME_NONNULL_END

